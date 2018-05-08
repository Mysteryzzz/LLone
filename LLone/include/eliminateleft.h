#ifndef ELIMINATELEFT_H
#define ELIMINATELEFT_H

#include "program.h"

#include <vector>

class EliminateLeft
{
    public:
        EliminateLeft();
        virtual ~EliminateLeft();

        static void EliminateDirectLeftRecursion(vector<Program>& programs);
        static void EliminateIndirectLeftRecursion(vector<Program>& programs);

    protected:

    private:
};

#endif // ELIMINATELEFT_H
