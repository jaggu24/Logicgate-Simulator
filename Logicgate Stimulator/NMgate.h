#ifndef NMGATE_H
#define NMGATE_H
#include "Input.h"
#include "Output.h"

class NMgate
{
    public:
        NMgate();
        Input i1;
        Input i2;
        Output o1;
        virtual void opert()=0;     //pure virtual function
};

#endif // NMGATE_H
