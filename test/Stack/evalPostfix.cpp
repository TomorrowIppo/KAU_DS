#include <iostream>
#include <string>
#include "../../include/Stack/ArrayStack/ArrayStack.hpp"

using namespace std;
using namespace ds;

/*
Sample input
23+4*5+

output
result = 25
*/

int main() {
    ArrayStack<int> stack;
    int val1 = 0, val2 = 0, offset = 0;
    string text;

    cin >> text; // 공백 없이 입력!

    for (char ch : text) {
        if (isdigit(ch)) {
            offset = ch - '0';
            stack.push(offset);
        } else {
            val2 = stack.pop();
            val1 = stack.pop();
            switch (ch) {
                case '+': stack.push(val1 + val2); break;
                case '-': stack.push(val1 - val2); break;
                case '*': stack.push(val1 * val2); break;
                case '/': stack.push(val1 / val2); break;
                default:
                    cerr << "Invalid operator" << endl;
                    return -1;
            }
        }
    }

    cout << "result = " << stack.pop() << endl;

    return 0;
}
