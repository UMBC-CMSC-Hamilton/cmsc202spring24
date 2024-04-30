/**
 * Polymorphism is a greek neologism from biology
 * 
 * Poly = many
 * morph = form
 * something can have many forms
 * 
*/

#include <iostream>
#include <string>
#include <vector>

#define PURE = 0 

using namespace std;

// overloading function names is a form of polymorphism
int multiply(int x, int y) { return 1;} 
int multiply(double x, double y) {return x * y;}

class Animal
{
    public:
        Animal()
            : bark_string("squeak")
        {}
        string type()
        {
            return m_type;
        }
        void fight(Animal & other_thing)
        {
            cout << m_type << " is fighting " << other_thing.m_type << endl;
        }
        // this is a promise that the child classes will implement this function
        // we don't actually implement it... 
        // abstract base class (you can't actually declare one)
                            // makes this pure, says this function will NOT be 
                            // implemented
        virtual void bark() = 0;
    protected:
        string bark_string;
        string m_type;
};

class Dog : public Animal
{
    public:
        Dog()
        {
            m_type = "dog";
        }
        virtual void bark()
        {
            cout << "Bark Bark" << endl;
        }

        void fetch(string thing)
        {
            cout << "The dog has fetched " << thing << endl;
        }
    private:
};

class Chicken : public Animal
{
    public:
        Chicken() {
            m_type = "Chicken";
        }
        virtual void bark()
        {
            cout << "Bwwaakkk" << endl;
        }
    private:
};

class Cat : public Animal // it doesn't have a bark so it calls the animal version
{
    public:
        Cat() {
            m_type ="Cat";
            bark_string = "purrrrrrrrr";
        }
        virtual void bark()
        {
            cout << "meow"<< endl;
        }
    private:
};

class Parent
{   
    public:
        virtual ~Parent() {}
        virtual void blah() {};
};

/*
    Why do you want constructors to be virtual?
        if you only ever want one constructor to run
        if you're doing something that would be duplicated
    Why would you NOT want constructors as virtual?
        If you rely on the parent's constructor to set variables that are stored
        in the parent.  

    Use virtual on destructors to prevent parent class from deallocating your memory.
        Especially if you're freeing memory.

*/

class Child: public Parent
{
    public: 
    int x;
};

int main()
{

    cout << sizeof(Parent) << " " << sizeof(Child) << endl;
    Dog d;
    Cat c;
    d.bark();
    c.bark();

    //cout << (void *)Animal::bark << " " << (void *)Dog::bark << endl;

    cout << endl;
    vector<Animal *> animal_list;
    animal_list.push_back(new Dog());
    animal_list.push_back(new Dog());
    animal_list.push_back(new Chicken());
    animal_list.push_back(new Chicken());
    animal_list.push_back(new Cat());
    animal_list.push_back(new Cat());
    animal_list.push_back(new Chicken());

    animal_list[3]->fight(*animal_list[5]);
    animal_list[0]->fight(*animal_list[4]);

    for (unsigned i = 0; i < animal_list.size(); i++)
    {
        animal_list[i]->bark();
    }

    // avoids a memory leak
    for (unsigned i = 0; i < animal_list.size(); i++)
    {
        delete animal_list[i];
    }

    return 0;
}