class Solution {
public:
    bool isAnagram(string s, string t) {
      unordered_map <int,int> mpp;
        unordered_map <int,int> map;
      if(s.size()!=t.size()) return false;
      for(int i=0;i<s.size();i++){
        mpp[s[i]]++;
       map[t[i]]++;
      }  
     for(int j=0;j<s.size();j++){
        if(map[s[j]]!=mpp[s[j]]) return false;
     }
      return true;
    }
};
