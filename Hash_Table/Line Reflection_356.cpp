//use x as the key. we could directly compare two sets!
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int,set<int>> mp;
        int minX = INT_MAX, maxX = INT_MIN;
        for(auto point: points){
            int x = point.first, y = point.second;
            mp[x].insert(y);
            minX = min(minX, x);
            maxX = max(maxX, x);
        }
        int line2X = minX + maxX;
        for(auto m: mp){
            int x1 = m.first, x2 = line2X - x1;
            if(!mp.count(x2) || m.second != mp[x2]) return false;
        }
        return true;
    }
};

//use y as the key. time complexity is the same as first solution
class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int,set<int>> mp;
        int minX = INT_MAX, maxX = INT_MIN;
        for(auto point: points){
            int x = point.first, y = point.second;
            mp[y].insert(x);
            minX = min(minX, x);
            maxX = max(maxX, x);
        }
        int line2X = minX + maxX;
        for(auto m: mp){
            int y = m.first;
            set<int> se = m.second;
            for(int x: se){
                if(!se.count(line2X - x)) return false;
            }
        }
        return true;
    }
};
/*
Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Hint:

Find the smallest and largest x-value for all points.
If there is a line then it should be at x = (minX + maxX) / 2.
For each point, make sure that it has a reflected point in the opposite side.
*/
