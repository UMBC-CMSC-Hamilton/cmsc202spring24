#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
    Today we're going to talk about if, else if, else
    switch/case
    loops


*/

void spongebob()
{
        int x, y;
    cout << "Tell me an integer: ";
    cin >> x;
    cout << "Tell me another integer: ";
    cin >> y;

    if (x > 0 && y > 0)
    {
        cout << "both are positive" << endl;
    } 
    else if( x > 0 || y > 0)
    {
        cout << "one is positive" << endl;
    } 
    else
    {
        cout << "both are non-positive" << endl;
    }

    // keep the order of your if statements in mind, go from the most specific
    // to the more general to avoid catching certain results too early.

    string answer;
    cout << "Do you work at the Krusty Krab? ";
    cin >> answer;

    if (answer == "yes")
    {
        cout << "Do you own it? ";
        cin >> answer;
        if (answer == "yes")
            cout << "You are Mr. Krab" << endl;
        else{
            cout << "Are you very grumpy? ";
            cin >> answer;
            if (answer == "yes")
            {
                cout << "You are squidward" << endl;
            }
            else
            {
                cout << "You are spongebob" << endl;
            }
        }
    }
    else{
        cout << "Are you happy-go-lucky? ";
        cin >> answer;
        if (answer == "yes")
        {
            cout << "You are Patrick" << endl;
        }
        else
        {
            cout << "You are Sandy" << endl;
        }
    }
}

void switch_case()
{
    /*
        switch-case

        What is switch / case?
            A lot of times you'll end up with a bunch of options that are essentially
            numerical constants.
            if you have a lot of if/else if / else if/ else if/ else you can replace
                that with an switch case
            you must be testing value == 1 ,value == 2, value == 3
    */
    int option = 0;
    cout << "Enter the option between 1 and 5: ";
    cin >> option;

    switch (option)
    {
        case 1:
            cout << "hi 1" << endl;
            break;
        case 2:
            cout << "hi 2" << endl;
            break;
        case 3:
            cout << "hi 3" << endl;
            break;
        case 4:
            cout << "hi 4" << endl;
            break;
        case 5:
            cout << "hi 5" << endl;
            break;
        default:
            cout << "You didn't pick a menu item." << endl;
    }

    char input;
    cout << "Enter a letter: ";
    cin >> input;

    bool uppercase = false;

    switch(input)
    {
        case 'A':
            uppercase = true;
        case 'a':
            cout << "The letter a comes from the shape of an ox" << endl;
            break;
        case 'B':
            uppercase = true;
        case 'b':
            cout << "we know banana" << endl;
            break;
        case 'C':
        // without the break we're essentially adding a bunch of or statements 
            uppercase = true;
        case 'c':
            cout << "we know about cantelope" << endl;
            break;
        default:  // for the sake of your brain, keep this as the bottom one.
            cout << "what happens?" << endl;
            break; // only need this if it's at the top or in the middle
    }
    if (uppercase)
    {
        cout << "The letter was in uppercase" << endl;
    }

}

int main()
{
    // spongebob();
    // switch_case();

    /**
     * Three kinds of loops:
     *  for loops
     *  while loops
     *  do-while loops
    */
   /*
    for(initialization; boolean expression;)

        as long as the expression is true, the for loop keeps going
            as soon as it is false, it ends.

    for(int i = 0; i < 10; i++)

    if the variable exists already
    int count = 17;
    for(count = 0; )
   */
    for(int i = 0; i < 10; i++) 
    {
        cout << i << " ";
    }
    cout << endl;

    int count = 0;
    for(; count < 15; count += 3)
    {
        cout << count << " ";
    }
    
    cout << endl;
    int j = 0;
    for (; j < 10;)
    {
        cout << j << " ";
        j++;
    }
    cout << endl;

    j = 0;
    while (j < 10)
    {
        cout << j << " ";
        j++;
    }
    j = 0;
    // this is an infinite for loop, who knows why they chose this.
    /*
    for(;;)
    {
        cout << j << " ";
        j++;
    }
    */
   for(;;)
   {    cout << "enter 0 to exit: ";
        cin >> j;
        if (j == 0)
        {
            break;
        }
   }

    for (int even = 0, odds=1; even <= 100 || odds < 105; even += 2, odds += 2)
    {
        cout << even << " " << odds << " ";
        // odds += 2;
    }

    /*
        What is a do-while?
            do {block} while(condition);
            do this block of code once
            then it checks the condition at the end.
            notice the semi-colon
    */
    int x = 100;
    do {
        cout << "Enter a positive number: ";
        cin >> x;
    } while( x <= 0);

    return 0;
}