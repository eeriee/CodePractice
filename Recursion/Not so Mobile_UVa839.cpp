#include<iostream>
#include<string>

using namespace std;
string getResult(int& w1, int d1, int& wr, int dr){
	string result = "";  
	int a,b,c,d;	
	if(w1 == 0) {  
		cin>>a>>b>>c>>d;
		result = (result != "NO")?getResult(a,b,c,d):result;
		w1 = a + c;
	}
	if(wr == 0) {
		cin>>a>>b>>c>>d;  
		result = (result != "NO")?getResult(a,b,c,d):result;
		wr = a + c;
	}  
	if(w1 != 0 && wr != 0){
		if(w1*d1 == wr*dr && result != "NO")
			result = "YES";
		else 
			result = "NO";
	}   
	return result;
}
int main(){
	int n;
	cin>>n;
	string s, blank;
	getline(cin,blank);
	for(int i=0; i<n; i++){
		getline(cin,blank);
		int w1,d1,wr,dr;
		cin>>w1>>d1>>wr>>dr;
		cout<<getResult(w1,d1,wr,dr)<<endl;
		if(i!=n-1) cout<<endl;          
	}    
	return 0;   
}
