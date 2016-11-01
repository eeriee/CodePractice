class Solution {
public:
    int numSquares(int n) {
        queue<int> q;
        q.push(n);
        int depth = 0;
        int breadth = 0;
        int m = 1;
        while(!q.empty()){
            if(m == 0){
                ++depth;
                m = breadth;
                breadth = 0;
            }
            int num = q.front();
            q.pop();
            --m;
            int sr = (int) sqrt(num);
            int lmt = num/3; //think about why it can make sure it's the best answer?
            for(int i = sr; i > 0 && i*i >= lmt; --i){
                int res = num - i*i;
                if(res == 0) return depth+1;
                q.push(res);
                ++breadth;
            }
        }
        return 0;
    }
};