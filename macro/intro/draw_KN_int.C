#include "../init.C"
const double alpha = 7.2973525643e-3, mu = pMass*kpMass/(pMass+kpMass);
const double factor = alpha*alpha*alpha*mu*mu*1.0e9/Const_GeVFM;

const double shift[]      = {             270,            40,             193,     -323,   -193,        -283 };
const double shift_err1[] = {              80,            60,              60,       74,     43,          42 };
const double shift_err0[] = {             -80,           -60,             -60,      -74,    -43,         -42 };
const double width[]      = {             560,             0,              80,      407,    249,         541 };
const double width_err1[] = {             260,           230,             220,      308,    141,         111 };
const double width_err0[] = {            -260,             0,             -80,     -308,   -141,        -111 };
const double color[]      = {              33,            45,              30,        1,      4,           2 };
const TString ref_name[]  = { "Izycki et al.", "Bird et al.", "Davies et al.", "KEK-PS", "Dear", "SIDDHARTA" };

const double martin[] = { -1.33*factor, 1.28*2*factor };
const double siegel[] = { -0.80*factor, 2.10*2*factor };
const double sakitt1[] = { -1.60*factor, 1.28*2*factor };
const double sakitt2[] = { -1.82*factor, 0.95*2*factor };
const double kim1[] = { -1.68*factor, 1.42*2*factor };
const double kim2[] = { -1.50*factor, 1.70*2*factor };

TH2F* setOpts(TH2F* h2);

void draw_KN_int(){
  init();
  TCanvas *c1 = new TCanvas();
  
  TH2F *h2 = setOpts(new TH2F("h1", "h1", 100, -500, 500, 100, 0, 1000));
  TLatex latex;
  TBox box;
  TLine line;
  TMarker mark;
  mark.SetMarkerStyle(8);
  line.SetLineWidth(2);
  box.SetFillStyle(0);
  box.SetLineStyle(8);
  box.SetLineWidth(2);
  
  h2-> Draw();
  for( int i=0; i<6; i++ ){
    if( i==3 ) box.SetLineStyle(1);
    
    mark.SetMarkerColor(color[i]);
    box.SetLineColor(color[i]);
    latex.SetTextColor(color[i]);
    mark.DrawMarker(shift[i], width[i]);
    box.DrawBox(shift[i]+shift_err0[i], width[i]+width_err0[i], shift[i]+shift_err1[i], width[i]+width_err1[i]);
    if( i==3 ) latex.DrawLatex(shift[i]-170, width[i], ref_name[i]);
    else latex.DrawLatex(shift[i]+15, width[i], ref_name[i]);
  }

  mark.SetMarkerStyle(22);
  mark.SetMarkerSize(1.5);
  mark.SetMarkerColor(46);
  line.SetLineColor(46);
  latex.SetTextColor(46);
  mark.DrawMarker(siegel[0], siegel[1]);
  line.DrawLine(siegel[0], siegel[1], -100, 920);
  latex.DrawLatex(-90, 905, "Siegel et al.[16]");
  
  mark.SetMarkerColor(38);
  line.SetLineColor(38);
  latex.SetTextColor(38);
  mark.DrawMarker(martin[0], martin[1]);
  line.DrawLine(martin[0], martin[1], -200, 500);
  latex.DrawLatex(-190, 485, "Martin[15]");
  
  mark.SetMarkerColor(6);
  line.SetLineColor(6);
  latex.SetTextColor(6);
  mark.DrawMarker(sakitt1[0], sakitt1[1]);
  mark.DrawMarker(sakitt2[0], sakitt2[1]);
  line.DrawLine(sakitt1[0], sakitt1[1], -200, 410);
  line.DrawLine(sakitt2[0], sakitt2[1], -200, 410);
  latex.DrawLatex(-190, 395, "Sakitt et al.[13]");
  
  mark.SetMarkerColor(3);
  line.SetLineColor(3);
  latex.SetTextColor(3);
  mark.DrawMarker(kim1[0], kim1[1]);
  mark.DrawMarker(kim2[0], kim2[1]);
  line.DrawLine(kim1[0], kim1[1], -200, 650);
  line.DrawLine(kim2[0], kim2[1], -200, 650);
  latex.DrawLatex(-190, 635, "Kim[14]");

  c1-> Print("KN_int_map.eps");
}

TH2F* setOpts(TH2F* h2){
  h2-> SetStats(0);
  h2-> SetMarkerStyle(8);
  h2-> SetLineWidth(2);
  h2-> SetTitle("");
  h2-> GetXaxis()->SetLabelSize(0.05);
  h2-> GetXaxis()->SetTitleSize(0.06);
  h2-> GetXaxis()->CenterTitle();
  h2-> GetYaxis()->SetLabelSize(0.05);
  h2-> GetYaxis()->SetTitleSize(0.06);
  h2-> GetYaxis()->CenterTitle();
  h2-> GetXaxis()-> SetTitle("Shift [eV]");
  h2-> GetYaxis()-> SetTitle("Width [eV]");

  return h2;
}
