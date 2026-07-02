#include "../init.C"
TH2F* setOpts(TH2F* h2);

const double ikeda1[] = { 1424, 7, -23, -26, 3, -14 };
const double ikeda2[] = { 1381, 18, -6, -81, 19, -8 };
const double geo1[] = { 1421, 3, -2, -19, 8, -5 };
const double geo2[] = { 1388, 9, -9, -114, 24, -25 };
const double jido1[] = { 1426, -16 };
const double jido2[] = { 1390, -66 };
const double mai2_1[] = { 1434, 2, -2, -10, 2, -1 };
const double mai2_2[] = { 1330, 4, -5, -56, 17, -11 };
const double mai5_1[] = { 1429, 8, -7, -12, 2, -3 };
const double mai5_2[] = { 1325, 15, -15, -90, 12, -18 };
const double DCC_A1[] = { 1432, -75 };
const double DCC_A2[] = { 1372, -56 };

const double DCC_B1[] = { 1428, -31 };
const double DCC_B2[] = { 1397, -98 };


void draw_L1405_two_pole(){
  init();
  TCanvas *c1 = new TCanvas();

  TH2F *h2 = setOpts(new TH2F("h1", "h1", 100, 1300, 1450, 100, -150, 0));
  TLatex latex;
  TLine line;
  TMarker mark;
  mark.SetMarkerSize(1.5);
  line.SetLineWidth(2);
  h2-> Draw();
  
  mark.SetMarkerColor(5);
  line.SetLineColor(5);
  latex.SetTextColor(5);
  mark.SetMarkerStyle(21);
  mark.DrawMarker(ikeda1[0], ikeda1[3]);
  mark.SetMarkerStyle(20);
  mark.DrawMarker(ikeda2[0], ikeda2[3]);
  line.DrawLine(ikeda1[0]+ikeda1[1], ikeda1[3], ikeda1[0]+ikeda1[2], ikeda1[3]);
  line.DrawLine(ikeda2[0], ikeda2[3]+ikeda2[4], ikeda2[0], ikeda2[3]+ikeda2[5]);
  line.DrawLine(ikeda1[0], ikeda1[3]+ikeda1[4], ikeda1[0], ikeda1[3]+ikeda1[5]);
  line.DrawLine(ikeda2[0]+ikeda2[1], ikeda2[3], ikeda2[0]+ikeda2[2], ikeda2[3]);
  line.DrawLine(ikeda1[0], ikeda1[3], 1405, -40);
  line.DrawLine(ikeda2[0], ikeda2[3], 1390, -50);  
  latex.DrawLatex(1390, -50, "Ikeda et al.");
  
  mark.SetMarkerColor(6);
  line.SetLineColor(6);
  latex.SetTextColor(6);
  mark.SetMarkerStyle(21);
  mark.DrawMarker(geo1[0], geo1[3]);
  mark.SetMarkerStyle(20);
  mark.DrawMarker(geo2[0], geo2[3]);
  line.DrawLine(geo1[0]+geo1[1], geo1[3], geo1[0]+geo1[2], geo1[3]);
  line.DrawLine(geo2[0], geo2[3]+geo2[4], geo2[0], geo2[3]+geo2[5]);
  line.DrawLine(geo1[0], geo1[3]+geo1[4], geo1[0], geo1[3]+geo1[5]);
  line.DrawLine(geo2[0]+geo2[1], geo2[3], geo2[0]+geo2[2], geo2[3]);
  line.DrawLine(geo1[0], geo1[3], 1440, -30);
  line.DrawLine(1440, -30, 1435, -100);
  line.DrawLine(geo2[0], geo2[3], 1417, -105);  
  latex.DrawLatex(1420, -108, "Geo et al.");
  
  mark.SetMarkerColor(3);
  line.SetLineColor(3);
  latex.SetTextColor(3);
  mark.SetMarkerStyle(21);
  mark.DrawMarker(jido1[0], jido1[1]);
  mark.SetMarkerStyle(20);
  mark.DrawMarker(jido2[0], jido2[1]);
  line.DrawLine(jido1[0], jido1[1], 1390, -23);
  line.DrawLine(jido2[0], jido2[1], 1375, -27);
  latex.DrawLatex(1360, -25, "Jido et al.");
  
  mark.SetMarkerColor(46);
  line.SetLineColor(46);
  latex.SetTextColor(46);
  mark.SetMarkerStyle(21);
  mark.DrawMarker(mai2_1[0], mai2_1[3]);
  mark.SetMarkerStyle(20);
  mark.DrawMarker(mai2_2[0], mai2_2[3]);
  line.DrawLine(mai2_1[0]+mai2_1[1], mai2_1[3], mai2_1[0]+mai2_1[2], mai2_1[3]);
  line.DrawLine(mai2_2[0], mai2_2[3]+mai2_2[4], mai2_2[0], mai2_2[3]+mai2_2[5]);
  line.DrawLine(mai2_1[0], mai2_1[3]+mai2_1[4], mai2_1[0], mai2_1[3]+mai2_1[5]);
  line.DrawLine(mai2_2[0]+mai2_2[1], mai2_2[3], mai2_2[0]+mai2_2[2], mai2_2[3]);
  line.DrawLine(mai2_1[0], mai2_1[3], 1358, -7);
  line.DrawLine(mai2_2[0], mai2_2[3]+20, 1330, -13);
  latex.DrawLatex(1320, -10, "Mai et al. #2");
  
  mark.SetMarkerColor(38);
  line.SetLineColor(38);
  latex.SetTextColor(38);
  mark.SetMarkerStyle(21);
  mark.DrawMarker(mai5_1[0], mai5_1[3]);
  mark.SetMarkerStyle(20);
  mark.DrawMarker(mai5_2[0], mai5_2[3]);
  line.DrawLine(mai5_1[0]+mai5_1[1], mai5_1[3], mai5_1[0]+mai5_1[2], mai5_1[3]);
  line.DrawLine(mai5_2[0], mai5_2[3]+mai5_2[4], mai5_2[0], mai5_2[3]+mai5_2[5]);
  line.DrawLine(mai5_1[0], mai5_1[3]+mai5_1[4], mai5_1[0], mai5_1[3]+mai5_1[5]);
  line.DrawLine(mai5_2[0]+mai5_2[1], mai5_2[3], mai5_2[0]+mai5_2[2], mai5_2[3]);
  line.DrawLine(mai5_1[0], mai5_1[3], 1360, -15);
  line.DrawLine(1360, -15, 1355, -45);
  line.DrawLine(mai5_2[0], mai5_2[3], 1350, -52);
  latex.DrawLatex(1340, -50, "Mai et al. #5");
  
  mark.SetMarkerColor(2);
  line.SetLineColor(2);
  latex.SetTextColor(2);
  mark.SetMarkerStyle(21);
  mark.DrawMarker(DCC_A1[0], DCC_A1[1]);
  mark.SetMarkerStyle(20);
  mark.DrawMarker(DCC_A2[0], DCC_A2[1]);
  line.DrawLine(DCC_A2[0], DCC_A2[1], 1400, -60);
  line.DrawLine(DCC_A1[0], DCC_A1[1], 1415, -65);
  latex.DrawLatex(1402, -63, "DCC.A");
  
  mark.SetMarkerColor(4);
  line.SetLineColor(4);
  latex.SetTextColor(4);
  mark.SetMarkerStyle(21);
  mark.DrawMarker(DCC_B1[0], DCC_B1[1]);
  mark.SetMarkerStyle(20);
  mark.DrawMarker(DCC_B2[0], DCC_B2[1]);  
  line.DrawLine(DCC_B2[0], DCC_B2[1], 1410, -90);
  line.DrawLine(DCC_B1[0], DCC_B1[1], 1420, -80);
  latex.DrawLatex(1405, -87, "DCC.B");

  c1-> Print("L1405_pole.eps");
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
  h2-> GetXaxis()-> SetTitle("M_{#pi #Sigma} [MeV]");
  h2-> GetYaxis()-> SetTitle("#Gamma [MeV]");

  return h2;
}
