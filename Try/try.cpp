#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Test {
    public:
    Test() {
        cout << "Hey" << endl;
    }

    // Copy constructor
    Test(const Test& temp) {
        cout << "Copy" << endl;
    }

    Test fun(int i) {
        cout << i << " ";
        return *this;
    }
};

int main() {

    vector<int> x;
    x.push_back(10);
    x.push_back(10);

    x.erase(x.begin());
    x.erase(x.begin());

    cout << x.size() << endl;

    return 0;
}
