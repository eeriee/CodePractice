#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int BinToDec(int x)
{
	int result = 0;
	for(int i=0; x > 0; i++) {
		if(x % 10 == 1) 
			result += (1 << i);
		x /= 10;
	}
	return result;
}
string DecToBin(int x)
{
	if ( x == 0 ) return "0";
	if ( x == 1 ) return "1";

	if ( x % 2 == 0 )
		return DecToBin(x / 2) + "0";
	else
		return DecToBin(x / 2) + "1";
}
int main(){
	int fisrtMemory;
	while(cin>> fisrtMemory){
		int memory[32];
		memory[0]=fisrtMemory;
		int pc =0;
		int accu =0;
		for(int i=1; i<32;i++){		
			cin>>memory[i];
		}
		while(pc<32){		
			int instr = memory[pc];
			++pc;
			if(pc==32)
				pc=0;
			int type = instr / 100000;
			int address = instr % 100000;
			int index = BinToDec(address);
			bool exitloop = false;
			int temp = 0;
			switch (type)
			{
			case 0: 
				memory[index] = accu;
				break;
			case 1:
				accu= memory[index];
				break;
			case 10:
				if(accu == 0)
					pc = index;
				break;
			case 100:
				temp = BinToDec(accu);	
				if(temp == 0)
					accu = 11111111;
				else{
					--temp;
					accu = std::stoi(DecToBin(temp));
				}
				break;
			case 101:
				temp = BinToDec(accu);			
				++temp;
				accu = std::stoi(DecToBin(temp));
				if(accu >= 100000000)
					accu %= 100000000;
				break;
			case 110:
				pc = index;
				break;
			case 111:
				exitloop = true;
				break;
			default:
				break;
			}
			if(exitloop) break;
		}
		cout<<setfill('0')<<setw(8)<<accu<<endl;
	}
	return 0;   
}
