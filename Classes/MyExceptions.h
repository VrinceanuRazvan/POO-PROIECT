#ifndef OOP_MYEXCEPTIONS_H
#define OOP_MYEXCEPTIONS_H

#include <stdexcept>
#include "exception"


class ExceptieGenerala : public std::exception {
public:
    const char *what() const noexcept override {
        return "Exceptie generala!";
    }
};

class ExceptieHp : public ExceptieGenerala {
public:
    const char *what() const noexcept override {
        return "Hp negativ";
    }
};

class ExceptieMovementSpeed : public ExceptieGenerala {
public:
    const char *what() const noexcept override {
        return "MovementSpeed Negativ";
    }
};


#endif //OOP_MYEXCEPTIONS_H
