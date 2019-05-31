#include"Not.h"
Not::Not()
{
    //ctor
}
void Not::opert()
{
    o1.out=!i1.i;
}
void Not::get() //find and display the output of the not gate
{
    i1.get();
    opert();
    o1.display();
}
