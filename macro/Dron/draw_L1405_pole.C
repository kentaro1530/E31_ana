#include "../init.C"

TH2F* setOpts(TH2F *h2);

void draw_L1405_pole(){
  init();
  TCanvas *c1=new TCanvas("c1", "c1");

  const double higher_mass[] = { 1.433, 1.429, 1.426, 1.432, 1.428 };
  const double lower_mass[]  = { 1.371, 1.344, 1.390, 1.372, 1.397 };

  const double higher_width[] = { -0.025, -0.015, -0.016, -0.075, -0.031 };
  const double lower_width[]  = { -0.054, -0.049, -0.066, -0.059, -0.098 };

  const int markerStyle[] = { 20, 21, 29, 22, 23 }; 
  const int markerColor[] = { 38, 40, 3, kRed, kBlue };

  const double marker_x[]={ 1.31, 1.31, 1.31, 1.35, 1.35 };
  const double marker_y[]={ -0.01, -0.02, -0.03, -0.015, -0.025 };
  const TString name[]={ "Cieply", "Ohinishi", "Histrical", "DCC.A", "DCC.B"};
  TH2F *h2=setOpts(new TH2F("h2", "", 100, 1.30, 1.45, 100, -0.1, 0.0));
  h2-> Draw();
  TBox box;
  box.SetFillStyle(0);
  box.SetLineStyle(9);
  box.SetLineWidth(2);
  TLatex latex;
  TMarker mark;
  mark.SetMarkerSize(2);
  for( size_t i=0; i<sizeof(higher_mass)/sizeof(higher_mass[0]); i++ ){
    mark.SetMarkerStyle(markerStyle[i]);
    mark.SetMarkerColor(markerColor[i]);
    mark.DrawMarker(higher_mass[i], higher_width[i]);
    mark.DrawMarker(lower_mass[i], lower_width[i]);

    mark.DrawMarker(marker_x[i], marker_y[i]);
    latex.DrawLatex(marker_x[i]+0.005, marker_y[i]-0.002, name[i]);
  }
  latex.DrawLatex(1.34, -0.043, "Lower pole");
  box.DrawBox(1.335, -0.1,   1.4, -0.045);

  latex.SetTextAngle(90);
  latex.DrawLatex(1.418, -0.08, "Higher pole");
  box.DrawBox(1.42, -0.085, 1.440, -0.005);


  c1-> Print("pic/Dron/L1405_pole.png");
  c1-> Print("pic/Dron/L1405_pole.eps");
}

TH2F* setOpts(TH2F *h2){
  h2-> SetStats(0);
  h2-> SetMarkerStyle(8);
  h2-> SetLineWidth(2);
  h2-> SetTitle("");
  h2->GetXaxis()->SetLabelSize(0.05);
  h2->GetXaxis()->SetTitleSize(0.06);
  h2->GetXaxis()->CenterTitle();
  
  h2->GetYaxis()->SetLabelSize(0.05);
  h2->GetYaxis()->SetTitleSize(0.06);
  h2->GetYaxis()->CenterTitle();
  h2->GetXaxis()->SetTitle("M_{#pi #Sigma} [GeV]");
  h2->GetYaxis()->SetTitle("#Gamma [GeV]");
  
  return h2;
}
