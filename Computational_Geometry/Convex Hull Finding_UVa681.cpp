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
};
LL cross(const point &p1, const point &p2, const point &p3){
	return (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
}

bool cmp(point p1, point p2){
	if(p1.y<p2.y) return true;
	else if(p1.y==p2.y) return p1.x<p2.x;
	return false;
}

vector<point> findConvexHull(vector<point> P)
{
	int n = P.size(), k = 0;
	vector<point> H(2*n);

	sort(P.begin(), P.end(), cmp);

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
	int n,m;
	cin>>n;
	cout<<n<<endl;
	for(int i = 0; i<n; i++){
		cin>>m;
		vector<point> contour;
		for(int j=0; j<m; j++){
			int x,y;
			cin>>x>>y;
			contour.push_back(point(x,y));
		}
		vector<point> hull = findConvexHull(contour);
		int t = hull.size();
		cout<<t<<"\n";
		for(int j=0; j<t;j++)
			cout<<hull[j].x<<" "<<hull[j].y<<"\n";
		if(i != n-1){
			cin>>m;
			cout<<"-1\n";
		}
	}

	return 0;
}
