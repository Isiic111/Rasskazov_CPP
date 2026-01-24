#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int n;

    cout << "Ввести кол-во дней: ";
    cin >> n;

    vector<double> temp(n);

    cout << "Введите температуры: " << endl;
    for (int i = 0; i < n; i++) {
        cout << "День " << i + 1 << ": ";
        cin >> temp[i];
    }

    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += temp[i];
    }
    double average_temp = sum / n;

    double min_temp = temp[0];
    double max_temp = temp[0];

    for (int i = 1; i < n; i++) {
        if (temp[i] < min_temp) {
            min_temp = temp[i];
        }
        if (temp[i] > max_temp) {
            max_temp = temp[i];
        }
    }

    int days_below_average = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i] < average_temp) {
            days_below_average++;
        }
    }

    cout << fixed;
    cout << "Количество дней: " << n << endl;
    cout << "Средняя температура: " << average_temp << endl;
    cout << "Мин температура: " << min_temp << endl;
    cout << "Макс температура: " << max_temp << endl;
    cout << "Кол-во дней с температурой ниже средней: " << days_below_average << endl;

    return 0;
}