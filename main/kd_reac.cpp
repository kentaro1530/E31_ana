#include "W_to_mom.hh"

#include "kd_reac/config.hh"
#include "kd_reac/search_qdash.cpp"

// template <class F>
// double diff(F f, double x, double h = 1e-8){ return (f(x+h)-f(x-h))/(2.0*h); }

int main(){
  std::cout<<"K- d reaction Calculation START"<<std::endl;
  TLorentzVector beam_lmom, d_lmom;
  beam_lmom.SetVectM(TVector3(0, 0, 1.0), kpMass);
  d_lmom.SetVectM(TVector3(0, 0, 0), dMass);
  TVector3 CM_to_lab = (beam_lmom+d_lmom).BoostVector();

  //  for( double piS_mass = 1.35; piS_mass<1.6; piS_mass += 0.01 ){
  double piS_mass = 1.50;
    std::complex<double> n_mom = W_to_mom((beam_lmom+d_lmom).M(), piS_mass, nMass);
    TLorentzVector n_lmom, piS_lmom;
    n_lmom.SetVectM(TVector3(0, 0, n_mom.real()), nMass);
    n_lmom.Boost(CM_to_lab);
    piS_lmom.SetVectM(TVector3(0, 0, -n_mom.real()), piS_mass);
    piS_lmom.Boost(CM_to_lab);
    TVector3 lab_to_KN = -piS_lmom.BoostVector();
    TVector3 P = piS_lmom.Vect();
    double q0_2 = (pow(piS_mass, 2) - pow(onshell_mass-Kbar_mass, 2)) * (pow(piS_mass, 2) - pow(onshell_mass+Kbar_mass, 2))/(4*pow(piS_mass, 2));
    const double E_N2_q0 = sqrt(q0_2+pow(onshell_mass, 2));
    const double E_Kbar_q0 = sqrt(q0_2+pow(Kbar_mass, 2));

    std::cout<<"piS mass = "<<piS_mass<<"   q0_2 = "<<q0_2<<std::endl;
    
    for( double theta = 0.5*dtheta; theta<TMath::Pi(); theta += dtheta ){
      std::cout<<">>> theta = "<<theta<<std::endl;
      search_qdash0_from_q0(beam_lmom, n_lmom, piS_lmom, theta, q0_2);
      //      for( double mom = 0; mom<1.0; mom+= 0.001 ){
      //	std::cout<<"  > mom "<<mom<<"  q_dash : "<<search_qdash(beam_lmom, n_lmom, piS_lmom, mom, theta).Mag2()<<std::endl;
      //      }
    }
  std::cout<<"K- d reaction Calculation FINISH"<<std::endl;
}
    //    for( double mom = 0.5*dmom; mom<max_mom; mom += dmom ){



	//	double theta = 0.5, mom = 0.3;
    // 	TVector3 q_N2(mom*sin(theta), 0.0, mom*cos(theta));
    // 	TVector3 q_Kbar = beam_lmom.Vect() - n_lmom.Vect() - q_N2;
    // 	double E_lab_Kbar = sqrt(pow(Kbar_mass, 2)+q_Kbar.Mag2());
    // 	double E_lab_N2 = sqrt(pow(onshell_mass, 2)+q_N2.Mag2());
    // 	double E_CM_Kbar = sqrt(pow(Kbar_mass, 2));
    // 	double E_CM_N2 = sqrt(pow(Kbar_mass, 2));
    // 	double e_Kbar = 0.5*(E_lab_Kbar + E_CM_Kbar);
    // 	double e_N2 = 0.5*(E_lab_N2 + E_CM_N2);
    // 	TVector3 q_dash = -q_N2 + e_N2/(e_Kbar+e_N2)*P;

    // 	int count=0;
    // 	while( true ){
    // 	  //	  std::cout<<"E_CM_Kbar(old) = "<<E_CM_Kbar<<std::endl;
    // 	  //	  std::cout<<"E_CM_N2(new) = "<<E_CM_N2<<std::endl;
    // 	  E_CM_Kbar = sqrt(pow(Kbar_mass, 2)+q_dash.Mag2());
    // 	  E_CM_N2 = sqrt(pow(Kbar_mass, 2)+q_dash.Mag2());
    // 	  e_Kbar = 0.5*(E_lab_Kbar + E_CM_Kbar);
    // 	  e_N2 = 0.5*(E_lab_N2 + E_CM_N2);
    // 	  TVector3 q_dash2 = -q_N2 + e_N2/(e_Kbar+e_N2)*P;
    // 	  // std::cout<<"E_CM_Kbar(old) = "<<E_CM_Kbar<<std::endl;
    // 	  // std::cout<<"E_CM_N2(new) = "<<E_CM_N2<<std::endl;
    // 	  // std::cout<<"q'(old) = ( "<<q_dash.X()<<", "<<q_dash.Y()<<", "<<q_dash.Z()<<" )"<<std::endl;
    // 	  // std::cout<<"q'(new) = ( "<<q_dash2.X()<<", "<<q_dash2.Y()<<", "<<q_dash2.Z()<<" )"<<std::endl;
    // 	  if( (q_dash-q_dash2).Mag()<1e-15 ){
    // 	    std::cout<<"Count = "<<count<<" loop calc finish  delta = "<<(q_dash-q_dash2).Mag()<<std::endl;
    // 	    break;
    // 	  }
    // 	  if( count==MAX_ITERATION ){
    // 	    throw std::runtime_error("q' Calculation not converged");
    // 	  }
    // 	  q_dash = q_dash2;
    // 	  count++;
    // 	}
    // 	const double factor = 1/(E_N2_q0 + sqrt(pow(onshell_mass, 2)+q_dash.Mag2())) + 1/(E_Kbar_q0 + sqrt(pow(Kbar_mass, 2)+q_dash.Mag2()));
    // 	const double W_q = sqrt(q_dash.Mag2()+pow(Kbar_mass, 2))+sqrt(q_dash.Mag2()+pow(onshell_mass, 2));
    // 	const double prefactor = (sqrt(P.Mag2()+pow(piS_mass, 2))+sqrt(P.Mag2()+pow(W_q, 2)))/(piS_mass+W_q);
//      }
//    }
//  }

//}
