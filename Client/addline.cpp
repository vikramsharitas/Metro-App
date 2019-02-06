#include <WinSock2.h>
#include"class.h"
#include"maps.h"

void addline()
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
}