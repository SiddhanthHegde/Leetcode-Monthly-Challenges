class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> length(n,1), count(n,1);
        int lis = 1;
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] < nums[i]) {
                        if (length[j] + 1 > length[i]) {
                            length[i] = length[j] + 1;
                            count[i] = count[j];
                        } else if (length[j] + 1 == length[i]) {
                            count[i] += count[j];
                        }
                    }
                }
                lis = max(lis, length[i]);
            }

            int numLis = 0;
            for (int i = 0; i < n; i++)
                if (length[i] == lis)
                    numLis += count[i];

            return numLis;
    }
};