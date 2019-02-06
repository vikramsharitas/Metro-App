#include"maps.h"
#include"class.h"
void read_line()
{
	lin tri;
	station tr1;
	fstream lines, stations;
	lines.open("lines.dat", ios::in | ios::binary);
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
			temp5->lind(tri.n, tri.num, f, g, h, i, j);

			char fname[20];
			_itoa(tri.num, fname, 10);
			strcat(fname, ".dat");
			stations.open(fname, ios::in | ios::binary);
			temp5->first = NULL;
			station *temp2;
			temp5->first = NULL;
			temp2 = temp5->first;

			int r = 0;
			if (stations.is_open())
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
					}

				}
			}
			stations.close();
			if (r == 0)
			{
				temp5->first = NULL;
				fline = NULL;
			}
			if (r == 1)
			{
				fline = NULL;
			}
		}
		int q = 0;
		while (!lines.eof() && fline != NULL)
		{
			q++;
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
			temp5 = fline;
			while (temp5->next.node != NULL)
				temp5 = temp5->next.node;

			if (!w)
			{
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
				stations.open(fname, ios::in | ios::binary);
				temp5->first = NULL;
				station *temp2 = temp5->first;
				int r = 0;
				if (stations.is_open())
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
						}

					}
				}
				stations.close();
				if (r == 0)
				{
					temp5->first = NULL;
				}
				if (r < 2)
					fline = NULL;
			}
		}
		lines.close();
		if (q == 0)
		{
			fline = NULL;
			if (fline == NULL)
			{
			}
		}
	}
}