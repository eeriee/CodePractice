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

int l,w,n,d,x,y,s,t;
int aug[2*N];
int pre[2*N];
int cap[2*N][2*N];
int vertex[N][2];

void BuildGraph(int i){
	cap[2*i-1][2*i]=1;
	if(vertex[i][1]<=d)
		cap[0][2*i-1]=INF;
	if(vertex[i][1]+d>=w)
		cap[2*i][2*n+1]=INF;
	for(int j=1; j<i; j++){
		int dist = (vertex[i][0] - vertex[j][0])* (vertex[i][0] - vertex[j][0]) +
			(vertex[i][1] - vertex[j][1])* (vertex[i][1] - vertex[j][1]);
		if(dist <= 4*d*d){
			cap[2*i][2*j-1] = cap[2*j][2*i-1] = INF;
		}
	}	
}
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
			for(int v =1; v<=t; v++){
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
	s = 0;
	while(scanf("%d %d %d %d", &l, &w, &n, &d)){			
		if(l == 0) break;
		t = 2*n+1;
		memset(cap,0,sizeof(cap));
		for(int i=1; i<=n; i++){ 
			scanf("%d %d", &vertex[i][0], &vertex[i][1]);
			BuildGraph(i);		                  
		}     
		printf("Case %d: %d\n", set++, EdmondsKarp());   
	}
	return 0;
}
