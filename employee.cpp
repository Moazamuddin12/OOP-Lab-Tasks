#include "q3.h"
#include <iostream>
#include <string>
using namespace std;
namespace emp{
	employee::employee(string e, int id, double s, int h) : empName(e) , empId(id), salary(s), hoursWorked(h) {
		cout << "Employee Sucessfully Added" << endl;
	}
	
	int employee::gethours(){
		return hoursWorked;
	}
	
	string employee::getName(){
		return empName;
	}
	
	int employee::getId(){
		return empId;
	}
	
	double employee::getSalary(){
		return salary;
	}
}


