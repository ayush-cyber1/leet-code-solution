class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        moveIfEmpty();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        moveIfEmpty();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

private:
    stack<int> inStack, outStack;

    void moveIfEmpty() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
};