#include"class.h"
//#include"functions.h"

void rech()
{
    cleardevice();
    setcolor(BLACK);
    setbkcolor(WHITE);
    char c1[20];int f=0;
    settextjustify(CENTER_TEXT, 1);
    settextstyle(0, 0, 8);
    outtextxy(w/2, h/4, "Recharge Amount");
    settextstyle(0, 0, 3);
char ch=0;
    int i=0;
    strcpy(c1, "");
    while(ch!=13&&i<20)
    {
        ch=getch();
        outtextxy(w/2, h/2, c1);
        if((int)ch!=8)
        {
            c1[i]=toupper((char)ch);
            c1[i+1]='\0';
            outtextxy(w/2,h/2,c1);
            i++;
        }
        else if(ch==8&&i>=1)
        {
            setcolor(WHITE);
            setfillstyle(SOLID_FILL, WHITE);
            bar(w/2, h/2-15, w/2+15*20, h/2+15);
            c1[i-1]='\0';
            setcolor(BLACK);
            outtextxy(w/2,h/2,c1);
            setbkcolor(WHITE);
            setcolor(BLACK);
            i--;
        }
    }
    f=atoi(c1);
   U.transa(f);
  std::ifstream f1("details.dat",std::ios::binary);
  f1.seekg(0);
  std::ofstream f2("temp.dat",std::ios::binary);
  USER U1;
  while(!f1.eof())
  {
      f1.read((char*)&U1, sizeof(U1));
      if(strcmp(U1.user, U.user)==0)
      {
          f2.write((char*)&U,sizeof(U));
      }

        else
            f2.write((char*)&U1,sizeof(U1));
    }
    f1.close();
    f2.close();
    remove("details.dat");
    rename("temp.dat", "details.dat");
}
