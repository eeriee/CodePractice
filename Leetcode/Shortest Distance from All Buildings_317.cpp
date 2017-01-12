/*
You want to build a house on an empty land which reaches all buildings in the shortest amount of distance. You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:

Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.
For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2):

1 - 0 - 2 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (1,2) is an ideal empty land to build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.

Note:
There will be at least one building. If it is not possible to build such house according to the above rules, return -1.
*/
class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        if(grid.empty() || grid[0].empty()) return -1;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,0));
        vector<vector<int>> total(n, vector<int>(m,0));
        vector<int> delta = {0,1,0,-1,0}; 
        int valid = 0, minDist = INT_MAX;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == 1){
                    queue<pair<int,int>> q;
                    q.push(make_pair(i,j));
                    minDist = INT_MAX;
                    while(!q.empty()){
                        auto v = q.front();
                        int vi = v.first;
                        int vj = v.second;
                        q.pop();
                        for(int k = 0; k < 4; ++k){// for left,right, top, bottom
                            int ui = vi+delta[k];
                            int uj = vj+delta[k+1];
                            if(ui >= 0 && ui < n && uj >= 0 && uj < m && grid[ui][uj] == valid){
                                --grid[ui][uj];
                                dist[ui][uj] = dist[vi][vj]+1;
                                total[ui][uj] += dist[ui][uj];
                                if(total[ui][uj] < minDist){
                                    minDist = total[ui][uj];
                                }
                                q.push(make_pair(ui,uj));
                            }
                        }
                    }
                    --valid;
                }
            }
        }
        return minDist == INT_MAX?-1:minDist;
    }
};