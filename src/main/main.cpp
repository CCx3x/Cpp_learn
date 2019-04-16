// Created by cc on 2019-03-22.
/********************************************************************************
 *  File Name       ：   main.cpp
 *  Founder         ：   cc
 *  Creation Date   ：   2019-03-22
 *  Description     ：   practical content for c++learning
 *  Modifier        ：   cc
 *  Modified Date   ：   2019-03-23
 *  Version         ：   1.0.1
 *  CMakeLists(cpp) ：   add_executable(main.cpp, "./main.cpp")
 ********************************************************************************/
#include <iostream>
#include "LandOwnerV2.h"
#include "Student.h"
#include "LandOwner.h"


using namespace std;

int main()
{
//    //this指针，使用student.h文件为例
//    Student * ptr_stu1 = new Student("大锤", "nmsl");
//    ptr_stu1->AddScore(78.99);
//    ptr_stu1->AddScore(88.99);
//    ptr_stu1->AddScore(98.99);
//    ptr_stu1->AddScore(108.99);
//    ptr_stu1->AddScore(108.99);
//    ptr_stu1->ShowInfo();
//
//    Student stu2 = {"尼玛", "wang"};
//    stu2.AddScore(66.6);
//    stu2.AddScore(76.6);
//    stu2.AddScore(86.6);
//    stu2.AddScore(96.6);
//    stu2.AddScore(56.6);
//    stu2.ShowInfo();
//
//    //两种书写方式一样
//    Student& scholar1 = stu2.GetSuperScholar(*ptr_stu1);
//    Student& scholar2 = ptr_stu1->GetSuperScholar(stu2);
//    cout << "学霸是：" << scholar1.GetName() << endl;
//    cout << "学霸是：" << scholar2.GetName() << endl;
//    //scholar1在栈内存中定义的，所以main结束后，会自动释放scholar1
//    //scholar2在栈内存中定义的，所以main结束后，会自动释放scholar2
//    //会导致释放两次
//    //所以在Student后加&符号，返回值是引用，所以前面也要是引用，否则会很危险！！！
//
//    delete(ptr_stu1);


    LandOwner* ptr_landOwner1 = new LandOwner();
    LandOwner* ptr_landOwner2 = new LandOwner("专业斗地主");
    LandOwner* ptr_landOwner3 = new LandOwner("专业地主");

    ptr_landOwner1->ShowInfo();
    ptr_landOwner2->ShowInfo();
    ptr_landOwner3->ShowInfo();

    ptr_landOwner2->TouchCard(20);

    delete ptr_landOwner1;
    delete ptr_landOwner2;
    delete ptr_landOwner3;


    /*
    //建议多使用堆内存，少使用栈内存！！！
    //使用类及其构造函数
    Student stu1;                                      //在栈内存中直接分配空间
    Student stu2("张三", "男");
    //Student stu3(28);
    //Student stu4 = 30;
    stu2.ShowInfo();

    //另一种使用方法,可使用new的方式分配内存
    Student* stu5 = new Student("李四", "未知的");       //在堆内存新分配了一块空间
    stu5->ShowInfo();                                  //此时调用成员函数的方式用"->"

    //当对象使用完毕时，记得delete，释放内存!!!
    delete stu5;
    */

    /*
    LandOwnerV2 land2;
    land2.name = "张三";
    land2.TouchCard(30);
    */

    return 0;
}
