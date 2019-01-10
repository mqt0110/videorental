#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <iostream>
#include "Video.h"

class Transaction: public Video
{
    int _day, _month, _year;  //DUE DATE
    Transaction *_nextTransaction;

    public:
        Transaction(){
            _nextTransaction=NULL;
        }
        Transaction(Video* &Video, int day, int month , int year){
            _videoCode=Video->get_Video_Code();
            _yearCompleted=Video->get_Year_Completed();
            _title=Video->get_Title();
            _author=Video->get_Author();
            _type=Video->get_Type();
            _country=Video->get_Country();
            _available= false;
            _day=day;
            _month=month;
            _year=year;
            _next=NULL;
            _nextTransaction=NULL;
        }
        void set_Due_Date(int day, int month , int year){
          _day=day;
          _month=month;
          _year=year;
        }
        virtual ~Transaction(){

        }
        int get_Day() const{
            return _day;
        }
        int get_Month() const{
            return _month;
        }
        int get_Year() const{
            return _year;
        }
        Transaction* get_Next_Transaction() const{
            return _nextTransaction;
        }
        void set_Next_Transaction(Transaction* newTransaction){
            _nextTransaction= newTransaction;
        }




};

#endif // TRANSACTION_H_INCLUDED
