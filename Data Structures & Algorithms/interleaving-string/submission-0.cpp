class Solution {
    bool solve(int i,int j,string & s1,string & s2,string & s3,vector<vector<int>> & dp){
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        if((i+j) == k) return true;
        if(i == n && j == m) return false;

        if(dp[i][j] != -1 ) return dp[i][j];

        bool firstchoice = false;
        if(i<n && s3[(i+j)] == s1[i]) firstchoice = solve(i+1,j,s1,s2,s3,dp);
        bool secchoice = false;
        if(j<m && s3[(i+j)] == s2[j]) secchoice = solve(i,j+1,s1,s2,s3,dp);
        return dp[i][j] = firstchoice || secchoice;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if((n+m) != s3.size()) return false;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
