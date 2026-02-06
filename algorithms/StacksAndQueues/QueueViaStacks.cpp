// 3.4 Queue via Stacks:
// Implement a MyQueue class which implements a queue using two stacks

#include <stack>

// Input: 1, 3, 4, 5
// Queue: 5, 4, 3, 1
// Stack1: 1, 3, 4, 5
// Stack2: 
class MyQueue {
    private:
        std::stack<int> mainStack;
        std::stack<int> queueStack;

        void shiftStacks() {
            if (queueStack.empty()) {
                while (!mainStack.empty())
                {
                    // Push the top of the mainStack
                    queueStack.push(mainStack.top());
                    mainStack.pop();
                }
            }
        }

    public:
        void push(int value) {
            mainStack.push(value);
        }

        int peek() {
            shiftStacks();
            return queueStack.top();
        }

        void pop() {
            shiftStacks();
            queueStack.pop();
        }

        bool empty() {
            return mainStack.empty() && queueStack.empty();
        }
};