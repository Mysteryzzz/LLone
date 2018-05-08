#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>

using namespace std;

class Program
{
    public:
        Program();
        Program(string _from, string _to);
        virtual ~Program();

        string getFrom();
        string getTo();

        void setFrom(string _from);
        void setTo(string _to);

    protected:

    private:
        string from;
        string to;

};


#endif
