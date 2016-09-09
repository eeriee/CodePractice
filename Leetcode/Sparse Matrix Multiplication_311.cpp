class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rows = A.size(), cols = B[0].size();

        if(rows == 0 || cols == 0) return {};
        
        vector<vector<int>> result(rows, vector<int>(cols));
        vector<vector<int>> nonZeroA(rows);

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < B.size(); ++j){
                if(A[i][j]) nonZeroA[i].push_back(j);
            }
        }

        for(int i = 0; i < rows; ++i){
            vector<int> nzA = nonZeroA[i];
            for(int j = 0; j < cols; ++j){
                for(int n = 0; n < nzA.size(); ++n){
                    int index = nzA[n];
                    if(B[index][j]) result[i][j] += A[i][index]*B[index][j];
                }
            }
        }
        return result;
    }
    
};
/* No additional table:
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rows = A.size(), cols = B[0].size();

        vector<vector<int>> result(rows, vector<int>(cols));

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < A[0].size(); ++j){
                if(A[i][j]){
                    for(int k = 0; k < cols; ++k){
                        if(B[j][k])
                            result[i][k] += A[i][j] * B[j][k];
                    }
                }
            }
        }
        return result;
    }
    
};
*/
/*
Question:
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

A = [
  [ 1, 0, 0],
  [-1, 0, 3]
]

B = [
  [ 7, 0, 0 ],
  [ 0, 0, 0 ],
  [ 0, 0, 1 ]
]


     |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
                  | 0 0 1 |
*/
