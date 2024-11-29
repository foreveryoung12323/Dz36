#include "WebBrowser.h"

void WebBrowser::visit(const string& url) {
    while (!forwardStack.isEmpty()) {
        forwardStack.pop();
    }
    history.push(url);
    cout << "Visited: " << url << endl;
}

string WebBrowser::back() {
    if (history.isEmpty())
        throw runtime_error("No history to go back to");
    string current = history.top();
    history.pop();
    forwardStack.push(current);
    cout << "Went back to: " << (history.isEmpty() ? "No previous site" : history.top()) << endl;
    return history.isEmpty() ? "" : history.top();
}

string WebBrowser::forward() {
    if (forwardStack.isEmpty())
        throw runtime_error("No forward history");
    string next = forwardStack.top();
    forwardStack.pop();
    history.push(next);
    cout << "Went forward to: " << next << endl;
    return next;
}
