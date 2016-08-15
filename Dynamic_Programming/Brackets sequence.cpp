#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x7FFFFFFF
#define N 105

char s[N];
int dp[N][N];
bool isRegular(char a, char b){
	if(a == '(' && b == ')') return true;
    if(a == '[' && b == ']') return true;
    return false;		
}
int main(){
	int t,n;
	scanf("%d", &t); 
	getchar();
	while(t--){
		gets(s);
		gets(s);
		n=strlen(s);
		//memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++){
			dp[i+1][i]=0;
			dp[i][i]=1;
		}
		for(int i=n-1;i>=0;i--){
			for(int j=i+1; j<n; j++){
				dp[i][j]=INF;
				if(isRegular(s[i],s[j]))
					dp[i][j] = min(dp[i][j],dp[i+1][j-1]);
				 for(int k=i;k<j;k++)
                	dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);				
			}				
		}
		if(n) printf("%d\n",dp[0][n-1]+n);
		else puts("0");
		if(t) puts("");	
	}

    return 0;
}
