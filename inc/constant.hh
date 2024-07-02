#ifndef CONSTANT_HH
#define CONSTANT_HH 1

//#include "common.hh"
#include "TInclude.hh"

namespace{
  const double PI=TMath::Pi();
  const double Const_GeVFM=0.1973269602; // GeV*fm

  const double pimMass=0.13957;
  const double pi0Mass=0.13498;
  const double pipMass=0.13957;
  const double piMass=(pimMass+pipMass+pi0Mass)/3.0;

  const double pMass = 0.938272;
  const double nMass = 0.939565;
  const double NMass = 0.5*(pMass+nMass);

  const double dMass = 1.87561;

  const double kpMass = 0.4936;
  const double kmMass = 0.4936;
  const double k0Mass = 0.497614;
  const double kMass  = 0.5*(kmMass+k0Mass);

  const double s0Mass= 1.192642;
  const double spMass= 1.18937;
  const double smMass= 1.197449;
  const double sigmaMass=(smMass+spMass+s0Mass)/3.0;
}

#endif
