#include <iostream>
#include <string>

using namespace std;

void pass_array(int ** array)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}


int sum_the_array(int array[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += array[i];
    }
    return total;
}

int main()
{
    /*
        when you declare an array it has to have a fixed size.
        this is not like lists in python, no such thing as append
    */

    int my_array[5] = {1, 7, 43, 92, -20};
    for(int i = 0; i < 5; i++)
    {
        cout << my_array[i] << ", ";
    }

    cout << endl;

    cout << sum_the_array(my_array, 5) << endl;

    cout << my_array[17] << endl;

    char hello[6] = "hello";

    char another_string[12] = {'p', 'o', 'r', 't', 'c', 'u', 'l', 'l', 'i', 's', 's', 'x'} ;
    char another_yet_string[7] = "happye";

    *(another_string - 1) = 'a';

    // another_string[12] = 'a';
    // another_string[13] = 'a';
    // another_string[14] = 'b';

    cout << hello << endl;
    cout << another_string << endl;
    cout << (void *)hello << " " << (void *)another_string  << (void *)another_yet_string <<  endl;

    hello[6] = 'a';
    cout << hello << endl;

    char my_big_string[1000] = "something big but not that big";
    cout << my_big_string << endl;


    char first_string[32];
    char second_string[32];

    cin >> first_string;
    cin >> second_string;

    cout << first_string << " " << second_string << endl;

    /*
        The number of elements in an array MUST be constant
    */
    const int length = 17;
    // cout << "tell me how long you want the array to be: ";
    int my_special_array[length];
    // more research into that...
    my_special_array[length / 2] = 14;

    /*
        Multidimensional array
    */

    int grid[3][2] = {{1, 2}, {5, 8}, {3, 7}};

    cout << grid[2][1] << " " <<  grid[0][1] << endl;
    pass_array((int **)grid);
    return 0;
}