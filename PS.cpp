#include "PS.h"

#include <utility>
#include <string>
#include <memory>

PS::PS() = default;

// PS::PS(const std::string &tip, int garantie, std::string versiune, const std::vector<std::string> &jocuri) : Sistem_gaming(tip, garantie), versiune(std::move(versiune)), jocuri(jocuri) {}

PS::PS(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, const std::string &tip, int garantie, std::string versiune, const std::vector<std::string> &jocuri) : Sistem_gaming(Nume, Descriere, Pret, Cantitate, tip, garantie), versiune(std::move(versiune)), jocuri(jocuri) {}

PS::~PS() = default;

const std::string &PS::getVersiune() const
{
    return versiune;
}

void PS::setVersiune(const std::string &versiune_)
{
    PS::versiune = versiune_;
}

const std::vector<std::string> &PS::getJocuri() const
{
    return jocuri;
}

void PS::setJocuri(const std::vector<std::string> &jocuri_)
{
    PS::jocuri = jocuri_;
}

std::ostream &operator<<(std::ostream &os, const PS &ps)
{
    os << dynamic_cast<const Produs &>(ps);
    os << "Versiune:" << ps.versiune << std::endl;
    os << "Jocuri:";
    for (const auto &joc : ps.jocuri)
    {
        os << joc << ", ";
    }
    os << "\b\b ";
    os << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, PS &ps)
{
    is >> dynamic_cast<Sistem_gaming &>(ps);
    std::cout << "Versiune:";
    fflush(stdin);
    std::getline(std::cin, ps.versiune);
    std::cout << "Cate jocuri vreti sa contina sistemul by default:";
    int n;
    is >> n;
    std::cout << "Introduceti jocurile:";
    for (int i = 0; i < n; i++)
    {
        std::string joc;
        fflush(stdin);
        std::getline(std::cin, joc);
        ps.jocuri.push_back(joc);
    }
    return is;
}

void PS::afisare()
{
    std::cout << *this;
}

std::unique_ptr<Produs> PS::clone() const
{
    return std::make_unique<PS>(*this);
}