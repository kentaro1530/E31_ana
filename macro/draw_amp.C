#include <vector>
#include "macro/init.C"

TGraph* make_gra(char* filepath, int colorID=kBlack){
  ifstream ifs(filepath);

  std::vector<double> xarr, yarr;
  std::string str;
  while( getline(ifs, str) ){
    double x, y;
    if( sscanf(str.c_str(), "%lf %lf", &x, &y)==2 ){
      xarr.push_back(0.001*x);
      yarr.push_back(y);
    }
  }
  return set(new TGraph(xarr.size(), &xarr[0], &yarr[0]), colorID);
}

void draw_amp(){
  init();
  const double kpThre=kpMass+pMass;
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);

  TGraph *gra_pimSp_A=make_gra("txt/pimSp_A.txt", kRed);
  TGraph *gra_pimSp_B=make_gra("txt/pimSp_B.txt", kBlue);
  TGraph *gra_pipSm_A=make_gra("txt/pipSm_A.txt", kRed);
  TGraph *gra_pipSm_B=make_gra("txt/pipSm_B.txt", kBlue);
  TGraph *gra_pimS0_A=make_gra("txt/pimS0_A.txt", kRed);
  TGraph *gra_pimS0_B=make_gra("txt/pimS0_B.txt", kBlue);
  gra_pimSp_A-> Draw("AL");
  gra_pimSp_B-> Draw("L");
  line.DrawLine(kpThre, 0, kpThre, 35);
  TLegend *leg=new TLegend(0.2, 0.6, 0.5, 0.9);
  leg-> SetBorderSize(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(gra_pimSp_A, "Model. A", "L");
  leg-> AddEntry(gra_pimSp_B, "Model. B", "L");
  leg-> Draw();
  c1-> Print("pic/discussion/DCC_pimSp.eps");

  gra_pipSm_A-> Draw("AL");
  gra_pipSm_B-> Draw("L");
  line.DrawLine(kpThre, 0, kpThre, 35);
  leg-> Draw();
  c1-> Print("pic/discussion/DCC_pipSm.eps");

  gra_pimS0_A-> GetYaxis()-> SetRangeUser(0, 10);
  gra_pimS0_A-> Draw("AL");
  gra_pimS0_B-> Draw("L");
  line.DrawLine(kpThre, 0, kpThre, 35);
  leg-> Draw();
  c1-> Print("pic/discussion/DCC_pimS0.eps");
}

TGraph* set(TGraph* gra, int colorID){
  gra-> SetMarkerStyle(8);
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(2);
  gra-> GetXaxis()-> SetRangeUser(1.30, 1.55);
  gra-> GetYaxis()-> SetRangeUser(0, 35);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  gra->GetXaxis()->SetTitle("#pi#Sigma mass [GeV/c^{2}]");
  gra->GetYaxis()->SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  return gra;
}
