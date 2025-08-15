#include <iostream>
#include <vector>
#include <string>

class Room {
public:
    int roomNumber;
    std::string host;
    std::string startTime;
    std::string endTime;
    int chairCapacity;
    bool isBooked;

    Room(int rn) : roomNumber(rn), chairCapacity(0), isBooked(false) {}

    void bookRoom(const std::string& host, const std::string& startTime, const std::string& endTime, int chairCapacity) {
        this->host = host;
        this->startTime = startTime;
        this->endTime = endTime;
        this->chairCapacity = chairCapacity;
        this->isBooked = true;
    }

    void displayStatus() {
        if (isBooked) {
            std::cout << "Room " << roomNumber << " is booked.\n";
            std::cout << "Host: " << host << "\n";
            std::cout << "Start Time: " << startTime << "\n";
            std::cout << "End Time: " << endTime << "\n";
            std::cout << "Chair Capacity: " << chairCapacity << "\n";
        } else {
            std::cout << "Room " << roomNumber << " is available.\n";
        }
    }
};

class RoomAllotmentSystem {
public:
    std::vector<Room> rooms;

    RoomAllotmentSystem(int numRooms) {
        for (int i = 1; i <= numRooms; ++i) {
            rooms.push_back(Room(i));
        }
    }

    void bookRoom() {
        int roomNumber, chairCapacity;
        std::string host, startTime, endTime;

        std::cout << "Enter room number to book: ";
        std::cin >> roomNumber;
        std::cout << "Enter host name: ";
        std::cin.ignore();
        std::getline(std::cin, host);
        std::cout << "Enter start time: ";
        std::getline(std::cin, startTime);
        std::cout << "Enter end time: ";
        std::getline(std::cin, endTime);
        std::cout << "Enter chair capacity: ";
        std::cin >> chairCapacity;

        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].bookRoom(host, startTime, endTime, chairCapacity);
            std::cout << "Room " << roomNumber << " booked successfully.\n";
        } else {
            std::cout << "Invalid room number.\n";
        }
    }

    void checkRoomStatus() {
        int roomNumber;
        std::cout << "Enter room number to check status: ";
        std::cin >> roomNumber;

        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].displayStatus();
        } else {
            std::cout << "Invalid room number.\n";
        }
    }
};

int main() {
    int numRooms, choice;
    std::cout << "Enter the number of rooms available: ";
    std::cin >> numRooms;
    RoomAllotmentSystem system(numRooms);

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Book a room\n";
        std::cout << "2. Check room status\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                system.bookRoom();
                break;
            case 2:
                system.checkRoomStatus();
                break;
            case 3:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
