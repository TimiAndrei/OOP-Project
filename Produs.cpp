#include "Produs.h"
#include "GenerateID.h"

#include <utility>
#include <string>
#include <memory>

Produs::Produs()
{
    this->ID = GenerateID::getInstance()->generateID();
    this->Pret = 0;
    this->Cantitate = 0;
}

Produs::Produs(std::string Nume, std::string Descriere, int Pret, int Cantitate) : Nume(std::move(Nume)), Descriere(std::move(Descriere)), Pret(Pret), Cantitate(Cantitate)
{
    this->ID = GenerateID::getInstance()->generateID();
}

Produs::Produs(const Produs &produs)
{
    this->ID = GenerateID::getInstance()->generateID();
    this->Nume = produs.Nume;
    this->Descriere = produs.Descriere;
    this->Pret = produs.Pret;
    this->Cantitate = produs.Cantitate;
} // constructor de copiere

Produs &Produs::operator=(const Produs &produs)
{
    this->ID = GenerateID::getInstance()->generateID();
    this->Nume = produs.Nume;
    this->Descriere = produs.Descriere;
    this->Pret = produs.Pret;
    this->Cantitate = produs.Cantitate;
    return *this;
}

Produs::~Produs() = default;

const std::string &Produs::getNume() const
{
    return Nume;
}

void Produs::setNume(const std::string &nume)
{
    Nume = nume;
}

const std::string &Produs::getDescriere() const
{
    return Descriere;
}

void Produs::setDescriere(const std::string &descriere)
{
    Descriere = descriere;
}

int Produs::getPret() const
{
    return Pret;
}

void Produs::setPret(int pret)
{
    Pret = pret;
}

int Produs::getCantitate() const
{
    return Cantitate;
}

void Produs::setCantitate(int cantitate)
{
    Cantitate = cantitate;
}

int Produs::getId() const
{
    return ID;
}

void Produs::setId(int id)
{
    ID = id;
}

std::ostream &operator<<(std::ostream &os, const Produs &produs)
{
    os << "ID:" << produs.ID << std::endl;
    os << "Nume:" << produs.Nume << std::endl;
    os << "Descriere:" << produs.Descriere << std::endl;
    os << "Pret:" << produs.Pret << std::endl;
    os << "Cantitate:" << produs.Cantitate << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Produs &produs)
{
    fflush(stdin);
    std::cout << "Nume:";
    std::getline(std::cin, produs.Nume);
    fflush(stdin);
    std::cout << "Descriere:";
    std::getline(std::cin, produs.Descriere);
    fflush(stdin);
    std::cout << "Pret:";
    is >> produs.Pret;
    std::cout << "Cantitate:";
    is >> produs.Cantitate;
    return is;
}

std::unique_ptr<Produs> Produs::clone() const
{
    return std::make_unique<Produs>(*this);
}

void Produs::afisare()
{
    std::cout << *this;
}
