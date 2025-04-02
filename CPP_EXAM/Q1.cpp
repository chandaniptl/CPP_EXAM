#include <iostream>
using namespace std;

class Employee
{
public:
    int empID;
    string empName;
    int empAge;
    string departmentName;
    float salary;
    int num_of_day_present;
    float bonus_amount;

    Employee() : num_of_day_present(0), bonus_amount(0.0)
    {
    }

    void addEmployee();
    void markAttendance(int day);
    float calculateSalary();
    void applyIncrement(float percentage);
    void grantBonus(float amount);
    void displayEmployee();

    int getEmpID()
    {
        return empID;
    }
};

void Employee::addEmployee()
{
    cout << "Enter Employee ID: ";
    cin >> empID;

    cout << "Enter Employee Name: ";
    cin.ignore();
    getline(cin, empName);

    cout << "Enter Employee Age: ";
    cin >> empAge;

    cout << "Enter Department Name: ";
    cin.ignore();
    getline(cin, departmentName);

    cout << "Enter Employee Salary: ";
    cin >> salary;

    num_of_day_present = 0;
    bonus_amount = 0.0;
}

void Employee::markAttendance(int day)
{
    if (num_of_day_present + day > 30)
    {
        cout << "Attendence Successfully!" << endl;
        return;
    }
    num_of_day_present += day;
}

float Employee::calculateSalary()
{
    return (salary / 30.0) * num_of_day_present + bonus_amount;
}

void Employee::applyIncrement(float percentage)
{
    salary += (salary * percentage / 100.0);
}

void Employee::grantBonus(float amount)
{
    bonus_amount += amount;
}

void Employee::displayEmployee()
{
    cout<<endl;
    cout << "Employee ID: " << empID << endl;
    cout << "Employee Name: " << empName << endl;
    cout << "Employee Age: " << empAge << endl;
    cout << "Department Name: " << departmentName << endl;
    cout << "Base Salary: " << salary << endl;
    cout << "Attendance: " << num_of_day_present << endl;
    cout << "Bonus: " << bonus_amount << endl;
    cout << "Total Salary: " << calculateSalary() << endl;
}

int main()
{

    const int Max_employee = 100;
    Employee Employee[Max_employee];
    int employeeCount = 0;
    int choice;
    int eid;

    do
    {
        cout << endl;
        cout << "Employee Management System" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Mark Attendance" << endl;
        cout << "3. Calculate Salary" << endl;
        cout << "4. Apply Increment" << endl;
        cout << "5. Grant Bonus" << endl;
        cout << "6. Display Employee" << endl;
        cout << "7. Exit" << endl;

        cout<<endl;
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            if (employeeCount < Max_employee)
            {
                Employee[employeeCount].addEmployee();
                employeeCount++;
            }
            break;
        }

        case 2:
        {
            cout << "Enter Employee ID: ";
            cin >> eid;
            int days;
            cout << "Enter Number Of Days: ";
            cin >> days;
            for (int i = 0; i < employeeCount; i++)
            {
                if (Employee[i].getEmpID() == eid)
                {
                    Employee[i].markAttendance(days);
                }
            }
            break;
        }

        case 3:
        {
            cout << "Enter Employee ID: ";
            cin >> eid;
            bool found = false;
            for (int i = 0; i < employeeCount; i++)
            {
                if (Employee[i].getEmpID() == eid)
                {
                    cout << "Calculated Salary: " << Employee[i].calculateSalary() << endl;
                    break;
                }
            }
            break;
        }

        case 4:
        {
            cout << "Enter Employee ID: ";
            cin >> eid;
            float percent;
            cout << "Enter Increment Percentage: ";
            cin >> percent;
            for (int i = 0; i < employeeCount; i++)
            {
                if (Employee[i].getEmpID() == eid)
                {
                    Employee[i].applyIncrement(percent);
                    break;
                }
            }
            break;
        }

        case 5:
        {
            cout << "Enter Employee ID: ";
            cin >> eid;
            float amount;
            cout << "Enter Bonus Amount: ";
            cin >> amount;
            bool found = false;
            for (int i = 0; i < employeeCount; i++)
            {
                if (Employee[i].getEmpID() == eid)
                {
                    Employee[i].grantBonus(amount);
                    break;
                }
            }
            break;
        }

        case 6:
        {
            cout << "Enter Employee ID: ";
            cin >> eid;
            bool found = false;
            for (int i = 0; i < employeeCount; i++)
            {
                if (Employee[i].getEmpID() == eid)
                {
                    Employee[i].displayEmployee();
                    break;
                }
            }
            break;
        }

        case 7:
            cout << "Exit The Program\n";
            break;

        default:
            cout << "Invalid choice! \n";
            break;
        }

    } while (choice != 7);

    return 0;
}
