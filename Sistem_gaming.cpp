#include "Sistem_gaming.h"
#include <string>
#include <utility>
#include <memory>

Sistem_gaming::Sistem_gaming()
{
    this->Garantie = 0;
}

Sistem_gaming::Sistem_gaming(std::string tip, int garantie) : Tip(std::move(tip)), Garantie(garantie) {}

Sistem_gaming::Sistem_gaming(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, std::string Tip, int Garantie) : Produs(Nume, Descriere, Pret, Cantitate), Tip(std::move(Tip)), Garantie(Garantie) {}

Sistem_gaming::~Sistem_gaming() = default;

const std::string &Sistem_gaming::getTip() const
{
    return Tip;
}

void Sistem_gaming::setTip(const std::string &tip)
{
    this->Tip = tip;
}

int Sistem_gaming::getGarantie() const
{
    return Garantie;
}

void Sistem_gaming::setGarantie(int garantie)
{
    this->Garantie = garantie;
}

std::ostream &operator<<(std::ostream &os, const Sistem_gaming &sistemGaming)
{
    os << dynamic_cast<const Produs &>(sistemGaming);
    os << "Tip:" << sistemGaming.Tip << std::endl;
    os << "Garantie:" << sistemGaming.Garantie << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Sistem_gaming &sistemGaming)
{
    is >> dynamic_cast<Produs &>(sistemGaming);
    std::cout << "Tip:";
    fflush(stdin);
    std::getline(std::cin, sistemGaming.Tip);
    std::cout << "Garantie:";
    is >> sistemGaming.Garantie;
    return is;
}

std::unique_ptr<Produs> Sistem_gaming::clone() const
{
    return std::make_unique<Sistem_gaming>(*this);
}
