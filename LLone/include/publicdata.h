#ifndef PUBLICDATA_H
#define PUBLICDATA_H


#include "program.h"

#include <vector>

using namespace std;

class PublicData
{
    public:
        PublicData();
        virtual ~PublicData();
        static vector<Program> programs;
        static string Vn;
        static string Vt;

        static char startSymbol;


        static bool isTerminal(char symbol);
        static bool isStart(char symbol);




    protected:

    private:



};

#endif // PUBLICDATA_H
