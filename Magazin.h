#ifndef GAMESTOP_MAGAZIN_H
#define GAMESTOP_MAGAZIN_H

#include "Produs.h"
#include "Sistem_gaming.h"
#include "PC.h"
#include "Xbox.h"
#include "PS.h"
#include "Joc.h"
#include "Oferta.h"
#include <memory>
#include <vector>
#include <string>

class Magazin
{
    std::vector<std::shared_ptr<Produs>> produse;
    std::vector<std::string> angajati;
    std::string nume;
    std::string adresa;
    static Magazin *instance;
    Magazin();
    Magazin(const std::vector<std::string> &angajati, const std::string &nume, const std::string &adresa, const std::vector<std::shared_ptr<Produs>> &produse = {});

public:
    static Magazin *getInstance();

    const std::vector<std::shared_ptr<Produs>> &getProduse() const;

    void setProduse(const std::vector<std::shared_ptr<Produs>> &produse);

    const std::vector<std::string> &getAngajati() const;

    void setAngajati(const std::vector<std::string> &angajati);

    const std::string &getNume() const;

    void setNume(const std::string &nume);

    const std::string &getAdresa() const;

    void setAdresa(const std::string &adresa);

    void adauga_produs(const std::shared_ptr<Produs> &produs);

    void sterge_produs(const std::shared_ptr<Produs> &produs);

    void sterge_produs(const std::string &nume);

    const std::shared_ptr<Produs> &get_produs(const std::string &nume);

    int cauta_produs(const std::string nume);

    friend std::ostream &operator<<(std::ostream &os, const Magazin &magazin);

    void Aplicare_oferta(std::string reducere);

    template <typename T>
    void actualizeazaPret(std::shared_ptr<T> produs)
    {
        if (auto sistem = dynamic_cast<Sistem_gaming *>(produs.get()))
            sistem->setPret(sistem->getPret() + sistem->getPret() * 0.15);
        else if (auto joc = dynamic_cast<Joc *>(produs.get()))
        {
            if (joc->getGameHours() >= 100)
            {
                joc->setPret(joc->getPret() * 1.5);
            }
            else if (joc->getGameHours() >= 50)
            {
                joc->setPret(joc->getPret() * 1.25);
            }
            else
            {
                joc->setPret(joc->getPret() * 1.1);
            }
        }
        else
            produs->setPret(produs->getPret() + produs->getPret() * 0.1);
    }
};

#endif // GAMESTOP_MAGAZIN_H
