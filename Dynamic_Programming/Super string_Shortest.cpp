#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>
#include <math.h>
#define FOR(i,n) for(int i=0; i<n; i++)
using namespace std;

int lcs[1001][1001];
int main(){
	int n;
	cin>>n;
	string blank;
	getline(cin,blank);
	for(int i=0; i<n; i++){
		string s1, s2;
		getline(cin,s1);
		getline(cin,s2);
		int len1 = s1.length();
		int len2 = s2.length();
		memset(lcs, 0, sizeof(lcs));

		for(int j=1; j<=len1; j++){
			for(int k=1; k<=len2; k++){
				if(s1[j-1] == s2[k-1])
					lcs[j][k] = lcs[j-1][k-1] + 1;
				else
					lcs[j][k] = (lcs[j-1][k] > lcs[j][k-1])? lcs[j-1][k]:lcs[j][k-1];
			}
		}
		int len = len1 + len2 - lcs[len1][len2];
		cout<<len<<endl;
	}
	return 0;
}
