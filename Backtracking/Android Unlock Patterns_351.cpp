/*
Given an Android 3x3 key lock screen and two integers m and n, where 1 ≤ m ≤ n ≤ 9, count the total number of unlock patterns of the Android lock screen, which consist of minimum of m keys and maximum n keys.

Rules for a valid pattern:
Each pattern must connect at least m keys and at most n keys.
All the keys must be distinct.
If the line connecting two consecutive keys in the pattern passes through any other keys, the other keys must have previously selected in the pattern. No jumps through non selected key is allowed.
The order of keys used matters.

Explanation:
| 1 | 2 | 3 |
| 4 | 5 | 6 |
| 7 | 8 | 9 |
Invalid move: 4 - 1 - 3 - 6 
Line 1 - 3 passes through key 2 which had not been selected in the pattern.

Invalid move: 4 - 1 - 9 - 2
Line 1 - 9 passes through key 5 which had not been selected in the pattern.

Valid move: 2 - 4 - 1 - 3 - 6
Line 1 - 3 is valid because it passes through key 2, which had been selected in the pattern

Valid move: 6 - 5 - 4 - 1 - 9 - 2
Line 1 - 9 is valid because it passes through key 5, which had been selected in the pattern.

Example:
Given m = 1, n = 1, return 9.
*/
/* 3rd solu. use bitmask to store visited infomation. fastest
used is the 9-bit bitmask telling which keys have already been used and (i1,j1) and (i2,j2) are the previous two key coordinates. A step is valid if...

I % 2: It goes to a neighbor row or
J % 2: It goes to a neighbor column or
used2 & (1 << (I/2*3 + J/2))): The key in the middle of the step has already been used.
*/
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        return count(m, n, 0, 1, 1, 1, 1);
    }
private:
    int count(int m, int n, int used, int i1, int j1, int i2, int j2) {
        int number = m <= 0;
        if (!n) return 1;
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int I = i2 + i, J = j2 + j, used2 = used | (1 << (i*3 + j));
                if (used2 > used && (I % 2 || J % 2 || used2 & (1 << (I/2*3 + J/2))))
                    number += count(m-1, n-1, used2, i2, j2, i, j);
            }
        }
        return number;
    }
};
//2nd solu, 1st optimization, because 1,3,7,9 are symmetric, 2,4,6,8 are symmetric. we only need to 
//count once. 4 times faster
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> grid(3, vector<bool>(3,false));
        int count = 0;
        for(int i = 0; i < 2; ++i){
            backtrack(m,n,1,0,i,count,grid); //1 and 2
        }
        count *= 4;
        backtrack(m,n,1,1,1,count,grid); //5
        return count;
    }
    void backtrack(int m, int n, int len, int I, int J, int& count, vector<vector<bool>>& grid){
        if(len >= m) ++count;
        if(len == n) return;
        grid[I][J] = true;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(i == I && j == J) continue;
                if(!grid[i][j]){
                    int diffI = abs(i-I);
                    int diffJ = abs(j-J);
                    if((diffI + diffJ == 4 || (diffI + diffJ == 2 && diffI*diffJ == 0)) && !grid[(i+I)/2][(j+J)/2]) continue;
                    backtrack(m, n, len+1, i, j, count, grid);
                }
            }
        }
        grid[I][J] = false;
    }
};
// first solu. slowest
class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<bool>> grid(3, vector<bool>(3,false));
        int count = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                backtrack(m,n,1,i,j,count,grid);
            }
        }
        return count;
    }
    void backtrack(int m, int n, int len, int I, int J, int& count, vector<vector<bool>>& grid){
        if(len >= m) ++count;
        if(len == n) return;
        grid[I][J] = true;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                if(i == I && j == J) continue;
                if(!grid[i][j]){
                    int diffI = abs(i-I);
                    int diffJ = abs(j-J);
                    if((diffI + diffJ == 4 || (diffI + diffJ == 2 && diffI*diffJ == 0)) && !grid[(i+I)/2][(j+J)/2]) continue;
                    backtrack(m, n, len+1, i, j, count, grid);
                }
            }
        }
        grid[I][J] = false;
    }
};