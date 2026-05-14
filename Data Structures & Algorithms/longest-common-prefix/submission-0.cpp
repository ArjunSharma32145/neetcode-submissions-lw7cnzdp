class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int minlen = 1e9;
        for(auto it : strs){
              minlen = min(minlen,(int)it.size());
        }
        string ans = "";
        for(int i=0;i<minlen;i++){
            char c = strs[0][i];
            for(int j=1;j<n;j++){
             if(strs[j][i] != c) return ans;
            }
            ans += c;
        }
        return ans;
    }
};