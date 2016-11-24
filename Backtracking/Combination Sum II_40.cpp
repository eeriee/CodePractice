class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int>> res;
        vector<int> ve;
        helper(0, target, res, ve, candidates);
        return res;
    }
    void helper(int pos, int target, vector<vector<int>> &res, vector<int> &ve, vector<int>& cands){
       for(int i = pos; i < cands.size(); ++i){
            int cand = cands[i];
            if((i > pos && cand == cands[i-1]) || cand > target) continue;
            ve.push_back(cand);
            int ans = target - cand;
            if(ans == 0){
                res.push_back(ve);
            }else{
                helper(i+1, ans, res, ve, cands);
            }
            ve.pop_back();
        }
    }
};