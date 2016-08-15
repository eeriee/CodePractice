#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<set>

using namespace std;
typedef unsigned long long ULL;
ULL power(ULL x, ULL p){
	if(p == 0)	return 1;
	if(p == 1) return x;
	return x*power(x,p-1);	
}
int main(){
	int prime[50];
	int flag[65];
	int cnt=0;	
	memset(flag,1,sizeof(flag));
	for(int i=2; i<65; i++){
		if(flag[i])	prime[++cnt]=i;
		for(int j=1; j<=cnt && i*prime[j]<65;j++){
			flag[prime[j]*i]=false;
			if(i%prime[j]==0) 
				break;
		}
	}
	set<ULL> sp;
	ULL ans;
	for(ULL i=2; i<1<<16; i++){
		ans = power(i,3);
		for(int j=4; j<65; j++){
			if(ans > ULLONG_MAX/i) break;
			ans *= i;
			if(!flag[j]){
				if(ans == 0)
					break;
				sp.insert(ans);
			}				
		}			
	}
	printf("1\n");
	for (set<ULL>::iterator it=sp.begin(); it!=sp.end(); ++it){
	    	printf("%llu\n", *it);
	}
	return 0;
}
