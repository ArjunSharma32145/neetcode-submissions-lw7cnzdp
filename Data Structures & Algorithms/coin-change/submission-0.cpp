class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int result = change(n-1,amount,coins);
        return result>=1e9 ? -1 : result;
    }
private :
int change(int index, int target ,  vector<int> & coins){
if(target ==0 ) return 0;
if(index==0){
    if(target%coins[0]==0) return target/coins[0];
    return 1e9; // i just dont wanna prefer it
}

    int nottake = change(index-1,target,coins);
    int take = 1e9;
    if(coins[index]<=target) take = 1 + change(index,target-coins[index],coins);
    return min(nottake,take);
}
};
