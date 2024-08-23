#include "common.hh"
#include "W_to_mom.hh"
#include "TMatrix.hh"
#include "reso.hh"
#include "util.hh"
#include "d_wave_func.hh"

#include <TLorentzVector.h>

const double CUT_MOMENTUM=0.2;
const double DELTA_P=CUT_MOMENTUM/50;
const double DELTA_THETA=TMath::Pi()/10;
const double START_MASS=1.3355;
const double END_MASS=1.8;
const double DELTA_MASS=0.001;

const TString outputname="respons_function2.root";

int main(){
  std::cout<<"START make response Function"<<std::endl;
  TFile *of=new TFile(outputname, "recreate");

  TLorentzVector beam_lmom, target_lmom;
  beam_lmom.SetVectM(TVector3(0, 0, 1.0), kpMass);
  target_lmom.SetVectM(TVector3(0, 0, 0), dMass);

  std::vector<double> piS_mass, n_mom, G0_phi, G0_phi2;
  for(double W2=START_MASS; W2<END_MASS; W2+=DELTA_MASS ){ // W2=pi Sigma mass
    const auto mom=W_to_mom((beam_lmom+target_lmom).M(), W2, nMass);
    TLorentzVector n_lmom;
    n_lmom.SetVectM(TVector3(0, 0, mom.real()), nMass);

    n_lmom.Boost((beam_lmom+target_lmom).BoostVector()); 
    double sum=0;
    std::vector<double> p_arr, theta_arr, offshell_mass, kbar_mass, kbar_mom, G0_arr, phi_arr;
    for(double p=0.5*DELTA_P; p<CUT_MOMENTUM; p+=DELTA_P){
      double inner_sum=0;
      for(double theta=0.5*DELTA_THETA; theta<TMath::Pi(); theta+=DELTA_THETA){
	TVector3 fermi_mom(p*p*sin(theta), 0, p*p*cos(theta));
	TLorentzVector onshell_lmom;
	onshell_lmom.SetVectM(fermi_mom, nMass);
	TLorentzVector offshell_lmom=target_lmom-onshell_lmom; 

	TLorentzVector inflight_lmom=beam_lmom+target_lmom-n_lmom-offshell_lmom; // KbarMomentum
	TVector3 boost=-(onshell_lmom+beam_lmom).BoostVector(); // K-onshell(K-N)系への変換

	TLorentzVector n_lmom_at_KN=n_lmom;
	TLorentzVector inflight_lmom_at_KN=inflight_lmom;
	n_lmom_at_KN.Boost(boost);
	inflight_lmom_at_KN.Boost(boost);
	
	const double G0=1.0/(inflight_lmom_at_KN.Vect().Mag2()-inflight_lmom_at_KN.M2()x);
      
	inner_sum+=d_wave_func::value_knucl(p)*G0*p*p*sin(theta)*DELTA_P*DELTA_THETA;
	
	if( isnan(G0) ){
	  std::cout<<"Fermi mom = "<<p<<"   theta="<<theta<<std::endl;
	  std::cout<<"m_N = "<<offshell_lmom.M()<<", m_K = "<<inflight_lmom.M()<<std::endl;
	  std::cout<<"Boost  = "<<boost.X()<<", "<<boost.Y()<<", "<<boost.Z()<<std::endl;
	  std::cout<<"p_Kbar = "<<inflight_lmom_at_KN.X()<<", "<<inflight_lmom_at_KN.Y()<<", "<<inflight_lmom_at_KN.Z()<<"   m = "<<inflight_lmom_at_KN.M()<<std::endl;
	  std::cout<<"n      = "<<n_lmom_at_KN.X()<<", "<<n_lmom_at_KN.Y()<<", "<<n_lmom_at_KN.Z()<<"   E = "<<n_lmom_at_KN.E()<<std::endl;
	  std::cout<<"G(p) = "<<1.0/(inflight_lmom.Vect().Mag2()-pow(inflight_lmom.M(), 2))<<std::endl;
	  std::cout<<"Phi(p_N) = "<<d_wave_func::value(p)<<std::endl;
	  std::cout<<std::endl;
	  continue;
	}
	p_arr.push_back(p);
	theta_arr.push_back(theta);
	offshell_mass.push_back(offshell_lmom.M());
	kbar_mass.push_back(inflight_lmom_at_KN.M());
      }
      //      std::cout<<"  p = "<<p<<" "<<inner_sum<<std::endl;
      //      std::cout<<"      p*p*phi_d(p) ="<<p*p*d_wave_func::value(p)<<std::endl;
      sum+=inner_sum;
    }
    //    std::cout<<Form("W_%d_offshell_mass", (int)(1000*W2))<<std::endl;
    piS_mass.push_back(W2);
    n_mom.push_back(n_lmom.Vect().Mag());
    G0_phi.push_back(sum);
    G0_phi2.push_back(pow(sum, 2));

    util::write_tgraph2D(p_arr, theta_arr, offshell_mass, Form("W_%d_offshell_mass", (int)(1000*W2)));
    util::write_tgraph2D(p_arr, theta_arr, kbar_mass, Form("W_%d_kbar_mass", (int)(1000*W2)));

    //    std::cout<<W2<<" \t"<<sum<<std::endl;
    //    std::cout<<n_lmom.X()<<", "<<n_lmom.Y()<<", "<<n_lmom.Z()<<", E="<<n_lmom.E()<<std::endl;
  }
  util::write_tgraph(piS_mass, n_mom, "forward_n_mom");
  util::write_tgraph(piS_mass, G0_phi, "G0_phi_mom");
  util::write_tgraph(piS_mass, G0_phi2, "G0_phi2_mom");

  of-> Write();
  std::cout<<"FINISH make response Function"<<std::endl;
}
