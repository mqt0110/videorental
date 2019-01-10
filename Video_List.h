#ifndef VIDEO_LIST_H_INCLUDED
#define VIDEO_LIST_H_INCLUDED

#include "Video.h"
#include <iomanip>

using namespace std;
class Video_List
{
	Video *head;

protected:
	Video_List(){
	    head=NULL;
	}
	virtual ~Video_List(){
	     Video *i=head;
	     while(i){
            i=i->get_Next();
            delete head;
            head = i;
         }
	}
	int add_Video(int videoCode, int yearCompleted, string title, string author, string type, string country ){		//IF CODE EXISTED, DO NOT ADD

    Video*p = new Video(videoCode,yearCompleted,title,author,type,country);
    Video *i, *j;
    if (head == NULL){
        head = p;
        return 1;
    }
    else if (videoCode < head->get_Video_Code()){
        p->set_Next(head);
        head = p;
        return 1;
    }else{
        for (i = j = head; i; i = i->get_Next()){
            if (i->get_Video_Code() == videoCode)
                return 0;
            else if ((videoCode < i->get_Video_Code() && videoCode > (j->get_Video_Code())) ){
                 p->set_Next(i);
                 j->set_Next(p);
                 return 1;
            }else if (!i->get_Next()){
                 i->set_Next(p);
                 return 1;
            }
            j = i;
        }
    }


return 0;
}
	int remove_Video(int videoCode){		// REMOVE VIDEO IF CODE EXISTES, REUTRN 1; ELSE RETURN 0

    Video*j, *i;
    for (i = j = head; i; i = i->get_Next()){
        if (i->get_Video_Code() == videoCode){
            if (i->get_Available()){
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
	void print(){       //PRINT THE LIST OF VIDEOS

    Video *i;

        cout<<std::setw(12) << left << "Code"
            <<std::setw(24) << left << "Title"
            <<std::setw(24) << left << "Author"
            <<std::setw(16) << left << "Type"
            <<std::setw(16) << left << "Country"
            <<std::setw(16) << left << "Year Completed"
              << "Available" << endl;
    for(i=head;i;i=i->get_Next())
        cout<<std::setw(12) << left << i->get_Video_Code()
            <<std::setw(24) << left << i->get_Title()
            <<std::setw(24) << left << i->get_Author()
            <<std::setw(16) << left << i->get_Type()
            <<std::setw(16) << left << i->get_Country()
            <<std::setw(16) << left << i->get_Year_Completed()
              << i->get_Available() << endl;


}
	int modify_Video(int videoCode, int yearCompleted, string title, string author, string type, string country ){		//IF  VIDEOCODE EXISTED, MODIFY VIDEO'S INFORMATION, RETURN 1; ELSE RETURN 0

     Video *p = new Video(videoCode,yearCompleted, title, author,type,country );
    if (!head){
        head = p;
        return 1;
    }
    Video *i, *j;
    for (i = j = head; i; i = i->get_Next()){
        if (i->get_Video_Code() == videoCode){
            if (i == head){
                p->set_Next(head->get_Next());
                head = p;
                delete i;
                return 1;
            }else{
                p->set_Next(i->get_Next());
                j->set_Next(p);
                delete i;
                return 1;
            }
        }
        j = i;
    }
    return 0;
}
	int set_Available(int videoCode, bool available){

    Video*i;
    for (i = head; i; i = i->get_Next()){
        if(videoCode == i->get_Video_Code()){
            i->set_Available(available);
            return 1;
        }
    }
    return 0;
}
	Video* check_Video_Code(int videoCode){		//IF VIDEOCODE EXISTED, RETURN VIDEO*; ELSE RETURN NULL

    Video *i;
    for (i = head; i; i = i->get_Next())
        if(videoCode == i->get_Video_Code())
            return i;

    return NULL;
}

};


#endif // VIDEO_LIST_H_INCLUDED
