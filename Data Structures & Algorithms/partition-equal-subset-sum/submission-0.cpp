class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
      for(const auto & it : nums){
       sum += it;
      }  
      if(sum%2 != 0) return false;
      int target = sum/2;
      int n= nums.size();
    return balochistan(n-1,target,nums);
    }
private: 
 bool balochistan(int index, int target, vector<int> & alqaeda){
    if( target ==0) return true;
    if(index == 0) return target == alqaeda[index];
    bool nottake = balochistan(index-1,target,alqaeda);
    bool take = false;
    if(target >= alqaeda[index]){
        take = balochistan(index-1,target-alqaeda[index],alqaeda);
    }
    return nottake || take;
 }
};
