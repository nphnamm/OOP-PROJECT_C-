#include <iostream>
#include<string>
#include<stdlib.h>
#include<ctime>
#include<stdbool.h>
#include <iomanip>
#include<fstream>
#include<stdio.h>
#include<conio.h>
using namespace std;


class Customer;
class RoomCustomer;
class Employee;
class Dish;
class RestaurantCustomer;
class Restaurant;
class Hotel;
class Room;
class RoomService;



class Room
{
public:
	string roomType;
	int noOfBeds;
	double rent;
	int roomNo;
	string dsphong;
	int sp;
	int status;

public:
	Room(string roomType, int noOfBeds, double rent, int roomNo,string dsphong)
	{
		this->roomType = roomType;
		this->noOfBeds = noOfBeds;
		this->rent = rent;
		this->roomNo = roomNo;
		this->dsphong = dsphong;
		this->status = 0;
		

	}
	void setRoom()
	{
		cout << "Enter Room Type, No of beds, Rent, RoomNo\n";
		cin >> this->roomType;
		cin >> this->noOfBeds;
		cin >> this->rent;
		cin >> this->roomNo;
		cin >> this->dsphong;
		status = 0;

	}

	Room()
	{
	}




	bool isVacant(Room r)
	{
		if (r.status == 1)
			return false;
		else
			return true;
	}

	void displayDetail()
	{

		cout << "Room Type :: " << this->roomType << endl;
		cout << "Number of Beds :: " << this->noOfBeds << endl;
		cout << "Rent :: " << this->rent << endl;
		cout << "Room Number ::" << this->roomNo << endl;
		if (status == 1)
			cout << " Occupied \n";
		else
			cout << "Vacant \n";
	}

	void vacateRoom(int rno)
	{
		int i;
		for (i = 0; i < 6; i++)
		{
			if (this->roomNo == rno)
				this->status = 0;
		}
	}

	void displayAvailable(Room r[6])
	{
		int i;
		for (i = 0; i < 6; i++)
		{
			if (r[i].status == 0)
				r[i].displayDetail();
		}
	}

};

class Dish
{
public:
	string dishName;
	double price;
	string dishType;
	string stt;
	
public:
	Dish( string stt ,string dishName, double price, string dishType)
	{
		this->stt = stt;
		this->dishName = dishName;
		this->price = price;
		this->dishType = dishType;
		
	}
	Dish()
	{

	}
};



class Customer
{
public:
	string custName;
	string custAddress;
	int custID=100;
	string custPhone;
	string custEmail;
	string checkInTime;
	int status=0;
	

public:
	Customer()
	{
		time_t c = time(0);
		char *dt = ctime(&c);
		this->custName = " ";
		this->custAddress = " ";
		this->custPhone = " ";
		this->custEmail = " ";
		this->checkInTime = dt;
		
		
	}

	void setData()
	{
		time_t now = time(0);
		string dt = ctime(&now);
		this->checkInTime = dt;
		rewind(stdin);
		cout << "\nEnter Name:";
		getline(cin, custName);
		rewind(stdin);
		cout << "\nEnter your Address :";
		getline(cin, custAddress);
		rewind(stdin);
		cout << "\nEnter your Phone number :";
		getline(cin, custPhone);
		cout << "\nEnter your Email : ";
		getline(cin, custEmail);
		custID++;
	}




	virtual void printCustomer()
	{
		
		cout << "ID :: " << custID << endl;

		cout << "Name :: " << custName << endl;
		
		cout << "Address :: " << custAddress << endl;
		
		cout << "Phone Number :: " << custPhone << endl;
	
		cout << "Email :: " << custEmail << endl;
		
		cout << "Check-In Time ::" << checkInTime << endl;

	}
	virtual float viewTotalBill() {
		return 0;
	}
	virtual void allocateRoom(Room r1) {
	}
	virtual void allocateDish(Dish d1) {
	}
	virtual void checkout() {
	}
};

class RoomCustomer : public Customer
{
public:
	double rbill;
	Room r;
	int bookStatus;
public:

	float viewTotalbill()
	{
		cout << "Bill =" << rbill;
		return rbill;
	}

	void allocateRoom(Room r1)
	{
		this->r = r1;
	}

	void printCustomer()
	{

		Customer::printCustomer();
			
			cout << "Room type :: " << r.roomType << endl;
			cout << "Room Number :: " << r.roomNo << endl;
			cout << "So Phong::" << r.sp << endl;
		
	}
	float viewTotalBill()
	{
		this->rbill = r.rent;
		cout << "Bill :: " << this->rbill << endl;
		return rbill;
	}
	void checkOut()
	{
		cout << "Your bill is " << this->rbill << "/-" << endl;
		this->rbill = 0;
		this->r.status = 0;
		cout << "Thank You! Visit Again.\n" << endl;
	}


};


class RestaurantCustomer :public Customer,public RoomCustomer
{
public:
	double dbill;
	Dish d;
	int orderStatus;
public:

	float viewTotalbill()
	{
		cout << "Bill =" << dbill;
		return dbill;
	}

	void allocateDish(Dish d1)
	{
		this->d = d1;
	}
	
	float viewTotalBill()
	{
		
		this->dbill = d.price+rbill ;
		cout << "Bill :: " << this->dbill << endl;
		return this->dbill;
	}

};


class Employee
{

public:


	virtual void performDuty() = 0;
	virtual ~Employee() {
	}
};


class RoomService :public Employee
{
public:
	void performDuty()
	{
		cout << "Employee XYZ arriving at your doorstep...\n\n";
	}

	virtual ~RoomService() {
	}

};

class Waiter :public Employee
{
public:
	void performDuty()
	{

		cout << "\n\nEmployee ABC arriving at your table to take your Order\n\n";

	}
	virtual ~Waiter() {
	}
};

class SelectEmployee {
	//protected:
	Employee* e;

public:
	SelectEmployee(Employee* e1)
	{
		e = e1;
	}

	void performDuty()
	{
		e->performDuty();
	}

};

class Restaurant
{
public:
	Dish dish[8];

public:


	void displayDish(Dish d)
	{
		cout << " Dish Name :: " << d.dishName << endl;
		cout << " Price :: " << d.price << endl;
		cout << " Dish Type :: " << d.dishType;

	}

	void displayMenu()
	{
		int i;
		for (i = 0; i < 8; i++)
		{
			displayDish(dish[i]);
		}

	}

};



class Hotel
{
private:
	static Hotel* instanceHotel;
	string hotelName;
	string hotelAddress;
public:
	Employee* employee[5];
	Restaurant restuarant;
	Room room[6];
	Customer* customer[5];

private:


	Hotel(string hname, string add)
	{
		this->hotelName = hname;
		this->hotelAddress = add;
	}
public:
	static Hotel* getHotel()
	{
		if (!instanceHotel)
			instanceHotel = new Hotel("RENNAISSANCE", "HUBLI");
		return instanceHotel;
	}

	void setHotel(Restaurant r, Room rs[5])
	{
		int i;

		for (i = 0; i < 5; i++)
		{
			this->room[i] = rs[i];
		}
		for (i = 0; i < 8; i++)
			this->restuarant.dish[i] = r.dish[i];

	}


	Room getRoom(int rno)
	{
		int i;
		for (i = 0; i < 6; i++)
		{
			if (room[i].roomNo == rno)
				return room[i];
		}
	}
	void displayAvailble() {
		int i;
		cout << "\n\n----------------------------------------------Room Details----------------------------------------------\n\n";
		cout << setw(25) << "Room Type" << setw(25) << "Number of Beds" << setw(25) << "Rent" << setw(25) << "Room Number" <<setw(20) << "So Phong\n";
		for (i = 0; i < 6; i++)
		{
			if (room[i].status == 0)
			{
				cout << setw(25) << room[i].roomType;
				cout << setw(25) << room[i].noOfBeds;
				cout << setw(25) << room[i].rent;
				cout << setw(25) << room[i].roomNo;
				cout << setw(18) << room[i].dsphong << "\n";
			}
		}
		cout << "\n\n";
	}

	void displayMenu()
	{
		cout << "\n\n-----------------------------------------------Menu-------------------------------------------------\n\n ";
		int i;
		const int width = 8;
		cout << setw(25) << " STT" << setw(25) << " Dish Name" << setw(25) << "Price" << setw(25) << "Dish Type" << endl;
		for (i = 0; i < 8; i++)
		{
			cout << setw(25) << restuarant.dish[i].stt;
			cout << setw(25) << restuarant.dish[i].dishName;
			cout << setw(25) << restuarant.dish[i].price;
			cout << setw(25) << restuarant.dish[i].dishType << "\n";
		}
		cout << "\n\n";
	}

	void bookRoom(int r)
	{
		int i;
		for (i = 0; i < 6; i++)
		{	
			int sphong;
			if (room[i].roomNo == r)
				cout << "\nNhap so phong: ";
				cin >> sphong;
			if (r == 1) {
				
				if (sphong < 200 & sphong >= 100) {
					cout << "\nDat Phong Thanh Cong";
					room[i].sp = sphong;
					break;
				}
				else {
					cout << "\nvui long nhap dung so phong\n";
				}
			}
		}
	}


	void askFeedback()
	{
		int f;
		string cname;
		ofstream feedback;
		feedback.open("feedback.txt", ios::app);
		feedback << "Customer Name\t : ";
		cout << "Enter your Name\n";
		cin >> cname;
		feedback << cname << "\t\t\t";
		cout << " Thanks for your time! \n How likely are you to recommend Hotel Rennaisance to a Friend or Colleague? \n Rate on a scale of 1-10\n";
		cin >> f;
		feedback << "Feedback\t: ";
		feedback << f << "\n";
		feedback.close();
		cout << " Thanks for your valuable feedback!" << endl;
	}

	void getCustomerData(Customer* c)
	{
		cout << " Name :: " << c->custName << endl;
		cout << " Address :: " << c->custAddress << endl;
		cout << " Phone :: " << c->custPhone << endl;
		cout << " Email :: " << c->custEmail << endl;
		cout << " Check-In Time:: " << c->checkInTime << endl;
	}

	void vacateRoom(int rno)
	{
		int i, j = 0;
		for (i = 0; i < 6; i++)
		{

			if (room[i].roomNo == rno)
			{
				j = 1;
				room[i].status = 0;
				cout << "Thank You! Visit Again.\n" << endl;
			}
		}
		if (j == 0)
			cout << "Sorry! Room Not Found, or occupied at the moment\n";

	}
	void takeOrder(string dnm)
	{
		int i, j = 0;
		for (i = 0; i < 8; i++)
		{
			if (restuarant.dish[i].stt == dnm)
			{
				j = 1;
				cout << "Order Successful\n" << endl;
				
				
			}
			
			
		}
		if (j == 0)
			
			cout << "Sorry! Dish Not Found, Enter a valid entry\n";
		return;
	}


};
Hotel* Hotel::instanceHotel = 0;
void pressanykey() {
	printf("\n\nNhan phim bat ki de tiep tuc ...");
	getch();
	system("cls");
}
int main()
{
	int check = 0;



	//ifstream file("Description.txt");
	//if (file.is_open()) {
	//	string line;
	//	while (getline(file,line)) {
	//		printf("%s", line.c_str());
	//	}
	//	file.close();
	//}

	cout << "\n";
	int ch, i, o, ch1, ch2, r, rno, rcount = 0, dcount = 0;
	Room r2;
	string dname;
	Dish d2;
	Hotel* ht = ht->getHotel();

	Dish d[8] = {
		Dish("1","Chocolate Fondue",140,"Desert"),
		Dish("2","Manchow Soup",110,"Soup"),
		Dish("3","Shahi Paneer",220,"Main Course"),
		Dish("4","Arizona Tea",100,"Beverage"),
		Dish("5","Grilled Romaine Salad",180,"Salad"),
		Dish("6","Mushroom Manchurian",170,"Starter"),
		Dish("7","Pina Colada",210,"Cocktail"),
		Dish("8","Raspberry Ripple",120,"Ice Cream")
	};

	Customer* c;
	Restaurant res;
	for (i = 0; i < 8; i++)
	{
		res.dish[i] = d[i];
	}
	ht->restuarant = res;

	Room rm[5] = {
	   Room("Single Room",1,3000,1,"100-199"),
	   Room("Double Room",1,4000,2,"200-299"),
	   Room("TripBoule Room",3,5000,3,"300-399"),
	   Room("Double Double Room",2,6000,4,"400-499"),
	   Room("Vip Room",2,7000,5,"500-599"),
	   
	};
	SelectEmployee* e;
	ht->setHotel(res, rm);
	while (1)
	{
		for (i = 0; i < 5; i++)
		{
			try {


				system("cls");
			level1:	cout << "Enter \n\t\t1. Danh Sach Phong \n\t\t2. Dat Phong \n\t\t3. Don Dep \n\t\t4. Danh Sach Do an  \n\t\t5. Dat Do an \n\t\t6. In Hoa Don  \n\t\t7. Dua Y Kien \n\t\t8. Huy Dat Phong \n\t\t9. Danh Gia \n\t\t10. Xuat Danh Sach \n\t\t11.exit \n\n";
				cin >> ch1;
				switch (ch1)
				{
				case 1:
					system("cls");
					ht->displayAvailble();
					system("pause");
					system("cls");
					goto level1;
				case 2:
					system("cls");
					ht->customer[i] = new RoomCustomer;
					cout << "Enter Your details\n";
					ht->customer[i]->setData();
					check++;
					system("cls");
					
					ht->displayAvailble();
					cout << "Enter Room No\n";
					cin >> rno;
					ht->bookRoom(rno);
					r2 = ht->getRoom(rno);
					ht->customer[i]->allocateRoom(r2);
					pressanykey();
					system("cls");
					goto level1;
					
				case 3:
					if (check == 0)
					{
						cout << "\n\n-----------------------------------------------------------------------------------------\n\n";
						cout << "Cannot vacate a book unless booked\n";
						cout << "\n\n-----------------------------------------------------------------\n\n";
					}

					else
					{
						ht->customer[i]->status = 0;
						cout << "Enter Room No\n";
						cin >> rno;
						ht->vacateRoom(rno);
						cout << "Room vacated\n";

					}
					goto level1;
				case 4:
					system("cls");
					ht->displayMenu();
					pressanykey();
					system("cls");
					goto level1;

				case 5:
					system("cls");
					
					if (check == 0) {
						cout << "\nVui Long Nhap Thong Tin truoc\n";
						pressanykey();
						goto level1;
					}
					else {
						o = 1;
						rewind(stdin);
						ht->customer[i] = new RestaurantCustomer;
						ht->customer[i]->status = 1;
						ht->displayMenu();
						
						cout << "Enter Dish Name you want to Order(Make sure you enter the exact same name.)\n";

						getline(cin, dname);
						ht->takeOrder(dname);

					

						ht->customer[i]->allocateDish(d2);
					}
					pressanykey();
					system("cls");

					if (o == 0)
					{
						cout << "\n\n-----------------------------------------------------------------------------------------\n\n";
						cout << "No such Dish Found";
					}
					goto level1;
				case 6: if (check == 0)
				{
					cout << "\n\n------------------------------------------------------------------------------------------\n\n";

					cout << "Cannot get Invoice Details unless you book a Room\n";
					cout << "\n\n-----------------------------------------------------------------\n\n";
					pressanykey();
					system("cls");
				}

					  else
				{
					system("cls");
					cout << "\n\n-----------------------------------------------------------------\n\n";
					ht->customer[i]->printCustomer();
					ht->customer[i]->viewTotalBill();
					cout << "\n\n-----------------------------------------------------------------\n\n";
					pressanykey();
					system("cls");
					goto level1;
				}
				case 7:
					if (check == 0)

					{
						cout << "\n\n--------------------------------------------------------------------------------------------\n\n";
						cout << "Cannot call Room Service Unless you book a Room\n";
						cout << "\n\n-----------------------------------------------------------------\n\n";
						pressanykey();
						system("cls");
					}

					else
					{
						e = new SelectEmployee(new RoomService);
						e->performDuty();
						//Rennaisance->employee->performDuty()
					}
					goto level1;
				case 8: 	if (check == 0)
				{
					cout << "\n\n-----------------------------------------------------------------------------------\n\n";
					cout << "No Room Booked\n";
					pressanykey();

				}

					  else
				{

					ht->customer[i]->status = 0;
					cout << "Enter Room No\n";
					cin >> rno;
					ht->vacateRoom(rno);
					cout << "Cancellation Successful!\n";

				}
					  goto level1;
				case 9: if (check == 0)
				{
					cout << "\n\n-----------------------------------------------------------------------------------\n\n";
					cout << "Cannot give feedback unless you order a Dish\n";
					pressanykey();

				}
					  else

					ht->askFeedback();
					goto level1;
				case 11: return 0;

				
				case 10:
					if (check == 0)
					{
						cout << "\n\n-----------------------------------------------------------------------------------\n\n";
						cout << "Danh sach trong\n";
						pressanykey();

					}
					else {
						for (int i = 0; i < check; i++) {
							ht->customer[i]->printCustomer();
							
							
						}
						pressanykey();
					}
					goto level1;
				}
				






			}
			catch (string erro)
			{
				erro = "EROR";
				cout << "----------------------------------------"<<erro<<"------------------------------------------\n\n";
			}
		}
	}
	
	return 0;
}
