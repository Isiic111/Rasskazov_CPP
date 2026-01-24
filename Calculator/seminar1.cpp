#include <iostream>
#include <cmath>

using namespace std;

int main() {
    
    setlocale(LC_ALL, "RUS");
    
    int choice;
    double num1, num2, result;

        cout << "1. Сложение (+)" << endl;
        cout << "2. Вычитание (-)" << endl;
        cout << "3. Умножение (*)" << endl;
        cout << "4. Деление (/)" << endl;
        cout << "5. Возведение в степень (^)" << endl;
        cout << "6. Квадратный корень (√)" << endl;
        cout << "7. Синус (sin)" << endl;
        cout << "8. Косинус (cos)" << endl;
        cout << "9. Тангенс (tan)" << endl;
        cout << "10. Логарифм натуральный (ln)" << endl;
        cout << "11. Логарифм десятичный (log10)" << endl;
        cout << "Выберите операцию: ";

        cin >> choice;

        switch (choice) {
        case 0:
            cout << "Выход из калькулятора. До свидания!" << endl;
            break;

        case 1: // Сложение
            cout << "Введите два числа: ";
            cin >> num1 >> num2;
            result = num1 + num2;
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;

        case 2: // Вычитание
            cout << "Введите два числа: ";
            cin >> num1 >> num2;
            result = num1 - num2;
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;

        case 3: // Умножение
            cout << "Введите два числа: ";
            cin >> num1 >> num2;
            result = num1 * num2;
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;

        case 4: // Деление
            cout << "Введите два числа: ";
            cin >> num1 >> num2;
            if (num2 == 0) {
                cout << "Ошибка! Деление на ноль невозможно." << endl;
            }
            else {
                result = num1 / num2;
                cout << num1 << " / " << num2 << " = " << result << endl;
            }
            break;

        case 5: // Возведение в степень
            cout << "Введите основание и показатель степени: ";
            cin >> num1 >> num2;
            result = pow(num1, num2);
            cout << num1 << " ^ " << num2 << " = " << result << endl;
            break;

        case 6: // Квадратный корень
            cout << "Введите число: ";
            cin >> num1;
            if (num1 < 0) {
                cout << "Ошибка! Корень из отрицательного числа невозможен." << endl;
            }
            else {
                result = sqrt(num1);
                cout << "√" << num1 << " = " << result << endl;
            }
            break;

        case 7: // Синус
            cout << "Введите угол: ";
            cin >> num1;
            result = sin(num1);
            cout << "sin(" << num1 << ") = " << result << endl;
            break;

        case 8: // Косинус
            cout << "Введите угол: ";
            cin >> num1;
            result = cos(num1);
            cout << "cos(" << num1 << ") = " << result << endl;
            break;

        case 9: // Тангенс
            cout << "Введите угол: ";
            cin >> num1;
            result = tan(num1);
            cout << "tan(" << num1 << ") = " << result << endl;
            break;

        case 10: // Натуральный логарифм
            cout << "Введите число: ";
            cin >> num1;
            if (num1 <= 0) {
                cout << "Ошибка! Логарифм определен только для положительных чисел." << endl;
            }
            else {
                result = log(num1);
                cout << "ln(" << num1 << ") = " << result << endl;
            }
            break;

        case 11: // Десятичный логарифм
            cout << "Введите число: ";
            cin >> num1;
            if (num1 <= 0) {
                cout << "Ошибка! Логарифм определен только для положительных чисел." << endl;
            }
            else {
                result = log10(num1);
                cout << "log10(" << num1 << ") = " << result << endl;
            }
            break;

        default:
            cout << "Такого в списке нет..." << endl;
            break;
        }

    return 0;
}
