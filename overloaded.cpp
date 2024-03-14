#include <iostream>
#include <string>
#include <math.h>
using namespace std;


/*
    arithmetic operators
        + - * / % +=, -=, *= /=, %=
    bitwise operators
        & | ^ (bitwise xor)
        << bitshifts! >>
          0101
        & 1100
          0100  

        ^ 0110001110
          1100101011
          1010100101 (only one can be on at a time)
*/

class Money
{
    public:
        Money(int dollars = 0, int cents = 0);
        int getDollars() const {return m_dollars;}
        int getCents() const {return m_cents;}
        void setDollars(int new_dollars)
        {
            m_dollars = new_dollars;
        }
        Money operator + (const Money & other);
        Money & operator += (float m);
        Money & operator -= (int dollars);

        Money & operator ^ (int times);
    private:
        int m_dollars;
        int m_cents;
};

Money::Money(int dollars, int cents)
{
    m_dollars = dollars;
    m_cents = cents;
}


Money & Money::operator ^ (int times)
{
    float current = m_dollars + float(m_cents) / 100.0;
    current = pow(current, times);
    m_dollars = int(current);
    m_cents = int(current * 100) % 100;
    return *this;
}


Money & Money::operator += (float m)
{
    int dollars = int(m);
    int cents = int((m * 100)) % 100;

    m_dollars += dollars;
    m_cents+= cents;

    return *this;
}

Money Money::operator + (const Money & other)
{
    if (m_cents + other.m_cents > 100)
    {
        return Money(m_dollars + other.m_dollars + 1, m_cents + other.m_cents - 100);
    }
    return Money(m_dollars + other.m_dollars, m_cents + other.m_cents);
}

Money & Money::operator -= (int dollars)
{
    m_dollars -= dollars;
    return *this;
}


/*

*/
ostream & operator << (ostream & out, Money m)
{
    out << "$" << m.getDollars() << "." << m.getCents() << " ";
    return out;
}

Money & operator += (Money & m, int dollars)
{
    m.setDollars(m.getDollars() + dollars);
    return m;
}

int main()
{
    Money m1(3, 82);
    Money m2(20, 3);

    m2+= 4;
    cout << m2 << endl;

    m1 = ((m1 + m2) + m1);
    cout << m1.getDollars() << "." << m1.getCents();
    cout << m2 << m1 << endl;
    m2 += 17;
    cout << m2;

    Money m3(451, 17);
    float x = 20.17;
    m3 += x;
    cout << m3 << endl;
    m3 -= 5.2;
    cout << m3 << endl;
    // normally it's bitwise xor;
    m2 = m2 ^ 4;
    cout << m2 << endl;

    unsigned int uix = 0b10110010110000111010101000111111;
    unsigned int uiy = 0b10110010110000111010100000101010;
    // xor rax, rax
    cout << (uix ^ uiy) << endl;
    return 0;
}