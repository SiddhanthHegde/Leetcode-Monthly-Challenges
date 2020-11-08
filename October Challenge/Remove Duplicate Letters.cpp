class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> count;
        for(char c : s) count[c]++;
        map<char,bool> visited;
        string ans;
        for(char c : s){
            count[c]--;
            if(visited[c]) continue;
            while(!ans.empty() && ans.back() > c && count[ans.back()]){
                visited[ans.back()] = false;
                ans.pop_back();
            }
            ans+=c;
            visited[c] = true;
        }
        return ans;
    }
};