/*
Now let's try to optimize the above solution. As can be seen, each time when we update size[i][j], 
we only need size[i][j - 1], size[i - 1][j - 1] (at the previous left column) and size[i - 1][j] (at the current column). 
So we do not need to maintain the full m*n matrix. In fact, keeping two columns is enough. 
Now we have the following optimized solution.
*/
// O(mn) time and O(m) space
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(m + 1, 0);
    int maxsize = 0, pre = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            int temp = dp[i];
            if (matrix[i - 1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                maxsize = max(maxsize, dp[i]);
            }
            else dp[i] = 0; 
            pre = temp;
        }
    }
    return maxsize * maxsize;
}
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (!m) return 0;
    int n = matrix[0].size();
    vector<int> pre(m, 0);
    vector<int> cur(m, 0);
    int maxsize = 0;
    for (int i = 0; i < m; i++) {
        pre[i] = matrix[i][0] - '0';
        maxsize = max(maxsize, pre[i]);
    }
    for (int j = 1; j < n; j++) {
        cur[0] = matrix[0][j] - '0';
        maxsize = max(maxsize, cur[0]);
        for (int i = 1; i < m; i++) {
            if (matrix[i][j] == '1') {
                cur[i] = min(cur[i - 1], min(pre[i - 1], pre[i])) + 1;
                maxsize = max(maxsize, cur[i]);
            }else{
                cur[i] = 0;
            }
        }
        swap(pre, cur);
    }
    return maxsize * maxsize;
}
};
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