#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#include <math.h>
#include<iomanip>
#include<map>
#define FOR(i,a,n) for(int i=a; i<=n; i++)
#define N 25
#define INF 0xFFFFFFF
using namespace std;

char a[N], b[N];
int alen, blen;
int dp[N][N], path[N][N], edit[4];;
void init(){
	memset(path,-1,sizeof(path));
	FOR(i,0,alen){
		dp[i][0]=i;
		path[i][0]=1;
	}
	FOR(i,0,blen){
		dp[0][i]=i;
		path[0][i]=2;
	}	
}
void printPath(int i, int j){
	if(i ==0 && j==0) return;
	switch(path[i][j]){
		case 1: 
			printPath(i-1, j);
			printf("D%c%02d", a[i], j+1);
			break;
		case 2:
			printPath(i, j-1);
			printf("I%c%02d", b[j], j);
			break;			
		case 3:
			printPath(i-1, j-1);
			printf("C%c%02d", b[j], j);	
			break;				
		default:
			printPath(i-1, j-1);
			break;	
	}		
}
int main(){
	while(scanf("%s", a+1)){
		if(a[1] == '#') break;
		scanf("%s", b+1);
		alen = strlen(a+1);
		blen = strlen(b+1);
		init();
		
		FOR(i,1,alen) FOR(j,1,blen){
			dp[i][j]=INF;
			edit[1]=dp[i-1][j]+1; //D
			edit[2]=dp[i][j-1]+1; //A
			edit[3]=dp[i-1][j-1]+1; //C
			if(a[i] == b[j])
				edit[0] = dp[i-1][j-1];
			else
				edit[0] = INF;
			FOR(k,0,3){
				if(edit[k]<dp[i][j]){
					dp[i][j]=edit[k];
					path[i][j]=k;
				}
			}													
		}	
				
		printPath(alen,blen);
		puts("E");
	}
	return 0;
}
