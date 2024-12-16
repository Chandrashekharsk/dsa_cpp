// MultiSet - (sorted, non-uniqueValues)
#include <iostream>
#include <set>
using namespace std;


int main() {
    multiset<int> ms;

    ms.insert(10);
    ms.insert(10);  
    ms.insert(10);  
    ms.insert(20);
    ms.insert(30);

    for (int i : ms) {
      cout << i << " ";
    }
    cout << endl;

    cout << "Count of 10 in multiset: " << ms.count(10) << endl;

    // Find an element in the multiset
    auto it = ms.find(20);
    if (it != ms.end()) {
      cout << "Element 20 found!" << endl;
    }

    // Erase one occurrence of an element
    ms.erase(ms.find(10));

    // Print elements after erasing one occurrence of 10
    for (int elem : ms) {
      cout << elem << " ";
    }
    cout << endl;

    // Erase all occurrences of 10
    ms.erase(10);

    for (int elem : ms) {
      cout << elem << " ";
    }
    cout << endl;

    return 0;
}
