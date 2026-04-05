class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      int cursum =0;
        for(int i=0;i<k-1;i++){
          cursum += arr[i];
        }
        int count = 0;
        for(int l =0;l<=arr.size()-k;l++){
          cursum += arr[l+k-1];
         if(cursum >= k*threshold) count++;
          cursum -= arr[l];
        }
        return count;
    }
};