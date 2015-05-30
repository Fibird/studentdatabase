#include <iostream>
#include <string>

using namespace std;
#define N 5

struct stuNode
{
   int stuID;
   string name;
   string gender;
   int age;
   struct stuNode *next;
};
stuNode *first=NULL, *track = NULL;    /* points to the first part */
/**************************************************************
 * Create: Creates a new base and save the information in it. *
 **************************************************************/
void Create(void);
/**************************************************************
 * Find: Finds the base that has the same age with the enter- *
 *       ed age and delete it.                                *
 **************************************************************/
int Find(int num);
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
    /*mark ������ǡ�����һ���ڵ����ʱmark��Ϊ1*/
    static int mark = -1;

    newStudent = new struct stuNode;
    cin >> newStudent->stuID
        >> newStudent->name
        >> newStudent->gender
        >> newStudent->age;

    if (-1 == mark)                     //������һ���ڵ�
    {
    newStudent->next = first;
    first = newStudent;
    track = newStudent;
    mark = 1;
    }
    else
    {
        track->next = newStudent;         //��������һ���ڵ�֮��Ľڵ�
        track = newStudent;
        newStudent->next = NULL;
    }
}
int Find(int num)
{
    stuNode *pre, *cur, *newStudent;

    for (cur = first, pre = NULL;
         cur != NULL && num != cur->age;
         pre = cur, cur = pre->next)
          ;
    if (cur == NULL)                    //δ�ҵ���������ͬ�����䣬��������
    {
        newStudent = new struct stuNode;

         newStudent->stuID = 180;
         newStudent->name = "aaa";
         newStudent->gender = "male";
         newStudent->age = num;

        track->next = newStudent;
        track = newStudent;
        newStudent->next = NULL;
        return 0;
    }
    if (pre == NULL)                 //��������ͬ�������ڵ�һ���ڵ�
    {
        first = first->next;
    }
    else                             //��������ͬ�������������ڵ�
    {
        pre->next = cur->next;
    }
    delete cur;
 //   delete newStudent;
    return 0;
}
void Print()
{
    stuNode *p;

    for (p = first; p !=NULL; p = p->next)
    {
        cout << p->stuID << endl;
        cout << p->name << endl;
        cout << p->gender << endl;
        cout << p->age << endl;
    }
}

