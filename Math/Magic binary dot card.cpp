#include<iostream>
#include<bitset>
#include<string>
using namespace std;

int main(){
	long long a,b;
	while(cin>>a>>b){
		string binaryA = bitset<60>(a).to_string();
		string binaryB = bitset<60>(b).to_string();
		int lenB = binaryB.length();
		long long result;
		if(binaryA.compare(binaryB) != 0){
			for(long long i=0; i<lenB; i++){
				if(binaryA.at(i) != binaryB.at(i)){
					binaryB.replace(i+1, lenB-i-1, lenB-i-1, '1');						
					break;
				}
			}
		}
		result = bitset<60>(binaryB).to_ullong();
		cout<<result<<endl;
	}
	return 0;
}
