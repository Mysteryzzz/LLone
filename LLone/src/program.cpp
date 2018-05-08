#include "program.h"

Program::Program()
{
    //ctor
}

Program::~Program()
{
    //dtor
}

Program::Program(string _from, string _to){
    from = _from;
    to = _to;
}

string Program::getFrom(){
    return from;

}

string Program::getTo(){
    return to;
}

void Program::setFrom(string _from){
    from = _from;
}

void Program::setTo(string _to){
    to = _to;
}
