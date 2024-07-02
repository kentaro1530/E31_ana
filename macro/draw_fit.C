#include "macro/init.C"

const TString infileroot="~/spectra_fit.root";

// TLegend *makeLegend(double x0=0.15, double y0=0.5, double x1=0.5, double y1=0.9);
// void printParam(TFile *f, TString dirname);
// void draw(TFile *f, TString dirname);

void draw_fit(){
  init();
  TFile *f=new TFile(infileroot);
  draw(f, "fit_model_A_by_phase");
  draw(f, "fit_model_B_by_phase");

  printParam(f, "fit_model_A_by_phase");
  printParam(f, "fit_model_B_by_phase");

  draw(f, "fit_model_A");
  draw(f, "fit_model_B");
  draw(f, "fit_model_A_fix_Phi");
  draw(f, "fit_model_B_fix_Phi");
  draw(f, "fit_model_A_fix_Phi_I0");
  draw(f, "fit_model_B_fix_Phi_I0");
  draw(f, "fit_model_A_fix_I0");
  draw(f, "fit_model_B_fix_I0");
  printParam(f, "fit_model_A");
  printParam(f, "fit_model_B");
  printParam(f, "fit_model_A_fix_Phi");
  printParam(f, "fit_model_B_fix_Phi");
  printParam(f, "fit_model_A_fix_Phi_I0");
  printParam(f, "fit_model_B_fix_Phi_I0");
  printParam(f, "fit_model_A_fix_I0");
  printParam(f, "fit_model_B_fix_I0");
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

void draw(TFile *f, TString dirname, int colorID=kRed){
  const double kpThre=kpMass+pMass;
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);
  TGraphErrors *gra_pimSp_CS=(TGraphErrors*)f->Get("gra_pimSp_CS");
  TGraphErrors *gra_pipSm_CS=(TGraphErrors*)f->Get("gra_pipSm_CS");
  TGraphErrors *gra_pimS0_CS=(TGraphErrors*)f->Get("gra_pimS0_CS");

  TDirectory *dir=(TDirectory*)f-> Get(dirname);
  //  dir-> cd();
  TGraph *gra_I0=(TGraph*)dir->Get("gra_I0");
  TGraph *gra_I1=(TGraph*)dir->Get("gra_I1");
  TGraph *gra_pimSp=(TGraph*)dir->Get("gra_pimSp");
  TGraph *gra_pipSm=(TGraph*)dir->Get("gra_pipSm");
  TGraph *gra_pimS0=(TGraph*)dir->Get("gra_pimS0");
  TGraph *gra_interfer=(TGraph*)dir->Get("gra_interfer");
  for( int i=0; i<gra_I0->GetN(); i++ ){
    double x0, x1, x_i, x_Sp, x_Sm, y0, y1, y_i, y_Sp, y_Sm;
    gra_I0-> GetPoint(i, x0, y0);
    gra_I1-> GetPoint(i, x1, y1);
    gra_interfer-> GetPoint(i, x_i, y_i);
    gra_pimSp-> GetPoint(i, x_Sp, y_Sp);    
    gra_pipSm-> GetPoint(i, x_Sm, y_Sm);    
    // std::cout<<x0<<"    "<<y0<<"   "<<y1<<"   "<<y_i<<"   "<<y_Sp<<"    "<<y_Sm<<std::endl;
    // std::cout<<x0<<"    "<<x0<<"   "<<x1<<"   "<<x_i<<"   "<<x_Sp<<"    "<<x_Sm<<std::endl;

    //    std::cout<<x0<<"    "<<y0+y1+y_i-y_Sp<<"   "<<y0+y1-y_i-y_Sm<<std::endl;
  }

  gSystem-> Exec(Form("mkdir -p pic/discussion/%s", dirname.Data()));
  gra_pimSp_CS-> SetLineColor(kRed);
  gra_pimSp_CS-> GetYaxis()-> SetRangeUser(0., 30.);
  gra_pipSm_CS-> SetLineColor(kBlue);
  gra_pipSm_CS-> GetYaxis()-> SetRangeUser(0., 15.);
  gra_pimS0_CS-> SetLineColor(3);
  gra_pimS0_CS-> GetYaxis()-> SetRangeUser(0., 10.);
  gra_pimSp-> SetLineColor(kRed);
  gra_pipSm-> SetLineColor(kBlue);

  gra_pimSp-> SetLineWidth(4);
  gra_pipSm-> SetLineWidth(4);
  gra_pimS0-> SetLineWidth(4);

  gra_pimS0-> SetLineColor(6);
  gra_I1-> SetLineColor(6);
  gra_interfer-> SetLineColor(6);

  gra_pimSp_CS-> Draw("AP");
  gra_pimSp-> Draw("L");
  gra_I0-> Draw("L");
  gra_I1-> Draw("L");
  gra_interfer-> Draw("L");
  TLegend *leg=makeLegend(); 
  leg-> AddEntry(gra_pimSp_CS, "Data", "lep");
  leg-> AddEntry(gra_pimSp,    "Theoritical Calc.", "lp");
  leg-> AddEntry(gra_I0,       "I=0", "lp");
  leg-> AddEntry(gra_I1,       "I=1", "lp");
  leg-> AddEntry(gra_interfer, "Interfer Term", "lp");
  leg-> Draw();
  line.DrawLine(kpThre, 0., kpThre, 30);
  c1->Print(Form("pic/discussion/%s/pimSp_fit.png", dirname.Data()));
  c1->Print(Form("pic/discussion/%s/pimSp_fit.eps", dirname.Data()));
  gra_pimSp_CS-> GetYaxis()-> SetRangeUser(0., 30.);
  c1->Print(Form("pic/discussion/%s/pimSp_fit_same.png", dirname.Data()));
  c1->Print(Form("pic/discussion/%s/pimSp_fit_same.eps", dirname.Data()));

  gra_pipSm_CS-> Draw("AP");
  gra_pipSm-> Draw("L");
  gra_I0-> Draw("L");
  gra_I1-> Draw("L");
  gra_interfer-> Draw("L");
  TLegend *leg=makeLegend(); 
  leg-> AddEntry(gra_pipSm_CS, "Data", "lep");
  leg-> AddEntry(gra_pipSm,    "Theoritical Calc.", "lp");
  leg-> AddEntry(gra_I0,       "I=0", "lp");
  leg-> AddEntry(gra_I1,       "I=1", "lp");
  leg-> AddEntry(gra_interfer, "Interfer Term", "lp");
  leg-> Draw();
  line.DrawLine(kpThre, 0., kpThre, 15);
  c1->Print(Form("pic/discussion/%s/pipSm_fit.png", dirname.Data()));
  c1->Print(Form("pic/discussion/%s/pipSm_fit.eps", dirname.Data()));
  gra_pipSm_CS-> GetYaxis()-> SetRangeUser(0., 30.);
  c1->Print(Form("pic/discussion/%s/pipSm_fit_same.png", dirname.Data()));
  c1->Print(Form("pic/discussion/%s/pipSm_fit_same.eps", dirname.Data()));

  gra_pimS0_CS-> Draw("AP");
  gra_pimS0-> Draw("L");
  TLegend *leg=makeLegend(); 
  leg-> AddEntry(gra_pimS0_CS, "Data", "lep");
  leg-> AddEntry(gra_pimS0,    "Theoritical Calc.", "lp");
  leg-> Draw();
  line.DrawLine(kpThre, 0., kpThre, 10);
  c1->Print(Form("pic/discussion/%s/pimS0_fit.png", dirname.Data()));
  c1->Print(Form("pic/discussion/%s/pimS0_fit.eps", dirname.Data()));
  gra_pimS0_CS-> GetYaxis()-> SetRangeUser(0., 30.);
  c1->Print(Form("pic/discussion/%s/pimS0_fit_same.png", dirname.Data()));
  c1->Print(Form("pic/discussion/%s/pimS0_fit_same.eps", dirname.Data()));
}
