#ifndef Sale_H
#define Sale_H

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class Sale{
	private:
		int id;
    	string name;
    	int price;
    	int quantity;
    	int total_sale_quantity;
    	int total_sale_price;
    	int total_sale_cost;
    public:
    	Sale();
    	Sale(int id,string name,int price,int quantity);
    	void sale_summary(vector<Sale>& sales);
};

#endif

