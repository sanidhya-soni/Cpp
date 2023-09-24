#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Animal {
    private:
    int x;
    public:
    int a;

    Animal(int x) {
        cout << "Created Object" << endl;
        this->x = x;
        cout << x << endl;
    }

    void setter(int x) {
        string pass = "sani@123";
        cout << "Enter Password: ";
        string conf;
        cin >> conf;
        if(pass.compare(conf) == 0) {
            this->x = x;
            cout << "Value Set Succesful!" << endl;
        }
        else {
            cout << "Password did not match :(" << endl;
        }
    }

    int getter() {
        return this->x;
    }

    ~Animal() {
        cout << "Destructor Called" << endl;
    }
};

int main() {

    // Padding and greedy alignment
    // cout << "Size of Empty Class is: " << sizeof(Animal) << endl;

    // Animal *a1 = new Animal();
    // a1->a = 5;
    // cout << a1->a << endl;
    // delete a1;
    // cout << a1->a << endl;

    Animal ab(5.5);
    cout << ab.getter() << endl;
    ab.setter(100);
    cout << ab.getter() << endl;

    cout << "Terminated" << endl;
    return 0;
}
