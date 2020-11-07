class Solution {
public:
    int smallestDivisor(vector<int>& nums, int t) {
        int low = 1, high = *max_element(nums.begin(),nums.end());
        int ans;
        while(low <= high){
            int mid = low + (high - low)/2;
            int sum = 0;
            for(int x : nums) sum += ceil((float)x/mid);
            if(sum <= t){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};