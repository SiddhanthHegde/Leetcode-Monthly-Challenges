class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int k = N;
        int count = 0;
        while(N){
            N /= 2;
            count++;
        }
        return pow(2,count) - 1 - k;
    }
};