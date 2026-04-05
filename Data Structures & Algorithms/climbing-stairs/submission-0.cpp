class Solution {
public:
int func(int  m){
    if(m==0) return 1;
    if(m==1) return 1;
    int  left = func(m-1);
    int right = func(m-2);
    return left+right;
 }

    int climbStairs(int n) {
       int ans =func(n);
       return ans;
    }
};
 
 