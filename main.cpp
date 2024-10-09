#include <iostream>
#include "USBConnection.h"

using namespace std;

int main() {
    int max_usb_ports = 10;
    USBConnection* c[max_usb_ports];

    for (int i = 0; i < max_usb_ports; i++) {
        // CreateUsbConnection is a static function
        // it creates a new object of USBConnection ...
        // if a port is available
        c[i] = USBConnection::CreateUsbConnection();
        if (c[i] != nullptr) {
            cout << "USB connection with ID = " << c[i]->get_id() << " was created\n";
        } else {
            cout << "no more USB ports available\n";
        }
    }

    // let's unplug one USB connection
    delete c[1];
    c[1] = nullptr;

    // this should return ID 2 to the stack
    USBConnection* a = USBConnection::CreateUsbConnection();
    if (a != nullptr) {
        cout << "USB connection with ID = " << a->get_id() << " was created\n";
    } else {
        cout << "no more USB ports available\n";
    }

    // Clean up remaining connections
    for (int i = 0; i < max_usb_ports; i++) {
        delete c[i];
    }

    return 0;
}
