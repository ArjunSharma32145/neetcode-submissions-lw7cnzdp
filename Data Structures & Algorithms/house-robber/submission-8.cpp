class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
       int prev = nums[0];
       int prev2 = 0;
        int ans = 0;
        for(int i=1;i<n;i++){
          int loot = nums[i] + prev2;
          int notloot = 0 + prev;
          ans= max(loot,notloot);
          prev2 = prev;
          prev = ans;
        }
        return ans;
      }
};
