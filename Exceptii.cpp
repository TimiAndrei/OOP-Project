#include "Exceptii.h"

const char *invalidName::what() const noexcept
{
    return "Nu exista un produs cu numele acesta in stoc!";
}

const char *invalidOption::what() const noexcept
{
    return "Optiunea introdusa nu este valida!";
}
