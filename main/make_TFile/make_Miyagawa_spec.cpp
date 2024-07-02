void make_Miyagawa_spec(){
  TGraph *gra_pimSp_blue=read_file::makeGraph2("txt/miyagawa_pimSp_blue.txt");
  TGraph *gra_pipSm_blue=read_file::makeGraph2("txt/miyagawa_pipSm_blue.txt");
  TGraph *gra_pi0S0_blue=read_file::makeGraph2("txt/miyagawa_pi0S0_blue.txt");
  TGraph *gra_pimS0_blue=read_file::makeGraph2("txt/miyagawa_pimS0_blue.txt");
  gra_pimSp_blue-> Write("pimSp_miyagawa_blue");
  gra_pipSm_blue-> Write("pipSm_miyagawa_blue");
  gra_pi0S0_blue-> Write("pi0S0_miyagawa_blue");
  gra_pimS0_blue-> Write("pimS0_miyagawa_blue");

  TGraph *gra_pimSp_blue_conv=read_file::makeGraph_conv2("txt/miyagawa_pimSp_blue.txt");
  TGraph *gra_pipSm_blue_conv=read_file::makeGraph_conv2("txt/miyagawa_pipSm_blue.txt");
  TGraph *gra_pimS0_blue_conv=read_file::makeGraph_conv2("txt/miyagawa_pimS0_blue.txt");
  TGraph *gra_pi0S0_blue_conv=read_file::makeGraph_conv2("txt/miyagawa_pi0S0_blue.txt");
  gra_pimSp_blue_conv-> Write("pimSp_miyagawa_blue_conv");
  gra_pipSm_blue_conv-> Write("pipSm_miyagawa_blue_conv");
  gra_pimS0_blue_conv-> Write("pimS0_miyagawa_blue_conv");
  gra_pi0S0_blue_conv-> Write("pi0S0_miyagawa_blue_conv");

  TGraph *gra_pimSp_red=read_file::makeGraph2("txt/miyagawa_pimSp_red.txt");
  TGraph *gra_pipSm_red=read_file::makeGraph2("txt/miyagawa_pipSm_red.txt");
  TGraph *gra_pi0S0_red=read_file::makeGraph2("txt/miyagawa_pi0S0_red.txt");
  TGraph *gra_pimS0_red=read_file::makeGraph2("txt/miyagawa_pimS0_red.txt");
  gra_pimSp_red-> Write("pimSp_miyagawa_red");
  gra_pipSm_red-> Write("pipSm_miyagawa_red");
  gra_pi0S0_red-> Write("pi0S0_miyagawa_red");
  gra_pimS0_red-> Write("pimS0_miyagawa_red");

  TGraph *gra_pimSp_red_conv=read_file::makeGraph_conv2("txt/miyagawa_pimSp_red.txt");
  TGraph *gra_pipSm_red_conv=read_file::makeGraph_conv2("txt/miyagawa_pipSm_red.txt");
  TGraph *gra_pimS0_red_conv=read_file::makeGraph_conv2("txt/miyagawa_pimS0_red.txt");
  TGraph *gra_pi0S0_red_conv=read_file::makeGraph_conv2("txt/miyagawa_pi0S0_red.txt");
  gra_pimSp_red_conv-> Write("pimSp_miyagawa_red_conv");
  gra_pipSm_red_conv-> Write("pipSm_miyagawa_red_conv");
  gra_pimS0_red_conv-> Write("pimS0_miyagawa_red_conv");
  gra_pi0S0_red_conv-> Write("pi0S0_miyagawa_red_conv");

  TGraph *gra_pimSp_green=read_file::makeGraph2("txt/miyagawa_pimSp_green.txt");
  TGraph *gra_pipSm_green=read_file::makeGraph2("txt/miyagawa_pipSm_green.txt");
  TGraph *gra_pi0S0_green=read_file::makeGraph2("txt/miyagawa_pi0S0_green.txt");
  TGraph *gra_pimS0_green=read_file::makeGraph2("txt/miyagawa_pimS0_green.txt");
  gra_pimSp_green-> Write("pimSp_miyagawa_green");
  gra_pipSm_green-> Write("pipSm_miyagawa_green");
  gra_pi0S0_green-> Write("pi0S0_miyagawa_green");
  gra_pimS0_green-> Write("pimS0_miyagawa_green");

  TGraph *gra_pimSp_green_conv=read_file::makeGraph_conv2("txt/miyagawa_pimSp_green.txt");
  TGraph *gra_pipSm_green_conv=read_file::makeGraph_conv2("txt/miyagawa_pipSm_green.txt");
  TGraph *gra_pimS0_green_conv=read_file::makeGraph_conv2("txt/miyagawa_pimS0_green.txt");
  TGraph *gra_pi0S0_green_conv=read_file::makeGraph_conv2("txt/miyagawa_pi0S0_green.txt");
  gra_pimSp_green_conv-> Write("pimSp_miyagawa_green_conv");
  gra_pipSm_green_conv-> Write("pipSm_miyagawa_green_conv");
  gra_pimS0_green_conv-> Write("pimS0_miyagawa_green_conv");
  gra_pi0S0_green_conv-> Write("pi0S0_miyagawa_green_conv");
}
