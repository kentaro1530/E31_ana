#include "macro/init.C"
#include "macro/make_gra.C"

void test(){
  TGraphErrors *gra_I0=make_data_sub();

  gra_I0-> Draw();

}
