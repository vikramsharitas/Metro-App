#define _WINSOCK_DEPRECATED_NO_WARNINGS

#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include"functions.h"
#include"class.h"
#include"fnc.h"

void map_edit()
{
	lin *fline, *temp5;
	fline = NULL;
	temp5 = fline;
	lin tri;
	station tr1;
	fstream lines, stations;
	//lines.open("lines.dat", ios::out | ios::binary);
	//lines.close();
	lines.open("lines.dat", ios::in | ios::binary);
	//lines.seekg(0);
	//lines.seekg(0 + sizeof(tri));
	if (lines.is_open())
	{
		if (!lines.eof())
		{
			lines.read((char*)&(tri), sizeof(tri));
			fline = new lin;
			temp5 = fline;
			temp5->next.node = NULL;
			temp5->prev.node = NULL;
			int f = 0, g = 0, h = 0, i = 0, j = 0;
			f = tri.gcol();
			g = tri.gx1();
			h = tri.gx2();
			i = tri.gy1();
			j = tri.gy2();
			cout << "\n" << f << " " << g << " " << h << " " << i << " " << j << endl;
			temp5->lind(tri.n, tri.num, f, g, h, i, j);

			cout << 3;

			char fname[20];
			_itoa(tri.num, fname, 10);
			strcat(fname, ".dat");
			cout << "\n" << "1st flie" << fname << endl;
			//stations.open(fname, ios::out | ios::binary);
			//stations.close();
			stations.open(fname, ios::in | ios::binary);
			//stations.seekg(0);
			//stations.seekg(0 + sizeof(tr1));
			temp5->first = NULL;
			station *temp2;
			temp5->first = NULL;
			temp2 = temp5->first;

			int r = 0;
            if(stations.is_open())
            {
                if (!stations.eof())
                {
                    stations.read((char*)&(tr1), sizeof(tr1));
                    temp5->first = new station(tr1.x, tr1.y, tr1.inter, tr1.name);
                    temp2 = temp5->first;
                    temp2->next.node = NULL;
                    temp2->prev.node = NULL;
                    cout << 4;
                }

                while (!stations.eof())
                {
                    r++;
                    int t = 0;
                    stations.read((char*)&(tr1), sizeof(tr1));
                    temp2 = temp5->first;
                    while (temp2 != NULL)
                    {
                        if (temp2->x == tr1.x)
                        {
                            t++;
                            break;
                        }
                        temp2 = temp2->next.node;
                    }

                    //cout << 6 << endl;
                    temp2 = temp5->first;

                    while (temp2->next.node != NULL)
                        temp2 = temp2->next.node;

                    cout << t << " " << 39876 << endl;

                    if(!t)
                    {
                        temp2->next.node = new station(tr1.x, tr1.y, tr1.inter, tr1.name);
                        station *temp3 = temp2;
                        temp2 = temp2->next.node;
                        temp2->prev.node = temp3;
                        temp3->next.node = temp2;
                        temp2->next.node = NULL;
                        cout << 5;
                    }

                }
            }
			stations.close();
			if (r == 0)
			{
				temp5->first = NULL;
				fline=NULL;
			}
			if (r == 1)
			{
				fline=NULL;
			}
		}
		int q = 0;
		while (!lines.eof()&&fline!=NULL)
		{
			q++;
			//tri = NULL;
			cout<<2<<endl;
			lines.read((char*)&(tri), sizeof(tri));
			temp5 = fline;
			int w = 0;
			while (temp5 != NULL)
			{
				if (temp5->num == tri.num)
				{
					w++;
					break;
				}
				temp5 = temp5->next.node;
			}
			//cout<<"\n"<<tri.num<<endl;
			temp5 = fline;
			cout << 2;
			while (temp5->next.node != NULL)
				temp5 = temp5->next.node;

			if (!w)
			{
				cout << 1;
				temp5->next.node = new lin;
				int f = 0, g = 0, h = 0, i = 0, j = 0;
				f = tri.gcol();
				g = tri.gx1();
				h = tri.gx2();
				i = tri.gy1();
				j = tri.gy2();
				temp5->next.node->lind(tri.n, tri.num, f, g, h, i, j);
				lin *temp1 = temp5;
				temp5 = temp5->next.node;
				temp5->prev.node = temp1;
				temp1->next.node = temp5;
				temp5->next.node = NULL;
				char fname[20];
				_itoa(tri.num, fname, 10);
				strcat(fname, ".dat");
				cout << "\n" << fname << endl;
				//stations.open(fname, ios::out | ios::binary);
				//stations.close();
				stations.open(fname, ios::in | ios::binary);
				//stations.seekg(0);
				//stations.seekg(0 + sizeof(tr1));
				temp5->first = NULL;
				station *temp2 = temp5->first;
				int r = 0;
                if(stations.is_open())
                {
                    if (!stations.eof())
                    {
                        stations.read((char*)&(tr1), sizeof(tr1));
                        temp5->first = new station(tr1.x, tr1.y, tr1.inter, tr1.name);
                        temp2 = temp5->first;
                        temp2->next.node = NULL;
                        temp2->prev.node = NULL;
                    }

                    while (!stations.eof())
                    {
                        r++;
                        int t = 0;
                        stations.read((char*)&(tr1), sizeof(tr1));
                        temp2 = temp5->first;
                        while (temp2 != NULL)
                        {
                            if (temp2->x == tr1.x)
                            {
                                t++;
                                break;
                            }
                            temp2 = temp2->next.node;
                        }

                        temp2 = temp5->first;

                        while (temp2->next.node != NULL)
                            temp2 = temp2->next.node;

                        if (!t)
                        {
                            temp2->next.node = new station(tr1.x, tr1.y, tr1.inter, tr1.name);
                            station *temp3 = temp2;
                            temp2 = temp2->next.node;
                            temp2->prev.node = temp3;
                            temp3->next.node = temp2;
                            temp2->next.node = NULL;
                            cout << 5;
                        }

                    }
                }
				stations.close();
				if (r == 0)
				{
					temp5->first = NULL;
				}
				if(r<2)
                    fline=NULL;
			}
		}
		lines.close();
		if (q == 0)
		{
			fline = NULL;
			if (fline == NULL)
			{
				cout << "I AM A FOOL" << endl;
			}
		}
	}

	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0)
	{
		std::cout<<"\n"<<"Winsock startup failed\nError"<<std::endl;
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
		std::cout<<" \n"<<"Failed to Connect\nError"<<std::endl;
		return;
	}
	std::cout << "Connected!" << std::endl;
	mill:
	setbkcolor(WHITE);
	setcolor(BLACK);
	cleardevice();
    settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w / 2 - 375, h / 2, "ADD LINE");
	outtextxy(w / 2 - 125, h / 2, "ADD STATION");
	outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
	outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
	outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
	outtextxy(w / 2, h / 2 + 400, "FARES");
	outtextxy(w - 200, h - 75, "BACK");

	int x = 0, y = 0, btn = 0;
	while (1)
	{
		while (1)
		{
			if (ismouseclick(WM_LBUTTONDOWN))
			{
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

		if (btn == 1)
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
			outtextxy(w / 2, h / 2 + 400, "FARES");
            outtextxy(w - 200, h - 75, "BACK");
		}
		else if (btn == 2)
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
					{
						int run = -1;
						send(Connection, (char*)&run, sizeof(run), NULL);
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						lines.close();
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						temp5 = fline;
						while (temp5 != NULL)
						{
							tri = *temp5;
							//cout << tri.num <<endl;

							char fname[20];

							_itoa(temp5->num, fname, 10);
							strcat(fname, ".dat");

							stations.open(fname, ios::out | ios::binary | ios::trunc);
							station *temp7;
							temp7 = temp5->first;
							int i = 0;
							while (temp7 != NULL)
							{
								tr1 = *temp7;
								i++;
								stations.write((char*)&(tr1), sizeof(tr1));
								temp7 = temp7->next.node;
							}
							stations.close();
							//cout << 9;
							if (i >= 2)
								lines.write((char*)&(tri), sizeof(tri));

							temp5 = temp5->next.node;
						}
						lines.close();
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
			outtextxy(w / 2, h / 2 + 400, "FARES");
            outtextxy(w - 200, h - 75, "BACK");
		}
		else if (btn == 3)
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
			outtextxy(w / 2, h / 2 + 400, "FARES");
            outtextxy(w - 200, h - 75, "BACK");
		}
		else if (btn == 4)
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
					{
						int run = -1;
						send(Connection, (char*)&run, sizeof(run), NULL);
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						lines.close();
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						temp5 = fline;
						while (temp5 != NULL)
						{
							tri = *temp5;
							//cout << tri.num <<endl;

							char fname[20];

							_itoa(temp5->num, fname, 10);
							strcat(fname, ".dat");

							stations.open(fname, ios::out | ios::binary | ios::trunc);
							station *temp7;
							temp7 = temp5->first;
							int i = 0;
							while (temp7 != NULL)
							{
								tr1 = *temp7;
								i++;
								stations.write((char*)&(tr1), sizeof(tr1));
								temp7 = temp7->next.node;
							}
							stations.close();
							//cout << 9;
							if (i >= 2)
								lines.write((char*)&(tri), sizeof(tri));

							temp5 = temp5->next.node;
						}
						lines.close();
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
			outtextxy(w / 2, h / 2 + 400, "FARES");
            outtextxy(w - 200, h - 75, "BACK");
		}
		else if (btn == 5)
		{
			int run = 1;
			char prog = 'm';
			send(Connection, (char*)&run, sizeof(run), NULL);
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
						//cout << " " << 5 << endl;
					}
					cout << " " << 3 << endl;
				} while (x3 != 0 && y3 != 0 && x4 != 0 && y4 != 0);
				temp5 = temp5->next.node;
			}
			cout << " " << 0 << endl;
			x1 = x2 = y1 = y2 = 0;
			send(Connection, (char*)&x1, sizeof(x1), NULL);
			cout << " " << 1 << endl;
			send(Connection, (char*)&x2, sizeof(x2), NULL);
			cout << " " << 2 << endl;
			send(Connection, (char*)&y1, sizeof(y1), NULL);
			cout << " " << 3 << endl;
			send(Connection, (char*)&y2, sizeof(y2), NULL);
			cout << " " << 4 << endl;

			outtextxy(w - 200, h - 75, "BACK");
			while (1)
            {
				getmouseclick(WM_LBUTTONDOWN, x, y);
				if (x >= w - 300 && x <= w - 100 && y <= h - 25 && y >= h - 125)
				{
					int run = -1;
					send(Connection, (char*)&run, sizeof(run), NULL);
					lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
					lines.close();
					lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
					temp5 = fline;
					while (temp5 != NULL)
					{
						tri = *temp5;
						//cout << tri.num <<endl;

						char fname[20];

						_itoa(temp5->num, fname, 10);
						strcat(fname, ".dat");

						stations.open(fname, ios::out | ios::binary | ios::trunc);
						station *temp7;
						temp7 = temp5->first;
						int i = 0;
						while (temp7 != NULL)
						{
							tr1 = *temp7;
							i++;
							stations.write((char*)&(tr1), sizeof(tr1));
							temp7 = temp7->next.node;
						}
						stations.close();
						//cout << 9;
						if (i >= 2)
							lines.write((char*)&(tri), sizeof(tri));

						temp5 = temp5->next.node;
					}
					lines.close();
					return;
				}
            }

            cleardevice();
            settextjustify(CENTER_TEXT, VCENTER_TEXT);
            outtextxy(w / 2 - 375, h / 2, "ADD LINE");
            outtextxy(w / 2 - 125, h / 2, "ADD STATION");
            outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
            outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
            outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
			outtextxy(w / 2, h / 2 + 400, "FARES");
            outtextxy(w - 200, h - 75, "BACK");
		}
		else if (btn == 6)
		{
			int run = 0;
			send(Connection, (char*)&run, sizeof(run), NULL);
			break;
		}

		else if (btn == 7)
		{
			int run = 1;
			char f = 'f';
			send(Connection, (char*)&run, sizeof(run), NULL);
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
			mall:
			outtextxy(w - 200, h - 75, "BACK");
			while (1)
			{
				//cout << 3;
				outtextxy(w / 2, 75, "PLEASE CHOOSE STATION 1");
				if (ismouseclick(WM_LBUTTONDOWN))
				{
					getmouseclick(WM_LBUTTONDOWN, x1, y1);

					if (x1 >= w - 300 && x1 <= w - 100 && y1 >= h - 100 && y1 <= h - 50)
					{
						int run = -1;
						send(Connection, (char*)&run, sizeof(run), NULL);
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						lines.close();
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						temp5 = fline;
						while (temp5 != NULL)
						{
							tri = *temp5;
							//cout << tri.num <<endl;

							char fname[20];

							_itoa(temp5->num, fname, 10);
							strcat(fname, ".dat");

							stations.open(fname, ios::out | ios::binary | ios::trunc);
							station *temp7;
							temp7 = temp5->first;
							int i = 0;
							while (temp7 != NULL)
							{
								tr1 = *temp7;
								i++;
								stations.write((char*)&(tr1), sizeof(tr1));
								temp7 = temp7->next.node;
							}
							stations.close();
							//cout << 9;
							if (i >= 2)
								lines.write((char*)&(tri), sizeof(tri));

							temp5 = temp5->next.node;
						}
						lines.close();
						return;
					}

					break;
				}

			}

			int n = 0;
			double m = 0, c = 0;

			temp = fline;

			while (temp != NULL)
			{
				m = temp->gy2() - temp->gy1();
				m /= (temp->gx2() - temp->gx1());
				c = temp->gy1();
				c += temp->gx1()*(temp->gy1() - temp->gy2()) / (temp->gx2() - temp->gx1());
				cout << m << endl;
				cout << "\n" << x1 << " " << y1 << " " << 5 * (cos(atan(m))) + m * x1 + c << " " << -5 * (cos(atan(m))) + m * x1 + c << " " << temp->gx2() + 5 << " " << temp->gx1() - 5 << endl;

				if (y1 <= 10 * (cos(atan(m))) + m * x1 + c && y1 >= -10 * (cos(atan(m))) + m * x1 + c && x1 < temp->gx2() + 10 && x1 > temp->gx1() - 10)
				{
					cout << m << endl;
					station* temp1 = temp->first;

					while (temp1 != NULL)
					{
						if (temp1->x < x1 + 10 && temp1->x > x1 - 10 && temp1->y > y1 - 10 && temp1->y < y1 + 10)
						{
							n++;
							break;
						}												
						temp1 = temp1->next.node;

					}
					if (n)
						break;
				}
				temp = temp->next.node;
			}

			cout << n << endl;

			if (n)
			{
				cout << "hell";
			hell:
				outtextxy(w / 2, 75, "PLEASE CHOOSE STATION 2 ON THE SAME LINE");
				while (1)
				{
					//cout << 3;
					if (ismouseclick(WM_LBUTTONDOWN))
					{
						getmouseclick(WM_LBUTTONDOWN, x2, y2);

						if (x2 >= w - 300 && x2 <= w - 100 && y2 >= h - 125 && y2 <= h - 25)
						{
							int run = -1;
							send(Connection, (char*)&run, sizeof(run), NULL);
							lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
							lines.close();
							lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
							temp5 = fline;
							while (temp5 != NULL)
							{
								tri = *temp5;
								//cout << tri.num <<endl;

								char fname[20];

								_itoa(temp5->num, fname, 10);
								strcat(fname, ".dat");

								stations.open(fname, ios::out | ios::binary | ios::trunc);
								station *temp7;
								temp7 = temp5->first;
								int i = 0;
								while (temp7 != NULL)
								{
									tr1 = *temp7;
									i++;
									stations.write((char*)&(tr1), sizeof(tr1));
									temp7 = temp7->next.node;
								}
								stations.close();
								//cout << 9;
								if (i >= 2)
									lines.write((char*)&(tri), sizeof(tri));

								temp5 = temp5->next.node;
							}
							lines.close();
							return;
						}

						break;
					}

				}
				cout << "\n" << m << " " << c << endl;
				int d = 0;
				cout << "\n" << x2 << " " << y2 << " " << 5 * (cos(atan(m))) + m * x2 + c << " " << -5 * (cos(atan(m))) + m * x2 + c << " " << temp->gx2() + 5 << " " << temp->gx1() - 5 << endl;
				if (y2 <= 10 * (cos(atan(m))) + m * x2 + c && y2 >= -10 * (cos(atan(m))) + m * x2 + c && x2 <= temp->gx2() + 10 && x2 >= temp->gx1() - 10)
				{
					cout << "\n" << 1 << endl;
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

					if (d == 2)
					{
						//cout << "hello2" << endl;
					}
				}

				//cout << d << endl;

				if (d)
				{
					//cout << "hello";
					send(Connection, (char*)&x1, sizeof(x1), NULL);
					send(Connection, (char*)&x2, sizeof(x2), NULL);
					send(Connection, (char*)&y1, sizeof(y1), NULL);
					send(Connection, (char*)&y2, sizeof(y2), NULL);
					//cout << "hello1";
					recv(Connection, (char*)&fare, sizeof(fare), NULL);
					setfillstyle(1, WHITE);
					bar(0, 0, w, 125);
					outtextxy(w / 2, 75, "FARE");
					char tot[4] = {};
					_itoa(fare, tot, 10);
					outtextxy(w / 2 + 400, 75, tot);
					cout << fare;
				}
				else
					goto hell;
			}

			else 
				goto mall;

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
					int run = -1;
					send(Connection, (char*)&run, sizeof(run), NULL);
					lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
					lines.close();
					lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
					temp5 = fline;
					while (temp5 != NULL)
					{
						tri = *temp5;
						//cout << tri.num <<endl;

						char fname[20];

						_itoa(temp5->num, fname, 10);
						strcat(fname, ".dat");

						stations.open(fname, ios::out | ios::binary | ios::trunc);
						station *temp7;
						temp7 = temp5->first;
						int i = 0;
						while (temp7 != NULL)
						{
							tr1 = *temp7;
							i++;
							stations.write((char*)&(tr1), sizeof(tr1));
							temp7 = temp7->next.node;
						}
						stations.close();
						//cout << 9;
						if (i >= 2)
							lines.write((char*)&(tri), sizeof(tri));

						temp5 = temp5->next.node;
					}
					lines.close();
					return;
				}
				else if (x >= 3 * w / 4 - 100 && x <= 3 * w / 4 + 100 && y >= h - 125 && y <= h - 25)
				{
					int run = -1;
					send(Connection, (char*)&run, sizeof(run), NULL);
					lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
					lines.close();
					lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
					temp5 = fline;
					while (temp5 != NULL)
					{
						tri = *temp5;
						//cout << tri.num <<endl;

						char fname[20];

						_itoa(temp5->num, fname, 10);
						strcat(fname, ".dat");

						stations.open(fname, ios::out | ios::binary | ios::trunc);
						station *temp7;
						temp7 = temp5->first;
						int i = 0;
						while (temp7 != NULL)
						{
							tr1 = *temp7;
							i++;
							stations.write((char*)&(tr1), sizeof(tr1));
							temp7 = temp7->next.node;
						}
						stations.close();
						//cout << 9;
						if (i >= 2)
							lines.write((char*)&(tri), sizeof(tri));

						temp5 = temp5->next.node;
					}
					lines.close();
					return;
				}
				else if (x >= w / 4 - 100 && x <= w / 4 + 100 && y >= h - 125 && y <= h - 25)
				{
					U.transa(-1*(int)fare);
					std::ifstream f1("details.dat", std::ios::binary);
					f1.seekg(0);
					std::ofstream f2("temp.dat", std::ios::binary);
					USER U1, U2;
					f1.read((char*)&U1, sizeof(U1));
					while (!f1.eof() && strcmp(U1.user, U2.user) != 0)
					{
						U2 = U1;
						if (strcmp(U1.user, U.user) == 0)
						{
							f2.write((char*)&U, sizeof(U));
						}

						else
							f2.write((char*)&U1, sizeof(U1));

						f1.read((char*)&U1, sizeof(U1));
					}
					f1.close();
					f2.close();
					remove("details.dat");
					rename("temp.dat", "details.dat");
					{
						int run = -1;
						send(Connection, (char*)&run, sizeof(run), NULL);
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						lines.close();
						lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
						temp5 = fline;
						while (temp5 != NULL)
						{
							tri = *temp5;
							//cout << tri.num <<endl;

							char fname[20];

							_itoa(temp5->num, fname, 10);
							strcat(fname, ".dat");

							stations.open(fname, ios::out | ios::binary | ios::trunc);
							station *temp7;
							temp7 = temp5->first;
							int i = 0;
							while (temp7 != NULL)
							{
								tr1 = *temp7;
								i++;
								stations.write((char*)&(tr1), sizeof(tr1));
								temp7 = temp7->next.node;
							}
							stations.close();
							//cout << 9;
							if (i >= 2)
								lines.write((char*)&(tri), sizeof(tri));

							temp5 = temp5->next.node;
						}
						lines.close();
						return;
					}
				}
			}
			{
			int run = -1;
			send(Connection, (char*)&run, sizeof(run), NULL);
			lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
			lines.close();
			lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
			temp5 = fline;
			while (temp5 != NULL)
			{
				tri = *temp5;
				//cout << tri.num <<endl;

				char fname[20];

				_itoa(temp5->num, fname, 10);
				strcat(fname, ".dat");

				stations.open(fname, ios::out | ios::binary | ios::trunc);
				station *temp7;
				temp7 = temp5->first;
				int i = 0;
				while (temp7 != NULL)
				{
					tr1 = *temp7;
					i++;
					stations.write((char*)&(tr1), sizeof(tr1));
					temp7 = temp7->next.node;
				}
				stations.close();
				//cout << 9;
				if (i >= 2)
					lines.write((char*)&(tri), sizeof(tri));

				temp5 = temp5->next.node;
			}
			lines.close();
			return;
				}
		}
	}

	lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
	lines.close();
	lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
	temp5 = fline;
	while (temp5 != NULL)
	{
		tri = *temp5;
		//cout << tri.num <<endl;

		char fname[20];

		_itoa(temp5->num, fname, 10);
		strcat(fname, ".dat");

		stations.open(fname, ios::out | ios::binary | ios::trunc);
		station *temp7;
		temp7 = temp5->first;
		int i=0;
		while (temp7 != NULL)
		{
			tr1 = *temp7;
			i++;
			stations.write((char*)&(tr1), sizeof(tr1));
			temp7 = temp7->next.node;
		}
		stations.close();
		//cout << 9;
		if(i>=2)
		lines.write((char*)&(tri), sizeof(tri));

		temp5 = temp5->next.node;
	}
	lines.close();

	//cout << 1 <<endl;
}
