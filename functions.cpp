#include <iostream>
#include <string>

using namespace std;


bool is_prime(unsigned int test);
int add_three(int x, int y, int z)
{
    return x + y + z;
}

int main()
{

    return 0;
}

bool is_prime(unsigned int test)
{
    for (int i = 2; i < test; i++)
    {
        if(test %  i == 0)
        {
            return false;
        }
    }
    return true;
}