#include "Exceptii.h"

// TextureFail implementation
const char* TextureFail::what() const noexcept {
    return "Texture failure occurred";
}

// DoodleException implementation
DoodleException::DoodleException() : message("Doodle occurred") {}

const char* DoodleException::what() const noexcept {
    return message.c_str();
}

void DoodleException::setMessage(const std::string& message1) {
    this->message = message1;
}

// DoodleCollisionException implementation
DoodleCollisionException::DoodleCollisionException() : DoodleException() {
    setMessage("DoodleCollision occurred");
}

// DoodleOutOfScreenException implementation
DoodleOutOfScreenException::DoodleOutOfScreenException() : DoodleException() {
    setMessage("DoodleOutOfScreenException occurred");
}

// GameOverException implementation
GameOverException::GameOverException() : DoodleException() {
    setMessage("GameOverException occurred");
}