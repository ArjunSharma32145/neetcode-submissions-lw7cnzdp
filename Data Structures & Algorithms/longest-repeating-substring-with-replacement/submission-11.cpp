class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq = 0;
        int ans = 0;
        int i=0;
        int j=0;
        unordered_map<char,int> freq;
        while(j<s.size()){
            freq[s[j]]++;
            maxfreq = max(maxfreq,freq[s[j]]);
            while((j-i+1) - maxfreq > k){
                freq[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
