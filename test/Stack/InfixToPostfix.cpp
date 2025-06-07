#include <iostream>
#include <string>
#include "../../include/Stack/LinkedListStack/LinkedListStack.hpp"

using namespace std;
using namespace ds;

/*
Sample input
3+(4*5)-6/2

output
345*+62/-
*/

// 연산자 우선순위 함수 정의
int precedence(char oper);

int main() {
    LinkedListStack<char> stack;
    string text;
    char op = '\0';

    cin >> text; // 공백 없이 입력

    for (char ch : text) {
        if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty()) {
                op = stack.peek();
                stack.pop();
                if (op == '(') break;
                cout << op;
            }
        } else if (ch >= '0' && ch <= '9') { // 한 자리 수만 가정
            cout << ch;
        } else {
            while (!stack.isEmpty()) {
                op = stack.peek();
                if (precedence(ch) > precedence(op)) break;
                cout << op;
                stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        cout << stack.peek();
        stack.pop();
    }

    return 0;
}

int precedence(char oper) {
    switch (oper) {
        case '(':
        case ')':
            return 0;
        case '+':
        case '-':
            return 1;
        default:
            return 2;
    }
    return -1;
}
