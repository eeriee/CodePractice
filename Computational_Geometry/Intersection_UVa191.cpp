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

bool LLIntersect(segment s1, segment s2){
	LL a = findDir2(s1,s2);
	LL b = findDir2(s2,s1);
	if(a<0 && b<0)
		return true;
	if(a==0 &&(between(s1.p1,s1.p2,s2.p1) || between(s1.p1,s1.p2,s2.p2)))
			return true;
	if(b==0 &&(between(s2.p1,s2.p2,s1.p1) || between(s2.p1,s2.p2,s1.p2)))
			return true;
	return false;
}
bool inRect(point a, point tl, point br){
	if(a.x>=tl.x&&a.x<=br.x&&a.y<=tl.y&&a.y>=br.y)
		return true;
	return false;
}
bool LRIntersect(segment s, segment s1, segment s2, segment s3, segment s4){
	if(LLIntersect(s,s1) || LLIntersect(s,s2) ||LLIntersect(s,s3) ||LLIntersect(s,s4))
		return true;
	if(inRect(s.p1,s1.p1,s3.p2) || inRect(s.p2,s1.p1,s3.p2))
		return true;
	return false;	
}
int main(){
	int n, xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
	cin>>n;
	for(int set = 0; set<n; set++){
		cin>>xstart>>ystart>>xend>>yend>>xleft>>ytop>>xright>>ybottom;
		if(xleft > xright)
			swap(xleft, xright);
		if(ybottom > ytop)
			swap(ybottom, ytop);
		segment s = segment(point(xstart, ystart),point(xend, yend));
		segment s1 = segment(point(xleft, ytop),point(xleft, ybottom));
		segment s2 = segment(point(xleft, ytop),point(xright, ytop));
		segment s3 = segment(point(xright, ytop),point(xright, ybottom));
		segment s4 = segment(point(xleft, ybottom),point(xright, ybottom));
		if(LRIntersect(s, s1, s2, s3, s4))
			cout<<"T\n";
		else
			cout<<"F\n";
	}
	return 0;
}
