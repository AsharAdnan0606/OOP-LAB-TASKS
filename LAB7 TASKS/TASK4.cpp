#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}
    virtual void displayInfo() {
        cout << "Name: " << name << " | ID: " << id << " | Email: " << email << "\n";
    }
};

class Student : public Person {
    vector<string> coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, vector<string> c, double g, int y)
        : Person(n, i, a, p, e), coursesEnrolled(c), GPA(g), enrollmentYear(y) {}
    void displayInfo() override {
        cout << "Student - " << name << " | GPA: " << GPA << " | Year: " << enrollmentYear << "\n";
    }
};

class Professor : public Person {
    string department;
    int coursesTaught;
    double salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, int c, double s)
        : Person(n, i, a, p, e), department(d), coursesTaught(c), salary(s) {}
    void displayInfo() override {
        cout << "Professor - " << name << " | Department: " << department << " | Salary: " << salary << "\n";
    }
};

class Staff : public Person {
    string department, position;
    double salary;
public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, double s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}
    void displayInfo() override {
        cout << "Staff - " << name << " | Position: " << position << " | Salary: " << salary << "\n";
    }
};

class Course {
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    Course(string id, string name, int cr, string instr, string sched)
        : courseId(id), courseName(name), credits(cr), instructor(instr), schedule(sched) {}
    void registerStudent(Student &s) {
        cout << s.displayInfo() << " registered in " << courseName << "\n";
    }
};

int main() {
    Student s("Alice", "S101", "123 St", "123456", "alice@mail.com", {"Math", "CS"}, 3.9, 2022);
    Professor p("Dr. Smith", "P201", "456 St", "789123", "smith@mail.com", "CS", 5, 75000);
    Staff st("John", "ST301", "789 St", "456789", "john@mail.com", "Admin", "Manager", 50000);
    Course c("CSE101", "Programming", 3, "Dr. Smith", "MWF 10 AM");
    
    s.displayInfo();
    p.displayInfo();
    st.displayInfo();
    
    c.registerStudent(s);
    
    return 0;
}

