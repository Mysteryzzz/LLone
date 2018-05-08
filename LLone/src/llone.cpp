#include "llone.h"

#include <stack>
#include <string>
#include <algorithm>


#include "firstset.h"
#include "follow.h"
#include "publicdata.h"

using namespace std;


LLone::LLone():table()
{
    //ctor
    Vn = "EATBF";

}

LLone::~LLone()
{
    //dtor
}

vector<Program> PublicData::programs =
{
    {"E", "TA"},
    {"A", "+TA"},
    {"A", "$"},
    {"T", "FB"},
    {"B", "*FB"},
    {"B", "$"},
    {"F", "(E)"},
    {"F", "i"}
};


char PublicData::startSymbol = 'E';
string PublicData::Vn = "EATBF";
string PublicData::Vt = "i+*()#";



Table LLone::getTable()
{
    return table;
}

void LLone::travseStack(stack<char> s)
{
    stack<char> temp(s);
    while(!temp.empty())
    {
        cout << temp.top();
        temp.pop();
    }
}


bool LLone::isNonTerminal(char s)
{
    return s >= 'A' && s <= 'Z';
}


string LLone::readTableRhs(char topChar, char readyChar)
{
//    cout << topChar << " readyChar: " << readyChar << endl;
    bool flagFind = false;
    for(auto item : table.getContent())
    {
        if(item.row == topChar && item.col == readyChar)
        {
            flagFind = true;
            return item.program.getTo();
        }
    }
    if(!flagFind)
    {
        return "Error!";
    }
}


bool LLone::analyze(string sequence)
{
    stack<char> container;
    container.push('#');
    container.push('E');

    int step = 0;
    int index = 1;
    cout << "Step     Symbol stack            Production" << endl;
    while(1)
    {
        cout << step++ << "     ";
        // top = a = #
        char topChar = container.top();
        char readyChar = sequence[index];
        if(topChar == readyChar && readyChar == '#')
        {
//            cout << "First session: ";
            cout << "  #          " << "     "  << endl;

            return true;
        }

        //top = a != #
        if(topChar == readyChar && readyChar != '#')
        {
//            cout << "Second session: ";
            travseStack(container);
            cout << "           " << endl;
            index++;
            container.pop();
            continue;
        }

        //top is termianl
        if(isNonTerminal(topChar))
        {
//            cout << "Third session: ";
            travseStack(container);
            cout << "                 ";
            string rhs = readTableRhs(topChar, readyChar);
            cout << topChar << "->"  << rhs << endl;;


            if(rhs == "Error!")
            {
                return false;
            }

            reverse(rhs.begin(), rhs.end());
            container.pop();
            if(rhs[0] == '$')
            {
                continue;
            }
            for(auto item : rhs)
            {
                container.push(item);
            }
        }


    }


}

//


void LLone::logOutFirstSet()
{
    cout << "FirstSet:" << endl;
    for(auto item : Vn)
    {
        FirstSet it(item);
        it.logOut();
    }
}

void LLone::logOutFollowSet()
{
    cout << "FollowSet:" << endl;
    for(auto item : Vn)
    {
        Follow it(item);
        it.logOut();
    }
}




/*
 $ means empty set;
 ![A-Z] && !$ && !# means terminal symnol
 A-Z means unterminal symbol
*/


int main()
{
    LLone llone;

    llone.logOutFirstSet();

    cout << endl;

    llone.logOutFollowSet();

    cout << endl;

    llone.getTable().logOut();

    string sequence;
    cin >> sequence;
    bool flag = llone.analyze(sequence);
    if(!flag)
    {
        cout << "Error" << endl;
    }
    else
    {
        cout << "Successful !" << endl;
    }

    return 0;
}
