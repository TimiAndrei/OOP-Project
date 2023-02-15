#include "PC.h"
#include <string>
#include <utility>
#include <memory>

PC::PC()
{
    this->memorie_ram = 0;
    this->memorie_stocare = 0;
}

PC::PC(const std::string &Nume, const std::string &Descriere, int Pret, int Cantitate, const std::string &tip, int garantie, std::string procesor, std::string placaVideo, int memorieRam,
       int memorieStocare) : Sistem_gaming(Nume, Descriere, Pret, Cantitate, tip, garantie), procesor(std::move(procesor)), placa_video(std::move(placaVideo)),
                             memorie_ram(memorieRam), memorie_stocare(memorieStocare) {}

PC::~PC() = default;

const std::string &PC::getProcesor() const
{
    return procesor;
}

void PC::setProcesor(const std::string &procesor_)
{
    PC::procesor = procesor_;
}

const std::string &PC::getPlacaVideo() const
{
    return placa_video;
}

void PC::setPlacaVideo(const std::string &placaVideo)
{
    placa_video = placaVideo;
}

int PC::getMemorieRam() const
{
    return memorie_ram;
}

void PC::setMemorieRam(int memorieRam)
{
    memorie_ram = memorieRam;
}

int PC::getMemorieStocare() const
{
    return memorie_stocare;
}

void PC::setMemorieStocare(int memorieStocare)
{
    memorie_stocare = memorieStocare;
}

std::ostream &operator<<(std::ostream &os, const PC &pc)
{
    os << dynamic_cast<const Sistem_gaming &>(pc);
    os << "Procesor:" << pc.procesor << std::endl;
    os << "Placa video:" << pc.placa_video << std::endl;
    os << "Memorie RAM:" << pc.memorie_ram << std::endl;
    os << "Memorie stocare:" << pc.memorie_stocare << std::endl;
    return os;
}

std::istream &operator>>(std::istream &is, PC &pc)
{
    is >> dynamic_cast<Sistem_gaming &>(pc);
    std::cout << "Procesor:";
    fflush(stdin);
    std::getline(std::cin, pc.procesor);
    std::cout << "Placa video:";
    fflush(stdin);
    std::getline(std::cin, pc.placa_video);
    std::cout << "Memorie RAM:";
    is >> pc.memorie_ram;
    std::cout << "Memorie stocare:";
    is >> pc.memorie_stocare;
    return is;
}

void PC::afisare()
{
    std::cout << *this;
}

std::unique_ptr<Produs> PC::clone() const
{
    return std::make_unique<PC>(*this);
}
