/*
it was a dark and stormy night. Detective havel and Detective Hakimi arrived at the scene of crime.
Other than the detectives there were 10 people present. They asked the first person:"out of the 9 other people there
how many had you already met before tonight?"  The person answered "5". They asked the same question
to the econt person who answered "5", and so on.
The 10 answers were:
5 3 0 2 6 2 0 7 2 5
The detectives looked at the answers carefully and deduced that there was an inconsistency, and
somebody must be lying.(for the purpose of this code, asume that nobody makes mistakes or forgets, adn if X has met Y,
that means Y has has also met X.)
*/
#include <iostream>
using namespace std;
int size=10;
void removeZeros(int* arr){
  int zeroCount=0;
  for (size_t i = 0; i < size; i++) {
    if(arr[i]==0){
      zeroCount++;
      arr[i]=-1;
    }
  }
  size=size-zeroCount;
}

void descendingSort(int* arr){
    int mayor, temp;
		for (int i = 0; i < size; i++) {
			mayor=i;
			for (int j = i+1; j < size; j++){
				if (arr[j]>arr[mayor]){
					mayor=j;
				}
			}
			temp=arr[i];
			arr[i]=arr[mayor];
			arr[mayor]=temp;
		}
  }


int main(){
  bool truth=true;
  int peopleArray[]={5,3,0,2,6,2,0,7,2,5};
while(true){
  descendingSort(&peopleArray[0]);
  removeZeros(&peopleArray[0]);
  for (size_t i = 0; i < size; i++) {
    cout<<peopleArray[i]<<" ";
  }
  cout<<endl;
  cout<<"actual size: "<<size<<endl;
  if(size==0){
    truth=true;
    break;
  }else if(peopleArray[0]>(size-1)){
    truth=false;
    break;
  }else{
    for (size_t i = 1; i <= peopleArray[0]; i++) {
      peopleArray[i]--;
    }
    peopleArray[0]=-1;
    descendingSort(&peopleArray[0]);
    size--;
  }
}
if(truth){
    cout<<"No hay inconsistencias"<<endl;
}else{
  cout<<"Alguien mintio"<<endl;
}

  return 0;
}
