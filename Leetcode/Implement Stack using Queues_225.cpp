// only use one queue
class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        int len = q.size();
        for(int i = 0; i < len-1; ++i){
            q.push(pop());
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = top();
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
// my solu
class MyStack {
private:
    queue<int> in;
    queue<int> out;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(in.empty()){
           swap(in, out);
        }
        out.push(x);
        while(!in.empty()){
            int top = in.front();
            in.pop();
            out.push(top);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res = top();
        out.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return out.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return out.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */