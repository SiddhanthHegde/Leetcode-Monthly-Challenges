class Solution {
    bool helper(vector<int>& arr, int start, vector<bool>& vis){
        int n = arr.size();
        if(start < 0 || start >= n || vis[start]) return false;
        if(arr[start] == 0) return true;
        vis[start] = true;
        return helper(arr, start - arr[start], vis) || helper(arr, start + arr[start], vis);
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n, false);
        return helper(arr, start, vis);
    }
};