// Created by cc on 2019-03-21.
/********************************************************************************
 *  File Name       ：   Student.h
 *  Founder         ：   cc
 *  Creation Date   ：   2019-03-21
 *  Description     ：   带参构造函数
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-03-22
 *  Version         ：   1.0.1
 *  CMakeLists(cpp) ：   add_executable(Student.h, "./Student.h")
 ********************************************************************************/
#ifndef C_STUDENT_H
#define C_STUDENT_H

#include <iostream>

using namespace std;


class Student {

public:
    //构造函数的重载规则，与普通函数相同。

    Student();

    Student(int);                 //如果构造函数中，只有一个是带唯一该参数,可以用下语句调用：Student stu4 = 30;

    Student(string);              //此中就不能使用上一种调用！

    Student(string, string);            //带参构造

    ~Student();

    void ShowInfo();

    //使用相应的Get/Set函数方法来调用private成员
    string GetName(){ return m_Name;}
    void SetName(string val){ m_Name = val;}
    string Getdesc(){ return m_desc;}
    void Setdesc(string val){ m_desc = val;}
    int Getage(){ return m_age;}
    void Setage(int val)
    {
        if (val < 0)
        {
            m_age = 18;
        }
        else
        {
            m_age = val;
        }
    }

    void InitScores();                      //初始化学生成绩数组，默认分配一个元素空间
    void AddScore(float);                   //向scores数组中添加一个分数

    Student& GetSuperScholar(Student&); //const ;     //要求返回学霸对象,函数的结尾声明为const：
                                                      //函数内部不允许修改对象本身，调用本对象非const方法就会报错！
                                                      //也可以在内部参数上加const。
    float GetTotal(); //const ;                       //计算总分

protected:

private:
    string m_Name;
    string m_desc;                          //描述
    int m_age;
    float* scores;                          //学生的分数数组
    int scoreCount;                         //学生成绩的个数
};


#endif //C_STUDENT_H
