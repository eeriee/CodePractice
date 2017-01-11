// O(mn), O(n) space.
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), rowSum;
        vector<int> colSum(n);
        int maxEnemies = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!j || grid[i][j-1] == 'W'){
                    rowSum = 0;
                    for(int k = j; k < n && grid[i][k] != 'W'; ++k){
                        rowSum += grid[i][k] == 'E';
                    }
                }
                if(!i || grid[i-1][j] == 'W'){
                    colSum[j] = 0;
                    for(int k = i; k < m && grid[k][j] != 'W'; ++k){
                        colSum[j] += grid[k][j] == 'E';
                    }
                }
                if(grid[i][j] == '0'){
                    maxEnemies = max(maxEnemies, colSum[j] + rowSum);
                }
            }
        }
        return maxEnemies;
    }
};