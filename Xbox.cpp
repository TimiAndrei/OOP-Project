#include "Xbox.h"
#include <string>
#include <utility>
#include <memory>

Xbox::Xbox() = default;

// Xbox::Xbox(const std::string &tip, int garantie, std::string versiune, const std::vector<std::string> &jocuri) : Sistem_gaming(tip, garantie), versiune(std::move(versiune)), jocuri(jocuri) {}

Xbox::Xbox(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, const std::string &tip, int garantie, std::string versiune, const std::vector<std::string> &jocuri) : Sistem_gaming(Nume, Descriere, Pret, Cantitate, tip, garantie), versiune(std::move(versiune)), jocuri(jocuri) {}

Xbox::~Xbox() = default;

const std::string &Xbox::getVersiune() const
{
    return versiune;
}

void Xbox::setVersiune(const std::string &versiune_)
{
    Xbox::versiune = versiune_;
}

const std::vector<std::string> &Xbox::getJocuri() const
{
    return jocuri;
}

void Xbox::setJocuri(const std::vector<std::string> &jocuri_)
{
    Xbox::jocuri = jocuri_;
}

std::ostream &operator<<(std::ostream &os, const Xbox &xbox)
{
    os << dynamic_cast<const Produs &>(xbox);
    os << "Versiune:" << xbox.versiune << std::endl;
    os << "Jocuri:";
    for (const auto &joc : xbox.jocuri)
    {
        os << joc << ", ";
    }
    // delete the last 2 spaces
    std::cout << "\b\b ";
    os << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, Xbox &xbox)
{
    is >> dynamic_cast<Sistem_gaming &>(xbox);
    std::cout << "Versiune:";
    fflush(stdin);
    std::getline(std::cin, xbox.versiune);
    std::cout << "Cate jocuri vreti sa contina sistemul by default:";
    int n;
    is >> n;
    std::cout << "Introduceti jocurile:";
    for (int i = 0; i < n; i++)
    {
        std::string joc;
        fflush(stdin);
        std::getline(std::cin, joc);
        xbox.jocuri.push_back(joc);
    }
    return is;
}

void Xbox::afisare()
{
    std::cout << *this;
}

std::unique_ptr<Produs> Xbox::clone() const
{
    return std::make_unique<Xbox>(*this);
}