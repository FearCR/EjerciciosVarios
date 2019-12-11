//cantidad de anos viciestos de enero de un ano a enero del otro
#include <iostream>
using namespace std;
int leap(int start, int fin){
  int leaps=0;
  for (size_t i = start; i < fin; i++) {
    if(i%4==0){
      if(i%100!=0){
        leaps++;
      }else if( i%900==200||i%900==600){
        leaps++;
      }
    }
  }
  return leaps;
}
int main(){
  int totalLeaps;
  totalLeaps=leap(123456,7891011);

  cout<<totalLeaps<<endl;
  return 0;
}
