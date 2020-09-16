#include <iostream>
#include <stdlib.h>
using namespace std;


int main(){
   int *a, n , aux=0;
   cin>>n;
   a=new int[n];
   for(int i=0 ; i<n ; i++){
    cin>>*(a+i);
   }
   for(int i=0; i<n ; i++){
        for(int j=0; j<n-1 ; j++){
            if(*(a+j) > *(a+j+1)){
               aux= *(a+j);
               *(a+j)= *(a+(j+1));
               *(a+(j+1))= aux;
            }
        }
   }
   for(int i=0 ; i<n ; i++){
    cout<<*(a+i)<<" ";
   }
   delete[] a;
   return 0;
}

