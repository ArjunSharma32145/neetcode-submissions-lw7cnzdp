class MinStack {
public:
    stack<int> s;
    stack<int> ss;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(ss.empty()) ss.push(val);
        else if(ss.top() > val) ss.push(val);
        else ss.push(ss.top());
    }
    
    void pop() {
        s.pop();
        ss.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return ss.top();
    }
};
