#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#include <math.h>

using namespace std;

struct monster
{	
	int i, cost, min, max;
	monster(int a, int b, int c, int d){ i = a; cost = b; min = c; max = d;}
	bool operator < (const monster& m)const{ return m.cost<cost;}
};
int main(){
	int m,n;
	while(scanf("%d %d",&m,&n) != EOF){
		int level[100];
		int price[100];
		//bool done[100];
		//memset(done, 0, sizeof(done));
		vector<vector<monster>> adj(n+1);
		priority_queue<monster> q;

		for(int i=0; i<n; i++){
			int a,b,c;
			scanf("%d %d %d", &a,&b,&c);
			price[i]=a;
			level[i]=b;
			q.push(monster(i,a,b,b));
			for(int j=0; j<c; j++){
				int x,y;
				scanf("%d %d", &x, &y);
				adj[x-1].push_back(monster(i,y,0,0));
			}
		}
		
		while(!q.empty()){
			monster u = q.top();
			q.pop();
			int iu = u.i;

			if(iu == 0){
				printf("%d\n",u.cost);
				break;
			}

			for(int j=0; j<adj[iu].size(); j++){
				monster v = adj[iu][j];
				int iv = v.i;
				int lv = level[iv];
				int min=std::min(lv,u.min);
				int max=std::max(lv,u.max);
				if(max - min <=m && price[iv]>u.cost+v.cost){
					//price[iv] = u.cost+v.cost;
					q.push(monster(iv,u.cost+v.cost,min, max));
				}
			}

		}
	}

	return 0;
}
