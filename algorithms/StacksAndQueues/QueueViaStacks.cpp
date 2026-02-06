// 3.4 Queue via Stacks:
// Implement a MyQueue class which implements a queue using two stacks

#include <stack>
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
            if (queueStack.empty()) return -1;
            return queueStack.top();
        }

        void pop() {
            shiftStacks();
            if (!queueStack.empty()) {
                queueStack.pop();
            }
        }

        bool empty() {
            return mainStack.empty() && queueStack.empty();
        }
};