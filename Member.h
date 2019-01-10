#ifndef MEMBER_H_INCLUDED
#define MEMBER_H_INCLUDED

#include <iostream>
#include <string.h>
#include "Transaction.h"
#include <iomanip>

using namespace std;
class Member
{
    int _memCode;
    string _name, _phone, _address;
    Member *_next;
    Transaction *head;

    public:
        Member(int memCode, string name, string phone, string address){
            _memCode=memCode;
            _name=name;
            _phone=phone;
            _address=address;
            _next=NULL;
            head=NULL;
        }
        virtual ~Member(){
        }
        int get_Mem_Code() const{
                return _memCode;
            }
        string get_Name() const{
                return _name;
            }
        string get_Phone() const{
            return _phone;
        }
        string get_Address()const{
            return _address;
        }
        Member* get_Next() const{
            return _next;
        }
        void set_Next(Member* newMember){
            _next=newMember;
        }
        int add_Transaction(Video* &video, int day , int month , int year){  // add information of video , and due date
            Transaction *p = new Transaction(video,day,month,year);
            Transaction *i, *j;
            if(!head)
               {
                    head=p;
                    return 1;
               }
            else if((video->get_Video_Code())<(head->get_Video_Code())){  // if the code is smaller then the head, add into first place , take head to second
                    p->set_Next_Transaction(head);
                    head=p;
                    return 1;
                }
                else{
                for(i=j=head;i;i=i->get_Next_Transaction()){
                    if ((i->get_Video_Code())==(video->get_Video_Code())){
                    i->set_Due_Date(day,month,year);
                    return 1;
                }else if((video->get_Video_Code()< i->get_Video_Code() )&& (video->get_Video_Code() >(j->get_Video_Code()))){
                    p->set_Next_Transaction(i);
                    j->set_Next_Transaction(p);
                    return 1;
                }else if (!(i->get_Next_Transaction())){
                i->set_Next_Transaction(p);
                return 1;
                }
                j=i;
            }
            return 0;
        }
}
        void print() {              //PRINT MEMBER INFORMATION
    cout << setw(16) << left << "Member Code"
              << setw(24) << left << "Name"
              << setw(24) << left << "Phone"
              << "Address" << endl;

    cout << setw(16) << std::left << _memCode
              << setw(24) << left << _name
              << setw(24) << left << _phone
              << _address << endl;

    cout << "\n\t\tTransaction" << endl;
    cout << setw(12) << left << "Video Code"
              << setw(24) << left << "Title"
              << setw(24) << left << "Author"
              << setw(16) << left << "Year Competed"
              << "Due date (dd/mm/yyyy)" <<endl;
    Transaction *i;

    for(i = head; i; i = i->get_Next_Transaction())
        cout << setw(12) << left << i->get_Video_Code()
                  << setw(24) << left << i->get_Title()
                  << setw(24) << left << i->get_Author()
                  << setw(16) << left << i->get_Year_Completed()
                  << i->get_Day() << "/" << i->get_Month() << "/" << i->get_Year() << endl;
}
        int return_Transaction(int videoCode){
            Transaction *j, *i;
            for (i = j = head; i; i = i->get_Next_Transaction()){
        if (i->get_Video_Code() == videoCode){
            if (i == head){
                head = head->get_Next_Transaction();
                delete i;
                return 1;
            }else{
                j->set_Next(i->get_Next_Transaction());
                delete i;
                return 1;
            }
       }
       j = i;
    }
    return 0;
}
        Transaction *get_Transaction_List(){
            return head;
        }
    void set_Mem_Info(string name, string phone, string address){ //MODIFY MEMBER'S INFORMATION
        _name=name;
        _phone=phone;
        _address=address;
}

};

#endif // MEMBER_H_INCLUDED
