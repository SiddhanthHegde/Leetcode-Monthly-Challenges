class Solution {
public:
    string decodeAtIndex(string s, int K) {
        int n = s.size();
        vector<long> len(n);
        len[0] = 1;
        int i = 1;
        while(len[i - 1] < K){
            if(isdigit(s[i])) len[i] = (s[i] - '0') * len[i - 1];
            else len[i] = 1 + len[i - 1];
            i++;
        }
        i--;
        while(len[i] > K){
            i--;
            if(len[i] < K) K = ((K - 1) % len[i]) + 1;
        }
        while(isdigit(s[i])) i--;
        return s.substr(i,1);
        
    }
};