#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

#include <stdexcept>
#include <string>

class MyException : public std::exception {
public:
    const char *what() const noexcept override;
};

class CustomError : public std::exception {
public:
    explicit CustomError(const std::string &message);

    const char *what() const noexcept override;

private:
    std::string errorMessage;
};

class AnotherError : public std::exception {
public:
    const char *what() const noexcept override;
};

class CriticalError : public std::exception {
public:
    const char *what() const noexcept override;
};

class FileError : public std::exception {
public:
    explicit FileError(const std::string &file);
    const char *what() const noexcept override;

private:
    std::string fileName;
};

#endif // MYEXCEPTIONS_H
