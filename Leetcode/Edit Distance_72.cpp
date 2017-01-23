#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string& s1, string& s2){
  if(!s1.size() || !s2.size()) return s1.size() + s2.size();
  int m = s1.size(), n = s2.size();
  vector<vector<int>> dist(m+1, vector<int>(n+1));
  for(int i = 0; i <= m; ++i){
    for(int j = 0; j <= n; ++j){
      if(i == 0 || j == 0){
        dist[i][j] = i+j;
        continue;
      }
      if(s1[i-1] == s2[j-1]) dist[i][j] = dist[i-1][j-1];
      else dist[i][j] = min(dist[i-1][j], min(dist[i][j-1], dist[i-1][j-1]))+1;
    }
  }
  return dist[m][n];
}
// To execute C++, please define "int main()"
int main() {
  string s1("gfg");
  string s2("bcefgg");
  cout << editDistance(s1,s2) << endl;
  return 0;
}
