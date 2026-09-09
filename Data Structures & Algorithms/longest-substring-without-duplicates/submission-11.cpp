class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> freq;
        int ans = 0;
        int i=0;
        int j=0;
        while(j<n){
            freq[s[j]]++;
            while(freq[s[j]] >=2){
               freq[s[i]]--;
               i++;
            }
          ans = max(ans,j-i+1);
          j++;
        }
        return ans;
    }
};
