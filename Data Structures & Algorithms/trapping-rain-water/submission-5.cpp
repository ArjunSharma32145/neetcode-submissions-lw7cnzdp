class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int left = 0;
        for(int i=0;i<n;i++){
           prefix[i] = left;
           left = max(left,height[i]);
        }
        left = 0;
        for(int i=n-1;i>=0;i--){
           suffix[i] = left;
           left = max(left,height[i]);
        }
        int maxirainwater = 0;
        for(int i=0;i<n;i++){
            int ht = min(prefix[i],suffix[i]);
            int water = ht - height[i];
            if(water > 0) maxirainwater += water;
        }
        return maxirainwater;
    }
};
