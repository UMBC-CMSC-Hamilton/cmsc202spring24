#include <set>
#include <string>
#include <iostream>

using namespace std;

struct DoSomethingReturnStruct {
    string first;
    int second;
};

pair<string, int> DoSomething()
{
    return pair<string, int>("Hi", 4);
}

pair<int, pair<float, string>> return_three_things()
{
    return pair<int, pair<float, string>>(3, pair<float, string>(4.7, "chicken"));
}

struct TTS {
    TTS(int x, float y, string z)
        : first(x), second(y), third(z)
    {};
    int first;
    float second;
    string third;
};

TTS return_three_things_TTS()
{
    return TTS(3, 4.7, string("chicken"));
}

int main()
{
    set<string> my_words;

    my_words.insert("valor");
    my_words.insert("valor"); // set will ignore the second insert
    my_words.insert("hello");
    my_words.insert("robot");
    my_words.insert("turkey");
    my_words.insert("prosody");

    for(set<string>::iterator setitr = my_words.begin();
        setitr != my_words.end(); setitr++)
    {
        cout << *setitr << endl;
    }
    // erase is the delete element (remove element)
    my_words.erase("hello");
    
    for(set<string>::iterator setitr = my_words.begin();
        setitr != my_words.end(); setitr++)
    {
        cout << *setitr << endl;
    }

    multiset<int> my_multi;

    my_multi.insert(7);
    my_multi.insert(9);
    my_multi.insert(8);
    my_multi.insert(3);
    my_multi.insert(9);
    my_multi.insert(3);
    my_multi.insert(3);
    my_multi.insert(9);


    for(multiset<int>::iterator msetitr = my_multi.begin(); 
        msetitr != my_multi.end(); msetitr++)
    {
        cout << *msetitr << " ";
    }
    cout << endl;

    pair<string, int> psi;
    psi.first = "loquatious";
    psi.second = 17;
    pair<int, pair<float, string>> ret = return_three_things();
    cout << ret.first << " " << ret.second.first << " " << ret.second.second << endl;
    TTS x = return_three_things_TTS();
    cout << x.first << " " << x.second << " " << x.third << endl;

    pair<int, double> idp = make_pair(3, 9.75);
    
    return 0;
}