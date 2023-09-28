#ifndef SDB.h
#define SDB.h

typedef struct SimpleDb
{
    uint32 Student_ID ;
    uint32 Student_year ;
    uint32 Course1_ID ;
    uint32 Course1_grade ;
    uint32 Course2_ID ;
    uint32 Course2_grade ;
    uint32 Course3_ID ;
    uint32 Course3_grade ;

} student ;

typedef enum
        {
            False,
            True
        } Bool ;

Bool SDB_IsFull () ;
uint8 SDB_GetUsedSize () ;
Bool SDB_AddEntry () ;
void SDB_DeletEntry (uint32 id) ;
Bool SDB_ReadEntry (uint32 id) ;
void SDB_GetList (uint32 * list) ;
Bool SDB_IsIdExist (uint32 id) ;
void SDB_APP () ;
void SDB_action (uint8 choice) ;
void printIDs(uint32 * list) ;

#endif // SDB.h
