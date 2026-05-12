class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count  =0;
        int res = 1e9;
        for(int i=0;i<nums.size();i++){
            if(res != nums[i] && count != 0)  count--;
            else if(res != nums[i] && count == 0) {
                res = nums[i];
                count =1;
            }
            else if(res == nums[i]) count++;
        }
        return res;
    }
};