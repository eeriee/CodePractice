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

#define MAX 1000000
#define LMT 1000
using namespace std;
int prime[80000];
bool flag[1000005];
int cnt=0;

void getPrime(){
	memset(flag,1,sizeof(flag));
	for(int i=3; i<=LMT; i+=2){
		if(flag[i]){
			for(int j=i*i; j<=MAX; j+= 2*i)
				flag[j]=0;
		}
	}
	prime[0]=2;
	for(int i=3; i<=MAX; i+=2){
		if(flag[i]){
			prime[++cnt]=i;
		}
	}	
}
int getKey(int n){
	if((n&1)&&flag[n])
		return n;
	int sum,max;
	sum=max=0;
	for(int i=0; i<=cnt && prime[i]<=n ; i++){
		if( n%prime[i] == 0){
			max =prime[i];
			sum+=max;
		}
	}	
	return (max<<1)-sum;
}
int main(){		
	int a,b;
	getPrime();
	while(scanf("%d %d", &a, &b), a){		
		if(getKey(a)>getKey(b))
			puts("a");
		else
			puts("b");
	}
	return 0;
}
/*
Question:
Everlasting Sa-Ga, a new, hot and very popular role-playing game, is out on October 19, 2008.
Fans have been looking forward to a new title of Everlasting Sa-Ga.
Little Jimmy is in trouble. He is a seven-year-old boy, and he obtained the Everlasting Sa-Ga
and is attempting to reach the end of the game before his friends. However, he is facing difficulty
solving the riddle of the first maze in this game — Everlasting Sa-Ga is notorious in extremely
hard riddles like Neverending Fantasy and Forever Quest.
The riddle is as follows. There are two doors on the last floor of the maze: the door to the
treasure repository and the gate to the hell. If he wrongly opens the door to the hell, the game
is over and his save data will be deleted. Therefore, he should never open the wrong door.
So now, how can he find the door to the next stage? There is a positive integer given for each
door — it is a great hint to this riddle. The door to the treasure repository has the integer that
gives the larger key number. The key number of a positive integer n is the largest prime factor
minus the total sum of any other prime factors, where the prime factors are the prime numbers
that divide into n without leaving a remainder. Note that each prime factor should be counted
only once.
As an example, suppose there are doors with integers 30 and 20 respectively. Since 30 has three
prime factors 2, 3 and 5, its key number is 5 − (2 + 3) = 0. Similarly, since 20 has two prime
factors 2 and 5, its key number 20 is 5 − 2 = 3. Jimmy therefore should open the door with 20.
Your job is to write a program to help Jimmy by solving this riddle.
Input
The input is a sequence of datasets. Each dataset consists of a line that contains two integers a
and b separated by a space (2 ≤ a, b ≤ 106
). It is guaranteed that key numbers of these integers
are always different.
The input is terminated by a line with two zeros. This line is not part of any datasets and thus
should not be processed.
1
Output
For each dataset, print in a line ‘a’ (without quotes) if the door with the integer a is connected
to the treasure repository; print ‘b’ otherwise. No extra space or character is allowed.
Sample Input
10 15
30 20
0 0
Output for the Sample Input
a
b
*/
