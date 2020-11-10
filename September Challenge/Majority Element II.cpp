class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1 = -1, x2 = -1, c1 = 0, c2 = 0;
        int n = nums.size()/3;
        vector<int> ans;
        for(int x : nums){
            if(x == x1) c1++;
            else if(x == x2) c2++;
            else if(c1 == 0){
                c1 = 1;
                x1 = x;
            }else if(c2 == 0){
                c2 = 1;
                x2 = x;
            }else{
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for(int x : nums){
            if(x == x1) c1++;
            if(x == x2) c2++;
        }
        if(c1 > n) ans.push_back(x1);
        if(c2 > n) ans.push_back(x2);
        return ans;
    }
};