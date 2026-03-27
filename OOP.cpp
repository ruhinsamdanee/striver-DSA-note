#include <bits/stdc++.h>
using namespace std;

class myDiary{
    public:
    string massage ;

    myDiary(){ //Constructor
        cout << "I am constructor(1st)" << endl ;// 1st ae constructor  print hoy 
    }

    myDiary(string n){//parameterized constructor
        massage = n ;
        cout << massage << " parameterized constructor(3rd)\n" ;//3rd ae parameterized constructor print hoy
    }

    void setstring(string s){ //2nd ae member function print hobe
        cout << s << " (2nd)" << endl;
    }

    ~myDiary(){//Destructor
        cout << "I am the Destructor (Last)" << endl ;// Destructor 2 bar print hoise karon constructor 2 ta chilo.
    }//sobar last ae destructor
};
int main() {
    myDiary BU ;//1st object non parameterized constructor/default constructor

    BU.setstring("I am Ruheen") ;//member function ae pathailam

    myDiary BU1("Bro I am here") ;// 2nd object create for parameterized constructor

    return 0;
}