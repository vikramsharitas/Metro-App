#include"maps.h"
#include"class.h"

void write_transa(int fare)
{
	U.transa(-1 * (int)fare);
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
}