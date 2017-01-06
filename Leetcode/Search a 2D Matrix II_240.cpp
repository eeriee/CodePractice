// O(m+n) m-num of row, n- num of col
// We can rule out one row or one column each time, so the time complexity is O(m+n).
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        //from top right corner
        int row = 0, col = matrix[0].size()-1;
        while(col >=0 && row < matrix.size()){
            int val = matrix[row][col];
            if(val == target) return true;
            if(val > target) --col;
            else ++row;
        }
        return false;
    }
};
// my binary search method O(mlogn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        int low = 0, high = matrix[0].size();
        for(int i = 0; i < matrix.size(); ++i){
            if(binarySearch(matrix[i], low, high, target))
                return true;
            if(!high) break;
        }
        return false;
    }
    bool binarySearch(vector<int>& row, int low, int& high, int target){
        while(high > low){
            int mid = (low+high)/2;
            int val = row[mid];
            if(val == target) return true;
            if(val > target) high = mid;
            else low = mid+1;
        }
        return false;
    }
};