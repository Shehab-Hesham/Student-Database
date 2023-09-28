#include <stdio.h>
#include <stdlib.h>
#include "STD.h"
#include "SDB.h"

student Database[10] ;


Bool SDB_IsFull ()
{
    if (Database[9].Student_ID != 0)
    {
        return True ;
    }
    //no need for else, return will exit the function
    return False ;
} /*to know if database is full, we check the last element of the array
if the array's last element is empty, any of the struct's parameters will be 0
We only check the last element because when an element is deleted,
all elements are shifted to the left, leaving empty spaces at the end of the array*/


uint8 SDB_GetUsedSize ()
{
    uint8 Usedsize = 0, i = 0 ;
    while ( i < 10 )
    {
        if (Database[i].Student_ID != 0)
            Usedsize ++ ;
        i++ ;
    }
    return Usedsize ;
}/*An element is empty if any of the struct's parameters is NULL,
if a student ID is not NULL, this means there is a student, so this element is used*/

Bool SDB_AddEntry ()
{
    uint8 i = 0 ;
    uint8 check_format ;
    while (i < 10)
    {
        if (Database[i].Student_ID == 0 && SDB_GetUsedSize() < 10)
        {
            printf("Please enter Student %d's ID\n", i+1) ;
            check_format = scanf("%d", &Database[i].Student_ID) ;
            if (check_format) // is  if input is of same type (correct format)
            {
                printf("Please enter Student %d's Year\n", i+1) ;
                check_format = scanf("%d", &Database[i].Student_year) ;
                if(check_format)
                {
                    printf("Please enter Student %d's Course 1 ID\n", i+1) ;
                    check_format = scanf("%d", &Database[i].Course1_ID) ;
                    if(check_format)
                    {
                        printf("Please enter Student %d's Course 1 Grade\n", i+1) ;
                        check_format = scanf("%d", &Database[i].Course1_grade) ;
                        if(check_format)
                        {
                            printf("Please enter Student %d's Course 2 ID\n", i+1) ;
                            check_format = scanf("%d", &Database[i].Course2_ID) ;
                            if (check_format)
                            {
                                printf("Please enter Student %d's Course 2 Grade\n", i+1) ;
                                check_format = scanf("%d", &Database[i].Course2_grade) ;
                                if (check_format)
                                {
                                    printf("Please enter Student %d's Course 3 ID\n", i+1) ;
                                    check_format = scanf("%d", &Database[i].Course3_ID) ;
                                    if (check_format)
                                    {
                                        printf("Please enter Student %d's Course 3 Grade\n", i+1) ;
                                        check_format = scanf("%d", &Database[i].Course3_grade) ;
                                        if (check_format)
                                        {
                                            printf("Student added successfully\n") ;
                                            return True ;
                                        }
                                    }
                                    else
                                    {
                                        printf("Incorrect Course ID format\n") ;
                                        return False ;
                                    }
                                }
                                else
                                {
                                    printf("Incorrect Course grade format\n") ;
                                    return False ;
                                }
                            }
                            else
                            {
                                printf("Incorrect Course ID format\n") ;
                                return False ;
                            }
                        }
                        else
                        {
                            printf("Incorrect Course grade format\n") ;
                            return False ;
                        }

                    }
                    else
                    {
                        printf("Incorrect Course ID format\n") ;
                        return False ;
                    }

                }
                else
                {
                    printf("Incorrect Year format\n") ;
                    return False ;
                }
            }
            else
            {
                printf("Incorrect ID format\n") ;
                return False ;
            }

        }
        i++ ;
    }
    //if no room for more students
    printf("Database is full, can't add more students\n") ;
    return False ;
}/*Always add entry to the next free element in the array of structs,
If the database is full, the loop will do nothing and database is full will be printed
Also, format of input is checked and if incorrect, False is returned after a warning is printed*/

void SDB_DeletEntry (uint32 id)
{
    uint8 i ;
    uint8 j ;
    uint8 pos ;
    if (SDB_IsIdExist(id) == 1)
    {
        if (SDB_GetUsedSize() > 3) //to avoid having a school with 3 or less students
        {
            for (i = 0 ; i < 10 ; i++)
            {

                if (Database[i].Student_ID == id)
                {
                    pos = i ;
                    break ;
                }
            }
            for (j = pos + 1 ; j < 10 ; j++)
            {
                Database[pos++] = Database[j] ;
            }
                    Database[9].Course1_grade = 0 ;
                    Database[9].Course1_ID = 0 ;
                    Database[9].Course2_grade = 0 ;
                    Database[9].Course2_ID = 0 ;
                    Database[9].Course3_grade = 0 ;
                    Database[9].Course3_ID = 0 ;
                    Database[9].Student_ID = 0 ;
                    Database[9].Student_year = 0 ;
                    printf("Student with ID = %d deleted successfully\n", id) ;
        }
        else
        {
            printf("Can't delete, school will have too few students\n") ;
        }
    }
    else
    {
        printf("ID does not exist in Database\n") ;
    }

} /*This does not exactly delete a student, it overwrites the
value of the next element of the struct in it's place, this happens for all elements
after the  student we desire to delete. The last struct of the array will
have a value of zero, this is how we check  used size and if the array is full or not*/

Bool SDB_ReadEntry (uint32 id)
{
    uint8 i = 0 ;
    while (i < 10 && Database[i].Student_ID != 0)
    {
        if (Database[i].Student_ID == id)
        {
            printf("Student %d's ID is %d\n", i+1, Database[i].Student_ID) ;
            printf("Student %d's Year is %d\n", i+1, Database[i].Student_year) ;
            printf("Student %d's Course 1 ID is %d\n", i+1, Database[i].Course1_ID) ;
            printf("Student %d's Course 1 Grade is %d\n", i+1, Database[i].Course1_grade) ;
            printf("Student %d's Course 2 ID is %d\n", i+1, Database[i].Course2_ID) ;
            printf("Student %d's Course 2 Grade is %d\n", i+1, Database[i].Course2_grade) ;
            printf("Student %d's Course 3 ID is %d\n", i+1, Database[i].Course3_ID) ;
            printf("Student %d's Course 3 Grade is %d\n", i+1, Database[i].Course3_grade) ;

            return True ;
        }
        i++ ;
    }
    printf("Student with id = %d does not exist\n", id) ;
    return False ; //returned false if ID not in database of students
}/*We loop through the array, where there are still elements
(no null elements yet, to avoid unnecessary iterations)
if the desired ID is found, we print the data stored in this struct student,
if the ID is not found, an alert is printed.
ALTERNATIVE SOLUTION: we can have if(SDB_IsIdExist (id) == TRUE), we have the while loop with  the if condition checking
where the student is and prints array*/

void SDB_GetList(uint32 * list)
{
    //uint8 size = SDB_GetUsedSize();
    uint8 i;
    for (i = 0; Database[i].Student_ID != 0 ; i++)
    {
        list[i] = Database[i].Student_ID;
    }
}/*Takes as input an address to an empty array and uses the pointer to store
Student IDs in the allocated array*/
void printIDs(uint32 * list)
{
    //uint8 size = SDB_GetUsedSize();
    if (Database[0].Student_ID == 0)
    {
        printf("The array is still empty\n");
    }
    else
    {
        uint8 i;
        for (i = 0; Database[i].Student_ID != 0; i++)
        {
            printf("Student %d's ID is: %d\n", i + 1, list[i]);
        }
    }
}/*Takes the list declared in SDBAPP and defined in SDB_GETLIST
and prints the IDs of students available*/
Bool SDB_IsIdExist (uint32 id)
{
    int i = 0 ;
    while (i < 10)
    {
        if (Database[i].Student_ID == id)
        {
            return True ;
        }
        i++ ;
    }
    printf("ID does not exist\n") ;
    return False  ; //returned false if ID not in database of students
}/*We loop through the array until we find the student with the desired
ID, if the ID does not exist, we print an alarm and return False*/
