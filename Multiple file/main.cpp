#include<iostream>
#include<vector>
#include<string>
#include<windows.h>
#include "Medicine.h"
#include "Inventory.h"
#include "Account.h"
#include "Sale.h"
using namespace std;

void clear()
{
	system("Pause");
	system("CLS");
}

int main() {
    Inventory inventory;
    Account	account;
    Sale sale;
    vector<Sale> sales;
	cout << "                                                         " << endl;
    cout << " _____ _                                                 " << endl;
    cout << "|  _  | |_ ___ ___ _____ ___ ___ _ _                     " << endl;
    cout << "|   __|   | .'|  _|     | .'|  _| | |                    " << endl;
    cout << "|__|  |_|_|__,|_| |_|_|_|__,|___|_  |                    " << endl;
    cout << "             _____              |___|                _   " << endl;
    cout << "            |     |___ ___ ___ ___ ___ _____ ___ ___| |_ " << endl;
    cout << "            | | | | .'|   | .'| . | -_|     | -_|   |  _|" << endl;
    cout << "            |_|_|_|__,|_|_|__,|_  |___|_|_|_|___|_|_|_|  " << endl;
    cout << "                              |___|                      " << endl;
    
    cout<<"\nPlease wait while loading...\n";
	for(int i=0;i<=100;i+=18)
	{
	for(int j=0;j<=i;j+=5)
		{
			cout<<char(178);	
		}
		Sleep(500);
	}
	system("CLS");
	
	while(account.login()!=1){
	}
	
    char choice;
    do {
    	cout << "+=======================================+" << endl;
	    cout << "| __             __              __     |" << endl;
	    cout << "||__) |__|  /\\  |__)  |\\/|  /\\  /  ` \\ /|" << endl;
	    cout << "||    |  | /~~\\ |  \\  |  | /~~\\ \\__,  | |" << endl;
	    cout << "+=======================================+" << endl;
        cout << "Please choose an option:" << endl;
        cout << "|0. Register new account" << endl;
        cout << "|1. Add medicine" << endl;
        cout << "|2. Remove medicine" << endl;
        cout << "|3. Find medicine" << endl;
        cout << "|4. Update medicine" << endl;
        cout << "|5. View all medicines" << endl;
        cout << "|6. Calculate bill" << endl;
        cout << "|7. Sale summary" << endl;
        cout << "|8. Re-order" << endl;
        cout << "|9. Quit" << endl;
        cout<<"Enter choice: ";
        cin >> choice;

        switch (choice) {
        case '0': {
        	cout<<"----------------------------------"<<endl;
        	account.registration();
        	clear();
			break;
		}
        case '1': {
            int id;
            string name, category;
            int price;
            int quantity;
            cout<<"----------------------------------"<<endl;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product category: ";
            cin >> category;
            cout << "Enter product price: RS ";
            cin >> price;
            cout << "Enter product quantity: ";
            cin >> quantity;
            Medicine medicine(id, name, category, price, quantity);
            inventory.add_Medicine(medicine);
            clear();
            break;
        }

        case '2': {
            int id;
            cout<<"----------------------------------"<<endl;
            cout << "Enter product id: ";
            cin >> id;
            inventory.remove_Medicine(id);
            clear();
            break;
        }

        case '3': {
            int id;
            cout<<"----------------------------------"<<endl;
            cout << "Enter product id: ";
            cin >> id;
            Medicine* medicine = inventory.find_Medicine(id);
            if (medicine) {
                cout << "Name: " << medicine->get_med_Name() << endl;
                cout << "Category: " << medicine->get_Category() << endl;
                cout << "Price: RS " << medicine->get_med_Price() << endl;
                cout << "Quantity: " << medicine->get_Quantity() << endl;
                cout << "----------------------------------" <<endl;
            }
            else {
                cout << "Product not found." << endl;
                cout << "----------------------------------" <<endl;
            }
            clear();
            break;
        }

        case '4': {
            int id;
            string name, category;
            int price;
            int quantity;
            cout<<"----------------------------------"<<endl;
            cout << "Enter the product id: ";
            cin >> id;
            cout << "Enter new product name: ";
            cin >> name;
            cout << "Enter new product category: ";
            cin >> category;
            cout << "Enter new product price: RS ";
            cin >> price;
            cout << "Enter new product quantity: ";
            cin >> quantity;
            inventory.update_Medicine(id, name, category, price, quantity);
            cout << "Product updated successfully." << endl;
            cout << "----------------------------------" <<endl;
            clear();
            break;
        }

        case '5': {
        	cout<<"----------------------------------"<<endl;
            inventory.print_Product();
            clear();
            break;
        }
            
        case '6':{
        	int id;
        	cout<<"----------------------------------"<<endl;
        	cout << "Enter the product id: ";
            cin >> id;
        	int bill_quantity;
			cout<<"Enter quantity: ";
			cin>>bill_quantity;
			Medicine* medicine = inventory.find_Medicine(id);
			if(medicine)
			{
			string name=medicine->get_med_Name();
			int price=medicine->get_med_Price();
			string category=medicine->get_Category();
			int quantity=medicine->get_Quantity();
			
			cout<<"----------------------------------"<<endl;
			cout<<"Bill: "<<endl;
			cout<< "Name: " <<name<< endl;
			cout<< "Category: " <<category<< endl;
		    cout<< "Price per pack: RS " << price*1.25<< endl;
		    cout<< "Total: RS " << price*1.25*bill_quantity<< endl;
			cout<<"----------------------------------"<<endl;
			Sale sale(id,name,price,bill_quantity);
//			sale.set_price(price);
//	    	sale.set_quantity(bill_quantity);
//	    	sale.set_name(name);
//	    	sale.set_id(id);
			sales.push_back(sale);
			quantity=quantity-bill_quantity;
			inventory.update_Medicine(id, name, category, price, quantity);
			}
			else {
		        cout << "Medicine with ID " << id << " not found." << endl;
		    }
		        	clear();
					break;
				}
				
        case '7':{
			sale.sale_summary(sales);
			clear();
			break;
		}
		
		case '8':{
			int choice;
			int stock_level;
			cout << "----------------------------------" <<endl;
			cout << "Please choose an option:" << endl;
	        cout << "|1. Set reorder level" << endl;
	        cout << "|2. Check reorder level" << endl;
	        cout << "|3. Place order" << endl;
	        cin>>choice;
	        switch(choice){
	        	case 1:{
	        		cout<<"Enter stock level for reorder: ";
	        		cin>>stock_level;
	        		inventory.set_reorder_level(stock_level);
					cout<<"Stock level for reorder set successfully."<<endl;
					break;
				}
	        	case 2:{
	        		cout<<"Stock reorder level: "<<inventory.get_reorder_level()<<endl;
					break;
				}
				case 3:{
					inventory.reorder_level();
					break;
				}
				default:{
					cout<<"Invalid option selected"<<endl;
					break;
				}	
						}
			clear();
			break;
		}
		
		case '9':		
        	{
            cout << "Exiting" << endl;
            cout << "----------------------------------" <<endl;
//            clear();
            return 0;}
            
        default:
        	{
            cout << "Invalid Choice" << endl;
            cout << "----------------------------------" <<endl;
            clear();
            break;
        }
    }
    } while (true);

 return 0;   
}

