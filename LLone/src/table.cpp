#include "table.h"

#include "firstset.h"
#include "follow.h"
#include "publicdata.h"



#include <iomanip>
#include <iostream>

Table::Table()
{
    programs = PublicData::programs;
    for(auto program : programs)
    {
        string to = program.getTo();
        string from = program.getFrom();
        FirstSet alpha(to);
        for(auto item : alpha.getContent())
        {
            if(PublicData::isTerminal(item))
            {
                content.push_back({ from[0], item, {from, to} });
            }
        }

        if(alpha.hasEpsilon()){
            Follow follow(from[0]);
            for(auto item : follow.getContent())
            {
                content.push_back({ from[0], item, {from, to} });

            }

        }

    }




    //ctor
}

Table::~Table()
{
    //dtor
}


vector<Cell> Table::getContent(){
    return content;
}



void Table::logOut(){

    cout << std::left << std::setw(3) << "";
    for(auto itemVt : PublicData::Vt){
        cout << std::left << std::setw(10) << itemVt;
    }
    cout << endl;
    for(auto itemVn : PublicData::Vn){
        cout << std::left << std::setw(3) << itemVn;
        for(auto itemVt : PublicData::Vt)
        {
            int index = findCell(itemVn, itemVt);
            string product = "Error";
            if(index != -1){
                product = content[index].program.getFrom() + "->" + content[index].program.getTo();
            }
            cout << std::left << std::setw(10) << product;
        }
        cout << endl;
    }

}


int Table::findCell(char rowChar, char colChar){
    int contentSize = content.size();
    for(int i = 0; i < contentSize; ++i){
        if(content[i].row == rowChar && content[i].col == colChar){
            return i;
        }
    }
    return -1;
}
