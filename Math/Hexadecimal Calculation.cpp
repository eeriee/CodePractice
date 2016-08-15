#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;
int getPriority(char c){
	int temp;
	switch (c)
	{
	case '*':
		temp = 3;
		break;
	case '+':
		temp = 2;
		break;		
	default:
		temp = 1;
		break;
	}
	return temp;
}
int hexToDec(char c){
	if(c >= '0' && c<='9')
		return c - '0';
	else
		return c -'A' + 10;
}
string decToHex(int a){
	string c;
	if(a < 16){
		if(a < 10)
			c = '0' + a;
		else
			c = 'A' + a - 10;
		return c;
	}else{
		if(a%16 < 10)
			c = '0' + a%16;
		else 
			c = 'A' + a%16 - 10;
		return decToHex(a/16) + c;
	}
}
int main(){	
	string s;
	while(getline(cin,s)){
		stack<char> exps;
		queue<char> q;
		int i=0;
		while(i<s.length()){
			char exp = s[i];
			if(exp == '('){
				exps.push(exp);
			}else if(exp == ')'){
				while(true){
					char temp = exps.top();					
					exps.pop();
					if(temp == '(')
						break;
					else
						q.push(temp);
				}
			}else if((exp >= '0' && exp<='9')||(exp >= 'A' && exp<='F')){
				q.push(exp);
			}else if(exps.empty() || getPriority(exp) > getPriority(exps.top())){
				exps.push(exp);
				char temp = exps.top();
			}else if(getPriority(exp) <= getPriority(exps.top())){
				char temp = exps.top();
				q.push(temp);
				exps.pop();
				continue;
			}	
			i++;
		}
		while(!exps.empty()){
			char temp = exps.top();
			q.push(exps.top());
			exps.pop();
		}
		stack<int> digit;
		while(!q.empty()){
			char temp = q.front();
			if(temp == '+' || temp== '*'){
				int a = digit.top();
				digit.pop();
				int b = digit.top();
				digit.pop();
				if(temp == '+')
					digit.push(a+b);
				else
					digit.push(a*b);
			}else{
				digit.push(hexToDec(temp));		
			}
			q.pop();	
		}
		cout<<decToHex(digit.top())<<endl;
	}
	return 0;
}
