#include <iostream>
#include "Management.h"
using namespace std;

int main (){

    bool state = true;

    Management management;

    while (state){
        int choice = -1, choice1 = -1, choice2 = -1;
        management.introduction();
        while(choice < 0 || choice > 8){
            cout << "\nEnter your choice: " << endl;
            cin >> choice;
        }
        switch (choice){
            case 1:
                management.add_New_Video();
                break;
            case 2:
                management.add_New_Mem();
                break;
            case 3:
                management.issue_Video();
                break;
            case 4:
                management.return_Video();
                break;
            case 5:
                management.print_Video_List();
                break;
            case 6:
                management.print_Mem_List();
                break;
            case 7:
                management.edit_Video_Menu();
                while(choice1 < 0 || choice1 > 3){
                    cout << "\nEnter your choice: " << endl;
                    cin >> choice1;
                }
                switch (choice1){
                    case 1:
                        management.print_Video_Info();
                        break;
                    case 2:
                        management.modify_Video();
                        break;
                    case 3:
                        management.delete_Video();
                        break;
                    case 0:
                        break;
                }
                break;

            case 8:
                management.edit_Mem_Menu();
                while(choice2 < 0 || choice2 > 3){
                    cout << "\nEnter your choice: " << endl;
                    cin >> choice2;
                }
                switch (choice2){
                    case 1:
                        management.print_Mem_Info();
                        break;
                    case 2:
                        management.modify_Member();
                        break;
                    case 3:
                        management.delete_Member();
                        break;
                    case 0:
                        break;
                }
                break;

            case 0:
                state = false;
                break;
        }

    }
    return 0;
}
