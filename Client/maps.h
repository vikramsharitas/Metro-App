#pragma once

#include<iostream>
#include<string>
#include<string.h>
#include"graphics.h"
#include<math.h>
#include<fstream>

using namespace std;

class station;
class lin;
void extern map_edit();
void extern read_line();
void extern write_line();
int extern getbtn();
void extern map();
void extern fares();
void extern addline();
void extern delline();
void extern addstat();
void extern delstat();
void extern write_transa(int);
int extern verify(int, int, lin*, double, double);

extern lin *fline, *temp5;

class station;

extern void map_edit();

struct nod
{
    public :
        station* node;
};

class station
{
    private :

    public :
        nod next , prev;
		bool inter = 1;
		int x = 0, y = 0;
		char name[30];
		station() {};

		station(int, int, int, int, int, int, int, station*);
		station(int, int);
		station(int, int, station*);
		station(int a, int b, bool c, char* nam);
};
































struct nod1
{

    public :
        lin* node;

};

class lin
{

    private :
        int col , x1 , y1 , x2 , y2;

    public :
		lin() {};
        lin (int);
		void lind(int a, int b, int c, int d, int e, int f, int g);
        int gx1();
        int gx2();
        int gy1();
        int gy2();
        int gcol();
		int n, num;
        nod1 next , prev;

        station* first;
		void add_station(int x, int y);
		void delete_station(int x, int y);
		void add_line(lin*);
		void delete_line(lin*&);
		void draw_line();
};
