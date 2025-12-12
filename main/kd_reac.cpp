#include "W_to_mom.hh"

#include "kd_reac/config.hh"

int main(){
  std::cout<<"K- d reaction Calculation START"<<std::endl;
  TLorentzVector beam_lmom, d_lmom;
  beam_lmom.SetVectM(TVector3(0, 0, 1.0), kpMass);
  d_lmom.SetVectM(TVector3(0, 0, 0), dMass);
  TVector3 CM_to_lab = (beam_lmom+d_lmom).BoostVector();

  double piS_mass = 1.45;
  std::complex<double> n_mom = W_to_mom((beam_lmom+d_lmom).M(), piS_mass, nMass);
  TLorentzVector n_lmom, piS_lmom;
  n_lmom.SetVectM(TVector3(0, 0, n_mom.real()), nMass);
  n_lmom.Boost(CM_to_lab);
  piS_lmom.SetVectM(TVector3(0, 0, -n_mom.real()), piS_mass);
  piS_lmom.Boost(CM_to_lab);
  TVector3 lab_to_KN = -piS_lmom.BoostVector();
  piS_lmom.Boost(lab_to_KN);
  
  //  std::cout<<n_lmom.X()<<", "<<n_lmom.Y()<<", "<<n_lmom.Z()<<std::endl;
  //  std::cout<<piS_lmom.X()<<", "<<piS_lmom.Y()<<", "<<piS_lmom.Z()<<std::endl;

  for( double theta = 0.5*dtheta; theta<TMath::Pi(); theta += dtheta){
    for( double mom = 0.0; mom<=max_mom; mom += dmom ){
      TVector3 fermi_mom = TVector3(mom*sin(theta), 0.0, mom*cos(theta));
      TLorentzVector onshell_lmom, offshell_lmom;
      onshell_lmom.SetVectM(fermi_mom, onshell_mass);
      offshell_lmom = d_lmom - onshell_lmom;

      TLorentzVector Kbar_lmom = beam_lmom + offshell_lmom - n_lmom;
      Kbar_lmom.Boost(lab_to_KN);
      onshell_lmom.Boost(lab_to_KN);

      std::cout<<"("<<Kbar_lmom.X()<<", "<<Kbar_lmom.Y()<<", "<<Kbar_lmom.Z()<<") :  m = "<<Kbar_lmom.M()<<std::endl;
      std::cout<<"("<<onshell_lmom.X()<<", "<<onshell_lmom.Y()<<", "<<onshell_lmom.Z()<<") :  m = "<<onshell_lmom.M()<<std::endl;
    }
  }

  
  
  
  std::cout<<"K- d reaction Calculation FINISH"<<std::endl;
}
