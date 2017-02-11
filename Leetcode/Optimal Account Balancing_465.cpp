class Solution {
public:
    int dfs(vector<int>& money, int start, int n, int num){
        int res = INT_MAX;
        while(start < n && money[start] == 0) ++start;
        for(int i = start+1; i <n; ++i){
            if((money[i] < 0 && money[start] > 0) || (money[i] > 0 && money[start] < 0)){
                money[i] += money[start];
                res = min(res, dfs(money, start+1, n, num+1));
                money[i] -= money[start];
            }
        }
        return res == INT_MAX?num:res;
    }
    int minTransfers(vector<vector<int>>& transactions) {
        if(transactions.empty()) return 0;
        unordered_map<int, int> mp;
        for(auto& trans: transactions){
            mp[trans[0]] -= trans[2];
            mp[trans[1]] += trans[2];
        }
        vector<int> money;
        for(auto& trans: mp){
            if(trans.second)
                money.push_back(trans.second);
        }
       
        return dfs(money, 0, money.size(), 0);
    }
};