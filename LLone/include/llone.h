#ifndef LLONE_H
#define LLONE_H

#include "table.h"
#include "program.h"
#include "eliminateleft.h"

#include <stack>
#include <vector>
#include <string>
#include <iostream>



using namespace std;

class LLone
{
    public:
        LLone();
        virtual ~LLone();
        bool isNonTerminal(char s);


        bool analyze(string sequence);

        string readTableRhs(char A, char a);

        void travseStack(stack<char> s);

        void logOutFirstSet();
        void logOutFollowSet();

        Table getTable();
    protected:

    private:
        Table table;
        string Vn;

};

#endif // LLONE_H
