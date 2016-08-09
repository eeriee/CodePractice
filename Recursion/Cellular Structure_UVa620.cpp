#include<iostream>
#include<string>

using namespace std;
string getStage(string s){
	int len = s.length();
	if(len == 1) return "SIMPLE";       
	else if(len>=3 && s[len-1]== 'B' && s[len-2]== 'A'){
		string str = s.substr(0, len-2);
		string str2 = getStage(str);
		if(str2 != "MUTANT")
			return "FULLY-GROWN";
		else
			return "MUTANT";
	}
	else if(len>=3 && s[0]=='B' && s[len-1]=='A'){
		string str = s.substr(1,len-2);
		string str2 = getStage(str);
		if(str2 != "MUTANT")
			return "MUTAGENIC";
		else
			return "MUTANT";           
	}
	else return "MUTANT";
}

int main(){
	int n;
	cin>>n;
	string s, blank;
	getline(cin,blank);
	do{
		getline(cin,s);
		n--;         
		cout<< getStage(s)<<endl;                                       
	}while(n>0);   
	return 0;   
}
