class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int n = tokens.size();
        int l = 0, r = n - 1;
        int score = 0, maxscore = 0;
        while(l <= r){
            if(P >= tokens[l]){
                P-=tokens[l++];
                score++;
                maxscore = max(score,maxscore);
            }else if(score > 0){
                P += tokens[r--];
                score--;
            }else break;
        }
        return maxscore;
    }
};