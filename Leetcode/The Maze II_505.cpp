class Path{
public:
    int start_x;
    int start_y;
    int dist;
    Path(int a, int b, int c): start_x(a), start_y(b), dist(c){}
    bool operator < (const Path& p) const{return dist > p.dist;}
};
class Solution {
private:
    vector<int> delta = {0,1,0,-1,0};
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),false));
        priority_queue<Path> q;
        q.push(Path(start[0], start[1], 0));
        while(!q.empty()){
            int x = q.top().start_x;
            int y = q.top().start_y;
            int dist = q.top().dist;
            q.pop();
            if(x == destination[0] && y == destination[1]){return dist;}
            if(visited[x][y]) continue;
            visited[x][y] = true;
            for(int i = 0; i < 4; ++i){
                int newx = x, newy = y, newdist = dist;
                while(newx >= 0 && newx < maze.size() && newy >= 0 && newy < maze[0].size() && !maze[newx][newy]){
                    newx += delta[i];
                    newy += delta[i+1];
                    ++newdist;
                }
                newx -= delta[i];
                newy -= delta[i+1];
                --newdist;
                if(visited[newx][newy]) continue;
                q.push(Path(newx, newy, newdist));
            }
        }
        return -1;
    }
};