class MyQueue {
    stack<int>s1;
    stack<int>s2;
    int peeks=-1;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
         if(s1.empty()){
            peeks=x;
        }
        s1.push(x);
       
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x = s2.top();
        s2.pop();
        return x;
    }
    
    int peek() {
        if(s2.empty() && peeks!=-1)return peeks;
        int x = s2.top();
        // s2.pop();
        return x;
    }
    
    bool empty() {
        if(s1.empty() && s2.empty())return 1;
        return 0;
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
