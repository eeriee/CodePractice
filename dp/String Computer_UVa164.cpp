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
#include<iomanip>
#include<map>
#define FOR(i,a,n) for(int i=a; i<=n; i++)
#define N 25
#define INF 0xFFFFFFF
using namespace std;

char a[N], b[N];
int alen, blen;
int dp[N][N], path[N][N], edit[4];;
void init(){
	memset(path,-1,sizeof(path));
	FOR(i,0,alen){
		dp[i][0]=i;
		path[i][0]=1;
	}
	FOR(i,0,blen){
		dp[0][i]=i;
		path[0][i]=2;
	}	
}
void printPath(int i, int j){
	if(i ==0 && j==0) return;
	switch(path[i][j]){
		case 1: 
			printPath(i-1, j);
			printf("D%c%02d", a[i], j+1);
			break;
		case 2:
			printPath(i, j-1);
			printf("I%c%02d", b[j], j);
			break;			
		case 3:
			printPath(i-1, j-1);
			printf("C%c%02d", b[j], j);	
			break;				
		default:
			printPath(i-1, j-1);
			break;	
	}		
}
int main(){
	while(scanf("%s", a+1)){
		if(a[1] == '#') break;
		scanf("%s", b+1);
		alen = strlen(a+1);
		blen = strlen(b+1);
		init();
		
		FOR(i,1,alen) FOR(j,1,blen){
			dp[i][j]=INF;
			edit[1]=dp[i-1][j]+1; //D
			edit[2]=dp[i][j-1]+1; //A
			edit[3]=dp[i-1][j-1]+1; //C
			if(a[i] == b[j])
				edit[0] = dp[i-1][j-1];
			else
				edit[0] = INF;
			FOR(k,0,3){
				if(edit[k]<dp[i][j]){
					dp[i][j]=edit[k];
					path[i][j]=k;
				}
			}													
		}	
				
		printPath(alen,blen);
		puts("E");
	}
	return 0;
}
/*
Question:
Extel have just brought out their newest computer, a string processing computer dubbed the X9091.
It is hoped that it will have some value in cryptography and related elds. (It is rumoured that the
Taiwanese are working on a clone that will correct Stage 1 essays, but we will ignore such vapourware).
This computer will accept input strings and produce output strings from them, depending on the
programs loaded into them at the time. The chip is the ultimate in RISC technology|it has only three
transformation instructions:
 Delete a character at a particular position.
 Insert a character at a particular position.
 Change the character at a particular position to a dierent character.
Programs for this machine are written in a form of machine code where each instruction has the
format ZXdd---Z represents the code for the instruction (D, I or C), X is a character and dd represents
a two digit number. A program is terminated by a special halt instruction consisting of the letter `E'.
Note that each instruction works on the string in memory at the time the instruction is executed.
To see how this all works consider the following example. It is desired to transform the string `abcde'
to the string `bcgfe'. This could be achieved by a series of Change commands, but is not minimal. The
following program is better.
abcde
Da01 bcde % note the `a' is necessary because it is checked by the hardware
Cg03 bcge
If04 bcgfe
E bcgfe % Terminates the program
Write a program that will read in two strings (the input string and the target string) and will
produce a minimal X9091 program necessary to transform the input string into the target string. Since
there may be multiple solutions, only one should be produced. Any solution that satises these criteria
will be accepted.
Input and Output
Input will consist of a series of lines, each line containing two strings separated by exactly one space.
The strings will consist of no more than 20 lower case characters. The le will be terminated by a line
consisting of a single #.
Output will consist of a series of lines, one for each line of the input. Each will consist of a program
in X9091 language.
Sample input
abcde bcgfe
#
Sample output
Da01Cg03If04E
*/
