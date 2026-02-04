#include <iostream>
#include <string>
#include "q3.h"

using namespace std;
using namespace emp;

int main() {
    employee e1("Moazamuddin", 771, 4500, 45);
    
    double hourlyRate = e1.getSalary();
    int totalHours = e1.gethours();
    
    double regularPay = 0;
    double overtimePay = 0;
    double totalPay = 0;

    if (totalHours > 40) {
        regularPay = 40 * hourlyRate;
        overtimePay = (totalHours - 40) * (hourlyRate * 1.5);
    } else {
        regularPay = totalHours * hourlyRate;
        overtimePay = 0;
    }

    totalPay = regularPay + overtimePay;

    cout << "=========Employee Details=========\n" << endl;
    cout << "Employee Name: " << e1.getName() << endl;
    cout << "Employee ID: " << e1.getId() << endl;
    cout << "Employee Salary Per Hour: Rs " << hourlyRate << "/-" << endl;
    cout << "Employee Worked Hours: " << totalHours << " Hours" << endl;
    cout << "Employee Regular Pay: Rs " << regularPay << "/-" << endl;
    cout << "Employee Overtime Pay: Rs " << overtimePay << "/-" << endl;
    cout << "Total Pay: Rs " << totalPay << "/-" << endl;

    return 0;
}
