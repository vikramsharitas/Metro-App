#pragma once

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
extern int w;
extern int h;
//extern void map();
extern void fill(int, int, int);
void extern first();
void extern signup();
void extern signin();
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
		USER();
		void transa(double i);
		double returnbal();
		void bye();
};
USER extern U;
void extern rech();
void extern fpage();
