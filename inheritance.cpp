#include <iostream>
using namespace std;

/**
 * private variables exist but are not accessible in child clases
 * Use the setters and getters or use protected instead
 * Generally you declare the inherited class as public because you want the public things to stay public, if you dont' you can declare it private, you can also declare things as protected
 * constructors are called from top down
 * destructors are called from bottom up
 * models an "is a relation"
 */
class Vehicle
{
	public:
		Vehicle()
		{
			cout << "In vehicle constructor" << endl;			
		}
		
		~Vehicle()
		{
		    cout << "calling vehicle destr." << endl;
		}

		int GetSerial() {return m_serial;}
		float GetMaxSpeed() {return m_max_speed; }
		void SetMaxSpeed(float new_max) {m_max_speed = new_max; }
	    void SetSerial(int new_serial) {m_serial = new_serial;}
    /*
        use protected instead of private
        in parent classes
    */
	protected:
		int m_serial;
		float m_max_speed;
};

class Car : public Vehicle
{
	public:
	    Car() { cout << "In car constr." << endl; 
	        SetSerial(777);
	        
	    }
	    ~Car()
	    {
	        cout << "in car destructor" << endl;
	    }
		bool IsSedan() {return m_sedan;}
		void SetSedan(bool is_a_sedan) {m_sedan = is_a_sedan; }
		bool HasSunroof() {return m_sunroof;}
		void SetSunroof(bool has_roof) {m_sunroof = has_roof; }
		int GetGarbage() {return garbage;}
	private:
	    int garbage;
		bool m_sedan;
		bool m_sunroof;
};

class SuperCool
{
    public:
    SuperCool()
    {
        cout << "Man it is cool" << endl;
    }
};

class Hatchback : protected SuperCool, public Car
{
    public:
        Hatchback()
        {
            cout << "in hatchback constructor" << endl;
        }
        ~Hatchback()
        {
            cout << "in hatchback destr." << endl;
        }
};

class Truck : public Vehicle
{
	public:
	    Truck() { cout << "In truck constr." << endl; }
	    ~Truck() {cout << "destroying a truck" << endl;}
		int GetCargoCap() {return m_cap;}
		void SetCargoCap(int new_cap) {m_cap = new_cap;}
	private:
		int m_cap;
};

void SetVehicleCargo(Vehicle * pv)
{
    ((Truck *)pv)->SetCargoCap(500);
}

int main()
{
    //Vehicle v;
    Car c;
    Truck t;
    Hatchback h;
    
    c.SetSedan(true);
    c.SetSerial(1234);
    cout << c.GetSerial() << " " << c.IsSedan() << endl;
    
    SetVehicleCargo(&t);
    SetVehicleCargo(&c);
    cout << c.GetGarbage() << endl;
    return 0;
}
