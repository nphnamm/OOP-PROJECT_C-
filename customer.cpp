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

