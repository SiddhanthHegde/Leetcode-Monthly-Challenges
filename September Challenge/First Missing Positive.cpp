class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int& x : nums){
            if(x <= 0 || x > n)
                x = n + 1;
        }
        for(int x : nums){
            x = abs(x);
            if(x <= n && nums[--x] > 0) nums[x] = -nums[x];
        }
        for(int i = 0; i < n; i++){
            if(nums[i] > 0)
                return i + 1;
        }
        return n + 1;
    }
};