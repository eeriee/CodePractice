// my way
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX, maxProf = 0;
        for(int i = 0; i < prices.size(); ++i){
            if(prices[i] < lowest){
                lowest = prices[i];
            }else{
                maxProf = max(maxProf, prices[i]-lowest);
            }
        }
        return maxProf;
    }
};

//Kadane's Algorithm
//https://en.wikipedia.org/wiki/Maximum_subarray_problem
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCurr = 0, maxProf = 0;
        for(int i = 1; i < prices.size(); ++i){
            maxCurr = max(0, maxCurr + prices[i] - prices[i-1]);
            maxProf = max(maxProf, maxCurr);
        }
        return maxProf;
    }
};