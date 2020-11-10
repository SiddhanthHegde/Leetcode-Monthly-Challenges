class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i = 1; i <= n/2; i++){
            string x = s.substr(0,i);
            //cout<<x<<" ";
            int k = x.size();
            if(n % k == 0){
                string m;
                int y = n/k;
                while(y--){
                    m += x;
                }
                if(m == s) return true;
            }
        }
        return false;
    }
};