class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> factors;
        helper(factors, {}, n, 2);
        return factors;
    }
   /* bool divisible(int n){
        if(n != 2 && n%2 == 0) return true;
        for(int i = 3; i*i <= n; i+=2){
            if(n%i == 0) return true;
        } 
        return false;
    } */
    void helper(vector<vector<int>>& v, vector<int> head, int n, int prev){
        for(int i = prev; i*i <= n; ++i){
            if(n%i == 0){
                head.push_back(i);
                //if(divisible(n/i)){ 
                    helper(v, head, n/i, i);
                //} 
                head.push_back(n/i);
                v.push_back(head);
                head.pop_back();
                head.pop_back();
            }
        }
     }
};
/*Question:
Numbers can be regarded as product of its factors. For example,
8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.
Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
