#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <vector>
#include <string>

#include "Medicine.h"

using namespace std;
class Inventory
{
private:
    vector<Medicine> medicines;
    int stock_level;
    int quantity_to_order;

public:
    void add_Medicine(Medicine medicine);
    void remove_Medicine(int id);
    Medicine* find_Medicine(int id);
    void update_Medicine(int id, string name, string category, int price, int quantity);
    void print_Product() const;
    void reorder_level();
    void set_reorder_level(int stock_level);
	int get_reorder_level() const;
};

#endif
