class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), i = 0, j = n - 1;
        
        while(i < j){
            if(numbers[i] + numbers[j] < target){
                ++i;
            }else if(numbers[i] + numbers[j] > target){
                --j;
            }else{
                return {i+1,j+1};
            }
        }
        return {};
    }
};
/* 
use binary search to find the medial number, and then use two pointers.
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size(), l = 0, r = n, m = (l+r)/2, half = target/2;
        while(r > l+1){
            if(numbers[m] < half) l = m;
            else if(numbers[m] > half) r = m;
            else break;
            m = (l+r)/2;
        }
        
        if(numbers[m] + numbers[m-1] >= target) m = m -1;
        
        for(int i = m, j = m+1; i > -1 && j < n; ){
            if(numbers[i] + numbers[j] < target)
                ++j;
            else if(numbers[i] + numbers[j] > target)
                --i;
            else
                return {i+1, j+1};
        }
        return {};
    }
};

worst case still O(n).
*/
