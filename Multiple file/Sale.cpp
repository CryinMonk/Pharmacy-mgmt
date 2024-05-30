#include<iostream>
#include <vector>
#include <string>
#include "Sale.h"

using namespace std;

Sale::Sale(){
}

Sale::Sale(int id,string name,int price,int quantity){
	this->id=id;
	this->name=name;
	this->price=price;
	this->quantity=quantity;
}

void Sale::sale_summary(vector<Sale>& sales){
		total_sale_cost = 0;
	    total_sale_price = 0;
	    total_sale_quantity = 0;
		for(size_t i=0;i<sales.size();i++)
		{
		total_sale_cost += sales[i].quantity * sales[i].price;
//		cout<<"Total sale cost"<<total_sale_cost;
		total_sale_price += (sales[i].quantity * sales[i].price * 1.25); 
//		cout<<"total sale price"<<total_sale_price<<endl;
        total_sale_quantity+=sales[i].quantity;
//        cout<<"total sale quantity"<<total_sale_quantity<<endl;
		}
	    cout<<"-----------Sale Summary-----------"<<endl;
	    cout<<"Date: "<<__DATE__<<endl;
//	    cout<<"Time: "<<__TIME__<<endl;
		cout<<"Total item sold: "<<total_sale_quantity<<endl;
	    cout<<"Total sales: "<<total_sale_price<<endl;
	    cout<<"Total cost of sale: "<<total_sale_cost<<endl;
	    cout<<"Total profit: "<<total_sale_price-total_sale_cost<<endl;
        cout << "----------------------------------" << endl;
}


