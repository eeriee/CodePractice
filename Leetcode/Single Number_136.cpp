// O(n) time and O(1) space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int num: nums){
            res ^= num;
        }
        return res;
    }
};
// O(n) time and space
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> se;
        int sum = 0;
        for(int num: nums){
            if(se.count(num)) sum -= num;
            else{
                sum += num;
                se.insert(num);
            }
        }
        return sum;
    }
};