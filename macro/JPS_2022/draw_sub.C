#include "macro/init.C"

void draw_sub(){
  init();

  TFile *f=new TFile("~/tmp.root");
  TFile *f2=new TFile("~/spectra.root");
  TGraphErrors *gra=(TGraphErrors*)f->Get("sub_CS0");
  gra-> GetYaxis()-> SetRangeUser(0., 30.); 
  gra-> SetMarkerStyle(8);
  gra-> SetLineWidth(3);
  gra-> SetMarkerSize(1.2);

  TGraph *gra1=(TGraph*)f2->Get("pimSp_modelA_conv");
  TGraph *gra2=(TGraph*)f2->Get("pipSm_modelA_conv");
  TGraph *gra3=(TGraph*)f2->Get("pimSp_modelB_conv");
  TGraph *gra4=(TGraph*)f2->Get("pipSm_modelB_conv");
  std::vector<double> xarr, y, x2, y2;
  for( int i=0; i<gra1->GetN(); i++ ){
    double x, tmp1, tmp2, tmp3, tmp4;
    gra1-> GetPoint(i, x, tmp1);
    gra2-> GetPoint(i, x, tmp2);
    gra3-> GetPoint(i, x, tmp3);
    gra4-> GetPoint(i, x, tmp4);
    xarr.push_back(x);
    y.push_back(tmp1-tmp2);
    y2.push_back(tmp3-tmp4);
  }
  // TGraph *gra_A=new TGraph(xarr.size(), &xarr[0], &y[0]);
  // TGraph *gra_B=new TGraph(xarr.size(), &xarr[0], &y2[0]);

  TGraph *gra_A=(TGraph*)f2->Get("interfer_A_conv"); 
  TGraph *gra_B=(TGraph*)f2->Get("interfer_B_conv"); 
  gra_A-> SetLineStyle(9);
  gra_B-> SetLineStyle(1);
  gra_A-> SetLineWidth(3);
  gra_B-> SetLineWidth(3);

  f-> ls();
  gra-> Draw("AP");
  gra_A-> Draw("PL");
  gra_B-> Draw("PL");
  c1-> Print("~/ag_Run78/pic/JPS_2022/sub.eps");

}
