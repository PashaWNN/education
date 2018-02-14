#include <iostream>
#include <cstdlib>

using namespace std;

class Test {
public:
    void hello() {
        cout << "Hello, world!\n";
    }
};

int main() {
    Test t;
    t.hello();
    return 0;
}
