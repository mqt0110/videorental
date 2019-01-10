#ifndef MANAGEMENT_H_INCLUDED
#define MANAGEMENT_H_INCLUDED


#include "Video_List.h"
#include "Member_List.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

using namespace std;

void clearScreen()
{
	cout << string(50, '\n');
}

class Management : public Video_List, public Member_List
{
    Member_List *ListMem;
    Video_List *ListVideo;
public:
    Management(){
    }
   virtual ~Management(){
    }
	void introduction(){
	clearScreen();

	cout << "**VIDEO RENTAL MANAGEMENT**\n" << endl;
	cout << "1. ADD NEW VIDEO" << endl;
	cout << "2. ADD NEW MEMBER" << endl;
	cout << "3. ISSUE VIDEO" << endl;
	cout << "4. RETURN VIDEO" << endl;
	cout << "5. LIST OF VIDEO" << endl;
	cout << "6. LIST OF MEMBER" << endl;
	cout << "7. EDIT VIDEO" << endl;
	cout << "8. EDIT MEMBER" << endl;
	cout << "0. QUIT" << endl;
}
	void add_New_Video(){
	clearScreen();

	int videoCode, yearCompleted;
	string title,author,type,country;

	cout << "Video code: ";
	cin >> videoCode;

	cout << "Title: ";
    cin.ignore();
	getline(cin, title);
	cout << "Author: ";
	getline(cin, author);
	cout << "Type: ";
	getline(cin, type);
	cout << "Country: ";
	getline(cin, country);
    cout << "Year completed: ";
	cin >> yearCompleted;

	if (Video_List::add_Video(videoCode,yearCompleted,title,author,type,country))
		cout << "\nAdd video successfully." <<endl;
	else
		cout << "\nAdd video unsuccessfully." << endl;

	cout << "\n\nPress ENTER to continue..."<<std::flush;
    cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void add_New_Mem(){
	clearScreen();

	int memCode;
	string name,phone,address;

	cout << "Member code: ";
	cin >> memCode;
	cout << "Name: ";
	cin.ignore();
	getline(cin,name);
	cout << "Phone:";
	getline(cin,phone);
	cout << "Address: ";
	getline(cin,address);

	if (Member_List::add_Member(memCode, name, phone, address))
		cout << "\nAdd member successfully." <<endl;
	else
		cout << "\nAdd member unsuccessfully." << endl;

	cout << "\n\nPress ENTER to continue...";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void issue_Video(){
	clearScreen();

	int videoCode, memCode, day, month, year;

	cout << "Video code: ";
	cin >> videoCode;
	cout << "Member code: ";
	cin >> memCode;
	cout << "\nDue date\n";
	cout << "Day: ";
	cin >> day;
	cout << "Month: ";
	cin >> month;
	cout << "Year: ";
	cin >> year;
    cin.ignore();

	if ((check_Video_Code(videoCode))){
		if (add_Transaction(memCode, check_Video_Code(videoCode), day, month, year)){
			set_Available(videoCode, false);
			cout << "\nIssue video successfully." << endl;
		}else
			cout << "\nIssue video unsuccessfully." << endl;
	}else
		cout << "\nIssue book unsuccessfully." << endl;

	cout << "\n\nPress ENTER to continue...";

	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void return_Video(){
	clearScreen();

	int videoCode, memCode;

	cout << "Video code: ";
	cin >> videoCode;
	cout << "Member code: ";
	cin >> memCode;

	if ((check_Video_Code(videoCode)) && (check_Mem_Code(memCode))) {
        (check_Mem_Code(memCode))->return_Transaction(videoCode);
        set_Available(videoCode, true);

		cout << "\nReturn video successfully." << endl;
	}else
		cout << "\nReturn video unsuccessfully." << endl;

	cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void print_Video_List() {
	clearScreen();
	Video_List::print();
	cout << "\n\nPress ENTER to continue...";
    cin.ignore();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void print_Mem_List() {
	clearScreen();
	Member_List::print();

	cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void print_Video_Info(){
	clearScreen();

	int videoCode;
	Video *video;

	cout << "Video code: ";
	cin >> videoCode;

	if ((video = check_Video_Code(videoCode)))
		video->print();
	else
		cout << "WRONG VIDEO CODE." << endl;

	cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void print_Mem_Info(){
	clearScreen();

	int memCode;

	cout << "Member code: ";
	cin >> memCode;

	if (check_Mem_Code(memCode))
		Member_List::print_Mem_Info(memCode);
	else
		cout << "WRONG MEMBER CODE." << endl;

	cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void modify_Video(){
	clearScreen();

	int videoCode, yearCompleted;
	string title, author,type,country;

	cout << "Video code: ";
	cin >> videoCode;
	cout << "Year completed: ";
	cin >> yearCompleted;
	cout << "Title: ";
    cin.ignore();
	getline(cin, title);
	cout << "Author: ";
	cin.ignore();
    getline(cin, author);
	cout << "Type: ";
	cin.ignore();
	getline(cin, type);
	cout << "Country Completed: ";
	cin.ignore();
	getline(cin, country);



	if (Video_List::modify_Video(videoCode,yearCompleted,title,author,type,country))
		cout << "\nEdit video successfully." << endl;
	else
		cout << "\nEdit video unsuccessfully." << endl;

	cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void modify_Member(){
	clearScreen();

	int memCode;
	string name, phone, address;

	cout << "Member code: ";
    cin >> memCode;
	cout << "Name: ";
	cin.ignore();
	getline(cin,name);
	cout << "Phone: ";
    cin.ignore();
	getline(cin,phone);
	cout << "Address: ";
    cin.ignore();
	getline(cin,address);

	if (Member_List::modify_Member(memCode,name,phone,address))
		cout << "\nEdit member successfully." << endl;
	else
		cout << "\nEdit member unsuccessfully." << endl;

	cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void delete_Video(){
	clearScreen();

	int videoCode;

	cout << "Video code: ";
	cin >> videoCode;

	if (Video_List::remove_Video(videoCode))
		cout << "\nRemove video successfully." << endl;
	else
		cout << "\nRemove video unsuccessfully." << endl;

    cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void delete_Member(){
	clearScreen();

	int memCode;

	cout << "Member code: ";
	cin >> memCode;

	if (Member_List::remove_Member(memCode))
		cout << "\nRemove member successfully." << endl;
	else
		cout << "\nRemove member unsuccessfully." << endl;

	cout << "\n\nPress ENTER to continue...";
	cin.ignore();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
	void edit_Video_Menu(){
	clearScreen();

	cout << "**EDIT VIDEO**\n" << endl;
	cout << "1. PRINT VIDEO INFORMATION" << endl;
	cout << "2. MODIFY VIDEO INFORMATION" << endl;
	cout << "3. DELETE VIDEO" << endl;
	cout << "0. BACK" << endl;
}
	void edit_Mem_Menu(){
	clearScreen();

	cout << "**EDIT MEMBER**\n" << endl;
	cout << "1. PRINT MEMBER INFORMATION" << endl;
	cout << "2. MODIFY MEMBER INFORMATION" <<endl;
	cout << "3. DELETE MEMBER" << endl;
	cout << "0. BACK" << endl;
}

};

#endif // MANAGEMENT_H_INCLUDED
