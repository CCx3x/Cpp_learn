// Created by cc on 2019-03-21.
/********************************************************************************
 *  File Name       ：   Student.cpp
 *  Founder         ：   cc
 *  Creation Date   ：   2019-03-21
 *  Description     ：   带参构造函数定义
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-03-22
 *  Version         ：   1.0.1
 *  CMakeLists(cpp) ：   add_executable(Student.cpp, "./Student.cpp")
 ********************************************************************************/
#include "Student.h"
#include <iostream>

using namespace std;

Student::Student()
{
    cout << "默认构造" << endl;
    InitScores();
    //ctor
}

Student::Student(int age)
{
    Setage(age);
    cout << "带参构造：Student(int age)" << endl;
    InitScores();
}

Student::Student(string name)
{
    SetName(name);
    cout << "带参构造：Student(string name)" << endl;
    InitScores();
}

Student::Student(string name, string desc)
{
    m_Name = name;      //等价于SetName(name);
    m_desc = desc;
    cout << "带参构造：Student(string name, string desc)" << endl;
    InitScores();
}

//Student::Student(string name, string desc) : m_Name(name), m_desc(desc)     //初始化参数列表的写法，与上一个是相同的
//{
//    //m_Name = name;      //等价于SetName(name);
//    //m_desc = desc;
//    cout << "带参构造：Student(string name, string desc)" << endl;
//}

void Student::InitScores()
{
    this->scores = new float[1];
    this->scoreCount = 1;
}

void Student::AddScore(float score)
{
    this->scores[this->scoreCount - 1] = score;
    //1、创建一个新数组，分配scoreCount+1个空间
    //2、复制原数组中的内容到新数组中
    //3、scoreCount++
    //4、scores指向新数组
    float * newScores = new float[scoreCount + 1];
    float * oldScores = scores;
    memcpy(newScores, scores, sizeof(float) * scoreCount);
    scoreCount++;
    scores = newScores;
    delete(oldScores);
}

float Student::GetTotal() //const
{
    float sum = 0;
    for (int i = 0; i < scoreCount - 1; i++)
    {
        sum += scores[i];
    }
    return sum;
}

/*返回学霸对象的函数
 * @param otherStu  要对比的另外一个学生对象
 * @return  返回总分比较大的那个学生对象
 * */
Student& Student::GetSuperScholar(Student & otherStu) //const
{
    //分别计算两个学生的总分
    if (this->GetTotal() > otherStu.GetTotal())
    {
        return *this;                         //返回当前对象的引用
    } else
    {
        return otherStu;                      //返回另一个对象
    }
}

void Student::ShowInfo()
{
    cout << m_desc << m_Name << endl;
    for (int i = 0; i < scoreCount - 1; i++)
    {
        cout << this->scores[i] << "\t";
    }
    cout << endl;
}


Student::~Student() {
    cout << m_Name << "被释放" << endl;        //自动释放的是栈内存里的对象
    delete this->scores;
    //ctor
}

