class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> freq;
        if(s.size() != t.size()) return false;
        int n = s.size();
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto it : freq) if(it.second != 0) return false;
        return true;
    }
};
