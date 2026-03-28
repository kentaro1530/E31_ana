#include "../init.C"
#include "../make_gra.C"

const TString infileroot="~/spectra_fit.root";

TGraphErrors* setStyle(TGraphErrors* gra);

void draw_kamano(){
  init();
  TFile *f=new TFile(infileroot);
  TCanvas *c1 = new TCanvas("c1", "c1");
  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(3);
  //  TGraphErrors *gra_pimSp_CS=setStyle((TGraphErrors*)f->Get("gra_pimSp_CS"));
  //  TGraphErrors *gra_pipSm_CS=setStyle((TGraphErrors*)f->Get("gra_pipSm_CS"));
  TGraphErrors *gra_pimS0_CS=setStyle((TGraphErrors*)f->Get("gra_pimS0_CS"));
  TGraphErrors *gra_data_I0=setStyle(make_data_I0());
  TGraphErrors *gra_sub=setStyle(make_data_sub());

  TDirectory *dir_A=(TDirectory*)f-> Get("fit_model_A_fix_Phi");
  TDirectory *dir_B=(TDirectory*)f-> Get("fit_model_B_fix_Phi");

  TGraph *gra_I0_A=(TGraph*)dir_A->Get("gra_I0");
  TGraph *gra_I1_A=(TGraph*)dir_A->Get("gra_I1");
  TGraph *gra_pimSp_A=(TGraph*)dir_A->Get("gra_pimSp");
  TGraph *gra_pipSm_A=(TGraph*)dir_A->Get("gra_pipSm");
  TGraph *gra_pimS0_A=(TGraph*)dir_A->Get("gra_pimS0");
  TGraph *gra_interfer_A=(TGraph*)dir_A->Get("gra_interfer");

  TGraph *gra_I0_B=(TGraph*)dir_B->Get("gra_I0");
  TGraph *gra_I1_B=(TGraph*)dir_B->Get("gra_I1");
  TGraph *gra_pimSp_B=(TGraph*)dir_B->Get("gra_pimSp");
  TGraph *gra_pipSm_B=(TGraph*)dir_B->Get("gra_pipSm");
  TGraph *gra_pimS0_B=(TGraph*)dir_B->Get("gra_pimS0");
  TGraph *gra_interfer_B=(TGraph*)dir_B->Get("gra_interfer");

  TNtuple *tup_A=(TNtuple*)dir_A->Get("fit_params");
  Float_t chi2_A, ndf_A, par_A[3], err_A[3];
  tup_A-> SetBranchAddress("chi2", &chi2_A);
  tup_A-> SetBranchAddress("NDF", &ndf_A);
  tup_A-> SetBranchAddress("A_I0", &par_A[0]);
  tup_A-> SetBranchAddress("A_I1", &par_A[1]);
  tup_A-> SetBranchAddress("epsilon", &par_A[2]);
  tup_A-> SetBranchAddress("A_I0_err", &err_A[0]);
  tup_A-> SetBranchAddress("A_I1_err", &err_A[1]);
  tup_A-> SetBranchAddress("epsilon_err", &err_A[2]);
  tup_A-> GetEntry(0);

  TNtuple *tup_B=(TNtuple*)dir_B->Get("fit_params");
  Float_t chi2_B, ndf_B, par_B[3], err_B[3];
  tup_B-> SetBranchAddress("chi2", &chi2_B);
  tup_B-> SetBranchAddress("NDF", &ndf_B);
  tup_B-> SetBranchAddress("A_I0", &par_B[0]);
  tup_B-> SetBranchAddress("A_I1", &par_B[1]);
  tup_B-> SetBranchAddress("epsilon", &par_B[2]);
  tup_B-> SetBranchAddress("A_I0_err", &err_B[0]);
  tup_B-> SetBranchAddress("A_I1_err", &err_B[1]);
  tup_B-> SetBranchAddress("epsilon_err", &err_B[2]);
  tup_B-> GetEntry(0);

  gra_pimS0_CS-> GetYaxis()-> SetRangeUser(0, 8);
  gra_pimS0_CS-> Draw("AP");
  gra_I1_A = scale(gra_I1_A, 2/par_A[1]);
  gra_I1_B = scale(gra_I1_B, 2/par_B[1]);
  gra_I1_A-> SetLineWidth(2);
  gra_I1_A-> SetLineColor(kRed);
  gra_I1_B-> SetLineWidth(2);
  gra_I1_B-> SetLineColor(kBlue);
  gra_I1_A-> Draw("PL");
  gra_I1_B-> Draw("PL");
  c1-> Print("../ana/Dron/Dron/pic/kamano_I0.eps");

  gra_data_I0-> GetYaxis()-> SetRangeUser(0, 17);
  gra_data_I0-> Draw("AP");
  gra_I0_A = scale(gra_I0_A, 1/par_A[0]);
  gra_I0_B = scale(gra_I0_B, 1/par_B[0]);
  gra_I0_A-> SetLineWidth(2);
  gra_I0_A-> SetLineColor(kRed);
  gra_I0_B-> SetLineWidth(2);
  gra_I0_B-> SetLineColor(kBlue);  
  gra_I0_A-> Draw("PL");
  gra_I0_B-> Draw("PL");
  c1-> Print("../ana/Dron/Dron/pic/kamano_I1.eps");

  gra_sub-> GetYaxis()-> SetRangeUser(0, 25);
  gra_sub-> Draw("AP");  
  gra_interfer_A = scale(gra_interfer_A, 1/sqrt(par_A[0]*par_A[1]));
  gra_interfer_B = scale(gra_interfer_B, 1/sqrt(par_B[0]*par_B[1]));
  gra_interfer_A-> SetLineWidth(2);
  gra_interfer_A-> SetLineColor(kRed);
  gra_interfer_B-> SetLineWidth(2);
  gra_interfer_B-> SetLineColor(kBlue);  
  gra_interfer_A-> Draw("PL"); 
  gra_interfer_B-> Draw("PL");
  c1-> Print("../ana/Dron/Dron/pic/kamano_interfer.eps");
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
