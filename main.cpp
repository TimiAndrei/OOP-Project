#include <iostream>

#include "Produs.h"
#include "Joc.h"
#include "Sistem_gaming.h"
#include "PC.h"
#include "PS.h"
#include "Xbox.h"
#include "Magazin.h"
#include "Exceptii.h"

using namespace std;

int main()
{
    // baza de date
    auto PC1 = new PC("Viking", "Perfect pentru Light gaming", 2500, 10, "Light gaming", 2, "intel I3", "Gtx1650", 4, 1000);
    auto PC2 = new PC("Raptor", "Perfect pentru Medium gaming", 3500, 10, "Medium gaming", 2, "intel I5", "Gtx1660", 8, 1500);
    auto PC3 = new PC("T-Rex", "Perfect pentru High gaming", 5000, 10, "High gaming", 2, "intel I7", "Gtx1660Ti", 16, 2000);
    auto PS1 = new PS("Playstation 3", "Perfect pentru Light Gaming", 1800, 10, "Light Gaming", 2, "PlayStation 3", {"Mortal Kombat", "GTA4", "Minecraft"});
    auto PS2 = new PS("Playstation 4", "Perfect pentru Medium Gaming", 2000, 10, "Medium Gaming", 2, "PlayStation 4", {"Mortal Kombat", "GTA4", "Minecraft", "GTA5", "Cyberpunk"});
    auto PS3 = new PS("Playstation 5", "Perfect pentru High Gaming", 3000, 10, "High Gaming", 2, "PlayStation 5", {"Mortal Kombat", "GTA4", "Minecraft", "GTA5", "Cyberpunk", "Fortnite", "Valorant"});
    auto Joc1 = new Joc("Mortal Kombat", "Perfect pentru tine", 500, 10, "actiune", "PS,PC,XBOX", 100, 18);
    auto Joc2 = new Joc("GTA4", "Perfect pentru tine", 100, 10, "actiune", "PS,PC,XBOX", 50, 18);
    auto Joc3 = new Joc("Minecraft", "Perfect pentru tine", 100, 10, "actiune", "PS,PC,XBOX", 100, 18);
    auto Xbox1 = new Xbox("Xbox 360", "Perfect pentru tine", 1500, 10, "Light Gaming", 2, "XBOX 360", {"Mortal Kombat", "GTA4", "Minecraft"});
    auto Xbox2 = new Xbox("Xbox One", "Perfect pentru tine", 2000, 10, "Medium Gaming", 2, "XBOX One", {"Mortal Kombat", "GTA4", "Minecraft", "GTA5", "Cyberpunk"});
    auto Xbox3 = new Xbox("Xbox Series X", "Perfect pentru tine", 2500, 10, "High Gaming", 2, "XBOX Series X", {"Mortal Kombat", "GTA4", "Minecraft", "GTA5", "Cyberpunk", "Fortnite", "Valorant"});

    auto Magazin1 = Magazin::getInstance();
    Magazin1->adauga_produs(std::shared_ptr<Produs>(PC1));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(PC2));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(PC3));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(PS1));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(PS2));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(PS3));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(Joc1));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(Joc2));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(Joc3));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(Xbox1));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(Xbox2));
    Magazin1->adauga_produs(std::shared_ptr<Produs>(Xbox3));

    int option = 0;
    std::string procent;

    cout << "Bine ati venit la magazinul de jocuri Gamestop !" << endl;
    do
    {
        cout << "\nCe doriti sa faceti:" << endl;
        cout << "1. Afisati produsele disponibile" << endl;
        cout << "2. Adaugati produse in stoc" << endl;
        cout << "3. Stergeti produse din stoc" << endl;
        cout << "4. Cautati un produs dupa nume" << endl;
        cout << "5. Aplicati o oferta tuturor produselor" << endl;
        cout << "6. Actualizare pret inflatie" << endl;
        cout << "0. Exit" << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            cout << "La revedere!" << endl;
            break;

        case 1:
            cout << *Magazin1;
            break;

        case 2:
            cout << "Ce produs doriti sa adaugati in stoc?" << endl;
            cout << "1. PC" << endl;
            cout << "2. PS" << endl;
            cout << "3. Xbox" << endl;
            cout << "4. Joc" << endl;
            int a;
            cin >> a;
            try
            {
                if (a == 1)
                {
                    auto PCa = std::make_shared<PC>();
                    cin >> *PCa;
                    Magazin1->adauga_produs(PCa);
                }
                else if (a == 2)
                {
                    auto PSa = std::make_shared<PS>();
                    cin >> *PSa;
                    Magazin1->adauga_produs(PSa);
                }
                else if (a == 3)
                {
                    auto Xboxa = std::make_shared<Xbox>();
                    cin >> *Xboxa;
                    Magazin1->adauga_produs(Xboxa);
                }
                else if (a == 4)
                {
                    auto Joca = std::make_shared<Joc>();
                    cin >> *Joca;
                    Magazin1->adauga_produs(Joca);
                }
                else
                {
                    throw invalidOption();
                }
            }
            catch (const invalidOption &e)
            {
                cout << e.what() << endl;
            }

            break;

        case 3:
            cout << "Ce produs doriti sa stergeti din stoc?" << endl;

            try
            {
                std::string nume;
                cout << "Introduceti numele produsului: ";
                fflush(stdin);
                std::getline(std::cin, nume);
                if (Magazin1->cauta_produs(nume) == -1)
                {
                    throw invalidName();
                }
                else
                {
                    Magazin1->sterge_produs(nume);
                    cout << "Produsul a fost sters cu succes!" << endl;
                }
            }
            catch (const invalidName &e)
            {
                cout << e.what() << endl;
            }
            break;

        case 4:

            cout << "Introduceti numele COMPLET al produsului despre care vreti sa aflati mai multe detalii:";
            try
            {
                fflush(stdin);
                string nume;
                std::getline(std::cin, nume);
                auto prod = Magazin1->get_produs(nume).get();
                if (Magazin1->cauta_produs(nume) == -1)
                {
                    throw invalidName();
                }
                else if (typeid(*prod) == typeid(PC)) // verificam tipul produsului
                {
                    auto PCa = dynamic_cast<PC *>(Magazin1->get_produs(nume).get());
                    PCa->afisare();
                }
                else if (typeid(*prod) == typeid(PS))
                {
                    auto PSa = dynamic_cast<PS *>(Magazin1->get_produs(nume).get());
                    PSa->afisare();
                }
                else if (typeid(*prod) == typeid(Joc))
                {
                    auto Joca = dynamic_cast<Joc *>(Magazin1->get_produs(nume).get());
                    Joca->afisare();
                }
                else if (typeid(*prod) == typeid(Xbox))
                {
                    auto Xboxa = dynamic_cast<Xbox *>(Magazin1->get_produs(nume).get());
                    Xboxa->afisare();
                }
                else
                {
                    throw invalidName();
                }
            }
            catch (const invalidName &e)
            {
                cout << e.what() << endl;
            }

            break;

        case 5:
            cout << "Introduceti procentul de reducere: ";
            fflush(stdin);
            std::getline(std::cin, procent);
            Magazin1->Aplicare_oferta(procent);
            break;

        case 6:
            for (const std::shared_ptr<Produs> &produs : Magazin1->getProduse())
            {
                Magazin1->actualizeazaPret(produs);
            }
            std::cout << "Preturile au fost actualizate cu succes!" << endl;
            break;

        default:
            cout << "Introduceti o valoare valida" << endl;
            break;
        }
    } while (option != 0);

    delete Magazin1;

    return 0;
}
