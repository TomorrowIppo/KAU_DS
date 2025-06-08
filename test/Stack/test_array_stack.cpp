#include "../../include/Stack/ArrayStack/ArrayStack.hpp"

using namespace ds;
using namespace std;

int main() {
    ArrayStack<char> stack;

    stack.push('A');
    cout << stack.peek() << '\n';  // A

    stack.push('B');
    stack.push('C');
    cout << stack.pop() << '\n';   // C
    cout << stack.peek() << '\n';  // B

    stack.push('D');
    stack.printInfo();  // D B A

    return 0;
}
