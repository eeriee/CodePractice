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
using namespace std;
#define N 1005

int t[N], year[N], dp[N];
char sign[N];
int n,cnt,mm, dd, HH, MM,cur,start,ed;

bool keep(int i){
	return sign[i] == '+';
}
int ans(){
	if(start == -1)
		return 0;
	dp[start] = 1;
	for(int i=start+1;i<n;i++){
		dp[i]=dp[i-1]+1;
		for(int j=i-1;j>=0;j--){
			if(year[i] == year[j] || (year[i]-1==year[j] && t[i]<t[j]) )
				dp[i]=min(dp[i],dp[j]+1);
			else break;
			if(keep(j)) break;
		}
	}
	cnt = dp[n-1];
	for(int i=n-2; year[i]==cur&&i>=ed; i--){
		cnt=min(cnt,dp[i]);
	}
	return cnt;
}
int main(){
	while(scanf("%d", &n),n){
		memset(year,0,sizeof(year));
		cnt=0;
		for(int i=0; i<n; i++){
			scanf("%d:%d:%d:%d %*s %c", &mm, &dd, &HH, &MM, &sign[i]);
			t[i] = ((mm * 31 + dd) * 24 + HH) * 60 + MM;
		}
		if(keep(0)) start = 0;
		else start = -1;
		for(int i=1; i<n; i++){
			if(start == -1 && keep(i)) start = i;
			if(keep(i)) ed=i;
			year[i]=(t[i-1]<t[i])?year[i-1]:year[i-1]+1;
		}
		cur = year[n-1];
		printf("%d\n",ans());
	}
	return 0;
}
