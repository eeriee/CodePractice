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

#define N 205

using namespace std;
int root[N];

struct node{
      int x,y;  
      node(){}
      node(int a, int b){x=a;y=b;}      
} nodes[N];

double dist(node a, node b){
       int x = a.x - b.x;
       int y = a.y - b.y;
       return sqrt(x*x+y*y);       
}

struct edge{
       int from, to;
       double len;
       edge(){}
       edge(int a, int b){from = a; to = b; len =dist(nodes[a],nodes[b]);}
       bool operator <(const edge& e) const{return len<e.len;}
       
} edges[N*N];

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

int main(){
    int n;
    int sce = 1;
    while(scanf("%d", &n)){
                  if(n==0)
                  break;
                  memset(root, -1, sizeof(root));
                  int x,y;
                  int e = 0;
                  for(int i=0; i<n; i++){
                        cin>>x>>y;                          
                        nodes[i] = node(x,y);
                        for(int j=0; j<i; j++){
                                edges[e++] = edge(i,j);                               
                        }
                  }  
                  sort(edges, edges+e); 
                  int from,to;
                  for(int i=0; i<e; i++){
                     from = edges[i].from;
                     to = edges[i].to;
                     if(find(from) != find(to))
                          Union(from,to);
                    if(find(0)==find(1)){
                      printf("Scenario #%d\nFrog Distance = %.3lf\n\n", sce++,edges[i].len);                    
                      break;                                                   
                    }                                             
                  }   
    }
    return 0;
}
