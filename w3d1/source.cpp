#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ( )
{
    ifstream inputfile;
    string filename;
    string words;
    
    //Get the filename from the user.
    cout << "Enter the filename: ";
    cin >> filename;
    
    //Open the input file.
    inputfile.open(filename.c_str());
    
    //If the file successfully opened, process it.
    if (inputfile)
    {
        while (inputfile >> words)
            cout << words << endl;
        
        //Close the file.
        inputfile.close();
    }
    else
    {
        //Display an error message.
        cout << "Error opening the file.\n";
    }
    
    return 0;
}