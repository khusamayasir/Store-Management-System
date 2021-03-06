#include <conio.h>
#include <iostream>
#include <string>

using namespace std;

struct Product                //Structure.
{
	string name;
	int model_number = 0;
	int wholesale_cost = 0;
	int retail_cost = 0;
	int av_quantity = 0;
	int s_quantity = 0;
};

struct Customer               //Structure.
{
	string name;
	int id = 0;
	int balance = 1000;
	string buying_history[10];
	int lastElementIndex = 0;
	int bill = 0;
};

void ProductInformation(Product);      //Function Declaration. 

void Customers(Customer);              //Function Declaration. 

bool findCustomerById(int id);         //Function Declaration. 

bool findProductByMN(int mn, int c_id); //Function Declaration. 

bool findQuantity(int qp, int c_id, int mn); //Function Declaration. 

Product p[20];                         //Global Array.

Customer c[5];                        //Global Array.

int filledElements = 0, currentProductIndex = 0, q_index = 0, history_index = 0, recipt = 0, lenghtOfArr = 0;
int current_customer_index;

void main()
{
	int choice, i;
	Product p;
	Customer c;

	cout << "\t\tWelcome To U.A.I Store Managment System" << endl;
	cout << "-------------------------------------------------------------------------------------" << endl << endl;

	cout << "\t\tWelcome To U.A.I Store" << endl << endl;

	do
	{
		cout << "Press 1, If You are a Dealer." << endl;
		cout << "Press 2, If Your are a Customer." << endl;
		cout << "Press 3, If You want to exit." << endl;
		cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

		cout << "Enter Your Choice: ";
		cin >> choice;
		cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

		switch (choice)
		{
		case 1:
		{
			ProductInformation(p);  //Function Calling.
			break;
		}
		case 2:
		{
			Customers(c);           //Function Calling.
			break;
		}
		}
	} while (choice != 3);

	_getch();
}

void ProductInformation(Product prod)    //Function Definition. 

{
	char opt, choice;
	int i, countp = 0, p_q;
	int  isproduct=0;

	do
	{
		cout << "\t\tWelcome in Dealer Mode" << endl << endl;

		cout << "Press a, to Add New Shipment in Store." << endl;
		cout << "Press b, to See Inventory in Store." << endl;
		cout << "Press c, to Check Sold & Unsold Products." << endl;
		cout << "Press e, to Exit from Dealer Mode." << endl;
		cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

		cout << "Enter Your Choice: ";
		cin >> opt;
		cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

		switch (opt)
		{
		
		case'a':
		{
			cout << "\t\tEnter Products & their Details" << endl << endl;

			for (i = currentProductIndex; i < 10; i++)
			{
				filledElements++;
				currentProductIndex++;

				cout << "Enter Product Name:\t\t";
				getline(cin, p[i].name, '.');

				cout << "Enter Product Model Number:\t";
				cin >> p[i].model_number;

				cout << "Enter Product WholeSale Cost:   ";
				cin >> p[i].wholesale_cost;

				cout << "Enter Product Retail Cost:\t";
				cin >> p[i].retail_cost;

				cout << "Enter Quantity of Product:\t";
				cin >> p[i].av_quantity;

				countp++;
				lenghtOfArr = countp;

				cout << "\nDo you want Add more Product in Store? (Y=Yes or N=No)";
				cin >> choice;
				cout << endl;

				if (choice == 'n' || choice == 'N')
				{
					break;
				}
				else
				{
					continue;
				}
			}

			cout << "-------------------------------------------------------------------------------------" << endl << endl;
			cout << "\t\tYou Successfully Filled Your Store with these Product. " << endl << endl;
			
			for (i = 0; i < lenghtOfArr ; i++)
			{
				cout << "Product Name: " << p[i].name << endl;
				cout << "Product Model Number:   " << p[i].model_number << endl;
				cout << "Product WholeSale Cost: " << p[i].wholesale_cost << endl;
				cout << "Product Retail Cost:    " << p[i].retail_cost << endl;
				cout << "Product Quantity:       " << p[i].av_quantity << endl;
				cout << endl;
			}
			
			cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

			break;
		}

		case 'b':
		{
			cout << "\t\tAvailable Items in Your Store. " << endl << endl;

			for (i = 0; i < filledElements; i++)
			{
				cout << "Product Name: " << p[i].name << endl;
				cout << "Product Model Number:   " << p[i].model_number << endl;
				cout << "Product WholeSale Cost: " << p[i].wholesale_cost << endl;
				cout << "Product Retail Cost:    " << p[i].retail_cost << endl;
				cout << "Product Quantity:       " << p[i].av_quantity << endl;
				cout << endl;
			}

			cout << "\n-------------------------------------------------------------------------------------" << endl << endl;
			break;
		}

		int new_model_number;
		case 'c':
		{
			cout << "Enter Product Model Number:  ";
			cin >> new_model_number;

			for (i = 0; i < 10; i++)
			{
				if (new_model_number == p[i].model_number)
				{
					cout << "Product Name:                " << p[i].name << endl;
					cout << "Product Available Quantity:  " << p[i].av_quantity << endl;
					cout << "Sold Quantiy of Product is:  " << p[i].s_quantity << endl;
					cout << endl;
				}
			}

			cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

			break;
		}

		}
	} while (opt != 'e');

}

bool findCustomerById(int id)    //Function Definition. 
{
	for (int i = 0; i < 5; i++)
	{
		if (c[i].id == id)
		{
			current_customer_index = i;
			return true;
			break;
		}
	}
	return false;
}

bool findProductByMN(int mn,int c_id)   //Function Definition. 
{
	for (int i = 0; i < 10; i++)
	{
		if (p[i].model_number == mn)
        {
			findCustomerById(c_id);
			c[current_customer_index].buying_history[c[current_customer_index].lastElementIndex] = p[i].name;
			c[current_customer_index].lastElementIndex++;
			history_index++;
			return true;
			break;
		}
	}
	return false;
}

bool findQuantity(int qp,int c_id, int mn)    //Function Definition. 
{
	for (int i = 0; i < 10; i++)
	{
		if (findCustomerById(c_id))
		{
			if (p[i].model_number == mn)
			{
				if (p[i].av_quantity >= qp)
				{
					q_index = i;
					c[c_id].bill = c[c_id].bill + p[i].retail_cost * qp;
					return true;
					break;
				}
			}
		}
			
	}
	return false;
}

void Customers(Customer)  //Function Definition. 
{
	int i, j, count = 0, countp = 0;
	char opt;
	int c_id, p_mn, p_q;
	int c_r = 0;
	bool isCustomer, isProduct, isQuantity, receipt;

	do
	{
		cout << "\t\t\tWelcome in Customer Mode" << endl << endl;

		cout << "Press a, to Add a Customer." << endl;
		cout << "Press b, to Start Shopping." << endl;
		cout << "Press c, to See Customer Detail." << endl;
		cout << "Press e, to Exit from Customer Mode." << endl;
		cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

		cout << "Enter Your Choice: ";
		cin >> opt;
		cout << "\n-------------------------------------------------------------------------------------" << endl << endl;

		switch (opt)
		{
		case 'a':
		{
			cout << "\t\t**Enter a Customer** " << endl << endl;

			for (j = 0; j < 5; j++)
			{
				cout << "Enter Customer Name:   ";
				getline(cin, c[j].name, '.');

				cout << "Enter Customer Id:     ";
				cin >> c[j].id;

				count++;

				cout << "\nDo you want to Introduce More Customer? (Y=Yes or N=No)";
				cin >> opt;
				cout << endl;

				if (opt == 'n' || opt == 'N')
				{
					break;
				}
				else
				{
					continue;
				}
			}

			cout << "-------------------------------------------------------------------------------------" << endl << endl;
			cout << "\t\tCustomer Entered Data" << endl << endl;

			for (j = 0; j < count; j++)
			{
				cout << "Customer Name is:   " << c[j].name << endl;
				cout << "Customer Id is:     " << c[j].id << endl;
				cout << endl;
			}
			cout << "\n-------------------------------------------------------------------------------------" << endl << endl;
			break;
		}

		case 'b':
		{
			cout << "\t\tAvailable Items In the Store." << endl << endl;

			for (i = 0; i < filledElements; i++)
			{
				cout << "Product Name: " << p[i].name << endl;
				cout << "Product Model Number:   " << p[i].model_number << endl;
				cout << "Product Wholesale Cost: " << p[i].wholesale_cost << endl;
				cout << "Product Retail Cost:    " << p[i].retail_cost << endl;
				cout << "Product Quantity:       " << p[i].av_quantity << endl;
				cout << endl;
			}

			cout << "-------------------------------------------------------------------------------------" << endl << endl;

			cout << "\t\tTo Buy Something Enter These Things" << endl << endl;

			cout << "Enter Customer Id:           ";
			cin >> c_id;

			isCustomer = findCustomerById(c_id);     //Function Calling.
			if (isCustomer)
			{
				do
				{
					cout << "Enter Product Model Number:  ";
					cin >> p_mn;
					isProduct = findProductByMN(p_mn, c_id);   //Function Calling.

					if (isProduct)
					{
						cout << "Enter Quantity of Product:   ";
						cin >> p_q;
						isQuantity = findQuantity(p_q, c_id, p_mn);   //Function Calling.

						if (isQuantity)
						{
							p[q_index].av_quantity = p[q_index].av_quantity - p_q;
							p[q_index].s_quantity = p[q_index].s_quantity + p_q;
							cout << "\nYou Buy this Product" << endl;
						}
						else
						{
							cout << "\nSORRY! Product is out of Stock." << endl;
						}
					}
					else
					{
						cout << "\nSORRY! Product does not exist." << endl;
					}

					cout << "\nDo you want to buy more Products? (Y=Yes or N=No)";
					cin >> opt;
					cout << endl;

				} while (opt != 'n' && opt != 'N');

				cout << "Your Total Bill is " << c[c_id].bill << endl << endl;

				cout << "\t\tCHECKOUT" << endl;

				int amount, new_c_id;

				cout << "Please Enter your Id: ";
				cin >> new_c_id;

				cout << "Please Enter Recipt Amount: ";
				cin >> amount;

				cout << endl;

				if (new_c_id == c_id)
				{
					if (amount <= c[c_id].balance)
					{
						if (amount == c[c_id].bill)
						{
							cout << "You have Succesfully Purchased the Products " << endl;
							c[c_id].balance = c[c_id].balance - amount;
						}
						else if (amount < c[c_id].bill)
						{
							cout << "Uddhar Ik Jung Hai Isliye Band Hai." << endl;
						}
						else if (amount > c[c_id].bill)
						{
							cout << "Ziyada Paisay Kuin Dyraha hai Bhai...." << endl;
						}
						//else
						//{
						//	cout << "Ziyada Paisay Kuin Dyraha hai Bhai.." << endl;
						//}
					}
					else
					{
						cout << "Uddhar Ik Jung Hai Isliye Band Hai" << endl;
					}
				}
				else
				{
					cout << "Enter valid customer Id." << endl;
				}

				cout << "\n-------------------------------------------------------------------------------------" << endl << endl;
			}
			else
			{
				cout << "SORRY! Invalid Customer Id." << endl;
			}
			cout << "\n-------------------------------------------------------------------------------------" << endl << endl;
			break;
		}

		case 'c':
		{
			cout << "Enter Customer Id: ";
			cin >> c_id;

			isCustomer = findCustomerById(c_id);
			if (isCustomer)
			{
				cout << "\n\t\tCustomer Details." << endl;

				for (i = 0; i < 5; i++)
				{
					if (c[i].id == c_id)
					{
						cout << "Id of Customer is:    " << c[i].id << endl;
						cout << "Name of Customer is:  " << c[i].name << endl;
						cout << "Current Balance is:   " << c[c_id].balance << endl;
						cout << "History of Bought Products " << endl;

						for (int j = 0; j < history_index; j++)
						{
							cout << c[i].buying_history[j];
						}
						cout << endl;
						break;
					}
					else
					{
						continue;
					}
				}
			}
			else
			{
				cout << "SORRY! Customer Id not found." << endl;
			}
			cout << "\n-------------------------------------------------------------------------------------" << endl << endl;
		}

		}
	} while (opt != 'e');
}