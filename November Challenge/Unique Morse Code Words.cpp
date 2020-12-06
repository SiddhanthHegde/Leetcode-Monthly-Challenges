class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> ans;
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto x : words){
            string k = "";
            for(char y : x){
                k += v[y - 'a'];
            }
            ans.insert(k);
        }
        return (int)ans.size();
    }
};