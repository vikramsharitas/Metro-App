#include"maps.h"
#include"class.h"

int getbtn()
{
	int btn = 0;
	while (1)
	{

		if (ismouseclick(WM_LBUTTONDOWN))
		{
			int x = 0, y = 0;
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (x <= w / 2 - 275 && x >= w / 2 - 475 && y <= h / 2 + 50 && y >= h / 2 - 50)
			{
				btn = 1;
				break;
			}
			if (x <= w / 2 - 25 && x >= w / 2 - 225 && y <= h / 2 + 50 && y >= h / 2 - 50)
			{
				btn = 2;
				break;
			}
			if (x <= w / 2 + 225 && x >= w / 2 + 25 && y <= h / 2 + 50 && y >= h / 2 - 50)
			{
				btn = 3;
				break;
			}

			if (x <= w / 2 + 475 && x >= w / 2 + 275 && y <= h / 2 + 50 && y >= h / 2 - 50)
			{
				btn = 4;
				break;
			}

			if (x >= w / 2 - 100 && x <= w / 2 + 100 && y <= h / 2 + 250 && y >= h / 2 + 150)
			{
				btn = 5;
				break;
			}

			if (x >= w - 300 && x <= w - 100 && y >= h - 100 && y <= h - 50)
			{
				btn = 6;
				break;
			}

			if (x >= w / 2 - 100 && x <= w / 2 + 100 && y <= h / 2 + 450 && y >= h / 2 + 350)
			{
				btn = 7;
				break;
			}
		}
	}
	return btn;
}