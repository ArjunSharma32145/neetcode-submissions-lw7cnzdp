class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxsum = nums[0];
        int minsum = 0;
        int cursum = 0;
        int totalsum =0;
        int cirsum = 0;
        for(int i=0;i<n;i++){
            cursum += nums[i];
            cirsum += nums[i];
            minsum = min(minsum,cirsum);
            totalsum += nums[i];
            maxsum = max(maxsum,cursum);
            cursum = max(cursum,0);
            cirsum = min(cirsum,0);

        }
        if(maxsum<0) return maxsum;
        return max(maxsum,totalsum-minsum);
    }
};