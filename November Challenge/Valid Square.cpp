class Solution {
    float d(vector<int>& a, vector<int>& b){
        return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> v;
        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);
        sort(v.begin(),v.end(),[](vector<int> a, vector<int> b){
            if(a[0] == b[0]) return a[1] < b[1];
            else return a[0] < b[0];
        });
        float a1 = d(v[0],v[1]);
        float a2 = d(v[0],v[2]);
        float a3 = d(v[2],v[3]);
        float a4 = d(v[1],v[3]);
        float a5 = d(v[0],v[3]);
        float a6 = d(v[1],v[2]);
        if(a1 == 0) return false;
        return (a1 == a2 && a2 == a3 && a3 == a4 && a1 == a4) && (a5 == a6);
    }
};