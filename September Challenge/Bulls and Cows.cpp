class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0, cows = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i])
                bulls++;
        }
        vector<int> a1(10),a2(10);
        for(char x : secret)
            a1[x - '0']++;
        for(char x : guess)
            a2[x - '0']++;
        for(int i = 0; i < 10; i++){
            cows += min(a1[i],a2[i]);
        }
        cows = cows < bulls ? 0 : cows - bulls;
        string ans =  to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};