// 3.2 Stack Min:
// How would you design a stack which, in addition to push and pop, has a function min
// which returns the minimum element? Push, pop and min should all operate in O(1) time.
#include <stack>

class MinStack {
    private:
        std::stack<int> mainStack;
        std::stack<int> minStack;

    public:
        void push(int val) {
            mainStack.push(val);
            
            // the firstNumber is always inherently the min
            if (minStack.empty() || val <= minStack.top()) {
                minStack.push(val);
            }
        }
        void pop() { 
            if (mainStack.empty()) return;

            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }

        int min(){
            if (minStack.empty()) return;
            return minStack.top();
        }

};