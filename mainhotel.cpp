	#include <iostream>
	#include<string>
	#include<stdlib.h>
	#include<ctime>
	#include<stdbool.h>
	#include <iomanip>
	#include<fstream>
	#include<stdio.h>
	#include<conio.h>
	#include<vector>
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
		this->sp = 0;

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

	void displayDetail()
	{

		cout << "Room Type :: " << this->roomType << endl;
		cout << "Number of Beds :: " << this->noOfBeds << endl;
		cout << "Rent :: " << this->rent << endl;
		cout << "Room Number ::" << this->roomNo << endl;
		
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
	
	int getsp() {
		return this->sp;
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



class Customer :public Room
{
public:
	string custName;
	string custAddress;
	int custID;
	string custPhone;
	string custEmail;
	string checkInTime;
	int sp;
	static int id;
	string CheckOutTime;

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
		this->custID = id++;
		
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
		
		time_t now = time(0);
		string dt = ctime(&now);
		this->CheckOutTime = dt;
		cout << "ID :: " << custID << endl;

		cout << "Name :: " << custName << endl;
		
		cout << "Address :: " << custAddress << endl;
		
		cout << "Phone Number :: " << custPhone << endl;
	
		cout << "Email :: " << custEmail << endl;
		
		cout << "Check-In Time ::" << checkInTime ;

		cout << "Check Out Time ::" << CheckOutTime;
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
	virtual int getsp() {
		return 0;
	}
	
};
int Customer::id = 100;

class RoomCustomer : public Customer
{
public:
	double bill;
	Room r;
	int bookStatus;
	
public:

	float viewTotalbill()
	{
		cout << "Bill =" << bill;
		return bill;
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
		this->bill = r.rent ;
		cout << "Bill :: " << this->bill;
		return bill;
	}
	void checkOut()
	{
		cout << "Your bill is " << this->bill << "/-" << endl;
		this->bill = 0;
		this->r.status = 0;
		cout << "Thank You! Visit Again.\n" << endl;
	}
	int getsp() {
		return this->r.sp;
	
	}


};


class RestaurantCustomer :public Customer 
{
public:
	double bill;
	Dish d;
	int orderStatus;
public:

	float viewTotalbill()
	{
		cout << "Bill =" << bill;
		return bill;
	}

	void allocateDish(Dish d1)
	{
		this->d = d1;
	}
	
	float viewTotalBill()
	{
		
		this->bill = d.price ;
		cout << "Bill :: " << this->bill << endl;
		return this->bill;
	}
	void printCustomer()
	{

		Customer::printCustomer();

		cout << "Dish Name  :: " << d.dishName << endl;
		cout << "Dish Type :: " << d.dishType << endl;
		cout << "Price::" << d.price << endl;

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
	Dish getDish(string dnam)
	{
		int i;
		for (i = 0; i < 8; i++)
		{

			if (dish[i].stt == dnam)

			{
				return dish[i];
			}
		}
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
	string acc = "nam";
	string pass = "123";
	

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
	Dish getDish(string dsh)
	{
		int i;
		for (i = 0; i < 8; i++)
		{
			if (restuarant.dish[i].stt == dsh)
				return restuarant.dish[i];
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
			if (room[i].roomNo == r) {
				
				 if (r == 1) {
					cout << "\nNhap so phong 100-200: ";
					cin >> sphong;
					while (sphong > 200 || sphong <= 100) {


						cout << "\nVui long nhap lai so phong:\n";
						cin >> sphong;
					}
				
					room[i].sp = sphong;
				}
				 if (r == 2) {
					cout << "\nNhap so phong 200-300: ";
					cin >> sphong;
					while (sphong > 300 || sphong <= 200) {
						cout << "\nVui long nhap lai so phong:\n";
						cin >> sphong;
					}
					room[i].sp = sphong;	
				}
				 if (r == 3) {
					cout << "\nNhap so phong 300-400: ";
					cin >> sphong;
					while (sphong > 400 || sphong <= 300) {
						cout << "\nVui long nhap lai so phong:\n";
						cin >> sphong;
					}		
					room[i].sp = sphong;
				}
				if (r == 4) {
					cout << "\nNhap so phong 400-500: ";
					cin >> sphong;
					while (sphong > 500 || sphong <= 400) {
						cout << "\nVui long nhap lai so phong:\n";
						cin >> sphong;
					}
					room[i].sp = sphong;
				
				}
				if (r == 5) {
					cout << "\nNhap so phong 500-600: ";
					cin >> sphong;
					while (sphong > 600 || sphong <= 500) {


						cout << "\nVui long nhap lai so phong:\n";
						cin >> sphong;
					}
					cout << "\nDat Phong Thanh Cong";
					room[i].sp = sphong;
					
				}
				cout << "\nVui Long Nhap So Ngay Ban O ";
				int sn;
				cin >> sn;
				while (sn < 1) {
					cout << "\nVui Long Nhap Lai";;
					cin >> sn;
				}
				room[i].rent=room[i].rent*sn;
				cout << "\nDat Phong Thanh Cong";
				break;
			}
			else if ((room[i].roomNo != r)) {
				while (r >= 6 || r < 1)
				{
					cout << "\nVui Long Nhap Lai :";
					cin >> r;
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
void Menu() {
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
	int ch, i =0, o, ch1, ch2, r, rno, rcount = 0, dcount = 0;
	Room r2;
	string dname, tk, mk;
	Dish d2;
	Hotel* ht = ht->getHotel();
	vector<Customer*> ds_customer;
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

	ht->setHotel(res, rm);
	cout << "\n\t\t\t\tNhap Tai Khoan: ";
	getline(cin, tk);
	cout << "\n\t\t\t\tNhap Mat khau :";
	getline(cin, mk);
	while (tk != ht->acc || mk != ht->pass) {
		system("cls");
		cout << "\n\t\t\t\tNhap Lai Tai Khoan va Mat Khau";
		cout << "\n\t\t\t\tNhap Tai Khoan: ";
		getline(cin, tk);
		cout << "\n\t\t\t\tNhap Mat khau :";
		getline(cin, mk);
	}

	while (true)
	{
		
			


				system("cls");
			level1:	cout << "\t\t\t-----------------------------------------------------------------\n";
				cout <<"\t\t\t------------CHUONG TRINH QUAN LY KHACH SAN ----------------------\n";
				cout <<"\t\t\t-	1.Danh Sach Phong Dang Co\t\t\t\t-\n";
				cout <<"\t\t\t-	2.Dat Phong              \t\t\t\t-\n";
				cout <<"\t\t\t-	3.Don Phong              \t\t\t\t-\n";
				cout <<"\t\t\t-	4.Danh Sach Do An        \t\t\t\t-\n";
				cout <<"\t\t\t-	5.Dat Do An              \t\t\t\t-\n";
				cout <<"\t\t\t-	6.In Hoa Don             \t\t\t\t-\n";
				cout <<"\t\t\t-	7.Khong Hai Long         \t\t\t\t-\n";
				cout <<"\t\t\t-	8.Huy Dat Phong          \t\t\t\t-\n";
				cout <<"\t\t\t-	9.Give FeedBack          \t\t\t\t-\n";
				cout <<"\t\t\t-	10.Danh Sach Phong Da Dat\t\t\t\t-\n";
				cout <<"\t\t\t--------------------Nhap Lua Chon Cua Ban------------------------\n";
				cin >> ch1;
				Customer* customer = new RoomCustomer ;
				{
					if (ch1 == 1) {
						system("cls");
						ht->displayAvailble();
						system("pause");
						system("cls");
						goto level1;
					}
					else if (ch1==2) {
						system("cls");
						
						cout << "Enter Your details\n";
						customer->setData();
						
						check++;
						system("cls");
						ds_customer.push_back(customer);
						
						ht->displayAvailble();
						cout << "Enter Room No\n";
						cin >> rno;
						ht->bookRoom(rno);
						r2 = ht->getRoom(rno);
						customer->allocateRoom(r2);
						pressanykey();
						system("cls");
						goto level1;
					}
					else if (ch1 ==3) {
						if (check == 0)
						{
							cout << "\n\n-----------------------------------------------------------------------------------------\n\n";
							cout << "Cannot vacate a book unless booked\n";
							cout << "\n\n-----------------------------------------------------------------\n\n";
						}

						else
						{

							cout << "Enter Room No\n";
							cin >> rno;
							for(int i=0;i<ds_customer.size();i++){
								while (ds_customer[i]->getsp() != rno) {
									
									cout << "\nVui Long Nhap Lai";
									cin >> rno;
								}
								cout << "Room vacated\n";
							
							}
							
	
						}
						goto level1;
					}
					else if (ch1 == 4) {
						system("cls");
						ht->displayMenu();
						pressanykey();
						system("cls");
						goto level1;
					}

					else if (ch1 == 5) {
						system("cls");

						if (check == 0) {
							cout << "\nVui Long Nhap Thong Tin truoc\n";
							pressanykey();
							goto level1;
						}
						else {
							o = 1;
							rewind(stdin);
							ht->displayMenu();
							int od;
						
							cout << "\nNhap Phong Muon Order ";
							cin >> od;
							for (int i = 0; i < ds_customer.size(); i++) {
								if (ds_customer[i]->getsp() == od) {
									rewind(stdin);
									cout << "Enter Dish Name you want to Order(Make sure you enter the exact same name.)\n";
									getline(cin, dname);
									ht->takeOrder(dname);
									d2 = ht->getDish(dname);
									customer->allocateDish(d2);
									
								}
								
							
							}
							
						}
						pressanykey();
						system("cls");

						if (o == 0)
						{
							cout << "\n\n-----------------------------------------------------------------------------------------\n\n";
							cout << "No such Dish Found";
						}

						goto level1;
					}
					else if (ch1 == 6) {
						if (check == 0)
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
							int px;
							cout << "\nNhap So Phong Can Xuat Hoa Don";
							cin >> px;
							
							for (int i = 0; i < ds_customer.size(); i++)
							{
								if(ds_customer[i]->getsp()==px){
									ds_customer[i]->printCustomer();
									ds_customer[i]->viewTotalBill();
									cout << "\n\n-----------------------------------------------------------------\n\n";
									pressanykey();
									system("cls");
									
								}
							}
						
							goto level1;
						}
					}
					else if (ch1 == 7) {
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
							Employee *e = new RoomService;
							e->performDuty();
							
						}
						goto level1;
					}
					else if (ch1 == 8) {
						if (check == 0)
						{
							cout << "\n\n-----------------------------------------------------------------------------------\n\n";
							cout << "No Room Booked\n";
							pressanykey();
						}
						else
						{
							cout << "Enter Room No\n";
							cin >> rno;
							ht->vacateRoom(rno);
							cout << "Cancellation Successful!\n";

						}
						goto level1;
					}
					else if (ch1 == 9) {
						if (check == 0)
						{
							cout << "\n\n-----------------------------------------------------------------------------------\n\n";
							cout << "Cannot give feedback unless you order a Dish\n";
							pressanykey();

						}
						else

							ht->askFeedback();
						goto level1;
					}

				else if( ch1==10){
					if (check == 0)
					{
						cout << "\n\n-----------------------------------------------------------------------------------\n\n";
						cout << "Danh sach trong\n";
						pressanykey();

					}
					else {
						system("cls");
						cout << "\n\n----------------------------------------------Room List Booked----------------------------------------------\n\n";
						cout  << "ID" << setw(5) << "Name" << setw(20) << "Address" << setw(20) << "Phone Number" << setw(20) << "Check In Time" << setw(20) <<"Room Type" << setw(20) <<"Room Number "<< setw(15) <<"So Phong\n";
						for (int i = 0; i < ds_customer.size(); i++) {
							
							cout << "\nKhach Hang Thu " << i + 1 <<endl;
							
							ds_customer[i]->printCustomer();
							

						}
						pressanykey();
					}
					goto level1;
				}
				else if (ch1 == 11) {
				return ;
				}
				else {
				cout << "\nNhap Lai ";
				}

			}
			/*catch (string erro)
			{
				erro = "EROR";
				cout << "----------------------------------------" << erro << "------------------------------------------\n\n";
			}*/
		}
	}

int main()
{
	Menu();
	system("pause");
	return 0;
}
