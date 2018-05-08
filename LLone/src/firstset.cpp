#include "firstset.h"
#include "publicdata.h"

#include <iostream>


FirstSet::FirstSet()
{
    //ctor
}

FirstSet::~FirstSet()
{
    //dtor
}


FirstSet::FirstSet(char symbol){
    programs = PublicData::programs;
    setContent(symbol);

}

FirstSet::FirstSet(string line){
    programs = PublicData::programs;
    int lineSize = line.size();
    for(int index = 0; index < lineSize; ++index){
        FirstSet temp(line[index]);
        for(auto symbol : temp.content){
            content.push_back(symbol);
        }
        if(!temp.hasEpsilon()){
            break;
        }
    }

}


void FirstSet::setContent(char symbol){
    if(PublicData::isTerminal(symbol)){
        content.push_back(symbol);
        return ;
    }
    if(symbol == '$'){
        content.push_back(symbol);
        return ;
    }


    for(Program program : programs){
        if(program.getFrom()[0] != symbol){
            continue;
        }
        int i;
        string right = program.getTo();
        for(i = 0; i < right.size(); ++i){

            if(PublicData::isTerminal(right[i])){
                content.push_back(right[i]);
                break;
            }
            if(right[i] == '$'){
                content.push_back(right[i]);
                break;
            }
            FirstSet point(right[i]);

            for(auto terminal : point.content){
                content.push_back(terminal);
            }



            if(!point.hasEpsilon()){
                break;
            }

        }
        if(i == program.getTo().size()){
            content.push_back('$');
        }
    }
}

void FirstSet::logOut(){
    for(auto symbol : content){
        cout << symbol << " ";
    }
    cout << endl;
}

vector<char> FirstSet::getContent(){
    return content;
}



//
bool FirstSet::hasEpsilon(){
    for(auto symbol : content){
        if(symbol == '$'){
            return true;
        }
    }

}



