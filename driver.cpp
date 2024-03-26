#include <iostream>
#include <string>
#include "list.h"

using namespace std;

int main()
{
    string command;
    string input;

    LinkedList the_list;
    cout << "What do you want to do? ";
    cin >> command;
    while(command != "quit")
    {
        if(command == "inshead")
        {
            cout << "what do you want to put in to the list? ";
            cin >> input;
            the_list.insert_at_head(input);
        }
        else if (command == "instail")
        {
            cout << "what do you want to put in to the list? ";
            cin >> input;
            the_list.insert_at_tail(input);
        }
        else if (command == "inspos")
        {
            int pos;
            cout << "what do you want to put in to the list? ";
            cin >> input;
            cout << "where you do want to insert? ";
            cin >> pos;
            the_list.insert_at_position(input, pos);
        }
        else if (command == "rem")
        {
            int pos;
            cout << "where you do want to remove? ";
            cin >> pos;
            the_list.remove_from_position(pos);
        }

        the_list.display_list();
        cout << "What do you want to do? ";
        cin >> command;
    }

    return 0;
}