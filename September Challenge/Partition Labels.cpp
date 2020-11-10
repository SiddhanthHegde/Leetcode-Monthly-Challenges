class Solution {
public:
    vector<int> partitionLabels(string S) {
        int n = S.length();
        vector<int> a(26);
        vector<int> ans;
        for(int i = 0 ; i < n; i++){
            a[S[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        for(int i = 0; i < n; i++){
            end = max(end,a[S[i] - 'a']);
            if(i == end){
                ans.push_back(end - start + 1);
                start = end + 1;
                
            }
        }
        return ans;
    }
        
};