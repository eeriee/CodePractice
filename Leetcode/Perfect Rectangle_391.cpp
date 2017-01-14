class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> se;
        int x1 = INT_MAX, y1 = INT_MAX, x2 = INT_MIN, y2 = INT_MIN, area = 0; 
        for(auto rect: rectangles){
            x1 = min(rect[0], x1);
            y1 = min(rect[1], y1);
            x2 = max(rect[2], x2);
            y2 = max(rect[3], y2);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            vector<string> strs;
            for(int i  = 0; i < 3; i=i+2){
                for(int j = 1; j < 4; j=j+2){
                    strs.push_back(to_string(rect[i]) + " " + to_string(rect[j]));
                }
            }
            for(string str: strs){
                if(se.count(str)) se.erase(str);
                else se.insert(str);
            }
        }
        string s1 = to_string(x1) +" "+ to_string(y1); 
        string s2 = to_string(x1) +" "+ to_string(y2);
        string s3 = to_string(x2) +" "+ to_string(y1);
        string s4 = to_string(x2) +" "+ to_string(y2);
        return area == (x2-x1)*(y2-y1) && se.size() == 4 && se.count(s1) && se.count(s2) && se.count(s3) && se.count(s4);
        /*
            [[0,0,1,1],[0,0,2,1],[1,0,2,1],[0,2,2,3]] 
            if only area and 4 corner points condition, it's not true.
            we need to ensure the only 4 is the final 4 corner.
        */
    }
};