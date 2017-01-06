class MinStack {
private:
    stack<int> numStk;
    stack<int> minStk;
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        numStk.push(x);
        if(minStk.empty() || minStk.top() >= x) minStk.push(x);
    }
    
    void pop() {
        if(minStk.top() == numStk.top()) minStk.pop();
        numStk.pop();
    }
    
    int top() {
        return numStk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */