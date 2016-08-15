#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<cstdio>
#include<cfloat>

using namespace std;

double EPS = 1.0e-6;

struct point{
	double x,y;
	point(){}
	point(double a, double b){x=a;y=b;}
};
double dist(point p){
	return sqrt(p.x*p.x + p.y*p.y);
}
bool hits(double d, point p, point v){
	if(abs(v.x*p.y-v.y*p.x)<EPS){
		double dp = dist(p);
		double dv = dist(v);	
		double dot = v.x*p.x + v.y*p.y;
		double D = d+ 5.0;
		if (dot > 0) D=2.0-dp;
		else if(dot < 0) D=dp;
		if(D<d || abs(D-d)<EPS) return true;
		return false;
	}
	return false;
}
int main(){
	double d;
	while(cin>>d){
		if(!d) break;
		double px,py,vx,vy;
		cin>>px>>py>>vx>>vy;
		if(hits(d, point(px,py),point(vx,vy)))
			cout<<"possible\n";
		else
			cout<<"impossible\n";		
	}
	return 0;
}
