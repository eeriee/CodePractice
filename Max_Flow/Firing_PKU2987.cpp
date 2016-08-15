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

#define N 5005
#define INF 0x7FFFFFFF

using namespace std;

int n,m,em,s,t;
long long profit;
long long aug[N];
int pre[N];
long long cap[N][N];
bool visited[N];
vector<vector<int>> graph;

long long EdmondsKarp(){
	queue<int> q;
	int f=0;
	while(true){
		memset(aug, 0, sizeof(aug));
		aug[s] = INF;
		q.push(s);
		while(!q.empty()){
			int u = q.front(); 
			q.pop();
			for(int i=0; i<graph[u].size(); i++){
				int v=graph[u][i];
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
			visited[temp] = 1;
			temp = pre[temp];			
		}
		f += aug[t];
	}

	return profit-f;	
}
void dfs(int u){	
	aug[u] = 1;
	for(int i=0; i<graph[u].size(); i++){
		int v=graph[u][i];
		if(!aug[v] && cap[u][v]){
			++em;
			dfs(v);
		}		
	}	
}
int main(){
	s=0;
	scanf("%d %d", &n, &m);	
	t=n+1;
	memset(cap,0,sizeof(cap));
	memset(visited,0,sizeof(visited));
	graph.assign(n+5, vector<int>());
	profit = 0;
	em=0;
	int x,a,b;
	for(int i=1; i<=n; i++){ 
		scanf("%d", &x);	
		if(x>=0){
			cap[0][i] = x;
			graph[0].push_back(i);
			graph[i].push_back(0);
			profit+=x;
		}else{
			cap[i][n+1] = -x;  
			graph[t].push_back(i);
			graph[i].push_back(t);
		}
	}  
	for(int i=0; i<m; i++){
		scanf("%d %d", &a, &b);
		cap[a][b]=INF;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}   
	profit = EdmondsKarp(); 
	memset(aug,0,sizeof(aug));  
	dfs(s);
	printf("%d %d\n", em, profit);

	return 0;
}
