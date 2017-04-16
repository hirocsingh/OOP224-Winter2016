#include "PosApp.h"
int main(){
  ict::PosApp app("posapp.txt", "bill.txt");
  app.run();
  return 0;
}
