class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> minv(n);
        minv[0] = nums[0];
        for(int i = 1; i < n; i++){
            minv[i] = min(minv[i - 1],nums[i]);
        }
        stack<int> s;
        for(int j = n - 1; j>=0 ; j--){
            if(nums[j] > minv[j]){
                while(!s.empty() && s.top() <=minv[j]) s.pop();
                if(!s.empty() && s.top() < nums[j]) return true;
                s.push(nums[j]);
            }
        }
        return false;
    }
};