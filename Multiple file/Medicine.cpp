#include <iostream>
#include <string>
#include "Medicine.h"

using namespace std;

Medicine::Medicine(int id, string name, string category, int price, int quantity)
    {
        this->id=id;
        this->name=name;
        this->category=category;
        this->price=price;
        this->quantity=quantity;
    }

    int Medicine::get_med_Id() const{
        return id;
    }

    void Medicine::set_med_Id(int id){
        this->id=id;
    }

    string Medicine::get_med_Name() const{
        return name;
    }

    void Medicine::set_med_Name(string name){
        this->name=name;
    }

    string Medicine::get_Category() const{
        return category;
    }

    void Medicine::set_Category(string category){
        this->category=category;
    }

    int Medicine::get_med_Price() const{
        return price;
    }

    void Medicine::set_med_Price(int price){
        this->price=price;
    }

    int Medicine::get_Quantity() const{
        return quantity;
    }

    void Medicine::set_Quantity(int quantity){
        this->quantity=quantity;
    }
    
