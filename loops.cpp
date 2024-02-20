#include <iostream>
#include <string>
using namespace std;

int main()
{
    int j = 0;
    for (int i = 1; i <= 10; i++)
        cout << i << " ";
    
    j++;
    cout << j << endl;
    
    string something;
    cout << "Enter quit to stop: ";
    cin >> something;
    while(something != "quit")
    {
        cout << "You have not quit yet." << endl;
        cin >> something;
    }

    do
    {
        cout << "Enter quit to stop: ";
        cin >> something;
    } while(something != "quit");

    /**
     *  Totally C++ legal
     *      Misses the idea of what a while loop is
    */
    while(true)
    {
        cout << "Enter quit to exit." << endl;
        cin >> something;
        if (something == "quit")
            break;
    }

    /*
        
        continue keyword
    */
   int total = 0;
   for (int i = 0; i < 10; i++)
   {
        if (i % 2)
        {
            continue;
        }
        total += i;
   }
   cout << "The total is: " << total << endl;

    cin >> something;
    cout << "The cin is done" << endl;
    while(something != "exit")
    {
        cout << " The something is: " << something << endl;
        if (something.empty())
        {
            cout << "That was empty" << endl;
            cin >> something;
            continue;
        }
        
        if (something[0] == 'a')
        {
            cout << "A is a vowel" << endl;
        }
        else if (something[0] == 'b')
        {
            cout << "B is a consonant" << endl;
        }
        cin >> something;
    }

    return 0;
}
