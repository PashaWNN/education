#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double nthrt(int i, int n) {
    return pow(i, 1.0/n);
}

int main() {
    //Input:
    vector<int> vec;
    int count;
    cout << "Enter number of integers: ";
    cin >> count;
    for (int i = 0; i<count; i++) {
        int q;
        cout << "Enter integer: ";  
        cin >> q;
        vec.emplace(vec.end(), q);
    }
    //Algorhytm:
    double r = 1;
    int n = 0;
    for (int i: vec) {
        n++;
        r *= i;
    }
    double result = nthrt(r, n);

    //Display result
    cout << result << endl;
    return 0;
}
