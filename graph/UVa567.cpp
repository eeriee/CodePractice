#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<list>
#include<iomanip>
#define for(i,n) for(int i=0; i<n; i++)
using namespace std;

int main(){
    int first;
    int set = 0;
       while(cin>>first){
            set++;
            bool map[20][20];           
            memset(map, 0, sizeof(map));
            for(i,19){
                         for(j, first){
                         int country;
                         cin>>country;
                         int temp = country -1;
                         map[i][temp]=map[temp][i]=true;
                         }
                         cin>>first;
            }  
            cout<<"Test Set #"<<set<<endl;                                                   
            for(i,first){
                         int prev[20];
                         memset(prev,-1,sizeof(prev)); 
                         bool v[20];
                         memset(v,0,sizeof(v)); 
                         queue<int> q;  
                         int s,d;
                         cin>>s>>d;                               
                         v[s-1]=true;
                         q.push(s-1);
                         while(!q.empty()){                        
                          int x= q.front();  
                           if(x==d-1)
                           break;                     
                           q.pop();                            
                           for(i,20){
                           if(map[x][i] && !v[i]) {
                                       q.push(i);
                                       v[i]=true; 
                                       prev[i]=x;
                                       if(i == d-1)
                                            break;
                                        } 
                               }            
                         }   
                         int temp = d-1;
                         int count=0;
                         while(prev[temp] != -1){
                                         count++;                                       
                                         if( (temp= prev[temp])== (s-1))
                                             break;     
                         }     
                          cout<<setw(2)<<right<<s<<" to ";
                          cout<<setw(2)<<right<<d<<": "<<count<<endl;                   
            }     
            cout<<endl;              
       } 
 return 0;   
}
