#include "exception.h"
#include <SFML/Graphics.hpp>

Exception::Exception(std::string message) { //Constructor for exception class 
    msg = message;
};
std::string Exception::getMsg() { //Method for getting message of exception
    return msg;
}