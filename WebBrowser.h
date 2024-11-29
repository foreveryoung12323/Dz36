#pragma once
#include "MyStack.h"
#include <string>
#include <iostream>
using namespace std;
class WebBrowser {
private:
    MyStack<string> history;
    MyStack<string> forwardStack;

public:
    void visit(const string& url);
    string back();
    string forward();
};
