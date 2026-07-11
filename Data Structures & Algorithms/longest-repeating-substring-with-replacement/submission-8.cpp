class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i =0;
        int j = 0;
        unordered_map<char,int> freq;
        int ans =0;
        int maxfreq = 0;
        while(j<n){
            freq[s[j]]++;
            maxfreq =max(maxfreq,freq[s[j]]);
            while((j-i+1) - maxfreq >k){
                freq[s[i]]--;
                if(freq[s[i]] == 0) freq.erase(s[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
