#ifndef MY_EXCEPTIONS_H
#define MY_EXCEPTIONS_H

#include <stdexcept>

class MyException : public std::exception {
public:
    const char *what() const noexcept override;
};

class CustomError : public MyException {
private:
    std::string errorMessage;

public:
    explicit CustomError(const std::string &message);

    const char *what() const noexcept override;
};

class AnotherError : public MyException {
public:
    const char *what() const noexcept override;
};

class CriticalError : public MyException {
public:
    const char *what() const noexcept override;
};

class FileError : public MyException {
private:
    std::string fileName;

public:
    explicit FileError(const std::string &file);

    const char *what() const noexcept override;
};

#endif // MY_EXCEPTIONS_H
