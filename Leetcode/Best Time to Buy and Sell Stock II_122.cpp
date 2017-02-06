class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int prof = 0, currProf = 0;
        for(int i = 1; i < prices.size(); ++i){
            currProf = max(0, prices[i] - prices[i-1]);
            prof += currProf;
        }
        return prof;
    }
};