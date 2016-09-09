//Better solution. Initialize the vector to start from the end and create a quadratic function to avoid repeatitions.
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size(), index, i = 0, j = n-1;
        vector<int> sorted(n);
        if(a >= 0){
            index = n-1;
            while(i <= j){
                int y1 = quad(nums[i],a,b,c), y2 = quad(nums[j],a,b,c);
                if(y1 >= y2){
                    sorted[index] = y1;
                    ++i;
                }else{
                    sorted[index] = y2;
                    --j;
                }
                --index;
            }
        }else{
            index = 0;
            while(i <= j){
                int y1 = quad(nums[i],a,b,c), y2 = quad(nums[j],a,b,c);
                if(y1 <= y2){
                    sorted[index] = y1;
                    ++i;
                }else{
                    sorted[index] = y2;
                    --j;
                }
                ++index;
            }
        }
        return sorted;
    }
    
    int quad(int x, int a, int b, int c){
        return a*x*x + b*x + c;
    }
};
//Long solution. Discuss each case seperately.
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res;
        if(a == 0){
            if(b >= 0){
                for(int i = 0; i < n; ++i){
                    res.push_back(nums[i]*b + c);
                }
            }else{
                for(int i = n-1; i >= 0; --i){
                    res.push_back(nums[i]*b + c);
                }
            }
        }else{
            double midX = -(double)b/(2*a);
            int lo = 0, hi = n-1, mid;
            if(nums[hi] <= midX) mid = hi;
            else if(nums[lo] >= midX) mid = lo;
            else{
                while(lo < hi){
                    mid = (lo + hi)/2;
                    if(nums[mid] >= midX) hi = mid;
                    else lo = mid+1;
                }
                mid = lo;
            }
            int i, j;
            if(a < 0){
                i = 0; 
                j = n-1;
                while(i<j){
                    int x1 = nums[i], x2 = nums[j];
                    if(abs(x1-midX) >= abs(x2-midX)){
                        res.push_back(a*x1*x1 + b*x1+c);
                        ++i;
                    }else{
                        res.push_back(a*x2*x2 + b*x2+c);
                        --j;
                    }
                }
                int x = nums[i];
                res.push_back(a*x*x + b*x+c);
            }else{
                i = mid-1;
                j = mid;
                while(i >= 0 && j < n){
                    int x1 = nums[i], x2 = nums[j];
                    if(abs(x1-midX) <= abs(x2-midX)){
                        res.push_back(a*x1*x1 + b*x1+c);
                        --i;
                    }else if(abs(x1-midX) > abs(x2-midX)){
                        res.push_back(a*x2*x2 + b*x2+c);
                        ++j;
                    }
                }
                while(i >= 0){
                    int x1 = nums[i];
                    res.push_back(a*x1*x1 + b*x1+c);
                    --i;
                }
                while(j < n){
                    int x2 = nums[j];
                    res.push_back(a*x2*x2 + b*x2+c);
                    ++j;
                }
            }
        }
        return res;
    }
};
