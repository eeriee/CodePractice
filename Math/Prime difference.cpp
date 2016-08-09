#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#include<math.h>
#include<iomanip>
#include<map>

#define MAX 1299709
#define LMT 1140
using namespace std;
int prime[100005];
int flag[1300000];

int main(){		
	memset(flag,0,sizeof(flag));
	for(int i=3; i<LMT; i+=2){
		if(!flag[i]){
			for(int j=i*i; j<=MAX; j+= 2*i)
				flag[j]=-1;
		}
	}
	prime[1]=2;
	flag[2]=1;
	for(int i=3, cnt=1; i<=MAX; i+=2){
		if(!flag[i]){
			flag[i]=++cnt;
			prime[cnt]=i;
		}
	}
	int k;
	while(scanf("%d", &k), k){
		if(flag[k]>0){
			printf("%d\n", 0);
			continue;
		}
		for(int i=k+1; i<=MAX; i++)
			if(flag[i]>0){
				int idx = flag[i];
				printf("%d\n", prime[idx]-prime[idx-1]);
				break;
			}
	}
	return 0;
}
