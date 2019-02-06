#include"class.h"
#include"maps.h"

void addstat()
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
	outtextxy(w - 200, h - 75, "BACK");
	while (1)
	{
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);

			if (x >= w - 300 && x <= w - 100 && y >= h - 100 && y <= h - 50)
			{
				return;
			}

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
		temp->add_station(x, y);
	}

	else
	{
		cleardevice();
		settextjustify(CENTER_TEXT, VCENTER_TEXT);
		outtextxy(w / 2, 50, "No Line Detected");
		outtextxy(w / 2, h - 50, "Press Any Key to Continue");
		while (!kbhit());
	}
}