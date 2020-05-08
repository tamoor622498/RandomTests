#include <iostream>

using namespace std;

int main() {
    int array[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            array[i][j] = 0;
        }
    }

    array[0][1] = 5;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10 ; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}