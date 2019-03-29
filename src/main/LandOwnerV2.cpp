// Created by cc on 2019-03-20.
/********************************************************************************
 *  File Name       ：   LandOwnerV2.cpp
 *  Founder         ：   cc
 *  Creation Date   ：   2019-03-20
 *  Description     ：   用.h格式头文件引入的类
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-03-20
 *  Version         ：   1.0.0
 *  CMakeLists(cpp) ：   add_executable(LandOwnerV2.cpp, "./LandOwnerV2.cpp")
 ********************************************************************************/
#include "LandOwnerV2.h"
#include <iostream>

using namespace std;

//在.h文件里声明的函数，在这里实现！也可在.h文件里实现部分函数，但一定要短！

//实现摸牌方法
LandOwnerV2::LandOwnerV2()
{
    //ctor
}

void LandOwnerV2::TouchCard(int cardCount)
{
    //暂时省略函数的实现
    cout << name << "摸了" << cardCount << "张牌" << endl;
}

LandOwnerV2::~LandOwnerV2()
{
    //ctor
}

