class Solution {
    vector<int> temp;
    void makenums(int num, int low,int high){
        if(num >= low && num <= high){
            temp.push_back(num);
        }
        if(num % 10 == 9) return;
        if(num > high) return;
        num = (num * 10) + (num % 10) + 1;
        makenums(num,low,high);
        
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        for(int i = 1; i <= 9; i++){
            makenums(i,low,high);
        }
        sort(temp.begin(),temp.end());
        return temp;
    }
};