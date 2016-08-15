#include<iostream>
#include<math.h>
#include<iomanip>
#include <algorithm>
#define FOR(i,a) 	for(int i=0;i<a;i++)

using namespace std;
void printTime(int a){
	int hour = a/3600;
	int min = a/60 - 60*hour;
	int sec = a - 3600*hour - 60*min;
	cout<<setfill('0')<<setw(2)<<hour<<":";
	cout<<setfill('0')<<setw(2)<<min<<":";
	cout<<setfill('0')<<setw(2)<<sec<<endl;
}
int main(){
	int n;
	int next = 1;
	while(cin>>n){
		int sce[100];
		int temp[100];
		int count=0;
		if(next !=0 && next != 1) {sce[count++]=next; }
		else if(next==0) break;
		sce[count++] = n;
		while(cin>>next){ 
			if(next == 0) {
				sort(sce, sce + count);
				int min = sce[0];
				int max = sce[count-1];
				int greTime = min - 5;
				int cycle = min*2;
				int maxLower = 0;
				int maxUpper;
				while(true){
					int gre = count;
					maxLower += cycle;
					if(maxLower > 5*3600) 
					{
						cout<<"Signals fail to synchronise in 5 hours"<<endl;
						break;
					}
					maxUpper = maxLower + greTime;   
					int minLower = maxLower;
					int minUpper = maxUpper;   
					for(int i=count-1;i>=0;i--){
						int cy = (sce[i]<<1);
						float temp = (float) cy;
						int fre = (int)(minLower/temp + 0.5);
						int lo = fre * cy;
						int up = lo + sce[i] -5;
						if(lo>=minUpper) break;
						else{
							if(lo>=minLower) minLower = lo;
							else if(up> minLower) minUpper = (up<minUpper?up:minUpper);
							else break;
						}
						gre = i;
					}
					if(gre == 0) 
					{
						printTime(minLower);
						break;
					}
				}				
				cin>>next; break;				
			}
			else sce[count++] = next;     
		}   
	}       
	return 0;   
}
