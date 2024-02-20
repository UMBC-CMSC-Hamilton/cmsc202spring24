#include <iostream>
#include <string>
#include <vector>
using namespace std;

void change_ints(int x, int & y)
{
    x += 5;
    y += 7;
    cout << x << " "<< y << endl;
}

// no reference on the array, but somehow it changed... how did that happen?
void change_array(int array[10])
{
    for (int i = 0; i < 10; i++)
    {
        cout << "What should we put in array[" << i << "]"; 
        cin >> array[i];
    }
}

void pointer_change(int * fake_array)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "What should we put in array[" << i << "]"; 
        cin >> *(fake_array + i);
    }
}
/*
    Show you that it will force convert into integer.  
double add(double x, double y)
{
    return x + y;// original add of integers
}
*/
/* evil don't do 
double add(int x, double y)
{
    cout << "did you call me?" << endl;
    return double(x) + y;// original add of integers
}
*/

int add(int x, int y)
{
    return x + y;// original add of integers
}

string add(string x, string y)
{
    return x + y; // string concatenation thing
}


void reference_examples();

// all by reference
void get_name_password(string & name, string & password, string & quest)
{
    cout << "What is your name?";
    cin >> name;

    cout << "What is your password: ";
    cin >> password;

    cout << "What is your quest: ";
    cin >> quest;
}

class BlahClass
{};

vector<string> split(string sentence, char split_char = ' ')
{
    vector<string> split_words;
    unsigned int prev_start = 0;
    for(unsigned int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == split_char)
        {
            split_words.push_back(sentence.substr(prev_start, i - prev_start + 1));
            prev_start = i;
        }
    }
    if (prev_start != sentence.length() - 1)
    {
        split_words.push_back(sentence.substr(prev_start, sentence.length() - prev_start + 1));
    }
    return split_words;
}

// after a default argument all other arguments must be default
int test_defaults(int x, int y = 2, int z = 3)
{
    return 0;
    //Question what happens with this: test_defaults(3, 5);
    // answer: x = 3, y = 5, z = 3(default)
    //test_defaults(7) --> x = 7, y = 2, z = 3 
    // print('asdf', end='hi')
    // open('filename.txt', mode = 'r') example of a default argument
}


int main()
{
    /*
        What is a pointer?
            A pointer is a variable that contains memory address

            & = reference operator which gets us the memory location of a variable
            * = dereference operator which gets us the value of the variable.  
    */
    int t = 15;
    int s = 23;
    int * pt = &t, *ps = &s; // needs *ps not just ps because that is just an integer
    cout << ps << s;
    *pt += 7;
    cout << *pt << " " << t << " " << pt << " " << &t << endl;

    /*
        Pass by value vs pass by reference
            pass by value = local variable is a copy of the global or other function variable
                local variable can change but the original variable doesn't

            pass by refererence - local variable is not a copy but actually is 
                a renaming of the other variable
                if you change the local variable the other[global, or other local]
                variable will also change.  

        Function Overloading
            overloading = using something with the same name or symbol to do multiple things
            use sparingly 

        Default Arguments
            what if you don't want to always have to enter an argument?
            split(string, char)

        def some_function(my_int, my_list)

        void some_function(int my_int, int & my_list[])
    */
    int a = 3, b = 17;
    cout << add(a, b) << endl;
    string hello = "hello", robots = "robots";
    cout << add(hello, robots) << endl;
    double dx = 15.2, dy = 22.7;
    cout << add(dx, dy) << endl;
    /*
    BlahClass bc1, bc2;
    add(bc1, bc2);
    */

    vector<string> result;
    result = split("hello there we are a string", ' ');
    for(unsigned int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    result = split("here is another string to break up");
    for(unsigned int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }


    result = split("in.this.case.we.use.periods", '.');
    for(unsigned int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}

void reference_examples()
{

   int x = 2, y = 4;
   change_ints(x, y);
   cout << x << " " << y << endl;

    int my_array[10] = {2, 5, 3, 1, 9}; // fill it with zeros
    string my_solutions[24];

    for (int j = 0; j < 10; j++)
    {
        cout << my_array[j] << ", ";
    }
    cout << endl;
    pointer_change(my_array);
    for (int j = 0; j < 10; j++)
    {
        cout << my_array[j] << ", ";
    }
    cout << endl;

    string nm, pw = "pw1", qst = "find the holy grail";
    get_name_password(nm, pw, qst);
    cout << nm << " : " << pw << " : " << qst;
}