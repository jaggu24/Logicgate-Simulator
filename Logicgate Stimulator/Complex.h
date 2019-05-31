#ifndef COMPLEX_H
#define COMPLEX_H
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Input.h"
#include "Output.h"
#include "Graphics.h"
#include "Nand.h"
#include "Nor.h"
#include "Xor.h"
#include "Xnor.h"
class Complex
{
    public:
        int menu();
        Complex();
    private:
        Input in[10];
        And an[7];
        Or oor[7];
        Not nt[5];
        Output ot[20];      //array of objects
        Nand nan[5];
        Nor nor[5];
        Xor xoor[4];
        Xnor xnor[4];
        void Design();
        void mux();
        void demux();
        void encoder();
        void decoder();
        void gate();

        int noi,noo,control,arr[200],f,r;
        void gates();                       //No. of inputs and outputs.
        void Or1();
        void Not1();
        void And1();
        void Nor1();
        void Nand1();
        void Xor1();
        void Xnor1();

        void enq(int n);
        int deq();
        int j,qq;
};
#endif // COMPLEX_H
