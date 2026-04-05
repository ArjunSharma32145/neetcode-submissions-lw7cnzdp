class Solution {
public:
    vector<int> countBits(int n) {
      int l = 0;
      vector<int> ans;
        while(l!=n+1){
          int count =0;
          for(int i=0;i<32;i++){
            if(l &(1u<<i)) count++;
          }
          ans.push_back(count);
          l++;
        }
        return ans;
    }
};
