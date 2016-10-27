//bfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        queue<pair<int,int>> q;
        int count = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == '0') continue;
                q.push(make_pair(i,j));
                grid[i][j] = '0';
                ++count;
                while(!q.empty()){
                     pair<int, int> x = q.front();
                     q.pop();
                     int xi = x.first;
                     int xj = x.second;
                     if(xi > 0 && grid[xi-1][xj] == '1'){
                         q.push(make_pair(xi-1, xj));
                         grid[xi-1][xj] = '0';
                     } 
                     if(xi < row-1 && grid[xi+1][xj] == '1'){
                         q.push(make_pair(xi+1, xj));
                         grid[xi+1][xj] = '0';
                     }
                     if(xj > 0 && grid[xi][xj-1] == '1'){
                         q.push(make_pair(xi, xj-1));
                         grid[xi][xj-1] = '0';
                     } 
                     if(xj < col-1 && grid[xi][xj+1] == '1'){
                         q.push(make_pair(xi, xj+1));
                         grid[xi][xj+1] = '0';
                     }
                }
            }
        }
        return count;
    }
};
//dfs
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0) return 0;
        int col = grid[0].size();
        int count = 0;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(grid[i][j] == '0') continue;
                dfs(i, j, row, col, grid);
                ++count;
            }
        }
        return count;
    }
    void dfs(int i, int j, int row, int col, vector<vector<char>>& grid){
        if(i < 0 || j < 0 || i >= row || j >= col || grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(i-1,j,row,col,grid);
        dfs(i+1,j,row,col,grid);
        dfs(i,j-1,row,col,grid);
        dfs(i,j+1,row,col,grid);
    }
};

//union find
class Solution {
public:
    vector<int> group;
    int count = 0;
    int find(int a){
        if(group[a] < 0){
            return a;
        }else{
            return group[a] = find(group[a]);
        }
    }
    void makeSet(int a, int b){
        group[a] += group[b];
        group[b] = a;
        --count;
    }
    void unionSet(int a, int b){
        int root1 = find(a);
        int root2 = find(b);
        if(root1 == root2) return;
        if(group[root1] < group[root2]){//root1 has more
            makeSet(root1, root2);
        }else{
            makeSet(root2, root1);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0) return 0;
        int m = grid[0].size();
        group.resize(n*m,-1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '0') continue;
                ++count;
                int idx = i*m+j;
                if(i < n-1 && grid[i+1][j] == '1'){
                    unionSet(idx, idx + m);
                }
                if(j < m-1 && grid[i][j+1] == '1'){
                    unionSet(idx, idx + 1);
                }

            }
        }
        return count;
    }
};