#ifndef REPORT_H
#define REPORT_H

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Course.h"
#include "Enrollment.h"
#include "Enrollment_Management.h"
#include "Logger.h"
using namespace std;
enum class ReportType { GENERAL };

template <ReportType type>
class Report {
public:
    static void generateReport(const vector<shared_ptr<Course>>& courses,
                               const vector<shared_ptr<Employee>>& employees,
                                EnrollmentManager& enrollmentManager);
};

template <>
void Report<ReportType::GENERAL>::generateReport(const vector<shared_ptr<Course>>& courses,
                                                 const vector<shared_ptr<Employee>>& employees,
                                                  EnrollmentManager& enrollmentManager) {
    try {
        // Log the start of the function
        Logger::log("Generating report.");

        cout << "\n=== Generating Report ===" << endl << endl;

        cout << "\n=== Course Details ===" << endl;
        // Display Course details
        for (const auto& course : courses) {
            course->displayCourseDetails();
            cout << endl;
        }

        cout << "\n=== Employee Details ===" << endl;
        // Display Employee details
        for (const auto& employee : employees) {
            employee->displayEmployeeDetails();
            cout << endl;
        }

        cout << "\n=== Enrollment Details ===" << endl;
        // Display all enrollments for a specific employee (e.g., Employee ID 1)
        int employeeIDToDisplay = 1;
        enrollmentManager.displayEnrollmentsForEmployee(employeeIDToDisplay);

        // Display all enrollments
        enrollmentManager.displayAllEnrollments();

        // Log the end of the function
        Logger::log("Report generated successfully.");
    }
    catch (const exception& e) {
        // Log error if an exception occurs during generateReport
        Logger::error("Exception occurred during generating report: " + string(e.what()));
    }
}

#endif //REPORT_H