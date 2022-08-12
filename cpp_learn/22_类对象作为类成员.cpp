/*
 * @Description: 类对象作为类成员
 * @Author: stone
 * @Date: 2020-02-07 13:36:40
 * @LastEditTime : 2020-02-08 17:32:01
 * @LastEditors  : stone
 */

#include "cpp_learn_inner.h"
#include <iostream>
#include <string>
using namespace std;

class Phone {
public:
    Phone(string pName)
    {
        cout << "Phone的构造" << endl;
        m_Pname = pName;
    }
    ~Phone()
    {
        cout << "Phone的析构" << endl;
    }

    // private:
    string m_Pname;
};
class Game {
public:
    Game(string Gname)
    {
        cout << "Game的构造" << endl;
        m_Gname = Gname;
    }
    ~Game()
    {
        cout << "Game的析构" << endl;
    }

    // private:
    string m_Gname;
};
class Person {
public:
    Person(string Name, string pName, string Gname) :
        m_Name(Name), m_Pname(pName), m_Gname(Gname)
    {
        cout << "Person构造" << endl;
    }
    ~Person()
    {
        cout << "Person析构" << endl;
    }

    // private:
    string m_Name;
    Phone m_Pname;
    Game m_Gname;
};
/**
 * @description:
 * @param :
 * @return:
 */
void Test22()
{
    // Person user("stone", "Vivo", "Glory");
    // cout << "Test22 done" << endl;
    return;
}
