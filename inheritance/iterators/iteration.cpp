#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <iterator>
#include <iostream>

using namespace std;


int main()
{
    vector<int> v;
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i * i + i - 3);
    }

    for(vector<int>::iterator the_itr = v.begin(); the_itr != v.end(); the_itr++)
    {
        cout << *the_itr << endl;
    }

    map<string, int> my_map;
    string s;
    int i;
    while (s != "quit")
    {
        cin >> s >> i;
        my_map[s] = i;
    }
    
    /*
        maps return pairs that's nice
    */
    for(map<string, int>::iterator map_itr = my_map.begin(); map_itr != my_map.end(); map_itr++)
    {
        cout << "Key: " << map_itr->first << " Value: " << map_itr->second << endl;
    }

    stack<string> stacky;
    string oper;
    string x;
    while (oper != "quit")
    {
        try{
            cout << "What do you want to do? ";
            cin >> oper;
            if (oper == "push")
            {
                cin >> x;
                stacky.push(x);
                cout << "pushed" << x << " onto stack" << endl;
            }
            else if (oper == "pop")
            {
                if (!stacky.empty())
                {
                cout << stacky.top() << endl;
                stacky.pop();
                }
                else
                {
                    cout << "Cannot pop from empty stack" << endl;
                }
            }

        }
        catch (std::exception)
        {
            cout << "cannot pop from empty stack"<< endl;
        }
    }

    return 0;
}