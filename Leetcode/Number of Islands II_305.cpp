class Solution {
private:
    vector<int> grid;
public:
    int find(int x){
        if(grid[x] == x) return x;
        return grid[x] = find(grid[x]);
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> delta = {0, 1, 0, -1, 0};
        int count = 0;
        vector<int> res;
        grid.resize(m*n, -1);
        for(int i = 0; i < positions.size(); ++i){
            int vi = positions[i].first;
            int vj = positions[i].second;
            int v = vi*n + vj;
            grid[v] = v;
            ++count;
            for(int j = 0; j < 4; ++j){
                int ui = vi + delta[j];
                int uj = vj + delta[j+1];
                int u = ui*n + uj;
                if(ui >= 0 && ui < m && uj >= 0 && uj < n && grid[u] != -1){
                    int vroot = find(v);
                    int uroot = find(u);
                    if(vroot != uroot){
                        grid[uroot] = vroot;
                        --count;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};