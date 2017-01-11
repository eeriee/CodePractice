/*
Given two 1d vectors, implement an iterator to return their elements alternately.

For example, given two 1d vectors:

v1 = [1, 2]
v2 = [3, 4, 5, 6]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1, 3, 2, 4, 5, 6].

Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?

Clarification for the follow up question - Update (2015-09-18):
The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example, given the following input:

[1,2,3]
[4,5,6,7]
[8,9]
It should return [1,4,8,2,5,9,3,6,7].
*/
//smart way with space complexity O(1)
class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(!v1.empty()) q.push(make_pair(v1.begin(), v1.end()));
        if(!v2.empty()) q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
       vector<int>::iterator it1 = q.front().first;
       vector<int>::iterator it2 = q.front().second;
       q.pop();
       if(it1+1 != it2){
           q.push(make_pair(it1+1, it2));
       }
       return *it1;
    }

    bool hasNext() {
        return !q.empty();
    }
};
// stupid way, cannot easily extend to k lists.
class ZigzagIterator {
private:
    vector<int> v;
    int curr;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(), n2 = v2.size();
        int n = min(n1,n2);
        for(int i = 0; i < n; ++i){
            v.push_back(v1[i]);
            v.push_back(v2[i]);
        }
        for(int i = n; i < n1; ++i){
            v.push_back(v1[i]);
        }
        for(int i = n; i < n2; ++i){
            v.push_back(v2[i]);
        }
        curr = 0;
    }

    int next() {
        return v[curr++];
    }

    bool hasNext() {
        if(curr < v.size())
            return true;
        return false;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */