#include"Or.h"
Or::Or()
{
    //ctor
}
void Or::opert()    //find the output of or gate
{
    o1.out=i1.i|i2.i;
}
void Or::get()  //find and display the output
{
    i1.get();
    i2.get();
    opert();
    o1.display();
}
