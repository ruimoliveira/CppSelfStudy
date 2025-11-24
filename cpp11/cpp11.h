#pragma once
#ifndef CPP11_H
#define CPP11_H

class Cpp11 {
    private:
        Cpp11() = default;
        ~Cpp11() = default;

    public:
        Cpp11(Cpp11& other) = delete;
        Cpp11& operator=(const Cpp11&) = delete;

    public:
        static Cpp11* Instance;
        static Cpp11& getInstance();
        void demo();

    private:
        //simple feature demos
        void braceOrEqualInitializersDemo();
        void autoKeywordDemo();
};

#endif // CPP11_H