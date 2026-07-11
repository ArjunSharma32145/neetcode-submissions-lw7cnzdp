class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmax(n,0);
        vector<int> rightmax(n,0);
        int leftht = 0;
        for(int i=0;i<n;i++){
            leftmax[i] = leftht;
            leftht = max(leftht,height[i]);
        }
        int rightht = 0;
        for(int i=n-1;i>=0;i--){
            rightmax[i] = rightht;
            rightht = max(rightht,height[i]);
        }
        int rainwater = 0;
        for(int i=0;i<n;i++){
            int ht = min(leftmax[i],rightmax[i]);
            int water =  ht - height[i];
            if(water <0) water = 0;
            rainwater += water;
        }
   return rainwater;
    }
};
