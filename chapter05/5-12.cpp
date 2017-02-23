#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::noskipws;

int main()
{
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    unsigned spaceCnt = 0, tabCnt = 0, newlineCnt = 0;
    unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
    char ch, prech;
    while (cin >> noskipws >> ch)
    {
        switch (ch)
        {
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case 'e':
        case 'E':
            ++eCnt;
            break;
        case 'i':
            if (prech == 'f')
                ++fiCnt;
        case 'I':
            ++iCnt;
            break;
        case 'o':
        case 'O':
            ++oCnt;
            break;
        case 'u':
        case 'U':
            ++uCnt;
            break;
        case ' ':
            ++spaceCnt;
            break;
        case '\t':
            ++tabCnt;
            break;
        case '\n':
            ++newlineCnt;
            break;
        case 'f':
            if (prech == 'f')
                ++ffCnt;
            break;
        case 'l':
            if (prech == 'f')
                ++flCnt;
            break;
        }
        prech = ch;
    }
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n'
         << "Number of spaces: \t" << spaceCnt << '\n'
         << "Number of tabs: \t" << tabCnt << '\n'
         << "Number of newlines: \t" << newlineCnt << '\n'
         << "Number of ff: \t" << ffCnt << '\n'
         << "Number of fl: \t" << flCnt << '\n'
         << "Number of fi: \t" << fiCnt << endl;
    return 0;
}