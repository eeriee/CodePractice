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
#define N 55
#define FOR(i,a,n) for(int i=a; i<n; i++)
#define MAX(a,b,c,d,x) dp[i][j][hh][ww]=max(dp[i][j][hh][ww],dp[a][b][c][d]+x);
char grid[N][N];
int dp[N][N][N][N],r,c;

int donut(){
	memset(dp,0,sizeof(dp));
	int hh,ww,d;
	FOR(h,3,r+1) FOR(w,3,c+1)FOR(i,0,r+1-h)FOR(j,0,c+1-w){
		hh=i+h-1;
		ww=j+w-1;
		d=1;
		FOR(k,0,w) if(grid[i][j+k]!='0'||grid[hh][j+k]!='0') d=0;
		FOR(k,0,h) if(grid[i+k][j]!='0'||grid[i+k][ww]!='0') d=0;
		dp[i][j][hh][ww]=d;
		MAX(i+1,j,hh,ww,0);
		MAX(i,j+1,hh,ww,0);
		MAX(i,j,hh-1,ww,0);
		MAX(i,j,hh,ww-1,0);
		MAX(i+1,j+1,hh-1,ww-1,d);
	} 				
	return dp[0][0][r-1][c-1];
}
int main(){
	int n;
	scanf("%d", &n); 
	FOR(t,1,n+1){
		scanf("%d", &r); 
		FOR(i,0,r)
			scanf(" %[^\n]", grid[i]);
		c=strlen(grid[0]);			
		printf("Case #%d: %d\n",t, donut());
	}
    return 0;
}
