#ifndef MEDICINE_H
#define MEDICINE_H

#include <iostream>
#include <string>
using namespace std;

class Medicine
{
private:
    int id;
    string name;
    string category;
    int price;
    int quantity;
public:
    Medicine(int id, string name, string category, int price, int quantity);
    int get_med_Id() const;
    void set_med_Id(int id);
    string get_med_Name() const;
    void set_med_Name(string name);
    string get_Category() const;
    void set_Category(string category);
    int get_med_Price() const;
    void set_med_Price(int price);
    int get_Quantity() const;
    void set_Quantity(int quantity);
};

#endif
