class Solution {
public:
    int characterReplacement(string s, int k) {
         // max freq walo ka to same rehne do minority ko change karo thats the idea 
         // ab freq ko track karne ke liye to map rkhna padega
         unordered_map<char,int> freq;
         int n = s.size();
         int i = 0;
         int j = 0;
         int ans = 0;
         int maxifreq = 0;
         while(j<n){
            freq[s[j]]++;
            maxifreq = max(maxifreq,freq[s[j]]);
            while((j-i+1) - maxifreq > k){
                freq[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
         }
         return ans;

    }
};
