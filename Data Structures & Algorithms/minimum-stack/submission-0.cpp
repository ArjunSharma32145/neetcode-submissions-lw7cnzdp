class MinStack {
public:
    MinStack() {  
    }
       stack<int> st;
    stack<int> minst;   
    void push(int val) {
        st.push(val);
        int mini = min(val, minst.empty() ? val : minst.top());
        minst.push(mini);
    }
    
    void pop() {
        st.pop();
        minst.pop();
    }
    
    int top() {
      return  st.top();
    }
    
    int getMin() {
      return  minst.top();
    }
};
