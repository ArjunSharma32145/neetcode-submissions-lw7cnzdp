class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int i=0;
        int ans = 1;
        bool flag= true;
        //Case 1
        for(int j=0;j<n-1;j++){
            if(flag){
                if(arr[j] < arr[j+1]){
                    ans = max(ans,j-i+2);
                }
                else i = j+1;
                flag = false;
            }
            else{
                if(arr[j] > arr[j+1]){
                    ans = max(ans,j-i+2);
                }
                else i = j+1;
                flag = true;
            }
        }
        //Case 2
        i = 0;
        flag = true;
        for(int j=0;j<n-1;j++){
            if(flag){
                if(arr[j] > arr[j+1]){
                    ans = max(ans,j-i+2);
                }
                else i = j+1;
                flag = false;
            }
            else{
                if(arr[j] < arr[j+1]){
                    ans = max(ans,j-i+2);
                }
                else i = j+1;
                flag  = true;
            }
        }
        return ans;
    }
};