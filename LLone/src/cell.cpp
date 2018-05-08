#include "cell.h"

Cell::Cell()
{
    //ctor
}

Cell::~Cell()
{
    //dtor
}

Cell::Cell(char _row, char _col, Program _program)
{
    row = _row;
    col = _col;
    program = _program;
}
