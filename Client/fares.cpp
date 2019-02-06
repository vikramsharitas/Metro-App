#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include"class.h"
#include"maps.h"

void fares()//i couldnt find any place to break and forn new function
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0)
	{
		return;
	}
	int run;
	char f = 'f';
	send(Connection, (char*)&(f), sizeof(f), NULL);

	double fare = 0;

	lin *temp = fline;
	cleardevice();
	while (temp != NULL)
	{
		temp->draw_line();
		temp = temp->next.node;
	}

	temp = fline;
	int x1 = 0, y1 = 0, y2 = 0, x2 = 0;
	while (1)
	{
		outtextxy(w - 200, h - 75, "BACK");
		while (1)
		{
			outtextxy(w / 2, 75, "PLEASE CHOOSE STATION 1");
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x1, y1);

				if (x1 >= w - 300 && x1 <= w - 100 && y1 >= h - 100 && y1 <= h - 50)
				{
					run = -1;
					send(Connection, (char*)&run, sizeof(run), NULL);
					return;
				}

				break;
			}

		}

		int n = 0;
		double m = 0, c = 0;

		temp = fline;

		while (temp != NULL && n != 1) //verifying click is on a line
		{
			m = temp->gy2() - temp->gy1();
			m /= (temp->gx2() - temp->gx1());
			c = temp->gy1();
			c += temp->gx1()*(temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());

			n = verify(x1, y1, temp, m, c);
			temp = temp->next.node;
		}

		if (n)
		{
			while (1)
			{
				outtextxy(w / 2, 75, "PLEASE CHOOSE STATION 2 ON THE SAME LINE");
				while (1)
				{
					if (ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN, x2, y2);

						if (x2 >= w - 300 && x2 <= w - 100 && y2 >= h - 125 && y2 <= h - 25)
						{
							run = -1;
							send(Connection, (char*)&run, sizeof(run), NULL);
							return;
						}

						break;
					}

				}
				int d = 0;
				if (y2 <= 10 * (cos(atan(m))) + m * x2 + c && y2 >= -10 * (cos(atan(m))) + m * x2 + c && x2 <= temp->gx2() + 10 && x2 >= temp->gx1() - 10)//verifying second click is on same line
				{
					station* temp1 = temp->first;

					while (temp1->next.node != NULL)
					{
						if (temp1->x < x2 + 10 && temp1->x > x2 - 10 && temp1->y > y2 - 10 && temp1->y < y2 + 10)
						{
							d++;
							break;
						}
						temp1 = temp1->next.node;

					}

					if (temp1->x < x2 + 10 && temp1->x > x2 - 10 && temp1->y > y2 - 10 && temp1->y < y2 + 10)
					{
						d++;
					}
				}

				if (d)
				{
					send(Connection, (char*)&x1, sizeof(x1), NULL);
					send(Connection, (char*)&x2, sizeof(x2), NULL);
					send(Connection, (char*)&y1, sizeof(y1), NULL);
					send(Connection, (char*)&y2, sizeof(y2), NULL);
					recv(Connection, (char*)&fare, sizeof(fare), NULL);
					setfillstyle(1, WHITE);
					bar(0, 0, w, 124);
					outtextxy(w / 2, 75, "FARE");
					char tot[4] = {};
					_itoa(fare, tot, 10);
					outtextxy(w / 2 + 400, 75, tot);
					break;
				}
				else
					continue;
			}
			break;
		}

		else
			continue;
	}

	outtextxy(w - 200, h - 75, "BACK");
	setfillstyle(1, WHITE);
	outtextxy(w / 4, h - 75, "TRANSACT");
	outtextxy(3 * w / 4, h - 75, "DON'T TRANSACT");
	while (1)
	{
		int x, y;
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (x >= w - 300 && x <= w - 100 && y >= h - 125 && y <= h - 25)
		{
			return;
		}
		else if (x >= 3 * w / 4 - 100 && x <= 3 * w / 4 + 100 && y >= h - 125 && y <= h - 25)
		{
			return;
		}
		else if (x >= w / 4 - 100 && x <= w / 4 + 100 && y >= h - 125 && y <= h - 25)
		{
			write_transa(fare);
			return;
		}
	}
}