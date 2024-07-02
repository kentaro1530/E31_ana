#ifndef KAMANO_HH
#define KAMANO_HH

#include "common.hh"
#include "read_file.hh"
#include "util.hh"
#include "reso.hh"

class Kamano{
public:
  Kamano();
  ~Kamano()=default;

  double I0_A(double m) const;
  double I0_B(double m) const;
  double I1_A(double m) const;
  double I1_B(double m) const;

  double pi0S0_A(double m) const { return I0_A(m); };
  double pi0S0_B(double m) const { return I0_A(m); };
  double pimSp_A(double m) const;
  double pimSp_B(double m) const;
  double pipSm_A(double m) const;
  double pipSm_B(double m) const;
  double pimS0_A(double m) const { return I1_A(m); };
  double pimS0_B(double m) const { return I1_A(m); };
  double interfer_A(double m) const { return pimSp_A(m)-pipSm_A(m); };
  double interfer_B(double m) const { return pimSp_B(m)-pipSm_B(m); };

  double I0_A_wReso(double m) const { return pi0S0_A_wReso(m); };
  double I0_B_wReso(double m) const { return pi0S0_A_wReso(m); };
  double I1_A_wReso(double m) const { return pimS0_A_wReso(m); };
  double I1_B_wReso(double m) const { return pimS0_A_wReso(m); };

  std::vector<std::vector<double> > pi0S0_A_points() const { return pi0S0_A_xy; }
  std::vector<std::vector<double> > pi0S0_B_points() const { return pi0S0_B_xy; }
  std::vector<std::vector<double> > pimS0_A_points() const { return pimS0_A_xy; }
  std::vector<std::vector<double> > pimS0_B_points() const { return pimS0_B_xy; }
  std::vector<std::vector<double> > pimSp_A_points() const { return pimSp_A_xy; }
  std::vector<std::vector<double> > pimSp_B_points() const { return pimSp_B_xy; }
  std::vector<std::vector<double> > pipSm_A_points() const { return pipSm_A_xy; }
  std::vector<std::vector<double> > pipSm_B_points() const { return pipSm_B_xy; }
  std::vector<std::vector<double> > interfer_A_points() const { return interfer_A_xy; }
  std::vector<std::vector<double> > interfer_B_points() const { return interfer_B_xy; }

  double pi0S0_A_wReso(double m) const { return reso::conv_kn(m, pi0S0_A_xy[0], pi0S0_A_xy[1]); };
  double pi0S0_B_wReso(double m) const { return reso::conv_kn(m, pi0S0_B_xy[0], pi0S0_B_xy[1]); };
  double pimSp_A_wReso(double m) const { return reso::conv_kn(m, pimSp_A_xy[0], pimSp_A_xy[1]); };
  double pimSp_B_wReso(double m) const { return reso::conv_kn(m, pimSp_B_xy[0], pimSp_B_xy[1]); };
  double pipSm_A_wReso(double m) const { return reso::conv_kn(m, pipSm_A_xy[0], pipSm_A_xy[1]); };
  double pipSm_B_wReso(double m) const { return reso::conv_kn(m, pipSm_B_xy[0], pipSm_B_xy[1]); };
  double pimS0_A_wReso(double m) const { return reso::conv_kp(m, pimS0_A_xy[0], pimS0_A_xy[1]); };
  double pimS0_B_wReso(double m) const { return reso::conv_kp(m, pimS0_B_xy[0], pimS0_B_xy[1]); };

  void dump();

private:
  std::vector<std::vector<double> > pimSp_A_xy, pimSp_B_xy, pipSm_A_xy, pipSm_B_xy, pi0S0_A_xy, pi0S0_B_xy, pimS0_A_xy, pimS0_B_xy, interfer_A_xy, interfer_B_xy;
  //  std::vector<std::vector<double> > pimSp_A_xy_wReso, pimSp_B_xy_wReso, pipSm_A_xy_wReso, pipSm_B_xy_wReso, pi0S0_A_xy_wReso, pi0S0_B_xy_wReso, pimS0_A_xy_wReso, pimS0_B_xy_wReso;
};

#endif
