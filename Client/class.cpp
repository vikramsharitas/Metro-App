#include"class.h"
void USER::transa(double i)
{
	bal = bal + i;
	if (bal < 0)
	{
		cleardevice();
		outtextxy(w / 2, h / 2, "Invalid Transaction!");
		outtextxy(w / 2, 75, "PRESS ANY KEY TO CONTINUE");
		getch();
		bal -= i;
		return;
	}
	if (first == NULL)
	{
		cleardevice();
		outtextxy(w / 2, h / 2, "Transaction Complete!");
		outtextxy(w / 2, 75, "PRESS ANY KEY TO CONTINUE");
		getch();
		first = new trans;
		first->tran = i;
		first->next = NULL;
	}
	else
	{
		cleardevice();
		outtextxy(w / 2, h / 2, "Transaction Complete!");
		outtextxy(w / 2, 75, "PRESS ANY KEY TO CONTINUE");
		getch();
		trans *temp = new trans;
		temp->tran = i;
		temp->next = first;
		first = temp;
	}
}

USER::USER()
{

	bal = 0.0;
	strcpy(user, "");
	strcpy(pass, "");
}

double USER::returnbal()
{
	return bal;
}

void USER::bye()
{
	bal = NULL;
	strcpy(pass, "");
	strcpy(user, "");
	first = NULL;
}