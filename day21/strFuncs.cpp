#include <iostream>
#include <string>

using namespace std;

int main() {
    // Initialize a string
    string str = "hello world";
    string anotherStr = "HELLO";

    // 1. length() / size()
    cout << "Length of str: " << str.length() << "\n";

    // 2. empty()
    cout << "Is str empty? " << (str.empty() ? "Yes" : "No") << "\n";

    // 3. clear()
    anotherStr.clear();
    cout << "anotherStr after clear: '" << anotherStr << "'\n";

    // 4. operator[]
    cout << "First character of str: " << str[0] << "\n";

    // 5. append() / +=
    str += "!";
    cout << "str after append: " << str << "\n";

    // 6. substr()
    string sub = str.substr(0, 5);
    cout << "Substring of str: " << sub << "\n";

    // 7. find()
    size_t pos = str.find("world");
    cout << "Position of 'world' in str: " << pos << "\n";

    // 8. replace()
    str.replace(0, 5, "hi");
    cout << "str after replace: " << str << "\n";

    // 9. compare()
    int cmp = str.compare("hi world!");
    cout << "Comparing str with 'hi world!': " << (cmp == 0 ? "Equal" : "Not Equal") << "\n";

    // 10. c_str()
    const char* cstr = str.c_str();
    cout << "C-style string: " << cstr << "\n";

    // 11. push_back()
    str.push_back('?');
    cout << "str after push_back: " << str << "\n";

    // 12. pop_back()
    str.pop_back();
    cout << "str after pop_back: " << str << "\n";

    // 13. erase()
    str.erase(3, 4);
    cout << "str after erase: " << str << "\n";

    // 14. insert()
    str.insert(3, "lo");
    cout << "str after insert: " << str << "\n";

    // 15. at()
    char ch = str.at(1);
    cout << "Character at index 1: " << ch << "\n";

    // 16. rfind()
    pos = str.rfind("o");
    cout << "Last occurrence of 'o': " << pos << "\n";

    // 17. swap()
    string temp = "temporary";
    str.swap(temp);
    cout << "str after swap with 'temporary': " << str << "\n";
    cout << "temp after swap: " << temp << "\n";

    // Reset str for further operations
    str = "hello world";

    // 18. find_first_of()
    pos = str.find_first_of("aeiou");
    cout << "First vowel in str: " << pos << "\n";

    // 19. find_last_of()
    pos = str.find_last_of("aeiou");
    cout << "Last vowel in str: " << pos << "\n";

    // 20. find_first_not_of()
    pos = str.find_first_not_of("hello");
    cout << "First non-'hello' character in str: " << pos << "\n";

    // 21. find_last_not_of()
    pos = str.find_last_not_of("world!");
    cout << "Last non-'world!' character in str: " << pos << "\n";

    // 22. resize()
    str.resize(15, '*');
    cout << "str after resize: " << str << "\n";

    // 23. copy()
    char buffer[6];
    str.copy(buffer, 5, 0);
    buffer[5] = '\0';
    cout << "Copied substring: " << buffer << "\n";

    // 24. data()
    const char* dataPtr = str.data();
    cout << "Data pointer: " << dataPtr << "\n";

    // 25. shrink_to_fit()
    str.shrink_to_fit();
    cout << "str after shrink_to_fit: " << str << "\n";

    return 0;
}
