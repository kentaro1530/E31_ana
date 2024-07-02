#include <vector>
#include "macro/init.C"

std::vector<std::vector<double> > read_amp(char* filepath){
  ifstream ifs(filepath);

  std::vector<std::vector<double> > data;
  std::string str;
  while( getline(ifs, str) ){
    double x, y;
    if( sscanf(str.c_str(), "%lf %lf", &x, &y)==2 ){
      std::vector<double> tmp;
      tmp.push_back(x);
      tmp.push_back(y);
      data.push_back(tmp);
    }
  }
  return data;
}

void draw_phase(){
  init();
  const double kpThre=kpMass+pMass;
  const double B1=1.428;
  const double B2=1.397;
  const double A1=1.432;
  const double A2=1.372;

  TLine line;
  line.SetLineColor(3);
  line.SetLineWidth(2);

  std::vector<std::vector<double> > pimS0_A_data=read_amp("txt/pimS0_A.txt");
  std::vector<std::vector<double> > pimSp_A_data=read_amp("txt/pimSp_A.txt");
  std::vector<std::vector<double> > pipSm_A_data=read_amp("txt/pipSm_A.txt");
  std::vector<std::vector<double> > pi0S0_A_data=read_amp("txt/pi0S0_A.txt");

  std::vector<std::vector<double> > pimS0_B_data=read_amp("txt/pimS0_B.txt");
  std::vector<std::vector<double> > pimSp_B_data=read_amp("txt/pimSp_B.txt");
  std::vector<std::vector<double> > pipSm_B_data=read_amp("txt/pipSm_B.txt");
  std::vector<std::vector<double> > pi0S0_B_data=read_amp("txt/pi0S0_B.txt");

  for( int i=0; i<pimS0_B_data.size(); i++ ){
    if( pimS0_A_data[i][0]!=pipSm_A_data[i][0] ) std::cout<<"x not match"<<std::endl;
    if( pimS0_A_data[i][0]!=pimSp_A_data[i][0] ) std::cout<<"x not match"<<std::endl;
    if( pimS0_A_data[i][0]!=pi0S0_A_data[i][0] ) std::cout<<"x not match"<<std::endl;

    if( pimS0_B_data[i][0]!=pipSm_B_data[i][0] ) std::cout<<"x not match"<<std::endl;
    if( pimS0_B_data[i][0]!=pimSp_B_data[i][0] ) std::cout<<"x not match"<<std::endl;
    if( pimS0_B_data[i][0]!=pi0S0_B_data[i][0] ) std::cout<<"x not match"<<std::endl;
  }

  std::cout<<pimS0_A_data.size()<<"  "
	   <<pimSp_A_data.size()<<"  "
	   <<pipSm_A_data.size()<<"  "
	   <<pi0S0_A_data.size()<<"  "<<std::endl;

  std::cout<<pimS0_B_data.size()<<"  "
	   <<pimSp_B_data.size()<<"  "
	   <<pipSm_B_data.size()<<"  "
	   <<pi0S0_B_data.size()<<"  "<<std::endl;
  std::vector<double> x, y_A, y_B;
  for( int i=0; i<pimSp_A_data.size(); i++ ){
    x.push_back(0.001*pimSp_A_data[i][0]);
    double val_A=0.25*(pimSp_A_data[i][1]-pipSm_A_data[i][1])/sqrt(pi0S0_A_data[i][1]*pimS0_A_data[i][1]);
    double val_B=0.25*(pimSp_B_data[i][1]-pipSm_B_data[i][1])/sqrt(pi0S0_B_data[i][1]*pimS0_B_data[i][1]);
    if( !TMath::IsNaN(val_A) ) y_A.push_back(val_A);
    else{
      std::cout<<pimSp_A_data[i][0]<<" error"<<std::endl;
      y_A.push_back(0);
    }
    if( !TMath::IsNaN(val_B) ) y_B.push_back(val_B);
    else{
      std::cout<<pimSp_B_data[i][0]<<" error"<<std::endl;
      y_B.push_back(0);
    }
  }
  TGraph *gra_A=set(new TGraph(x.size(), &x[0], &y_A[0]), kRed);
  TGraph *gra_B=set(new TGraph(x.size(), &x[0], &y_B[0]), kBlue);
  gra_A-> Draw("AL");
  gra_B-> Draw("L");
  line.SetLineColor(kRed);
  line.DrawLine(A1, 0, A1, 3.2);
  line.DrawLine(A2, 0, A2, 3.2);
  line.SetLineColor(kBlue);
  line.DrawLine(B1, 0, B1, 3.2);
  line.DrawLine(B2, 0, B2, 3.2);
  line.SetLineColor(3);
  line.DrawLine(kpThre, 0, kpThre, 3.2);
  TLegend *leg=new TLegend(0.6, 0.2, 0.9, 0.5);
  leg-> SetBorderSize(0);
  leg-> SetFillStyle(0);
  leg-> AddEntry(gra_A, "Model. A", "L");
  leg-> AddEntry(gra_B, "Model. B", "L");
  leg-> Draw();
  c1-> Print("pic/discussion/DCC_phase.eps");
}

TGraph* set(TGraph* gra, int colorID){
  gra-> SetMarkerStyle(8);
  gra-> SetLineColor(colorID);
  gra-> SetMarkerColor(colorID);
  gra-> SetLineWidth(2);
  gra-> GetXaxis()-> SetRangeUser(1.30, 1.55);
  gra-> GetYaxis()-> SetRangeUser(0, 1.0);
  gra-> SetTitle();
  gra->GetXaxis()->SetLabelSize(0.05);
  gra->GetXaxis()->SetTitleSize(0.06);
  gra->GetXaxis()->CenterTitle();

  gra->GetYaxis()->SetLabelSize(0.05);
  gra->GetYaxis()->SetTitleSize(0.06);
  gra->GetYaxis()->CenterTitle();
  gra->GetXaxis()->SetTitle("#pi#Sigma mass [GeV/c^{2}]");

  return gra;
}
