#include "../init.C"
#include "../make_gra.C"

const TString infileroot="~/spectra_fit.root";
const TString outfile="~/fit_model_B.root";

void draw(TFile *f, TString dirname);
void printParam(TFile *f, TString dirname);
TGraphErrors* setStyle(TGraphErrors* gra);

void draw_fit_B(){
  init();
  TFile *f=new TFile(infileroot);
  TFile *of=new TFile(outfile, "update");
  draw(f, "fit_model_B_fix_Phi");
  printParam(f, "fit_model_B");
}

void printParam(TFile *f, TString dirname){
  TDirectory *dir=(TDirectory*)f-> Get(dirname);
  TNtuple *tup=(TNtuple*)dir->Get("fit_params");
  Float_t chi2, ndf, par[3], err[3];
  tup-> SetBranchAddress("chi2", &chi2);
  tup-> SetBranchAddress("NDF", &ndf);
  tup-> SetBranchAddress("A_I0", &par[0]);
  tup-> SetBranchAddress("A_I1", &par[1]);
  tup-> SetBranchAddress("epsilon", &par[2]);
  tup-> SetBranchAddress("A_I0_err", &err[0]);
  tup-> SetBranchAddress("A_I1_err", &err[1]);
  tup-> SetBranchAddress("epsilon_err", &err[2]);
  tup-> GetEntry(0);
  std::cout<<"Chi2/NDF = "<<chi2<<"/"<<ndf<<" ~ "<<chi2/ndf<<std::endl;
  std::cout<<"A I=0 : "<<par[0]<<" +- "<<err[0]<<std::endl;
  std::cout<<"A I=1 : "<<par[1]<<" +- "<<err[1]<<std::endl;
  std::cout<<"epsilon : "<<par[2]<<" +- "<<err[2]<<std::endl;
}

TLegend *makeLegend(double x0=0.15, double y0=0.5, double x1=0.5, double y1=0.9){
  TLegend* leg=new TLegend(x0, y0, x1, y1);
  leg-> SetFillStyle(0);
  leg-> SetBorderSize(0);
  return leg;
}

void draw(TFile *f, TString dirname){
  TCanvas *c1 = new TCanvas("c1", "c1");
  const double kpThre=kpMass+pMass;
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);
  TGraphErrors *gra_pimSp_CS=setStyle((TGraphErrors*)f->Get("gra_pimSp_CS"));
  TGraphErrors *gra_pipSm_CS=setStyle((TGraphErrors*)f->Get("gra_pipSm_CS"));
  TGraphErrors *gra_pimS0_CS=setStyle((TGraphErrors*)f->Get("gra_pimS0_CS"));
  TGraphErrors *gra_data_I0=setStyle(make_data_I0());
  TGraphErrors *gra_sub=setStyle(make_data_sub());

  TDirectory *dir=(TDirectory*)f-> Get(dirname);
  TNtuple *tup=(TNtuple*)dir->Get("fit_params");
  Float_t chi2, ndf, par[3], err[3];
  tup-> SetBranchAddress("chi2", &chi2);
  tup-> SetBranchAddress("NDF", &ndf);
  tup-> SetBranchAddress("A_I0", &par[0]);
  tup-> SetBranchAddress("A_I1", &par[1]);
  tup-> SetBranchAddress("epsilon", &par[2]);
  tup-> SetBranchAddress("A_I0_err", &err[0]);
  tup-> SetBranchAddress("A_I1_err", &err[1]);
  tup-> SetBranchAddress("epsilon_err", &err[2]);
  tup-> GetEntry(0);

  std::cout<<par[0]<<"  "<<par[1]<<"  "<<par[2]<<std::endl;

  //  dir-> cd();
  TGraph *gra_I0=(TGraph*)dir->Get("gra_I0");
  TGraph *gra_I1=(TGraph*)dir->Get("gra_I1");
  TGraph *gra_pimSp=(TGraph*)dir->Get("gra_pimSp");
  TGraph *gra_pipSm=(TGraph*)dir->Get("gra_pipSm");
  TGraph *gra_pimS0=(TGraph*)dir->Get("gra_pimS0");
  TGraph *gra_interfer=(TGraph*)dir->Get("gra_interfer");
  gra_interfer=scale(gra_interfer, 2.0);
  for( int i=0; i<gra_I0->GetN(); i++ ){
    double x0, x1, x_i, x_Sp, x_Sm, y0, y1, y_i, y_Sp, y_Sm;
    gra_I0-> GetPoint(i, x0, y0);
    gra_I1-> GetPoint(i, x1, y1);
    gra_interfer-> GetPoint(i, x_i, y_i);
    gra_pimSp-> GetPoint(i, x_Sp, y_Sp);    
    gra_pipSm-> GetPoint(i, x_Sm, y_Sm);    
  }

  gSystem-> Exec(Form("mkdir -p pic/Dron/%s", dirname.Data()));
  gra_pimSp_CS-> SetLineColor(kRed);
  gra_pimSp_CS-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pipSm_CS-> SetLineColor(kBlue);
  gra_pipSm_CS-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pimS0_CS-> SetLineColor(kBlack);
  gra_pimS0_CS-> GetYaxis()-> SetRangeUser(0., 8.);
  gra_pimSp-> SetLineColor(kRed);
  gra_pipSm-> SetLineColor(kBlue);
  gra_data_I0-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_data_I0-> GetYaxis()-> SetRangeUser(0.0, 30);
  gra_sub-> GetYaxis()-> SetRangeUser(0.0, 30);

  gra_pimSp-> SetLineWidth(4);
  gra_pipSm-> SetLineWidth(4);
  gra_pimS0-> SetLineWidth(4);

  gra_pimS0-> SetLineColor(kBlue);
  gra_I1-> SetLineColor(kBlue);
  gra_I0-> SetLineColor(kBlue);
  gra_interfer-> SetLineColor(kBlue);
  gra_interfer-> SetLineWidth(3);
  gra_I0-> SetLineWidth(3);

  gra_data_I0-> Draw("AP");
  gra_I0-> Draw("L");
  gra_data_I0-> Write("gra_data_I0");
  gra_I0-> Write("gra_I0_B_scale");
  line.DrawLine(kpThre, 0., kpThre, 30);
  c1->Print(Form("pic/Dron/%s/I0_fit.eps", dirname.Data()));

  gra_sub-> Draw("AP");
  gra_interfer-> Draw("L");
  line.DrawLine(kpThre, 0., kpThre, 30);
  gra_sub-> Write("gra_sub");
  gra_interfer-> Write("gra_interfer_B_scale");
  c1->Print(Form("pic/Dron/%s/interfer_fit.eps", dirname.Data()));

  gra_pimSp_CS-> Draw("AP");
  gra_pimSp-> Draw("L");
  line.DrawLine(kpThre, 0., kpThre, 30);
  gra_pimSp_CS-> Write("gra_pimSp_CS");
  gra_pimSp-> Write("gra_pimSp_B_scale");
  c1->Print(Form("pic/Dron/%s/pimSp_fit.eps", dirname.Data()));

  gra_pipSm_CS-> Draw("AP");
  gra_pipSm-> Draw("L");
  line.DrawLine(kpThre, 0., kpThre, 30);
  gra_pipSm_CS-> Write("gra_pipSm_CS");
  gra_pipSm-> Write("gra_pipSm_B_scale");
  c1->Print(Form("pic/Dron/%s/pipSm_fit.eps", dirname.Data()));

  gra_pimS0_CS-> Draw("AP");
  gra_pimS0-> Draw("L");
  line.DrawLine(kpThre, 0., kpThre, 8);
  gra_pimS0_CS-> Write("gra_pimS0_CS");
  gra_pimS0-> Write("gra_pimS0_B_scale");
  c1->Print(Form("pic/Dron/%s/pimS0_fit.eps", dirname.Data()));
}

TGraphErrors* setStyle(TGraphErrors* gra){
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);

  gra-> GetXaxis()-> CenterTitle();
  gra-> GetXaxis()->SetLabelSize(0.05);
  gra-> GetXaxis()->SetTitleSize(0.06);
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");

  gra-> GetYaxis()-> CenterTitle();
  gra-> GetYaxis()->SetLabelSize(0.05);
  gra-> GetYaxis()->SetTitleSize(0.06);
  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");

  gra-> SetLineWidth(3);
  gra-> SetTitle("");

  return gra;
}
