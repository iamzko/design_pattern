//
// Created by Administrator on 2021/6/23.
//
#include <iostream>

#ifndef DESIGN_PATTERN_ABSTRACTSPORTPRODUCT_H
#define DESIGN_PATTERN_ABSTRACTSPORTPRODUCT_H

class AbstractSportProduct//产品抽象基类
{
public:
    AbstractSportProduct()
    {}

    void print_name();

    void play();
};

class Basketball : public AbstractSportProduct
{
public:
    Basketball()
    {
        print_name();
        play();
    }

    void print_name()
    {
        std::cout << "get basketball!" << std::endl;
    }

    void play()
    {
        std::cout << "play basketball!" << std::endl;
    }
};

class Football : public AbstractSportProduct
{
public:
    Football()
    {
        print_name();
        play();
    }

    void print_name()
    {
        std::cout << "get football!" << std::endl;
    }

    void play()
    {
        std::cout << "play football!" << std::endl;
    }
};

class volleyball : public AbstractSportProduct
{
public:
    volleyball()
    {
        print_name();
        play();
    }

    void print_name()
    {
        std::cout << "get volleyball!" << std::endl;
    }

    void play()
    {
        std::cout << "play volleyball!" << std::endl;
    }
};
//抽象工厂类
class AbstractFactory
{
public:
    virtual AbstractSportProduct* get_sport_product() = 0;
};
class BasketballFactory: public AbstractFactory
{
public:
    BasketballFactory()
    {
        std::cout << "basketball factory!" << std::endl;
    }
    AbstractSportProduct* get_sport_product()
    {
//        std::cout << "basketball" << std::endl;
        return new Basketball();
    }
};
class FootballFactory:public AbstractFactory
{
public:
    FootballFactory()
    {
        std::cout << "football factory!" << std::endl;
    }
    AbstractSportProduct* get_sport_product()
    {
//        std::cout << "football" << std::endl;
        return new Football();
    }
};
class  volleyballFactory:public AbstractFactory
{
public:
    volleyballFactory()
    {
        std::cout << "volleyball factory!" << std::endl;
    }
    AbstractSportProduct* get_sport_product()
    {
//        std::cout << "volleyball" << std::endl;
        return new volleyball();
    }
};


#endif //DESIGN_PATTERN_ABSTRACTSPORTPRODUCT_H
