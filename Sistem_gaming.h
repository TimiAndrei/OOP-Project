#ifndef GAMESTOP_SISTEM_GAMING_H
#define GAMESTOP_SISTEM_GAMING_H

#include "Produs.h"
#include <string>
#include <memory>

class Sistem_gaming : public Produs
{
    std::string Tip;
    int Garantie;

public:
    Sistem_gaming();

    Sistem_gaming(std::string Tip, int Garantie);

    Sistem_gaming(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, std::string Tip, int Garantie);

    ~Sistem_gaming() override;

    [[nodiscard]] const std::string &getTip() const;

    void setTip(const std::string &tip);

    [[nodiscard]] int getGarantie() const;

    void setGarantie(int garantie);

    friend std::ostream &operator<<(std::ostream &os, const Sistem_gaming &sistemGaming);

    friend std::istream &operator>>(std::istream &is, Sistem_gaming &sistemGaming);

    std::unique_ptr<Produs> clone() const override;
};

#endif // GAMESTOP_SISTEM_GAMING_H
