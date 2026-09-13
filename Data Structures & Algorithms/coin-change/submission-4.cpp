class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
        // now if coins are zero then impossible 
        // if the amount is zero then zero coins required
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
          for(int j=1;j<=amount;j++){

            if(coins[i-1] <= j){
              int take = dp[i][j-coins[i-1]] + 1;
              int nottake = dp[i-1][j];
              dp[i][j] =  min(take,nottake);
            }
            else{
             dp[i][j] = dp[i-1][j];
            }
          }
        }
        if(dp[n][amount] == 1e9) return -1;
        return dp[n][amount];
    }
};
