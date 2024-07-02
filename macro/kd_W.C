{
  const double beam_mom=1.0;
  const double kpMass = 0.4936;
  //  const double dMass = 1.87561;
  const double dMass = 0.938;

  TLorentzVector beam_lmom;
  beam_lmom.SetVectM(TVector3(0, 0, beam_mom), kpMass);
  TLorentzVector tgt_lmom;
  tgt_lmom.SetVectM(TVector3(0, 0, 0), dMass);

  const TLorentzVector tot_lmom=beam_lmom+tgt_lmom;
  std::cout<<tot_lmom.E()<<std::endl;
}
