#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    string ownerName;
    double balance;
    static int totalAccounts;
    static double totalBankBalance;
    const double MIN_BALANCE = 10.0;

public:
    BankAccount(string accNum, string name, double initialBalance)
        : accountNumber(accNum), ownerName(name), balance(initialBalance) {
        totalAccounts++;
        totalBankBalance += balance;
    }

    ~BankAccount() {
        totalAccounts--;
        totalBankBalance -= balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            totalBankBalance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && (balance - amount) >= MIN_BALANCE) {
            balance -= amount;
            totalBankBalance -= amount;
            return true;
        }
        return false;
    }

    void displayAccountInfo() const {
        cout << "����� �����: " << accountNumber << endl;
        cout << "��������: " << ownerName << endl;
        cout << "������: " << balance << endl;
    }

    static int getTotalAccounts() {
        return totalAccounts;
    }

    static double getTotalBankBalance() {
        return totalBankBalance;
    }

    static double getAverageBalance() {
        if (totalAccounts > 0) {
            return totalBankBalance / totalAccounts;
        }
        return 0.0;
    }
};

int BankAccount::totalAccounts = 0;
double BankAccount::totalBankBalance = 0.0;

int main() {
    cout << "=== ������ ������ ����� ===" << endl;
    cout << "����� ������: " << BankAccount::getTotalAccounts() << endl;
    cout << "����� ������: " << BankAccount::getTotalBankBalance() << endl;

    BankAccount account1("ACC001", "���� ������", 1000.0);
    BankAccount account2("ACC002", "���� ������", 500.0);

    cout << "\n=== ����� �������� ���� ������ ===" << endl;
    cout << "����� ������: " << BankAccount::getTotalAccounts() << endl;
    cout << "����� ������: " << BankAccount::getTotalBankBalance() << endl;
    cout << "������� ������: " << BankAccount::getAverageBalance() << endl;

    cout << "\n=== �������� ===" << endl;
    account1.deposit(200.0);
    cout << "���������� ����� 1 �� 200" << endl;

    if (account2.withdraw(100.0)) {
        cout << "������ �� ����� 2: 100" << endl;
    }
    else {
        cout << "�� ������� ����� �� ����� 2" << endl;
    }

    cout << "\n=== ����� �������� ===" << endl;
    cout << "����� ������: " << BankAccount::getTotalAccounts() << endl;
    cout << "����� ������: " << BankAccount::getTotalBankBalance() << endl;
    cout << "������� ������: " << BankAccount::getAverageBalance() << endl;

    cout << "\n=== �������� ���������� ����� ===" << endl;
    {
        BankAccount account3("ACC003", "������ �������", 300.0);
        cout << "����� ������: " << BankAccount::getTotalAccounts() << endl;
        cout << "����� ������: " << BankAccount::getTotalBankBalance() << endl;
    }

    cout << "\n=== ����� �������� ���������� ����� ===" << endl;
    cout << "����� ������: " << BankAccount::getTotalAccounts() << endl;
    cout << "����� ������: " << BankAccount::getTotalBankBalance() << endl;

    cout << "\n=== ���������� � ������ ===" << endl;
    account1.displayAccountInfo();
    cout << "---" << endl;
    account2.displayAccountInfo();

    return 0;
}