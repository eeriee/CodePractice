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
	int coins[5] = {1,5,10,25,50};
	long cents[7500];
	memset(cents, 0, sizeof(cents));
	cents[0]=1;
	int coin;

	for(int i=0; i<5; i++){
		coin = coins[i];
		for(int j=0; j+coin<7500;j++)			
			cents[j+coin]+=cents[j];
	}

	int n;	
	while(scanf("%d", &n)!=EOF)	
		printf("%d\n", cents[n]);

	return 0;
}
