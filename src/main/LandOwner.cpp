// Created by cc on 2019-03-22.
/********************************************************************************
 *  File Name       ：   LandOwner.cpp
 *  Founder         ：   cc
 *  Creation Date   ：   2019-03-22
 *  Description     ：   类函数实例--地主类
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-03-23
 *  Version         ：   1.0.1
 *  CMakeLists(cpp) ：   add_executable(LandOwner.cpp, "./LandOwner.cpp")
 ********************************************************************************/
#include "LandOwner.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

LandOwner::LandOwner()
{
    SetNickName("默认地主");
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    cout << "LandOwner()" << endl;
    InitCards();
    //ctor
}

LandOwner::LandOwner(string nickName) : m_NickName(nickName)
{
    SetSex("保密");
    SetExp(0);
    SetGold(1000);
    cout << "LandOwner(string nickName)" << endl;
    InitCards();
    //测试isContains
    //cout << "测试：" << isContains(13) << endl;
}

LandOwner::LandOwner(string nickName, string sex, int gold, long exp) : m_NickName(nickName), m_Sex(sex), m_Gold(gold), m_Exp(exp)
{
    cout << "LandOwner(string nickName, string sex, int gold, long exp)" << endl;
    InitCards();
}

void LandOwner::ShowInfo()
{
    cout << "昵称：" << GetNickName() << endl;
    cout << "性别：" << GetSex() << endl;
    cout << "金币：" << GetGold() << endl;
    cout << "经验：" << GetExp() << endl;
}

void LandOwner::InitCards()                                 //初始化packCards,surplusCards,currCards
{
    //生成默认的衣服扑克牌
    for (int i = 0; i < 54; i++)
    {
        packCards.push_back(i + 1);
        surplusCards.push_back(packCards.at(i));            //surplusCards.push_back(i + 1)
    }
    currCards.clear();
    //ShowCards(packCards);                                   //验证ShowCards函数
}

void LandOwner::ShowCards(const vector<int>& cards)
{
    /*
    //5.使用算法的方式，将容器（vector）的内容复制到cout绑定的迭代器中
    //#include<iterator>        #include<algorithm>
    copy(cards.cbegin(), cards.cend(), ostream_iterator<int>(cout, "， "));
    cout << endl;
    */


    //4.for区间遍历 -- C++11
    for (auto card : cards)
    {
        cout << getColor(card) << getValue(card) << ", ";
    }
    cout << endl;


    /*
    //3.C++11里新式的写法，迭代器使用类型推断
    for (auto iter = cards.begin(); iter != cards.end(); iter++)
    {
        cout << *iter << "， ";
    }
    cout << endl;
    */

    /*
    //2.C++写法，使用迭代器（数据量小时都一样，但更专业）
    for (vector<int>::const_iterator iter = cards.begin(); iter != cards.end(); iter++)
    {
        cout << *iter << "， ";
    }
    cout << endl;
    */

    /*
    //1.c语言的习惯
    for (int i = 0; i< cards.size(); i++)
    {
        cout << cards[i] << "， ";
    }
    cout << endl;
    */
}

void LandOwner::TouchCard(int cardCount)
{
    //随机生成一张剩余牌集合surpluscards中含有的牌，添加到玩家的currcards集合中，再从surpluscards中删除这张牌
    srand(time(NULL));                                      //时间种子
    for (int i = 0; i < cardCount; i++)
    {
        int randIndex = rand() % 53 + 1;                    //1-54之间的随机数字
        //判断：随机生成的牌是否在surpluscards中（写成私有方法isContains）
        if (isContains(packCards[randIndex]))
        {
            currCards.push_back(packCards[randIndex]);      //将摸的牌放入手牌数组
            deleteCard(surplusCards, packCards[randIndex]); //将摸走的牌删除
        }
        else
        {
            i--;                                            //重新摸牌
        }
    }
    cout << "<地主摸牌> - 当前手牌如下：" << endl;
    ShowCards(currCards);
    cout << "<地主摸牌后> - 剩余手牌如下：" << endl;
    ShowCards(surplusCards);

}

bool LandOwner::isContains(int cardNum)
{
    //使用算法查找（find）
    vector<int>::iterator iter = find(surplusCards.begin(), surplusCards.end(), cardNum);
    //    if (iter == surplusCards.end())
    //    {
    //        return false;
    //    }
    //    else
    //    {
    //        return true;
    //    }
    return iter != surplusCards.end();

    /*
    //1.普通做法：(较复杂，未完成，不建议使用）
    for (int i = 0; i < surplusCards.size(); i++)
    {
        if (surplusCards[i] == packCards[cardIndex])
        { return true;}

    }
    return false;
    */
}

void LandOwner::deleteCard(vector<int> & cardVec, int card)
{
    //2.使用算法删除
    auto iter = find(cardVec.begin(), cardVec.end(), card);
    if (iter != cardVec.end())
    {
        //找到了，就删除掉
        cardVec.erase(iter);
    }

    /*//1.普通做法
    for (auto iter = cardVec.begin(); iter != cardVec.end();)
    {
        if (*iter == card)
        {
            //如果找到，就删除元素
            iter = cardVec.erase(card);                     //这里的返回值指向已删除元素的下一个元素
        } else
        {
            ++iter;                                         //继续判断下一个元素是否相同，++尽量写前面
        }
    }*/
}

string LandOwner::getColor(int card) //注意card不是下标
{
    if (card == 53) return "小王";
    if (card == 54) return "大王";
    string colors[] = {"♠️", "♥️", "♦️", "♣️"};
    return colors[(card - 1) / 13];
}

string LandOwner::getValue(int card)
{
    if (card == 53) return "Black Joker";
    if (card == 54) return "Red Joker";
    string values[] = {"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    return values[(card - 1) % 13];
}

LandOwner::~LandOwner()
{
    cout << GetNickName() << "被释放" << endl;
    //ctor
}

