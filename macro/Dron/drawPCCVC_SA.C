#include "../init.C"

const TString infilename="PCCVC_SA_no_npreac.root";
const double SA_NC=0.0214832;

TGraphErrors* setOpts(TGraphErrors* gra, int color=kBlack);

void drawPCCVC_SA(){
  setMargin();
  TCanvas *c1=new TCanvas();
  
  TFile *f = new TFile(infilename);
  TLine line;
  line.SetLineColor(kRed); line.SetLineWidth(2);

  std::vector<double> x, y, y2, y3, y4, xerr;
  for( int mm=130; mm<200; mm++ ){
    TH2F *h2       =(TH2F*)f->Get(Form("sa_%d_acc", mm));
    TH2F *h2_wCut  =(TH2F*)f->Get(Form("sa_%d_acc_wCut", mm));
    TH2F *h2_nophys=(TH2F*)f->Get(Form("sa_%d_acc_nophys", mm));
    TH2F *h2_nophys_wCut=(TH2F*)f->Get(Form("sa_%d_acc_nophys_wCut", mm));
    h2_wCut-> GetZaxis()-> SetRangeUser(0.0, 1.0);
    h2_wCut-> GetXaxis()-> SetRangeUser(0.25, -0.25);
    h2_wCut-> GetYaxis()-> SetRangeUser(0.25, -0.25);
    //    setAxisTitle(h2_wCut, "X [rad]", "Y [rad]");
    h2_wCut-> Draw("colz");
    double sum=0, sum2=0, sum3=0, sum4=0;

    for( int binx=1; binx<=h2->GetNbinsX(); binx++ ){
      for( int biny=1; biny<=h2->GetNbinsY(); biny++ ){
        double width=h2->GetXaxis()->GetBinWidth(binx);
        double height=h2->GetYaxis()->GetBinWidth(biny);
        double eff=h2->GetBinContent(binx, biny);
        sum+=width*height*eff;

        if( !TMath::IsNaN(h2_wCut->GetBinContent(binx, biny)) ) sum2+=width*height*h2_wCut->GetBinContent(binx, biny);
        if( !TMath::IsNaN(h2_nophys->GetBinContent(binx, biny)) ) sum3+=width*height*h2_nophys->GetBinContent(binx, biny);
        if( !TMath::IsNaN(h2_nophys_wCut->GetBinContent(binx, biny)) ) sum4+=width*height*h2_nophys_wCut->GetBinContent(binx, biny);
      }
    }
    //    std::cout<<sum<<"  "<<sum2<<std::endl;
    x.push_back(0.01*mm+0.005);
    y.push_back(sum);
    y2.push_back(sum2);
    y3.push_back(sum3);
    y4.push_back(sum4);
    xerr.push_back(0.005);
    //    std::cout<<0.01*mm+0.005<<"   "<<1000.*sum2<<" +- "<<1000.*sum2/sqrt(h2_wCut->GetEntries())<<std::endl;
    //    wait(false, Form("solid_ang_%d", mm));
  }
  //  for( int i=0; i<x.size(); i++ ) std::cout<<x[i]<<"  "<<y[i]<<std::endl;
  TGraphErrors *gra=setOpts(new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], 0));
  TGraphErrors *gra2=setOpts(new TGraphErrors(x.size(), &x[0], &y2[0], &xerr[0], 0)); //, kRed);
  TGraphErrors *gra3=setOpts(new TGraphErrors(x.size(), &x[0], &y3[0], &xerr[0], 0), kBlue);
  TGraphErrors *gra4=setOpts(new TGraphErrors(x.size(), &x[0], &y4[0], &xerr[0], 0), kBlue);
  gra2->GetXaxis()-> SetRangeUser(1.35, 1.599);
  gra2->GetYaxis()-> SetRangeUser(0.0, 0.025);
  gra2->GetXaxis()-> SetTitle("d(K^{-}, p)\"X\" [GeV/c^{2}]");
  gra2->GetYaxis()-> SetTitle("#Omega [Sr]");
  //  gra-> Draw("AP");
  // gra3-> Draw("AP");
  //  gra4-> Draw("P");
  gra2-> Draw("AP");
  line.DrawLine(1.35, SA_NC, 1.6, SA_NC);
  line.SetLineColor(3);
  line.DrawLine(kpMass+pMass, 0, kpMass+pMass, 0.025);
  
  c1-> Print("pic/Dron/PCCVC_SA.eps");
}
  
TGraphErrors* setOpts(TGraphErrors* gra, int color){
  gra->SetMarkerStyle(8);
  gra->SetLineWidth(2);
  gra->SetMarkerColor(color);
  gra->SetLineColor(color);

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
  
