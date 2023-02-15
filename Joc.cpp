//
// Created by timia on 12/6/2022.
//

#include "Joc.h"

#include <utility>
#include <memory>

Joc::Joc() = default;

Joc::Joc(const std::string &nume, const std::string &descriere, int pret, int cantitate, std::string gen, std::string platforma, int gameHours, int minAge) : Produs(nume, descriere, pret, cantitate),
                                                                                                                                                              Gen(std::move(gen)),
                                                                                                                                                              Platforma(std::move(platforma)),
                                                                                                                                                              Game_hours(gameHours),
                                                                                                                                                              Min_age(minAge) {}

Joc::~Joc() = default;

const std::string &Joc::getGen() const
{
    return Gen;
}

void Joc::setGen(const std::string &gen)
{
    Joc::Gen = gen;
}

const std::string &Joc::getPlatforma() const
{
    return Platforma;
}

void Joc::setPlatforma(const std::string &platforma)
{
    Joc::Platforma = platforma;
}

int Joc::getGameHours() const
{
    return Game_hours;
}

void Joc::setGameHours(int gameHours)
{
    Game_hours = gameHours;
}

int Joc::getMinAge() const
{
    return Min_age;
}

void Joc::setMinAge(int minAge)
{
    Min_age = minAge;
}

std::ostream &operator<<(std::ostream &os, const Joc &joc)
{
    os << dynamic_cast<const Produs &>(joc);
    os << "Gen:" << joc.Gen << std::endl;
    os << "Platforma:" << joc.Platforma << std::endl;
    os << "Game hours:" << joc.Game_hours << std::endl;
    os << "Min age:" << joc.Min_age << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Joc &joc)
{
    is >> dynamic_cast<Produs &>(joc);
    std::cout << "Gen:";
    is >> joc.Gen;
    std::cout << "Platforma:";
    is >> joc.Platforma;
    std::cout << "Game hours:";
    is >> joc.Game_hours;
    std::cout << "Min age:";
    is >> joc.Min_age;
    return is;
}

void Joc::afisare()
{
    std::cout << *this;
}

std::unique_ptr<Produs> Joc::clone() const
{
    return std::make_unique<Joc>(*this);
}
