#include "../init.C"

TGraphErrors* setOpts(TGraphErrors* gra, int color=kBlack);

std::vector<TGraphErrors*> readFile(TString filename, int color=kBlack){
  std::ifstream ifs(filename);
  std::string str;
  std::vector<double> x, y, xerr, err0, err1;
  while( getline(ifs, str) ){
    double mm, cs, width, yerr0, yerr1;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf", &mm, &cs, &width, &yerr0, &yerr1)==5 ){
      x.push_back(mm);
      y.push_back(cs);
      xerr.push_back(width);
      err0.push_back(yerr0);
      err1.push_back(yerr1);
    }
  }

  std::vector<TGraphErrors*> gras;
  gras.push_back(setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &err1[0]), color));
  gras.push_back(setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &err0[0]), color));
  return gras;
}

void draw_pimL_CS(){
  init();
  TCanvas *c1 = new TCanvas();
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);
  const double kpThre = kpMass + pMass;
  
  std::vector<TGraphErrors*> gra_pimL  = readFile("../ag_Run78/txt/Run68/pimL_CS.txt", 6);
  std::vector<TGraphErrors*> gra_pimS0 = readFile("../ag_Run78/txt/Run68/pimS0_CS.txt", 5);
  gra_pimS0[0]-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pimS0[0]-> GetYaxis()-> SetRangeUser(0.0, 8.0);
  gra_pimS0[0]-> GetYaxis()-> SetTitle(TITLE_CS);
  gra_pimS0[0]-> GetXaxis()-> SetTitle("d(K^{-}, p)\"#pi^{-}#Lambda\" [GeV/c^{2}]");
  gra_pimS0[0]-> SetLineWidth(1);
  gra_pimS0[1]-> SetFillStyle(0);
  gra_pimS0[1]-> SetLineWidth(1);

  gra_pimS0[0]-> Draw("AP");
  gra_pimS0[1]-> Draw("P2");

  gra_pimL[1]-> SetFillStyle(0);
  gra_pimL[0]-> Draw("P");
  gra_pimL[1]-> Draw("P2");
  line.DrawLine(kpThre, 0, kpThre, 8);
  
  TLegend *leg = new TLegend(0.2, 0.65, 0.5, 0.8);
  leg-> SetFillStyle(0);
  leg-> SetBorderSize(0);
  leg-> AddEntry(gra_pimL[0],  "d(K^{-}, p)\"#pi^{-}#Lambda\"", "lep");
  leg-> AddEntry(gra_pimS0[0], "d(K^{-}, p)\"#pi^{-}#Sigma^{0}\"", "lep");
  leg-> Draw();
  c1-> Print("pic/Dron/KP_ana/pimL_CS.png");
  c1-> Print("pic/Dron/KP_ana/pimL_CS.eps");
}

TGraphErrors* setOpts(TGraphErrors* gra, int color){
  gra-> SetMarkerStyle(8);
  gra-> SetLineWidth(2);
  gra-> SetMarkerColor(color);
  gra-> SetLineColor(color);
  gra-> SetLineWidth(2);
  gra->SetTitle("");
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  return gra;
}
