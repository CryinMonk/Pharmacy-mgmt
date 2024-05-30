#include "Inventory.h"

void Inventory::add_Medicine(Medicine medicine)
    {
        bool found = false;
        for (size_t i = 0; i < medicines.size(); i++)
        {
            if (medicines[i].get_med_Id() == medicine.get_med_Id())
            {
                cout << "Id already Exist."<< endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            medicines.push_back(medicine);
            cout << "Product added successfully." << endl;
            cout << "----------------------------------" <<endl;
        }
    }

void Inventory::remove_Medicine(int id)
    {
        bool found = false;
        for (size_t i = 0; i < medicines.size(); i++)
        {
            if (medicines[i].get_med_Id() == id)
            {
                medicines.erase(medicines.begin() + i);
                found = true;
                cout << "Product removed successfully." << endl;
                cout << "----------------------------------" <<endl;
                break;
            }
        }
        if (!found)
        {
            cout << "Id does not exist" << endl;
        }
    }

Medicine* Inventory::find_Medicine(int id)
    {
        for(size_t i=0; i<medicines.size(); i++)
        {
            if(medicines[i].get_med_Id() == id)
            {
                return &medicines[i];
            }
        }
        return NULL;
    }

void Inventory::update_Medicine(int id, string name, string category, int price, int quantity)
    {
        bool found = false;
        for (size_t i = 0; i < medicines.size(); i++)
        {
            if (medicines[i].get_med_Id() == id)
            {
                medicines[i].set_med_Name(name);
                medicines[i].set_Category(category);
                medicines[i].set_med_Price(price);
                medicines[i].set_Quantity(quantity);
                
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "ID does not exist." << endl;
        }
    }

void Inventory::print_Product() const{
        for(size_t i=0; i<medicines.size(); i++)
        {
            cout<<"ID : "<<medicines[i].get_med_Id()<<endl;
            cout<<"Name : "<<medicines[i].get_med_Name()<<endl;
            cout<<"Category : "<<medicines[i].get_Category()<<endl;
            cout<<"Price : RS"<<medicines[i].get_med_Price()<<endl;
            cout<<"Quantity : "<<medicines[i].get_Quantity()<<endl;
            cout<<"Total Price : RS"<<medicines[i].get_med_Price()*medicines[i].get_Quantity()<<endl;
            cout << "----------------------------------" <<endl;
        }
    }
    
void Inventory::set_reorder_level(int stock_level){
	this->stock_level=stock_level;
}

int Inventory::get_reorder_level() const{
	return stock_level;
}    

void Inventory::reorder_level(){
	for(unsigned int i=0;i<medicines.size();i++)
	{
		if(medicines[i].get_Quantity()<=stock_level){
			cout<<"Enter the quantity to order: ";
			cin>>quantity_to_order;
			cout<<"Order Placed Successfully"<<endl;
			cout << "----------------------------------" <<endl;
		}
		else{
			cout<<"There is sufficient stock remaining."<<endl;
		}
	}
}
