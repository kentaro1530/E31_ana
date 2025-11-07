#include "../init.C"

const TString infileroot="~/spectra.root";

TGraphErrors* scale(TGraphErrors *gra){
  for( int i=0; i<gra-> GetN(); i++ ){
    double errx = gra->GetErrorX(i);
    double erry = gra->GetErrorY(i);
    double x, y;
    gra-> GetPoint(i, x, y);
    gra-> SetPointError(i, errx, 0.5*erry);
    gra-> SetPoint(i, x, 0.5*y);
  }
  return gra;
}

void draw_data(){
  init();

  TFile *f=new TFile(infileroot);
  TGraphErrors *gra_pimSp_data=(TGraphErrors*)f->Get("pimSp_CS0");
  TGraphErrors *gra_pipSm_data=(TGraphErrors*)f->Get("pipSm_CS0");
  TGraphErrors *gra_pimS0_data=scale((TGraphErrors*)f->Get("pimS0_CS0"));
  const double kpThre=kpMass+pMass;
  TCanvas *c1 = new TCanvas();
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);
  TArrow arr;
  TLatex latex;
  arr.SetLineWidth(2);
  gra_pimSp_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  gra_pimSp_data-> GetYaxis()-> SetRangeUser(0., 35.);
  gra_pimSp_data-> SetLineColor(kRed);
  gra_pimSp_data-> Draw("AP");
  //  line.DrawLine(kpThre, 0., kpThre, 30);
  line.DrawLine(kpThre, 0., kpThre, 35);
  //  c1-> Print("pic/Dron/pimSp_data2.png");
  //  c1-> Print("pic/Dron/pimSp_data2.eps");

  line.DrawLine(kpThre, 0., kpThre, 30);
  arr.DrawArrow(1.52, 10., 1.52, 6, 0.05, "-|>");
  latex.DrawLatex(1.5, 11, "#Lambda(1520)");
  arr.DrawArrow(1.385, 8.0, 1.385, 4.5, 0.05, "-|>");
  latex.DrawLatex(1.375, 9.0, "#Sigma(1385)");
  //  c1-> Print("pic/Dron/pimSp_data.png");
  //  c1-> Print("pic/Dron/pimSp_data.eps");

  gra_pipSm_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  gra_pipSm_data-> GetYaxis()-> SetRangeUser(0., 35.);
  gra_pipSm_data-> SetLineColor(kBlue);
  //  gra_pipSm_data-> Draw("AP");
  gra_pipSm_data-> Draw("P");
  // line.DrawLine(kpThre, 0., kpThre, 30);
  // c1-> Print("pic/Dron/pipSm_data2.png");
  // c1-> Print("pic/Dron/pipSm_data2.eps");
  // arr.DrawArrow(1.52, 5., 1.52, 2.5, 0.05, "-|>");
  // latex.DrawLatex(1.5, 5.1, "#Lambda(1520)");
  // arr.DrawArrow(1.385, 5., 1.385, 2.5, 0.05, "-|>");
  // latex.DrawLatex(1.375, 6., "#Sigma(1385)");
  //  line.DrawLine(kpThre, 0., kpThre, 30);
  //  c1-> Print("pic/Dron/pipSm_data.png");
  //  c1-> Print("pic/Dron/pipSm_data.eps");
  TLegend *leg = new TLegend(0.7, 0.7, 0.9, 0.9);
  leg-> SetLineWidth(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(gra_pimSp_data, "#pi^{-}#Sigma^{+}", "lep");
  leg-> AddEntry(gra_pipSm_data, "#pi^{+}#Sigma^{-}", "lep");
  leg-> Draw();
  
  gra_pimS0_data-> GetXaxis()-> SetRangeUser(1.35, 1.55);
  gra_pimS0_data-> Draw("P");
  // gra_pimS0_data-> GetYaxis()-> SetRangeUser(0., 10.);
  gra_pimS0_data-> SetLineColor(5);
  leg-> AddEntry(gra_pimS0_data, "#pi^{-}#Sigma^{0}", "lep");
  // gra_pimS0_data-> Draw("AP");
  // line.DrawLine(kpThre, 0., kpThre, 30);
  // c1-> Print("pic/Dron/pimS0_data2.png");
  // c1-> Print("pic/Dron/pimS0_data2.eps");

  // gra_pimS0_data-> GetYaxis()-> SetRangeUser(0., 10.);
  // gra_pimS0_data-> SetLineColor(3);
  // gra_pimS0_data-> Draw("AP");
  // arr.DrawArrow(1.385, 2.0, 1.385, 1.0, 0.05, "-|>");
  // latex.DrawLatex(1.375, 2.1, "#Sigma(1385)");
  // line.DrawLine(kpThre, 0., kpThre, 10);
  // c1-> Print("pic/discussion/pimS0_data.png");
  // c1-> Print("pic/discussion/pimS0_data.eps");

  c1-> Print("pic/cv/All_CS_woK0.png");
  c1-> Print("pic/cv/All_CS_woK0.eps");

}
