class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> mpp;
        if(s.size() != t.size()) return false;
        for(auto x : s) mpp[x]++;
        for(auto y : t) mpp[y]--;
        for(auto it : mpp) if(it.second != 0) return false;
        return true;
    }
};
