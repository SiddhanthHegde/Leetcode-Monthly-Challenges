class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int s = flowerbed.size();
        int c = 0;
        flowerbed.push_back(0);
        for(int i = 0; i < s; i++){
            if(flowerbed[i]) continue;
            int left = i == 0 ? 0 : flowerbed[i - 1];
            int right = flowerbed[i+1];
            if(left == 0 && right == 0) {
                flowerbed[i] = 1;
                c++;
            }
        }
        return c >= n;
    }
};