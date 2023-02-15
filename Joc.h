//
// Created by timia on 12/6/2022.
//

#ifndef GAMESTOP_JOC_H
#define GAMESTOP_JOC_H

#include "Produs.h"
#include <string>
#include <memory>

class Joc : public Produs
{
    std::string Gen;
    std::string Platforma;
    int Game_hours;
    int Min_age;

public:
    Joc();

    Joc(const std::string &nume, const std::string &descriere, int pret, int cantitate, std::string gen,
        std::string platforma, int gameHours, int minAge);

    ~Joc() override;

    [[nodiscard]] const std::string &getGen() const;

    void setGen(const std::string &gen);

    [[nodiscard]] const std::string &getPlatforma() const;

    void setPlatforma(const std::string &platforma);

    [[nodiscard]] int getGameHours() const;

    void setGameHours(int gameHours);

    [[nodiscard]] int getMinAge() const;

    void setMinAge(int minAge);

    friend std::istream &operator>>(std::istream &is, Joc &joc);

    friend std::ostream &operator<<(std::ostream &os, const Joc &joc);

    void afisare() override;

    std::unique_ptr<Produs> clone() const override;
};

#endif // GAMESTOP_JOC_H
