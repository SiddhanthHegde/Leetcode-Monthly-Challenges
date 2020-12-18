class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i,j;
        i = j = INT_MAX;
        for(int x : nums){
            if(x <= i) i = x;
            else if(x <= j) j = x;
            else return true;
        }
        return false;
    }
};