#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class PatientRecord {
private:
    std::string name;
    std::string id;
    std::string dob; // Date of birth
    std::string medicalHistory;
    std::string currentTreatments;
    std::vector<std::string> billingDetails;

    // Private method for sensitive data (accessible only to authorized roles)
    void updateMedicalHistory(const std::string& history) {
        medicalHistory = history;
    }

    // Private method to update billing details (only accessible by billing staff)
    void addBillingDetails(const std::string& details) {
        billingDetails.push_back(details);
    }

public:
    // Constructor
    PatientRecord(std::string patientName, std::string patientId, std::string patientDob) 
        : name(patientName), id(patientId), dob(patientDob) {}

    // Public method that returns only non-sensitive information
    std::string getPublicData() const {
        return "Name: " + name + "\nID: " + id + "\nDOB: " + dob;
    }

    // Public method that returns medical data in a controlled way (for authorized roles)
    std::string getMedicalData() const {
        return "Medical History: " + medicalHistory + "\nCurrent Treatments: " + currentTreatments;
    }

    // Friend classes to grant access to update medical history and billing details
    friend class Doctor;
    friend class Billing;
};

// Doctor class - Can access medical data and update medical history
class Doctor {
public:
    void updateMedicalHistory(PatientRecord& record, const std::string& history) {
        record.updateMedicalHistory(history);
        std::cout << "Medical history updated for " << record.name << std::endl;
    }

    std::string viewMedicalData(const PatientRecord& record) {
        return record.getMedicalData();
    }
};

// Billing class - Can access and update billing details
class Billing {
public:
    void addBillingDetail(PatientRecord& record, const std::string& detail) {
        record.addBillingDetails(detail);
        std::cout << "Billing detail added for " << record.name << std::endl;
    }

    void viewBillingData(const PatientRecord& record) {
        std::cout << "Billing Details: ";
        for (const auto& detail : record.billingDetails) {
            std::cout << detail << " ";
        }
        std::cout << std::endl;
    }
};

// Receptionist class - Only allowed to see public data, not sensitive information
class Receptionist {
public:
    void viewPublicData(const PatientRecord& record) {
        std::cout << "Public Data: " << record.getPublicData() << std::endl;
    }

    // Unauthorized access should not be allowed
    void tryToViewMedicalData(const PatientRecord& record) {
        std::cout << "Access Denied! Receptionists cannot view medical data." << std::endl;
    }
};

int main() {
    // Creating a patient record
    PatientRecord patient("John Doe", "12345", "1985-03-25");

    // Creating role instances
    Doctor doctor;
    Billing billing;
    Receptionist receptionist;

    // Authorized actions
    doctor.updateMedicalHistory(patient, "Patient has hypertension.");
    billing.addBillingDetail(patient, "$100 for consultation.");

    // Viewing authorized data
    std::cout << "\nDoctor's View:\n" << doctor.viewMedicalData(patient) << std::endl;
    billing.viewBillingData(patient);

    // Unauthorized access attempts by receptionist
    std::cout << "\nReceptionist's View:\n";
    receptionist.viewPublicData(patient); // Allowed
    receptionist.tryToViewMedicalData(patient); // Denied

    return 0;
}

