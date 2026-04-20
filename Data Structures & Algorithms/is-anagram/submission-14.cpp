class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> freq(26,0);
        for(auto it : s) freq[it-'a']++;
        for(auto lol : t) freq[lol-'a']--;
        for(auto check : freq) if(check != 0) return false;
        return true;
    }
};
