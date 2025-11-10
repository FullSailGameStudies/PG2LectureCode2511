#include "Card.h"
#include <iostream>

int Card::Value() const
{
    int value = 0;
    if (face_ == "A") value = 1;
    else if (face_ == "J") value = 11;
    else if (face_ == "Q") value = 12;
    else if (face_ == "K") value = 13;
    else value = std::stoi(face_);
    return value;
}

void Card::Print() const
{
    std::cout << face_ << " " << suit_;
}


