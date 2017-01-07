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
#include<iomanip>

#define N 505

using namespace std;
int root[N];
int key[N];
int cost[N];

struct edge{
	int from, to,len;
	edge(){}
	edge(int a, int b,int c){from = a; to = b; len =c;}
	bool operator <(const edge& e) const{return len<e.len;}

} edges[N*N];

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

int getRolls(int a, int b){
	return min(a-b,10+b-a);
}

int getTotalRolls(int a, int b){
	int x,y;
	int total = 0;
	for(int i=0; i<4; i++){
		x = a%10;
		y = b%10;
		if(x > y)
			total += getRolls(x,y);
		else
			total += getRolls(y,x);
		a = a/10;
		b = b/10;
	}
	return total;
}


int main(){
	int t,n;
	scanf("%d", &t);
	for(int i=0; i<t; i++){
		scanf("%d", &n);
		memset(root, -1, sizeof(root));
		memset(cost, 0, sizeof(cost));
		memset(key, 0, sizeof(key));
		for(int j=0; j<n; j++){
			cin>>key[j];
		}	
		int e = 0;
		int min = 40;
		for(int j=0; j<n; j++){
			int temp = getTotalRolls(key[j],0);
			if(min>temp)
				min = temp;
		}
		for(int j=0; j<n; j++){                        
			for(int k=j+1; k<n; k++){
				int len = getTotalRolls(key[j], key[k]);
				edges[e++] = edge(j,k,len);                               
			}
		}  
		if(!e){
			printf("%d\n", min);
			continue;
		}
		sort(edges, edges+e); 
		int from,to,r;
		for(int j=0; j<e; j++){
			from = edges[j].from;
			to = edges[j].to;
			if(find(from) != find(to)){
				Union(from,to,edges[j].len);
				r = find(from);
				if(root[r] == -n){
					printf("%d\n",cost[r] + min);
					break;
				}
			}                                             
		}   

	}
	return 0;
}
