#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;


int md(int n, int* m) { //Нахождение минимальной разницы
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += m[i];
    }

    int target = sum / 2; //Мы хотим чтобы каждая группа каш была максимально приближенна к target
    bool* bl = new bool[target + 1]();  //Мы задаём булев динамический массив
    bl[0] = true; //Все элементы массива будут False, кроме первого

    // Основной цикл для построения массива достижимых значений
    for (int i = 0; i < n; i++) { //Этими циклами мы находим достижимые значения 
        for (int j = target; j >= m[i]; j--) {
            bl[j] = bl[j] || bl[j - m[i]];
        }
    }

    int best = 0; //Мы находим самый большой достижимый элемент
    for (int i = target; i >= 0; i--) {
        if (bl[i]) {
            best = i;
            break;
        }
    }

    delete[] bl; // Освобождение выделенной памяти, так как мы уже нашли лучший вариант

    int otherPart = sum - best; //Мы так делаем, потому что редко где разница "0"
    return abs(otherPart - best); //Конечный ответ
}

int main() {
    int n;
    cin >> n;

    int m[32]; //Ограничение в условии на n <= 32
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