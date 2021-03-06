//dp
class Solution {
public:
    bool isMatch(string s, string p) {
       int m = s.size(), n = p.size();
       if(!n) return m == n;
       vector<vector<bool>> dp(m+1, vector<bool>(n+1,false));
       dp[0][0] = true; // dp[i][j] means s[0..i-1] == p[0..j-1]
       for(int i = 0; i < n; ++i){
           if(p[i] == '*' && dp[0][i-1]) dp[0][i+1] = true;
       }
       for(int i = 0; i < m; ++i){
           for(int j = 0; j < n; ++j){
               if(p[j] == '.' || p[j] == s[i]) dp[i+1][j+1] = dp[i][j];
               else if(p[j] == '*'){ // j must >=1 because '*' cannot be the start
                    if(p[j-1] == '.' || p[j-1] == s[i]){
                        dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j] || dp[i+1][j-1]; 
                    }else{
                        dp[i+1][j+1] = dp[i+1][j-1];
                    }
               }
              
           }
       }
       return dp[m][n];
    }
};
//recursive
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())    return s.empty();
        
        if ('*' == p[1])
            // x* matches empty string or at least one character: x* -> xx*
            // *s is to ensure s is non-empty
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};
