#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class MyStack {
private:
    vector<T> stack;

public:
    bool isEmpty() const;
    T top() const;
    void push(const T& value);
    void pop();
    void show() const;
};

template <typename T>
bool MyStack<T>::isEmpty() const {
    return stack.empty();
}

template <typename T>
T MyStack<T>::top() const {
    if (!isEmpty())
        return stack.back();
    throw runtime_error("Stack is empty");
}

template <typename T>
void MyStack<T>::push(const T& value) {
    stack.push_back(value);
}

template <typename T>
void MyStack<T>::pop() {
    if (!isEmpty())
        stack.pop_back();
    else
        throw runtime_error("Stack is empty");
}

template <typename T>
void MyStack<T>::show() const {
    for (auto it = stack.rbegin(); it != stack.rend(); ++it)
        cout << *it << std::endl;
}
