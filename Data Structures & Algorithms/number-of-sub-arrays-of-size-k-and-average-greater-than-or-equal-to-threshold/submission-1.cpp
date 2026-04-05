class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        vector<int>prefix(arr.size()+1);
        for(int i=0;i<arr.size();i++){
          prefix[i+1] += prefix[i] + arr[i];
        }
        int ans = 0;
        int l=0;
        for(int r = k-1;r<arr.size();r++){
          int sum = prefix[r+1] - prefix[l];
          int avg = sum/k;
          if(avg >= threshold) ans++;
          l++;
        }
        return ans;
    }
};