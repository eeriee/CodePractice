/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16595
 * Submitted at:  2015-05-09 11:49:57
 *
 * User ID:       94
 * Username:      53064064
 * Problem ID:    178
 * Problem Name:  The Problem with the Problem Setter(Easy ver.)
 */

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

#define maxn 1025
#define INF 2000

using namespace std;


struct Edge{
	int from, to, cap, flow;
	Edge(int a, int b, int c, int d){from=a; to=b; cap=c; flow=d;}
};
int n,m,s,t; //no. of nodes/edge/start/des
vector<Edge> edges;
vector<int> G[maxn]; //G[i][j]->the idx of the j-th edge of node i in edges
bool vis[maxn]; //for bfs
int d[maxn]; //dist of s to i
int cur[maxn]; //cur edge
void AddEdge(int from, int to, int cap) {
	edges.push_back(Edge(from,to,cap,0));
	edges.push_back(Edge(to,from,0,0));
	m=edges.size();
	G[from].push_back(m-2);
	G[to].push_back(m-1);
}
void init(){
	edges.clear();
	for(int i=0; i<n; i++) G[i].clear();
	memset(d,0,sizeof(d));
	memset(cur,-1,sizeof(cur));
}
bool BFS(){
	memset(vis,0,sizeof(vis));
	queue<int> q;
	q.push(s);
	d[s]=0;
	vis[s]=1;
	while(!q.empty()){
		int x=q.front(); 
		q.pop();
		for(int i=0; i<G[x].size(); i++){
			Edge& e=edges[G[x][i]];
			if(!vis[e.to] &&e.cap>e.flow){//only consider edge in residual network
				vis[e.to]=1;
				d[e.to]=d[x]+1;
				q.push(e.to);
			}
		}
	}
	return vis[t];
}
int DFS(int x, int a){
	if(x==t||a==0) return a;
	int flow=0,f;
	for(int& i=cur[x]; i<G[x].size(); i++) {//from last considered edge
		Edge& e = edges[G[x][i]];
		if(d[x]+1==d[e.to] && (f=DFS(e.to, min(a, e.cap-e.flow)))>0){
			e.flow+=f;
			edges[G[x][i]^1].flow=-f;
			flow+=f;
			a-=f;
			if(a==0) break;
		}
	}
	return flow;
}
int maxflow(){
	int flow =0;
	while(BFS()){
		memset(cur,0,sizeof(cur));
		flow+=DFS(s,INF);
	}
	return flow;
}
int main(){
	int total,nk,np,len,x,y;
	while(scanf("%d %d", &nk, &np)){
		if(nk == 0 && np==0) break;
		init();
		s=0;
		t=nk+np+1;
		n=t+1;
		total = 0;
		for(int i=1; i<=nk; i++){
			scanf("%d", &len);
			AddEdge(np+i,t,len);
			total += len;
		}		  
		for(int i=1; i<=np; i++){ 
			AddEdge(0,i,1);
			scanf("%d", &x);
			for(int j=1; j<=x; j++){
				scanf("%d", &y);
				AddEdge(i,np+y,1);
			}
		}     
		if(total-maxflow())
			puts("0");
		else
			puts("1");
	}
	return 0;
}
