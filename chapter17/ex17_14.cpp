#include <regex>
#include <iostream>

using namespace std;

int main()
{
    try
    {
        regex r("[[:alnum:]] + \\.(cpp|cxx|cc$", regex::icase);
    }
    catch (regex_error e)
    {
        cout << e.what() << "\ncode: " << e.code() << endl;
    }

    return 0;
}