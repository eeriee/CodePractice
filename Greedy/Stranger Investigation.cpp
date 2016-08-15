#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
using namespace std;
void swap(int &a, int &b){
    int temp;
    if(a>b){
        temp=a;a=b;b=temp;}
}
int main(){
    int N,k,n,t,i,j,s=0,count=0;
    int w[1000];
    cin>>N;
    for(t=0;t<N;t++){
        cin>>n>>k;
        for(i=0;i<n;i++){
            cin>>w[i];
            }
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++){
                swap(w[j],w[j+1]);
                }
            }
        for(i=0;i<n;i++){
            s+=w[i];
            if(s>k)
            break;
            count++;}
        cout<<count<<endl;
        s=0;
        count=0;
    }
    
    return 0;
}
