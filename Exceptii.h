//
// Created by timia on 12/11/2022.
//

#ifndef GAMESTOP_EXCEPTII_H
#define GAMESTOP_EXCEPTII_H

#include <exception>

class invalidName : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

class invalidOption : public std::exception
{
public:
    [[nodiscard]] const char *what() const noexcept override;
};

#endif // GAMESTOP_EXCEPTII_H
