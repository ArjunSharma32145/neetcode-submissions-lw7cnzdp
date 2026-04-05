class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int maxele = INT_MIN;
          for(int l=0;l<nums.size()-k+1;l++){
            maxele = INT_MIN;
            int r = l;
            while(r<nums.size() && r<k+l){
                maxele = max(maxele,nums[r]);
                r++;
            }
             ans.push_back(maxele);
          }
    return ans;
    }
};
