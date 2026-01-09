#pragma once
#include "common.hh"

const double N_theta = 10;
const double dtheta = TMath::Pi()/N_theta;

const double max_mom = 0.5;
const double N_mom = 10;
const double dmom = max_mom/N_mom;

const double onshell_mass = nMass;
const double Kbar_mass = kpMass;

const int MAX_ITERATION = 50;
const double TOL = 1.0e-12;
