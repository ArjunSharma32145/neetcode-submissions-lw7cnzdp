class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0;
        unordered_map<int,int> mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
           while(mpp[s[i]]>1){
            mpp[s[l]]--;
            l++;
           }
           ans = max(ans,i-l+1);
        }
        return ans;
    }
};
