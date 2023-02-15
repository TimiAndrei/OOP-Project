#include "Oferta.h"
#include "Produs.h"
#include "Exceptii.h"

template <typename T>
Oferta<T>::Oferta() {}

template <typename T>
Oferta<T>::Oferta(T reducere) : reducere(reducere) {}

template <typename T>
void Oferta<T>::operator()(std::shared_ptr<Produs> p)
{
    p->setPret(p->getPret() - reducere / 100.0 * p->getPret());
}

Oferta<int>::Oferta() {}

Oferta<int>::Oferta(int reducere) : reducere(reducere) {}

void Oferta<int>::operator()(std::shared_ptr<Produs> p)
{
    p->setPret(p->getPret() - reducere / 100.0 * p->getPret());
}

Oferta<std::string>::Oferta(std::string reducere) : Oferta<int>()
{
    int reducereInt;
    while (true)
    {
        try
        {
            reducereInt = std::stoi(reducere);
            break;
        }
        catch (const std::invalid_argument &)
        {
            std::cout << "Datele introduse sunt invalide, incercati sa introduceti numere intregi" << std::endl;
            std::cout << "Introduceti procentul de reducere:" << std::endl;
            fflush(stdin);
            std::getline(std::cin, reducere);
            fflush(stdin);
        }
    }
    *static_cast<Oferta<int> *>(this) = Oferta<int>(reducereInt);
}

void Oferta<std::string>::operator()(std::shared_ptr<Produs> p)
{
    Oferta<int>::operator()(p);
}