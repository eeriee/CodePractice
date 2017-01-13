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

#define N 105
#define M 5000
#define INF 10005

using namespace std;
int n,m,u,v,c,r;
int root[N];
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
void UnionSet (int set1, int set2) {
	root[set1] += root[set2]; 
	root[set2] = set1;     
}
void Union (int a, int b) {
	int root1=find(a);
	int root2=find(b);
	if  (root[root1] < root[root2]) 
		UnionSet(root1, root2);	
	else		
		UnionSet(root2, root1);
}
int kruskal(int i){
	memset(root,-1,sizeof(root));
	int min = INF;
	int max = 0;
	for(int j=i; j<m; j++){
		int ui = edges[j].from;
		int vi = edges[j].to;
		int len = edges[j].len;
		if(find(ui) != find(vi)){
			Union(ui,vi); 
			if(len < min)
				min = len;
			if(len > max)
				max = len;
			r = find(ui);
			if(root[r] == -n){
				return max - min;
			}
		}
	}		
	return -1;
}
int main(){

	while(scanf("%d %d", &n, &m)){
		if(n==0 && m==0)
			break;
		for(int i=0; i<m; i++){
			scanf("%d %d %d", &u,&v,&c);
			edges[i] = edge(u,v,c);                                           
		}
		sort(edges, edges+m);
		int answer = -1;
		int temp;
		for(int i=0; i<m; i++){
			temp = kruskal(i);
			if(temp>=0){
				if(answer==-1)
					answer = INF;
				answer =  min(temp,answer);
			}
		}
		printf("%d\n", answer);

	}
	return 0;
}
