#include "macro/init.C"

void draw_responseFunc(){
  init();

  TFile *f=new TFile("~/spectra.root");
  TGraphErrors* pimS0_CS=(TGraphErrors*)f->Get("pimS0_CS0");
  pimS0_CS-> GetYaxis()-> SetRangeUser(0, 8);
  TGraph *resF=(TGraph*)f-> Get("responseFunc");
  resF=scale(resF, 0.11);
  resF-> SetLineWidth(2);
  resF-> SetLineColor(kRed);
  pimS0_CS-> Draw("AP");
  resF-> Draw("L");

  c1-> Print("pic/Dron/pimS0_wResF.png");
  c1-> Print("pic/Dron/pimS0_wResF.eps");
}
