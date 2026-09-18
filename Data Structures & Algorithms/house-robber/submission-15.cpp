class Solution {
    vector<int> dp;
    int solve(int index,vector<int> & nums){
        int n = nums.size();
        if(index >= n ) return 0;

        if(dp[index] != -1) return dp[index];
        int loot = nums[index] + solve(index+2,nums);
        int notloot = 0 + solve(index+1,nums);
        return dp[index] =  max(loot,notloot);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n,-1);
     return   solve(0,nums);
    }
};
