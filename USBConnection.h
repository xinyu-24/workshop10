#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>
#include <memory>
#include <stdexcept>

class USBConnection {
public:
    // Destructor
    ~USBConnection() {
        ids.push(id);
    }

    // Static function to create new USBConnection objects
    static USBConnection* CreateUsbConnection() {
        if (ids.empty()) {
            return nullptr; // No available USB ports
        }
        return new USBConnection(ids.top());
    }

    // Function to get the ID of the connection
    int get_id() const {
        return id;
    }

private:
    // Private constructor
    USBConnection(int id) : id(id) {
        ids.pop();
    }

    int id; // ID of the USB connection

    // Static stack to manage available IDs
    static std::stack<int> ids;
};

// Initialize the static stack with IDs 3, 2, and 1
std::stack<int> USBConnection::ids({3, 2, 1});

#endif // USBCONNECTION_H
