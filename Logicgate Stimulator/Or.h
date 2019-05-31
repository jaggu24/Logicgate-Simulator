#ifndef OR_H
#define OR_H
#include "Input.h"
#include "Output.h"
#include "NMgate.h"
class Or : public NMgate    //or is derived class of NMgate
{
    public:
        Or();
 /*       Input i1;
        Input i2;
        Output o1;  */
        void opert();
        void get();
};

#endif // OR_H
