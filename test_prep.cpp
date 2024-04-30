#include <iostream>

using namespace std;

double divide(int x, int y = 5)
{
    if (y == 0)
        return 0;
    return double(x) / y;
}

void absoluteValue(int * p_int)
{
    if (*p_int < 0)
    {
        *p_int *= -1;
    }
}

void no_excuses()
{
    int input;
    cin >> input;
    absoluteValue(&input);
    cout << input << endl;
}

void what_they_want(int & x, int & y)
{
    for(int i = 1; i <= y; i++)
    {
        cout << (i) * x << " ";
    }
    cout << endl;
}

class Table
{

    public:
        int getlength();
        void setlength(int new_len);
        int getwidth();
        void setwidth(int new_len);
        
        string getName();
        void set
    private:
        string name;
        string material;
        int length;
        int width;
};

void blah(int & x, int & y)
// pre-condition: x is six, y is a number of times we will iterate??
// post-condition: x and y are unchanged and the values are printed
{
    cout << 6 << 12 << 18 << 24;
}

int main()
{
    cout << divide(7, 2) << endl;
    return 0;
}