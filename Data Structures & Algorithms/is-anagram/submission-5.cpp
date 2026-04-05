class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> mpp;
        unordered_map <char,int> map;
        if(s.size() != t.size()) return false;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            map[t[i]]++;
        }
        for(int j=0;j<s.size();j++){
            if(mpp[t[j]] != map[t[j]]) return false;
        }
        return true;
    }
};
