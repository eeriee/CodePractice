class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m, vector<int>(n));
        for(int i = 0; i < m; ++i){
            grid[i][0] = 1;
        }
        for(int j = 0; j < n; ++j){
            grid[0][j] = 1;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};

//cut to the O(min(m, n)) space complexity
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m > n) swap(m,n);
        vector<int> grid(m, 1);
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < m; ++j){
                grid[j] += grid[j-1];
            }
        }
        return grid[m-1];
    }
};