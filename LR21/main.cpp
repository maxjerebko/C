#include <iostream>
#include <sstream>

class Flight {
public:
    Flight();
    Flight(int flightId, int maxSeats, int bookedSeats);
    void displayStatus();
    bool bookSeats(int seatsToBook);
    bool releaseSeats(int seatsToCancel);

    int getFlightId() const {
        return flightId;
    }

private:
    int flightId;
    int seatCapacity;
    int currentReservations;
    int getReservationLimit();
};

Flight::Flight() : flightId(0), seatCapacity(0), currentReservations(0) {}

Flight::Flight(int flightId, int maxSeats, int bookedSeats) {
    this->flightId = flightId;
    this->seatCapacity = maxSeats;

    if (bookedSeats < 0) {
        this->currentReservations = 0;
    } else if (bookedSeats > getReservationLimit()) {
        this->currentReservations = getReservationLimit();
    } else {
        this->currentReservations = bookedSeats;
    }
}

void Flight::displayStatus() {
    double loadFactor = (static_cast<double>(currentReservations) / static_cast<double>(seatCapacity)) * 100;
    std::cout << "Flight " << flightId << ": " << currentReservations << "/" << seatCapacity << " (" << loadFactor << "%) seats taken" << std::endl;
}

int Flight::getReservationLimit() {
    return static_cast<int>(seatCapacity * 1.05 + 0.5);
}

bool Flight::bookSeats(int seatsToBook) {
    if (seatsToBook < 0) return false;
    if (currentReservations + seatsToBook <= getReservationLimit()) {
        currentReservations += seatsToBook;
        return true;
    }
    return false;
}

bool Flight::releaseSeats(int seatsToCancel) {
    if (seatsToCancel < 0) return false;
    if (currentReservations - seatsToCancel >= 0) {
        currentReservations -= seatsToCancel;
        return true;
    }
    return false;
}

bool interpretInput(const std::string& userInput, std::string& command, int& flightId, int& value) {
    std::istringstream inputStream(userInput);
    inputStream >> command;

    if (command == "quit") return true;
    if (!(inputStream >> flightId)) return false;

    if (command == "create" || command == "add" || command == "cancel") {
        if (!(inputStream >> value)) return false;
    } else {
        value = -1;
    }

    return true;
}

int main() {
    const int MAX_FLIGHT_COUNT = 10;
    Flight flightList[MAX_FLIGHT_COUNT];

    std::string inputLine;
    std::string command;
    int flightId, value;

    while (true) {
        std::cout << "What would you like to do? ";
        std::getline(std::cin, inputLine);

        if (!interpretInput(inputLine, command, flightId, value)) {
            std::cout << "Invalid command format\n\n";
            continue;
        }

        if (command == "quit") break;

        if (command == "create") {
            bool created = false;
            for (int i = 0; i < MAX_FLIGHT_COUNT; ++i) {
                if (flightList[i].getFlightId() == 0) {
                    flightList[i] = Flight(flightId, value, 0);
                    created = true;
                    break;
                }
            }
            if (!created) std::cout << "Flight creation failed: maximum flight limit reached\n";
        } else if (command == "delete") {
            bool found = false;
            for (int i = 0; i < MAX_FLIGHT_COUNT; ++i) {
                if (flightList[i].getFlightId() == flightId) {
                    flightList[i] = Flight();
                    found = true;
                    break;
                }
            }
            if (!found) std::cout << "Cannot delete: flight " << flightId << " not found\n";
        } else if (command == "add") {
            bool success = false;
            for (int i = 0; i < MAX_FLIGHT_COUNT; ++i) {
                if (flightList[i].getFlightId() == flightId) {
                    if (!flightList[i].bookSeats(value)) {
                        std::cout << "Booking failed: flight is full\n";
                    }
                    success = true;
                    break;
                }
            }
            if (!success) std::cout << "Booking failed: flight " << flightId << " not found\n";
        } else if (command == "cancel") {
            bool success = false;
            for (int i = 0; i < MAX_FLIGHT_COUNT; ++i) {
                if (flightList[i].getFlightId() == flightId) {
                    if (!flightList[i].releaseSeats(value)) {
                        std::cout << "Cancellation failed: not enough reservations\n";
                    }
                    success = true;
                    break;
                }
            }
            if (!success) std::cout << "Cancellation failed: flight " << flightId << " not found\n";
        }

        bool flightsAvailable = false;
        for (int i = 0; i < MAX_FLIGHT_COUNT; ++i) {
            if (flightList[i].getFlightId() != 0) {
                flightList[i].displayStatus();
                flightsAvailable = true;
            }
        }
        if (!flightsAvailable) {
            std::cout << "No flights currently in the system\n";
        }

        std::cout << std::endl;
    }

    return 0;
}

