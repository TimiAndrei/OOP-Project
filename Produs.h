#ifndef GAMESTOP_PRODUS_H
#define GAMESTOP_PRODUS_H

#include <string>
#include <iostream>
#include <memory>

class Produs
{
protected:
    std::string Nume;
    std::string Descriere;
    int Pret;
    int Cantitate;
    int ID;

public:
    Produs();

    Produs(std::string Nume, std::string Descriere, int Pret, int Cantitate);

    Produs(const Produs &produs);

    Produs &operator=(const Produs &produs);

    virtual ~Produs();

    [[nodiscard]] const std::string &getNume() const;

    void setNume(const std::string &nume);

    [[nodiscard]] const std::string &getDescriere() const;

    void setDescriere(const std::string &descriere);

    [[nodiscard]] int getPret() const;

    void setPret(int pret);

    [[nodiscard]] int getCantitate() const;

    void setCantitate(int cantitate);

    [[nodiscard]] int getId() const;

    void setId(int id);

    friend class Magazin;

    friend std::ostream &operator<<(std::ostream &os, const Produs &produs);
    friend std::istream &operator>>(std::istream &is, Produs &produs);

    virtual void afisare();

    virtual std::unique_ptr<Produs> clone() const;
};
#endif // GAMESTOP_PRODUS_H
