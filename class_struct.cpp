#include <iostream>
#include <string>

using namespace std;

/**
 * Objects!!!!
 * 
 * New data types that allow us to contain both functions [methods] 
 *  and data [variables]
 * In C++ there are three different ways to make such a thing
 * 
 * struct - cover this
 * class - cover this
 * union - nope :(
 * 
 * Objects also sometimes allow data protection.  Idea: some variables can be
 *  accessed from the outside of the object and some can't.
 *  Functions that can only be called from within the class.   
 * public = accessible outside of the class
 * protected = inaccessible
 * private = inaccessible

 * how do we make a struct?

    remember we are defining a type of object

        traditionally structs don't usually have methods... C++ allows it
    
    structures are by default public, but you can change things to private or protected
        using the private: or protected: keywords (they have colon after them)
*/

// forward declaration
struct EmptyThing;

struct Dog
{
    public:
    string name;
    string breed;
    string color;
    double weight;
    void bark() { cout << name << " says ruff" << endl; }
    void setID(int new_id)
    {
        id_tag = new_id;
        // all changes go through this, cannot change this variable without calling this function
    }
    int getID()
    {
        return id_tag;
    }
    private:
        int id_tag; // keep this secret and protected from outside programmers
};


struct Egg; // promise that we'll implement the Egg struct later
struct Chicken
{
    Egg * p_egg_array;
};

// the egg struct is an object
struct Egg 
{
    Chicken father; // member and an object
    Chicken mother; // member and an object
    double weight; // member but not an object itself
    Chicken hatch()
    {
        return Chicken();        
    }
};

void display_dog(Dog d)
{
    cout << "Name: " << d.name << ", Breed: " << d.breed << endl;
    cout << "\tColor: " << d.color << " which weighs " << d.weight << endl;
}


class Movie
{
    public:
        void Display(bool verbose = false)
        {
            cout << name << " directed by " << director << " in " << year << endl;
            if (verbose)
            {
                cout << "\t It cost $" << budget << " and is "  << endl;
                PrintLength();
                cout << endl;
            }
        }
        string GetName() { return name;}
        string GetDirector() {return director; }
        string GetGenre() {return genre; }
        
        // if you're writing a setter that may reject the new thing, maybe return a bool
        void SetName(string new_name)
        {
            name = new_name;
        }
        void SetDirector(string new_dir)
        {
            director = new_dir;
        }
        void SetGenre(string new_genre)
        {
            genre = new_genre;
        }

        int GetYear() { return year; }
        bool SetYear(int new_year)
        {
            if (new_year > 1900)
            {
                year = new_year;
                return true;
            }
            return false;
        }

        void  PrintLength()
        {
            cout << length / 3600 << " Hr. " << (length % 3600) / 60 << " minutes and " << length % 60 << " seconds.";  
        }

        int GetLength()
        {
            return length;
        }

        void SetLength(int new_time)
        {
            length = new_time;
        }


        int budget; // ignore the cents

    private:
        int length; // in seconds
        string name;
        string director;
        string genre;
        int year;

        int ConvertToYen()
        {
            return 150 * budget;
        }

};


int main()
{
    Dog pupper;
    pupper.name = "Pupper";
    pupper.breed = "pointer"; //?
    pupper.color = "oreo";
    pupper.weight = 40;

    Dog gracie;
    gracie.name = "Gracie";
    gracie.breed = "Black Lab";
    gracie.color = "Black";
    gracie.weight = 70;
    gracie.setID(77);
    cout << gracie.getID() << endl;

    display_dog(pupper);
    pupper.bark();

    display_dog(gracie);
    gracie.bark();

    Movie m;
    m.SetName("Lord of the Rings: Fellowship of the Ring");
    m.SetDirector("Peter Jackson");
    m.SetLength(2 * 3600 + 58 * 60 + 3);
    m.SetGenre("Fantasy Adventure");
    m.SetYear(2001);
    m.budget = 100000000;
    m.Display();

    m.Display(true);

    cout << sizeof(Movie) << " " << sizeof(string) <<  endl;


    Movie * p_movie = &m;

    //(*p_movie).budget = 231988643;
    p_movie->budget = 231988643;
    //*p_movie.Display();
    p_movie->Display();
    /**
     *  the arrow notation -> does the dereferencing and the data access or member
     *  function call in one step.  
    */
    Egg mr_egg;

    Egg * p_egg = &mr_egg;
    p_egg->weight = 3;
    
    return 0;
}