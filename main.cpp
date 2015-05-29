#include <iostream>

using namespace std;
#define N 5

struct stuNode
{
   int stuID;
   char name[20];
   char gender[10];
   int age;
   struct stuNode *next;
};
stuNode *student=NULL;     /* points to the first part */
/**************************************************************
 * Create: Creates a new base and save the information in it. *
 **************************************************************/
void Create(void);
/**************************************************************
 * Find: Finds the base that has the same age with the enter- *
 *       ed age and delete it.                                *
 **************************************************************/
void Find(int num);
/**************************************************************
 * Print: Prints the database.                                *
 **************************************************************/
void Print(void);

int main()
{
    int i;
    int sameAge;
    for (i = 0; i < N; i++)
    {
        Create();
    }

    cin >> sameAge;
    Find(sameAge);

    Print();

    return 0;
}
void Create()
{
    stuNode *newStudent;

    newStudent = new struct stuNode;

    cin >> newStudent->stuID
        >> newStudent->name
        >> newStudent->gender
        >> newStudent->age;
    newStudent->next = student;
    student = newStudent;
}
void Find(int num)
{
    stuNode *pre, *cur;
    for (cur = student, pre = NULL;
         cur != NULL && num != cur->age;
         pre = cur, cur = pre->next)
          ;
    if (cur == NULL)
        ;
    if (pre == NULL)
        student = student->next;
    else
        pre->next = cur->next;

    delete [] cur;
}
void Print()
{
    stuNode *p;

    for (p = student; p !=NULL; p = p->next)
    {
        cout << p->stuID << endl;
        cout << p->name << endl;
        cout << p->gender << endl;
        cout << p->age << endl;
    }
}
