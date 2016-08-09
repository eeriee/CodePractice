#include<iostream>
#include <stdio.h>
#include <string.h>
#define N 300
using namespace std;

void DFS(int v, int a, int b, int c, int n, int& count, bool* visited){
	count++;
	visited[v] = true;
	int w = (a*v*v + b*v +c)%n;
	if(!visited[w]){
		DFS(w,a,b,c,n,count,visited);
	}
}
int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int a,b,c,n;
		cin>>a>>b>>c>>n;		
		int max = 0;
		bool visited[300];
		for(int i=0; i<n; i++){
			int count= 0;
			memset(visited, 0, sizeof(bool) * N);
			DFS(i,a,b,c,n,count,visited);
			if(max<count)
				max = count;
		}		
		cout<<max<<endl;
	}
	return 0;
}
/*
Question
Scrooge McDuck has a new plan how to increase his wealth. He found ancient ruins with an extraordinary maze. This maze consists of n chambers. The chambers are numbered 0 through n− 1. Each chamber contains exactly one gem. Chambers are connected by one-way tunnels. Each chamber has exactly two outgoing tunnels: one leads to the chamber with number (a ⋅ v2 + b ⋅ v + c) modn, the other will bring you out of the maze.

You can enter the maze at any location, move along the tunnels and collect the gems. But once you leave the maze, you’ll trigger a self-destruct mechanism – the ceiling of the maze will collapse and all the gems that you did not collect will be lost forever.

Scrooge wants to know the maximum number of gems he can take from the maze.

Input speciﬁcation

The ﬁrst line of the input ﬁle contains an integer t specifying the number of test cases. Each test case is preceded by a blank line.

Each test case consist of a single line containing four integers a, b, c, and n – the numbers that describe one particular maze.

In the easy data set n ≤ 300. In the hard data set n ≤ 224.

Output speciﬁcation

For each test case, output a single line containing a single integer – the maximum number of gems that can be taken from the maze.

Example

input
3

1 2 0 64

0 2 1 47

0 3 5 128
output
5
23
64
The starting chamber matters. For instance, assume that in the ﬁrst example test case Scrooge starts in the chamber 0. His only two options are a tunnel that leads back to chamber 0 and a tunnel that leads outside – not much of a choice. A much better strategy is to start in the chamber 2 and follow the path 2 → 8 → 16 → 32 → 0 → outside.
*/
