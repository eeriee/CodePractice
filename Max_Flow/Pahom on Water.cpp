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

#define N 305
#define INF 100000000
using namespace std;

int n,s,t;

int aug[2*N];
int pre[2*N];
int cap[2*N][2*N];
int vertex[N][2];
int r[N];
double fre[N];

bool isOverlap(int i, int j){
	int a = vertex[i][0] - vertex[j][0];
	int b = vertex[i][1] - vertex[j][1];
	int c = r[i]+r[j];
	return 	(a*a + b*b - c*c)<=0;
}
void BuildGraph(int i){
	if(fre[i] == 400.0){
		s=2*i;
		cap[s][s+1] =INF;
	}else if(fre[i] == 789.0){
		t=2*i+1;
		cap[t-1][t] = 2;		
	}else{
		cap[2*i][2*i+1]=1;
	}
	for(int j=0; j<i; j++){
		if(isOverlap(i,j)){
			if(fre[i]<fre[j])		
				cap[2*i+1][2*j] = INF;
			else if(fre[j]<fre[i])
				cap[2*j+1][2*i] = INF;
		}
	}	
}
void EdmondsKarp(){
	queue<int> q;
	int f=0;
	int total = 2*n;
	while(true){
		memset(aug, 0, sizeof(aug));
		aug[s] = 1;
		q.push(s);
		while(!q.empty()){
			int u = q.front(); 
			q.pop();
			for(int v =0; v<total; v++){
				if(!aug[v] && cap[u][v]){
					pre[v] = u;
					q.push(v);
					aug[v] = 1;	
				}				
			}	
		}
		if(aug[t] == 0) break;
		int temp = t;
		while(temp!=s){
			--cap[pre[temp]][temp];
			++cap[temp][pre[temp]];
			temp = pre[temp];			
		}
		f += aug[t];
		if(f >= 2) break;
	}
	if(f>=2)
		printf("Game is VALID\n");
	else
		printf("Game is NOT VALID\n");			
}
int main(){
    int set;
    scanf("%d", &set);
    for(int index=0; index<set; index++){
		memset(cap,0,sizeof(cap));
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			scanf("%lf %d %d %d", &fre[i], &vertex[i][0], &vertex[i][1], &r[i]);
			BuildGraph(i);								
		}
		EdmondsKarp(); 	
	}
    return 0;
}
