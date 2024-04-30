#include <iostream>
using namespace std;

union HighAndLow
{
    struct{
        short low;
        short hi;
    };
    int total;
};

union AsciiConverter
{
    char the_letter;
    int x;
};

int main()
{
    HighAndLow hl;
    hl.total = 0;
    hl.low = 12346;
    cout << hl.total << endl; 
    AsciiConverter a;
    a.x = 65;
    cout << a.the_letter << endl;
    return 0;
}