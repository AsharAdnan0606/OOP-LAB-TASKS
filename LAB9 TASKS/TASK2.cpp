#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Logger {
private:
    std::vector<std::string> logs;
    size_t maxLogs = 1000; // Maximum log limit

    // Private method to format the log message with timestamp and severity
    std::string formatLog(const std::string& severity, const std::string& message) {
        std::time_t now = std::time(0);
        char* dt = std::ctime(&now);
        // Remove the newline character from the timestamp
        std::string timestamp(dt);
        timestamp.pop_back(); 
        return "[" + timestamp + "] [" + severity + "] " + message;
    }

    // Private method to manage the log size and enforce the log limit
    void manageLogLimit() {
        if (logs.size() >= maxLogs) {
            logs.erase(logs.begin()); // Remove the oldest log entry
        }
    }

public:
    void logInfo(const std::string& message) {
        std::string formattedMessage = formatLog("INFO", message);
        logs.push_back(formattedMessage);
        manageLogLimit();
    }

    void logWarning(const std::string& message) {
        std::string formattedMessage = formatLog("WARN", message);
        logs.push_back(formattedMessage);
        manageLogLimit();
    }

    void logError(const std::string& message) {
        std::string formattedMessage = formatLog("ERROR", message);
        logs.push_back(formattedMessage);
        manageLogLimit();
    }

    // A single method to log with severity
    void logMessage(const std::string& severity, const std::string& message) {
        std::string formattedMessage = formatLog(severity, message);
        logs.push_back(formattedMessage);
        manageLogLimit();
    }

    // Retrieve logs for auditing (read-only interface)
    class LogRetriever {
    private:
        const std::vector<std::string>& logs;
        bool isAuthenticated;

    public:
        LogRetriever(const std::vector<std::string>& logs, bool authenticated)
            : logs(logs), isAuthenticated(authenticated) {}

        void displayLogs() {
            if (isAuthenticated) {
                for (const auto& log : logs) {
                    std::cout << log << std::endl;
                }
            } else {
                std::cout << "Unauthorized access!" << std::endl;
            }
        }
    };

    // Function to return a LogRetriever object for auditing purposes
    LogRetriever getLogRetriever(bool authenticated) {
        return LogRetriever(logs, authenticated);
    }
};

int main() {
    Logger logger;

    // Simulate different modules logging
    logger.logInfo("Network module started.");
    logger.logWarning("Database module connection slow.");
    logger.logError("Disk space running low.");
    logger.logMessage("INFO", "User login successful.");
    logger.logMessage("ERROR", "Failed to send email.");

    // Display logs using an authorized auditor
    Logger::LogRetriever auditor = logger.getLogRetriever(true);
    std::cout << "Audit logs:" << std::endl;
    auditor.displayLogs();

    // Display logs using an unauthorized auditor
    Logger::LogRetriever unauthorizedAuditor = logger.getLogRetriever(false);
    std::cout << "Audit logs (unauthorized):" << std::endl;
    unauthorizedAuditor.displayLogs();

    return 0;
}

