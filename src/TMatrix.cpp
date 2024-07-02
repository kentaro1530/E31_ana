#include "TMatrix.hh"
#include "W_to_mom.hh"

TransMatrix::TransMatrix(const double mass00, const double mass01, const double mass10, const double mass11)
  : fMass00(mass00), fMass01(mass01), fMass10(mass10), fMass11(mass11) {
  if( fMass00+fMass01>fMass10+fMass11 ){
    std::swap(fMass00, fMass10);
    std::swap(fMass10, fMass11);
  }
}

TransMatrix::TransMatrix(const double mass00, const double mass01, const double mass10, const double mass11,
		 const std::complex<double> &A, const std::complex<double> &R, const double &phase) 
  : TransMatrix(mass00, mass01, mass10, mass11){ fA=A, fR=R, fPhase=phase; }

std::complex<double> TransMatrix::amp12(const double &E) const {
  const std::complex<double> k1=W_to_mom(E, fMass00, fMass01);
  const std::complex<double> k2=W_to_mom(E, fMass10, fMass11);
  
  const std::complex<double> factor=exp(std::complex<double>(0, 1)*fPhase)/sqrt(k1);
  //  std::cout<<norm(fA)<<"  "<<abs(pow(fA, 2))<<"  "<<pow(abs(fA), 2)<<std::endl;
  const std::complex<double> num=sqrt(fA.imag()-0.5*norm(fA)*fR.imag()*k2*k2);
  const std::complex<double> deno=1.0-std::complex<double>(0, 1)*fA*k2+0.5*fA*fR*k2*k2;
  //  std::cout<<E<<"  "<<k1<<"   "<<k2<<std::endl;
  //  std::cout<<"    "<<factor<<"  "<<num<<"  "<<deno<<std::endl;

  return factor*num/deno;
}

std::complex<double> TransMatrix::amp22(const double &E) const {
  const std::complex<double> k2=W_to_mom(E, fMass10, fMass11);
  return fA/(1.0-std::complex<double>(0, 1)*fA*k2+0.5*fA*fR*k2*k2);
}
