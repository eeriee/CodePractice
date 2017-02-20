//bfs
class Solution {
private:
    vector<int> delta = {0,1,0,-1,0};
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),false));
        queue<pair<int,int>> q;
        q.push(make_pair(start[0], start[1]));
        visited[start[0]][start[1]] = true;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0; i < 4; ++i){
                int newx = x, newy = y;
                while(newx >= 0 && newx < maze.size() && newy >= 0 && newy < maze[0].size() && !maze[newx][newy]){
                    newx += delta[i];
                    newy += delta[i+1];
                }
                newx -= delta[i];
                newy -= delta[i+1];
                if(newx == destination[0] && newy == destination[1]) return true;
                if(visited[newx][newy]) continue;
                visited[newx][newy] = true;
                q.push(make_pair(newx, newy));
            }
        }
        return false;
    }
};
//dfs every time first roll until the end, mark the start node to avoid re-visit
class Solution {
private:
    vector<int> delta = {0,1,0,-1,0};
public:
    bool dfs(vector<vector<int>>& maze, int x, int y, vector<int>& destination, vector<vector<bool>>& visited){
        if(visited[x][y]) return false;
        if(x == destination[0] && y == destination[1]) return true;
        visited[x][y] = true;
        for(int i = 0; i < 4; ++i){
            int newx = x, newy = y;
            while(newx >= 0 && newx < maze.size() && newy >= 0 && newy < maze[0].size() && !maze[newx][newy]){
                newx += delta[i];
                newy += delta[i+1];
            }
            newx -= delta[i];
            newy -= delta[i+1];
            if(dfs(maze, newx, newy, destination, visited)) return true;
        }
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),false));
        for(int i = 0; i < 4; ++i){
            if(dfs(maze, start[0], start[1], destination, visited)) return true;
        }
        return false;
    }
};