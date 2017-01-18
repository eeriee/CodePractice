//use bit mask
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> flow(m, vector<int>(n,0)); // 1st bit store the previous state, 2nd bit store the curr state
        queue<pair<int,int>> q;
        for(int i = 0; i < n; ++i){
            q.push(make_pair(0,i));
        }
        for(int i = 0; i < m; ++i){
            q.push(make_pair(i,0));
        }
        vector<pair<int,int>> ans;
        bfs(ans, matrix, flow, q, 2, m, n);
        for(int i = 0; i < n; ++i){
            q.push(make_pair(m-1,i));
        }
        for(int i = 0; i < m; ++i){
            q.push(make_pair(i,n-1));
        }
        bfs(ans, matrix, flow, q, 1, m, n);
        return ans;
    }
    void bfs(vector<pair<int,int>>& ans, vector<vector<int>>& matrix, vector<vector<int>>& flow, queue<pair<int,int>>& q, int valid, int m, int n){
        vector<int> delta = {0, 1, 0, -1, 0};
        while(!q.empty()){
            auto v = q.front();
            int vi = v.first;
            int vj = v.second;
            q.pop();
            if((flow[vi][vj]&valid) == valid) continue;
            flow[vi][vj] |= valid;
            if(flow[vi][vj] == 3){
                ans.push_back(v);
            } 
            for(int i = 0; i < 4; ++i){
                int ui = vi + delta[i];
                int uj = vj + delta[i+1];
                if(ui>=0 && ui<m && uj>=0 && uj < n && (flow[ui][uj]&valid) != valid && matrix[ui][uj] >= matrix[vi][vj]){
                    q.push(make_pair(ui,uj));
                }
            }
        }
    }
};