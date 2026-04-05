class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int res=0;
        int l=0;
        int maxf=0;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
            maxf=max(maxf,freq[s[i]]);
            while((i-l+1)-maxf > k){
                freq[s[l]]--;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};
