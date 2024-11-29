#include "WebBrowser.h"
#include "RPNCalculator.h"
#include "MyStack.h"

//int main() {
//    WebBrowser browser;
//
//    browser.visit("google.com");
//    browser.visit("github.com");
//    browser.visit("stackoverflow.com");
//
//    browser.back();
//    browser.back();
//    browser.forward();
//
//}

int main() {
    string rpn = "8 2 5 * + 1 3 2 * + 4 - /";

    try {
        int result = evaluateRPN(rpn);
        cout << "Result: " << result << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }


}
