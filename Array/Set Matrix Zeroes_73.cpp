class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int col0 = 1, row = matrix.size(), col = matrix[0].size();
        //from top to bottom
        for(int i = 0; i < row; ++i){
            if(!matrix[i][0]) col0 = 0;
            for(int j = 1; j < col; ++j){
                if(!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        //from bottom to top
        for(int i = row-1; i >= 0; --i){
            for(int j = col-1; j> 0; --j){
                if(!matrix[i][0] || !matrix[0][j])
                    matrix[i][j] = 0;
            }
            if(!col0) matrix[i][0] = 0;
        }
    }
};