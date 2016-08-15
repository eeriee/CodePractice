#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#include<set>
#include<map>
#define FOR(i,a,n) for(int i=a; i<n; i++)
#define infinity 10000000

using namespace std;
struct city{
	int n, dis;
	city(int a, int b){n=a; dis=b;}
	bool operator < (const city &c) const{
		if(c.dis<dis)
			return true;
		else
			return c.n<n;
	}
};
int main(){
	int n,m;
	while(cin>>n>>m){
		int dis[102][102];
		//int path[101][101];
		FOR(i,1,n+1) FOR(j,1,n+1){
			if(i==j)
				dis[i][j] = 0;
			else
				dis[i][j] = infinity;
			//path[i][j] = -1;
		}
		int u,v,w;
		FOR(i,0,m){			
			cin>>u>>v>>w;
			dis[u][v] = dis[v][u]=w;
		}
		FOR(k,1,n+1) FOR(i,1,n+1) FOR(j,1,n+1){
			if(dis[i][j]>dis[i][k] + dis[k][j])
				dis[i][j] = dis[i][k] + dis[k][j];
		}
		priority_queue<city> q;
		FOR(i,1,n+1){
			int total = 0;
			FOR(j,1,n+1){
				total += dis[i][j];
			}
			q.push(city(i,total));
		}
		cout<<q.top().n<<endl;
	}
	return 0;
}
