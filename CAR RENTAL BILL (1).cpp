#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

const int MAX=100;

//structures
struct CarRental
{
	char code, delivery;
	int quantity,number=0;
	string cartype, add_delivery;
	double price=0, total_price, new_price[MAX],total_sales=0;
};

//function prototype
void output(CarRental &);
void priceList();
void input(CarRental &,int );
void carType(CarRental &);
void carPrice(CarRental &);
void addDeliver(CarRental &);
void deliverService(CarRental &, int);
void total_sales(CarRental &);

/*main function*/
int main()
{
	CarRental customer;
	int i=0;
	while(i<1)
	{
		char opt;
		string b;
	cout<<"\n***************************************************************************************\n";  
    cout<<setw(45)<<right<<"Billing Management System\n";  
    cout<<"\n***************************************************************************************\n";  
    cout<<"What you want to do?\n";  
    cout<<setw(15)<<left<<"1."<<"To enter new entry\n";
    cout<<setw(15)<<left<<"2."<<"To view total sales\n";
    cout<<setw(15)<<left<<"3."<<"Exit\n";
    cout<<"\n\nEnter your option: ";  
    cin>>opt; 
	
	system("cls"); 

	switch(opt)
	{
		case'1':
			{
				output(customer);
				cout<<"Please press enter to continue...\n";
				cin.ignore();
				getline(cin,b);
				system("cls");
				break;
			}
		case'2':
			{
				total_sales(customer);
				cout<<"Please press enter to continue...\n";
				cin.ignore();
				getline(cin,b);
				system("cls");
				break;
			}
		case'3':
			{
				i=1;
				break;
			}
	}
	}
	return 0;
	
}

void output(CarRental &customer)
{
    /*text file output in NotePad File*/
	ofstream outputFile;
	outputFile.open("CarRental.txt");
	
    // exit option
	char ans;
	
	do
	{
		int x=customer.number+1;
		input(customer,x);
		
		outputFile<<fixed<<setprecision(2);
		outputFile<<"***************************************************************************************"<<endl<<endl;
		outputFile<<setw(45)<<"Car Rental Receipt for Customer"<<x<<endl<<endl;
		outputFile<<setw(30)<<left<<"Car Type"<<setw(10)<<right<<": "<<customer.cartype<<endl;
		outputFile<<setw(30)<<left<<"Quantity Total"<<setw(10)<<right<<": "<<customer.quantity<<endl;
		outputFile<<setw(30)<<left<<"Price"<<setw(10)<<right<<": "<<"RM"<<customer.total_price<<endl;
		outputFile<<setw(30)<<left<<"Add Delivery"<<setw(10)<<right<<": "<<customer.add_delivery<<endl;
		outputFile<<setw(30)<<left<<"New price + Gov Tax"<<setw(10)<<right<<": "<<"RM"<<customer.new_price[x]<<endl<<endl;
		outputFile<<"Thank you and please come again"<<endl<<endl;
		outputFile<<"****************************************************************************************"<<endl;
		outputFile<<"\n\n";
	
		customer.number++;//update for the num of customers
 	   
 	   //asking the user whether to continue or not
 	   cout<<"Do you want to continue?(Y for yes; N for no): ";
 	   cin>>ans;
	   system("cls");
		
 	}while(ans!='N'&&ans!='n');
	
	
	
 	outputFile.close();
}

void priceList()
{
    /*IDE output on DEV C++*/
	cout<<setw(65)<<"CAR RENTAL"<<endl;
	cout<<"************************************************************************************************************************"<<endl;
	cout<<setw(30)<<"CAR"<<setw(30)<<"CODE"<<setw(30)<<"PRICE(RM)"<<setw(30)<<"ADDITIONAL DELIVERY(RM)"<<endl;
	cout<<"************************************************************************************************************************"<<endl;
	cout<<setw(30)<<"SEDAN"<<setw(30)<<"S"<<setw(30)<<"185.00"<<endl;
	cout<<setw(30)<<"SUV"<<setw(30)<<"U"<<setw(30)<<"350.00"<<endl;
	cout<<setw(30)<<"MPV"<<setw(30)<<"M"<<setw(30)<<"550.00"<<setw(30)<<"20.00 each"<<endl;
	cout<<setw(30)<<"TRUCK"<<setw(30)<<"T"<<setw(30)<<"650.00"<<endl;
	cout<<"MAXIMUM NUMBER OF CUSTOMERS IS 100"<<endl<<endl;

}

void input(CarRental &customer,int num)
{
	int i=0;
	while(i<1)
	{
		priceList();
		    
		cout<<"CUSTOMER: "<<num<<endl;
		cout<<"Choose available car code (S/U/M/T): ";
		cin>>customer.code;
		carType(customer);
		if(customer.cartype=="Invalid")
		{
			system("cls");
			cout<<"**Invalid. Please enter again.**\n"<<endl;
			continue;
		}
		int p=0;
		while(p==0)
		{
			cout<<"Quantity: ";
			cin>>customer.quantity;	
			if(customer.quantity<0)
			{
				cout<<"Please enter again!!!!"<<endl;
				continue;
			}
			if(customer.quantity>100)
			{
				cout<<"MAXIMUM 100 cars to be rent for each customer.Please enter again!!!!"<<endl;
				continue;
			}
			p++;
		}
		cout<<fixed<<setprecision(2);
		carPrice(customer);
		cout<<"Total Price: RM"<<customer.total_price<<endl;
		int j=0;
		while(j<1)
		{
			cout<<"Additional delivery services? (Y/N): ";
			cin>>customer.delivery;
			addDeliver(customer);
			if(customer.add_delivery=="Invalid")
			{
				cout<<"**Invalid. Please enter again.**\n";
				continue;
			}
			j++;
		}
		deliverService(customer, num);
		cout<<"New Price + Gov tax(4%): RM"<<customer.new_price[num]<<endl<<endl;
		cout<<"Bill was printed to CarRentalBill.txt\n";
		i++;
	}
}

/*fucntion for car type*/
void carType(CarRental &customer)
{
	if (customer.code=='S'||customer.code=='s')
    {
		customer.cartype="Sedan";
	}
	else if (customer.code=='U'||customer.code=='u')
	{
		customer.cartype="SUV";
	}
	else if (customer.code=='M'||customer.code=='m')
	{
		customer.cartype="MPV";
	}
	else if (customer.code=='T'||customer.code=='t')
	{
		customer.cartype="Truck";
	}
	else 
	{
		customer.cartype="Invalid";
	}
}

/*function for total price*/
void carPrice(CarRental &customer)
{	
	if (customer.code=='S'||customer.code=='s')
    {customer.price=185.00;}
	else if (customer.code=='U'||customer.code=='u')
	{customer.price=350.00;}
	else if (customer.code=='M'||customer.code=='m')
	{customer.price=550.00;}
	else if (customer.code=='T'||customer.code=='t')
	{customer.price=650.00;}
	else 
	{customer.price=0.00;}
	
	customer.total_price=customer.price*customer.quantity;
}

void addDeliver(CarRental &customer)
{
    if (customer.delivery=='Y'||customer.delivery=='y')
    {customer.add_delivery="Yes";}
    else if (customer.delivery=='N'||customer.delivery=='n')
    {customer.add_delivery="No";}
    else
    {customer.add_delivery="Invalid";}
}

/*function for new price*/
void deliverService(CarRental &customer, int num)
{
	if (customer.delivery=='Y'||customer.delivery=='y')
	{customer.new_price[num]=(customer.total_price+20)*(1.04);}
	else
	{customer.new_price[num]=customer.total_price*1.04;}
}

void total_sales(CarRental &customer) 
{
    if (customer.number != 0) 
	{
        customer.total_sales = 0; // Reset total_sales to avoid accumulating previous values
        for (int i = 1; i < customer.number+1; i++) 
		{
            customer.total_sales += customer.new_price[i];
            cout << "\nCustomer #" << i << " = RM " << customer.new_price[i] << endl;
        }
        cout << "\n\nTotal sales per day is RM " << customer.total_sales<<endl<<endl;
    } 
	
	else 
	{
        cout << "\n**No data stored**\n\n";
    }
}
