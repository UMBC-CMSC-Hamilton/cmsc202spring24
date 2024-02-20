#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void write_file_example()
{
    string filename;
    cout << "Please enter the filename: ";
    cin >> filename;

    fstream my_file(filename, ios_base::out);

    string contents = "";
    do 
    {
        my_file << contents << endl;
        cout << "What do you want to add to the file? ";
        cin >> contents;
    }while (contents != "quit");

    my_file.close();
}

int main()
{
    string filename;
    cout << "Enter a file to read: ";
    cin >> filename;

    fstream read_file;

    read_file.open(filename, ios_base::in);

    string contents;

    while (!read_file.eof())
    {
        
        // read_file >> contents;
        // you need a terminator which tells getline when to stop
        getline(read_file, contents, '\n');
        cout << contents << endl;
    }

    read_file.close();

    /*
        if you accidentally hit Ctrl +Z and it suspends
        type fg = foreground, it'll bring it back up. 
    */
    return 0;
}