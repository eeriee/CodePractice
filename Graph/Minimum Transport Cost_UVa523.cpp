#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#define N 10000
#define infinity 100000000
using namespace std;

struct node
{	
	int i, cost;
	node(int a, int b){ i = a; cost = b;}
	bool operator < (const node& n)const{ return n.cost<cost;}
};
int main(){
	int m;
	cin>>m;
	string blank;
	getline(cin,blank);
	bool flag = true;
	for(int index=0; index<m; index++){		
		string s;
		stringstream ss;
		
		getline(cin,blank);
		getline(cin,s);
		ss << s;
		string c;
		int n = 0;
		int temp[N];
		while(ss>>c){
			++n;
			int cost = stoi(c);
			temp[n] = cost;
			
		}
		vector<vector<node>> adj(n+1);
		for(int i=1; i<=n; i++){
			int cost = temp[i];
			if(cost!=0 && cost!=-1){
				adj[1].push_back(node(i,cost));
			}
		}
		for(int j=2; j<=n; j++){
			for(int k=1; k<=n; k++){
				int cost;
				cin>>cost;
				if(cost!=0 &&cost!=-1)
					adj[j].push_back(node(k,cost));
			}
		}
		
		int tax[N];
		for(int i=1; i<=n; i++){
			cin>>tax[i];
		}

		int start, end;
		
		while(cin>>start>>end){
			if(!flag)
				cout<<endl;
			else
				flag = false;

			priority_queue<node> q;
			q.push(node(start,0));
			int prev[N];
			int cost[N];
			bool done[N];			
			
			for(int i=1;i<=n;i++){
				cost[i]=infinity;
			}
			cost[start] = 0;
			memset(prev, -1, sizeof(prev));
			memset(done, 0, sizeof(done));
			while(!q.empty()){
				node u = q.top();
				q.pop();
				int i = u.i;
				if(i == end){
					cout<<"From "<<start<<" to "<<end<<" :"<<endl;
					cout<<"Path: "<<start;
					stack<int> path;
					int temp = end;
					while(temp != start){
						path.push(temp);
						temp = prev[temp];
					}
					while(!path.empty()){
						cout<<"-->"<<path.top();
						path.pop();
					}
					cout<<endl;
					cout<<"Total cost : "<<cost[i]<<endl;
					break;
				}
				done[i] = true;
				for(int j=0;j<adj[i].size();j++){
					node v = adj[i][j];
					int iv = v.i;
					if(!done[iv]){
						if(iv == end){
							if(cost[iv] > cost[i] + v.cost){
								cost[iv] = cost[i] + v.cost;
								q.push(node(iv,cost[iv]));
								prev[iv] = i;
							}
						}else if(cost[iv] > cost[i] + v.cost + tax[iv]){
							cost[iv] = cost[i] + v.cost + tax[iv];
							q.push(node(iv,cost[iv]));
							prev[iv] = i;
						}
						
					}
				}
			}
			char c1 = cin.get();
			char c2 = cin.peek();
			if (c2 == '\n')
				break;
		}
	}
	return 0;
}
