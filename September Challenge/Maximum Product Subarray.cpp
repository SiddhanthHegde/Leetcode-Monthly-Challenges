class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int cur_max = nums[0],cur_min = nums[0],final_max = nums[0];
        nums.erase(nums.begin());
        for(int x : nums){
            int temp = cur_max;
            cur_max = max({cur_max * x,cur_min * x,x});
            cur_min = min({temp * x,cur_min * x,x});
            final_max = max(final_max,cur_max);
        }
        return final_max;
    }
};