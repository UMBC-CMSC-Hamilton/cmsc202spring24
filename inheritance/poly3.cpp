class Parent
{
    public:
        Parent(int x, int y) : ix(x), iy(y) {}
        virtual void nothing() = 0;
    private:
        int ix, iy;
};

class TheKid : public Parent
{
    public:
        TheKid(int x, int y) 
            : Parent(x, y) 
        {   // not allowed because this tries to construct a parent object
            
            // Parent(x, y); Parent is abstract
            /*
                private problems:
                ix = x;
                iy = y
            */
        }
        virtual void nothing() {};
    private:
};


/**
 * 1 to m_challenge
 * 
 * (rand() % m_challenge) + 1
 * 
 * In case of a tie, you must win [i think?]
 * 
 * 
*/