class Solution {
    vector<vector<int>> ans;
    void helper(vector<int>& temp, vector<int>& candidates,int target, int index){
        if(target <= 0){
            if(target == 0) ans.push_back(temp);
            return;
        }
        for(int i = index; i < (int)candidates.size();i++){
            temp.push_back(candidates[i]);
            helper(temp,candidates,target - candidates[i],i);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        helper(temp,candidates,target,0);
        return ans;
    }
};