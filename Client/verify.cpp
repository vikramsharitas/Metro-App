#include"maps.h"
#include"class.h"

int verify(int x1, int y1, lin *temp, double m, double c)
{
	int n = 0;
	if (y1 <= 10 * (cos(atan(m))) + m * x1 + c && y1 >= -10 * (cos(atan(m))) + m * x1 + c && x1 < temp->gx2() + 10 && x1 > temp->gx1() - 10)
	{
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
	}
		return n;
}