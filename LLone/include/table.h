#ifndef TABLE_H
#define TABLE_H

#include "cell.h"

#include <vector>



using namespace std;

class Table
{
    public:
        Table();
        virtual ~Table();
        void logOut();
        vector<Cell> getContent();

        int findCell(char row, char col);

    protected:

    private:
        vector<Cell> content;
        vector<Program> programs;
};

#endif // TABLE_H
