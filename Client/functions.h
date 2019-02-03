#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include"maps.h"

void extern map_edit();

void add_line(lin *fline)
{
	cleardevice();
	lin *temp = fline;
	while (temp != NULL)
	{
		temp->draw_line();
		temp = temp->next.node;
	}
	if (fline == NULL)
	{
		//cout << " " << 1 << endl;
		fline = new lin(1);
	}

	else
		fline->add_line(fline);

	cleardevice();
	temp = fline;
	while (temp != NULL)
	{
		temp->draw_line();
		temp = temp->next.node;
	}

	cleardevice();
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w / 2 - 375, h / 2, "ADD LINE");
	outtextxy(w / 2 - 125, h / 2, "ADD STATION");
	outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
	outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
	outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
	outtextxy(w - 200, h - 75, "BACK");
}

void add_station(lin* fline)
{
	cleardevice();
	lin *temp = fline;
	while (temp != NULL)
	{
		temp->draw_line();
		temp = temp->next.node;
	}
	temp = fline;
	int x = 0, y = 0;
	while (1)
	{
		//cout << 3;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);

			if (x >= w - 300 && x <= w - 100 && y >= h - 100 && y <= h - 50)
				return;

			break;
		}

	}

	int b = 0;

	while (temp != NULL)
	{
		double m = temp->gy2() - temp->gy1();
		m /= (temp->gx2() - temp->gx1());
		double c = temp->gy1();
		c += temp->gx1()*(temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());

		if (y <= 5 * (cos(atan(m))) + m * x + c && y >= -5 * (cos(atan(m))) + m * x + c && x < temp->gx2() - 5 && x > temp->gx1() + 5)
		{
			b++;
			break;
		}
		temp = temp->next.node;
	}

	if (b)
	{
		temp->add_station();
	}

	else
	{
		cleardevice();
		settextjustify(CENTER_TEXT, VCENTER_TEXT);
		outtextxy(w / 2, 50, "No Line Detected");
		outtextxy(w / 2, h - 50, "Press Any Key to Continue");
		while (!kbhit());
	}

	cleardevice();
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w / 2 - 375, h / 2, "ADD LINE");
	outtextxy(w / 2 - 125, h / 2, "ADD STATION");
	outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
	outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
	outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
	outtextxy(w - 200, h - 75, "BACK");
}

void delete_line(lin *fline)
{
	lin *temp = fline;
	setbkcolor(WHITE);
	setcolor(BLACK);
	cleardevice();
	while (temp != NULL)
	{
		temp->draw_line();
		temp = temp->next.node;
	}

	temp = fline;
	fline->delete_line(temp);

	cleardevice();
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w / 2 - 375, h / 2, "ADD LINE");
	outtextxy(w / 2 - 125, h / 2, "ADD STATION");
	outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
	outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
	outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
	outtextxy(w - 200, h - 75, "BACK");
}

void delete_station(lin *fline)
{
	cleardevice();
	lin *temp = fline;
	while (temp != NULL)
	{
		temp->draw_line();
		temp = temp->next.node;
	}
	temp = fline;
	int x = 0, y = 0;
	while (1)
	{
		//cout << 3;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);

			if (x >= w - 300 && x <= w - 100 && y >= h - 100 && y <= h - 50)
				return;

			break;
		}

	}

	int b = 0;

	while (temp != NULL)
	{
		double m = temp->gy2() - temp->gy1();
		m /= (temp->gx2() - temp->gx1());
		double c = temp->gy1();
		c += temp->gx1()*(temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());

		if (y <= 5 * (cos(atan(m))) + m * x + c && y >= -5 * (cos(atan(m))) + m * x + c && x < temp->gx2() - 5 && x > temp->gx1() + 5)
		{
			b++;
			break;
		}
		temp = temp->next.node;
	}

	if (b)
	{
		temp->delete_station(x, y);
	}

	else
	{
		cleardevice();
		settextjustify(CENTER_TEXT, VCENTER_TEXT);
		outtextxy(w / 2, 50, "No Line Detected");
		outtextxy(w / 2, h - 50, "Press Any Key to Continue");
		while (!kbhit());
	}

	cleardevice();
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w / 2 - 375, h / 2, "ADD LINE");
	outtextxy(w / 2 - 125, h / 2, "ADD STATION");
	outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
	outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
	outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
	outtextxy(w - 200, h - 75, "BACK");
}

void maps(lin *fline)
{
	lin *temp5 = fline;
	cleardevice();
	while (temp5 != NULL)
	{
		temp5->draw_line();
		temp5 = temp5->next.node;
	}

	while (!kbhit()) {};

	cleardevice();
	settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w / 2 - 375, h / 2, "ADD LINE");
	outtextxy(w / 2 - 125, h / 2, "ADD STATION");
	outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
	outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
	outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
	outtextxy(w - 200, h - 75, "BACK");
}

#endif
