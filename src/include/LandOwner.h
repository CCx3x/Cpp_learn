// Created by cc on 2019-03-22.
/********************************************************************************
 *  File Name       ：   LandOwner.h
 *  Founder         ：   cc
 *  Creation Date   ：   2019-03-22
 *  Description     ：   类函数实例--地主类
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-03-23
 *  Version         ：   1.0.1
 *  CMakeLists(cpp) ：   add_executable(LandOwner.h, "./LandOwner.h")
 ********************************************************************************/
#ifndef CPP_LEARN_LANDOWNER_H
#define CPP_LEARN_LANDOWNER_H

#include <iostream>
#include <vector>

using namespace std;


class LandOwner {
private:
    string m_NickName;
    string m_Sex;
    int m_Gold;
    long m_Exp;
    vector<int> packCards;                              //默认牌组，1-54
    vector<int> surplusCards;                           //摸牌后剩余的牌
    vector<int> currCards;                              //当前玩家的手牌数组，从一副牌里摸牌放入这个vector中,currentCards
    bool isContains(int);                               //剩余牌集合中是否包含cardNum这个牌
    void deleteCard(vector<int>&, int);                 //删除集合中的数字
    string getColor(int);                               //获得牌的花色
    string getValue(int);                               //获得牌面

public:
    LandOwner();

    //带参构造
    LandOwner(string);          //默认昵称
    LandOwner(string, string, int, long);

    ~LandOwner();

    string GetNickName(){ return m_NickName;}
    void SetNickName(string val){ m_NickName = val;}
    string GetSex(){ return m_Sex;}
    void SetSex(string val){ m_Sex = val;}
    int GetGold(){ return m_Gold;}
    void SetGold(int val){ m_Gold = val;}
    long GetExp(){ return m_Exp;}
    void SetExp(long val){ m_Exp = val;}

    void ShowInfo();
    void InitCards();                                   //初始化packCards,surplusCards,currCards
    void ShowCards(const vector<int>&);                 //显示集合中的牌面
    void TouchCard(int cardCount);                      //摸牌

protected:

};


#endif //CPP_LEARN_LANDOWNER_H
