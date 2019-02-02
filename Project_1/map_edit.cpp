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

	setbkcolor(WHITE);
	setcolor(BLACK);
	cleardevice();
    settextjustify(CENTER_TEXT, VCENTER_TEXT);
	outtextxy(w / 2 - 375, h / 2, "ADD LINE");
	outtextxy(w / 2 - 125, h / 2, "ADD STATION");
	outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
	outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
	outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
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
                temp->delete_station();
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
		else if (btn == 5)
		{
			temp5 = fline;
            cleardevice();
            while (temp5 != NULL)
            {
                temp5->draw_line();
                temp5 = temp5->next.node;
            }

            while (1)
            {
                if(kbhit())
                    break;
            }

            cleardevice();
            /*settextjustify(CENTER_TEXT, VCENTER_TEXT);
            outtextxy(w / 2 - 375, h / 2, "ADD LINE");
            outtextxy(w / 2 - 125, h / 2, "ADD STATION");
            outtextxy(w / 2 + 125, h / 2, "DELETE LINE");
            outtextxy(w / 2 + 375, h / 2, "DELETE STATION");
            outtextxy(w / 2, h / 2 + 200, "VIEW MAP");
            outtextxy(w - 200, h - 75, "BACK");*/
            break;
		}
		else if (btn == 6)
		{
			break;
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
		cout << 9;
		if(i>=2)
		lines.write((char*)&(tri), sizeof(tri));

		temp5 = temp5->next.node;
	}
	lines.close();

	//cout << 1 <<endl;
}
