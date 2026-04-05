class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,s,t,dp);
    }
    int func(int i, int j, string & s, string & t, vector<vector<int>> & dp){
          int n = s.size();
        int m = t.size();
        if(j<0) return 1; // matlab we have got that baby count that way
        if(i<0) return 0; // sadly we reached end dont find way
        if(dp[i][j] != -1) return dp[i][j];
        int take = 0;
        if(s[i]==t[j]) take = func(i-1,j-1,s,t,dp);
        int nottake  = func(i-1,j,s,t,dp);
        return dp[i][j] = take + nottake; 
    }
};
