#ifndef PILAS_COLAS_ITERADORES_EJERCICIO3_H
#define PILAS_COLAS_ITERADORES_EJERCICIO3_H

#include "stack.h"

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
        init_stack(&mainStack);
        init_stack(&minStack);
    }

    void push(int val) {
        ::push(&mainStack, val);
        if (isempty(&minStack) || val <= ::top(&minStack)) {
            ::push(&minStack, val);
        }
    }

    void pop() {
        if (!isempty(&mainStack)) {
            if (::top(&mainStack) == ::top(&minStack)) {
                ::pop(&minStack);
            }
            ::pop(&mainStack);
        }
    }

    int top() {
        return ::top(&mainStack);
    }

    int getMin() {
        return ::top(&minStack);
    }
};

void ejercicio3() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << "Mínimo actual: " << minStack.getMin() << endl;  // Output: -3
    minStack.pop();
    cout << "Elemento en el tope: " << minStack.top() << endl;  // Output: 0
    cout << "Mínimo actual: " << minStack.getMin() << endl;  // Output: -2

}

#endif //PILAS_COLAS_ITERADORES_EJERCICIO3_H
