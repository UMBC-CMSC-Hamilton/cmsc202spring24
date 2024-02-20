#include <iostream>

using namespace std;

int main()
{
    /*
        char arrays will generally keep getting read until you see a null terminator
    */
    char hello[6] = "hello"; // always need one more for the null terminator
    char goodbye[8] = "goodbye";
    goodbye[7] = 'a'; 
    hello[5] = 'b';
    cout << (void *)hello << " " << (void *)goodbye << endl;

    cout << hello << " " << goodbye << endl;

    int n;
    cin >> n;
    //int my_array[n];
    // turn on -pedantic-errors and fail
    return 0;
}