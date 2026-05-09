class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<int,char> freq;
        for(auto it : s) freq[it]++;
        for(auto it : t) freq[it]--;
        for(auto lol : freq) if(lol.second != 0) return false;
        return true;
    }
};
