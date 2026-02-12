#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;

int main(){

    LinkedList<int> intList;                   // int testing
    cout << "is it empty (1 if true and 0 if false): " << intList.isEmpty() << endl;            // print results
    intList.insert(0,10);                   // insert 10 at 0
    intList.insert(1,20);               /// insert 20 at 1
    cout << "int list after adding stuff: " << intList << endl;            // print results
    intList.remove(0);                  // remove pos 0
    cout << "int list after removing 0 pos : " << intList << endl;            // print results
    
    //    intList.remove(5);                  // remove pos 5
    //    cout << "int list after removing 0 pos : " << intList << endl;            // print results or error
    
    LinkedList<int> intCopy(intList);       // make new list and copy old onto new
    cout << "Copied list : " << intCopy << endl;            // print results

    LinkedList<string> stringList;                   // string testing
    cout << "is it empty (1 if true and 0 if false): " << stringList.isEmpty() << endl;   // print results
    stringList.insert(0,"Lebron");               // insert at 0
    stringList.insert(1,"James");               // insert at 1
    cout << "string list after adding stuff: " << stringList << endl;   // print results
    stringList.remove(0);                       // remove pos 0
    cout << "string list after removing 0 pos: " << stringList << endl; // print results
    LinkedList<string> stringCopy(stringList);  // copy constructor
    cout << "Copied string list: " << stringCopy << endl;   // print results

    return 0;
} 