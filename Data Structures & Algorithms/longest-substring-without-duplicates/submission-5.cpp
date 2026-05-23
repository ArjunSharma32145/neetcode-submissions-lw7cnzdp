class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int n = s.size();
        unordered_set<int> st;
        int ans = 0;
        int l = 0;
        for(int i=0;i<n;i++){
              while(st.count(s[i])){
                st.erase(s[l]);
                l++;
              }
              st.insert(s[i]);
              ans = max(ans,(int)st.size());
        }
        return ans;
    }
};
