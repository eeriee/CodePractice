class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record(nums.begin(), nums.end());
        int ans = 0;
        for(int num: nums){
            if(!record.count(num-1)){ // only consider the situation that num is the start of consecutive sequence
                int end = num + 1;
                while(record.count(end)){
                    ++end;
                }
                ans = max(ans, end - num);
            }
        }
        return ans;
    }
};

// way to calculate the start and end
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> record(nums.begin(), nums.end());
        int ans = 0;
        for(int num: nums){
            if(!record.count(num)) continue;
            record.erase(num);
            int prev = num-1;
            int next = num+1;
            while(record.count(prev)) record.erase(prev--);
            while(record.count(next)) record.erase(next++);
            ans = max(ans, next - prev - 1);
        }
        return ans;
    }
};

/*
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, vector<bool>> mp;
        unordered_map<int, bool> visited;
        for(int num: nums){
            if(mp.count(num)) continue;
            mp[num] = {false,false};
            visited[num] = false;
            if(mp.count(num-1)){
                mp[num-1][1]= true;
                mp[num][0] = true;
            }
            if(mp.count(num+1)){
                mp[num][1] = true;
                mp[num+1][0] = true;
            }
        }
        int max = 0;
        for(int num: nums){
            if(visited[num]) continue;
            int len = dfs(num, 0, mp, visited) + dfs(num, 1, mp, visited) - 1;
            if(len > max) max = len;
        }
        return max;
    }
    int dfs(int key, int next, unordered_map<int, vector<bool>>& mp, unordered_map<int, bool>& visited){
        visited[key] = true;
        if(!mp[key][next]) return 1;
        int nextKey = key + (next? 1: -1);
        return 1 + dfs(nextKey, next, mp, visited);
    }
};
*/