#ifndef GAMESTOP_GENERATEID_H
#define GAMESTOP_GENERATEID_H

class GenerateID
{
private:
    static int ID;

    GenerateID();
    static GenerateID *instance;

public:
    static int generateID();
    static GenerateID *getInstance();
};

#endif // GAMESTOP_GENERATEID_H