#include "publicdata.h"


#include "program.h"




PublicData::PublicData()
{




    //ctor
}

PublicData::~PublicData()
{
    //dtor
}




bool PublicData::isTerminal(char s){
    return !(s >= 'A' && s <= 'Z') && (s != '$');
}

bool PublicData::isStart(char s){
    return s == 'E';
}


