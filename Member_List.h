#ifndef MEMBER_LIST_H_INCLUDED
#define MEMBER_LIST_H_INCLUDED

#include "Member.h"
using namespace std;

class Member_List
{
	Member *head;

public:
	Member_List(){
	    head=NULL;
	}
	virtual ~Member_List(){
    Member *i = head;
    while (i){
        i = i->get_Next();
        delete head;
        head = i;
    }
}
	int add_Member(int memCode, string name, string phone,string address){		//IF MEMBER CODE EXISTED, DO NOT ADD

    Member *m = new Member(memCode, name, phone, address);
    Member *i, *j;
    if (head == NULL){
        head = m;
        return 1;
    }else if ( memCode < head->get_Mem_Code()){
        m->set_Next(head);
        head = m;
        return 1;
    }else{
        for (i = j = head; i; i = i->get_Next()){
            if (memCode == i->get_Mem_Code())
                return 0;

            else if ((memCode < i->get_Mem_Code() && memCode > (j->get_Mem_Code())) ){
                 m->set_Next(i);
                 j->set_Next(m);
                 return 1;
            }else if (!i->get_Next()){
                 i->set_Next(m);
                 return 1;
            }
            j = i;
        }
    }
    return 0;
}
	int remove_Member(int memCode){		// REMOVE MEMBER IF MEMCODE EXISTED, RETURN 1; ELSE RETURN 0

    Member *j, *i;
    for (i = j = head; i; i = i->get_Next()){
        if (i->get_Mem_Code() == memCode){
            if(! i->get_Transaction_List()){
                if (i == head){
                    head = head->get_Next();
                    delete i;
                    return 1;
                }else{
                    j->set_Next(i->get_Next());
                    delete i;
                    return 1;
                }
            }else
                return 0;
        }
       j = i;
    }
    return 0;
}
	void print(){       //PRINT THE LIST OF MEMBERS

    Member *i;
    cout << setw(16) << left << "Member Code"
              << setw(24) << left << "Name"
              << setw(24) << left << "Phone"
              << "Address" << endl;

    for (i = head; i; i = i->get_Next())
    cout << setw(16) << left << i->get_Mem_Code()
                  << setw(24) << left << i->get_Name()
                  << setw(24) << left << i->get_Phone()
                  << i->get_Address() << endl;
}
	int modify_Member(int memCode, string name, string phone, string address){		//IF MEMCODE EXISTED, MODIFY MEMBER'S INFORMATION, RETURN 1; ELSE RETURN 0

	    if (!head){
                head= new Member(memCode,name,phone,address);
                return 0;
	    }

    Member *i;
    for (i = head; i; i = i->get_Next())
        if (i->get_Mem_Code() == memCode){
            i->set_Mem_Info(name, phone, address);
            return 1;
        }

    return 0;
	}
	int add_Transaction(int memCode, Video* Video, int day, int month , int year){		//ADD  TRANSACTION AND IF VIDEO IS IN LOAN, CHANGE DUE DATE -> RETURN 1; ELSE RETURN 0

    Member *i;
    for (i = head; i; i = i->get_Next()){
        if (memCode == i->get_Mem_Code()){
            i->add_Transaction(Video, day, month, year);
            return 1;
        }
    }
    return 0;
}
	void print_Mem_Info(int memCode){		//PRINT ALL INFORMATION OF CHOSEN MEMBER
        Member *i;
        for (i = head; i; i = i->get_Next())
        if(memCode == i->get_Mem_Code()){
            i->print();
            return;
        }
	}
	Member* check_Mem_Code(int memCode){		//IF MEMCODE EXISTED, RETURN MEMBER*; ELSE RETURN NULL

    Member *i;
    for (i = head; i; i = i->get_Next())
        if(memCode == i->get_Mem_Code())
            return i;

    return NULL;
}
};
#endif // MEMBER_LIST_H_INCLUDED
