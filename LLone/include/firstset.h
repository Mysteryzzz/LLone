#ifndef FIRSTSET_H
#define FIRSTSET_H

#include "program.h"

#include <vector>

class FirstSet
{
    public:
        FirstSet();
        FirstSet(char symbol);
        FirstSet(string line);


        virtual ~FirstSet();


        void setContent(char symbol);
        bool hasEpsilon();

        vector<char> getContent();

        void logOut();

    protected:

    private:
        vector<char> content;
        vector<Program> programs;

};

#endif // FIRSTSET_H
