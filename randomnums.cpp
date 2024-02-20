#include<iostream>
#include<cstdlib>
#include<random>
#include<windows.h>

using namespace std;

int main()
{  
    // let me explain
    // srand is the seed function for the random number generator.  
    // I will figure out what is the correct time library
    cout << GetTickCount() << endl;
    // you will use time, not this.  
    srand(GetTickCount());
    int the_seed;
    // cin >> the_seed;
    // srand(the_seed);
    for (int i = 0; i < 20; i++)
    {
        cout << rand() << " ";
    }
    cout << endl;

    for (int i = 0; i < 20; i++)
    {
        cout << (rand() % 10) + 1 << " ";
    }
    cout << endl;
    // we want numbers between 101 and 150
    for (int i = 0; i < 20; i++)
    {
        cout << (rand() % 50) + 101 << " ";
    }
    cout << endl;
    // we want numbers between 100 and 150 (inclusive of both endpoints)
    for (int i = 0; i < 20; i++)
    {
        cout << (rand() % 51) + 100 << " ";
    }

    unsigned int big_rand = 32768 * rand() + rand();
    cout << big_rand << endl;
    big_rand = rand() << 16 + rand();
    cout << big_rand << endl;
    /**
     * 
     * 101 << 1
     * 1010
     * 110 << 2
     * 11000b = 24d
    */

    unsigned int happy = 0;
    happy--;
    cout << happy << endl;

    unsigned long really_happy = 0;
    really_happy --;
    cout << really_happy << endl;

    unsigned int five = 5;
    cout << five * -1 <<  endl;
    five *= -1;
    cout << five << endl;

    if (five < -2)
    {
        cout << "hi" << endl;
    }
    /**
     *  when we get to vectors, remember that .size() gives an unsigned answer
     * 
    */
    return 0;
}