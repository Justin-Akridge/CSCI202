#include "hasht.h"
#include <iostream>

using namespace std;

int main() {

    //test case 1
    cout << "\n------------TEST CASE 1------------\n";
    hashT map1;
    map1.insert("1", "2");
    map1.insert("2", "3");
    map1.insert("3", "4");
    cout << "1: " << map1.search("1") << endl;
    cout << "2: " << map1.search("2") << endl;
    cout << "3: " << map1.search("3") << endl;
    map1.print();
    map1.remove("2");
    map1.print();

    cout << "\n------------TEST CASE 2------------\n";
    hashT map2(10);
    map2.insert("Justin", "Akridge");
    map2.insert("foo", "bar");
    map2.insert("toodle", "bar");
    cout << "search for Justin's last name: " << map2.search("Justin") << endl;
    cout << "search for foo: " << map2.search("foo") << endl;
    cout << "search for toodle: " << map2.search("toodle") << endl;
    if (map2.isItemAtEqual("foo", "toodle")) {
        cout << "Items are equal!\n";
    } else {
        cout << "Items are not equal!\n";
    }

    // test case 3
    cout << "\n------------TEST CASE 3------------\n";
    hashT map3(5);
    map3.insert("May", "1");
    map3.insert("April", "14");
    map3.insert("June", "3");
    cout << "Search appointment in May: " << map3.search("May") << " day of the month" << endl;
    cout << "search appointment in April: " << map3.search("April") << " day of the month" << endl;
    cout << "search appointment in June: " << map3.search("June") << " day of the month" << endl;
}
