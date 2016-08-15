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
#include<set>

#define FOR(i,n) for(int i=0; i<n; i++)
#define SCAN(a) scanf("%d", &a);
#define READ(v) FOR(j,c) {SCAN(x); v.push_back(x);}
using namespace std;

int main(){	
	int a;
	SCAN(a);
	FOR(i,a) {
		int n,m,c;
		scanf("%d %d %d", &n, &m, &c);
		vector<int> row;
		vector<int> seat;
		int x;
		READ(row);
		READ(seat);
		set<pair<int,int>> r;
		FOR(j,c) {
			if(seat[j]>1) r.insert(make_pair(row[j],seat[j]));
			if(seat[j]<m) r.insert(make_pair(row[j],seat[j]+1));
		}
		printf("Case #%d: %lld\n", i+1, (long long)n*(m-1)-r.size());
	}
	return 0;
}
