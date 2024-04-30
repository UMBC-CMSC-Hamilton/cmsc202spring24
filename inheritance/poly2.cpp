#include <iostream>
using namespace std;

// can't declare a Parent directly anymore.  
class Parent
{
    public:
        // pure functions make the class abstract
        // if there's no pure function the class is NOT abstract
        virtual void doSomething() = 0;
        int getRandomNumber(int x)
        {
            return x + 1;
        }
    private:
};

class Child : public Parent
{
    public:
        virtual void doSomething()
        {   
            cout << "I am a kid" << endl;
        }
        // overriding because this one gets 
        // called, much harder to access the parent function
        int getRandomNumber(int x)
        {
            Parent::getRandomNumber(x); // this might work, might explode
        }
        // no overriding going on at all
        // just overloading
        double getRandomNumber(double x)
        {
            return 3.2;
        }
    private:
};