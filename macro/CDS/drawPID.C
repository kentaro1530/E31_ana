#include "../init.C"
#include "TPolyLine.h"
const TString infilename = "~/test/Run78/k18ana/root/Run78/readAna.root";
const double PID_Param[3] = { 0.00381414, 0.000119896, 0.0113647 };

TH2F* setOpts(TH2F* h2){
  h2-> SetStats(0);
  h2-> SetMarkerStyle(8);
  h2-> SetLineWidth(2);
  h2-> SetTitle("");
  h2-> GetXaxis()->SetLabelSize(0.05);
  h2-> GetXaxis()->SetTitleSize(0.06);
  h2-> GetXaxis()->CenterTitle();
  h2-> GetYaxis()->SetLabelSize(0.05);
  h2-> GetYaxis()->SetTitleSize(0.06);
  h2-> GetYaxis()->CenterTitle();
  h2-> GetXaxis()-> SetTitle("mass^{2} [(GeV/c^{2})^{2}]");
  h2-> GetYaxis()-> SetTitle("mom [GeV/c]");
  
  return h2;
}
double calc_sigma(double m, double p){ return 2*sqrt(PID_Param[0]*m*m*p*p + PID_Param[1]*pow(m, 4)*(1+m*m/(p*p)) + PID_Param[2]*p*p*(m*m+p*p)); }

void drawPID(){
  init();
  TFile *f = new TFile(infilename);
  TCanvas *c1 = new TCanvas("c1", "c1");
  
  TH2F *h2 = setOpts((TH2F*)f-> Get("CDS_mass2_mom"));
  h2-> GetXaxis()-> SetRangeUser(-0.1, 1.2);
  h2-> Draw("colz");

  std::vector<double> x_pip, y_pip, x_p, y_p;
  for( double y=1.0; y>=0.02; y -= 0.001 ){
    double sigma_pi = calc_sigma(piMass, y);
    double sigma_p = calc_sigma(pMass, y);
    if( piMass*piMass-2.5*sigma_pi <= -0.1) continue;
    y_pip.push_back(y);
    x_pip.push_back(piMass*piMass-2.5*sigma_pi);
  }
  for( double y=0.02; y<=1.0; y += 0.001 ){
    double sigma_pi = calc_sigma(piMass, y);
    y_pip.push_back(y);
    x_pip.push_back(piMass*piMass+2.5*sigma_pi);
  }

  for( double y=1.0; y>=0.07; y -= 0.001 ){
    double sigma_pi = calc_sigma(piMass, y);
    double sigma_p = calc_sigma(pMass, y);
    if( pMass*pMass-2.5*sigma_p < piMass*piMass+2.5*sigma_pi ) continue;
    y_p.push_back(y);
    x_p.push_back(pMass*pMass-2.5*sigma_p);
  }
  for( double y=0.07; y<=1.0; y += 0.001 ){  
    double sigma_p = calc_sigma(pMass, y);
    if( pMass*pMass+2.5*sigma_p<=1.2 ){
      y_p.push_back(y);
      x_p.push_back(pMass*pMass+2.5*sigma_p);
    }
    else{
      y_p.push_back(y);
      x_p.push_back(1.2);
    }
  }
  
  std::vector<double> x_pim, y_pim, x_km, y_km;
  for( double y=-1.0; y<=-0.02; y += 0.001 ){
    double sigma_pi = calc_sigma(piMass, y);
    double sigma_p = calc_sigma(pMass, y);
    if( piMass*piMass-2.5*sigma_pi <= -0.1) continue;
    y_pim.push_back(y);
    x_pim.push_back(piMass*piMass-2.5*sigma_pi);
  }
  for( double y=-0.02; y>=-1.0; y -= 0.001 ){
    double sigma_pi = calc_sigma(piMass, y);
    y_pim.push_back(y);
    x_pim.push_back(piMass*piMass+2.5*sigma_pi);
  }

  for( double y=-1.0; y<=-0.05; y += 0.001 ){
    double sigma_pi = calc_sigma(piMass, y);
    double sigma_k = calc_sigma(kpMass, y);
    if( kpMass*kpMass-2.5*sigma_k < piMass*piMass+2.5*sigma_pi ) continue;
    y_km.push_back(y);
    x_km.push_back(kpMass*kpMass-2.5*sigma_k);
  }
  for( double y=-0.05; y>=-1.0; y -= 0.001 ){  
    double sigma_k = calc_sigma(pMass, y);
    y_km.push_back(y);
    x_km.push_back(kpMass*kpMass+2.5*sigma_k);
  }

  TPolyLine *pl_pip = new TPolyLine(x_pip.size(), &x_pip[0], &y_pip[0]);
  pl_pip-> SetLineWidth(2);
  //  pl_pip-> SetLineColor(2);
  pl_pip-> SetLineStyle(9);
  pl_pip-> Draw();
  TPolyLine *pl_p = new TPolyLine(x_p.size(), &x_p[0], &y_p[0]);
  pl_p-> SetLineWidth(2);
  //  pl_p-> SetLineColor(5);
  pl_p-> SetLineStyle(2);
  pl_p-> Draw();  
  TPolyLine *pl_pim = new TPolyLine(x_pim.size(), &x_pim[0], &y_pim[0]);
  pl_pim-> SetLineWidth(2);
  //  pl_pim-> SetLineColor(4);
  pl_pim-> SetLineStyle(9);
  pl_pim-> Draw();
  TPolyLine *pl_km = new TPolyLine(x_km.size(), &x_km[0], &y_km[0]);
  pl_km-> SetLineWidth(2);
  //  pl_km-> SetLineColor(3);
  pl_km-> SetLineStyle(8);
  pl_km-> Draw();
  
  gPad-> SetLogz();
  c1-> Print("pic/Run78/CDS/CDS_PID.eps");
  c1-> Print("pic/Run78/CDS/CDS_PID.png");
}
