class Solution {
    int solve(int index,int buy,int cool,vector<vector<vector<int>>> & dp,vector<int> & prices){
        if(index == prices.size()) return 0;
        if(dp[index][buy][cool] != -1) return dp[index][buy][cool];
        int profit = 0;
        if(cool){
            profit = solve(index+1,buy,cool-1,dp,prices);
        }
        else if(buy){
            profit = max(-prices[index] + solve(index+1,0,cool,dp,prices), 0 + solve(index+1,1,cool,dp,prices));
        }
        else{
            profit = max(prices[index] + solve(index+1,1,cool+1,dp,prices) , 0 + solve(index+1,0,cool,dp,prices));
        }
        return dp[index][buy][cool] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
       vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(0,1,0,dp,prices);
    }
};
