/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 16580
 * Submitted at:  2015-05-09 08:57:09
 *
 * User ID:       94
 * Username:      53064064
 * Problem ID:    218
 * Problem Name:  SuperSale (UVa 10130)
 */

#include<iostream>
#include<math.h>
#include<queue>
#include<stack>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<string.h>
#include<sstream>

using namespace std;


int main(){
	int t,n,p[1000+5],w[1000+5],mw[30+5],g,wgt,value,maxw; 

	scanf("%d", &t);
	for(int index=0; index<t; index++){
		scanf("%d", &n);	
		for(int i=0; i<n; i++){
			cin>>p[i]>>w[i];
		}
		memset(mw, 0, sizeof(mw));

		for(int i=0; i<n; i++){
			wgt = w[i];
			for(int j=30-wgt; j>=0; j--)
				if(mw[j+wgt]<mw[j]+p[i])
					mw[j+wgt]=mw[j]+p[i];
		}
		scanf("%d", &g);
		value = 0;

		for(int i=0; i<g; i++){
			scanf("%d", &maxw);
			value+= mw[maxw];
		}

		printf("%d\n",value);
	}

	return 0;
}
