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
 // Create: Creates a new base and save the information in it.
void Create(void);
//Delete: Deletes the base that has the same age with the entered age and delete it.
int Delete(int num);
 //Print: Prints the database.
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
    Delete(sameAge);

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

    if (first == NULL)                     //创建第一个节点
    {
    newStudent->next = NULL;
    first = track = newStudent;
    }
    else
    {
        track->next = newStudent;         //创建除第一个节点之外的节点
        track = newStudent;
        newStudent->next = NULL;
    }
}
int Delete(int num)
{
    stuNode *pre, *cur, *newStudent;

    for (cur = first, pre = NULL;
         cur != NULL && num != cur->age;
         pre = cur, cur = pre->next)
          ;
    if (cur == NULL)                    //未找到与输入相同的年龄，新增数据
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
    if (pre == NULL)                 //与输入相同的年龄在第一个节点
    {
        first = first->next;
    }
    else                             //与输入相同的年龄在其他节点
    {
        pre->next = cur->next;
    }
    delete cur;

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

