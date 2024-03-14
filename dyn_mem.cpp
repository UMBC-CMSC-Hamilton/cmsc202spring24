#include <iostream>
#include <string>
using namespace std;

/***
 * Dynamic Memory 
 * 
 * when you create an array you specify the number or elements in the array
 *  that number cannot change
 *  that number must be determined at COMPILE time.  (vs Runtime.)
 * 
 * vectors are a solution to this [a vector is a class that uses dynamic memory]
 * 
 * memory that is not dynamic is allocated from the "stack"
 * dynamic memory is allocated from the "heap"
 * |----stack memory -----|----heap memory----------------------------------|
 * 
 * How do we do this?
 *  two keywords that help us out. 
 *      new
 *      delete
*/


struct Place {
    string name;
    int rent;
};

class GameClass
{
    public:
        GameClass(int size)
            : m_size(size)
        {
            m_places = new Place[m_size];
            // set all the places to the correct names and rents
        }

        void RunGame()
        {}
        
        ~GameClass()
        {
            // when this gets called the class is basically "leaving scope"
            // or the program is ending
            delete [] m_places;
        }

    private:
        int m_size;
        Place * m_places;
};

void blah()
{
    cout << "hi again" << endl;
}

struct MissStruct
{
    MissStruct(int lx, int ly)
        : x(lx), y(ly)
    {}
    int x;
    int y;
    double z;
    char t;
};

int main()
{
    std::cout << "hi" << std::endl;
    cout << "now we don't have to use the namespace every time" << endl;

    int x;
    cout << "Enter a length of the array that you want: ";
    cin >> x;

    int * p_array = new int[x];

    for (int i = 0; i < x; i++)
    {
        cout << "Enter value for position " << i + 1 << ": ";
        cin >> p_array[i];
    }

    for (int i = 0; i < x; i++)
    {
        cout << p_array[i] << " ";
    }
    cout << endl;

    delete [] p_array;
    p_array = nullptr;
    // prevents us from accidentally using this memory again
    /*
    for (int i = 0; i < x; i++)
    {
        cout << p_array[i] << " ";
    }
    cout << endl;
    */
    
    int * mr_pointer = new int(3); // parentheses are basically a constructor
    cout << *mr_pointer << endl;
    
    delete mr_pointer;
    mr_pointer = nullptr;

    double * mr_double = new double(3.14);
    cout << *mr_double << endl;
    delete mr_double;
    // double delete doesn't harm you but also doesn't do anything
    // delete mr_double;

    MissStruct * p_struct = new MissStruct(7, 11);

    cout << p_struct->x << " " << p_struct->y << endl;

    delete p_struct;

    int testx = p_struct->x;
    int testy = p_struct->y;
    cout << testx << " " << testy << endl;

    return 0;
}