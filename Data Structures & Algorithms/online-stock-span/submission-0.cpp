class StockSpanner {
public:
    stack<pair<int,int>> st;
    int index = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
             int check = index;
             int ans = 0;
     while(!st.empty()){
          if(st.top().first > price ){
          ans =  check - st.top().second;
          break;
          }
        else while(!st.empty() && st.top().first <= price ) st.pop();
     }
      if(st.empty()) ans = check+1;
     st.push({price,index});
     index++;
       return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */