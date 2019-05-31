#ifndef GRAPHICS_H
#define GRAPHICS_H


class Graphics
{
    public:
        Graphics();
        int xe,ye;
        int posx[100];
        int posy[100];
        void addx(int a);
        void addy(int a);
        int andg(int a,int b);
        void org(int a,int b);
        void notg(int a,int b);
};

#endif // GRAPHICS_H
