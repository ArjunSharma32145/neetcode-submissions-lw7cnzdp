class Solution {
public:
    int rob(vector<int>& nums) {
        int n  = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        int curr = nums[0];
        for(int i=2;i<=n;i++){
            int loot = nums[i-1] + prev2;
            int notloot = 0 + prev;
            curr = max(loot,notloot);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
};
