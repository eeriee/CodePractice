class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int bottomleftX = max(A,E);
        int bottomleftY = max(B,F);
        int toprightX = min(C,G);
        int toprightY = min(D,H);
        int area = (C-A)*(D-B) + (G-E)*(H-F);
        if(bottomleftX < toprightX && bottomleftY < toprightY)
            area -= (toprightX - bottomleftX) * (toprightY - bottomleftY);
        return area;
    }
};

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A,E), right = max(min(C,G), left);
        int bottom = max(B,F), top = max(min(D,H), bottom);
        return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
    }
};