class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxisum = -1e5;
        int currsum = 0;
        for(auto it : nums){
         currsum += it;
         maxisum = max(maxisum,currsum);
        if(currsum < 0) currsum = 0;
        }
        return maxisum;
    }
};
