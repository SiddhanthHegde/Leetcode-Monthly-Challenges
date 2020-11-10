class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask = 0, cmax = 0;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            unordered_set<int> s;
            for (int num : nums)
                s.insert(mask & num);

            int tmp = cmax | (1 << i);
            for (int prefix : s) {
                if (s.find(tmp ^ prefix) != s.end()) {
                    cmax = tmp;
                    break;
                }
            }
        }

        return cmax;
    }
};