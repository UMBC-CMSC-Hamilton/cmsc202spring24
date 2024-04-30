/*
    Recursion - abstraction & encapsulation

    What is recursion?
        when a function calls itself.

    You can use return to give results back to a higher level of the recursion
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int count_as(string s)
{
    if(s.empty())
        return 0; // base case
    
    if (s[0] == 'a' || s[0] == 'A')
    {
        return 1 + count_as(s.substr(1, s.length() - 1));
    }
    else
    {
        return 0 + count_as(s.substr(1, s.length() - 1));
    }
}


int count_as_better(string & s, int i = 0)
{
    if(i == s.length())
        return 0; // base case
    
    if (s[i] == 'a' || s[i] == 'A')
    {
        return 1 + count_as_better(s, i + 1);
    }
    else
    {
        return 0 + count_as_better(s, i + 1);
    }
}

template<typename T>
struct LLN {
    LLN(T nd = T()) : data(nd), p_next(nullptr) {}
    void insert_at_tail(T new_data);
    T data;
    LLN * p_next;

    private:
        void insert_tail_rec(T new_data, LLN<T> * current);
};

template<typename T>
void LLN<T>::insert_at_tail(T new_data)
{   
    insert_tail_rec(new_data);
}

template<typename T>
void insert_tail_rec(T new_data, LLN<T> * current)
{
    if(!current->p_next)
    {
        current->p_next = new LLN<T>(new_data);
    }
    else
    {
        insert_tail_rec(new_data, current->p_next);
    }
}

/*

    1, 2, 8, 12, 15, 25, 31, 37, 42
    bin search looks at the middle element
    if the list is sorted, then basically we can know which direction an element
        "will or would be" if it's in the list
    
    looking for 8
    1, 2, 8, 12, 15, 25, 31, 37, 42
    
    1, 2, 8, 12 --> return true, searching for 1 instead
    1, 2
    1
    searching for 35
    1, 2, 8, 12, start 15, 25, 31, 37, 42
    25, 31, 37, 42
    25, 31 start = 5 end = 6
    start = 7 and end = 6
*/

bool binary_search(const vector<int> & vec, int start, int end, int look_for)
{
    if(start >= end)
    {
        return false;
    }
    int middle_index = (start + end) / 2;
    
    cout << start << " " << end << " " << vec[middle_index] << endl;
    if(vec[middle_index] == look_for)
    {
        return true;
    }
    else if (look_for < vec[middle_index])
    {
        return binary_search(vec, start, middle_index, look_for);
    }
    else
    {
        return binary_search(vec, middle_index + 1, end, look_for);
    }
}

/*
    branching recursion is a recursion that calls multiple recursions per 
        function call
    aaa
    aab
    aba
    abb
    baa
    bab
    bba
    bbb

*/

void as_and_bs(int n, string current)
{
    if (!n)
    {
        cout << current << " ";
        return;
    }
    as_and_bs(n - 1, current + "a");
    as_and_bs(n - 1, current + "b");
}

void countdown(int n)
{
    if (!n)
    {
        cout << "Blastoff" << endl;
    }
    else
    {
        if (!(n % 1000))
            cout << "T - " << n << endl;
        countdown(n - 1);
    }
}

int main()
{
    cout << count_as("abba") << endl;
    cout << count_as("sljdfslkjdlkfdsj") << endl;
    cout << count_as("abccbaaaba") << endl;

    LLN<int> listy;
    vector<int> numbers;
    for(int i = 0; i < 100; i++)
    {   
        numbers.push_back(4 * i + 3);
        cout << 4 * i + 3 << " ";
    }
    cout << endl;
    int search_for;
    cout << "What would you like to search for ? ";
    cin >> search_for;

    if(binary_search(numbers, 0, numbers.size(), search_for))
    {
        cout << "Found it" << endl;
    }
    else
    {
        cout << "nope." << endl;

    }

    as_and_bs(4, "");
    cout << endl;
    as_and_bs(9, "");
    cout << endl;
    
    // it never calls more than 25 recursions deep
    // as_and_bs(25, "");
    int t = 0;
    cin >> t;
    while (t >= 0)
    {
        countdown(t);
        cin >> t;
    }
    
    return 0;
}