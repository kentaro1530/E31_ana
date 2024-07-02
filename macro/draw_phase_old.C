#include "macro/init.C"

void draw_phase(){
  TFile *f=new TFile("~/spectra.root");
  TGraph *graA=(TGraph*)f->Get("gra_phase_A");
  TGraph *graB=(TGraph*)f->Get("gra_phase_B");
  const double kpThre=0.5*(k0Mass+nMass+kpMass+pMass);
  TLine line;
  std::cout<<kpThre<<std::endl;
  line.SetLineWidth(2);
  line.SetLineColor(3);

  graA-> SetTitle("Model. A");
  graA-> SetLineWidth(2);
  graA-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  graA-> GetYaxis()-> SetRangeUser(1., 3.);
  graA-> Draw("AL");
  line.DrawLine(kpThre, 1, kpThre, 3);
  line.SetLineColor(2);
  line.DrawLine(1.432, 1, 1.432, 3);
  line.DrawLine(1.372, 1, 1.372, 3);

  c1-> Print("pic/discussion/phase_A.png");
  c1-> Print("pic/discussion/phase_A.eps");

  graB-> SetTitle("Model. B");
  graB-> SetLineWidth(2);
  graB-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  graB-> GetYaxis()-> SetRangeUser(1., 3.);
  graB-> Draw("AL");
  line.SetLineColor(3);
  line.DrawLine(kpThre, 1, kpThre, 3);
  line.SetLineColor(4);
  line.DrawLine(1.428, 1, 1.428, 3);
  line.DrawLine(1.397, 1, 1.397, 3);
  c1-> Print("pic/discussion/phase_B.png");
  c1-> Print("pic/discussion/phase_B.eps");
}
