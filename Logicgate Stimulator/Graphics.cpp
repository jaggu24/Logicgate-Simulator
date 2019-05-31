#include "Graphics.h"
#include <iostream>
using namespace std;
#include <graphics.h>
#include <conio.h>
Graphics::Graphics()
{
    posx[2]=0;
    posy[3]=0;
    xe=0;
    ye=0;
    int gd = DETECT, gm;

   initgraph(&gd, &gm, "C:\\TC\\BGI");
   line(10,10,100,100);
}
void Graphics::addx(int a)
{
    static int i=0;
    posx[i]=a;
    i+=1;
}
void Graphics::addy(int b)
{
    static int i=0;
    posy[i]=b;
    i+=1;
}
int Graphics::andg(int a=0,int b=0)
{
    int x,y;
    if(a==0)
    {
        x=xe;
        y=ye;
    }
    else if(a==1)
    {
        x=posx[b];
        y=posy[b];
    }
    else if(a==2)
    {
        line(0,ye+15,200,ye+15);
        line(200,ye+15,xe-200,ye-35);
        return 0;
    }
    else if(a==3)
    {
        line(xe-200,ye-35,posx[b],posy[b]);
        return 0;
    }
    arc(x+100, y+100, 270, 90, 50);
    line(x+100,y+50,x+100,y+150);
    line(x,y+75,x+100,y+75);
    line(x,y+125,x+100,y+125);
    line(x+150,y+100,x+200,y+100);
    addx(x+200);
    addy(y+100);
    ye=y+160;
    xe=x+200;
    return 0;
}
void Graphics::org(int a=0,int b=0)
{
    int x,y;
}
void Graphics::notg(int a=0,int b=0)
{
    int x,y;
}
