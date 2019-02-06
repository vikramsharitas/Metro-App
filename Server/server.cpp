#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include<math.h>
#include<time.h>
int addrlen;

void fares();
void map();

SOCKET newConnection;

int main()
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) 
	{
		std::cout << "WinSock startup failed\nError" << std::endl;
		return 0;
	}

	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	while (1)
	{
		newConnection = accept(sListen, NULL, NULL);
		if (newConnection == 0)
		{
			std::cout << "Failed to accept the client's connection." << std::endl;
		}

		else
		{
			char prog;
			recv(newConnection, (char*)&prog, sizeof(prog), NULL);
			if (prog == 'f')
			{
				fares();
			}
			else if (prog == 'm')
			{
				map();
			}
		}
	}
	return 0;
}

void fares()
{
	double total = 0;
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	recv(newConnection, (char*)&x1, sizeof(x1), NULL);
	if (x1 == -1)
	{
		return;
	}
	recv(newConnection, (char*)&x2, sizeof(x2), NULL);
	recv(newConnection, (char*)&y1, sizeof(y1), NULL);
	recv(newConnection, (char*)&y2, sizeof(y2), NULL);
	total = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	total /= 25;
	total += 10;
	send(newConnection, (char*)&total, sizeof(total), NULL);
}

void map()
{
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
	recv(newConnection, (char*)&x1, sizeof(x1), NULL);
	if (x1 == -1)
	{
		return;
	}
	recv(newConnection, (char*)&x2, sizeof(x2), NULL);
	recv(newConnection, (char*)&y1, sizeof(y1), NULL);
	recv(newConnection, (char*)&y2, sizeof(y2), NULL);
	while (x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0)
	{
		double m = y2 - y1;
		if (x1 != x2)
		{
			m /= (x2 - x1);
		}
		else m = 0;
		time_t t = _time64(NULL);
		long int time = (long int)t;
		time = time % 600;
		if (x2 != x1)
		{
			y3 = time * 0.3672 * sin(atan(m)) + y1;
			x3 = time * 0.3672 * cos(atan(m)) + x1;
			y4 = y2 - time * 0.3672 * sin(atan(m));
			x4 = x2 - time * 0.3672 * cos(atan(m));
		}
		else
		{
			x3 = x4 = x1;
			y4 = y2 - time * 0.3672;
			x4 = x2 - time * 0.3672;
		}
		while (x3 < x2 && x3 > x1 && x4 <x2 && x4 > x1)
		{
			send(newConnection, (char*)&x3, sizeof(x3), NULL);
			send(newConnection, (char*)&y3, sizeof(y3), NULL);
			send(newConnection, (char*)&x4, sizeof(x4), NULL);
			send(newConnection, (char*)&y4, sizeof(y4), NULL);
			time += 600;
			if (x2 != x1)
			{
				y3 = time * 0.3672 * sin(atan(m)) + y1;
				x3 = time * 0.3672 * cos(atan(m)) + x1;
				y4 = y2 - time * 0.3672 * sin(atan(m));
				x4 = x2 - time * 0.3672 * cos(atan(m));
			}
			else
			{
				x3 = x4 = x1;
				y4 = y2 - time * 0.3672;
				x4 = x2 - time * 0.3672;
			}
		}
		x3 = y3 = x4 = y4 = 0;
		send(newConnection, (char*)&x3, sizeof(x3), NULL);
		send(newConnection, (char*)&y3, sizeof(y3), NULL);
		send(newConnection, (char*)&x4, sizeof(x4), NULL);
		send(newConnection, (char*)&y4, sizeof(y4), NULL);
		recv(newConnection, (char*)&x1, sizeof(x1), NULL);
		if (x1 == -1)
		{
			return;
		}
		recv(newConnection, (char*)&x2, sizeof(x2), NULL);
		recv(newConnection, (char*)&y1, sizeof(y1), NULL);
		recv(newConnection, (char*)&y2, sizeof(y2), NULL);
	}
}