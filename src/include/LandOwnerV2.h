// Created by cc on 2019-03-20.
/********************************************************************************
 *  File Name       ：   LandOwnerV2.h
 *  Founder         ：   cc
 *  Creation Date   ：   2019-03-20
 *  Description     ：   类的头文件，.h格式（常用）
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-03-20
 *  Version         ：   1.0.0
 *  CMakeLists(cpp) ：   add_executable(LandOwnerV2.h, "./LandOwnerV2.h")
 ********************************************************************************/
#ifndef C_LANDOWNERV2_H
#define C_LANDOWNERV2_H

#include <iostream>

using namespace std;


class LandOwnerV2
{
public:
    LandOwnerV2();      //构造函数的声明，与.hpp文件里的构造函数区别就是没有{}，在这里只声明函数，不要实现！！！实现在同名的cpp文件里！
    ~LandOwnerV2();     //析构函数的声明

    void TouchCard(int);                //声明摸牌方法
    //void ShowScore();                   //声明的显示积分方法
    string name;        //地主的名称
    long score;         //地主的积分
    int cards[20];      //地主的手牌数组
};


#endif //C_LANDOWNERV2_H
