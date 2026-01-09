#include "W_to_mom.hh"
#include "d_wave_func.hh"

#include "kd_reac/config.hh"
#include "kd_reac/search_qdash.cpp"

int main(){
  std::cout<<"K- d reaction Calculation START"<<std::endl;
  TLorentzVector beam_lmom, d_lmom;
  beam_lmom.SetVectM(TVector3(0, 0, 1.0), kpMass);
  d_lmom.SetVectM(TVector3(0, 0, 0), dMass);
  TVector3 CM_to_lab = (beam_lmom+d_lmom).BoostVector();

  for( double piS_mass = 1.35; piS_mass<1.6; piS_mass += 0.01 ){
    std::complex<double> n_mom = W_to_mom((beam_lmom+d_lmom).M(), piS_mass, nMass);
    TLorentzVector n_lmom, piS_lmom;
    n_lmom.SetVectM(TVector3(0, 0, n_mom.real()), nMass);
    n_lmom.Boost(CM_to_lab);
    piS_lmom.SetVectM(TVector3(0, 0, -n_mom.real()), piS_mass);
    piS_lmom.Boost(CM_to_lab);
    TVector3 lab_to_KN = -piS_lmom.BoostVector();
    TVector3 P = piS_lmom.Vect();
    double q0_2 = (pow(piS_mass, 2) - pow(onshell_mass-Kbar_mass, 2)) * (pow(piS_mass, 2) - pow(onshell_mass+Kbar_mass, 2))/(4*pow(piS_mass, 2));

    std::cout<<"piS mass = "<<piS_mass<<"   q0_2 = "<<q0_2<<std::endl;

    double val = 0;
    for( double theta = 0.5*dtheta; theta<TMath::Pi(); theta += dtheta ){
      for( double mom = 0.5*dmom; mom < N_mom; mom += dmom ){
	//      for( double mom = 0; mom<1.0; mom+= 0.001 ){
	TVector3 qdash = search_qdash(beam_lmom, n_lmom, piS_lmom, mom, theta);

	const double W_qdash = sqrt(qdash.Mag2()+pow(Kbar_mass, 2)) + sqrt(qdash.Mag2() + pow(onshell_mass, 2));
	
	const double inv_f = 1/(sqrt(qdash.Mag2()+pow(onshell_mass, 2)) + sqrt(q0_2+pow(onshell_mass, 2)))
	                     + 1/(sqrt(qdash.Mag2()+pow(Kbar_mass, 2)) + sqrt(q0_2+pow(Kbar_mass, 2)));
	const double factor = (sqrt(P.Mag2()+pow(piS_mass, 2))+sqrt(P.Mag2()+pow(W_qdash, 2)))/(piS_mass, W_qdash);
	
	val += d_wave_func::value_knucl(mom)*mom*mom*sin(theta)*(factor/inv_f)/(qdash.Mag2()-q0_2);
      } 
    }
    std::cout<<"  val = "<<val<<std::endl;
  }
  std::cout<<"K- d reaction Calculation FINISH"<<std::endl;
}
