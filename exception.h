#pragma once
#include <SFML/Graphics.hpp>

class Exception {
private:
    std::string msg; //private msg of error
public:
    Exception(std::string message); //Constructor for exception class 
    std::string getMsg(); //Method for getting message of exception
};