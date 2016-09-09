class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ranges;
        for(int i = 0; i < nums.size(); ++i){
            if(lower != nums[i]) {
               string s = to_string(lower);
               if((lower + 1) != nums[i]){
                    s += "->" + to_string(nums[i]-1);
               }
               ranges.push_back(s);
            }
            lower = nums[i]+1;
        }
        if(lower < upper){
            ranges.push_back(to_string(lower) + "->" + to_string(upper));
        }else if(lower == upper){
            ranges.push_back(to_string(lower));
        }
        return ranges;
    }
};
//pay attention to the concatenation of string and int in c++, it's different from Java. 
//use to_string(), which is already included in #include <string>, requiring c++11
/*
Java Solution
public class Solution {
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        List<String> ranges = new ArrayList<String>();
        for(int i = 0; i < nums.length; ++i){
            if(lower != nums[i]) {
               String s = lower + "";
               if((lower + 1) != nums[i])
                    s += "->" + (nums[i]-1);
               ranges.add(s);
            }
            lower = nums[i]+1;
        }
        if(lower < upper)
            ranges.add(lower + "->" + upper);
        else if(lower == upper)
            ranges.add(lower + "");
        
        return ranges;
    }
}
*/
