#include"class.h"
#include"maps.h"

void delline()
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
}