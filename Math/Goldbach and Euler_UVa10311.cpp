#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<set>
#include<math.h>
#include<vector>

#define MAX 100000000
#define N 10000
#define SCAN(a) scanf("%d", &a)
#define IsComp(n)  (flag[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) flag[n>>6]|=(1<<((n>>1)&31))

using namespace std;

int flag[(MAX>>6)+1];
	
int main(){	

	for (int i = 3; i <= N; i += 2)
	    if (!IsComp(i))
	        for (int j = i*i; j <= MAX; j += i+i)
	                SetComp(j); 
	int x,a,b;	
	while(SCAN(x) != EOF){
		a=b=0;
		if(x & 1){
			if(x>3 && !IsComp(x-2)){
				a=2;
				b=x-2;	
			} 			
		}else{
			int i = ((x/2) == (x-x/2))?(x/2-1):(x/2);
			if(!(i&1)) i--; 
			for(; i>1; i-=2){
				if(!IsComp(i) && !IsComp(x-i)){
					a=i;
					b=x-i;
					break;	
				}	
			}							
		}
		if(a)	
			printf("%d is the sum of %d and %d.\n", x, a, b);
		else
			printf("%d is not the sum of two primes!\n", x);					
	}		
	return 0;
}
