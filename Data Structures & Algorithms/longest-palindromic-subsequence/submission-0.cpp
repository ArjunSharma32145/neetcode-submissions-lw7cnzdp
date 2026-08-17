class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(r.begin(),r.end());
        int m = s.size();
        int n = m;
        // gonna represent size not index
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //base case would be any one string has size zero which obv lps would be zero
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                    continue;
                }
                if(s[i-1] == r[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};