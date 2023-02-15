#ifndef GAMESTOP_PC_H
#define GAMESTOP_PC_H

#include "Sistem_gaming.h"
#include <string>
#include <vector>
#include <memory>

class PC : public Sistem_gaming
{
    std::string procesor;
    std::string placa_video;
    int memorie_ram;
    int memorie_stocare;

public:
    PC();

    PC(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, const std::string &tip, int garantie, std::string procesor, std::string placaVideo, int memorieRam,
       int memorieStocare);

    ~PC() override;

    [[nodiscard]] const std::string &getProcesor() const;

    void setProcesor(const std::string &procesor);

    [[nodiscard]] const std::string &getPlacaVideo() const;

    void setPlacaVideo(const std::string &placaVideo);

    [[nodiscard]] int getMemorieRam() const;

    void setMemorieRam(int memorieRam);

    [[nodiscard]] int getMemorieStocare() const;

    void setMemorieStocare(int memorieStocare);

    friend std::ostream &operator<<(std::ostream &os, const PC &pc);

    friend std::istream &operator>>(std::istream &is, PC &pc);

    void afisare() override;

    std::unique_ptr<Produs> clone() const override;
};

#endif // GAMESTOP_PC_H
