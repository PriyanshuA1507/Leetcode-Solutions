class MyQueue {
public:
 stack<int> front;
 stack<int> rear;
    MyQueue() {
        
    }
    
    void push(int x) {
       front.push(x);
    }
    
    int pop() {
    if (rear.empty()) {
            while (!front.empty()) {
               rear.push(front.top());
                front.pop();
            }
        }
        int val =rear.top();
       rear.pop();
        return val;
    }
    
    int peek() {
    if (rear.empty()) {
            while (!front.empty()) {
                rear.push(front.top());
                front.pop();
            }
        }
        return rear.top();
    }
    
    bool empty() {
      return rear.size()==0 && front.size()==0;  
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */