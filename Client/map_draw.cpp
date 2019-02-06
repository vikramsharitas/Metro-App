#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include"class.h"
#include"maps.h"

void map()
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
	char prog = 'm';
	send(Connection, (char*)&prog, sizeof(prog), NULL);
	temp5 = fline;
	cleardevice();
	while (temp5 != NULL)
	{
		temp5->draw_line();
		temp5 = temp5->next.node;
	}

	temp5 = fline;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0, x3 = 0, x4 = 0, y3 = 0, y4 = 0;
	while (temp5 != NULL)
	{
		x1 = temp5->gx1();
		x2 = temp5->gx2();
		y1 = temp5->gy1();
		y2 = temp5->gy2();
		double m = y2 - y1;
		m /= x2 - x1;
		send(Connection, (char*)&x1, sizeof(x1), NULL);
		send(Connection, (char*)&x2, sizeof(x2), NULL);
		send(Connection, (char*)&y1, sizeof(y1), NULL);
		send(Connection, (char*)&y2, sizeof(y2), NULL);
		do {
			recv(Connection, (char*)&x3, sizeof(x3), NULL);
			recv(Connection, (char*)&y3, sizeof(y3), NULL);
			recv(Connection, (char*)&x4, sizeof(x4), NULL);
			recv(Connection, (char*)&y4, sizeof(y4), NULL);
			if (x3 != 0 && y3 != 0 && x4 != 0 && y4 != 0)
			{
				setfillstyle(1, WHITE);
				circle(x3, y3, 5);
				floodfill(x3, y3, BLACK);
				setfillstyle(1, 0);
				circle(x4, y4, 5);
				floodfill(x4, y4, BLACK);
			}
		} while (x3 != 0 && y3 != 0 && x4 != 0 && y4 != 0);
		temp5 = temp5->next.node;
	}
	x1 = x2 = y1 = y2 = 0;
	send(Connection, (char*)&x1, sizeof(x1), NULL);
	send(Connection, (char*)&x2, sizeof(x2), NULL);
	send(Connection, (char*)&y1, sizeof(y1), NULL);
	send(Connection, (char*)&y2, sizeof(y2), NULL);

	outtextxy(w - 200, h - 75, "BACK");
	while (1)
	{
		int x = 0, y = 0;
		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (x >= w - 300 && x <= w - 100 && y <= h - 25 && y >= h - 125)
		{
			return;
		}
	}
}