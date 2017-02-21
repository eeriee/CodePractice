class Path{
public:
    int start_x;
    int start_y;
    int dist;
    string s;
    Path(int a, int b, int c, string str): start_x(a), start_y(b), dist(c), s(str){}
    bool operator < (const Path& p) const{
        if(dist == p.dist){
            return s > p.s;
        }
        return dist > p.dist;
    }
};
class Solution {
private:
    vector<int> delta = {0,1,0,-1,0};
    string movement = "rdlu";
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(),false));
        priority_queue<Path> q;
        q.push(Path(ball[0], ball[1], 0, ""));
        while(!q.empty()){
            int x = q.top().start_x;
            int y = q.top().start_y;
            int dist = q.top().dist;
            string path = q.top().s;
            q.pop();
            if(x == hole[0] && y == hole[1]){return path;}
            if(visited[x][y]) continue;
            visited[x][y] = true;
            for(int i = 0; i < 4; ++i){
                int newx = x, newy = y, newdist = dist;
                while(newx >= 0 && newx < maze.size() && newy >= 0 && newy < maze[0].size() && !maze[newx][newy] && (newx != hole[0] || newy != hole[1])){
                    newx += delta[i];
                    newy += delta[i+1];
                    ++newdist;
                }
                if(newx != hole[0] || newy != hole[1]){
                    newx -= delta[i];
                    newy -= delta[i+1];
                    --newdist;
                }
                if(visited[newx][newy]) continue;
                q.push(Path(newx, newy, newdist, path + movement[i]));
            }
        }
        return "impossible";
    }
};