#include "And.h"
#include <iostream>
using namespace std;
And::And()
{
}
void  And::opert()
{
    o1.out=i1.i&i2.i;
}
void And::get() //find and display the output of the and gate
{
    i1.get();
    i2.get();
    opert();
    o1.display();
}
