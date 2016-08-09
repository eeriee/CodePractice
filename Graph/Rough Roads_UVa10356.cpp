#include<iostream>
#include<queue>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#define N 1000000
using namespace std;

struct  node
{
	int i, dist;
	bool cycle;
	node(int a, int b,int c){
		i = a;
		dist = b;
		cycle = c;
	}

	bool operator < (const node& n)const
    {
		return n.dist<dist;
    }
};
int main(){
	int n,r;
	int set = 0;
	while(cin>>n>>r){
		set++;
		int dist[500][2];
		bool done[500][2];
		int len[500][500];
		memset(len, 0, sizeof(len));
		vector<vector<int>> adj(n);

		for(int i=0; i<n; i++){
			for(int j=0; j<2; j++){
				dist[i][j] = N;
				done[i][j] = false;
			}
		}
		dist[0][0] = 0;
		//done[500][0] = true;
		for(int i=0; i<r; i++){
			int a,b,c;
			cin>>a>>b>>c;
			adj[a].push_back(b);
			adj[b].push_back(a);
			len[a][b] = len[b][a] = c;
		}
		cout<<"Set #"<<set<<endl;
		priority_queue<node> q;
		q.push(node(0,0,0));
		bool flag = false;
		while(!q.empty()) {
			node u = q.top();
			q.pop();
			int i = u.i;
			bool c = u.cycle;
			if(i == n-1 && c == false){
				cout<<dist[n-1][0]<<endl;
				flag = true;
				break;
			}
			done[i][c] = true;
			for(int j=0; j<adj[i].size(); j++){
				int v = adj[i][j];
				if(!done[v][!c] && dist[v][!c]> dist[i][c] + len[i][v]){
					dist[v][!c] = dist[i][c] + len[i][v];
					q.push(node(v, dist[v][!c], !c));
				}
			}
		}
		if(!flag)
			cout<<'?'<<endl;
	}
	return 0;
}
