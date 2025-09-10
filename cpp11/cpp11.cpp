#include "cpp11.h"

Cpp11* Cpp11::Instance = nullptr;

Cpp11& Cpp11::getInstance() {
    if (Instance == nullptr) {
        Instance = new Cpp11();
    }
    return *Instance;
}

void Cpp11::demo() {
    // Demonstration of some C++11 features
}