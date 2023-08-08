// Header Files
#include<iostream>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
#include<ncurses.h>
#include<unistd.h>
using namespace std;	// Declaring namespaces

class shopping {
protected:
	int pcode;
	float price;
	float dis;
	string pname;
		
public:
    void menu();
	void administrator();
	void add();
	void rem();
	void list();
	virtual void buyer() {}		
};

class customer: public shopping {
	void receipt();
	void buyer();
};

void shopping::menu() {
	m:
	int choice;
	string email;
	string password;
	system("clear");
	cout<<"░██████╗██╗░░░██╗██████╗░███████╗██████╗░███╗░░░███╗░█████╗░██████╗░██╗░░██╗███████╗████████╗\n██╔════╝██║░░░██║██╔══██╗██╔════╝██╔══██╗████╗░████║██╔══██╗██╔══██╗██║░██╔╝██╔════╝╚══██╔══╝\n╚█████╗░██║░░░██║██████╔╝█████╗░░██████╔╝██╔████╔██║███████║██████╔╝█████═╝░█████╗░░░░░██║░░░\n░╚═══██╗██║░░░██║██╔═══╝░██╔══╝░░██╔══██╗██║╚██╔╝██║██╔══██║██╔══██╗██╔═██╗░██╔══╝░░░░░██║░░░\n██████╔╝╚██████╔╝██║░░░░░███████╗██║░░██║██║░╚═╝░██║██║░░██║██║░░██║██║░╚██╗███████╗░░░██║░░░\n╚═════╝░░╚═════╝░╚═╝░░░░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝░░░╚═╝░░░\n\n\t\t███╗░░░███╗░█████╗░██╗███╗░░██╗  ███╗░░░███╗███████╗███╗░░██╗██╗░░░██╗\n\t\t████╗░████║██╔══██╗██║████╗░██║  ████╗░████║██╔════╝████╗░██║██║░░░██║\n\t\t██╔████╔██║███████║██║██╔██╗██║  ██╔████╔██║█████╗░░██╔██╗██║██║░░░██║\n\t\t██║╚██╔╝██║██╔══██║██║██║╚████║  ██║╚██╔╝██║██╔══╝░░██║╚████║██║░░░██║\n\t\t██║░╚═╝░██║██║░░██║██║██║░╚███║  ██║░╚═╝░██║███████╗██║░╚███║╚██████╔╝\n\t\t╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝╚═╝░░╚══╝  ╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚══╝░╚═════╝░\n\n"<<endl;
	cout<<"\t\t\t\t\t   1) Administrator    \n";
	cout<<"\t\t\t\t\t                       \n";
	cout<<"\t\t\t\t\t   2) Buyer            \n";
	cout<<"\t\t\t\t\t                       \n";
	cout<<"\t\t\t\t\t   3) Exit             \n";
	cout<<"\n\t\t\t\t Please select!  ";
	cin>>choice;
	
	switch(choice) {
		case 1:
			cout<<"\n\n\t\t\t LOGIN CREDENIALS: \n";
			cout<<"\n\t\t\t Email: ";
			cin>>email;
			cout<<"\t\t\t Password: ";
			cin>>password;
			
			if(email=="1" && password=="1") {
				system("clear");
				administrator();
			}
			else {
				cout<<"Invalid email/password";
				break;
			}
		case 2:
			{
				buyer();
			}
		case 3:
			{
				exit(0);
			}
		default :
			{
				cout<< "Please select from the given options";	
			}	
	}
goto m;
}

void shopping::administrator() {
	m:
	int choice;
	system("clear");

cout<<"─█▀▀█ █▀▀▄ █▀▄▀█ ─▀─ █▀▀▄ ─▀─ █▀▀ ▀▀█▀▀ █▀▀█ █▀▀█ ▀▀█▀▀ █▀▀█ █▀▀█ 　 ░█▀▄▀█ █▀▀ █▀▀▄ █──█\n░█▄▄█ █──█ █─▀─█ ▀█▀ █──█ ▀█▀ ▀▀█ ──█── █▄▄▀ █▄▄█ ──█── █──█ █▄▄▀ 　 ░█░█░█ █▀▀ █  █ █──█\n░█─░█ ▀▀▀─ ▀───▀ ▀▀▀ ▀──▀ ▀▀▀ ▀▀▀ ──▀── ▀─▀▀ ▀──▀ ──▀── ▀▀▀▀ ▀─▀▀ 　 ░█──░█ ▀▀▀ ▀  ▀ ─▀▀▀\n\n"<<endl;
	cout<<"\n\t\t\t\t           1) Add the product       ";
	cout<<"\n\t\t\t\t                                   ";
	cout<<"\n\t\t\t\t           2) Delete the product   ";
    cout<<"\n\t\t\t\t                                   ";
    cout<<"\n\t\t\t\t           3) Back to main menu    ";
    
    cout<<"\n\n\t Enter your Choice: ";
    cin>>choice;
    
    switch(choice) {
    	case 1:
    		add();
    		break;
    	case 2:
    		rem();
    		break;
    	case 3:
    		menu();
    		break;
    	default :
    		cout<<"Invalid choice!\n";	
	}
	goto m;
}

void shopping::add() {
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;

	system("clear");
	cout<<" █▀▀█ █▀▀▄ █▀▀▄ 　 █▀▀▄ █▀▀ █───█ 　 ░█▀▀█ █▀▀█ █▀▀█ █▀▀▄ █──█ █▀▀ ▀▀█▀▀\n░█▄▄█ █──█ █──█ 　 █──█ █▀▀ █▄█▄█ 　 ░█▄▄█ █▄▄▀ █──█ █──█ █──█ █── ──█──\n░█─░█ ▀▀▀─ ▀▀▀─ 　 ▀──▀ ▀▀▀ ─▀─▀─ 　 ░█─── ▀─▀▀ ▀▀▀▀ ▀▀▀─ ─▀▀▀ ▀▀▀ ──▀──\n\n"<<endl;
	cout<<"\n\n\t Serial Number: ";
	cin>>pcode;
	cout<<"\n\n\t Name of the product: ";
	cin>>pname;
	cout<<"\n\n\t Price of the product: ";
	cin>>price;
	cout<<"\n\n\t Discount on product(in Percentage): ";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data) {
		data.open("database.txt", ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else {
		data>>c>>n>>p>>d;
		while(!data.eof()) {
			if(c == pcode) {
				token++;	
			}
			data>>c>>n>>p>>d;
		}
		data.close();
		
		if(token==1) {
			cout<<"\n\tSame Product Serial Number does exist.\n";
			sleep(2);
	 		goto m;
		}
		else{
			data.open("database.txt", ios::app|ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			data.close();
		}
	}
	cout<<"\n\n\t\t Record inserted!\n";
	sleep(1);
}

void shopping::rem() {
	
	fstream data,data1;
	int pkey;
	int token=0;
	system("clear");
	cout<<" █▀▀▄ █▀▀ █── █▀▀ ▀▀█▀▀ █▀▀ 　 ░█▀▀█ █▀▀█ █▀▀█ █▀▀▄ █──█ █▀▀ ▀▀█▀▀\n░█─░█ █▀▀ █── █▀▀ ──█── █▀▀ 　 ░█▄▄█ █▄▄▀ █──█ █──█ █──█ █── ──█──\n░█▄▄▀ ▀▀▀ ▀▀▀ ▀▀▀ ──▀── ▀▀▀ 　 ░█─── ▀─▀▀ ▀▀▀▀ ▀▀▀─ ─▀▀▀ ▀▀▀ ──▀──\n\n"<<endl;
	list();
	cout<<"\n\n\t Serial Number: ";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data) {
		cout<<"File doesnt exist";	
	}
	
	else {
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()) {
			if(pcode==pkey) {
				cout<<"\n\n\t Product deleted succesfully\n";
				sleep(1);
				token++;
			}
			else {
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";	
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		
		if(token==0) {
			cout<<"\n\n Record not found!\n";
			sleep(1);
		}
	}
}

void shopping::list() {

	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n----------------------------------------------\n\n";
	cout<<left<<setw(20)<<"Sr. No"<<left<<setw(20)<<"Name"<<left<<setw(20)<<"Price";
	cout<<"\n\n----------------------------------------------\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<left<<setw(20)<<pcode<<left<<setw(20)<<pname<<left<<setw(20)<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void customer::buyer() {
	int choice;
	system("clear");
	m:
	cout<<"\n\n\t\t░█▀▀█ █──█ █──█ █▀▀ █▀▀█ 　 ░█▀▄▀█ █▀▀ █▀▀▄ █──█\n\t\t░█▀▀▄ █──█ █▄▄█ █▀▀ █▄▄▀ 　 ░█░█░█ █▀▀ █──█ █──█\n\t\t░█▄▄█ ─▀▀▀ ▄▄▄█ ▀▀▀ ▀─▀▀ 　 ░█──░█ ▀▀▀ ▀──▀ ─▀▀▀\n\n";
	cout<<"\n\t\t\t\t           1) Buy the product       ";
	cout<<"\n\t\t\t\t                                   ";
	cout<<"\n\t\t\t\t           2) Go back               \n\n";
	cout<<"\t\t\t Enter your choice : ";
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;	
		case 2:
			menu();
			goto m;
			break;
		default :
			cout<<"invalid choice\n";
	}
}

void customer::receipt() 
	{
		system("clear");
		fstream data;
		
		int arrc[100],arrq[100];
		char choice;
		int c=0;
		float amount=0;
		float dis=0;
		float total=0;
		cout<<"\n\n\t\t  █░░ █ █▀ ▀█▀\n\t\t  █▄▄ █ ▄█ ░█░ ";
		data.open("database.txt",ios::in);
		if(!data)
		{
			cout<<"\n\n Empty database";
		}
		else
		{
			data.close();                                   
			list();
			cout<<"\n----------------------------------------------";
			cout<<"\n            Please place the order   \n";
			cout<<"----------------------------------------------\n";
			do
			{
				m:
				cout<<"\n\n Serial Number : ";
				cin>>arrc[c];
				cout<<"\n Product Quantity : ";
				cin>>arrq[c];
				for(int i=0;i<c;i++)
				{
					if(arrc[c] == arrc[i])
					{
						cout<<"\n\n Incorrect Serial Number. Please try again!";
						goto m;
					}
				}
				c++;             
				cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
				cin>>choice;	
			} while(choice == 'y');
			
			system("clear");
			
			cout<<"\n\n\t\t\t           ---------------RECEIPT---------------\n";
			cout<<left<<setw(20)<<"\nSerial Number"<<left<<setw(20)<<"Product Name"<<left<<setw(20)<<"Quantity"<<left<<setw(20)<<"Price"<<left<<setw(20)<<"Amount"<<left<<setw(20)<<"Amount with discount\n\n";
			
			
			for(int i=0;i<c;i++) 
			{
				data.open("database.txt",ios::in);
				data>>left>>setw(20)>>pcode>>left>>setw(20)>>pname>>left>>setw(20)>>price>>left>>setw(20)>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])   
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total =total+ dis;
						cout<<left<<setw(20)<<pcode<<left<<setw(20)<<pname<<left<<setw(20)<<arrq[i]<<left<<setw(20)<<price<<left<<setw(20)<<amount<<left<<setw(20)<<dis<<endl;	
					}
					   data>>pcode>>pname>>price>>dis;  
				}
				data.close();
			}
			cout<<"\n";
			cout<<"-------------------------------------------------------------------------------------------------------------------------\n";
			cout<<"\n Total Amount: "<<left<<setw(20)<<" "<<left<<setw(20)<<" "<<left<<setw(20)<<" "<<left<<setw(25)<<" "<<left<<setw(30)<<total<<"\n\n"<<endl;
		}
	}
int main()
{
	customer s;
	s.menu();
}

