#include <iostream>
#include <vector>
#include <string>

class Flight {
private:
    std::string flightNumber;
    std::string departure;
    std::string arrival;
    int capacity;
    int bookedSeats;
    std::vector<std::string> bookedPassengers;

    // Private helper function to check if the seat booking is valid
    bool isSeatAvailable() const {
        return bookedSeats < capacity;
    }

    // Private helper function to check if the passenger is already booked
    bool isPassengerBooked(const std::string& passengerName) const {
        for (const auto& passenger : bookedPassengers) {
            if (passenger == passengerName) {
                return true;
            }
        }
        return false;
    }

public:
    // Constructor
    Flight(std::string fNumber, std::string dep, std::string arr, int cap)
        : flightNumber(fNumber), departure(dep), arrival(arr), capacity(cap), bookedSeats(0) {}

    // Method to book a seat
    bool bookSeat(const std::string& passengerName) {
        if (isSeatAvailable() && !isPassengerBooked(passengerName)) {
            bookedPassengers.push_back(passengerName);
            bookedSeats++;
            std::cout << "Seat booked for " << passengerName << " on flight " << flightNumber << std::endl;
            return true;
        }
        std::cout << "Booking failed for " << passengerName << ". No seats available or already booked." << std::endl;
        return false;
    }

    // Method to cancel a seat
    bool cancelSeat(const std::string& passengerName) {
        for (auto it = bookedPassengers.begin(); it != bookedPassengers.end(); ++it) {
            if (*it == passengerName) {
                bookedPassengers.erase(it);
                bookedSeats--;
                std::cout << "Seat canceled for " << passengerName << " on flight " << flightNumber << std::endl;
                return true;
            }
        }
        std::cout << "Cancelation failed for " << passengerName << ". No booking found." << std::endl;
        return false;
    }

    // Method to upgrade a seat (assuming upgrade is just a message for simplicity)
    void upgradeSeat(const std::string& passengerName) {
        if (isPassengerBooked(passengerName)) {
            std::cout << "Upgrade successful for " << passengerName << " on flight " << flightNumber << std::endl;
        } else {
            std::cout << "Upgrade failed for " << passengerName << ". No booking found." << std::endl;
        }
    }

    // Method to display flight details
    void displayFlightDetails() const {
        std::cout << "Flight: " << flightNumber << "\nDeparture: " << departure << "\nArrival: " << arrival
                  << "\nCapacity: " << capacity << "\nBooked Seats: " << bookedSeats << std::endl;
    }

    // Getter for available seats
    int getAvailableSeats() const {
        return capacity - bookedSeats;
    }
};

class Passenger {
private:
    std::string id;
    std::string name;

public:
    // Constructor
    Passenger(std::string passengerId, std::string passengerName) : id(passengerId), name(passengerName) {}

    // Method to request booking
    bool requestBooking(Flight& flight) {
        return flight.bookSeat(name);
    }

    // Method to request seat cancellation
    bool requestCancellation(Flight& flight) {
        return flight.cancelSeat(name);
    }

    // Method to request seat upgrade
    void requestUpgrade(Flight& flight) {
        flight.upgradeSeat(name);
    }

    // Getter for name
    std::string getName() const {
        return name;
    }
};

int main() {
    // Create some flight objects
    Flight flightA("AA123", "New York", "Los Angeles", 3);
    Flight flightB("BB456", "Chicago", "Miami", 2);

    // Create some passenger objects
    Passenger passenger1("P001", "Alice");
    Passenger passenger2("P002", "Bob");
    Passenger passenger3("P003", "Charlie");
    Passenger passenger4("P004", "David");

    // Display flight details
    flightA.displayFlightDetails();
    flightB.displayFlightDetails();

    // Passengers requesting bookings
    passenger1.requestBooking(flightA);
    passenger2.requestBooking(flightA);
    passenger3.requestBooking(flightA); // Should succeed
    passenger4.requestBooking(flightA); // Should fail (no seats available)

    // Cancel a seat and re-book
    passenger2.requestCancellation(flightA);
    passenger2.requestBooking(flightA); // Should succeed now

    // Try upgrading seats
    passenger1.requestUpgrade(flightA); // Should succeed
    passenger4.requestUpgrade(flightA); // Should fail

    // Final flight details
    flightA.displayFlightDetails();
    flightB.displayFlightDetails();

    return 0;
}

