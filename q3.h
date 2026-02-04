#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>

using namespace std;

namespace emp{
	
	class employee{
	private:
		string empName;
		int empId;
		double salary;
		int hoursWorked;
	public:
		employee(string e, int id, double s, int h);
		
		double getSalary();
		
		int getId();
		
		int gethours();
		
		string getName();
	};
}

#endif

