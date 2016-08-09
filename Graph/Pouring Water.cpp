/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16391
 * Submitted at:  2015-05-08 15:37:48
 *
 * User ID:       94
 * Username:      53064064
 * Problem ID:    169
 * Problem Name:  Pouring Water...again...
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
#include <map>
#define N 151
#define FOR(i) for(int i=0; i<2; i++)
#define SETCHILD(c) if(!visited[cup[0]][cup[1]][c]){state child = state(cup[0], cup[1],c, s.cnt+1); q.push(child);visited[cup[0]][cup[1]][c]=true;}
using namespace std;
int capacity[2], t, cap;
bool visited[N][N][1001];

struct state
{	
	int a,b,c,cnt;
	state(){}
	state(int c1, int c2, int c3, int c4){ a=c1;b=c2;c=c3;cnt=c4;}
};

bool isStopState(state& s){
	if(s.a == t || s.b == t)
		return true;
	return false;
}

int bfs(){
	memset(visited,false,sizeof(visited));
	queue<state> q;
	state start = state(0,0,cap,0);
	q.push(start);
	int count = -1;
	while(!q.empty()){
		state s = q.front();
		int c = s.c;
		q.pop();
		//edit cap
		if(isStopState(s)){
			return s.cnt;
		}
		int cup[2] = {s.a, s.b};
		//fill
		if(c>0){
			FOR(i) if(cup[i] < capacity[i]){
				int temp = cup[i];
				if(c < capacity[i] - cup[i]){
					cup[i] += c;
				}else{
					cup[i] = capacity[i];
				}
				int tempc = c - (cup[i] - temp);
				SETCHILD(tempc);
				cup[i] = temp;
			}
		}
		//empty
		FOR(i) if(cup[i] > 0){
			int temp = cup[i];
			cup[i] = 0;
			SETCHILD(c);
			cup[i] = temp;
		}

		//pour one to another
		if(cup[0]>0 && cup[1]<capacity[1]){
			int tempi = cup[0];
			int tempj = cup[1];
			if(cup[0] > capacity[1] - cup[1]){
				cup[0] -= capacity[1] - cup[1];
				cup[1] = capacity[1];
			}else{
				cup[1] += cup[0];
				cup[0] = 0;
			}
			SETCHILD(c);
			cup[0] = tempi;
			cup[1] = tempj;
		}

		if(cup[1]>0 && cup[0]<capacity[0]){
			int tempi = cup[0];
			int tempj = cup[1];
			if(cup[1] > capacity[0] - cup[0]){
				cup[1] -= capacity[0] - cup[0];
				cup[0] = capacity[0];
			}else{
				cup[0] += cup[1];
				cup[1] = 0;
			}
			SETCHILD(c);
			cup[0] = tempi;
			cup[1] = tempj;
		}
	}
	return count;
}
int main(){

	int a,b;
	while(scanf("%d %d %d %d", &a,&b,&t,&cap) != EOF){
		capacity[0] = a;
		capacity[1] = b;
		bool noWay = true;
		FOR(i) if(t<=capacity[i]){
			noWay = false;
			break;
		}
		if(noWay)
			printf("%d\n", -1);
		else
			printf("%d\n", bfs());			
	}
	return 0;
}
