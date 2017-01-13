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

#define N 500+5
#define M 1000000+5
#define minInt -2147483648
#define FOR(a,n) for(int i=a; i<n; i++)

using namespace std;

int root[N];
bool visited[N];

struct edge{
       int from, to,len;
       edge(){}
       edge(int a, int b, int c){from = a; to = b; len = c;}
       bool operator <(const edge& e) const{return len>e.len;}
       
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


int main ()
{
    int n,m,maxLen;
    while(cin>>n>>m){
        if(n==0 && m == 0)
                break;
        maxLen= minInt;
        int a,b,c,maxCity;
        maxCity = 0;
        memset(root,-1,sizeof(root));
        FOR(0,m){       
                cin>>a>>b>>c;
				edges[i] = edge(a,b,c);   
				if(maxLen < c)
					maxLen = c;
        }     
        FOR(0,m){
			if(edges[i].len == maxLen){
				int from = edges[i].from;
				int to = edges[i].to;
				if(find(from) != find(to))
					Union(from, to);
			}
		}

		FOR(1,n+1){
			if(maxCity < -root[i])
			maxCity = - root[i];
		}
        cout<<maxCity<<endl;             
    }       
    return 0;
}
