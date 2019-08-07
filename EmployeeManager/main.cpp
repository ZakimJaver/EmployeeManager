/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: zakim
 * Employee Manager
 * Created on March 27, 2019, 3:35 PM
 */

#include <cstdlib>
#include "Employee.h"
#include "LinkedList.h"
#include <ctime>
#include <string>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    char option;
    LinkedList list;
    //menu system
    do{
        cout << "\n\n\tMenu \n";
        cout << "____________________\n";
        cout<<"0. exit\n1. Add Employee\n2. Edit/View Employee\n3. List all employees\n4. Sort Alphabetically (by first name)\n5. Save data\n6. Load data\n";
        cin>>option;
        //choices
        switch(option){
            case '0':
                cout<<"GoodBye\n";
                break;
            case '1': 
                cout << "Adding emp\n ";
                //add emp func
                list.insert();
                break;
            case '2':
                cout<<"Editing employee\n";
                list.edit();
                break;
            case '3':
                list.display();
                break;
            case '4':
                list.sort();
                break;
            case '5':
                list.save();
                break;
            case '6':
                list.load();
                break;
        }
    }while (option != '0');
    return 0;
}

