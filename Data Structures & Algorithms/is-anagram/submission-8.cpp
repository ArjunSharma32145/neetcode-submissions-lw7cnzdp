class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map <char,int> mpp;
        for(auto it : s){
            mpp[it]++;
        }
        for(int i=0;i<s.size();i++){
            mpp[t[i]]--;
            if(mpp[t[i]] <0) return false;
        }
        return true;
    }
};
