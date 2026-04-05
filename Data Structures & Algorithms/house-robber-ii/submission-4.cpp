class Solution {
public:
    int func(int start,int end,vector<int> & nums){
      int prev = nums[start];
      int prev2 = 0;
      int ans= 0;
      for(int i = start+1;i<end;i++){
         int loot = nums[i] + prev2;
         int notloot = 0 + prev;
         ans = max(loot,notloot);
         prev2 = prev;
         prev = ans;
      }
      return ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int onecase = func(1,n,nums);
        int seccase = func(0,n-1,nums);
        return max(onecase,seccase);
    }
};
