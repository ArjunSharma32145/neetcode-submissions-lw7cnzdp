class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> lol;
      for(int i=0;i<nums.size();i++){
        int complement = target - nums[i];
        if(lol.find(complement) != lol.end()) return {lol[complement],i};
        lol[nums[i]] = i;
      } 
      return {}; 
    }
};
