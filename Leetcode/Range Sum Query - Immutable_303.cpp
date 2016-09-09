//hashmap
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            sums[i] = sum;
        }
        sums[-1] = 0;
    }

    int sumRange(int i, int j) {
        return sums[j] - sums[i-1];
    }
    unordered_map<int, int> sums;
};
//vector. faster
class NumArray {
public:
    NumArray(vector<int> &nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            sums[i] = sum;
        }
        sums[-1] = 0;
    }

    int sumRange(int i, int j) {
        return sums[j] - sums[i-1];
    }
    unordered_map<int, int> sums;
};
//partial_sum function
class NumArray {
public:
    NumArray(vector<int> &nums) : psum(nums.size()+1, 0) {
        partial_sum( nums.begin(), nums.end(), psum.begin()+1);
    }

    int sumRange(int i, int j) {
        return psum[j+1] - psum[i];
    }
private:
    vector<int> psum;    
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
