#ifndef GAMESTOP_OFERTA_H
#define GAMESTOP_OFERTA_H

#include "Produs.h"

template <typename T>
class Oferta
{
private:
    T reducere;

public:
    Oferta();
    Oferta(T reducere);
    void operator()(std::shared_ptr<Produs> p);
};

template <>
class Oferta<int> // specializare pentru int
{
private:
    int reducere;

public:
    Oferta();
    Oferta(int reducere);
    void operator()(std::shared_ptr<Produs> p);
};

template <>
class Oferta<std::string> : public Oferta<int> // specializare pentru string
{
public:
    using Oferta<int>::Oferta;
    Oferta(std::string reducere);
    void operator()(std::shared_ptr<Produs> p);
};

#endif // GAMESTOP_OFERTA_H
