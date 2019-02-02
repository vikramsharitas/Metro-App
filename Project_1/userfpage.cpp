#include"class.h"
#include"fnc.h"

void fpage()
{
    begg:
    closegraph();
    initwindow(w, h);
    settextstyle(4, 0, 2);
    setbkcolor(WHITE);
    setcolor(BLACK);
    cleardevice();
    settextjustify(1,1);
    //outtextxy(w/2,h/2-30,"FARES");
    outtextxy(w/2,h/2+30,"RECHARGE");
    outtextxy(w/2,h/2+90,"MAPS");
    outtextxy(w/2, h/10, U.user);
    outtextxy(w/2, h/2+210, "LOGOUT");
    char bal[20];
    sprintf(bal, "%f", U.returnbal());
    outtextxy(w/2, h/10+50, bal);
    int btn;
    btn=0;
    while(1)
    {
        int x, y;
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(500);
			getmouseclick(WM_LBUTTONDOWN, x, y);
        /*if(x>=w/2-100&& x<=w/2+100 && y>=h/2-55 && y<=h/2-5)
            btn=2;*/
        if(x>=w/2-100 && x<=w/2+100 && y>=h/2+5 && y<=h/2+55)
            btn=3;
        if(x>=w/2-100&& x<=w/2+100 && y>=h/2+65 && y<=h/2+115)
            btn=4;
        if(x>=w/2-100&&x<=w/2+100&&y>=h/2+185&&y<=h/2+265)
            btn=6;
        if (btn>0)
            break;
    }
    if(btn==2)
        {
            //fares();
            goto begg;
        }
    else if(btn==3)
        {
            rech();
            goto begg;
        }
    else if(btn==4)
    {
        map_edit();
        goto begg;
    }
    else if(btn==6)
    {
        closegraph();
        U.bye();
        return;
    }
}
