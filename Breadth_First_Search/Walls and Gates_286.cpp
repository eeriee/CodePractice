class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int ro = rooms.size();
        if(!ro) return;
        int co = rooms[0].size();
        int n = ro*co;
        queue<pair<int,int>> q;
        for(int i = 0; i < ro; ++i){
            for(int j = 0; j < co; ++j){
                if(rooms[i][j] == 0){
                    q.push(make_pair(i,j));
                }
            }
        }
        
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            int vi = v.first;
            int vj = v.second;
            int cur = rooms[vi][vj];
            if(vi > 0){
                int* up = &rooms[vi-1][vj];
                if(*up = INT_MAX){
                    *up = cur+1;
                    q.push(make_pair(vi-1, vj));
                }
            }
            if(vi+1<ro){
                int* down = &rooms[vi+1][vj];
                if(*down = INT_MAX){
                    *down = cur+1;
                    q.push(make_pair(vi+1, vj));
                }
            }
            if(vj > 0){
                int* left = &rooms[vi][vj-1];
                if(*left = INT_MAX){
                    *left = cur+1;
                    q.push(make_pair(vi, vj-1));
                }
            }
            if(vj+1<co){
                int* right = &rooms[vi][vj+1];
                if(*right = INT_MAX){
                    *right = cur+1;
                    q.push(make_pair(vi, vj+1));
                }
            }
        }
    }
};
