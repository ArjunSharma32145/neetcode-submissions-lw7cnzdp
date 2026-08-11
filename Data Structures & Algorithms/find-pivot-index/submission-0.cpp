class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0;
        for(auto it : nums) totalsum += it;
        int sum =0;
        for(int i=0;i<nums.size();i++){
            int right = totalsum - sum - nums[i];
            if(sum == right) return i;
            sum += nums[i];
        }
        return -1;
    }
};