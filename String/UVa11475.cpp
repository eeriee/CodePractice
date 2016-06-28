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

using namespace std;

string s;
int nxt[100005];
void kmp(int n){
	int i = 0,j = -1;
	nxt[0]=-1;
	while(i<n)
		if(j == -1 || s[n-1-i] == s[n-1-j]) nxt[++i] = ++j;
		else j = nxt[j];
}

int go_match(int n){
	int i = 0,j = 0;
	while(i < n && j < n)
		if(j == -1 || s[i] == s[n-1-j]){i++; j++;}
		else j = nxt[j];

	return j;
}

int main(){
	int len;	
	while(getline(cin,s)){
		len = s.length();
		kmp(len);
		int cur = go_match(len);
		cout<<s;
		for(int k=len-cur-1; k>=0; k--){
			cout<<s[k];
		}
		cout<<endl;

	}
	return 0;
}
