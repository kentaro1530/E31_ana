#include "macro/init.C"

void draw_fit_scat_amp_I0(){
  init();

  TFile *f=new TFile("~/spectra_fit_scat_amp_I0.root");
  float pole, width;

  /*********************/
  /*** K-p Threshold ***/
  /*********************/
  // printParam(f, "Kmp", pole, width);
  // draw(f, "Kmp");
  // c1-> Print("pic/Dron/fit_I0_Kmp.eps");
  // drawPole(f, "Kmp", pole);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp.eps");
  // drawWidth(f, "Kmp", width);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp.eps");
  // drawScatAmp(f, "Kmp");
  // c1-> Print("pic/Dron/fit_scat_amp_I0_Kmp.eps");
  // drawPole2(f, "Kmp", pole, 1.5);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus_r15.eps");
  // drawPole2(f, "Kmp", pole, 1.75);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus_r175.eps");
  // drawPole2(f, "Kmp", pole, 2);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus_r2.eps");
  // drawPole2(f, "Kmp", pole, 2.25);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus_r225.eps");
  // drawPole2(f, "Kmp", pole, 2.5);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus_r25.eps");
  // drawPole2(f, "Kmp", pole, 2.75);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus_r275.eps");
  // drawPole2(f, "Kmp", pole, 3);
  // c1-> Print("pic/Dron/fit_pole_gaus_Kmp_fit2Gaus_r3.eps");

  // drawWidth2(f, "Kmp", width, 1.5);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus_r15.eps");
  // drawWidth2(f, "Kmp", width, 1.75);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus_r175.eps");
  // drawWidth2(f, "Kmp", width, 2);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus_r2.eps");
  // drawWidth2(f, "Kmp", width, 2.25);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus_r225.eps");
  // drawWidth2(f, "Kmp", width, 2.5);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus_r25.eps");
  // drawWidth2(f, "Kmp", width, 2.75);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus_r275.eps");
  // drawWidth2(f, "Kmp", width, 3);
  // c1-> Print("pic/Dron/fit_width_gaus_Kmp_fit2Gaus_r3.eps");

  /********************/
  /*** KN threshold ***/
  /********************/
  printParam(f, "KN", pole, width);
  std::cout<<pole<<"   "<<width<<std::endl;
  draw(f, "KN");
  c1-> Print("pic/Dron/fit_I0_KN.eps");
  drawPole(f, "KN", pole);
  c1-> Print("pic/Dron/fit_pole_gaus_KN.eps");
  drawWidth(f, "KN", width);
  c1-> Print("pic/Dron/fit_width_gaus_KN.eps");
  drawScatAmp(f, "KN");
  c1-> Print("pic/Dron/fit_scat_amp_I0_KN.eps");

  // drawPole2(f, "KN", pole, 1.5);
  // c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus_r15.eps");
  // drawPole2(f, "KN", pole, 1.75);
  // c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus_r175.eps");
  // drawPole2(f, "KN", pole, 2);
  // c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus_r2.eps");
  // drawPole2(f, "KN", pole, 2.25);
  // c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus_r225.eps");
  // drawPole2(f, "KN", pole, 2.5);
  // c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus_r25.eps");
  // drawPole2(f, "KN", pole, 2.75);
  // c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus_r275.eps");
  // drawPole2(f, "KN", pole, 3);
  // c1-> Print("pic/Dron/fit_pole_gaus_KN_fit2Gaus_r3.eps");

  // drawWidth2(f, "KN", width, 1.5);
  // c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus_r15.eps");
  // drawWidth2(f, "KN", width, 1.75);
  // c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus_r175.eps");
  // drawWidth2(f, "KN", width, 2);
  // c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus_r2.eps");
  // drawWidth2(f, "KN", width, 2.25);
  // c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus_r225.eps");
  // drawWidth2(f, "KN", width, 2.5);
  // c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus_r25.eps");
  // drawWidth2(f, "KN", width, 2.75);
  // c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus_r275.eps");
  // drawWidth2(f, "KN", width, 3);
  // c1-> Print("pic/Dron/fit_width_gaus_KN_fit2Gaus_r3.eps");

  /*********************/
  /*** K0N Threshold ***/
  /*********************/
  // printParam(f, "KzeroN", pole, width);
  // draw(f, "KzeroN");
  // c1-> Print("pic/Dron/fit_I0_KzeroN.eps");
  // drawPole(f, "KzeroN", pole);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN.eps");
  // drawWidth(f, "KzeroN", width);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN.eps");
  // drawScatAmp(f, "KzeroN");
  // c1-> Print("pic/Dron/fit_scat_amp_I0_KzeroN.eps");

  // drawPole2(f, "KzeroN", pole, 1.5);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus_r15.eps");
  // drawPole2(f, "KzeroN", pole, 1.75);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus_r175.eps");
  // drawPole2(f, "KzeroN", pole, 2);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus_r2.eps");
  // drawPole2(f, "KzeroN", pole, 2.25);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus_r225.eps");
  // drawPole2(f, "KzeroN", pole, 2.5);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus_r25.eps");
  // drawPole2(f, "KzeroN", pole, 2.75);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus_r275.eps");
  // drawPole2(f, "KzeroN", pole, 3);
  // c1-> Print("pic/Dron/fit_pole_gaus_KzeroN_fit2Gaus_r3.eps");

  // drawWidth2(f, "KzeroN", width, 1.5);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus_r15.eps");
  // drawWidth2(f, "KzeroN", width, 1.75);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus_r175.eps");
  // drawWidth2(f, "KzeroN", width, 2);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus_r2.eps");
  // drawWidth2(f, "KzeroN", width, 2.25);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus_r225.eps");
  // drawWidth2(f, "KzeroN", width, 2.5);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus_r25.eps");
  // drawWidth2(f, "KzeroN", width, 2.75);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus_r275.eps");
  // drawWidth2(f, "KzeroN", width, 3);
  // c1-> Print("pic/Dron/fit_width_gaus_KzeroN_fit2Gaus_r3.eps");
}

bool drawPole(TFile *f, TString dirName, float pole){
  TDirectory* dir=(TDirectory*)f->Get(dirName);

  TH1F *h1=set((TH1F*)dir-> Get("Pole_dist_gauss"));
  h1-> GetXaxis()-> SetTitle("M_{#pi #Sigma} [GeV]");
  h1-> GetYaxis()-> SetTitle("Count");
  h1-> Draw();

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(pole, 0, pole, 1.1*h1->GetMaximum());

  h1-> Fit("gaus", "q0");
  double mean=h1->GetFunction("gaus")-> GetParameter(1);
  double sigma=h1->GetFunction("gaus")-> GetParameter(2);
  TF1* gaus=(TF1*)h1->GetFunction("gaus");

  TF1 *func=(TF1*)gROOT->FindObject("double_gaus");
  func-> SetParameter(0, h1->GetMaximum());
  func-> SetParameter(1, h1->GetBinCenter(h1->GetMaximumBin()));
  func-> SetParameter(2, 0.6*h1->GetRMS());
  func-> SetParameter(3, 0.4*h1->GetRMS());
  func-> SetLineColor(kBlue);
  h1-> Fit("double_gaus", "+q0", "");

  func-> SetLineColor(3);
  double mean2=func->GetParameter(1);
  double sigma_l=func->GetParameter(2);
  double sigma_h=func->GetParameter(3);
  double h_mean=h1->GetMean();
  double RMS=h1->GetRMS();

  line.SetLineColor(kRed);
  line.DrawLine(mean, 0, mean, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(mean-sigma, 0, mean-sigma, 1.05*h1->GetMaximum());
  line.DrawLine(mean+sigma, 0, mean+sigma, 1.05*h1->GetMaximum());

  line.SetLineStyle(1);
  line.SetLineColor(kBlue);
  line.DrawLine(mean2, 0, mean2, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(mean2-sigma_l, 0, mean2-sigma_l, 1.05*h1->GetMaximum());
  line.DrawLine(mean2+sigma_h, 0, mean2+sigma_h, 1.05*h1->GetMaximum());
  
  line.SetLineStyle(1);
  line.SetLineColor(1);
  line.DrawLine(h_mean, 0, h_mean, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(h_mean-RMS, 0, h_mean-RMS, 1.05*h1->GetMaximum());
  line.DrawLine(h_mean+RMS, 0, h_mean+RMS, 1.05*h1->GetMaximum());

  // std::cout<<"Gaussian chi2/NDF = "<<gaus->GetChisquare()<<"/"<<gaus->GetNDF()<<" = "<<gaus->GetChisquare()/gaus->GetNDF()<<std::endl;
  // std::cout<<gaus->GetParameter(1)<<" +- "<<gaus->GetParError(1)<<std::endl;
  // std::cout<<gaus->GetParameter(2)<<" +- "<<gaus->GetParError(2)<<std::endl;

  // std::cout<<"Gaussian chi2/NDF = "<<func->GetChisquare()<<"/"<<func->GetNDF()<<" = "<<func->GetChisquare()/func->GetNDF()<<std::endl;
  // std::cout<<func->GetParameter(1)<<" +- "<<func->GetParError(1)<<std::endl;
  // std::cout<<func->GetParameter(2)<<" +- "<<func->GetParError(2)<<std::endl;
  // std::cout<<func->GetParameter(3)<<" +- "<<func->GetParError(3)<<std::endl;

  // std::cout<<h1->GetMean()<<std::endl;
  // std::cout<<h1->GetRMS()<<Std::endl;

  // std::cout<<"Pole : "<<pole<<"   + "<<sigma+mean-pole<<"   - "<<pole-mean+sigma<<std::endl;
  // std::cout<<"       "<<mean<<"   "<<sigma<<"  + "<<sigma+mean-pole<<"   - "<<pole-mean+sigma<<std::endl;
  // std::cout<<"       "<<mean2<<"  "<<sigma_h<<" "<<sigma_l<<"  + "<<sigma_h+mean2-pole<<"   - "<<pole-mean2+sigma_l<<std::endl;
  // std::cout<<"       "<<h1->GetMean()<<"  "<<h1->GetRMS()<<"  + "<<h1->GetMean()-h1->GetRMS()-pole<<"  - "<<pole-h1->GetMean()+h1->GetRMS()<<std::endl;

  // std::cout<<"       "<<mean+sigma<<"   "<<mean-sigma<<std::endl;
  // std::cout<<"       "<<mean2+sigma_h<<"  "<<mean2-sigma_l<<std::endl;
  // std::cout<<"       "<<h1->GetMean()+h1->GetRMS()<<"  "<<h1->GetMean()-h1->GetRMS()<<std::endl;

  std::cout<<"Pole : "<<pole<<std::endl;
  std::cout<<"Pole (gaus)     : "<<mean+sigma<<", "<<mean<<", "<<mean-sigma<<std::endl;
  std::cout<<"Pole (2-gaus)   : "<<mean2+sigma_h<<", "<<mean2<<", "<<mean-sigma_l<<std::endl;
  std::cout<<"Pole (RMS/mean) : "<<h1->GetMean()+h1->GetRMS()<<", "<<h1->GetMean()<<", "<<h1->GetMean()-h1-> GetRMS()<<std::endl;
}

bool drawWidth(TFile *f, TString dirName, float width){
  //  std::cout<<"Width = "<<width<<std::endl;
  TDirectory* dir=(TDirectory*)f->Get(dirName);

  TH1F *h1=set((TH1F*)dir-> Get("Width_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(-0.1, 0.0);
  h1-> GetXaxis()-> SetTitle("M_{#pi #Sigma} [GeV]");
  h1-> GetYaxis()-> SetTitle("Count");
  h1-> Draw();

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(width, 0, width, 1.1*h1->GetMaximum());

  h1-> Fit("gaus", "q0");
  double mean=h1->GetFunction("gaus")-> GetParameter(1);
  double sigma=h1->GetFunction("gaus")-> GetParameter(2);
  TF1* gaus=(TF1*)h1->GetFunction("gaus");

  TF1 *func=(TF1*)gROOT->FindObject("double_gaus");
  func-> SetParameter(0, h1->GetMaximum());
  func-> SetParameter(1, h1->GetBinCenter(h1->GetMaximumBin()));
  func-> SetParameter(2, 0.6*h1->GetRMS());
  func-> SetParameter(3, 0.4*h1->GetRMS());
  func-> SetLineColor(kBlue);
  h1-> Fit("double_gaus", "+q0", "");
  func-> SetLineColor(3);

  double mean2=func->GetParameter(1);
  double sigma_l=func->GetParameter(2);
  double sigma_h=func->GetParameter(3);
  double h_mean=h1->GetMean();
  double RMS=h1->GetRMS();

  line.SetLineColor(kRed);
  line.DrawLine(mean, 0, mean, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(mean-sigma, 0, mean-sigma, 1.05*h1->GetMaximum());
  line.DrawLine(mean+sigma, 0, mean+sigma, 1.05*h1->GetMaximum());

  line.SetLineStyle(1);
  line.SetLineColor(kBlue);
  line.DrawLine(mean2, 0, mean2, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(mean2-sigma_l, 0, mean2-sigma_l, 1.05*h1->GetMaximum());
  line.DrawLine(mean2+sigma_h, 0, mean2+sigma_h, 1.05*h1->GetMaximum());

  line.SetLineStyle(1);
  line.SetLineColor(1);
  line.DrawLine(h_mean, 0, h_mean, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(h_mean-RMS, 0, h_mean-RMS, 1.05*h1->GetMaximum());
  line.DrawLine(h_mean+RMS, 0, h_mean+RMS, 1.05*h1->GetMaximum());

  // std::cout<<"Gaussian chi2/NDF = "<<gaus->GetChisquare()<<"/"<<gaus->GetNDF()<<" = "<<gaus->GetChisquare()/gaus->GetNDF()<<std::endl;
  // std::cout<<gaus->GetParameter(1)<<" +- "<<gaus->GetParError(1)<<std::endl;
  // std::cout<<gaus->GetParameter(2)<<" +- "<<gaus->GetParError(2)<<std::endl;

  // std::cout<<"Gaussian chi2/NDF = "<<func->GetChisquare()<<"/"<<func->GetNDF()<<" = "<<func->GetChisquare()/func->GetNDF()<<std::endl;
  // std::cout<<func->GetParameter(1)<<" +- "<<func->GetParError(1)<<std::endl;
  // std::cout<<func->GetParameter(2)<<" +- "<<func->GetParError(2)<<std::endl;
  // std::cout<<func->GetParameter(3)<<" +- "<<func->GetParError(3)<<std::endl;

  // std::cout<<h1->GetMean()<<std::endl;
  // std::cout<<h1->GetRMS()<<Std::endl;

  // std::cout<<"Width : "<<width<<"   + "<<sigma+mean-width<<"   - "<<width-mean+sigma<<std::endl;
  // std::cout<<"       "<<mean<<"   "<<sigma<<"  + "<<sigma+mean-width<<"   - "<<width-mean+sigma<<std::endl;
  // std::cout<<"       "<<mean2<<"  "<<sigma_h<<" "<<sigma_l<<"  + "<<sigma_h+mean2-width<<"   - "<<width-mean2+sigma_l<<std::endl;
  // std::cout<<"       "<<h1->GetMean()<<"  "<<h1->GetRMS()<<"  + "<<h1->GetMean()-h1->GetRMS()-width<<"  - "<<width-h1->GetMean()+h1->GetRMS()<<std::endl;

  // std::cout<<"       "<<mean+sigma<<"   "<<mean-sigma<<std::endl;
  // std::cout<<"       "<<mean2+sigma_h<<"  "<<mean2-sigma_l<<std::endl;
  // std::cout<<"       "<<h1->GetMean()+h1->GetRMS()<<"  "<<h1->GetMean()-h1->GetRMS()<<std::endl;

  // std::cout<<"Width : "<<width<<std::endl;
  // std::cout<<"Width (gaus)     : "<<mean+sigma<<", "<<mean<<", "<<mean-sigma<<std::endl;
  // std::cout<<"Width (2-gaus)   : "<<mean2+sigma_h<<", "<<mean2<<", "<<mean-sigma_l<<std::endl;
  // std::cout<<"Width (RMS/mean) : "<<h1->GetMean()+h1->GetRMS()<<", "<<h1->GetMean()<<", "<<h1->GetMean()-h1-> GetRMS()<<std::endl;
}

bool drawWidth2(TFile *f, TString dirName, float width, double range=2.0){
  TDirectory* dir=(TDirectory*)f->Get(dirName);

  TH1F *h1=set((TH1F*)dir-> Get("Width_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(-0.1, 0.0);
  h1-> GetXaxis()-> SetTitle("M_{#pi #Sigma} [GeV]");
  h1-> GetYaxis()-> SetTitle("Count");
  h1-> Draw();

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(width, 0, width, 1.1*h1->GetMaximum());

  TF1 *func=(TF1*)gROOT->FindObject("double_gaus");
  func-> SetParameter(0, h1->GetMaximum());
  func-> SetParameter(1, h1->GetBinCenter(h1->GetMaximumBin()));
  func-> SetParameter(2, 0.6*h1->GetRMS());
  func-> SetParameter(3, 0.4*h1->GetRMS());
  func-> SetLineColor(kBlue);
  h1-> Fit("double_gaus", "q0", "");

  double mean2=func->GetParameter(1);
  double sigma_l=func->GetParameter(2);
  double sigma_h=func->GetParameter(3);
  double chi2=func->GetChisquare()/func->GetNDF();
  h1-> Fit("double_gaus", "q", "", mean2-range*sigma_l, mean2+range*sigma_h);

  double mean2_2=func->GetParameter(1);
  double sigma_l_2=func->GetParameter(2);
  double sigma_h_2=func->GetParameter(3);
  double chi2_2=func->GetChisquare()/func->GetNDF();

  int counter=0;
  while( true ){
    mean2=mean2_2;
    sigma_l=sigma_l_2;
    sigma_h=sigma_h_2;
    chi2=chi2_2;
    h1-> Fit("double_gaus", "q", "", mean2-range*sigma_l, mean2+range*sigma_h);
    mean2_2=func->GetParameter(1);
    sigma_l_2=func->GetParameter(2);
    sigma_h_2=func->GetParameter(3);
    chi2_2=func->GetChisquare()/func->GetNDF();

    // std::cout<<"Iteration : "<<counter<<std::endl;  
    // std::cout<<chi2<<"  "<<chi2_2<<std::endl;
    // std::cout<<mean2<<"  "<<mean2_2<<std::endl;
    // std::cout<<sigma_h<<"  "<<sigma_h_2<<std::endl;
    // std::cout<<sigma_l<<"  "<<sigma_l_2<<std::endl;
    // std::cout<<fabs((chi2-chi2_2)/chi2_2)<<"  "<<fabs((mean2-mean2_2)/mean2_2)<<"  "<<fabs((sigma_h-sigma_h_2)/sigma_h_2)<<"  "<<fabs((sigma_l-sigma_l_2)/sigma_l_2)<<std::endl;
    if( fabs((chi2-chi2_2)/chi2_2)<0.01 && fabs((mean2-mean2_2)/mean2_2)<0.01 && fabs((sigma_h-sigma_h_2)/sigma_h_2)<0.01 && fabs((sigma_l-sigma_l_2)/sigma_l_2)<0.01 ) break;
    counter++;
    if( counter>1000 ) break;
  }
  line.SetLineStyle(1);
  line.SetLineColor(kBlue);
  line.DrawLine(mean2, 0, mean2, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(mean2-sigma_l, 0, mean2-sigma_l, 1.05*h1->GetMaximum());
  line.DrawLine(mean2+sigma_h, 0, mean2+sigma_h, 1.05*h1->GetMaximum());

  std::cout<<"===== Draw Width w/ 2-Gaussian ====="<<std::endl;
  //  std::cout<<"chi2/NDF : "<<func->GetChisquare()<<"/"<<func->GetNDF()<<" = "<<func->GetChisquare()/func->GetNDF()<<std::endl;
  std::cout<<"\"Range\" : "<<range<<","<<std::endl;
  std::cout<<"\"chi2\" : "<<func->GetChisquare()<<","<<std::endl;
  std::cout<<"\"NDF\" : "<<func->GetNDF()<<","<<std::endl;
  std::cout<<"\"Mean\" : "<<mean2<<","<<std::endl;
  std::cout<<"\"Lower\" : "<<mean2-sigma_l<<","<<std::endl;
  std::cout<<"\"Upper\" : "<<mean2+sigma_h<<std::endl;

  return true;
}

bool drawPole2(TFile *f, TString dirName, float pole, double range=2.0){
  TDirectory* dir=(TDirectory*)f->Get(dirName);

  TH1F *h1=set((TH1F*)dir-> Get("Pole_dist_gauss"));
  h1-> GetXaxis()-> SetRangeUser(-0.1, 0.0);
  h1-> GetXaxis()-> SetTitle("M_{#pi #Sigma} [GeV]");
  h1-> GetYaxis()-> SetTitle("Count");
  h1-> Draw();

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(pole, 0, pole, 1.1*h1->GetMaximum());

  TF1 *func=(TF1*)gROOT->FindObject("double_gaus");
  func-> SetParameter(0, h1->GetMaximum());
  func-> SetParameter(1, h1->GetBinCenter(h1->GetMaximumBin()));
  func-> SetParameter(2, 0.6*h1->GetRMS());
  func-> SetParameter(3, 0.4*h1->GetRMS());
  func-> SetLineColor(kBlue);
  h1-> Fit("double_gaus", "q0", "");

  double mean2=func->GetParameter(1);
  double sigma_l=func->GetParameter(2);
  double sigma_h=func->GetParameter(3);
  double chi2=func->GetChisquare()/func->GetNDF();
  h1-> Fit("double_gaus", "q", "", mean2-range*sigma_l, mean2+range*sigma_h);

  double mean2_2=func->GetParameter(1);
  double sigma_l_2=func->GetParameter(2);
  double sigma_h_2=func->GetParameter(3);
  double chi2_2=func->GetChisquare()/func->GetNDF();

  int counter=0;
  while( true ){
    mean2=mean2_2;
    sigma_l=sigma_l_2;
    sigma_h=sigma_h_2;
    chi2=chi2_2;
    h1-> Fit("double_gaus", "q", "", mean2-range*sigma_l, mean2+range*sigma_h);
    mean2_2=func->GetParameter(1);
    sigma_l_2=func->GetParameter(2);
    sigma_h_2=func->GetParameter(3);
    chi2_2=func->GetChisquare()/func->GetNDF();
  
    // std::cout<<"Iteration : "<<counter<<std::endl;
    // std::cout<<chi2<<"  "<<chi2_2<<std::endl;
    // std::cout<<mean2<<"  "<<mean2_2<<std::endl;
    // std::cout<<sigma_h<<"  "<<sigma_h_2<<std::endl;
    // std::cout<<sigma_l<<"  "<<sigma_l_2<<std::endl;
    // std::cout<<fabs((chi2-chi2_2)/chi2_2)<<"  "<<fabs((mean2-mean2_2)/mean2_2)<<"  "<<fabs((sigma_h-sigma_h_2)/sigma_h_2)<<"  "<<fabs((sigma_l-sigma_l_2)/sigma_l_2)<<std::endl;
    if( fabs((chi2-chi2_2)/chi2_2)<0.01 && fabs((mean2-mean2_2)/mean2_2)<0.01 && fabs((sigma_h-sigma_h_2)/sigma_h_2)<0.01 && fabs((sigma_l-sigma_l_2)/sigma_l_2)<0.01 ) break;
    counter++;
    if( counter>1000 ) break;
  }
  line.SetLineStyle(1);
  line.SetLineColor(kBlue);
  line.DrawLine(mean2, 0, mean2, 1.05*h1->GetMaximum());
  line.SetLineStyle(9);
  line.DrawLine(mean2-sigma_l, 0, mean2-sigma_l, 1.05*h1->GetMaximum());
  line.DrawLine(mean2+sigma_h, 0, mean2+sigma_h, 1.05*h1->GetMaximum());

  std::cout<<"===== Draw Pole w/ 2Gaussian ====="<<std::endl;
  //  std::cout<<"chi2/NDF : "<<func->GetChisquare()<<"/"<<func->GetNDF()<<" = "<<func->GetChisquare()/func->GetNDF()<<std::endl;
  std::cout<<"\"Range\" : "<<range<<","<<std::endl;
  std::cout<<"\"chi2\" : "<<func->GetChisquare()<<","<<std::endl;
  std::cout<<"\"NDF\" : "<<func->GetNDF()<<","<<std::endl;
  std::cout<<"\"Mean\" : "<<mean2<<","<<std::endl;
  std::cout<<"\"Lower\" : "<<mean2-sigma_l<<","<<std::endl;
  std::cout<<"\"Upper\" : "<<mean2+sigma_h<<std::endl;

  return true;
}


void printParam(TFile*f, TString dirName, float &pole, float &width){
  TDirectory* dir=(TDirectory*)f->Get(dirName);
  TNtuple *tup=(TNtuple*)dir-> Get("fit_params");
  float chi2, ndf, scale, scale_err, A_I0_re, A_I0_re_err, A_I0_im, A_I0_im_err, R_I0_re, R_I0_re_err, R_I0_im, R_I0_im_err, pole, width;
  tup-> SetBranchAddress("chi2", &chi2);
  tup-> SetBranchAddress("NDF", &ndf);
  tup-> SetBranchAddress("scale", &scale);
  tup-> SetBranchAddress("scale_err", &scale_err);
  tup-> SetBranchAddress("A_I0_re", &A_I0_re);
  tup-> SetBranchAddress("A_I0_re_err", &A_I0_re_err);
  tup-> SetBranchAddress("A_I0_im", &A_I0_im);
  tup-> SetBranchAddress("A_I0_im_err", &A_I0_im_err);
  tup-> SetBranchAddress("R_I0_re", &R_I0_re);
  tup-> SetBranchAddress("R_I0_re_err", &R_I0_re_err);
  tup-> SetBranchAddress("R_I0_im", &R_I0_im);
  tup-> SetBranchAddress("R_I0_im_err", &R_I0_im_err);
  tup-> SetBranchAddress("Pole", &pole);
  tup-> SetBranchAddress("Width", &width);
  tup-> GetEntry(0);


  std::cout<<chi2<<"/"<<ndf<<"="<<chi2/ndf<<std::endl;
  // std::cout<<scale<<" +- "<<scale_err<<std::endl;
  // std::cout<<A_I0_re<<" +- "<<A_I0_re_err<<std::endl;
  // std::cout<<A_I0_im<<" +- "<<A_I0_im_err<<std::endl;
  // std::cout<<R_I0_re<<" +- "<<R_I0_re_err<<std::endl;
  // std::cout<<R_I0_im<<" +- "<<R_I0_im_err<<std::endl;
}

TGraph* setOpts(TGraph* gra){
  gra-> GetXaxis()-> CenterTitle();
  gra-> GetXaxis()->SetLabelSize(0.05);
  gra-> GetXaxis()->SetTitleSize(0.06);
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");

  gra-> GetYaxis()-> CenterTitle();
  gra-> GetYaxis()->SetLabelSize(0.05);
  gra-> GetYaxis()->SetTitleSize(0.06);
  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");
  return gra;
}

void drawScatAmp(TFile *f, TString dirName){
  TDirectory* dir=(TDirectory*)f->Get(dirName);

  TGraph* gra_re=setOpts(scale(Const_GeVFM, (TGraph*)dir->Get("gra_I0_KN_KN_re")));
  TGraph* gra_im=scale(Const_GeVFM, (TGraph*)dir->Get("gra_I0_KN_KN_im"));
  TGraphAsymmErrors* gra_re_wErr=scaleAsymm(Const_GeVFM, (TGraphAsymmErrors*)dir->Get("gra_I0_KN_KN_re_wErr"));
  TGraphAsymmErrors* gra_im_wErr=scaleAsymm(Const_GeVFM, (TGraphAsymmErrors*)dir->Get("gra_I0_KN_KN_im_wErr"));
  gra_re_wErr-> SetFillColor(kRed);
  gra_im_wErr-> SetFillColor(kBlue);
  gra_re_wErr-> SetFillStyle(3001);
  gra_im_wErr-> SetFillStyle(3001);
  gra_re-> SetLineWidth(2);
  gra_im-> SetLineWidth(2);
  gra_re-> SetLineColor(kRed);
  gra_im-> SetLineColor(kBlue);
  gra_re-> SetTitle(0);
  gra_re-> GetYaxis()-> SetRangeUser(-1.5, 3.5);
  gra_re-> GetXaxis()-> SetRangeUser(1.35, 1.5);
  gra_re-> Draw("AL");
  gra_im-> Draw("L");
  gra_im_wErr-> Draw("4");
  gra_re_wErr-> Draw("4");

  // double pole=searchPole(gra_re);
  // double pole_min=searchPole_min(gra_re_wErr);
  // double pole_max=searchPole_max(gra_re_wErr);

  // std::cout<<"Pole position : "<<pole<<" -"<<pole-pole_min<<" +"<<pole_max-pole<<std::endl;

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(kMass+NMass, -1.5, kMass+NMass, 3.5);
}

void draw(TFile *f, TString dirName){
  TGraphErrors *data=(TGraphErrors*)f->Get("I0_CS");
  data-> GetYaxis()-> SetRangeUser(0, 20);
  data-> Draw("AP");

  TDirectory* dir=(TDirectory*)f->Get(dirName);
  TGraph *responseFunc=(TGraph*)dir->Get("responseFunc");
  TGraph* gra_I0=(TGraph*)dir->Get("fit_I0");
  TGraph* gra_I0_wReso=(TGraph*)dir->Get("fit_I0_wReso");
  responseFunc=scale(0.25, responseFunc);
  responseFunc-> SetLineWidth(2);
  responseFunc-> SetLineColor(kBlue);
  responseFunc-> SetLineStyle(9);
  responseFunc-> Draw("L");

  gra_I0-> SetLineColor(kRed);
  gra_I0-> SetLineWidth(2);
  gra_I0-> SetLineStyle(9);
  gra_I0-> Draw("L");

  gra_I0_wReso-> SetLineColor(kRed);
  gra_I0_wReso-> SetLineWidth(2);
  gra_I0_wReso-> Draw("L");

  TLine line;
  line.SetLineWidth(2);
  line.SetLineColor(3);
  line.DrawLine(kMass+NMass, 0, kMass+NMass, 20);


}

TGraph* scale(double scale, TGraph* gra){
  std::vector<double>x, y;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x.push_back(tmpx);
    y.push_back(scale*tmpy);
  }
  TGraph* gra= new TGraph(x.size(), &x[0], &y[0]);
  return gra;
}

TGraphAsymmErrors* scaleAsymm(double scale, TGraphAsymmErrors* gra){
  std::vector<double> x, y, xerr_min, xerr_max, yerr_min, yerr_max;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra->GetPoint(i, tmpx, tmpy);
    x.push_back(tmpx);
    y.push_back(scale*tmpy);
    xerr_min.push_back(gra->GetErrorXlow(i));
    xerr_max.push_back(gra->GetErrorXhigh(i));
    yerr_min.push_back(scale*gra->GetErrorYlow(i));
    yerr_max.push_back(scale*gra->GetErrorYhigh(i));
  }
  //  for( int i=0; i<x.size(); i++ ) std::cout<<x[i]<<"  "<<xerr_min[i]<<"  "<<xerr_max[i]<<"  "<<y[i]<<"  "<<yerr_min[i]<<"  "<<yerr_max[i]<<std::endl

  return new TGraphAsymmErrors(x.size(), &x[0], &y[0], &xerr_min[0], &xerr_max[0], &yerr_min[0], &yerr_max[0]);
}

double searchPole(TGraph* gra){
  double x1, x2, y1, y2;
  for( int i=0; i<gra-> GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x2=x1;
    x1=tmpx;
    y2=y1;
    y1=tmpy;
    if( y1*y2<0 ) break;
  }
  //  std::cout<<x1<<"  "<<x2<<"  "<<y1<<"  "<<y2<<std::endl;
  return (x2*y1-y2*x1)/(y2-y1);
}

double searchPole_min(TGraphAsymmErrors* gra){
  double x1, x2, y1, y2;
  for( int i=0; i<gra-> GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x2=x1;
    x1=tmpx;
    y2=y1;
    y1=tmpy-gra->GetErrorYlow(i);
    if( y1*y2<0 ) break;
  }
  //  std::cout<<x1<<"  "<<x2<<"  "<<y1<<"  "<<y2<<std::endl;
  return (x2*y1-y2*x1)/(y2-y1);
}

double searchPole_max(TGraphAsymmErrors* gra){
  double x1, x2, y1, y2;
  for( int i=0; i<gra-> GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x2=x1;
    x1=tmpx;
    y2=y1;
    y1=tmpy+gra->GetErrorYhigh(i);
    if( y1*y2<0 ) break;
  }
  //  std::cout<<x1<<"  "<<x2<<"  "<<y1<<"  "<<y2<<std::endl;
  return (x2*y1-y2*x1)/(y2-y1);
}
