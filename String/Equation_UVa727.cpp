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
	case '/':
		temp = 3;
		break;
	case '+':
	case '-':
		temp = 2;
		break;		
	default:
		temp = 1;
		break;
	}
	return temp;
}
int main(){
	int n;
	cin>>n;
	string s, blank;
	char c;
	for(int i=0; i<n; i++){
		if(i==0){
			getline(cin,blank);
			getline(cin,blank);
		}
		getline(cin,s);
		char exp = s[0];
		stack<char> exps;
		while(s.length()>0){
			if(exp == '('){
				exps.push(exp);
			}else if(exp == ')'){
				while(true){
					char temp = exps.top();
					exps.pop();
					if(temp == '(')
						break;
					else
						cout<<temp;
				}
			}else if(exp >= '0' && exp<='9'){
				cout<<exp;
			}else if(exps.empty() || getPriority(exp) > getPriority(exps.top())){
				exps.push(exp);
			}else if(getPriority(exp) <= getPriority(exps.top())){
				char temp = exps.top();
				cout<<temp;
				exps.pop();
				continue;
			}	
			getline(cin,s);
			exp = s[0];
		}
		while(!exps.empty()){
			cout<<exps.top();
			exps.pop();
		}
		cout<<endl;
		if(i != n-1) cout<<endl;
	}
	return 0;
}
