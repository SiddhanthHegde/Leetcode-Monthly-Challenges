class Solution {
public:
    bool buddyStrings(string A, string B) {
        int na = A.size();
        int nb = B.size();
        if(A == B){
            set<char> s;
            for(char x : A) s.insert(x);
            if(s.size() < na) return true;
            return false;
        }
        if(na != nb) return false;
        vector<int> v;
        for(int i = 0; i < na; i++){
            if(A[i] != B[i]) v.push_back(i);
        }
        if(v.size() == 2 && A[v[0]] == B[v[1]] && B[v[0]] == A[v[1]]) return true;
        return false;
    }
};