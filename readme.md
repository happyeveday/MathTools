# 以 CPP 为基础开发的科学计算器

相关信息：     

    姓名：杨向原        
    学校：兰州大学      
    学院：信息科学与工程学院        
    学生卡号：320220942311

    姓名：李宏诚        
    学校：兰州大学      
    学院：信息科学与工程学院        
    学生卡号：320220941681

    姓名：周鸿越       
    学校：兰州大学      
    学院：信息科学与工程学院        
    学生卡号：320220942531


开发平台：Windows11,QTcreator community 15.0,VScode       

## 具体内容
开发流程    

    1.实现不同数据类型的数据互通√   
    2.完成不同数据类型之间的数据计算√   
    3.生成函数图像√     
    4.矩阵运算     
    5.函数运算     
    6.封装QT桌面应用

## 实现方法        
### 不同数据类型的数据互通        
通过template和使用<type_traits>库中的common::type<A,B>返回进行运算的两个数据类型中更高阶的数据类型实现        
### 不同数据类型之间的数据计算        
通过定义，目前仅仅定义了+,-,*,/，后续会加入**,&,|,~等计算        
### 生成函数图像        
通过FunctionPlotter.cpp文件和matplotlibcpp.h引入python，再通过python3.8提供的numpy以及matplotlib进行图像绘制        
