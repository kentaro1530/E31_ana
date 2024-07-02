#ifndef TMatrix_HH
#define TMatrix_HH 

#include "common.hh"
#include "constant.hh"

class TransMatrix{
public:
  TransMatrix(const double mass00, const double mass01, const double mass10, const double mass11);
  TransMatrix(const double mass00, const double mass01, const double mass10, const double mass11,
	  const std::complex<double> &A, const std::complex<double> &R, const double &phase);
  TransMatrix()=delete;
  ~TransMatrix()=default;

private:
  double fMass00;
  double fMass01;
  double fMass10;
  double fMass11;
  std::complex<double> fA;
  std::complex<double> fR;
  double fPhase=0;

public:
  std::complex<double> getA() const { return fA; }
  std::complex<double> getR() const { return fR; }
  double getMass00() const { return fMass00; }
  double getMass01() const { return fMass01; }
  double getMass10() const { return fMass10; }
  double getMass11() const { return fMass11; }
  double getPhase() const { return fPhase; }
  void setA(const std::complex<double> &A){ fA=A; }
  void setR(const std::complex<double> &R){ fR=R; }
  void setAR(const double &A_re, const double &A_im, const double &R_re, const double &R_im){ fA=std::complex<double>(A_re, A_im); fR=std::complex<double>(R_re, R_im); }
  void setPhase(const double &phase){ fPhase=phase; }
  void setMasses(const double mass00, const double mass01, const double mass10, const double mass11){ fMass00=mass00, fMass01=mass01, fMass10=mass10, fMass11=mass11; }

  std::complex<double> amp12(const double &E) const; 
  std::complex<double> amp22(const double &E) const; 
  //  std::complex<double> amp11
};

#endif
