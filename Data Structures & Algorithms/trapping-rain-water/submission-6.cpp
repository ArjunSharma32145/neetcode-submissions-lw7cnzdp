class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int leftheight= 0;
        for(int i=0;i<n;i++){
            prefix[i] = leftheight;
            leftheight = max(leftheight,height[i]); 
        }
        int rightheight = 0;
        for(int i=n-1;i>=0;i--){
            suffix[i] = rightheight;
            rightheight = max(rightheight,height[i]);
        }
        int water= 0;
        for(int i=0;i<n;i++){
            int hcheck = min(prefix[i],suffix[i]) - height[i];
            if(hcheck<=0) continue;
            water += hcheck;
        }
        return water;
    }
};
