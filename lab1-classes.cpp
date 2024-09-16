#include <string>
#include <cmath>
#include <iostream>

class EmployeeDepartment {
private:
    std::string department_name;
    int employees_count;
    int norm_hours;
    double hourly_payment;
    double income_tax;

public:
    EmployeeDepartment(
        std::string department_name,
        const int employees_count,
        const int norm_hours,
        const double hourly_payment,
        const int income_tax
    ):
       department_name(std::move(department_name)),
       employees_count(employees_count),
       norm_hours(norm_hours),
       hourly_payment(hourly_payment),
       income_tax(100.0 - income_tax) {
    }

    std::string getDepartmentName() const {return department_name; }
    int getEmployeesCount() const { return employees_count; }
    int getNormHours() const { return norm_hours; }
    double getHourlyPayment() const { return hourly_payment; }
    double getIncomeTax() const { return income_tax; }

    void setEmployeesCount(const int new_employees_count) {
        employees_count = new_employees_count;
    }

    void setNormHours(const int new_norm_hours) {
        norm_hours = new_norm_hours;
    }

    void setHourlyPayment(const int new_income_tax) {
        income_tax = new_income_tax;
    }

    double calculateTotalPayout() const {
        const double tax = income_tax / 100.0;
        const double total_payout = employees_count * norm_hours * hourly_payment * tax;
        return std::round(total_payout * 100.0) / 100.0;
    }
};


int main() {
    const EmployeeDepartment department("PolyTech", 10, 5, 10, 13);
    std::cout << department.calculateTotalPayout() << std::endl;
    return 0;
}
