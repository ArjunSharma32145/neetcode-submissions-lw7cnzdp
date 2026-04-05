class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n,0);
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n){
                if(temperatures[j]>temperatures[i]){
                    result[i] = j-i;
                    break;
                }
                j++;
            }
        }
        return result;
    }
};
