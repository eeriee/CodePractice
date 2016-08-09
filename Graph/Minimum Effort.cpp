#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>

#define infinity 100000000
using namespace std;

struct node
{	
	int i, cost;
	node(int a, int b){ i = a; cost = b;}
	bool operator < (const node& n)const{ return n.cost<cost;}
};
vector<vector<node>> adj;
vector<stack<int>> path(2);
int  n;
string place[200];

int findPlace(string s){
	for(int i=0; i<n; i++){
		if(place[i].compare(s) == 0){
			return i;
		}
	}
	return -1;
}

void dijkstra(int a, int b, int c, int &d){
	priority_queue<node> q;
	int cost[200];
	int pre[200];
	bool done[200];	
	for(int i=0;i<n;i++){
		cost[i]=infinity;
		pre[i] = -1;
		done[i] = false;
	}
	cost[a] = 0;
	q.push(node(a,0));
	while(!q.empty()){
		node u = q.top();
		int iu = u.i;
		q.pop();
		if(iu == b){
			int temp = b;
			d += cost[iu];
			while(pre[temp] != -1){
				path[c].push(temp);
				temp = pre[temp];
			}
			break;
		}
		done[iu] = true;
		for(int i=0; i<adj[iu].size(); i++){
			node v = adj[iu][i];
			int iv = v.i;
			if(!done[iv] && cost[iv] > u.cost + v.cost){
				
				cost[iv] = u.cost + v.cost;
				q.push(node(iv,cost[iv]));
				pre[iv] = iu;
			}
		}
	}
}

int main(){
	while(cin>>n){
		adj.assign(n,vector<node>());
		string blank;
		getline(cin,blank);		
		int office, hall;
		for(int i=0; i<n; i++){
			string s;
			getline(cin,s);
			place[i] = s;
			if(s.compare("office") == 0)
				office = i;
			else if (s.compare("hall") == 0)
				hall = i;
		}
		int p;
		cin>>p;
		getline(cin,blank);
		for(int i=0; i<p; i++){
			string s;
			getline(cin, s);
			int pos;
			for(int j=0;j<s.length();j++){
				if(s[j] == ':'){
					pos = j;
					break;
				}
			}
			string place1, place2;
			int no1, no2;
			no1 = no2 = -1;
			place1 = s.substr(0,pos);
			no1 = findPlace(place1);
			int cost[2] = {0,0};
			int temp[2] = {-1,-1};
			int times =0;
			for(int j=s.length()-1; j>pos; j--){
				if(s[j] == ' '){
					temp[times++] = j;
					if(times >= 2) break;
				}
			}
			string temp1 = s.substr(temp[0]+1);
			cost[0] = stoi(temp1);

			place2 = s.substr(pos+1, temp[0]-pos-1);
			no2 = findPlace(place2);

			if(temp[1] != -1){
				string temp2 = s.substr(temp[1]+1, temp[0]-temp[1]-1);
				bool digit = true;
				for(int j=0; j<temp2.length(); j++){
					if(temp2[j]<'0' || temp2[j]>'9'){
						digit = false;
						break;
					}
				}
				if(digit) {					
					string tempplace2 = s.substr(pos+1, temp[1]-pos-1);
					int tempno2 = findPlace(tempplace2);
					if(tempno2 != -1){
						cost[1] = stoi(temp2);
						place2 = tempplace2;
						no2 = tempno2;
					}
				}
			}
			if(cost[1]){
				adj[no1].push_back(node(no2,cost[1]));
				adj[no2].push_back(node(no1,cost[0]));
			}else{
				adj[no1].push_back(node(no2,cost[0]));
			}
		}


		int count = 0;

		dijkstra(office, hall, 0, count);
		dijkstra(hall, office, 1, count);		
		cout<<count<<endl;
		cout<<"office";
		for(int i=0; i<2; i++){
			while(!path[i].empty()){
				cout<<" -> "<<place[path[i].top()];
				path[i].pop();
			}
		}
		cout<<endl<<endl;

	}
	return 0;
}
