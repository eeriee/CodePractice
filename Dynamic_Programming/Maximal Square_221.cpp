/*
Now let's try to optimize the above solution. As can be seen, each time when we update size[i][j], 
we only need size[i][j - 1], size[i - 1][j - 1] (at the previous left column) and size[i - 1][j] (at the current column). 
So we do not need to maintain the full m*n matrix. In fact, keeping two columns is enough. 
Now we have the following optimized solution.
*/
// O(mn) time and space
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int maxLen = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == '0') continue;
                if(i == 0 || j == 0){
                    dp[i][j] = matrix[i][j]-'0';
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen*maxLen;
    }
};