const double piMass = 0.13957;
const double pMass = 0.938272;
const double nMass = 0.939565;
const double dMass = 1.87561;
const double lMass = 1.115683;
const double s0Mass= 1.192642;
const double spMass= 1.18937;
const double smMass= 1.197449;
const double kpMass = 0.4936;
const double k0Mass = 0.497614;
const double ThreeHeMass = 2.80839;
const double kMass=0.5*(kpMass+k0Mass);
const double NMass=0.5*(pMass+nMass);
const double Const_GeVFM=0.1973269602; // GeV*fm

void init(){
  gROOT-> GetColor(3)-> SetRGB(0., 0.7, 0.); //Green  (0., 1.,0.)
  gROOT-> GetColor(5)-> SetRGB(1., 0.5, 0.); //Yellow (1., 1.,0.)  
  gROOT-> GetColor(6)-> SetRGB(135./255., 0/255., 204./255.); //Yellow (1., 1.,0.)
  double gray=150./255.;
  gROOT-> GetColor(kGray)-> SetRGB(gray, gray, gray);

  
  gStyle-> SetTitleH(0.11);
  setMargin(0.01, 0.15, 0.15, 0.1);

  Double_t doubleGauss(Double_t *x, Double_t *par){
    if( x[0]<par[1] ) return par[0]*std::exp(-(x[0]-par[1])*(x[0]-par[1])/(4*par[2]*par[2]));
    else  return par[0]*std::exp(-(x[0]-par[1])*(x[0]-par[1])/(4*par[3]*par[3]));
  }
  TF1* func=new TF1("double_gaus", doubleGauss, -1.0, 2.0, 4);
  func-> SetParameter(0, 1000);
  func-> SetParameter(1, 0.5);
  func-> SetParameter(2, 0.1);
  func-> SetParameter(3, 0.5);
}

TGraph* scale(TGraph *gra, double val){
  std::vector<double> x, y;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra->GetPoint(i, tmpx, tmpy);
    x.push_back(tmpx);
    y.push_back(val*tmpy);
  }
  return new TGraph(x.size(), &x[0], &y[0]);
}


void setMargin(double top, double left, double bottom, double right){
  gStyle-> SetPadLeftMargin(left);
  gStyle-> SetPadBottomMargin(bottom);
  gStyle-> SetPadRightMargin(right);
  gStyle-> SetPadTopMargin(top);
}

void setLeftMargin(double val){ gStyle-> SetPadLeftMargin(val); }
void setRightMargin(double val){ gStyle-> SetPadRightMargin(val); }
void setTopMargin(double val){ gStyle-> SetPadTopMargin(val); }
void setBottomMargin(double val){ gStyle-> SetPadBottomMargin(val); }

void setMargin(){ setMargin(0.15, 0.1, 0.15, 0.01); }

TH1F* set(TH1F* obj, int colorID=kBlack){
  //  cout<<obj<<endl;
  obj-> SetLineColor(colorID);
  obj->SetStats(0);
  obj-> SetTitle("");
  obj->GetXaxis()->SetLabelSize(0.05);
  obj->GetXaxis()->SetTitleSize(0.06);
  obj->GetXaxis()->CenterTitle();

  obj->GetYaxis()->SetLabelSize(0.05);
  obj->GetYaxis()->SetTitleSize(0.06);
  obj->GetYaxis()->CenterTitle();
  return obj;
}

TGraphErrors* GevToMev(TGraphErrors* gra, int colorID=kBlack){
  std::vector<double> x, y, xerr, yerr;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    double tmpye=gra->GetErrorY(i);
    double tmpxe=gra->GetErrorX(i);
    x.push_back(1000.*tmpx);
    y.push_back(tmpy);
    xerr.push_back(1000.*tmpxe);
    yerr.push_back(tmpye);
  }
  TGraphErrors* gra= new TGraphErrors(x.size(), &x[0], &y[0], &xerr[0], &yerr[0]);

  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetMarkerStyle(8);
  gra-> SetLineWidth(3);
  gra-> SetMarkerSize(1.2);
  gra-> GetXaxis()-> SetRangeUser(1350, 1500);
  gra-> GetYaxis()-> SetRangeUser(0, 30);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  gra->SetTitle("");
  return gra;
}

TGraph* GevToMev(TGraph* gra, int colorID=kBlack){
  std::vector<double> x, y;
  for( int i=0; i<gra->GetN(); i++ ){
    double tmpx, tmpy;
    gra-> GetPoint(i, tmpx, tmpy);
    x.push_back(1000.*tmpx);
    y.push_back(tmpy);
  }
  TGraph* gra= new TGraph(x.size(), &x[0], &y[0]);

  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(3);
  gra-> SetMarkerSize(1.2);
  gra-> GetXaxis()-> SetRangeUser(1350, 1500);
  gra-> GetYaxis()-> SetRangeUser(0, 30);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  gra->SetTitle("");
  return gra;
}
