#include <iostream>
#include <string>
#include "../../include/Stack/LinkedListStack/LinkedListStack.hpp"

using namespace std;
using namespace ds;

/*
Sample input 1
(){}()(())({{}})

output
OK!

Sample input 2
(){}()(())({{}})]

output
ERROR
*/

int main() {
    LinkedListStack<char> stack;
    string text;
    char prev = '\0';

    getline(cin, text);

    for (char ch : text) {
        switch (ch) {
            case '[': case '(': case '{':
                stack.push(ch);
                break;
            case ']': case ')': case '}':
                if (stack.isEmpty()) {
                    cout << "ERROR" << endl;
                    return -1;
                }
                prev = stack.pop();
                if ((ch == ']' && prev != '[') ||
                    (ch == ')' && prev != '(') ||
                    (ch == '}' && prev != '{')) {
                    cout << "ERROR" << endl;
                    return -1;
                }
                break;
            default:
                // 다른 문자는 무시
                break;
        }
    }

    if (!stack.isEmpty())
        cout << "ERROR" << endl;
    else
        cout << "OK!" << endl;

    return 0;
}
