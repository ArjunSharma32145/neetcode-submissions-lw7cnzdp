class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxleft(n,0);
        vector<int> maxright(n,0);
        int prefix = 0;
        for(int i=0;i<n;i++){
            maxleft[i] = prefix;
            prefix = max(prefix,height[i]);
        }
        int suffix = 0;
        for(int i=n-1;i>=0;i--){
            maxright[i] = suffix;
            suffix = max(suffix,height[i]);
        }
        int rainwater = 0;
        for(int i=0;i<n;i++){
            int check = min(maxleft[i],maxright[i]) - height[i];
            if(check >=0) rainwater += check;
        }
        return rainwater;
    }
};
