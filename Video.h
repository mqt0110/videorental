#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED

#include<iostream>
#include <string>
#include <iomanip>
using namespace std;

class Video
{
    protected:
        int _videoCode, _yearCompleted;
        bool _available;
        string _title, _author,_type,_country;
        Video *_next;

    public:
        Video(){
        }
        Video(int videoCode,int yearCompleted,string title, string author, string type, string country){
            _videoCode=videoCode;
            _title=title;
            _author=author;
            _type=type;
            _country=country;
            _yearCompleted=yearCompleted;
            _available=true;
            _next=NULL;
        }
        virtual ~Video(){
        }
        int get_Video_Code() const{
            return _videoCode;
        }
        int get_Year_Completed() const{
            return _yearCompleted;
        }
        bool get_Available() const{
            return _available;
        }
        string get_Title() const{
            return _title;
        }
        string get_Author() const{
            return _author;
        }
        string get_Country() const{
            return _country;
        }
        string get_Type() const{
            return _type;
        }
        Video* get_Next() const{
            return _next;
        }
        void set_Available(bool available){
            _available=available;
        }
        void set_Next(Video * new_Video){
            _next=new_Video;
        }
        void print() {      //PRINT VIDEO INFORMATION

        cout<< setw(12) << left << "Code"
            << setw(24) << left << "Title"
            << setw(24) << left << "Author"
            << setw(16) << left << "Type"
            << setw(16) << left << "Country"
            << setw(16) << left << "Year Completed"
              << "Available" << endl;
        cout<< setw(12) << left <<_videoCode
            << setw(24) << left <<_title
            << setw(24) << left <<_author
            << setw(16) << left <<_type
            << setw(16) << left <<_country
            << setw(16) << left << _yearCompleted
              << _available << endl;
        }
};

#endif // VIDEO_H_INCLUDED
