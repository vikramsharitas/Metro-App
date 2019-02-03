#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include"functions.h"
#include"fnc.h"
#include"graphics.h"

void fares(lin *fline)
{
	//Winsock Startup
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) //If WSAStartup returns anything other than 0, then that means an error has occured in the WinSock Startup.
	{
		MessageBoxA(NULL, "Winsock startup failed", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}

	SOCKADDR_IN addr; //Address to be binded to our Connection socket
	int sizeofaddr = sizeof(addr); //Need sizeofaddr for the connect function
	addr.sin_addr.s_addr = inet_addr("127.0.0.1"); //Address = localhost (this pc)
	addr.sin_port = htons(1111); //Port = 1111
	addr.sin_family = AF_INET; //IPv4 Socket

	SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket
	if (connect(Connection, (SOCKADDR*)&addr, sizeofaddr) != 0) //If we are unable to connect...
	{
		MessageBoxA(NULL, "Failed to Connect", "Error", MB_OK | MB_ICONERROR);
		return; //Failed to Connect
	}
	std::cout << "Connected!" << std::endl;

	lin *temp = fline;
	cleardevice();
	while (temp != NULL)
	{
		temp->draw_line();
		temp = temp->next.node;
	}
	temp = fline;
	int x1 = 0, y1 = 0, y2 = 0, x2 = 0, fare = 10;
	while (1)
	{
		//cout << 3;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x1, y1);

			if (x1 >= w - 300 && x1 <= w - 100 && y1 >= h - 100 && y1 <= h - 50)
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

		if (y1 <= 5 * (cos(atan(m))) + m * x1 + c && y1 >= -5 * (cos(atan(m))) + m * x1 + c && x1 < temp->gx2() - 5 && x1 > temp->gx1() + 5)
		{
			b++;
			break;
		}
		temp = temp->next.node;
	}

	if (b)
	{
		temp = fline;
		while (1)
		{
			//cout << 3;
			if (ismouseclick(WM_LBUTTONDOWN))
			{
				getmouseclick(WM_LBUTTONDOWN, x2, y2);

				if (x2 >= w - 300 && x2 <= w - 100 && y2 >= h - 100 && y2 <= h - 50)
					return;

				break;
			}

		}

		int c = 0;

		while (temp != NULL)
		{
			double m = temp->gy2() - temp->gy1();
			m /= (temp->gx2() - temp->gx1());
			double c = temp->gy1();
			c += temp->gx1()*(temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());

			if (y2 <= 5 * (cos(atan(m))) + m * x2 + c && y2 >= -5 * (cos(atan(m))) + m * x2 + c && x2 < temp->gx2() - 5 && x2 > temp->gx1() + 5)
			{
				c++;
				break;
			}
			temp = temp->next.node;
		}

		if (c)
		{
			send(Connection, (char*)&x1, sizeof(x1), NULL);
			send(Connection, (char*)&x2, sizeof(x2), NULL);
			send(Connection, (char*)&y1, sizeof(y1), NULL);
			send(Connection, (char*)&y2, sizeof(y2), NULL);
			recv(Connection, (char*)&fare, sizeof(fare), NULL);
		}
	}
}