#include "../init.C"

const TString inputText_pimSp="../ag_Run78/txt/Run78/K0_ts/CS_pimSp_after.txt";
const TString inputText_pipSm="../ag_Run78/txt/Run78/K0_ts/CS_pipSm_after.txt";

TGraphErrors* setOpts(TGraphErrors* gra, int color=kBlack);

std::vector<TGraphErrors*> readFile(const TString input_file, int colorID){
  std::ifstream ifs(input_file);
  std::vector<double> x, xerr, y, yerr, yerr2, yerr3;
  std::string str;

  while( getline(ifs, str) ){
    double tmpx, tmpy, tmp_errx, tmp_erry, tmp_erry2, tmp_erry3;
    if( sscanf(str.c_str(), "%lf %lf %lf %lf %lf %lf", &tmpx, &tmpy, &tmp_errx, &tmp_erry, &tmp_erry2, &tmp_erry3)==6 ){
      x.push_back(tmpx);
      y.push_back(tmpy);
      xerr.push_back(tmp_errx);
      yerr.push_back(tmp_erry);
      yerr2.push_back(tmp_erry2);
      yerr3.push_back(tmp_erry3);
    }
    //    else std::cout<<str<<std::endl;
  }
  std::vector<TGraphErrors*> gras;
  gras.push_back(setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr3[0]), colorID));
  gras.push_back(setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr2[0]), colorID));
  gras.push_back(setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr[0]), colorID));

  return gras;
}

void drawChargeCS(){
  init();
  TCanvas *c1 = new TCanvas();
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);
  const double kpThre = kpMass + pMass;

  //  TFile *f = new TFile("~/spectra.root");
  //  TGraphErrors *gra_pimSp0 = setOpts((TGraphErrors*)f->Get("pimSp_CS0"), kRed);
  //  TGraphErrors *gra_pimSp1 = setOpts((TGraphErrors*)f->Get("pimSp_CS1"), kRed);
  //  TGraphErrors *gra_pimSp2 = setOpts((TGraphErrors*)f->Get("pimSp_CS2"), kRed);
  std::vector<TGraphErrors*> gra_pimSp = readFile(inputText_pimSp, kRed);
  gra_pimSp[0]-> GetXaxis()-> SetTitle("d(K^{-}, n)\"#pi^{#mp}#Sigma^{#pm}\" [GeV/c^{2}]");
  gra_pimSp[0]-> GetYaxis()-> SetTitle(TITLE_CS);
  gra_pimSp[0]-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_pimSp[0]-> GetYaxis()-> SetRangeUser(0, 35);
  gra_pimSp[1]-> SetFillStyle(0);
  gra_pimSp[2]-> SetFillStyle(0);
  gra_pimSp[2]-> SetLineWidth(1);
  gra_pimSp[0]-> Draw("AP");
  gra_pimSp[1]-> Draw("P2");
  gra_pimSp[2]-> Draw("P2");

  std::vector<TGraphErrors*> gra_pipSm = readFile(inputText_pipSm, kBlue);
  gra_pipSm[1]-> SetFillStyle(0);
  gra_pipSm[2]-> SetFillStyle(0);
  gra_pipSm[2]-> SetLineWidth(1);
  gra_pipSm[0]-> Draw("P");
  gra_pipSm[1]-> Draw("P2");
  gra_pipSm[2]-> Draw("P2");
  
  // TGraphErrors *gra_pipSm0 = setOpts((TGraphErrors*)f->Get("pipSm_CS0"), kBlue);
  // TGraphErrors *gra_pipSm1 = setOpts((TGraphErrors*)f->Get("pipSm_CS1"), kBlue);
  // TGraphErrors *gra_pipSm2 = setOpts((TGraphErrors*)f->Get("pipSm_CS2"), kBlue);
  // gra_pipSm1-> SetFillStyle(0);
  // gra_pipSm2-> SetFillStyle(0);
  // gra_pipSm2-> SetLineWidth(1);
  // gra_pipSm0-> Draw("P");
  // gra_pipSm1-> Draw("P2");
  // gra_pipSm2-> Draw("P2");
  line.DrawLine(kpThre, 0, kpThre, 35);

  TLegend *leg=new TLegend(0.2, 0.7, 0.5, 0.9);
  leg-> SetFillStyle(0); leg-> SetBorderSize(0);
  leg-> AddEntry(gra_pimSp[2], "#pi^{-}#Sigma^{+} mode", "lep");
  leg-> AddEntry(gra_pipSm[2], "#pi^{+}#Sigma^{-} mode", "lep");
  leg-> Draw();

  c1-> Print("ChargeCS.eps");
  c1-> Print("ChargeCS.png");  
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

