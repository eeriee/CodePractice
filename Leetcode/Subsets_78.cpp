// iterative
class Solution1{
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = subs.size();
            for (int j = 0; j < n; j++) {
                subs.push_back(subs[j]); 
                subs.back().push_back(nums[i]);
            }
        }
        return subs;
    }
}; 

// recursive - backtracking
class Solution2 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<vector<int>> sets;
        vector<int> sub;
        sets.push_back(sub);
        makeSet(sets, sub, nums, 0);
        return sets;
    }
    void makeSet(vector<vector<int>>& sets, vector<int>& sub, vector<int>& nums, int start){
        for(int i = start; i < nums.size(); ++i){
            sub.push_back(nums[i]);
            sets.push_back(sub);
            makeSet(sets, sub, nums, i+1);
            sub.pop_back();
        }
    }
};

/*
Bit Manipulation, time complexity. O(n*2^n)

This is the most clever solution that I have seen. The idea is that to give all the possible subsets, we just need to exhaust all the possible combinations of the numbers. And each number has only two possibilities: either in or not in a subset. And this can be represented using a bit.

There is also another a way to visualize this idea. That is, if we use the above example, 1 appears once in every two consecutive subsets, 2 appears twice in every four consecutive subsets, and 3 appears four times in every eight subsets, shown in the following (initially the 8 subsets are all empty):

[], [], [], [], [], [], [], []

[], [1], [], [1], [], [1], [], [1]

[], [1], [2], [1, 2], [], [1], [2], [1, 2]

[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]

The code is as follows. */
class Solution3 {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int num_subset = pow(2, nums.size()); 
        vector<vector<int> > res(num_subset, vector<int>());
        for (int i = 0; i < nums.size(); i++)
            for (int j = 0; j < num_subset; j++)
                if ((j >> i) & 1)
                    res[j].push_back(nums[i]);
        return res;  
    }
};

