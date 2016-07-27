class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> arr(length, 0);
        int start, end, val;
        for(int i = 0; i < updates.size(); ++i){
            start = updates[i][0];
            end = updates[i][1];
            val = updates[i][2];
            arr[start] += val;
            if(end < length-1) arr[end+1] -= val;
        }
        for(int i = 1; i < length; ++i){
            arr[i] += arr[i-1];
        }
        return arr;
    }
};
