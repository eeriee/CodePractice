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
#include<set>

using namespace std;

typedef long long int LL; 

struct point{
	LL x,y;
	point(){}
	point(LL a, LL b){x=a;y=b;}
	bool operator < (const point &p) const{
		if(x<p.x) return true;
		else if(x==p.x) return y<p.y;
		return false;
	}
};
LL cross(const point &p1, const point &p2, const point &p3){
	return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
}
LL determinant(point p1,point p2){
	return p1.x*p2.y-p1.y*p2.x;
}
LL getArea2(vector<point> P){
	LL area = 0;
	for(int i=0; i<P.size()-1; i++){
		area += determinant(P[i], P[i+1]);		
	}
	return area;
}
vector<point> findConvexHull(vector<point> P)
{
	int n = P.size(), k = 0;
	vector<point> H(2*n);

	sort(P.begin(), P.end());

	// Build lower hull
	for (int i = 0; i < n; ++i) {
		while (k >1 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (int i = n-2, t = k; i >= 0; i--) {
		while (k >t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}
int main(){
	int n, t =1;
	while(scanf("%d", &n)){
		if(n==0) break;
		vector<point> contour;
		int x,y;
		scanf("%d %d", &x, &y);
		point p0 = point(x,y);
		contour.push_back(p0);
		for(int i=1; i<n; i++){			
			scanf("%d %d", &x, &y);
			contour.push_back(point(x,y));
		}
		contour.push_back(p0);
		LL a1 = getArea2(contour);
		vector<point> hull = findConvexHull(contour);
		LL a2 = getArea2(hull);
		LL aw = a2 - a1;
		printf("Tile #%d\nWasted Space = %.2lf %%\n\n" , t++,(double)aw * 100/a2);
	}
	return 0;
}
