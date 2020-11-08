class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count = 0;
        if(k == 0){
            unordered_map<int,int> mp;
            for(int x : nums) mp[x]++;
            for(auto x : mp) count += x.second > 1 ? 1 : 0;
            return count;
        }
        unordered_set<int> s(nums.begin(),nums.end());
        
        for(int x : s){
            count += s.count(x + k);
        }
        return count;
    }
};