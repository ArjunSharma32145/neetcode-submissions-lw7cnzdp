class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int result = change(n-1,amount,coins,dp);
        
        return result>=1e9 ? -1 : result;
    }
private :
int change(int index, int target ,  vector<int> & coins, vector<vector<int>> & dp){
if(target ==0 ) return 0;
if(index==0){
    if(target%coins[0]==0) return target/coins[0];
    return 1e9; // i just dont wanna prefer it
}
      if(dp[index][target] != -1) return dp[index][target];
    int nottake = change(index-1,target,coins,dp);
    int take = 1e9;
    if(coins[index]<=target) take = 1 + change(index,target-coins[index],coins,dp);
    return dp[index][target] = min(nottake,take);
}
};
