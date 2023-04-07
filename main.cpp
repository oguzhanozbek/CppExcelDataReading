#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Signature { // This struct creates the signature required in the assignment
    char school[40];
    char course[50];
    char semester[50];
    char name[50];
    char studentid[20];
};

enum string_code{
    eMale,
    eFemale
};

string inputgender;
string inputname;

int hashit (string const& inString) {
    if (inputgender == "male") return eMale;
    if (inputgender == "female") return eFemale;}


int main()
{
    struct Signature ozbek { // the signature is instantiated here.
            "Sheridan Trafalgar FAST",
            "PROG23672 Data Structures and Algorithms",
            "2023 Winter",
            "Oguzhan Ozbek",
            "991656424" };
    cout << ozbek.school << endl << ozbek.course << endl << ozbek.semester << endl << ozbek.name << endl << ozbek.studentid << endl;


    ifstream inFile;

    string rank;
    string malename;
    string nummale;
    string femalename;
    string numfemale;



    cout << "Please enter the gender to find out the rank: ";
    cin >> inputgender;

    cout << "Please enter the name to find out the rank: ";
    cin >> inputname;




    inFile.open("C:/Projects/Assignment4/names.csv");
    if (inFile.is_open()) {
        cout << "File has been opened" << endl;
    }
    else {
        cout << "NO FILE HAS BEEN OPENED" << endl;
    }

    while (!inFile.eof()) {
        getline ( inFile, rank ,',');
        getline ( inFile, malename,',');
        getline ( inFile, nummale,',');
        getline ( inFile, femalename,',');
        getline ( inFile, numfemale,',');


        switch(hashit(inputname)){
            case eMale:
                if (malename==inputname) {
                    cout<< "The rank for the male name entered is: " << rank << endl;
                }

            case eFemale:
                if (femalename==inputname){
                    cout<< "The rank for the female name entered is: " << rank << endl;
                }
        }

    }
    inFile.close();
    system("pause");
    return 0;
}