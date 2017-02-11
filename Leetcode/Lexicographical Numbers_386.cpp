//fast O(n) time
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        int prev =  1;
        res.push_back(1);
        for(int i = 1; i < n; ++i){ //find what should be the next one
            if(prev*10 <= n){
                prev*=10;
            }else{
                while(prev%10 == 9 || prev == n) prev /= 10;
                ++prev;
            }
            res.push_back(prev);
        }
        return res;
    }
};
//my solu
class Solution {
public:
    void dfs(vector<int>& res, int prev, int n){
        if(prev > n) return;
        res.push_back(prev);
        for(int i = 0; i < 10; ++i){
            dfs(res, prev*10+i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i < 10; ++i){
            dfs(res, i, n);
        }
        return res;
    }
};