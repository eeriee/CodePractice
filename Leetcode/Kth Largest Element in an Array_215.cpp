// priority_queue
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
        return pq.top();
    }
};
// heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = n/2-1; i >= 0; --i){
            heapify(nums, n, i);
        }
        for(int i = n-1; i >= n-k; --i){
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
        return nums[n-k];
    }
    
    void heapify(vector<int>& nums, int n, int i){
        int max = i;
        int left = i*2 + 1;
        int right = i*2 + 2;
        if(left < n && nums[left] > nums[i]){
            max = left;
        }
        if(right < n && nums[right] > nums[max]){
            max = right;
        }
        if(max != i){
            swap(nums[max], nums[i]);
            heapify(nums, n, max);
        }
    }
    
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }
};

// Partition algorithm
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        --k;
        int lo = 0, hi = nums.size() - 1;
        while(lo < hi){
            int pos = partition(nums, lo, hi); //return the postion before which are larger than the pivot
            if(pos < k){
                lo = pos+1;
            }else if (pos > k){
                hi = pos -1;
            }else{
                break;
            }
        }
        return nums[k];
    }
    int partition(vector<int>& nums, int lo, int hi){
        int pivot = nums[lo];
        int start = lo;
        int end = hi+1;
        while(true){
            while(start < hi && nums[++start] > pivot); //before start, items > pivot
            while(end > lo && nums[--end] < pivot); // after end, items < pivot
            if(start >= end) break; 
            swap(nums[start], nums[end]);
        }
        swap(nums[lo], nums[end]); // after swapping, before end, all element are larger than nums[end]
        return end;
    }
    
    void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
    }

};
