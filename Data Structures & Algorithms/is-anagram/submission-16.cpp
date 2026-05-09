class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> hashtable(26,0);
        for(auto it : s) hashtable[it - 'a']++;
        for(auto it : t) hashtable[it - 'a']--;
        for(auto it : hashtable) if(it != 0) return false;
        return true; 
    }
};
