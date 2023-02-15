#include "GenerateID.h"

int GenerateID::ID = 0;
GenerateID *GenerateID::instance = nullptr;

GenerateID::GenerateID() {}

int GenerateID::generateID()
{
    return ID++;
}

GenerateID *GenerateID::getInstance()
{
    if (instance == nullptr)
        instance = new GenerateID();

    return instance;
}