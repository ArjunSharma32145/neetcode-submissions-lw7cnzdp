class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int n = s.size();
        unordered_map<int,int> freq;
        int ans = 0;
        int maxfreq = 0;
        for(int i=0;i<n;i++){
          freq[s[i]]++;
          maxfreq = max(maxfreq,freq[s[i]]);
          while((i-left+1) - maxfreq > k){
            freq[s[left]]--;
            left++;
          }
          ans = max(ans,i-left+1);
        }
        return ans;
    }
};
