class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> diff(n);
        int total = 0;
        for(int i = 0; i < n; i++){
            diff[i] = gas[i] - cost[i];
            total += diff[i];
        }
        if(total < 0) return -1;
        for(int i = 0 ; i < n; i++){
            if(diff[i] > 0) return i;
        }
        return -1;
    }
};