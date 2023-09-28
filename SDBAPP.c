#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"

void SDB_APP ()
{
    uint8 choice = 8; //Dummy value, to be able to enter while loop

    while (choice != 0)
    {
        printf("Enter 0 to exit\nEnter 1 to add entry\nEnter 2 to check used size in database\nEnter 3 to read student data\nEnter 4 to get the list of all student IDs\nEnter 5 to check if ID exists\nEnter 6 to delete student data\nEnter 7 to check if Database is full\n") ;
        scanf("%d", &choice) ;
        SDB_action(choice) ;
    }
    printf("Thank you for using my database\n") ;
}/*This function is the core of the project,
This gives user options and the user keeps choosing what to do,
and the choice is sent to the action function, repeatedly, until the user chooses 0,
which ends the program*/
void SDB_action (uint8 choice)
{
    uint32 id;
    Bool full, addedSuccess, ID_exist ;
    uint8 usedSize ;
    uint32 * list = (char *) malloc(10 * sizeof(student)); //to store values from Database in [case 4]


    switch(choice)
    {
        default : printf("Invalid Input, try again\n") ; break ;
        case 0 : break ; //nothing happens if 0 chosen, it will exit loop
        case 1 :
            addedSuccess = SDB_AddEntry() ;
            (addedSuccess == True)? printf("Data added Successfully\n"): printf("Failed to add data\n") ;
            break ;
        case 2 :
            usedSize = SDB_GetUsedSize() ;
            printf("Number of students in database is %d\n", usedSize) ;
            break ;
        case 3 :
            printf("Please Enter ID To Read Student Data\n");
            scanf("%d", &id) ;
            ID_exist = SDB_ReadEntry(id) ;
            if(ID_exist == False)
                 printf("ID does not exist\n")  ;
            break ;
        case 4 :
            SDB_GetList(list) ;
            printIDs(list) ;
            free(list) ;
            break ;
        case 5 :
            printf("Please Enter ID To Check if ID Exists\n");
            scanf("%d", &id) ;
            ID_exist = SDB_IsIdExist(id) ;
            (ID_exist)? printf("ID exists\n") : printf("ID does not exists\n") ;
            break ;
        case 6 :
            printf("Please Enter ID To Delete Student\n");
            scanf("%d", &id) ;
            SDB_DeletEntry(id) ;
            break ;
        case 7 :
            full = SDB_IsFull() ;
            (full == True)? printf("Database is full\n"): printf("Database is not full\n") ;
            break ;
    }
}/*Depending on the choice of the user, the appropriate functions are called
some functions return a value, which is used to output a statement
to help the user understand what is happening.
Some functions also require an input ID, for these specific functions:
SDB_DeleteEntry, SDB_IsIdExist, SDB_ReadEntry
the user is asked to input an ID, which is used in the functions*/
