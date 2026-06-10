class Solution {
public:
    int tribonacci(int n) {
       
      int  prev3 = 0;
  if(n==0) return prev3;
      int  prev2 = 1;
        if(n==1) return prev2;
      int  prev = 1;
        int curr = 0;
        for(int i=3;i<=n;i++){
           curr = prev + prev2 + prev3;
           prev3 = prev2;
           prev2 = prev;
           prev = curr;
        }
        if(!curr) return prev;
        return curr;
    }
};