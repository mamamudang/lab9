#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double initialLoan, interestRate, annualPayment;

    cout << "Enter initial loan: ";
    cin >> initialLoan;

    cout << "Enter interest rate per year (%): ";
    cin >> interestRate;

    cout << "Enter amount you can pay per year: ";
    cin >> annualPayment;

    cout << left << setw(13) << "EndOfYear#" << setw(13) << "PrevBalance" << setw(13) 
         << "Interest" << setw(13) << "Total" << setw(13) << "Payment" << setw(13) << "NewBalance" << endl;

    double prevBalance = initialLoan;
    int year = 0;

    while (prevBalance > 0) {
        year++;
        double interest = prevBalance * (interestRate / 100.0);
        double total = prevBalance + interest;
        double payment = (total > annualPayment) ? annualPayment : total;
        double newBalance = total - payment;

        cout << fixed << setprecision(2);
        cout << left << setw(13) << year << setw(13) << prevBalance << setw(13) << interest
             << setw(13) << total << setw(13) << payment << setw(13) << newBalance << endl;

        prevBalance = newBalance;
    }

    return 0;
}
