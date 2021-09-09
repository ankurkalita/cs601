
#include <iostream>
#include <stack>
using namespace std;
 
class Stack
{
    stack<int> s;       // main stack to store elements
    stack<int> aux;     // auxiliary stack to store minimum elements
 
public:
    // Inserts a given element on top of the stack
    void push(int x)
    {
        // push the given element into the main stack
        s.push(x);
 
        // if the auxiliary stack is empty, push the given element into it
        if (aux.empty()) {
            aux.push(x);
        }
        else {
            // push the given element into the auxiliary stack
            // if it is less than or equal to the current minimum
            if (aux.top() >= x) {
                aux.push(x);
            }
        }
    }
 
    // Removes the top element from the stack and returns it
    int pop()
    {
        if (empty())
        {
            cout << "Stack underflow!!" << endl;
            return -1;
        }
 
        // remove the top element from the main stack
        int top = s.top();
        s.pop();
 
        // remove the top element from the auxiliary stack
        // only if it is minimum
        if (top == aux.top()) {
            aux.pop();
        }
 
        // return the removed element
        return top;
    }
 
    // Returns the top element of the stack
    int top() {
        return s.top();
    }
 
    // Returns the total number of elements in the stack
    int size() {
        return s.size();
    }
 
    // Returns the true if the stack is empty; false otherwise
    bool empty() {
        return s.empty();
    }
 
    // Returns the minimum element from the stack in constant time
    int min()
    {
        if (aux.empty())
        {
            cout << "Stack underflow!! ";
            return -1;
        }
 
        return aux.top();
    }
};
 
int main()
{
    Stack s;
    
    cout << "Push 6" << endl;
    s.push(6);
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Push 7" << endl;
    s.push(7);
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Push 8" << endl;
    s.push(8);
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Push 5" << endl;
    s.push(5);
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Push 3" << endl;
    s.push(3);
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Pop" << endl;
    s.pop();
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Push 10" << endl;
    s.push(10);
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Pop" << endl;
    s.pop();
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    cout << "Pop" << endl;
    s.pop();
    cout << "Current Min:" << s.min() << endl;    // prints 6
 
    return 0;
}