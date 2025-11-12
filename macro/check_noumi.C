const double pMass = 0.938272;
const double nMass = 0.939565;
const double NMass = 0.5*(pMass+nMass);

const double kmMass = 0.4936;
const double k0Mass = 0.497614;
const double kMass  = 0.5*(kmMass+k0Mass);

void check_noumi(){
  auto A=std::complex<double>(-1.12/0.1973269602,  0.84/0.1973269602);
  auto R=std::complex<double>(-0.18/0.1973269602, -0.40/0.1973269602);

  std::complex<double> ans1=(std::complex<double>(0, 1)*A+sqrt(-A*A-2.0*A*R))/(A*R);
  std::complex<double> ans2=(std::complex<double>(0, 1)*A-sqrt(-A*A-2.0*A*R))/(A*R);

  std::complex<double> pole1=sqrt(ans1*ans1+NMass*NMass)+sqrt(ans1*ans1+kMass*kMass);
  std::complex<double> pole2=sqrt(ans2*ans2+NMass*NMass)+sqrt(ans2*ans2+kMass*kMass);

  std::cout<<pole1<<std::endl;
  std::cout<<pole2<<std::endl;
}
