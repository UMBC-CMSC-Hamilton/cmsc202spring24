#include <iostream>
#include <string>

using namespace std;

int I_am_global = 3;



// add 7 to each number
void add_to_numbers(int * px, int * py, int * pz)
{
    *px += 7;
    *py += 7;
    *pz += 7;
}

#define NUM_THINGS 5

void LoadFiveThings(string five_things_array[NUM_THINGS])
{
    for(int i = 0; i < NUM_THINGS; i++)
    {
        cout << "tell me a thing ";
        cin >> five_things_array[i];
    }
}

int * get_array()
{
    int my_array[NUM_THINGS];
    for (int i =0; i < NUM_THINGS; i++)
    {
        my_array[i] = 2 * i + 7;
    }
    return my_array;
}

int main()
{
    int x = 2, y = 4, z = 12;
    add_to_numbers(&x, &y, &z);
    cout << x << " " << y << " " << z << endl;
    /*
        What is a pointer?
            it's a variable that instead of having a value like int, float, char 
                string, it has a memory location

            What is a memory location?
                A memory location is just a number.
                On a 64 bit system a memory location is a "long"
                Why did we make the transition from :
                8 bits to 16 bits to 32 bits to 64 bits?
                    will we go to 128 bits soon? probably not
    */

    x = 5;
    // declare a pointer (we have a memory address, whose contents are an int)
    // & = reference operator what it does is gets the address of the thing
    // * = dereference operator = get the value at that address
    int * p_to_x = &x;

    cout << "The address of x is " << &x << endl;
    cout << "The VALUE of p_to_x is " << p_to_x << endl;

    *p_to_x = 7;
    cout << "The new value of x is: " << x << endl;

    char hello[] = "hello";

    char * p_letter = (char *)hello;

    for (int i = 0; i < 5; i++)
    {
        cout << (void * )(p_letter + i) << " " << *(p_letter + i) << endl;
    }

    int my_int_array[] = {3, 19, 21, 27, 55, 0, 1};

    for (int j = 0; j < 7; j++)
    {
        cout << (void * )(my_int_array + j) << " " << *(my_int_array + j) << endl;
    }

    cout << sizeof(float) << " " << sizeof(int) << " " << sizeof(long) << " " << sizeof(char) << " " << sizeof(wchar_t) << endl;

    string names[NUM_THINGS];
    LoadFiveThings(names);

    for (int k = 0; k< NUM_THINGS; k++)
    {
        cout << names[k] << endl;
    }
    /*
    int * result = get_array();
    for (int i = 0; i < NUM_THINGS; i++)
    {
        cout << result[i] << endl;
    }
    */
    int * pointer = nullptr;
    cout << pointer << endl;

    *pointer = 7;

    /**
     * For safety we set pointers who are not yet set to nullptr
     * 
    */
   int * something = nullptr;

   if (something != nullptr)
   {}

   if (something)
   {}

   string blah[24][2];

    return 0;
}