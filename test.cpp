/**
 * You can make a decision, either you can install msvc++
 * 
 *      my recommendation: install visual studio community NOT VS CODE
 *      should come with the msvc++ compiler which should compile your code
 * 
 * or you can install g++
 *      https://github.com/niXman/mingw-builds-binaries/releases
 *      download x86_64-13.2.0-release-win32-seh-ucrt-rt_v11-rev0.7z
 *      download 7zip
 * 
 *      open C:\ and drag-drop from 7zip to create a mingw64 folder.
 * 
 *      Then you have to decide on an IDE:
 *          Eclipse C++ - i kinda like
 *          VS Code - i haven't been able to get to work for others???
 *          Code::Blocks
 * 
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void print_stuff()
{
       cout << "hi" << endl;

    /**
     * How do you output and input?
     *  output : cout
     *  input :  cin
     *  remember that it uses the bitshift operator in order to do cout and cin
    */
    int x = 2;
    cout << x << " " << 17 << " hello " << endl;

    char c;
    cout << "Enter a character, not a string: " << endl;
    cin >> c;

    string my_string;
    cout << "Now input a string: ";
    cin >> my_string;

    cout << my_string << " " << c << endl;
    // getline(cin, my_string);
    // cout << my_string << endl;
    double pi = 3.14159265358979;

    double other = 439.212312313123;
    double random = 3.2;
    // setprecision(number of digits) not just decimal digits
    // set precision also latches on, set it once and then it'll stay
    // only have to reset it if you need to later.
    cout << setprecision(10) << pi  << " " << other << " " << random << endl;
    /*
        fill works basically as you expect
            fill latches on, when you set it, you only have to do it once
    */
    cout.fill('0');
    // set width is different, you must set it before each print. 
    cout << setw(5) << "abc" << setw(5) << "7" << endl;

    cout.fill('&');

    cout << setw(10) << "hello" << endl;
    /**
     * Remember to include endlines, forces the OS to clear the output buffer.  
     * 
    cout<< "this is definitely going to print";
    // crash
    int * p = 0;
    *p = 4;
    cout << "yep that crashed" << endl;
    */
}

int main()
{
    /*
        if statements and conditions

    */
   //print_stuff();
   cout << "program starting" << endl;
    int x = -3;
    if (x > 0)
    {
        cout << "X is positive" << endl;
        cout << "x is very positive" << endl;
    }

    int y = 2;
    int z = 5;
    // or syntax
    if (y > 4 || z > 4)
    {
        cout << "one of them is bigger than 4"<< endl;
    }
    // the and syntax
    if( x > 1 && y > 1)
    {
        cout << "yep they are both bigger than 1" << endl;
    }

    int t = 0;
    // not syntax, remember that an expression is true if it is not zero, empty string.
    if (!t)
    {
        cout << "not t is true" << endl;
    }
    if (t)
    {
        cout << "does this evaluate?" << endl;
    }

    if (t)
    {   // post-fix is because they occur after the variable
        // t = t + 1;
        t ++;
    }
    else
    {
        // t = t - 1;
        t--;
    }
    cout << t << endl;
    int s = 14;
    
    cout << ++s << endl;
    cout << s << endl;

    int number;
    cout << "Tell me a number between 1 and 5 ";
    cin >> number;
    
    if(number == 1)
        cout << "x is 1, 1 is a lonely number" << endl;
    else if (number == 2)
        cout << "you have a friend you see?" << endl;
    else if (number == 3) 
    {
        cout << "definitely a crowd" << endl; 
        number *= 2;
    }
    else if (number == 4)
        cout << "you are not prime" << endl;
    else if (number == 5)
        cout << "too much, way too much " << endl;
    else {
        cout << "this is not in range" << endl;
    }
    return 0;
}