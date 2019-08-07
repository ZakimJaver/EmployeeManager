/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   employee.h
 * Author: zakim
 *
 * Created on March 27, 2019, 3:44 PM
 * 
 * Information about the employee
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string.h>
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
struct Employee {
    int empID; // random id
    char fname[15];
    char lname[15];
    char groupID[12];  //the group id the person is a part of //e.g. a212
    int sales; //number of sales the emp made
    char dob[15]; //date of birth format dd-mm-yyyy
    char dJoined[15]; //date when they joined dd-mm-yyyy
    char phone[11]; //phone number
    char email[35];
    struct Employee *next;
};


#endif /* EMPLOYEE_H */

