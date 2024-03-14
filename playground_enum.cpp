#include <iostream>
#include <string>

using namespace std;

/*
    an enum is a way to define a bunch of constants together
*/

enum seasons {WINTER, SPRING, SUMMER, FALL};
enum DaysOfWeek {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};
enum Garbage{COOL = 17, SUPER = 1729, HAPPY = 42};

// you might see this sometimes
// typedef enum Thing{A = 2, B= 7, C = 12};

typedef int * pint;

void what_is_happiness()
{
    cout << HAPPY << endl;
}

/// 
/// @param argc traditionally these names are used 
/// @param argv 
/// @return 
int main(int argc, char ** argv)
{
    
    for(int i = 0; i < argc; i++)
    {
        cout << argv[i] << " :: ";
    }
    cout << endl;

    cout << int(WINTER) << " " << int(SUMMER) << endl;
    cout << MONDAY << " " << WEDNESDAY << " " << FRIDAY <<endl;
    cout << HAPPY << " " << SUPER << " " << COOL <<endl;

    DaysOfWeek x = MONDAY;
    cout << x << endl;

    pint something;
    const int HAPPY = 17;
    cout << HAPPY << endl;

    what_is_happiness();
    int day;
    cin >> day;

    switch (day)
    {
        case MONDAY:
            cout << "morning feels so bad, everyone seems to nag me" << endl;
            break;
        case TUESDAY:
            cout << "i feel better" << endl;
            break;
        case WEDNESDAY:
            cout << "Terrible but maybe survivable" << endl;
            break;
        case THURSDAY:
            cout << "almost friday" << endl;
            break;
        case FRIDAY:
            cout<< "I got friday on my mind" << endl;
            break;
        case SATURDAY:
            cout << "sleep half of day" << endl;
            break;
        case SUNDAY:
            cout << "Monday night letdown" << endl;
            break;
        default:
            cout << "I don't think that was right..." << endl;
    }

    return 0;
}