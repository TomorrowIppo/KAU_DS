#include <iostream>
#include "../../include/Stack/LinkedListStack/LinkedListStack.hpp"

using namespace std;
using namespace ds;

int main() {
    LinkedListStack<char>* stack = new LinkedListStack<char>();

    stack->push('A');
    cout << stack->peek() << '\n';   // A

    stack->push('B');
    stack->push('C');
    cout << stack->pop() << '\n';    // C
    cout << stack->peek() << '\n';   // B
    stack->push('D');

    stack->printInfo();              // D -> B -> A

    delete stack;
    return 0;
}
