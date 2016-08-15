#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#include <map>
#define FOR(i) for(int i=0; i<4; i++)
#define SETCHILD()  if(!visited[cup[0]][cup[1]][cup[2]][cup[3]]){state child = state(cup[0], cup[1], cup[2], cup[3],s.cnt+1);q.push(child);visited[cup[0]][cup[1]][cup[2]][cup[3]]=true;}
using namespace std;
int capacity[4];
int t;
bool visited[25][25][25][25];

struct state
{	
	int a,b,c,d,cnt;
	state(){}
	state(int c1, int c2, int c3, int c4, int e){ a=c1;b=c2;c=c3;d=c4;cnt=e;}
};

bool isStopState(state& s){
	if(s.a == t || s.b == t || s.c == t|| s.d == t)
		return true;
	return false;
}

int bfs(){
	memset(visited,0,sizeof(visited));
	queue<state> q;
	//map <state, state> parentOf;
	state start = state(0,0,0,0,0);
	q.push(start);
	//parentOf[start] = state(-1,-1,-1,-1);
	int count = -1;
	while(!q.empty()){
		state s = q.front();
		q.pop();
		if(isStopState(s)){
			return s.cnt;
		}
		int cup[4] = {s.a, s.b, s.c, s.d};
		//fill
		FOR(i) if(cup[i] < capacity[i]){
			int temp = cup[i];
			cup[i] = capacity[i];
			SETCHILD();
			cup[i] = temp;
		}
		//empty
		FOR(i) if(cup[i] > 0){
			int temp = cup[i];
			cup[i] = 0;
			SETCHILD();
			cup[i] = temp;
		}

		//pour one to another
		FOR(i) if(cup[i]>0) FOR(j) if(i !=j && cup[j]<capacity[j]){
			int tempi = cup[i];
			int tempj = cup[j];
			if(cup[i] > capacity[j] - cup[j]){
				cup[i] -= capacity[j] - cup[j];
				cup[j] = capacity[j];
			}else{
				cup[j] += cup[i];
				cup[i] = 0;
			}
			SETCHILD();
			cup[i] = tempi;
			cup[j] = tempj;
		}
	}
	return count;
}
int main(){

	int a,b,c,d;
	while(cin>>a>>b>>c>>d>>t){
		capacity[0] = a;
		capacity[1] = b;
		capacity[2] = c;
		capacity[3] = d;
		bool noWay = true;
		FOR(i) if(t<=capacity[i]){
			noWay = false;
			break;
		}
		if(noWay)
			cout<<-1<<endl;
		else
			cout<<bfs()<<endl;			
	}
	return 0;
}
