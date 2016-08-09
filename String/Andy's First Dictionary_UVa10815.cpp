#include <algorithm>
#include <math.h>
#include <string>
#include <vector> 
#include <queue>
#include <set>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	string s1, s2;
	set<string> dic;
    while(cin>>s1){		
		s2 = "";
		int len = s1.size();
		for(int i=0; i<len; i++){
			if(s1[i]>='A' && s1[i]<='Z'){
				s2.push_back(s1[i]-'A'+'a');
			}else if(s1[i]>='a' && s1[i]<='z'){
				s2.push_back(s1[i]);
			}else if(s2 != ""){
				dic.insert(s2);
				s2="";
			}				
		}
		if(s2 != "")
			dic.insert(s2);								
	}
	for (set<string>::iterator it=dic.begin(); it!=dic.end(); ++it)
    		cout << *it <<endl;
    return 0;
}
