#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
#include<iostream>
#include"graphics.h"
#include<fstream>
#include<process.h>
#include<string>
#include<windows.h>
#include<time.h>
#include<stdio.h>
#include<math.h>

int extern w1, w2, h1, h2;
//extern void map();
extern void fill(int, int, int);
int extern w, h;
void extern first();
void extern second();
void extern third();
void extern TextBox(int,int, char[]);
void extern PassWord(int,int,char[]);
void extern SHA256(char*);

//class station;
//class lin;

struct trans
{
    int tran;
    trans *next;
};
class USER
{
        double  bal;
        trans* first=NULL;
    public:
        char user[20];
        char pass[70];
        USER()
        {
            bal=0.0;
            strcpy(user,"");
            strcpy(pass,"");
         }
         void transa(double i)
         {
            bal=bal+i;
            if(bal<0)
            {
                cleardevice();
                outtextxy(w/2, h/2, "Invalid Transaction!");
				outtextxy(w/2, 75, "PRESS ANY KEY TO CONTINUE");
                getch();
                bal-=i;
                return;
            }
            if(first==NULL)
            {
                cleardevice();
                outtextxy(w/2, h/2, "Transaction Complete!");
				outtextxy(w/2, 75, "PRESS ANY KEY TO CONTINUE");
                getch();
                first=new trans;
                first->tran=i;
                first->next=NULL;
            }
            else
            {
                cleardevice();
                outtextxy(w/2, h/2, "Transaction Complete!");
				outtextxy(w/2, 75, "PRESS ANY KEY TO CONTINUE");
                getch();
                trans *temp=new trans;
                temp->tran=i;
                temp->next=first;
                first=temp;
            }
        }
        double returnbal()
        {
            return bal;
        }
        void bye()
        {
            bal=NULL;
            strcpy(pass, "");
            strcpy(user, "");
            first=NULL;
        }
};
USER extern U;
void extern rech();
void extern fpage();
#endif // CLASS_H_INCLUDED
