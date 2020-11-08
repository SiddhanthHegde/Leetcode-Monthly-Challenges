class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> ans;
        for(int x : a){
            if(ans.empty() || x > 0) ans.push_back(x);
            else{
                while(1){
                    int p = ans.back();
                    if(p < 0){
                        ans.push_back(x);
                        break;
                    }
                    else if(x == -p){
                        ans.pop_back();
                        break;
                    }
                    else if(x > -p){
                        break;
                    }else{
                        ans.pop_back();
                        if(ans.empty()){
                            ans.push_back(x);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};