/*
    1st question:
        how's the project going?
        
        my_string.substr(first index, number of chars)

*/
#include<iostream>
#include<string>
#include<vector>

const int num_items = 6

using namespace std;

void split(string the_string, char split_on)
{
    vector<string> the_strings;
    int first_index = 0;
    for(unsigned int i= 0; i < the_string.length();i++)
    {
        if(the_string[i] == ',')
        {
            the_strings.push_back(the_string.substr(first_index, 
                    i - first_index));
            first_index = i + 1; // you may accidentally use i here, if you do that's fine, you'll see a comma, add one and get rid of it.
        }
    }
    // after the loop, the issue is that
    // there could be more at the end of the
    // string that doesn't have a comma
    the_strings.push_back(the_string.substr(first_index, the_string.length() - first_index + 1));
}