#include <iostream>
#include <stdexcept>
using namespace std;

class MyResource {
    int* data;

public:
    MyResource(int value) {
        data = new int(value);
        cout << "Resource acquired: " << *data << endl;
    }

    ~MyResource() {
        delete data;
        cout << "Resource released" << endl;
    }

    void useResource() {
        cout << "Using resource: " << *data << endl;
    }
};

void riskyFunction() {
    MyResource res(42); 
    res.useResource();

    throw runtime_error("Something went wrong!");
}

int main() {
    try {
        riskyFunction();
    }
    catch (const exception& ex) {
        cout << "Exception caught: " << ex.what() << endl;
    }

    return 0;
}
