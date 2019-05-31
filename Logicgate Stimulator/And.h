#ifndef AND_H
#define AND_H
#include "Input.h"
#include "Output.h"
#include "NMgate.h"
class And : public NMgate       //class AND is derived class of NM gate
{
    public:
        And();
  /*      Input i1;
        Input i2;
        Output o1;      */
        void opert();
        void get();
};

#endif // AND_H
