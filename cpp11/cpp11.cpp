#include "cpp11.h"

#include <vector>

Cpp11* Cpp11::Instance = nullptr;

Cpp11& Cpp11::getInstance() {
    if (Instance == nullptr) {
        Instance = new Cpp11();
    }
    return *Instance;
}

void Cpp11::demo() {
    braceOrEqualInitializersDemo();
}

void Cpp11::braceOrEqualInitializersDemo() {

    std::string str_eq = "equal sign initialization";
    std::string str_br {"brace initialization"};
    std::string str_lst {'l', 'i', 's', 't', ' ', 'i', 'n', 'i', 't',};

    std::vector<int> vec_eq = {1, 2, 3, 4, 5}; // equal sign list initialization

    struct Point {
        int x, y;
        Point(int x_val, int y_val) : x(x_val), y(y_val) {};
    };

    Point p1 = Point(10,10); // equal sign initialization
    Point p2 {30, 40};   // brace initialization
}