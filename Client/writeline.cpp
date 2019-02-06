#include"class.h"
#include"maps.h"

void write_line()
{
	fstream lines, stations;
	lin tri;
	station tr1;
	lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
	lines.close();
	lines.open("lines.dat", ios::out | ios::binary | ios::trunc);
	temp5 = fline;
	while (temp5 != NULL)
	{
		tri = *temp5;

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
		if (i >= 2)
			lines.write((char*)&(tri), sizeof(tri));

		temp5 = temp5->next.node;
	}
	lines.close();
}