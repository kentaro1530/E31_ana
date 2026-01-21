#include "config.hh"

TVector3 search_qdash(const TLorentzVector &beam_lmom, const TLorentzVector &n_lmom, const TLorentzVector &piS_lmom,
		      const double &mom, const double &theta);

std::vector<double> search_qdash0_from_q0(const TLorentzVector &beam_lmom, const TLorentzVector &n_lmom, const TLorentzVector &piS_lmom,
					  const double &theta, const double &q0_2){
  std::vector<double> result;
  double mom1 = 0.0, mom2 = 0.001;
  TVector3 q1 = search_qdash(beam_lmom, n_lmom, piS_lmom, mom1, theta);
  TVector3 q2 = search_qdash(beam_lmom, n_lmom, piS_lmom, mom2, theta);

  while( mom2<1.0 ){
    q1 = q2;
    mom2 += 0.001;
    q2 = search_qdash(beam_lmom, n_lmom, piS_lmom, mom2, theta);

    if( (q1.Mag2()-q0_2)*(q2.Mag2()-q0_2) < 0 ){
      //      std::cout<<"Find q'_0 = "<<(0.5*(q1-q2)).Mag2()<<std::endl;
      std::cout<<q0_2<<"  "<<q1.Mag2()<<"  "<<q2.Mag2()<<std::endl;
      result.push_back((0.5*(q1-q2)).Mag());
    }
  }
  std::cout<<"Find n = "<<result.size()<<" Solution"<<std::endl;
  return result;
}

TVector3 search_qdash(const TLorentzVector &beam_lmom, const TLorentzVector &n_lmom, const TLorentzVector &piS_lmom,
		      const double &mom, const double &theta){
  //  std::cout<<"pi S = "<<piS_lmom.M()<<"  mom = "<<mom<<"  theta = "<<theta<<std::endl;
  TVector3 P = piS_lmom.Vect();
  TVector3 q_N2(mom*sin(theta), 0.0, mom*cos(theta));
  TVector3 q_Kbar = beam_lmom.Vect() - n_lmom.Vect() - q_N2;
  double E_lab_Kbar = sqrt(pow(Kbar_mass, 2)+q_Kbar.Mag2());
  double E_lab_N2 = sqrt(pow(onshell_mass, 2)+q_N2.Mag2());
  double E_CM_Kbar = sqrt(pow(Kbar_mass, 2));
  double E_CM_N2 = sqrt(pow(Kbar_mass, 2));
  double e_Kbar = 0.5*(E_lab_Kbar + E_CM_Kbar);
  double e_N2 = 0.5*(E_lab_N2 + E_CM_N2);
  TVector3 q_dash = -q_N2 + e_N2/(e_Kbar+e_N2)*P;

  for( size_t count=0; count<=MAX_ITERATION; count++ ){
    E_CM_Kbar = sqrt(pow(Kbar_mass, 2)+q_dash.Mag2());
    E_CM_N2 = sqrt(pow(Kbar_mass, 2)+q_dash.Mag2());
    e_Kbar = 0.5*(E_lab_Kbar + E_CM_Kbar);
    e_N2 = 0.5*(E_lab_N2 + E_CM_N2);
    TVector3 q_dash2 = -q_N2 + e_N2/(e_Kbar+e_N2)*P;
    //    std::cout<<count<<"   "<<q_dash.Mag()<<"   "<<q_dash2.Mag()<<"   "<<(q_dash-q_dash2).Mag()<<std::endl;
    if( (q_dash-q_dash2).Mag()<TOL ){
      //      std::cout<<"Count = "<<count<<" loop calc finish  delta = "<<(q_dash-q_dash2).Mag()<<std::endl;
      return q_dash2;
    }
    q_dash = q_dash2;
  }
  throw std::runtime_error("q' Calculation not converged");
}
