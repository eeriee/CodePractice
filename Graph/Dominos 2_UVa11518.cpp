#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<vector>

using namespace std;
vector <int> adj[10001];
bool v[10001];

void fall(int a, int& count) {
	v[a] = true;
	++count;
	for(int i=0; i<adj[a].size(); i++){
		int b = adj[a][i];
		if(!v[b])
			fall(b, count); 
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,m,l;
		cin>>n>>m>>l;
		memset(adj, 0, sizeof(adj));

		for(int j=0; j<m; j++){
			int a,b;
			cin>>a>>b;
			adj[a].push_back(b);
		}

		memset(v, 0, sizeof(v));

		int count = 0;
		for(int j=0; j<l;j++){
			int z;
			cin>>z;
			if(!v[z])
				fall(z, count);
		}
		cout<<count<<endl;
	}
	return 0;
}
/*
Question:
Dominos are lots of fun. Children like to stand the tiles on their side in long lines.
When one domino falls, it knocks down the next one, which knocks down the one
after that, all the way down the line. However, sometimes a domino fails to knock the
next one down. In that case, we have to knock it down by hand to get the dominos
falling again.
Given a set of dominos that are knocked down by hand, your task is to determine the
total number of dominos that fall.
Input Specification
The first line of input contains one integer specifying the number of test cases to
follow. Each test case begins with a line containing three integers n, m, l no larger
than 10 000, followed by m+l additional lines. The first integer n is the number of
domino tiles. The domino tiles are numbered from 1 to n. Each of the m lines after the
first line contains two integers x and y indicating that if domino number x falls, it will
cause domino number y to fall as well. Each of the following l lines contains a single
integer z indicating that the domino numbered z is knocked over by hand.
Sample Input
1
3 2 1
1 2
2 3
2
Output Specification
For each test case, output a line containing one integer, the total number of dominos
that fall over.
Output for Sample Input
2 
*/
