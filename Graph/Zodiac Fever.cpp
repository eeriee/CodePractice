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
#define FOR(a) for(int i=0; i<a; i++)

using namespace std;


struct trap{	
	char type;
	int move;
	trap(char a, int b){type = a; move = b;}

};

struct room{
	int i, cost;
	room(int a, int b){i=a; cost=b;}
	bool operator < (const room &r)const{
		if (i != r.i) return i<r.i;
		return cost<r.cost;
	}
};

struct node{
	int i, cost, pos;
	node(int a, int b, int c){i=a; cost=b; pos=c;}
	bool operator < (const node &n)const{
		return n.cost<cost;
	}
};
int nr, nc, nt, entrance, ipos, treasure, pos;

int main(){

	while(cin>>nr>>nc>>nt>>entrance>>ipos>>treasure>>pos){
		bool solu = false;
		vector<vector<room>> rooms(nr+1);
		vector<vector<trap>> traps(nr+1);
		FOR(nc){
			int a,b,c;
			cin>>a>>b>>c;
			rooms[a].push_back(room(b,c));
			rooms[b].push_back(room(a,c));
		}
		FOR(nt){
			int a,b;
			char c;
			cin>>a>>c>>b;
			traps[a].push_back(trap(c,b));
		}
		priority_queue<node> q;
		q.push(node(entrance,0,ipos));
		map<room, int> visited;
		while(!q.empty()){
			node u = q.top();
			q.pop();
			int iu = u.i;
			int upos = u.pos;
			if(iu == treasure &&  upos == pos){
				solu = true;
				cout<<u.cost<<endl;
				break;
			}
			FOR(rooms[iu].size()){
				room v = rooms[iu][i];
				int iv = v.i;
				int vpos = upos;
				if(traps[iv].size() != 0){
					trap trv = traps[iv][0];
					char c = trv.type;
					int m = trv.move;

					switch (c)
					{
					case '+':
						vpos += m;
						break;
					case '-':
						vpos -= m;
						break;
					case '*':
						vpos *= m;
						break;
					case '=':
						vpos = m;
						break;
					default:
						break;
					}
					if(vpos > 12)
						vpos %= 12;
					while(vpos<=0){
						vpos += 12;
					}
				}
				room r = room(iv,vpos);
				if(visited.find(r) == visited.end()){
					q.push(node(iv,u.cost + v.cost, vpos));
					visited[r] = u.cost + v.cost;
				}else if(u.cost + v.cost<visited[r]){
					q.push(node(iv,u.cost + v.cost, vpos));
					visited[r] = u.cost + v.cost;
				}
			}
		}
		if(!solu)
			cout<<"Pray!"<<endl;
	}
	return 0;
}
