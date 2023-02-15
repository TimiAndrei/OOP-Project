#ifndef GAMESTOP_PS_H
#define GAMESTOP_PS_H

#include "Sistem_gaming.h"
#include <string>
#include <vector>
#include <memory>

class PS : public Sistem_gaming
{
    std::string versiune;
    std::vector<std::string> jocuri;

public:
    PS();

    //  PS(const std::string &tip, int garantie, std::string versiune, const std::vector<std::string> &jocuri);

    PS(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, const std::string &tip, int garantie, std::string versiune, const std::vector<std::string> &jocuri);

    ~PS() override;

    [[nodiscard]] const std::string &getVersiune() const;

    void setVersiune(const std::string &versiune);

    [[nodiscard]] const std::vector<std::string> &getJocuri() const;

    void setJocuri(const std::vector<std::string> &jocuri);

    friend std::ostream &operator<<(std::ostream &os, const PS &ps);

    friend std::istream &operator>>(std::istream &is, PS &ps);

    void afisare() override;

    std::unique_ptr<Produs> clone() const override;
};

#endif // GAMESTOP_PS_H
