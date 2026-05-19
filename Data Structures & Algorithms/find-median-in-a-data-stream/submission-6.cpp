class MedianFinder {
public:
  //max heap
  priority_queue<double> piche;
  // min heap
  priority_queue<double,vector<double>,greater<double>> aage;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        piche.push(num);
        if( piche.size() && aage.size() && piche.top() > aage.top()){
            aage.push(piche.top());
            piche.pop();
        }
        if(piche.size() > aage.size() +1){
            aage.push(piche.top());
            piche.pop();
        }
        if(aage.size() > piche.size() + 1){
            piche.push(aage.top());
            aage.pop();
        }

    }
    
    double findMedian() {
        if(piche.size() > aage.size()){
            return piche.top();
        }
        if(aage.size() > piche.size()){
            return aage.top();
        }
        return (piche.top() + aage.top())/2;
    }
};
