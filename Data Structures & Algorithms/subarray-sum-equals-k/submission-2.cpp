class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix = 0;
        int ans =0;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
          prefix += nums[i];
          int comp = prefix - k;
          if(comp == 0) ans++;
           if(mpp.count(comp)) ans += mpp[comp];
          mpp[prefix]++;
        }
        return ans;
    }
};