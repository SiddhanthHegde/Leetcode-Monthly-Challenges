class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                string a = to_string(nums[i]) + to_string(nums[j]);
                string b = to_string(nums[j]) + to_string(nums[j]);
                if(b > a) swap(nums[i],nums[j]);
            }
        }
        string ans = "";
        int zeros = 0;
        for(int x : nums) {
            if(x == 0) zeros++;
            ans += to_string(x);
        }
        if(zeros == n) return "0";
        return ans;
    }
};