class Solution {
    vector<int> dp;
    int solve(int index,vector<int> & nums){
        if(index == nums.size()-1) return 0;
    if(dp[index] != -1) return dp[index];
     int ans = 1e9;
        for(int jump=1;jump<=nums[index];jump++){
            if(index+jump >= nums.size()) break;
      ans = min(ans,solve(index+jump,nums) + 1);
        }
        return dp[index] = ans;
    }
public:
    int jump(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return solve(0,nums);
    }
};
