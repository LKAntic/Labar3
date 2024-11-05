#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;


int md(int n, int* m) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i];
    }

    int target = sum / 2;
    bool* bl = new bool[target + 1]();
    bl[0] = true;

    for (int i = 0; i < n; i++) { 
        for (int j = target; j >= m[i]; j--) {
            bl[j] = bl[j] || bl[j - m[i]];
        }
    }

    int best = 0;
    for (int i = target; i >= 0; i--) {
        if (bl[i]) {
            best = i;
            break;
        }
    }

    delete[] bl;

    int otherPart = sum - best;
    return abs(otherPart - best);
}

int main() {
    int n;
    cin >> n;

    int m[32];
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    double start = clock();

    cout << md(n, m) << endl;

    double end = clock();
    double t = (end - start)/CLOCKS_PER_SEC;
    cout << "Sec " << t;
    return 0;
}
