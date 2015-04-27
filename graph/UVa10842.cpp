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

using namespace std;
int root[N];

struct edge{
       int from, to, len;
       edge(){}
       edge(int a, int b, int c){from = a; to = b; len =c;}
       bool operator <(const edge& e) const{return len>e.len;}
       
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
    int set,n,m,u,v,c,e, min;
    scanf("%d", &set);
    for(int i=0; i<set; i++){
        memset(root,-1,sizeof(root));
        e = 0;
        min=0;
        scanf("%d %d", &n,&m);
        for(int j=0; j<m; j++){
           scanf("%d %d %d", &u,&v,&c);
              edges[e++] = edge(u,v,c);                                           
        }
        sort(edges, edges+e);
        for(int j=0; j<e; j++){
            int ui = edges[j].from;
            int vi = edges[j].to;
            if(find(ui) != find(vi)){
                      Union(ui,vi);                           
            }
            if(root[find(ui)] == -n && edges[j].len > min ) 
                min = edges[j].len;
        }
        printf("Case #%d: %d\n", i+1, min);
    }

    return 0;
}
