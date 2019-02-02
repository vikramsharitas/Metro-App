#include"class.h"
//#include"fnc.h"

USER U;
char ps[20];
char uname[20],passwd[70],passwd1[70];

void first()
{
    begg:
    closegraph();
    initwindow(w, h);
    setbkcolor(WHITE);
    setcolor(BLACK);
    cleardevice();
    int x , y ,btn=0;
    readimagefile("Penguins.jpg",0,0,1400,700);
    //initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
    setcolor(BLACK);
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(150,10,"WELCOME TO THE METRO APP");
    settextstyle(4,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(400,80,"DO YOU HAVE A USER ID");
    setcolor(BLACK);
    settextstyle(4,HORIZ_DIR,2);
    rectangle(450,150,520,180);
    outtextxy(455, 155, "YES");
    rectangle(600,150,670,180);
    outtextxy(610, 155, "NO");
    char str1[100];
    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN))
            delay(0);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=450 && x<=520 && y>=150 && y<=180)
            btn=1;
        if(x>=600&& x<=670 && y>=150 && y<=180)
            btn=2;
        if (btn>0)
            break;
    }
    if (btn==1)
    {
        cleardevice();
        third();
        goto begg;
    }
    else
    {
        cleardevice();
        second();
        goto begg;
    }
}

void second()
{
    beg:
    closegraph();
    initwindow(w, h);
    setcolor(BLACK);
    setbkcolor(WHITE);
    cleardevice();
    int x , y ,btn=0;
    readimagefile("Tulips.jpg",0,0,1400,700);
    setcolor(BLACK);
    setbkcolor(WHITE);
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(150,10," CREATE ACCOUNT");
    settextstyle(4,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(150,80,"USER ID");
    outtextxy(150,120,"PASSWORD");
    outtextxy(150,160,"RE ENTER PASS WORD");
    TextBox(650,80, uname);
    PassWord(650,120,passwd);
    PassWord(650,160,passwd1);
    setcolor(BLACK);
    settextstyle(4,HORIZ_DIR,2);
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(450,195,540,225);
    fill(460, 200, GREEN);
    setbkcolor(GREEN);
    setcolor(WHITE);
    outtextxy(455, 200, "SAVE");
    setcolor(RED);
    setfillstyle(SOLID_FILL, RED);
    rectangle(600,195,740,225);
    fill(610, 200, RED);
    setbkcolor(RED);
    setcolor(WHITE);
    outtextxy(605, 200, "CANCEL");
    setbkcolor(WHITE);
    setcolor(BLACK);
    //char str1[100];
    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(500);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=450 && x<=540 && y>=190 && y<=220) btn=1;
        if(x>=600&& x<=735 && y>=190 && y<=220)  btn=2;
        if (btn>0) break;
    }
    if (btn==1)
    {
        USER U1;
        if(strcmp(passwd,passwd1)==0)
        {
            std::ifstream f_in("details.dat", std::ios::binary);
            f_in.seekg(0);
            int i=0;
            while(!f_in.eof())
            {
                f_in.read((char*)&U1, sizeof(U1));
                if(strcmp(uname, U1.user)==0)
                {
                    settextjustify(1, 1);
                    outtextxy(700,600,"Sorry! User Already Exists");
                    getch();
                    cleardevice();
                    goto beg;
                    i++;
                }
            }
            f_in.close();
            if(i==0)
            {
                std::ofstream fout("details.dat", std::ios::binary|std::ios::app);
                strcpy(U.user, uname);
                strcpy(U.pass, passwd);
                fout.write((char*)&U, sizeof(U));
                fout.close();
                cleardevice();
                fpage();
                return;
            }
        }
        else
        {
            outtextxy(700, 600, "Passwords do not match!");
            getch();
            cleardevice();
            goto beg;
        }
    }
    else
        return;
 }

void third()
{
    begi:
    closegraph();
    initwindow(w, h);
    setcolor(BLACK);
    setbkcolor(WHITE);
    cleardevice();
    int x , y ,btn=0;
    readimagefile("Lighthouse.jpg",0,0,1400,700);
    //initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
    setcolor(BLACK);
    settextstyle(4,HORIZ_DIR,5);
    outtextxy(150,10," USER LOGIN");
    settextstyle(4,HORIZ_DIR,3);
    setcolor(BLACK);
    outtextxy(150,80,"USER ID");
    outtextxy(150,120,"PASSWORD");
    TextBox(400,80, uname);
    PassWord(400,120,passwd);
    setcolor(BLACK);
    settextstyle(4,HORIZ_DIR,2);
    setcolor(GREEN);
    setbkcolor(GREEN);
    rectangle(450,153,560,183);
    fill(460, 160, GREEN);
    setcolor(WHITE);
    setbkcolor(GREEN);
    outtextxy(455, 158, "LOGIN");
    setcolor(RED);
    rectangle(600 ,153,740,183);
    fill(620, 160, RED);
    setcolor(WHITE);
    setbkcolor(RED);
    outtextxy(610, 158, "CANCEL");
    setcolor(BLACK);
    setbkcolor(WHITE);
    char str1[100];
    while(1)
    {
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(500);
        getmouseclick(WM_LBUTTONDOWN, x, y);
        if(x>=450 && x<=560 && y>=150 && y<=180)
            btn=1;
        if(x>=600&& x<=735 && y>=150 && y<=180)
            btn=2;
        if (btn>0)
            break;
    }
    if (btn==1)
    {
        int valid=0;
        char fff[20];
        USER U1;
        std::ifstream f_in("details.dat", std::ios::binary|std::ios::ate);
        f_in.seekg(0);
        while(!f_in.eof())
        {
            f_in.read((char*)&U1, sizeof(U1));
            if(strcmp(uname, U1.user)==0&&strcmp(passwd, U1.pass)==0)
            {
                valid=1;
                break;
            }
        }
        f_in.close();
        if(valid==1)
        {
            cleardevice();
            U=U1;
            fpage();
            return;
        }
        else
        {
            settextjustify(1, 1);
            outtextxy(w/2, 3*h/4, "Invalid username or password");
            settextjustify(LEFT_TEXT, 1);
            getch();
            cleardevice();
            goto begi;
        }
    }
    else
    {
        cleardevice();
        return;
    }
}

int poly[8];
int curposx,curposy;
int flag;
void TextBox(int x, int y, char str[20])
{
    setbkcolor(WHITE);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    strcpy(str, "");
    char ch;
    /* our polygon array */
    poly[0]=x-10;poly[1]=y-5;poly[2]=x+500;poly[3]=y-5;
    poly[4]=x+500;poly[5]=y+30;poly[6]=x-10;poly[7]=y+30;
    fillpoly(4, poly);
    ch=getch();
    int i=0;
    while(ch!=13&&i<20)
    {
        fillpoly(4, poly);
        if((int)ch!=8)
        {
            str[i]=toupper((char)ch);
            str[i+1]='\0';
            outtextxy(x,y,str);
            i++;
        }
        else if(ch==8&&i>=1)
        {
            str[i-1]='\0';
            setcolor(BLACK);
            outtextxy(x,y,str);
            setbkcolor(WHITE);
            setcolor(BLACK);
            i--;
        }
        ch=getch();
    }
    return ;
}
void PassWord(int x, int y,char str[70])
{
    setbkcolor(WHITE);
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, WHITE);
    strcpy(str,"");
    strcpy(ps,"");
    /* our polygon array */
    poly[0]=x-10;poly[1]=y-5;poly[2]=x+500;poly[3]=y-5;
    poly[4]=x+500;poly[5]=y+30;poly[6]=x-10;poly[7]=y+30;
    fillpoly(4, poly);
    settextjustify(LEFT_TEXT, TOP_TEXT);
    char ch=getch();
    int i=0;
    while(ch!=13&&i<20)
    {
        fillpoly(4, poly);
        if((int)ch!=8)
        {
            str[i]=(char)ch;
            ps[i]='*';
            str[i+1]='\0';
            ps[i+1]='\0';
            outtextxy(x,y,ps);
            i++;
        }
        else if(ch==8&&i>=1)
        {
            str[i-1]='\0';
            ps[i-1]='\0';
            setcolor(BLACK);
            outtextxy(x,y,ps);
            i--;
        }
        ch=getch();
    }
    SHA256(str);
    return ;
}
