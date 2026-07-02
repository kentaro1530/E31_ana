#include "../init.C"
const TString infilename = "../ag_Run78/root/Run78/readAna.root";

TH2F* setOpts(TH2F* h2);

const double pos[3] = { -0.4, -0.5, -5.9 };
const double rot[3] = { Deg2Rad*0.2,   Deg2Rad*0.8, Deg2Rad*0 };
const double r = 3;
const double len = 10.;

void draw_vertex(){
  init();
    
  TFile *f =new TFile(infilename);
  TCanvas *c1 = new TCanvas();
  double x0, y0, x1, y1, x2, y2, x3, y3;
  TEllipse circle(-0.4, -0.5, 3);
  circle.SetLineWidth(2);
  circle.SetLineColor(2);
  circle.SetFillStyle(0);
  
  TLine line;
  line.SetLineColor(2);
  line.SetLineWidth(2);
  
  std::vector<TPad*> pads;
  setMargin(0.01, 0.15, 0.15, 0.001);
  TPad *pad=new TPad("pad_xy", "pad_xy", 0.0, 0.5, 0.4, 1.0);
  pad-> Draw();
  pads.push_back(pad);

  setMargin(0.01, 0.001, 0.15, 0.1);
  pad=new TPad("pad_zy", "pad_zy", 0.4, 0.5, 1.0, 1.0);
  pad-> Draw();
  pads.push_back(pad);

  setMargin(0.001, 0.001, 0.15, 0.1);
  pad=new TPad("pad_zx", "pad_zx", 0.4, 0.075, 1.0, 0.575);
  pad-> Draw();
  pads.push_back(pad);

  pads[0]->cd();  
  TH2F *h2 = setOpts((TH2F*)f-> Get("Vtx_XY"));
  h2-> GetXaxis()-> SetRangeUser(-7, 7);
  h2-> GetYaxis()-> SetRangeUser(-7, 7);
  h2-> GetXaxis()-> SetTitle("X [cm]");
  h2-> GetYaxis()-> SetTitle("Y [cm]");
  h2-> Draw("colz");
  gPad-> SetLogz();
  circle.DrawEllipse(-0.4, -0.5, 3, 3, 0, 360, 0);
  
  pads[1]->cd();
  h2 = setOpts((TH2F*)f-> Get("Vtx_ZY"));
  h2-> GetXaxis()-> SetRangeUser(-20, 10);
  h2-> GetYaxis()-> SetRangeUser(-7, 7);
  h2-> Draw("colz");
  x0 = pos[2] - 0.5*len*cos(rot[0]);
  y0 = -r + pos[1] - 0.5*r*sin(rot[0]);
  x1 = pos[2] + 0.5*len*cos(rot[0]);
  y1 = -r + pos[1] + 0.5*r*sin(rot[0]);
  x2 = pos[2] + 0.5*len*cos(rot[0]);
  y2 = r + pos[1] - 0.5*r*sin(rot[0]);
  x3 = pos[2] - 0.5*len*cos(rot[0]);
  y3 = r + pos[1] + 0.5*r*sin(rot[0]);
  line.DrawLine(x0, y0, x1, y1);
  line.DrawLine(x1, y1, x2, y2);
  line.DrawLine(x2, y2, x3, y3);
  line.DrawLine(x3, y3, x0, y0);
  gPad-> SetLogz();

  pads[2]->cd();
  h2 = setOpts((TH2F*)f-> Get("Vtx_ZX"));
  h2-> GetXaxis()-> SetRangeUser(-20, 10);
  h2-> GetYaxis()-> SetRangeUser(-7, 7);
  h2-> GetYaxis()-> SetTitle("Y [cm]");
  h2-> GetXaxis()-> SetTitle("Z [cm]");
  h2-> Draw("colz");

  x0 = pos[2] - 0.5*len*cos(rot[1]);
  y0 = -r + pos[0] - 0.5*r*sin(rot[1]);
  x1 = pos[2] + 0.5*len*cos(rot[1]);
  y1 = -r + pos[0] + 0.5*r*sin(rot[1]);
  x2 = pos[2] + 0.5*len*cos(rot[1]);
  y2 = r + pos[0] - 0.5*r*sin(rot[1]);
  x3 = pos[2] - 0.5*len*cos(rot[1]);
  y3 = r + pos[0] + 0.5*r*sin(rot[1]);
  line.DrawLine(x0, y0, x1, y1);
  line.DrawLine(x1, y1, x2, y2);
  line.DrawLine(x2, y2, x3, y3);
  line.DrawLine(x3, y3, x0, y0);
  gPad-> SetLogz();

  c1-> Print("vertex.eps");
}


TH2F* setOpts(TH2F* h2){
  std::cout<<h2<<std::endl;
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
  return h2;
}
