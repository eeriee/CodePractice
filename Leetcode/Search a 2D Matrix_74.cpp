class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(!matrix.size()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n;
        while(low < high){
            int mid = (low+high)/2;
            int row = mid/n;
            int col = mid%n;
            int val = matrix[row][col];
            if(val == target) return true;
            if(val > target) high = mid;
            else low = mid+1;
        }
        return false;
    }
};