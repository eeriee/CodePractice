//max flow
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

#define N 105
#define INF 1500

using namespace std;

int n,s,t,c,x,y,w;
int aug[N];
int pre[N];
int cap[N][N];
//int flow[N][N];

int EdmondsKarp(){
	queue<int> q;
	int f=0;
	while(true){
		memset(aug, 0, sizeof(aug));
		aug[s] = INF;
		q.push(s);
		while(!q.empty()){
			int u = q.front(); 
			q.pop();
			for(int v =1; v<=n; v++){
				if(!aug[v] && cap[u][v]){
					pre[v] = u;
					q.push(v);
					aug[v] = min(aug[u],cap[u][v]);	
				}				
			}	
		}
		if(aug[t] == 0) break;
		int temp = t;
		while(temp!=s){
			cap[pre[temp]][temp] -= aug[t];
			cap[temp][pre[temp]] += aug[t];
			temp = pre[temp];			
		}
		f += aug[t];
	}
	return f;	
}
int main(){
    int set = 1;
    while(scanf("%d", &n)){
			memset(cap,0,sizeof(cap));
          if(n == 0) break;
          scanf("%d %d %d", &s, &t, &c);
          for(int i=0; i<c; i++){ 
				scanf("%d %d %d", &x, &y, &w);
				cap[x][y] += w;	
				cap[y][x] += w;			                  
          }     
		  printf("Network %d\nThe bandwidth is %d.\n\n", set++, EdmondsKarp());   
    }
    return 0;
}
