#include "Magazin.h"
#include <algorithm>
#include "Oferta.h"

Magazin::Magazin() {}

Magazin::Magazin(const std::vector<std::string> &angajati,
                 const std::string &nume, const std::string &adresa, const std::vector<std::shared_ptr<Produs>> &produse) : produse(produse), angajati(angajati), nume(nume),
                                                                                                                            adresa(adresa) {}

const std::vector<std::shared_ptr<Produs>> &Magazin::getProduse() const
{
    return produse;
}

void Magazin::setProduse(const std::vector<std::shared_ptr<Produs>> &NewProduse)
{
    Magazin::produse = NewProduse;
}

const std::vector<std::string> &Magazin::getAngajati() const
{
    return angajati;
}

void Magazin::setAngajati(const std::vector<std::string> &NewAngajati)
{
    Magazin::angajati = NewAngajati;
}

const std::string &Magazin::getNume() const
{
    return nume;
}

void Magazin::setNume(const std::string &NewNume)
{
    Magazin::nume = NewNume;
}

const std::string &Magazin::getAdresa() const
{
    return adresa;
}

void Magazin::setAdresa(const std::string &NewAdresa)
{
    Magazin::adresa = NewAdresa;
}

void Magazin::adauga_produs(const std::shared_ptr<Produs> &NewProdus)
{
    produse.push_back(NewProdus);
}

void Magazin::sterge_produs(const std::shared_ptr<Produs> &NewProdus)
{
    int index = cauta_produs(NewProdus->getNume());
    if (index != -1)
    {
        produse.erase(produse.begin() + index);
    }
}

void Magazin::sterge_produs(const std::string &NewNume)
{
    int index = cauta_produs(NewNume);
    if (index != -1)
    {
        produse.erase(produse.begin() + index);
    }
}

int Magazin::cauta_produs(const std::string NewNume)
{
    // search for name and return index
    for (size_t i = 0; i < produse.size(); i++)
    {
        if (produse[i]->getNume() == NewNume)
            return i;
    }
    return -1;
}

const std::shared_ptr<Produs> &Magazin::get_produs(const std::string &NewNume)
{
    int index = cauta_produs(NewNume);
    return produse[index];
}

std::ostream &operator<<(std::ostream &os, const Magazin &magazin)
{
    os << "Nume Magazin: " << magazin.nume << std::endl;
    os << "Adresa: " << magazin.adresa << std::endl;
    os << "Angajati: ";
    for (const auto &angajat : magazin.angajati)
    {
        os << angajat << " ";
    }
    os << std::endl;
    os << "Produse: " << std::endl;
    os << "-----------------" << std::endl;
    for (const auto &produs : magazin.produse)
    {
        if (dynamic_cast<Joc *>(produs.get()))
        {
            os << "Joc: " << std::endl;
            os << *dynamic_cast<Joc *>(produs.get()) << std::endl;
        }
        else if (dynamic_cast<PC *>(produs.get()))
        {
            os << "PC: " << std::endl;
            os << *dynamic_cast<PC *>(produs.get()) << std::endl;
        }
        else if (dynamic_cast<Xbox *>(produs.get()))
        {
            os << "Xbox: " << std::endl;
            os << *dynamic_cast<Xbox *>(produs.get()) << std::endl;
        }
        else if (dynamic_cast<PS *>(produs.get()))
        {
            os << "PS: " << std::endl;
            os << *dynamic_cast<PS *>(produs.get()) << std::endl;
        }
    }
    return os;
}
Magazin *Magazin::getInstance()
{
    if (instance == nullptr)
        instance = new Magazin({"Ion", "Vasile", "Gheorghe"}, "GameStop", "Strada 1, nr. 1", {});

    return instance;
}

Magazin *Magazin::instance = nullptr;

void Magazin::Aplicare_oferta(std::string reducere)
{
    Oferta<std::string> oferta(reducere);
    Magazin *magazin = Magazin::getInstance();
    std::for_each(magazin->getProduse().begin(), magazin->getProduse().end(), oferta);
}
