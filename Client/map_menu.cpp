#include"class.h"
#include"maps.h"

lin *fline, *temp5;

void map_edit()
{
	fline = NULL;
	temp5 = fline;
	read_line();
	int btn = 0;
	while (1)
	{
		heli:

		cleardevice();
		settextjustify(CENTER_TEXT, VCENTER_TEXT);
		outtextxy(w / 2 - 375, h / 2, "ADD LINE");
		outtextxy(w / 2 - 125, h / 2, "ADD STATION");
		outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
		outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
		outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
		outtextxy(w / 2, h / 2 + 400, "FARES");
		outtextxy(w - 200, h - 75, "BACK");

		btn = getbtn();

		if (btn == 1)
		{
			addline();
		}
		else if (btn == 2)
		{
			addstat();
		}
		else if (btn == 3)
		{
			delline();
		}
		else if (btn == 4)
		{
			delstat();
		}
		else if (btn == 5)
		{
			map();
		}
		else if (btn == 6)
		{
			break;
		}

		else if (btn == 7)
		{
			fares();
		}
	}
	write_line();
}