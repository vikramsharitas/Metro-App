#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include<math.h>
#include<time.h>
#include<process.h>

int main()
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) 
	{
		MessageBoxA(NULL, "WinSock startup failed", "Error", MB_OK | MB_ICONERROR);
		return 0;
	}

	SOCKADDR_IN addr;
	int addrlen = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;
	int con = 0;
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &addrlen);
	if (newConnection == 0)
	{
		std::cout << "Failed to accept the client's connection." << std::endl;
	}
	else
	{
		char prog;
		int run = 0;
		recv(newConnection, (char*)&run, sizeof(run), NULL);
		if (run == -1)
		{
			exit(0);
		}
		while (run == 1)
		{
			recv(newConnection, (char*)&prog, sizeof(prog), NULL);
			if ((int)prog == -1)
			{
				exit(0);
			}
			if (prog == 'f')
			{
				double total = 0;
				int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
				recv(newConnection, (char*)&x1, sizeof(x1), NULL);
				if (x1 == -1)
				{
					exit(0);
				}
				recv(newConnection, (char*)&x2, sizeof(x2), NULL);
				if (x2 == -1)
				{
					exit(0);
				}
				recv(newConnection, (char*)&y1, sizeof(y1), NULL);
				if (y1 == -1)
				{
					exit(0);
				}
				recv(newConnection, (char*)&y2, sizeof(y2), NULL);
				if (y2 == -1)
				{
					exit(0);
				}
				std::cout << x1 << " " << x2 << " " << y1 << " " << y2 << std::endl;
				total = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
				total /= 25;
				total += 10;
				std::cout << "\n" << total;
				send(newConnection, (char*)&total, sizeof(total), NULL);
			}

			else if (prog == 'm')
			{
				int x1 = 0, y1 = 0, x2 = 0, y2 = 0, x3 = 0, y3 = 0, x4 = 0, y4 = 0;
				do{
					recv(newConnection, (char*)&x1, sizeof(x1), NULL);
					if (x1 == -1)
					{
						exit(0);
					}
					recv(newConnection, (char*)&x2, sizeof(x2), NULL);
					if (x2 == -1)
					{
						exit(0);
					}
					recv(newConnection, (char*)&y1, sizeof(y1), NULL);
					if (y1 == -1)
					{
						exit(0);
					}
					recv(newConnection, (char*)&y2, sizeof(y2), NULL);
					if (y2 == -1)
					{
						exit(0);
					}
					double m = y2 - y1;
					if (x1 != x2)
					{
						m /= (x2 - x1);
					}
					else m = 0;
					
					std::cout << m;
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
						std::cout << 1;
						send(newConnection, (char*)&x3, sizeof(x3), NULL);
						send(newConnection, (char*)&y3, sizeof(y3), NULL);
						send(newConnection, (char*)&x4, sizeof(x4), NULL);
						send(newConnection, (char*)&y4, sizeof(y4), NULL);
						std::cout << 1;
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
				} while (x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0);
				
			}

			recv(newConnection, (char*)&run, sizeof(run), NULL);
			if (run == -1)
			{
				exit(0);
			}
		}
	}

	return 0;
}