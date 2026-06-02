class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m) return false; // agar dono ka size hi equal nahi hai to baat khatam
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            freq[t[i]]--;
        }
        for(auto it : freq) if(it.second != 0) return false;
        return true;

    }
};
