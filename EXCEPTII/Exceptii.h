#pragma once
#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H

#include <iostream>
#include <exception>
#include <string>

class TextureFail : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override;
};

class DoodleException : public std::exception {
private:
    std::string message;

public:
    explicit DoodleException();
    ~DoodleException() noexcept override = default;

    [[nodiscard]] const char* what() const noexcept override;
    void setMessage(const std::string& message1);
};

class DoodleCollisionException : public DoodleException {
public:
    explicit DoodleCollisionException();
};

class DoodleOutOfScreenException : public DoodleException {
public:
    explicit DoodleOutOfScreenException();
};

class GameOverException : public DoodleException {
public:
    explicit GameOverException();
};

#endif // OOP_EXCEPTIONS_H
