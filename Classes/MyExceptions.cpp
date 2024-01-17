#include "MyExceptions.h"

const char *MyException::what() const noexcept {
    return "MyException: An exception occurred.";
}

CustomError::CustomError(const std::string &message) : errorMessage(message) {}

const char *CustomError::what() const noexcept {
    return errorMessage.c_str();
}

const char *AnotherError::what() const noexcept {
    return "AnotherError: Another exception occurred.";
}

const char *CriticalError::what() const noexcept {
    return "CriticalError: A critical exception occurred.";
}

FileError::FileError(const std::string &file) : fileName(file) {}

const char *FileError::what() const noexcept {
    return ("FileError: An error occurred with file " + fileName).c_str();
}
