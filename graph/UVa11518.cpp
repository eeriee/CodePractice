#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<vector>

using namespace std;
vector <int> adj[10001];
bool v[10001];

void fall(int a, int& count) {
	v[a] = true;
	++count;
	for(int i=0; i<adj[a].size(); i++){
		int b = adj[a][i];
		if(!v[b])
			fall(b, count); 
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,m,l;
		cin>>n>>m>>l;
		memset(adj, 0, sizeof(adj));

		for(int j=0; j<m; j++){
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
		}

		memset(v, 0, sizeof(v));

		int count = 0;
		for(int j=0; j<l;j++){
			int z;
			cin>>z;
			if(!v[z])
				fall(z, count);
		}
		cout<<count<<endl;
	}
	return 0;
}
