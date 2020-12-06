class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        sort(digits.begin(), digits.end());
        string numstr = to_string(n);
        int count = 0;
        
        for(int i = 1; i <= numstr.size() - 1; i++) {
            count += pow(digits.size(), i);
        }
        
        int i = 0;
        while(i < numstr.size()) {
            int j = 0;
            while(j < digits.size() && digits[j][0] < numstr[i]) {
                count += pow(digits.size(), numstr.size() - 1 - i);
                j++;
            }
            if(j == digits.size() || digits[j][0] > numstr[i]) {
                break;
            }
            i++;
        }

        if(i == numstr.size()) {
            count++;
        }
        return count;
    }
};