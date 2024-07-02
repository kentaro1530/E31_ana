#include "macro/init.C"

const double A1_re=1.432, A1_im=0.075;
const double A2_re=1.372, A2_im=0.056;

const double B1_re=1.428, B1_im=0.031;
const double B2_re=1.397, B2_im=0.098;

const double kpThre=0.5*(k0Mass+nMass+kpMass+pMass);
const double piSThre=piMass+spMass;

void draw_DCC_2pole(){
  init();

  gStyle-> SetPadLeftMargin(0.15);
  gStyle-> SetPadBottomMargin(0.15);
  gStyle-> SetPadRightMargin(0.05);
  gStyle-> SetPadTopMargin(0.1);

  TLine line1;
  line1.SetLineWidth(3);
  line1.SetLineColor(3);
  TLine line2;
  line2.SetLineWidth(3);
  line2.SetLineColor(3);
  line2.SetLineStyle(8);

  TLatex text;
  text.SetTextSize(0.07);
  TMarker mark_A;
  mark_A.SetMarkerColor(kPink+2);
  mark_A.SetMarkerStyle(33);
  mark_A.SetMarkerSize(5);

  TMarker mark_B;
  mark_B.SetMarkerColor(kOrange+2);
  mark_B.SetMarkerStyle(21);
  mark_B.SetMarkerSize(3);

  TH2F *h2= new TH2F("", "", 100, 1.35, 1.45, 100, -0.120, 0);
  h2-> SetLineWidth(2);
  h2->SetTitle("");
  h2->GetXaxis()->SetLabelSize(0.05);
  h2->GetXaxis()->SetTitleSize(0.06);
  h2->GetXaxis()->CenterTitle();
  h2->GetYaxis()->SetLabelSize(0.05);
  h2->GetYaxis()->SetTitleSize(0.06);
  h2->GetYaxis()->CenterTitle();
  h2-> GetXaxis()-> SetTitle("Re W[GeV]");
  h2-> GetYaxis()-> SetTitle("Im W[GeV]");
  h2-> SetStats(0);

  h2-> Draw();
  line1.DrawLine(kpThre, 0, kpThre, -0.12);
  line2.DrawLine(piSThre, 0, piSThre, -0.12);
  mark_A.DrawMarker(A1_re, -A1_im);
  mark_A.DrawMarker(A2_re, -A2_im);
  text.DrawText(A1_re-0.0075, -A1_im+0.005, "A1");
  text.DrawText(A2_re-0.0075, -A2_im+0.005, "A2");

  mark_B.DrawMarker(B1_re, -B1_im);
  mark_B.DrawMarker(B2_re, -B2_im);
  text.DrawText(B1_re-0.0075, -B1_im+0.005, "B1");
  text.DrawText(B2_re-0.0075, -B2_im+0.005, "B2");

  text.DrawLatex(kpThre-0.005, 0.0+0.0005, "#bar{K}N");
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_2pole.eps");

  h2-> Draw();
  line1.DrawLine(kpThre, 0, kpThre, -0.12);
  line2.DrawLine(piSThre, 0, piSThre, -0.12);
  mark_A.DrawMarker(A1_re, -A1_im);
  mark_A.DrawMarker(A2_re, -A2_im);
  text.DrawText(A1_re-0.0075, -A1_im+0.005, "A1");
  text.DrawText(A2_re-0.0075, -A2_im+0.005, "A2");

  text.DrawLatex(kpThre-0.005, 0.0+0.0005, "#bar{K}N");
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_A.eps");

  h2-> Draw();
  line1.DrawLine(kpThre, 0, kpThre, -0.12);
  line2.DrawLine(piSThre, 0, piSThre, -0.12);
  mark_B.DrawMarker(B1_re, -B1_im);
  mark_B.DrawMarker(B2_re, -B2_im);
  text.DrawText(B1_re-0.0075, -B1_im+0.005, "B1");
  text.DrawText(B2_re-0.0075, -B2_im+0.005, "B2");

  text.DrawLatex(kpThre-0.005, 0.0+0.0005, "#bar{K}N");
  c1-> Print("~/ag_Run78/pic/JPS_2022/DCC_B.eps");
}



