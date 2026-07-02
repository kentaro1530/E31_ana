#include "../init.C"

TGraphErrors* setOpts(TGraphErrors* gra, int color=kBlack);

void draw_neutral_trig(){
  init();

  ifstream ifs("../ag_Run78/txt/Run78_run_prod.txt");
  TCanvas *c1 = new TCanvas();
  std::string str;
  std::vector<double> x, y, xerr, yerr;
  
  while( getline(ifs, str) ){
    stringstream ss(str);
    int run;
    ss >> run;
    std::cout<<run<<std::endl;
    TFile *f = new TFile(Form("../ag_Run78/root/Run78/readChk/run%d.root", run));
    TH1F *h1=(TH1F*)f-> Get("trig_chk_N");
    double deno=h1->GetBinContent(5), num=h1->GetBinContent(6);
    double p = num/deno;
    double err = sqrt(p*(1.0-p)/deno);

    x.push_back(run);
    xerr.push_back(0.5);
    y.push_back(p);
    yerr.push_back(err);    
  }

  TGraphErrors *gra = setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr[0]));
  gra-> GetXaxis()-> SetRangeUser(x[0]-5, x[x.size()-1]+5);
  gra-> GetYaxis()-> SetRangeUser(0.5, 1.05);
  gra-> GetXaxis()-> SetTitle("Run Number");
  gra-> GetYaxis()-> SetTitle("Neutral trigger efficiency");
  gra-> Draw("AP");

  c1-> Print("Neutral_wide.eps");
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
