class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int ans = 0;
        for( auto x : mpp) if(x.second ==1) ans = x.first;
        return ans;
    }
};
