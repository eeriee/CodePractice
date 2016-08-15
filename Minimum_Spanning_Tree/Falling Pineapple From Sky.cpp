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

#define N 1005
#define M 25005

using namespace std;
int root[N];
long long cost[N];
struct edge{
	int from, to, len;
	edge(){}
	edge(int a, int b, int c){from = a; to = b; len =c;}
	bool operator <(const edge& e) const{return len<e.len;}

} edges[M];

int find (int a)  {	
	if (root[a] < 0)		
		return a;	
	else		
		return root[a] = find(root[a]);
}
void UnionSet (int set1, int set2, int c) {
	root[set1] += root[set2]; 
	cost[set1] += cost[set2] + c;
	root[set2] = set1;     
}
void Union (int a, int b, int c) {
	int root1=find(a);
	int root2=find(b);
	if  (root[root1] < root[root2]) 
		UnionSet(root1, root2, c);	
	else		
		UnionSet(root2, root1, c);
}

int main(){
	int n,m,u,v,c,e,r,point;
	bool noway;
	while(scanf("%d %d", &n, &m)){
		if(n==0 && m==0)
			break;
		memset(root,-1,sizeof(root));
		memset(cost,0,sizeof(cost));
		noway = true;
		e = 0;
		for(int j=0; j<m; j++){
			scanf("%d %d %d", &u,&v,&c);
			edges[e++] = edge(u,v,c);                                           
		}
		sort(edges, edges+e);
		queue<int> unuse;
		for(int j=0; j<e; j++){
			int ui = edges[j].from;
			int vi = edges[j].to;
			int len = edges[j].len;
			if(find(ui) != find(vi)){
				Union(ui,vi,len); 
				r = find(ui);
				if(root[r] == -n){
					point = j;
					noway = false;
					break;
				}
			}else{
				unuse.push(len);
			}
		}
		if(noway)
			printf("\\(^o^)/ pray to god\n");
		else{
			printf("Min cost: %d\n", cost[r]);
			while(!unuse.empty()){
				printf("%d ", unuse.front());
				unuse.pop();
			}
			if(point+1<e)
				printf("%d", edges[point+1].len);
			for(int j=point+2; j<e; j++){
					printf(" %d", edges[j].len);
			}
			printf("\n");
		}

	}
	return 0;
}
