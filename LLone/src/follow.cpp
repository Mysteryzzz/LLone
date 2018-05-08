#include "follow.h"


#include <iostream>

#include "firstset.h"
#include "publicdata.h"


Follow::Follow()
{
    //ctor
}

Follow::~Follow()
{
    //dtor
}


Follow::Follow(char symbol)
{
    programs = PublicData::programs;
    if(PublicData::isStart(symbol))
    {
//        cout << "True" << endl;
        content.insert('#');
    }
    setContent(symbol);
}


void Follow::setContent(char symbol)
{
    for(auto program : programs)
    {
        if(program.getFrom()[0] == symbol)
        {
            continue;
        }
        int index;
        string to = program.getTo();
        int toSize = program.getTo().size();
        for(index = 0; index < toSize; ++index)
        {
            if(to[index] == symbol)
            {
                if(index > 0 && index < toSize - 1 && isNonTerminal(symbol))  // aBb, B<=Vn
                {
                    //to: +TE
                    FirstSet temp( to.substr(index + 1, toSize - (index + 1)) );

                    for(auto item : temp.getContent())
                    {
                        content.insert(item);
                    }

                    for(auto item : content)
                    {
                        if(item == '$')
                        {
                            content.erase(item);
                        }
                    }

                }
                if(index > 0 && index < toSize - 1)  //aBb b->$
                {
                    FirstSet temp(to.substr(index + 1, toSize - (index + 1)));
                    if(temp.hasEpsilon())
                    {
                        Follow fromFollow = Follow(program.getFrom()[0]);
                        for(auto item : fromFollow.content)
                        {
                            content.insert(item);
                        }
                    }
                }

                if((index == toSize - 1))  // aB
                {
                    Follow fromFollow = Follow(program.getFrom()[0]);
                    for(auto item : fromFollow.content)
                    {
                        content.insert(item);
                    }

                }
            }

        }





    }



}


bool Follow::isNonTerminal(char s)
{
    return s <= 'Z' && s>= 'A';
}

void Follow::logOut()
{
    for(auto symbol : content)
    {
        cout << symbol << " ";
    }
    cout << endl;
}

set<char> Follow::getContent(){
    return content;
}

