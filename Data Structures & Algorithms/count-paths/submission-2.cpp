class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i == 0 && j == 0){
                     dp[i][j] = 1;
                     continue;
                }
                // left wala
                int left = 0;
               if(j>=1) left = dp[i][j-1] ;
               int up =0;
               if(i>=1) up = dp[i-1][j] ;
               dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
    }
};
