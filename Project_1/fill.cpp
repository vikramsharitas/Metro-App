#include"class.h"
//#include"functions.h"

void fill(int x, int y, int nc)
{
    if((getpixel(x, y)!=nc)&&(x<w)&&(x>0)&&(y<h)&&(y>0))
    {
        putpixel(x, y, nc);
        fill(x+1, y, nc);
        fill(x, y+1, nc);
        fill(x-1, y, nc);
        fill(x, y-1, nc);

    }
}
