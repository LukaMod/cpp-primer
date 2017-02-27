#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::endl;

int main()
{
    vector<int> v1;
    cout << "v1: "
         << "size: " << v1.size() << " {";
    for (auto it = v1.cbegin(); it != v1.cend(); ++it)
        cout << *it << ",";
    cout << "}" << endl;

    vector<int> v2(10);
    cout << "v2: "
         << "size: " << v2.size() << " {";
    for (auto it = v2.cbegin(); it != v2.cend(); ++it)
        cout << *it << ",";
    cout << "}" << endl;

    vector<int> v3(10, 42);
    cout << "v3: "
         << "size: " << v3.size() << " {";
    for (auto it = v3.cbegin(); it != v3.cend(); ++it)
        cout << *it << ",";
    cout << "}" << endl;

    vector<int> v4{10};
    cout << "v4: "
         << "size: " << v4.size() << " {";
    for (auto it = v4.cbegin(); it != v4.cend(); ++it)
        cout << *it << ",";
    cout << "}" << endl;

    vector<int> v5{10, 42};
    cout << "v5: "
         << "size: " << v5.size() << " {";
    for (auto it = v5.cbegin(); it != v5.cend(); ++it)
        cout << *it << ",";
    cout << "}" << endl;

    vector<string> v6{10};
    cout << "v6: "
         << "size: " << v6.size() << " {";
    for (auto it = v6.cbegin(); it != v6.cend(); ++it)
        cout << *it << ",";
    cout << "}" << endl;

    vector<string> v7{10, "hi"};
    cout << "v7: "
         << "size: " << v7.size() << " {";
    for (auto it = v7.cbegin(); it != v7.cend(); ++it)
        cout << *it << ",";
    cout << "}" << endl;

    return 0;
}