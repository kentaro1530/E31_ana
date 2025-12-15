#include "W_to_mom.hh"

#include "kd_reac/config.hh"
#include "kd_reac/search_q0.cpp"

int main(){
  std::cout<<"K- d reaction Calculation START"<<std::endl;
  TLorentzVector beam_lmom, d_lmom;
  beam_lmom.SetVectM(TVector3(0, 0, 1.0), kpMass);
  d_lmom.SetVectM(TVector3(0, 0, 0), dMass);
  TVector3 CM_to_lab = (beam_lmom+d_lmom).BoostVector();

  double piS_mass = 1.43;
  std::complex<double> n_mom = W_to_mom((beam_lmom+d_lmom).M(), piS_mass, nMass);
  TLorentzVector n_lmom, piS_lmom;
  n_lmom.SetVectM(TVector3(0, 0, n_mom.real()), nMass);
  n_lmom.Boost(CM_to_lab);
  piS_lmom.SetVectM(TVector3(0, 0, -n_mom.real()), piS_mass);
  piS_lmom.Boost(CM_to_lab);
  TVector3 lab_to_KN = -piS_lmom.BoostVector();
  TVector3 P = piS_lmom.Vect();
  //  piS_lmom.Boost(lab_to_KN);

  std::cout<<piS_mass<<std::endl;
  //  std::cout<<n_lmom.X()<<", "<<n_lmom.Y()<<", "<<n_lmom.Z()<<std::endl;
  std::cout<<"pi Sigma Vector = ( "<<piS_lmom.X()<<", "<<piS_lmom.Y()<<", "<<piS_lmom.Z()<<" )"<<std::endl;
  std::cout<<"P = ( "<<P.X()<<", "<<P.Y()<<", "<<P.Z()<<" )"<<std::endl;
  std::cout<<"lab_to_KN = ( "<<lab_to_KN.X()<<", "<<lab_to_KN.Y()<<", "<<lab_to_KN.Z()<<" )"<<std::endl;
  double q_2 = (pow(piS_mass, 2) - pow(onshell_mass-Kbar_mass, 2)) * (pow(piS_mass, 2) - pow(onshell_mass+Kbar_mass, 2))/(4*pow(piS_mass, 2));
  std::cout<<"q_2 = "<<q_2<<std::endl;
  std::cout<<"W(q_2) = "<<sqrt(pow(onshell_mass, 2)+q_2)+sqrt(pow(Kbar_mass, 2)+q_2)<<std::endl;
  
  
  double theta = 0.0, mom = 0.3;
  //  for( double theta = 0.5*dtheta; theta<TMath::Pi(); theta += dtheta){
  //    for( double mom = 0.0; mom<=max_mom; mom += dmom ){
      TVector3 fermi_mom = TVector3(mom*sin(theta), 0.0, mom*cos(theta));
      TLorentzVector onshell_lmom, offshell_lmom;
      onshell_lmom.SetVectM(fermi_mom, onshell_mass);
      offshell_lmom = d_lmom - onshell_lmom;
      double q0_2 = search_q0(piS_mass);      
      std::cout<<"q0_2 = "<<q0_2<<std::endl;
      std::cout<<"W(q0_2) = "<<sqrt(pow(onshell_mass, 2)+q0_2)+sqrt(pow(Kbar_mass, 2)+q0_2)<<std::endl;
      
      //      TLorentzVector Kbar_lmom = beam_lmom + offshell_lmom - n_lmom;
      //      Kbar_lmom.Boost(lab_to_KN);
      //      onshell_lmom.Boost(lab_to_KN);

      // std::cout<<"("<<Kbar_lmom.X()<<", "<<Kbar_lmom.Y()<<", "<<Kbar_lmom.Z()<<") :  m = "<<Kbar_lmom.M()<<std::endl;
      // std::cout<<"("<<onshell_lmom.X()<<", "<<onshell_lmom.Y()<<", "<<onshell_lmom.Z()<<") :  m = "<<onshell_lmom.M()<<std::endl;
      //    }
      //  }

  
  
  
  std::cout<<"K- d reaction Calculation FINISH"<<std::endl;
}
