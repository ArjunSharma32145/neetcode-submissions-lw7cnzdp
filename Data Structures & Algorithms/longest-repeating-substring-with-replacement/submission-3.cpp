class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> mpp;
        int maxf =0;
        int l =0;
        int ans= 0;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
            maxf= max(maxf,mpp[s[i]]);
            while((i-l+1)-maxf > k){
                mpp[s[l]]--;
                l++;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};
