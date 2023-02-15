#ifndef GAMESTOP_XBOX_H
#define GAMESTOP_XBOX_H

#include "Sistem_gaming.h"
#include <string>
#include <vector>
#include <memory>

class Xbox : public Sistem_gaming
{
    std::string versiune;
    std::vector<std::string> jocuri; // jocuri bonus la cumparare

public:
    Xbox();

    Xbox(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, const std::string &tip, int garantie, std::string versiune, const std::vector<std::string> &jocuri);

    ~Xbox() override;

    [[nodiscard]] const std::string &getVersiune() const;

    void setVersiune(const std::string &versiune);

    [[nodiscard]] const std::vector<std::string> &getJocuri() const;

    void setJocuri(const std::vector<std::string> &jocuri);

    friend std::ostream &operator<<(std::ostream &os, const Xbox &xbox);

    friend std::istream &operator>>(std::istream &is, Xbox &xbox);

    void afisare() override;

    std::unique_ptr<Produs> clone() const override;
};

#endif // GAMESTOP_XBOX_H
