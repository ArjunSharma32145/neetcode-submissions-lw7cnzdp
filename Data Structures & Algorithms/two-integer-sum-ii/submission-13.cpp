class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=1;
        int j  = numbers.size();
        while(i<j){
            int sum = numbers[i-1] + numbers[j-1];
            if(sum > target) j--;
            else if(sum < target) i++;
            else return {i,j};
        }
        return {};
    }
};
