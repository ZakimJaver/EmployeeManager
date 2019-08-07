/* 
 * File:   LinkedList.h
 * Author: zakim
 *
 * Created on March 27, 2019, 4:41 PM
 * 
 * This will store all the data of the employee for temp usage. 
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include "Employee.h"
#include <ctime> 
#include <fstream>
#include <sstream> 

using namespace std;

class LinkedList {
private:
    //pointer for the first and last employee
    Employee * start;
    Employee * last;
public:

    void insert(); //adds the data to the list 
    void delete_at(Employee *tmp, Employee *prev); //deletes the data with a specific id
    void display(); //displays data (emp id, emp full name, sales)
    void edit();//select what emp the user wishes to edit and gives the choices on what they would like to edit
    void sort();//sorts data by: employee name (alphabetically), number of sales or employee id 
    void save();//saves the everything to a text file
    void load();//loads data from the text file
    void editEmp(Employee *emp);//edits employee given emp id
    
    LinkedList(){
        start = NULL;
        last = NULL;
    }

};

//converts string to int
    int getNum(){
        int num = 0;
        string s;
        while(num == 0){
            
            cin >> s;
            try{
                stringstream nums(s);
                nums >> num;
            }catch(const exception& ex){
                cout<<"Invalid input, try again";            
            }
            if(num == 0){
                cout << "Invalid input, try again\n";
            }
        }
        return num;
    }

 /*
 * Creating Employee
 */
    void LinkedList::insert(){
        
        int error = 0;//used to check if there are any errors
        Employee *emp = new Employee();
        
        //entering employees information
        //fname
        do{
            cout<<"Please enter the employees first name:\n";
            try{
                cin >> emp->fname;
            }catch(const exception& ex){
                cout<<"Invalid first name, try again";
                error = 1;
            }
        }while(error != 0);
        
        //lname
        do{
            cout<<"Please enter the employees Last name:\n";
            try{
                cin >> emp->lname;
            }catch(const exception& ex){
                cout<<"Invalid last name, try again";
                error = 1;
            }
        }while(error != 0);
        
        //groupID
        do{
            cout<<"Please enter the group ID " << emp->fname << " is in:\n";
            try{
                cin >> emp->groupID;
            }catch(const exception& ex){
                cout<<"Invalid group ID, try again";
                error = 1;
            }
        }while(error != 0);
        
        //dob
        do{
            cout<<"Please enter " << emp->fname << "'s date of birth (dd-mm-yyyy):\n";
            try{
                cin >> emp->dob;
            }catch(const exception& ex){
                cout<<"Invalid date, try again";
                error = 1;
            }
        }while(error != 0);
        
        //date joined
        do{
            cout<<"Please enter when " << emp->fname << " joined (dd-mm-yyyy):\n";
            try{
                cin >> emp->dJoined;
            }catch(const exception& ex){
                cout<<"Invalid date, try again";
                error = 1;
            }
        }while(error != 0);
        
        //phone
        do{
            cout<<"Please enter " << emp->fname << "'s phone number (9055555555):\n";
            try{
                cin >> emp->phone;
            }catch(const exception& ex){
                cout<<"Invalid phone number, try again";
                error = 1;
            }
        }while(error != 0);
        
        //email
        do{
            cout<<"Please enter " << emp->fname << "'s email address:\n";
            try{
                cin >> emp->email;
            }catch(const exception& ex){
                cout<<"Invalid email address, try again";
                error = 1;
            }
        }while(error != 0);
        
        //end of entering info
        
        //random number for employee id
        srand((unsigned)time(0)); 
        int i;
        i = (rand()%100000000000)+1; 
        emp->empID = i;
        
        //sales starts of with 0 as they haven't sold anything
        //could be edited later
        emp->sales = 0;
        cout << emp->fname << " has been added successfully with the id: " << emp->empID << "\n";
        
        //sets the first and last employee in the list as the current one if none other exist
        if(start == NULL){
            start = last = emp;
        }else{
            //sets last employee as the current employee
            last->next = emp;
            last = emp;
        }
        
    }

/*
 * Displaying all employees
 */
    void LinkedList::display(){
        Employee* tmp = new Employee();
        tmp = start;
        
        if(tmp == NULL){
            //empty list
            cout <<"Nothing to display\n";
        }else{
            //displays employees table headers
            while(tmp != NULL){
                cout << "Employee ID: " << tmp->empID << " || Employee full name: " << tmp->fname << " " << tmp->lname << " || Total sales: " << tmp->sales << " || Group ID: " << tmp->groupID << "\n";
                tmp = tmp->next;
            }
        }
        
  
    }
    
    void LinkedList::edit(){
        int id;
        Employee* tmp = start;
        Employee* prev = NULL;
                
        if(tmp == NULL){
            cout << "List is empty\n";
            return;
        }
                    
        cout << "Please enter the employee's ID you wish to edit: \n";
        id = getNum();
        
        while(tmp != NULL){
            //finds the id
            if(tmp->empID == id){
                char option;
                do{
                    cout << "\nId found\nFull name: " << tmp->fname << " " << tmp->lname << "\nGroupID: " << tmp->groupID << "\nTotal sales: " << tmp->sales << "\nDate of Birth: " << tmp->dob << "\nDate joined: " << tmp->dJoined << "\nPhone: " << tmp->phone << "\nEmail: " << tmp->email << "\n\nWhat would you like to do:\n1. Add sales\n2. Delete Employee\n3. edit info\n4. <- Back\n";

                    cin >> option;
                    switch(option){
                        case '1':
                            cout<<"How many sales would you like to add for " << tmp->fname << "?\n";
                            int sales;
                            sales = getNum();
                            tmp->sales += sales;
                            cout << tmp->fname << " now has " << tmp->sales << " sales.\n";
                            return;
                            break;
                        case '2': 
                            delete_at(tmp, prev);
                            cout<<"Deleted\n";
                            return;
                            break;
                        case '3':
                            editEmp(tmp);
                        case '4':
                            cout<<"Going back\n";
                    }
                }while (option != '4');
                return;
            }
            prev = tmp;
            tmp = tmp->next;
        }
        cout << "ID doesn't exist, going back\n";
    }
    
    void LinkedList::editEmp(Employee* emp){
        cout << "\nEditing employee\n";
        int iVal;
        cout << "What would you like to change:\n1. First name\n2. Last name\n3. Group ID\n4. Sales\n5. Date of Birth\n6. Date joined\n7. Phone number\n8. Email\n";
        
        iVal = getNum();
            do{
            switch(iVal){
                case 1:
                    cout<<"Enter the new First name:\n";
                    cin>>emp->fname;
                    cout<<"New First name: " << emp->fname << "\n";
                    break;
                case 2:
                    cout<<"Enter the new Last name:\n";
                    cin>>emp->lname;
                    cout<<"New Last name: " << emp->lname << "\n";
                    break;
                case 3:
                    cout<<"Enter the new group ID:\n";
                    cin>>emp->groupID;
                    cout<<"New Group ID: " << emp->groupID << "\n";
                    break;
                case 4:
                    cout<<"Enter the total sales:\n";
                    cin>>emp->sales;
                    cout<<"New total sales: " << emp->sales << "\n";
                    break;
                case 5:
                    cout<<"Enter the date of birth:\n";
                    cin>>emp->dob;
                    cout<<"New Date of birth: " << emp->dob << "\n";
                    break;
                case 6:
                    cout<<"Enter the date joined:\n";
                    cin>>emp->dJoined;
                    cout<<"New date joined: " << emp->dJoined << "\n";
                    break;
                case 7:
                    cout<<"Enter the new phone number:\n";
                    cin>>emp->phone;
                    cout<<"New phone number: " << emp->phone << "\n";
                    break;
                case 8:
                    cout<<"Enter the new email:\n";
                    cin>>emp->email;
                    cout<<"New email: " << emp->email << "\n";
                    break;
            }
            }while(iVal>8 && iVal<0);
        
        
                
    }
    
    void LinkedList::delete_at(Employee* tmp, Employee* prev){
        
        if(tmp != NULL){ //first = last (when there is only one element remaining)
            
            if(prev != NULL){//there is prev employee
                prev->next = tmp->next;
                //if tmp is last, prev = last
                if(tmp == last)
                    last = prev;
                free(tmp);
                return;
            }else{ //first element
                start = tmp->next;
                free(tmp);
                if(start == NULL){
                    last = NULL;
                }
                return;
            }
        }
        
    }
    
    
    void LinkedList::sort(){
        
        //insertion sort
        Employee *largest = start;//temp element stores the largest of the unsorted list
        Employee *tmp = start;//goes through the unsorted list
        Employee *large = new Employee();//stores the largest element (starting point)
        large->next = start;
        
        if(tmp == NULL || tmp == last){
            cout<<"Nothing to sort";
            return;
        }else{
            //go through the list and find the largest val
            //add it to the front and make it the main starting point
            //keep finding the largest elements until there are no more elements left unsorted
            while(tmp->next != NULL){
                if(strcmp(tmp->next->fname, large->next->fname) > 0)
                            large = tmp;//sets large to the node before the largest node.  
                tmp = tmp->next;
            }
            largest = large->next;//stores largest node
            //if large->next points to start, the largest number is already in order so we dont need to move anything
            if(large->next != start){
                large->next = largest->next;
                largest->next = start;
            }
            last = start = largest;


            while(largest->next != NULL){
                large = largest;
                tmp = largest->next;
                while(tmp->next != NULL){
                    if(strcmp(tmp->next->fname, large->next->fname) > 0)
                            large = tmp;//sets large to the node before the largest node.  
                        tmp = tmp->next;
                    }
               
                tmp = large->next;//largest in unsorted list
                large->next = tmp->next;
                tmp->next = start;
                start = tmp;
            }
            
            cout <<"Sorted\n";
        }
        
    }
    
    void LinkedList::save(){
        ofstream myEmployees;
        myEmployees.open("myEmployee.txt");
        
        Employee* tmp = new Employee();
        tmp = start;
        
        if(tmp == NULL){
            printf("Nothing to save\n");
        }else{
            while(tmp != NULL){
                myEmployees << tmp->empID << " " << tmp->fname << " " << tmp->lname << " " << tmp->groupID << " " << tmp->sales << " " << tmp->dob << " " << tmp->dJoined << " " << tmp->phone << " " << tmp->email << "\n";
                tmp = tmp->next;
            }
        }
        myEmployees.close();
        cout<<"Data has been saved\n";
    }
    
    void LinkedList::load(){
        ifstream myEmployeeList;
        myEmployeeList.open("myEmployee.txt");
        //list was empty
        while(!myEmployeeList.eof()){
            Employee *emp = new Employee();
            myEmployeeList >> emp->empID >> emp->fname >> emp->lname >> emp->groupID >> emp->sales >> emp->dob >> emp->dJoined >> emp->phone >> emp->email;
            if(emp->empID != 0){
            if(last==NULL){
                start = last = emp;
            }else{
                last->next = emp;
                emp->next = NULL;
                last = emp; 
            }
            }
        }
        cout<<"Data loaded\n";
    }

#endif /* LINKEDLIST_H */

