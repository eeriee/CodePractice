class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos, pos1, pos2;
        pos = m+n-1;
        pos1 = m-1;
        pos2 = n-1;
        while(pos1 >= 0 && pos2 >=0){
            if(nums1[pos1] >= nums2[pos2]){
                nums1[pos] = nums1[pos1];
                --pos1;
            }else{
                nums1[pos] = nums2[pos2];
                --pos2;
            }
            --pos;
        }
        //the front of the A array is already sorted
       /* while(pos1 >= 0){
            nums1[pos--] = nums1[pos1--];
        }*/
        while(pos2 >= 0){
            nums1[pos--] = nums2[pos2--];
        }
    }
};