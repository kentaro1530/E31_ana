#include "macro/init.C"

void draw_scat_amp_I1(){
  init();
  TFile *f=new TFile("scat_test.root");
  TCanvas *c1=new TCanvas("c1", "c1");
  const double kn_thre=(kpMass+k0Mass+nMass+pMass)/2;

  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);

  TGraph *KN_KN_re=set((TGraph*)f->Get("KN_KN_re"), -2, 3);
  c1-> Update();
  TGraph *KN_KN_im=set((TGraph*)f->Get("KN_KN_im"), 0, 15, kRed);
  c1-> Update();

  KN_KN_re-> Draw("AL");
  KN_KN_im-> Draw("L");
  line.DrawLine(kn_thre, -2, kn_thre, 3);

  line.SetLineColor(kBlue);
  line.DrawLine(1.4177, -2, 1.4177, 3);

  double re=-0.323*1.9733;
  double re_err=-0.074*1.9733;

  double im=0.407*1.9733;
  double im_err=-0.308*1.9733;

  TBox box;
  box.SetLineWidth(3);
  box.SetFillStyle(0);
  box.DrawBox(kpMass+pMass, re-re_err, k0Mass+nMass, re+re_err);
  line.SetLineWidth(3);
  line.SetLineColor(kBlack);
  line.DrawLine(kpMass+pMass, re, k0Mass+nMass, re);

  box.SetLineColor(kRed);
  box.DrawBox(kpMass+pMass, im-im_err, k0Mass+nMass, im+im_err);
  line.SetLineColor(kRed);
  line.DrawLine(kpMass+pMass, im, k0Mass+nMass, im);

  c1-> Print("pic/Dron/scat_amp.eps");
  c1-> Print("pic/Dron/scat_amp.png");
}

TGraph* set(TGraph* gra, double min, double max, int colorID=kBlack){
  gra-> SetMarkerStyle(8);
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(2);
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra-> GetYaxis()-> SetRangeUser(min, max);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  //  gra-> GetXaxis()-> SetLabelOffset(999);
  //  gra-> GetYaxis()-> SetLabelOffset(999);
  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  gra->GetYaxis()->SetTitle("T^{I=0}_{#bar{K}N #rightarrow #bar{K}N} [GeV/c^{2}]");
  gra->GetXaxis()->SetTitle("#pi#Sigma mass [GeV/c^{2}]");

  return gra;
}
