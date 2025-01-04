#include <iostream>
using namespace std;

class Example {
public:
    int x;
    void show() {
        cout << "Value of x: " << x << endl;
    }
};

int main() {
    Example obj;       // Regular object
    obj.x = 10;

    Example* ptr = &obj; // Pointer to the object

    // Access members using dereferencing
    (*ptr).x = 20;       // Dereference and use .
    (*ptr).show();

    // Access members using ->
    ptr->x = 30;         // Directly use ->
    ptr->show();
    cout<< &ptr;

    return 0;
}
