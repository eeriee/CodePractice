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
#define N 1005

using namespace std;

char s[N], pattern[N];
int sa[N], t1[N], t2[N], c[N], Rank[N], Height[N], sn, pn;

void build_sa(int m){
	int i, *x = t1, *y = t2;
	for(i=0; i<m; i++) c[i]=0;
	for(i=0; i<sn; i++) c[x[i]=s[i]]++;		
	for(i=1; i<m; i++) c[i]+=c[i-1];	
	for(i=sn-1; i>=0; i--) sa[--c[x[i]]] = i;

	for(int k=1; k<sn; k<<=1){
		int p=0;
		for(i=sn-k; i<sn; i++) y[p++]=i;
		for(i=0;i<sn;i++) if(sa[i]>=k) y[p++]=sa[i]-k;

		for(i=0; i<m; i++) c[i]=0;
		for(i=0; i<sn; i++) c[x[y[i]]]++;		
		for(i=1; i<m; i++) c[i]+=c[i-1];	
		for(i=sn-1; i>=0; i--) sa[--c[x[y[i]]]] = y[i];

		swap(x,y);
		p=1; x[sa[0]]=0;
		for(i=1;i<sn;i++)
			x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
		if(p>=sn) break;
		m=p;
	}
}
int cmp(int p){
	return strncmp(pattern, s+sa[p], pn);	
}
int find(){
	int l=1, r=sn,m,MIN;
	while(l<r){
		m=(l+r)/2;
		if(cmp(m)>0) l=m+1;
		else r=m;
	}
	MIN=l;r=sn;
	while(l<r){
		m = (l+r)/2;
		if (cmp(m)<0) r = m;
		else l = m+1;
	}
	return r-MIN;
}
void getHeight(){
	int i, j, k=0;
	for(i=0; i<sn; i++) Rank[sa[i]]=i;
	for(i=0; i<sn; i++){
		if(k) k--;
		int j=sa[Rank[i]-1];
		while(s[i+k] == s[j+k]) k++;
		Height[Rank[i]]=k;
	}
}
int main(){
	int n, idx;
	scanf("%d",&n);
	while (n--){	
		pn=0;
		pattern[0]=0;
		scanf("%s",s);
		sn=strlen(s)+1;
		build_sa('T'+1);
		getHeight();
		for(int i=0; i<sn; i++){
			if(Height[i]>pn){
				pn=Height[i];
				idx=i;
			}			
		}
		if(pn>0){
			strncpy(pattern, s+sa[idx], pn);
			pattern[pn]=0;
			printf("%s %d\n",pattern,find());
		}else
			printf("No repetitions found!\n");
	}
	return 0;
}
