class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int count = 0, left = 0, right = 0;
        int prod = 1;
        while(right < n){
            prod *= nums[right];
            while(prod >= k){
                prod /= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        
        return count;
    }
};