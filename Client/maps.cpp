#include"maps.h"
#include"class.h"

station::station(int x3, int y3, int n, int x1, int y1, int x2, int y2, station* first)
{
	double m = 0, c = 0;
	if (n == 0)
	{
		m = (y2 - y1);
		m /= (x2 - x1);
		c = y1;
		c += x1 * (y1 - y2) / (x2 - x1);
	}
	next.node = NULL;
	prev.node = NULL;

	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	
	x = x3;
	y = y3;
	if (n == 0 && y <= 5 * (cos(atan(m))) + m * x + c && y >= -5 * (cos(atan(m))) + m * x + c && x < x2 - 5 && x > x1 + 5)    //calculate m, n & c
	{
		setfillstyle(1, WHITE);
		bar(0, 0, w, 124);
		outtextxy(w / 2, 75, "ENTER NAME OF STATION");
		char ch;
		ch = getch();
		int i = 0;
		while (ch != 13 && i < 20)
		{
			setfillstyle(1, WHITE);
			bar(0, h - 124, w - 400, h);
			if ((int)ch != 8)
			{
				name[i] = toupper((char)ch);
				name[i + 1] = '\0';
				outtextxy(w / 2, h - 75, name);
				i++;
			}
			else if (ch == 8 && i >= 1)
			{
				name[i - 1] = '\0';
				setcolor(BLACK);
				outtextxy(w / 2, h - 75, name);
				setbkcolor(WHITE);
				setcolor(BLACK);
				i--;
			}
			ch = getch();
		}
		setfillstyle(1, WHITE);
		bar(0, h - 124, w - 400, h);
		y = m * x + c;
		station* temp = first;
		int b = 0;
		while (temp->next.node != NULL)
		{
			if (temp->x > x)
			{
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
		outtextxy(x, y + 30, name);
	}
	else if (n == 1 && y <= y2 - 5 && y >= y1 + 5 && x <= x1 + 5 && x >= x1 - 5)   //The same as earlier, but for vertical lines
	{
		setfillstyle(1, WHITE);
		bar(0, 0, w, 124);
		outtextxy(w / 2, 75, "ENTER NAME OF STATION");
		char ch;
		ch = getch();
		int i = 0;
		while (ch != 13 && i < 20)
		{
			setfillstyle(1, WHITE);
			bar(0, h - 124, w - 400, h);
			if ((int)ch != 8)
			{
				name[i] = toupper((char)ch);
				name[i + 1] = '\0';
				outtextxy(w / 2, h - 75, name);
				i++;
			}
			else if (ch == 8 && i >= 1)
			{
				name[i - 1] = '\0';
				setcolor(BLACK);
				outtextxy(w / 2, h - 75, name);
				setbkcolor(WHITE);
				setcolor(BLACK);
				i--;
			}
			ch = getch();
		}
		setfillstyle(1, WHITE);
		bar(0, h - 124, w - 400, h);
		x = x1;
		station*temp = first;
		while (temp->y < y && temp->next.node != NULL)
		temp = temp->next.node;
		if (temp->next.node != NULL)
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
		outtextxy(x, y + 30, name);
	}
}

station::station(int x1, int y1)
{
	x = x1;
	y = y1;
	setfillstyle(1, WHITE);
	bar(0, 0, w, 124);
	outtextxy(w / 2, 75, "ENTER NAME OF STATION");
	char ch;
	ch = getch();
	int i = 0;
	while (ch != 13 && i < 20)
	{
		setfillstyle(1, WHITE);
		bar(0, h - 124, w - 400, h);
		if ((int)ch != 8)
		{
			name[i] = toupper((char)ch);
			name[i + 1] = '\0';
			outtextxy(w / 2, h - 75, name);
			i++;
		}
		else if (ch == 8 && i >= 1)
		{
			name[i - 1] = '\0';
			setcolor(BLACK);
			outtextxy(w / 2, h - 75, name);
			setbkcolor(WHITE);
			setcolor(BLACK);
			i--;
		}
		ch = getch();
	}
	setfillstyle(1, WHITE);
	bar(0, h - 124, w - 400, h);
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
	outtextxy(x, y + 30, name);
}

station::station(int x1, int y1, station *first)
{
	x = x1;
	y = y1;
	inter = TRUE;
	setfillstyle(1, WHITE);
	bar(0, 0, w, 124);
	outtextxy(w / 2, 75, "ENTER NAME OF STATION");
	char ch;
	ch = getch();
	int i = 0;
	while (ch != 13 && i < 20)
	{
		setfillstyle(1, WHITE);
		bar(0, h - 124, w - 400, h);
		if ((int)ch != 8)
		{
			name[i] = toupper((char)ch);
			name[i + 1] = '\0';
			outtextxy(w / 2, h - 75, name);
			i++;
		}
		else if (ch == 8 && i >= 1)
		{
			name[i - 1] = '\0';
			setcolor(BLACK);
			outtextxy(w / 2, h - 75, name);
			setbkcolor(WHITE);
			setcolor(BLACK);
			i--;
		}
		ch = getch();
	}
	setfillstyle(1, WHITE);
	bar(0, h - 124, w - 400, h);
	next.node = NULL;
	prev.node = NULL;

	station* temp = first;

	int b = 0;

	while (temp->next.node != NULL)
	{
		if (temp->x > x)
		{
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
	outtextxy(x, y + 30, name);
}

station::station(int a, int b, bool c, char* nam)
{
	strcpy(name, nam);
	inter = c;
	x = a;
	y = b;
}








lin::lin(int z)
{
	settextjustify(CENTER_TEXT, VCENTER_TEXT);

	next.node = NULL;
	prev.node = NULL;
	double m = 0, c = 0;
	n = 0;

	outtextxy(w / 2, 75, "SELECT THE END POINTS OF LINE WITHIN SPECIFIED REGION");
	rectangle(0, 125, w, h - 125);

	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x1, y1);

			if (y1 > 125 && y1 < h - 125)
				break;
		}

	}

	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x2, y2);

			if (y2 > 125 && y2 < h - 125)
				break;
		}
	}

	setfillstyle(1, WHITE);
	bar(0, 0, w, 124);
	outtextxy(w / 2, 75, "ENTER LINE COLOR ( <= 16 )");
	char ch, c1[3];
	ch = getch();
	int i = 0;
	while (ch != 13 && i < 20) //getting input from window for line colour
	{
		setfillstyle(1, WHITE);
		bar(0, h - 124, w - 400, h);
		if ((int)ch != 8)
		{
			c1[i] = toupper((char)ch);
			c1[i + 1] = '\0';
			outtextxy(w / 2, h - 75, c1);
			i++;
		}
		else if (ch == 8 && i >= 1)
		{
			c1[i - 1] = '\0';
			setcolor(BLACK);
			outtextxy(w / 2, h - 75, c1);
			setbkcolor(WHITE);
			setcolor(BLACK);
			i--;
		}
		ch = getch();
	}
	setfillstyle(1, WHITE);
	bar(0, h - 124, w - 400, h);
	col = atoi(c1);  //converting array received to integer
	num = z;
	if (y1 == y2)
	{
		n = 1;

		if (x1 > x2)//making smaller of the 2 x1
		{
			x1 = x1 + x2;
			x2 = x1 - x2;
			x1 = x1 - x2;
		}
	}

	else
	{
		if (x1 > x2)//making smaller of the 2 x1
		{
			x1 = x1 + x2;
			x2 = x1 - x2;
			x1 = x1 - x2;
			y1 = y1 + y2;
			y2 = y1 - y2;
			y1 = y1 - y2;
		}
		m = (y2 - y1);
		m /= (x2 - x1);
		c = y1;
		c += x1 * (y1 - y2) / (x2 - x1);
	}

	{
		int poly[10];
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

		setfillstyle(SOLID_FILL, col);
		fillpoly(5, poly);
	}

	first = new station(x1, y1);
	station *temp8;
	temp8 = first;
	temp8->next.node = new station(x2, y2);
	temp8 = first->next.node;
	temp8->prev.node = first;

}

int lin::gx1()
{
	return x1;
}

int lin::gx2()
{
	return x2;
}

int lin::gy1()
{
	return y1;
}

int lin::gcol()
{
	return col;
}

int lin::gy2()
{
	return y2;
}

void lin::delete_line(lin* &fline)
{
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w - 200, h - 75, "Exit");
	int x, y, b = 0;
	lin *temp = fline;

	while (1)
	{
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
		}

		else
		{
			lin *temp1;
			temp1 = temp->prev.node;
			temp1->next.node = NULL;
			temp->prev.node = NULL;
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

	else
	{
		settextjustify(CENTER_TEXT, VCENTER_TEXT);
		setfillstyle(1, WHITE);
		bar(0, h - 124, w - 400, h);
		outtextxy(w / 2, 50, "No Line Detected Or First Line Detected");
		outtextxy(w / 2, h - 50, "Press Any Key to Continue");
		while (!kbhit()) {}
	}
}

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
				setfillstyle(1, WHITE);
				bar(0, h - 124, w - 400, h);
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
}

void lin::draw_line()
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
	for (temp6 = first; temp6 != 0; temp6 = temp6->next.node)
	{
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
	}
}

void lin::delete_station(int x, int y)
{
	station* temp = first;
	temp = temp->next.node;

	while (temp->next.node != NULL)
	{
		if (temp->x < x + 5 && temp->x > x - 5 && temp->y > y - 5 && temp->y < y + 5 && x < x2 - 5 && x > x1 + 5)
		{
			n++;
			break;
		}

		temp = temp->next.node;

	}
	if (n)
	{
		station *temp1 = temp->prev.node, *temp2 = temp->next.node;
		temp1->next.node = temp2;
		temp2->prev.node = temp1;
		temp->next.node = NULL;
		temp->prev.node = NULL;
		delete temp;
	}
	else
	{
		settextjustify(CENTER_TEXT, VCENTER_TEXT);
		outtextxy(w / 2, 50, "No Station Detected OR Terminal Station Detected");
		outtextxy(w / 2, h - 50, "Press Any Key to Continue");
	}
	while (!kbhit()) {}

}

void lin::add_station(int x, int y)
{
	station* temp = new station(x, y, n, x1, y1, x2, y2, first);
}

void lin::lind(int a, int b, int c, int d, int e, int f, int g)
{
	col = c;
	x1 = d;
	x2 = e;
	y1 = f;
	y2 = g;
	n = a;
	num = b;
}