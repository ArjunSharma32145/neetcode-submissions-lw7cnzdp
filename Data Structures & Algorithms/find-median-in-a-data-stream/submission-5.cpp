class MedianFinder {
public:
vector<int> arr;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        arr.push_back(num);
    }
    
    double findMedian() {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        double ans;
        if(n%2 == 0){
            int mid = n/2;
            int prev = mid-1;
            double sum = arr[mid] + arr[prev];
            ans = sum/2;
        }
        else {
             int mid = n/2;
            ans = arr[mid];
        }
        return ans;
    }
};
