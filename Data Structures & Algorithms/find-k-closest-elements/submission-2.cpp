class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> diffi;
    
        int l =0;
        int cursum =0;
        int j=0;
        for( j=0;j<k;j++){
            cursum += abs(arr[j] - x);
        }
        j=k-1;
        int index = l;
       int sum = cursum;
        while(j<=arr.size()-1){
            cursum -= abs(arr[l] - x);
            l++;
            j++;
              if(j>arr.size()-1) break;
            cursum += abs(arr[j] - x);
           if(cursum <sum){
             index = l;
             sum = cursum;
           }
        }
      for(int i=index;i<index+k;i++){
        diffi.push_back(arr[i]);
      }
      return diffi;
    }
};