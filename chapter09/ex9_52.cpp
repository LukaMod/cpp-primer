#include <stack>
#include <string>
#include <iostream>
using std::stack;
using std::string;
using std::cout;
using std::endl;

int main()
{
    const string &expr = "(Age) is ((a very high (price)) to (pay) for) maturity";
    int lbracket = 0;
    char sign = '#';
    stack<char> st;
    for (const auto &c : expr)
    {
        st.push(c);
        if (c == '(')
            ++lbracket;
        if (lbracket && c == ')')
        {
            while (st.top() != '(')
                st.pop();
            st.pop();
            st.push(sign);
            --lbracket;
        }
    }
    string output;
    while (!st.empty())
    {
        output.insert(output.begin(), st.top());
        st.pop();
    }
    cout << output << endl;

    return 0;
}