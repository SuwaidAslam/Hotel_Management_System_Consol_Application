#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <vector>
#include <windows.h>
using namespace std;
const int total_rooms = 250;
class Room {
private:
	static int roomCount;
public:
	int fare;
	char type[20];
	int roomNum;
	int floor_num;
	bool status; //0 = not reserved\ 1 = reserved
	char allotedName[100];
	Room();
	virtual ~Room() {}
	virtual void reset() = 0;
};

Room::Room() {
		roomCount++;
		roomNum = roomCount;
		strcpy(allotedName, "Empty");
		status = 0;
		if (roomNum <= 50) {
			if (roomNum <= 10)
				this->floor_num = 1;
			if (roomNum > 10 && roomNum <= 20)
				this->floor_num = 2;
			if (roomNum > 20 && roomNum <= 30)
				this->floor_num = 3;
			if (roomNum > 30 && roomNum <= 40)
				this->floor_num = 4;
			if (roomNum > 40 && roomNum <= 50)
				this->floor_num = 5;
		}
		else if (roomNum > 50 && roomNum <= 100) {
			if (roomNum <= 60)
				this->floor_num = 1;
			if (roomNum > 60 && roomNum <= 70)
				this->floor_num = 2;
			if (roomNum > 70 && roomNum <= 80)
				this->floor_num = 3;
			if (roomNum > 80 && roomNum <= 90)
				this->floor_num = 4;
			if (roomNum > 90 && roomNum <= 100)
				this->floor_num = 5;
		}
		else if (roomNum > 100 && roomNum <= 150) {
			if (roomNum <= 110)
				this->floor_num = 1;
			if (roomNum > 110 && roomNum <= 120)
				this->floor_num = 2;
			if (roomNum > 120 && roomNum <= 130)
				this->floor_num = 3;
			if (roomNum > 130 && roomNum <= 140)
				this->floor_num = 4;
			if (roomNum > 140 && roomNum <= 150)
				this->floor_num = 5;
		}
		else if (roomNum > 150 && roomNum <= 200) {
			if (roomNum <= 160)
				this->floor_num = 1;
			if (roomNum > 160 && roomNum <= 170)
				this->floor_num = 2;
			if (roomNum > 170 && roomNum <= 180)
				this->floor_num = 3;
			if (roomNum > 180 && roomNum <= 190)
				this->floor_num = 4;
			if (roomNum > 190 && roomNum <= 200)
				this->floor_num = 5;
		}
		else if (roomNum > 200 && roomNum <= 250) {
			if (roomNum <= 210)
				this->floor_num = 1;
			if (roomNum > 210 && roomNum <= 220)
				this->floor_num = 2;
			if (roomNum > 220 && roomNum <= 230)
				this->floor_num = 3;
			if (roomNum > 230 && roomNum <= 240)
				this->floor_num = 4;
			if (roomNum > 240 && roomNum <= 250)
				this->floor_num = 5;
		}
}
int Room::roomCount = 0;
class Standard : public Room {
public:
	Standard() : Room(){
		fare = 300;
		strcpy(type, "Standard");
	}
	Standard(int floorN, int roomN,bool s, char *A_N): Room(){
		floor_num = floorN;
		roomNum = roomN;
		status = s;
		strcpy(allotedName, A_N);
		fare = 300;
		strcpy(type, "Standard");
	}
	void reset() {
	strcpy(allotedName, "Empty");
	status = 0;
	}
};
class Moderate : public Room {
public:
	Moderate() : Room(){
		fare = 500;
		strcpy(type, "Moderate");
	}
	Moderate(int floorN, int roomN,bool s, char *A_N) : Room() {
		floor_num = floorN;
		roomNum = roomN;
		status = s;
		strcpy(allotedName, A_N);
		fare = 500;
		strcpy(type, "Moderate");
	}
	void reset() {
	strcpy(allotedName, "Empty");
	status = 0;
    }

};
class Superior : public Room {
public:
	Superior() : Room(){
		fare = 1000;
		strcpy(type, "Superior");
	}
	Superior(int floorN, int roomN,bool s, char *A_N) : Room() {
		floor_num = floorN;
		roomNum = roomN;
		status = s;
		strcpy(allotedName, A_N);
		fare = 1000;
		strcpy(type, "Superior");
	}
	void reset() {
	strcpy(allotedName, "Empty");
	status = 0;
    }
};
class JuniorSuite : public Room {
public:
	JuniorSuite() : Room(){
		fare = 2000;
		strcpy(type, "JuniorSuite");
	}
	JuniorSuite(int floorN, int roomN,bool s, char *A_N) : Room() {
		floor_num = floorN;
		roomNum = roomN;
		status = s;
		strcpy(allotedName, A_N);
		fare = 2000;
		strcpy(type, "JuniorSuite");
	}
	void reset() {
	strcpy(allotedName, "Empty");
	status = 0;
	}
};
class Suite : public Room {
public:
	Suite() : Room(){
		fare = 5000;
		strcpy(type, "Suite");
	}
	Suite(int floorN, int roomN,bool s, char *A_N) : Room() {
		floor_num = floorN;
		roomNum = roomN;
		status = s;
		strcpy(allotedName, A_N);
		fare = 5000;
		strcpy(type, "Suite");
	}
	void reset() {
	strcpy(allotedName, "Empty");
	status = 0;
	}

};
/// Customer Class
class Customer {
public:
	char name[100];
	int age;
	char gender[10];
	unsigned long int ID_card_num;
	float Balance;
	int days;
	int FloorNum;
	char RoomType[20];
	int RoomNum;
	char CheckinTime[20];
	char CheckinDate[20];
	char CheckoutTime[20];
	char CheckoutDate[20];
	char TimeRemaining[20];
	//func
	void getData();

	Customer() {
		strcpy(name, " ");
		age = 0;
		strcpy(gender, " ");
		ID_card_num = 0;
		Balance = 0;
		days = 0;
		FloorNum = 0;
		strcpy(RoomType, " ");
		strcpy(CheckinTime, " ");
		strcpy(CheckinDate, " ");
		strcpy(CheckoutTime, "00:00");
		strcpy(CheckoutDate, "00");
		strcpy(TimeRemaining, "00:00");
	}
};

void Customer::getData() {
	cin.ignore();
	cout << "Full Name: ";
	cin.getline(name, sizeof(name));
	cout << "Age: ";
	cin >> age;
	cin.ignore();
	cout << "Gender(M/F): ";
	cin.getline(gender, sizeof(gender));
	cout << "ID card-Number: ";
	cin >> ID_card_num;
	cout << "Total Days To Reserve: ";
	cin >> days;
	cin.ignore();
}
/// Hotel Class
class Hotel {
public:
	vector<Room*>rooms;
	vector<Customer> customers;
	int customer_counter = { 0 };
	int checkout_counter = { 0 };
	Hotel()
	{
		for (unsigned int i = 0; i < 50; i++)
			rooms.push_back(new Standard);
		for (unsigned int i = 0; i < 50; i++)
			rooms.push_back(new Moderate);
		for (unsigned int i = 0; i < 50; i++)
			rooms.push_back(new Superior);
		for (unsigned int i = 0; i < 50; i++)
			rooms.push_back(new JuniorSuite);
		for (unsigned int i = 0; i < 50; i++)
			rooms.push_back(new Suite);
		LoadRooms();
		LoadCustomers();
	}
	~Hotel()
	{
		SaveRooms();
		SaveCustomers();
	}
	void main_menu();
	void ReserveRoom();
	void CheckinCustomer();
	void ViewReservedRooms();
	void DetailedReport();
	void SaveRooms();
	void LoadRooms();
	void SaveCustomers();
	void LoadCustomers();
};

void Hotel::SaveRooms() {
	ofstream outfile;
	outfile.open("rooms.txt", ios::trunc);
	if (!outfile) { // If can't open
		cout << "rooms.txt can't open" << endl;
		abort(); // Exit
	}
	else {
		for (unsigned int i = 0; i < total_rooms; i++) {
			outfile << rooms[i]->floor_num << "," << rooms[i]->roomNum << "," << rooms[i]->type << "," << rooms[i]->fare << "," <<
				rooms[i]->status << "," << rooms[i]->allotedName << endl;
		}
		outfile.close();
	}
}
void Hotel::SaveCustomers() {
	ofstream outf;
	outf.open("customers.txt", ios::trunc);
	if (!outf) { // If can't open
		cout << "customers.txt can't open" << endl;
		abort(); // Exit
	}
	else {
		for (unsigned int i = 0; i < customers.size(); i++) {
			outf << customers[i].name << "," << customers[i].age << "," << customers[i].gender << ","
				<< customers[i].ID_card_num << "," << customers[i].Balance << "," << customers[i].days << ","
				<< customers[i].FloorNum << "," << customers[i].RoomType << "," << customers[i].RoomNum << ","
				<< customers[i].CheckinTime << "," << customers[i].CheckinDate << "," << customers[i].CheckoutTime << ","
				<< customers[i].CheckoutDate << "," << customers[i].TimeRemaining << endl;
		}
		outf.close();
	}
}
void Hotel::LoadRooms() {
	string str;
	ifstream fin("rooms.txt"); // Open and read rooms.txt
	if (!fin) { // If can't open
		cout << "rooms.txt does not exist." << endl;
		cout << "Creating file..." << endl;
		Sleep(1000);
		ofstream wfile;
		wfile.open("rooms.txt", ios::trunc);//create new file
		wfile.close();
	}
	else{
		try {
			fin.seekg(0,ios::end);
			unsigned long int file_size = fin.tellg();
			fin.seekg(0,ios::beg);
			if(file_size  == 0)
			{
			 cout << "rooms.txt File is empty!"<<endl;
			 Sleep(1000);
			}
			else
				rooms.clear();
			int floorN, roomN, fare; char type[20], allotedN[100]; bool status;
			while (getline(fin, str)) {
				unsigned int i = str.find(",");
				floorN = stoi(str.substr(0, i));
				str = str.substr(i + 1);
	
				i = str.find(",");
				roomN = stoi(str.substr(0, i));
				str = str.substr(i + 1);
	
				i = str.find(",");
				strcpy(type, str.substr(0, i).c_str());
				str = str.substr(i + 1);
	
				i = str.find(",");
				fare = stoi(str.substr(0, i));
				str = str.substr(i + 1);
	
				i = str.find(",");
				status = stoi(str.substr(0, i));
				strcpy(allotedN, str.substr(i + 1).c_str());
				if (string(type) == "Standard") {
					rooms.push_back(new Standard(floorN,roomN,status, allotedN));
				}
				else if (string(type) == "Moderate") {
					rooms.push_back(new Moderate(floorN,roomN,status, allotedN));
				}
				else if (string(type) == "Superior") {
					rooms.push_back(new Superior(floorN,roomN,status, allotedN));
				}
				else if (string(type) == "JuniorSuite") {
					rooms.push_back(new JuniorSuite(floorN,roomN,status, allotedN));
				}
				else if (string(type) == "Suite") {
					rooms.push_back(new Suite(floorN,roomN,status, allotedN));
				}
			}
		}
		catch (...) {
			cout << "rooms.txt File  is Empty!"<<endl;
			Sleep(1000);
		}
		fin.close();	
	}
}
void Hotel::LoadCustomers() {
	Customer customer;
	string str;
	ifstream fin("customers.txt"); // Open and read customers.txt
	if (!fin) { // If can't open 
		ofstream wfile;
		cout << "customers.txt does not exist." << endl;
		cout << "Creating file..." << endl;
		Sleep(1000);
		wfile.open("customers.txt", ios::trunc);//Create new file
		wfile.close();
	}
	else{
		try {
		while (getline(fin, str)) {
			unsigned int i = str.find(",");
			strcpy(customer.name, str.substr(0, i).c_str());
			str = str.substr(i + 1);

			i = str.find(",");
			customer.age = stoi(str.substr(0, i));
			str = str.substr(i + 1);

			i = str.find(",");
			strcpy(customer.gender, str.substr(0, i).c_str());
			str = str.substr(i + 1);

			i = str.find(",");
			customer.ID_card_num = stoi(str.substr(0, i));
			str = str.substr(i + 1);

			i = str.find(",");
			customer.Balance = stoi(str.substr(0, i));
			str = str.substr(i + 1);

			i = str.find(",");
			customer.days = stoi(str.substr(0, i));
			str = str.substr(i + 1);

			i = str.find(",");
			customer.FloorNum = stoi(str.substr(0, i));
			str = str.substr(i + 1);

			i = str.find(",");
			strcpy(customer.RoomType, str.substr(0, i).c_str());
			str = str.substr(i + 1);


			i = str.find(",");
			customer.RoomNum = stoi(str.substr(0, i));
			str = str.substr(i + 1);

			i = str.find(",");
			strcpy(customer.CheckinTime, str.substr(0, i).c_str());
			str = str.substr(i + 1);

			i = str.find(",");
			strcpy(customer.CheckinDate, str.substr(0, i).c_str());
			str = str.substr(i + 1);

			i = str.find(",");
			strcpy(customer.CheckoutTime, str.substr(0, i).c_str());
			str = str.substr(i + 1);

			i = str.find(",");
			strcpy(customer.CheckoutDate, str.substr(0, i).c_str());
			strcpy(customer.TimeRemaining, str.substr(i + 1).c_str());

			customers.push_back(customer);
		}
	}
	catch (...) {
		cout << "customer.txt File is Empty!"<<endl;
		Sleep(1000);
	}
	fin.close();
	}
}
void Hotel::main_menu() {
	int option = 0;
	while (option != 5)
	{
		system("CLS");
		cout << "\t\t\t[\t-----Hotel Management System------\t]\t\t\t\n";
		cout << "\t\t\t\t1 - Press 1 to Reserve a room\t\t\t\t\n";
		cout << "\t\t\t\t2 - Press 2 to Checkin/Checkout a customer/visitor\t\t\t\t\n";
		cout << "\t\t\t\t3 - Press 3 to View Reserved Rooms\t\t\t\t\n";
		cout << "\t\t\t\t4 - Press 4 to See Detail Report\t\t\t\t\n";
		cout << "\t\t\t\t5 - Press 5 to exit\t\t\t\t\n";
		cout << "Enter Option: ";
		cin >> option;
		switch (option) {
		case 1:
			ReserveRoom();
			break;
		case 2:
			CheckinCustomer();
			break;
		case 3:
			ViewReservedRooms();
			break;
		case 4:
			DetailedReport();
			break;
		default:
			cout << "Press Any key to Continue...!";
			getch();
		}
	}
	system("CLS");
	cout << "\n\t\tClosing Program..." << endl;
	Sleep(1000);
}
void Hotel::ReserveRoom() {
	unsigned int i;
	system("CLS");
	cout << "1 => Reserve Room" << endl;
	cout << "2 => Reset Rooms Record" << endl;
	int ch; cout << "->"; cin >> ch;
	if (ch == 2)
	{
		for (i = 0; i < total_rooms; i++)
		{
			rooms[i]->reset();
		}
		cout << "Reset successful!" << endl;
	}
	else
	{
		bool flag = 1;
		int floor;
		cout << "-Enter Floor Number(1 - 5): ";
		cin >> floor;
		if (floor == 1) {
			cout << "\t1. Standard(1 - 10)" << endl;
			cout << "\t2. Moderate(51 - 60)" << endl;
			cout << "\t3. Superior(101 - 110)" << endl;
			cout << "\t4. Junior Suite(151 - 160)" << endl;
			cout << "\t5. Suite(201 - 210)" << endl;
		}
		if (floor == 2) {
			cout << "\t1. Standard(11 - 20)" << endl;
			cout << "\t2. Moderate(61 - 70)" << endl;
			cout << "\t3. Superior(111 - 120)" << endl;
			cout << "\t4. Junior Suite(161 - 170)" << endl;
			cout << "\t5. Suite(211 - 220)" << endl;
		}
		if (floor == 3) {
			cout << "\t1. Standard(21 - 30)" << endl;
			cout << "\t2. Moderate(71 - 80)" << endl;
			cout << "\t3. Superior(121 - 130)" << endl;
			cout << "\t4. Junior Suite(171 - 180)" << endl;
			cout << "\t5. Suite(221 - 230)" << endl;
		}
		if (floor == 4) {
			cout << "\t1. Standard(31 - 40)" << endl;
			cout << "\t2. Moderate(81 - 90)" << endl;
			cout << "\t3. Superior(131 - 140)" << endl;
			cout << "\t4. Junior Suite(181 - 190)" << endl;
			cout << "\t5. Suite(231 - 240)" << endl;
		}
		if (floor == 5) {
			cout << "\t1. Standard(41 - 50)" << endl;
			cout << "\t2. Moderate(91 - 100)" << endl;
			cout << "\t3. Superior(141 - 150)" << endl;
			cout << "\t4. Junior Suite(191 - 200)" << endl;
			cout << "\t5. Suite(241 - 250)" << endl;
		}
		cout << "-Enter Room Type:";
		int type;
		cin >> type;
		int room_num;
		cout << "-Enter Room Number: ";
		if (type == 1)
		{
			cin >> room_num;
			for (i = 0; i < rooms.size(); i++) {
				Standard* standard = dynamic_cast<Standard*>(rooms[i]);
				if (standard != 0) {
					if (room_num == standard->roomNum && standard->status == 0) {
						cout << "Press Enter to Continue..." << endl;
						getch();
						flag = 0;
						break;
					}
				}
			}
		}
		else if (type == 2)
		{
			cin >> room_num;
			for (i = 0; i < rooms.size(); i++) {
				Moderate* moderate = dynamic_cast<Moderate*>(rooms[i]);
				if (moderate != 0) {
					if(room_num == moderate->roomNum && moderate->status == 0){
						cout << "Press Enter to Continue..." << endl;
						getch();
						flag = 0;
						break;
					}
				}
			}
		}
		else if (type == 3)
		{
			cin >> room_num;
			for (i = 0; i < rooms.size(); i++) {
				Superior* superior = dynamic_cast<Superior*>(rooms[i]);
				if (superior != 0) {
					if (room_num == superior->roomNum && superior->status == 0) {
						cout << "Press Enter to Continue..." << endl;
						getch();
						flag = 0;
						break;
					}
				}
			}
		}
		else if (type == 4)
		{
			cin >> room_num;
			for (i = 0; i < rooms.size(); i++) {
				JuniorSuite* junior_Suite = dynamic_cast<JuniorSuite*>(rooms[i]);
				if (junior_Suite != 0) {
					if (room_num == junior_Suite->roomNum && junior_Suite->status == 0) {
						cout << "Press Enter to Continue..." << endl;
						getch();
						flag = 0;
						break;
					}
				}
			}
		}
		else if (type == 5)
		{
			cin >> room_num;
			for (i = 0; i < rooms.size(); i++) {
				Suite* suite = dynamic_cast<Suite*>(rooms[i]);
				if (suite != 0) {
					if (room_num == suite->roomNum && suite->status == 0) {
						cout << "Press Enter to Continue..." << endl;
						getch();
						flag = 0;
						break;
					}
				}
			}
		}
		else {
			cout << "Invalid!" << endl;
			getch();
			ReserveRoom();
		}
		if (flag)
		{
			cout << "Room Already Reserved!" << endl;
			cout << "Press Enter to Continue..." << endl;
			getch();
			ReserveRoom();
		}
		else{
			//Customer Record Entry
			char n_o;
			cout << "Are You an Old or New Cutomer(N/O):";
			cin >> n_o;
			if (n_o == 'N') {
				Customer cus;
				cus.getData();
				cout << "Paid In Advance or No (Y/N): ";
				char c; cin >> c;
				(c == 'Y') ? cus.Balance = 0 : cus.Balance = rooms[i]->fare * cus.days;
				strcpy(rooms[i]->allotedName, cus.name);
				cus.FloorNum = rooms[i]->floor_num;
				strcpy(cus.RoomType, rooms[i]->type);
				cus.RoomNum = rooms[i]->roomNum;
				rooms[i]->status = 1;
				cout << "Room Reserved!" << endl;
				customers.push_back(cus);
				cin.ignore();
			}
			else if(n_o == 'O') {
				unsigned int k;
				char name[100];
				cin.ignore();
				cout << "Please Enter Your Name: ";
				cin.getline(name, sizeof(name));
				cout << "Searching..." << endl;
				bool flg = 0;
				for (k = 0; k < customers.size(); k++) {
					if (string(customers[k].name) == name) {
						Sleep(1000);
						cout << "Found!" << endl;
						cout << "--Press Enter to continue..." << endl;
						flg = 1;
						getch();
						break;
					}
				}
				if (flg) {
					cout << "Paid In Advance or No (Y/N): ";
					char c; cin >> c;
					(c == 'Y') ? customers[k].Balance = 0 : customers[k].Balance = rooms[i]->fare * customers[k].days;
					strcpy(rooms[i]->allotedName, customers[k].name);
					customers[k].FloorNum = rooms[i]->floor_num;
					strcpy(customers[k].RoomType, rooms[i]->type);
					customers[k].RoomNum = rooms[i]->roomNum;
					rooms[i]->status = 1;
					cout << "Room Reserved!" << endl;
				}
				else {
					cout << "Not Found!" << endl;
					getch();
					ReserveRoom();
				}
			}
		}
	}
	getch();
}

void Hotel::CheckinCustomer() {
	system("CLS");
	cout << "1 =>Check-In Customer." << endl;
	cout << "2 =>Check-Out Customer." << endl;
	cout << "3 =>Clear Customers Record." << endl;
	int select; cout << "->"; cin >> select;
	if (select == 2) {
		char name[100];
		cin.ignore();
		cout << "Please Enter Customer's' Name: ";
		cin.getline(name, sizeof(name));
		cout << "Searching..." << endl;
		bool flag = 0;
		unsigned int k;
		for (k = 0; k < customers.size(); k++) {
			if (string(customers[k].name) == name) {
				Sleep(1000);
				cout << "Found!" << endl;
				cout << "\tFloor Number: " << customers[k].FloorNum << endl;
				cout << "\tRoom Number: " << customers[k].RoomNum << endl;
				cout << "\tRoom Type: " << customers[k].RoomType << endl;
				cout << "\tBalance: " << customers[k].Balance << endl;
				cout << "--Press Enter to continue..." << endl;
				flag = 1;
				getch();
				break;
			}
		}
		if (flag)
		{
			for (unsigned int i = 0; i < rooms.size(); i++) {
				if (customers[k].RoomNum == rooms[i]->roomNum && rooms[i]->status == 1) {
					rooms[i]->status = 0;
					strcpy(rooms[i]->allotedName, "Empty");
				}
			}
			cout << "Enter Check-Out Time(hours:minutes): ";
			cin.getline(customers[k].CheckoutTime, sizeof(customers[k].CheckoutTime));
			cout << "Enter Check-Out Date(MM/DD/YY): ";
			cin.getline(customers[k].CheckoutDate, sizeof(customers[k].CheckoutDate));
			//customers.erase(customers.begin()+k);
			cout << "Processing..." << endl;
			checkout_counter++;
			Sleep(1000);
			cout << "Check-out successful!" << endl;
		}
		else {
			cout << "Not Found..." << "You have Not reserved a Room!..." << endl;
			cout << "Press Enter to Reserve!" << endl;
			getch();
			ReserveRoom();
		}

	}
	else if(select == 3) {
		customers.clear();
		cout << "Reset successful!" << endl;
	}
	else {
		cout << "Room Already Reserved?(Y/N): ";
		char ch; cout << "->"; cin >> ch;
		if (ch == 'Y')
		{
			char name[100];
			cin.ignore();
			cout << "Please Enter Customer's' Name: ";
			cin.getline(name, sizeof(name));
			cout << "Searching..." << endl;
			bool flag = 0;
			unsigned int k;
			for (k = 0; k < customers.size(); k++) {
				if (string(customers[k].name) == name) {
					Sleep(1000);
					cout << "Found!" << endl;
					cout << "\tFloor Number: " << customers[k].FloorNum << endl;
					cout << "\tRoom Number: " << customers[k].RoomNum << endl;
					cout << "\tRoom Type: " << customers[k].RoomType << endl;
					cout << "\tBalance: " << customers[k].Balance << endl;
					cout << "--Press Enter to continue..." << endl;
					flag = 1;
					getch();
					break;
				}
			}
			if (flag)
			{
				cin.ignore();
				cout << "Enter Check-in Time(hours:minutes): ";
				cin.getline(customers[k].CheckinTime, sizeof(customers[k].CheckinTime));
				cout << "Enter Check-in Date(MM/DD/YY): ";
				cin.getline(customers[k].CheckinDate, sizeof(customers[k].CheckinDate));
				cout << "Processing..." << endl;
				customer_counter++;
				Sleep(1000);
				cout << "Checked-In successful!" << endl;
			}
			else {
				cout << "Not Found..." << "You have Not reserved a Room!..." << endl;
				cout << "Press Enter to Reserve!" << endl;
				getch();
				ReserveRoom();
			}
		}
		else
		{
			cout << "Please Press Enter to Reserve a Room!";
			getch();
			ReserveRoom();
		}
	}
	getch();
}
void Hotel::ViewReservedRooms() {
	system("CLS");
	cout << "\n\t\t\tReserved Rooms\t\t\t" << endl;
	for (unsigned int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->status == 1)
		{
			cout << "**------------------------**\n";
			cout << "Room Type: " << rooms[i]->type << endl;
			cout << "Room Floor: " << rooms[i]->floor_num << endl;
			cout << "Room Number: " << rooms[i]->roomNum << endl;
			cout << "Fare: " << rooms[i]->fare << endl;
			cout << "Allocated To: " << rooms[i]->allotedName << endl;
		}
	}
	cout << "Press Enter to Continue...";
	getch();
}
void Hotel::DetailedReport() {
	system("CLS");
	int c_s = 0, c_m = 0, c_su = 0, c_j = 0, c_sui = 0; char date[20];
	int checkIn_counter=0, checkOut_counter=0;
	cout << "=> Number of Rooms Reserved and Types" << endl;
	for (unsigned int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->status == 1 && string(rooms[i]->type) == "Standard") {
			c_s++;
		}
		if (rooms[i]->status == 1 && string(rooms[i]->type) == "Moderate") {
			c_m++;
		}
		if (rooms[i]->status == 1 && string(rooms[i]->type) == "Superior") {
			c_su++;
		}
		if (rooms[i]->status == 1 && string(rooms[i]->type) == "JuniorSuite") {
			c_j++;
		}
		if (rooms[i]->status == 1 && string(rooms[i]->type) == "Suite") {
			c_sui++;
		}
	}
	cout << "\tStandard :    " << c_s << endl;
	cout << "\tModerate :    " << c_m << endl;
	cout << "\tSuperior :    " << c_su << endl;
	cout << "\tJuniorSuite : " << c_j << endl;
	cout << "\tSuite :       " << c_sui << endl;

	//Empty room check
	int emp = 0;
	for (unsigned int i = 0; i < rooms.size(); i++) {
		if (rooms[i]->status == 0) {
			emp++;
		}
	}
	cout << "=> Empty Rooms: " << emp << endl;
	cout<<"-Enter Particular Date of Record(MM/DD/YY): ";
	cin.ignore();
	cin.getline(date, sizeof(date));
	for(unsigned int i=0;i<customers.size();i++){
		if(date == string(customers[i].CheckinDate)){
			checkIn_counter++;
		}
		if(date == string(customers[i].CheckoutDate)){
			checkOut_counter++;
		}
	}
	cout<<"=> Customers Checked-In: "<<checkIn_counter<<endl;
	cout<<"=> Customers Checked-Out: "<<checkOut_counter<<endl;
	getch();
}

//Main
int main() {
	Hotel* hotel = new Hotel;
	hotel->main_menu();
	delete hotel;
	return 0;
}
