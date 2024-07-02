#include "root_util.hh"

TGraph* root_util::set_opts(TGraph* gra){
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);

  gra-> GetXaxis()-> CenterTitle();
  gra-> GetXaxis()->SetLabelSize(0.05);
  gra-> GetXaxis()->SetTitleSize(0.06);
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");

  gra-> GetYaxis()-> CenterTitle();
  gra-> GetYaxis()->SetLabelSize(0.05);
  gra-> GetYaxis()->SetTitleSize(0.06);
  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");

  gra-> SetLineWidth(2);
  gra-> SetTitle("");

  return gra;
}

TGraphErrors* root_util::set_opts(TGraphErrors* gra){
  gra-> GetXaxis()-> SetRangeUser(1.35, 1.5);

  gra-> GetXaxis()-> CenterTitle();
  gra-> GetXaxis()->SetLabelSize(0.05);
  gra-> GetXaxis()->SetTitleSize(0.06);
  gra-> GetXaxis()-> SetTitle("#pi #Sigma mass [GeV/c^{2}]");

  gra-> GetYaxis()-> CenterTitle();
  gra-> GetYaxis()->SetLabelSize(0.05);
  gra-> GetYaxis()->SetTitleSize(0.06);
  gra-> GetYaxis()-> SetTitle("#frac{d^{2}#sigma}{d#Omega dm} #mub/sr MeV");

  gra-> SetLineWidth(2);
  gra-> SetTitle("");

  return gra;
}

TGraph* root_util::add(TGraph *gra1, TGraph *gra2){
  std::vector<double> x, y;

  if( gra1->GetN()!=gra2->GetN() ){
    std::cout<<"!!!!! root_util::add TGraph  N is not matched !!!!!"<<std::endl;
    exit(0);
  }

  for( int i=0; i<gra1-> GetN(); i++ ){
    double x1, y1, x2, y2;
    gra1-> GetPoint(i, x1, y1);
    gra2-> GetPoint(i, x2, y2);
    if( fabs(x1-x2)>1.0e-8 ){
      std::cout<<"!!!!! root_util::add TGraph i="<<i<<" x is not matched !!!!!"<<std::endl;
      exit(0);
    }
    x.push_back(x1);
    y.push_back(y1+y2);
  }

  return new TGraph(gra1->GetN(), &x[0], &y[0]);
}

TGraph* root_util::sub(TGraph *gra1, TGraph *gra2){
  std::vector<double> x, y;

  if( gra1->GetN()!=gra2->GetN() ){
    std::cout<<"!!!!! root_util::add TGraph  N is not matched !!!!!"<<std::endl;
    exit(0);
  }

  for( int i=0; i<gra1-> GetN(); i++ ){
    double x1, y1, x2, y2;
    gra1-> GetPoint(i, x1, y1);
    gra2-> GetPoint(i, x2, y2);
    if( fabs(x1-x2)>1.0e-8 ){
      std::cout<<"!!!!! root_util::add TGraph i="<<i<<" x is not matched !!!!!"<<std::endl;
      exit(0);
    }
    x.push_back(x1);
    y.push_back(y1-y2);
  }

  return new TGraph(gra1->GetN(), &x[0], &y[0]);
}


TGraph* root_util::scale(double scale, TGraph *gra1){
  std::vector<double> x, y;

  for( int i=0; i<gra1-> GetN(); i++ ){
    double x1, y1;
    gra1-> GetPoint(i, x1, y1);
    x.push_back(x1);
    y.push_back(scale*y1);
  }

  return new TGraph(gra1->GetN(), &x[0], &y[0]);
}
