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

using namespace std;
typedef long long int LL; 
struct point{
	LL x,y;
	point(){}
	point(LL a, LL b){x=a;y=b;}
};
struct segment{
	point p1, p2;
	segment(point a, point b){p1=a;p2=b;}
};
LL findMatrix(point p1,point p2){
	return p1.x*p2.y-p1.y*p2.x;
}
LL findDir(point p1, point p2, point p3){
	return findMatrix(p1,p2)+findMatrix(p2,p3)+findMatrix(p3,p1);
}
LL findDir2(segment s1, segment s2){
	return findDir(s1.p1,s1.p2,s2.p1)*findDir(s1.p1,s1.p2,s2.p2);
}
bool between(point a, point b, point c)
{
	if(((b.x - a.x) * (c.y - a.y) -(c.x - a.x) * (b.y - a.y)) !=0)
		return false;
	if (a.x != b.x) // Line A-B is not Vertical
		return (((a.x <= c.x) && (c.x <= b.x)) ||
		((a.x >= c.x) && (c.x >= b.x)));
	else
		return (((a.y <= c.y) && (c.y <= b.y)) ||
		((a.y >= c.y) && (c.y >= b.y)));
}

bool hasCommonPtr(segment s1, segment s2){
	LL a = findDir2(s1,s2);
	LL b = findDir2(s2,s1);
	if(a<0 && b<0)
		return true;
	if(a==0)
		if(between(s1.p1,s1.p2,s2.p1) || between(s1.p1,s1.p2,s2.p2))
			return true;
	if(b==0)
		if(between(s2.p1,s2.p2,s1.p1) || between(s2.p1,s2.p2,s1.p2))
			return true;
	return false;
}
int main(){
	int n,m,t;
	cin>>n;
	for(int set = 0; set<n; set++){
		t=0;
		cin>>m;
		vector<segment> s;
		for(int i=0; i<m; i++){
			LL a,b,c,d;
			cin>>a>>b>>c>>d;
			s.push_back(segment(point(a,b),point(c,d)));
		}
		for(int i=0; i<m; i++){
			bool flag = true;
			for(int j=0; j<m; j++){
				if(i!=j && hasCommonPtr(s[i],s[j])){					
					flag = false;
					break;
				}
			}
			if(flag){
				t++;
			}
		}
		cout<<t<<endl;
	}

	return 0;
}
