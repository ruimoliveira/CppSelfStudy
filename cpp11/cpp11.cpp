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
    autoKeywordDemo();
    decltypeKeywordDemo();
}

struct Point {
    int x, y;
    Point(int x_val, int y_val) : x(x_val), y(y_val) {};
};

void Cpp11::braceOrEqualInitializersDemo() {
    std::string str_eq = "equal sign initialization";
    std::string str_br {"brace initialization"};
    std::string str_lst {'l', 'i', 's', 't', ' ', 'i', 'n', 'i', 't',};

    std::vector<int> vec_eq = {1, 2, 3, 4, 5}; // equal sign list initialization

    Point p1 = Point(10,10); // equal sign initialization
    Point p2 {30, 40};   // brace initialization
}

void Cpp11::autoKeywordDemo() {
    auto x{1}; // infers type int
    const auto y = 3.14; // infers type const double
    auto cstring = "char*"; // infers type char*
    auto b = true; // infers type bool
    auto p = Point(5, 10); // infers type Point

    auto ptr = &p; // infers type Point*
    auto& ref = x; // infers type int&
    auto&& rvalueRef = 2.71; // infers type int&&
    
    auto list = {1, 2, 3, 4, 5}; // infers type std::initializer_list<int>
    auto it = list.begin(); // infers type std::initializer_list<int>::iterator
    
    auto func = [](int a, int b) { return a + b; }; // infers type of lambda function
    auto funcPtr = &Cpp11::demo; // infers type void (Cpp11::*)()
}

template<typename T>
struct GenericClass {
    T value;
    public:
    GenericClass(T val) : value(val) {}
    const T& getValue() const { return value; }
    void setValue(T val) { value = val; }
};

template<typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a + b) { // trailing return type
    return a + b;
}

void Cpp11::decltypeKeywordDemo() {
    auto integer = add(5, 10); // infers type int
    auto floating = add(3.14, 2.71); // infers type double
    auto mixed = add(5, 2.71); // infers type double
    auto str = add(std::string("Hello, "), std::string("World!")); // infers type std::string

    GenericClass<int> intObj(42);
    decltype(intObj.getValue()) intRef = intObj.getValue(); // infers type const int&
}