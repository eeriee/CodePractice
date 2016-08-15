#include<iostream>
#include <math.h>

using namespace std;
int main(){
	int l,u;
	while(cin>>l>>u){
		int finalCount = 0;
		for(int v=l; v<=u; v++){
			int end = (int)sqrt(v)+1;
			int count = 0;
			for(int b = 1; b<end;b++){
				if(v%b==0){
					int factor = v/b;
					if(!((factor+b)&3)){                                               
						if(3*b*b>v && factor!=b) 
							count+=2;
						else
							count++;
					}
				}
			}
			if(count>1)
				finalCount += ((count)*(count-1)>>1);
		}
		cout<<finalCount<<endl; 
	}
	return 0;   
}
