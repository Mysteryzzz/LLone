#ifndef FOLLOW_H
#define FOLLOW_H


#include "program.h"

#include <set>
#include <vector>

class Follow
{
    public:
        Follow();
        Follow(char symbol);
        virtual ~Follow();

        void setContent(char symbol);
        bool isNonTerminal(char symbol);
        void logOut();

        set<char> getContent();

    protected:

    private:
        set<char> content;
        vector<Program> programs;
};

#endif // FOLLOW_H
