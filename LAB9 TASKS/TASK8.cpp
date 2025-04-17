#include <iostream>
#include <string>
using namespace std;

// Abstract class Student
class Student {
protected:
    string name;

public:
    // Constructor to initialize student name
    Student(string studentName) : name(studentName) {}

    // Pure virtual function to calculate tuition
    virtual double getTuition(string status, int creditHours) = 0;

    // Getter for name
    string getName() const {
        return name;
    }

    // Virtual destructor
    virtual ~Student() {}
};

// Derived class GraduateStudent that inherits from Student
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    // Constructor to initialize GraduateStudent's name and research topic
    GraduateStudent(string studentName, string topic) : Student(studentName), researchTopic(topic) {}

    // Override the getTuition function for Graduate students
    double getTuition(string status, int creditHours) override {
        double tuition = 0.0;
        if (status == "undergraduate") {
            tuition = 200.0 * creditHours; // $200 per credit hour for undergraduate
        } else if (status == "graduate") {
            tuition = 300.0 * creditHours; // $300 per credit hour for graduate
        } else if (status == "doctoral") {
            tuition = 400.0 * creditHours; // $400 per credit hour for doctoral
        }
        return tuition;
    }

    // Method to set the research topic
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    // Method to get the research topic
    string getResearchTopic() const {
        return researchTopic;
    }

    // Method to display GraduateStudent info
    void displayInfo() const {
        cout << "Student Name: " << getName() << "\nResearch Topic: " << researchTopic << endl;
    }
};

int main() {
    // Create a GraduateStudent object
    GraduateStudent gradStudent("Alice", "Artificial Intelligence");

    // Display student's information
    gradStudent.displayInfo();

    // Get tuition based on status and credit hours
    int creditHours = 15; // Example: 15 credit hours
    string status = "graduate"; // Example: graduate status
    double tuition = gradStudent.getTuition(status, creditHours);

    // Display calculated tuition
    cout << "Tuition for " << gradStudent.getName() << " with " << creditHours << " credit hours: $" << tuition << endl;

    return 0;
}

