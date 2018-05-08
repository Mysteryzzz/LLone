#ifndef CELL_H
#define CELL_H


#include "program.h"

class Cell
{
    public:
        Cell();
        Cell(char _row, char _col, Program _program);
        virtual ~Cell();


        char row;
        char col;
        Program program;


    protected:

    private:

};

#endif // CELL_H
