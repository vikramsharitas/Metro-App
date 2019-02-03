#ifndef MAPS_H_INCLUDED
#define MAPS_H_INCLUDED

//#include"common.h"
#include<iostream>
#include<string>
#include<string.h>
#include"graphics.h"
#include<math.h>
#include<fstream>

using namespace std;

class station;
class lin;

int screenWidth=GetSystemMetrics(SM_CXSCREEN);
extern int w=screenWidth;
extern int h=getmaxheight()+3;

class station;

extern void map_edit();
extern void maps();

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
        //int gx();
        //int gy();

        //string gname();
        //int gline();

		station(int, int, int, int, int, station*);
		station(int, int);
		station(int, int, station*);
		station(int a, int b, bool c, char* nam)
		{
			strcpy(name, nam);
			inter = c;
			x = a;
			y = b;
		};
};
station::station( int n, int x1, int y1, int x2, int y2, station* first)
{
	double m = 0, c = 0;
	//std::cout<<"\n" << n << std::endl;
	if (n == 0)
	{
		m = (y2 - y1);
		m /= (x2 - x1);
		c = y1;
		c += x1 * (y1 - y2) / (x2 - x1);
	}
	//cout << m << " " << c << endl;
    next.node = NULL;
    prev.node = NULL;

	settextjustify(CENTER_TEXT, VCENTER_TEXT);
    outtextxy (w - 200, h - 75, "Exit");

    while( 1 )
    {
        //cout<<1;
        if( ismouseclick( WM_LBUTTONDOWN ) )
        {
            //cout<<2;
            getmouseclick( WM_LBUTTONDOWN , x , y );
            //cout<<x<<" "<<y<<" "<<5*(cos(atan(m))) + m*x + c<<" "<<-5*(cos(atan(m))) + m*x + c<<" "<<x1<<" "<<x2<<endl;
            if( n == 0 && y <= 5*(cos(atan(m))) + m*x + c && y >= -5*(cos(atan(m))) + m*x + c && x < x2 - 5 && x > x1 + 5 )    //calculate m, n & c
            {
                setfillstyle(1, WHITE);
                bar(0, 0, w, 125);
                outtextxy(w/2, 75, "ENTER NAME OF STATION");
                char ch;
                ch=getch();
                int i=0;
                while(ch!=13&&i<20)
                {
                    setfillstyle(1, WHITE);
                    bar(0, h-125, w-400, h);
                    if((int)ch!=8)
                    {
                        name[i]=toupper((char)ch);
                        name[i+1]='\0';
                        outtextxy(w/2,h-75,name);
                        i++;
                    }
                    else if(ch==8&&i>=1)
                    {
                        name[i-1]='\0';
                        setcolor(BLACK);
                        outtextxy(w/2,h-75,name);
                        setbkcolor(WHITE);
                        setcolor(BLACK);
                        i--;
                    }
                    ch=getch();
                }
                setfillstyle(1, WHITE);
                bar(0, h-125, w-400, h);
				//cout << "\n" << 3 << endl;
                y = m*x + c;

                station* temp = first;

                outtextxy (w - 200, h - 75, "Exit");

				int b = 0;

				while (temp->next.node != NULL)
				{
					if (temp->x > x)
					{
						//cout << "\n" << 3 << endl;
						b++;
						break;
					}
					temp = temp->next.node;
				}

				if (temp->x > x)
				{
					b++;
				}

                if(b)
                {
					//cout << "\n" << 4 << endl;
                    temp = temp->prev.node;
                    station* temp1;
                    temp1 = temp->next.node;
                    next.node = temp1;
                    prev.node = temp;
                    temp->next.node = this;
                    temp1->prev.node = this;
                }

                outtextxy (w - 200, h - 75, "Exit");

				int poly[10];
				poly[0] = x - 5;
				poly[1] = y - 5;
				poly[2] = x + 5;
				poly[3] = y - 5;
				poly[4] = x + 5;
				poly[5] = y + 5;
				poly[6] = x - 5;
				poly[7] = y + 5;
				poly[8] = x - 5;
				poly[9] = y - 5;
				setfillstyle(SOLID_FILL, YELLOW);
				fillpoly(4, poly);

				break;
            }

            else if( n == 1 && y <= y2 - 5 &&y >= y1 + 5 && x <= x1 + 5 && x >= x1 - 5 )
            {
                setfillstyle(1, WHITE);
                bar(0, 0, w, 125);
                outtextxy(w/2, 75, "ENTER NAME OF STATION");
                char ch;
                ch=getch();
                int i=0;
                while(ch!=13&&i<20)
                {
                    setfillstyle(1, WHITE);
                    bar(0, h-125, w-400, h);
                    if((int)ch!=8)
                    {
                        name[i]=toupper((char)ch);
                        name[i+1]='\0';
                        outtextxy(w/2,h-75,name);
                        i++;
                    }
                    else if(ch==8&&i>=1)
                    {
                        name[i-1]='\0';
                        setcolor(BLACK);
                        outtextxy(w/2,h-75,name);
                        setbkcolor(WHITE);
                        setcolor(BLACK);
                        i--;
                    }
                    ch=getch();
                }
                setfillstyle(1, WHITE);
                bar(0, h-125, w-400, h);

                x = x1;

                station*temp = first;

                while ( temp->y < y && temp->next.node != NULL )
                    temp = temp->next.node;

                if( temp->next.node != NULL)
                {
                    temp = temp->prev.node;
                    station* temp1;
                    temp1 = temp->next.node;
                    next.node = temp1;
                    prev.node = temp;
                    temp->next.node = this;
                    temp1->prev.node = this;
                }

				int poly[10];
				poly[0] = x - 5;
				poly[1] = y - 5;
				poly[2] = x + 5;
				poly[3] = y - 5;
				poly[4] = x + 5;
				poly[5] = y + 5;
				poly[6] = x - 5;
				poly[7] = y + 5;
				poly[8] = x - 5;
				poly[9] = y - 5;
				setfillstyle(SOLID_FILL, YELLOW);
				fillpoly(4, poly);

                break;
            }

            else if (x >= w - 300 && x <= w - 100 && y >= h - 100 && y <= h - 50)
                break;

        }

    }

}

station::station(int x1, int y1)
{
    x = x1;
    y = y1;
    setfillstyle(1, WHITE);
    bar(0, 0, w, 125);
    outtextxy(w/2, 75, "ENTER NAME OF STATION");
    char ch;
    ch=getch();
    int i=0;
    while(ch!=13&&i<20)
    {
        setfillstyle(1, WHITE);
        bar(0, h-125, w-400, h);
        if((int)ch!=8)
    {
            name[i]=toupper((char)ch);
            name[i+1]='\0';
            outtextxy(w/2,h-75,name);
            i++;
        }
        else if(ch==8&&i>=1)
        {
            name[i-1]='\0';
            setcolor(BLACK);
            outtextxy(w/2,h-75,name);
            setbkcolor(WHITE);
            setcolor(BLACK);
            i--;
        }
        ch=getch();
    }
    setfillstyle(1, WHITE);
    bar(0, h-125, w-400, h);
	next.node = NULL;
	prev.node = NULL;

	int poly[10];
	poly[0] = x - 5;
	poly[1] = y - 5;
	poly[2] = x + 5;
	poly[3] = y - 5;
	poly[4] = x + 5;
	poly[5] = y + 5;
	poly[6] = x - 5;
	poly[7] = y + 5;
	poly[8] = x - 5;
	poly[9] = y - 5;
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(4, poly);
}

station::station(int x1, int y1, station *first)
{
	x = x1;
	y = y1;
	inter = TRUE;
	setfillstyle(1, WHITE);
    bar(0, 0, w, 125);
    outtextxy(w/2, 75, "ENTER NAME OF STATION");
    char ch;
    ch=getch();
    int i=0;
    while(ch!=13&&i<20)
    {
        setfillstyle(1, WHITE);
        bar(0, h-125, w-400, h);
        if((int)ch!=8)
        {
            name[i]=toupper((char)ch);
            name[i+1]='\0';
            outtextxy(w/2,h-75,name);
            i++;
        }
        else if(ch==8&&i>=1)
        {
            name[i-1]='\0';
            setcolor(BLACK);
            outtextxy(w/2,h-75,name);
            setbkcolor(WHITE);
            setcolor(BLACK);
            i--;
        }
        ch=getch();
    }
    setfillstyle(1, WHITE);
    bar(0, h-125, w-400, h);
	next.node = NULL;
	prev.node = NULL;

	station* temp = first;

	//outtextxy(w - 200, h - 75, "Exit");

	int b = 0;

	while (temp->next.node != NULL)
	{
		if (temp->x > x)
		{
			//cout << "\n" << 3 << endl;
			b++;
			break;
		}
		temp = temp->next.node;
	}

	if (temp->x > x)
	{
		b++;
	}

	if (b)
	{
		//cout << "\n" << 4 << endl;
		temp = temp->prev.node;
		station* temp1;
		temp1 = temp->next.node;
		next.node = temp1;
		prev.node = temp;
		temp->next.node = this;
		temp1->prev.node = this;
	}

	int poly[10];
	poly[0] = x - 5;
	poly[1] = y - 5;
	poly[2] = x + 5;
	poly[3] = y - 5;
	poly[4] = x + 5;
	poly[5] = y + 5;
	poly[6] = x - 5;
	poly[7] = y + 5;
	poly[8] = x - 5;
	poly[9] = y - 5;
	setfillstyle(SOLID_FILL, YELLOW);
	fillpoly(4, poly);
}






























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
		void lind (int a, int b, int c, int d, int e, int f, int g)
		{
			col = c;
			x1 = d;
			x2 = e;
			y1 = f;
			y2 = g;
			n = a;
			num = b;
		};
        int gx1();
        int gx2();
        int gy1();
        int gy2();
        int gcol();
		int n, num;
        nod1 next , prev;

        station* first;
		void add_station()
		{
			station* temp = new station(n, x1, y1, x2, y2, first);

		};
		void delete_station(int x, int y)
		{
			station* temp = first;

			while (temp->next.node != NULL)
			{
				if (temp->x < x + 5 && temp->x > x - 5 && temp->y > y - 5 && temp->y < y + 5 && x < x2 - 5 && x > x1 + 5)
				{
					n++;
					break;
				}

				temp = temp->next.node;

			}
			if (temp->x < x + 5 && temp->x > x - 5 && temp->y > y - 5 && temp->y < y + 5 && x < x2 - 5 && x > x1 + 5)
			{
				n++;
			}
			if(n)
			{
				//cout <<"\n"<< 1;
				station *temp1 = temp->prev.node, *temp2 = temp->next.node;
				temp1->next.node = temp2;
				temp2->prev.node = temp1;
				delete temp;
			}
			else
			{
				settextjustify(CENTER_TEXT, VCENTER_TEXT);
				outtextxy(w/2, 50, "No Station Detected OR Terminal Station Detected");
				outtextxy(w / 2, h - 50, "Press Any Key to Continue");
			}
			while (!kbhit()) {}

		}

		void add_line(lin*);
		void delete_line(lin*&);
		void draw_line()
		{
			int poly[10];
			if (x2 != x1)
			{
				double m = 0, c = 0;
				m = (y2 - y1);
				m /= (x2 - x1);
				c = y1;
				c += x1 * (y1 - y2) / (x2 - x1);
				poly[0] = x1 - 5 * sin(atan(m));
				poly[1] = y1 + 5 * cos(atan(m));
				poly[2] = x1 + 5 * sin(atan(m));
				poly[3] = y1 - 5 * cos(atan(m));
				poly[4] = x2 + 5 * sin(atan(m));
				poly[5] = y2 - 5 * cos(atan(m));
				poly[6] = x2 - 5 * sin(atan(m));
				poly[7] = y2 + 5 * cos(atan(m));
				poly[8] = x1 - 5 * sin(atan(m));
				poly[9] = y1 + 5 * cos(atan(m));
			}
			else
			{
				poly[0] = x1 - 5;
				poly[1] = y1;
				poly[2] = x1 + 5;
				poly[3] = y1;
				poly[4] = x2 + 5;
				poly[5] = y2;
				poly[6] = x2 - 5;
				poly[7] = y2;
				poly[8] = x1 - 5;
				poly[9] = y1;
			}

			setfillstyle(SOLID_FILL, col);
			fillpoly(5, poly);

			station *temp6;
			temp6 = first;
			for (temp6=first; temp6 != 0; temp6=temp6->next.node)
			{
				//cout << "\n" << temp6->x << " " << temp6->y << endl;
				int x = temp6->x;
				int y = temp6->y;
				poly[0] = x + 5;
				poly[1] = y - 5;
				poly[2] = x + 5;
				poly[3] = y + 5;
				poly[4] = x - 5;
				poly[5] = y + 5;
				poly[6] = x - 5;
				poly[7] = y - 5;
				poly[8] = x + 5;
				poly[9] = y - 5;
				setfillstyle(SOLID_FILL, YELLOW);
				fillpoly(5, poly);
				settextjustify(CENTER_TEXT, BOTTOM_TEXT);
				outtextxy(temp6->x, temp6->y + 30, temp6->name);
				//if (temp6->next.node != NULL)
			}
		};
};

lin::lin (int z)
{
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w - 200, h - 75, "Exit");

    next.node = NULL;
    prev.node = NULL;
	double m = 0, c = 0;
	n = 0;
    /*if ( beg->next.node != NULL )
    {
        cout<<1;
        lin* temp = beg;
        while( temp->next.node != NULL )
        {
            temp = temp->next.node;
        }

        //beg->next.node = ths;
        //prev.node = beg;
    }*/

    while( 1 )
    {
        if( ismouseclick( WM_LBUTTONDOWN))
        {
            getmouseclick ( WM_LBUTTONDOWN , x1 , y1 );

			if (x1 >= w - 300 && x1 <= w - 100 && y1 >= h - 100 && y1 <= h - 50)
			{
				return;
			}

			if (y1 > 125 && y1 < h - 125)
				break;
        }

    }

    while( 1 )
    {
        if( ismouseclick( WM_LBUTTONDOWN))
        {
            getmouseclick ( WM_LBUTTONDOWN , x2 , y2 );

			if (x2 >= w - 300 && x2 <= w - 100 && y2 >= h - 100 && y2 <= h - 50)
				return;

			if (y2 > 125 && y2 < h - 125)
				break;
        }
    }
    //cout<<1;

    setfillstyle(1, WHITE);
    bar(0, 0, w, 125);
    outtextxy(w/2, 75, "ENTER LINE COLOR ( <= 16 )");
    char ch, c1[3];
    ch=getch();
    int i=0;
    while(ch!=13&&i<20)
    {
        setfillstyle(1, WHITE);
        bar(0, h-125, w-400, h);
        if((int)ch!=8)
        {
            c1[i]=toupper((char)ch);
            c1[i+1]='\0';
            outtextxy(w/2,h-75,c1);
            i++;
        }
        else if(ch==8&&i>=1)
        {
            c1[i-1]='\0';
            setcolor(BLACK);
            outtextxy(w/2,h-75,c1);
            setbkcolor(WHITE);
            setcolor(BLACK);
            i--;
        }
        ch=getch();
    }
    setfillstyle(1, WHITE);
    bar(0, h-125, w-400, h);
    col=atoi(c1);
    num = z;
    if ( y1 == y2 )
    {
            n = 1;

            if ( x1 > x2 )
            {
                x1 = x1 + x2;
                x2 = x1 - x2;
                x1 = x1 - x2;
            }
            //cout<<1<<endl;
    }

    else
    {
        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<m<<" "<<n<<"\n";
        if ( x1 > x2 )
            {
                x1 = x1 + x2;
                x2 = x1 - x2;
                x1 = x1 - x2;
                y1 = y1 + y2;
                y2 = y1 - y2;
                y1 = y1 - y2;
            }
            //cout<<m<<endl;
            m = ( y2 - y1 );
            m /= ( x2 - x1 );
            //cout<<"\n"<< m<<endl;
            c = y1;
            c += x1*( y1 - y2 )/( x2 - x1 );
            //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<m<<" "<<n<<"\n";
    }

    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<m<<" "<<n<<" "<<c<<"\n";

   // if( m < 0 && n == 0 )
    {
        int poly[10];
        poly[0] = x1 - 5*sin ( atan( m ) );
        poly[1] = y1 + 5*cos ( atan( m ) );
        poly[2] = x1 + 5*sin ( atan( m ) );
        poly[3] = y1 - 5*cos ( atan( m ) );
        poly[4] = x2 + 5*sin ( atan( m ) );
        poly[5] = y2 - 5*cos ( atan( m ) );
        poly[6] = x2 - 5*sin ( atan( m ) );
        poly[7] = y2 + 5*cos ( atan( m ) );
        poly[8] = x1 - 5*sin ( atan( m ) );
        poly[9] = y1 + 5*cos ( atan( m ) );

        setfillstyle(SOLID_FILL , col);
        fillpoly( 5 , poly );
        //rectangle(x1, y2, x2, y1);
        //cout<<1;
        //system( "pause");
        //fillpoly(4, poly);
    }

	first = new station(x1, y1);
	station *temp8;
	temp8 = first;
	temp8->next.node = new station(x2, y2);
    temp8 = first->next.node;
    temp8->prev.node = first;
    //first->next.node = temp1;
    //temp1 = new station(num, n, m, c, x1, y1, x2, y2, first);

};

int lin::gx1()
{
    return x1;
};

int lin::gx2()
{
    return x2;
};

int lin::gy1()
{
    return y1;
};

int lin::gcol()
{
	return col;
};

int lin::gy2()
{
    return y2;
};

/*int lin::gnum()
{
    return num;
}*/

void lin::add_line(lin *fline)
{
	lin *temp = fline;
	double c = 0, m = 0, m1 = 0, c1 = 0;
	while (temp->next.node != NULL)
	{
		temp = temp->next.node;
	}
	temp->next.node = new lin(temp->num + 1);
	lin *temp1 = temp;
	temp = temp->next.node;
	temp->next.node = NULL;
	temp->prev.node = temp1;
	//temp1->next.node = temp;

	m = temp->gy2() - temp->gy1();
	m /= (temp->gx2() - temp->gx1());
	c = temp->gy1();
	c += temp->gx1() * (temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());
	temp1 = temp;
	temp = fline;
	int b = 0;
	while (temp != NULL)
	{
		b++;
		m1 = temp->gy2() - temp->gy1();
		m1 /= (temp->gx2() - temp->gx1());
		c1 = temp->gy1();
		c1 += temp->gx1() * (temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());
		if (m != m1)
		{
			int x = (c1 - c);
			x /= (m - m1);
			int y = (m*c1 - m1 * c);
			y /= (m - m1);
			if (x < w && y < h && x > 0 && y > 0 && x < temp1->x2 && x > temp1->x1)
			{
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, WHITE);
				int poly1[] = { 0, 0, w, 0, w, 125, 0, 125, 0, 0 };
				fillpoly(5, poly1);
				setcolor(BLACK);
				//outtextxy(w - 200, h - 75, "Exit");
                setfillstyle(1, WHITE);
                bar(0, h-125, w-400, h);
				outtextxy(w / 2, 50, "Do You Want To Add Intersecting Station?");
				outtextxy(w / 4, h - 75, "YES");
				outtextxy(3 * w / 4, h - 75, "NO");
				int e = 0, f = 0;
				while (1)
				{
					if (ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN, e, f);
						if (e < w / 4 + 100 && e > w / 4 - 100 && f < h - 25 && h > h - 125)
						{
							station *temp2 = new station(x, y, temp1->first);
							temp2 = NULL;
							break;
						}
						else if (e < 3 * w / 4 + 100 && e > 3 * w / 4 - 100 && f < h - 25 && h > h - 125)
							break;
					}
				}
			}
		}
		temp = temp->next.node;
	}
};

void lin::delete_line(lin* &fline)
{
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w - 200, h - 75, "Exit");
	int x, y, b = 0;
	lin *temp = fline;
	/*while (temp->prev.node != NULL)
	{
		temp = temp->prev.node;
	}*/

	while (1)
	{
		//cout << 3;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);

			if (x >= w - 300 && x <= w - 100 && y >= h - 125 && y <= h - 25)
				return;

			break;
		}

	}

	int d = 0;
	while (temp != NULL)
	{
		double m = temp->gy2() - temp->gy1();
		m /= (temp->gx2() - temp->gx1());
		double c = temp->gy1();
		c += temp->gx1()*(temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());

		d++;

		if (y <= 5 * (cos(atan(m))) + m * x + c && y >= -5 * (cos(atan(m))) + m * x + c && x < temp->gx2() && x > temp->gx1())
		{
			b++;
			break;
		}
		temp = temp->next.node;
	}
	if (b == 1 && d != 1)
	{
		if (temp->next.node != NULL)
		{
			lin *temp1, *temp2;
			temp1 = temp->prev.node;
			temp2 = temp->next.node;
			temp2->prev.node = temp1;
			temp1->next.node = temp2;
			temp->prev.node = NULL;
			temp->next.node = NULL;
			//cout << 1 << endl;
		}

		else
		{
			lin *temp1;
			temp1 = temp->prev.node;
			temp1->next.node = NULL;
			temp->prev.node = NULL;
			//cout << 2 << endl;
		}

		station *temp3, *temp4;
		temp3 = temp->first;
		temp4 = temp->first;
		while (1)
		{
			temp3 = temp3->next.node;
			delete temp4;
			temp4 = temp3;
			if (temp3 == NULL && temp4 == NULL)
			{
				break;
			}

		}
		char fname[20];
		_itoa(temp->num, fname, 10);
		strcat(fname, ".dat");
		remove(fname);
		delete temp;
	}

    /*else if(b==1 && d==1)
    {
        temp=fline;
        if(fline->next.node!=NULL)
        {
            fline=fline->next.node;
            fline->prev.node=NULL;
        }
        else
            fline=NULL;
        temp->next.node=NULL;
        delete temp;
    }*/

	else
	{
		settextjustify(CENTER_TEXT, VCENTER_TEXT);
        setfillstyle(1, WHITE);
        bar(0, h-125, w-400, h);
		outtextxy(w / 2, 50, "No Line Detected Or First Line Detected");
		outtextxy(w / 2, h - 50, "Press Any Key to Continue");
		while(!kbhit()){}
	}
};

#endif
