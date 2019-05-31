#include "Complex.h"
#include <iostream>
#include <math.h>
#include<stdlib.h>
using namespace std;

Complex::Complex()                  //constructor to initialize the variables
{
    control=0;
    f=0;
    r=0;
    arr[2]=0;
    j=0;
    qq=0;                                                   //Controls truth table;
}
void Complex::enq(int n)
{
    arr[r]=n;
    r+=1;
}
int Complex::deq()
{
    f+=1;
    return(arr[f-1]);
}

void Complex::Design()      //Design the logic circuit
{
    system("cls");
    int a;
    static int qt=0;
    cout<<"Enter the no. of outputs ";
    cin>>a;
    for(int i=0;i<a;i++)
    {
        int b;
        cout<<endl<<"Enter the output number ";
        cin>>b;
        ot[b].display();
    }
    int u;
    cout<<endl<<"Do you wish to check for other inp. \n0-No\n1-Yes\n2.Truth table\n3.Enter choise : ";
    if(qt>=pow(2,noi))
    {
        qq=0;
        qt=0;
    }
    if(qq==0)
    cin>>u;
    else
    u=2;
    if(u==1)
    {
        control+=1;
        f=0;
    }
    else if(u==0)
    {
        control=0;
        r=0;
        f=0;
    }
    else if(u==2)
    {
        int q=j;
        control+=1;
        for(int i=noi-1;i>=0;i--)
        {
            int w;
            q>>1;
            w=q|0;
            in[i].i=(bool)w;
        }
        j+=1;
        qq=1;
        f=0;
        qt+=1;
    }
    //cout<<"\nThe qt is "<<qt<<endl;
}
void Complex::gate()                //Get the input for specific gate
{
    for(int i=0;i<noi&&qq==0;i++)
    {
        in[i].get();
        j|in[i].i;
        j<<1;
    }
    cout<<"The ip is "<<j<<endl;

}
int Complex::menu()             //displays the menu
{
    system("cls");
    int c;
    if(control==0)
    {
        cout<<"\n1.Input\n2.Output\n3.Gates\n4.Display\n5.Exit\nEnter Choice :- ";
        cin>>c;
        enq(c);
    }
    else
        c=deq();
    switch(c)
    {
        case 1:
            if(control==0)
            {
                cout<<"Enter the no.of inputs:";
                cin>>noi;
                enq(noi);
            }
            else
                noi=deq();
            gate();
            break;
        case 2:
            cout<<"Enter the outputs:";
            cin>>noo;
            break;
        case 3:
            gates();
            break;
        case 4:
            Design();
            break;
        case 5:
            return 0;
        default :
                cout<<"\nInvalid Input ";
                r-=1;
                menu();
                break;
    }
    system("cls");
    menu();
    return 1;
}
void Complex::gates()               //Shows the no of gates
{
    system("cls");
    int c;
    if(control==0)
    {
        cout<<"\n1.And\n2.Or\n3.Not\n4.Nand\n5.Nor\n6.Xor\n7.Xnor\n8.Encoder\n9.Decoder\n10.Multiplexer\n11.Demultiplexer\nEnter : ";
        cin>>c;
        enq(c);
    }
    else
        c=deq();
    switch(c)
    {
        case 1:
                And1();
                break;
        case 2:
                Or1();
                break;
        case 3:
                Not1();
                break;
        case 4:
                Nand1();
                break;
        case 5:
                Nor1();
                break;
        case 6:
                Xor1();
                break;
        case 7:
                Xnor1();
                break;
        case 8:
                encoder();
                decoder();
                break;
                break;
        case 9:
        case 10:
                mux();
                break;
        case 11:
                demux();
                break;
        default:
                gates();

    }
}
void Complex::And1()        //implements the and gate
{
    system("cls");
    static int n=0;
    if(control==1&&n!=0)
        n-=n;
    int a,g;

    for(int i=1;i<3;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old"<<endl;
            cout<<"Enter the input : ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                an[n].i1.i=in[a].i;

            }
            else
            {
                if(control==0)
                 {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                an[n].i2.i=in[a].i;

            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op "<<n<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                an[n].i1.i=ot[a].out;

            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op 2 :";
                    cin>>a;
                    enq(a);
                }
                an[n].i2.i=ot[a].out;

            }

        }
    }
    an[n].opert();
    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();
    ot[a].out=an[n].o1.out;
    n+=1;
}
void Complex::Or1()     //implements the or gate
{
    system("cls");
    static int n=0;
    if (control==1&&n!=0)
        n-=n;
    int a,g;

    for(int i=1;i<3;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old\nChoice  :- ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                oor[n].i1.i=in[a].i;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                oor[n].i2.i=in[a].i;
            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op "<<n<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                oor[n].i1.i=ot[a].out;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op 2 :";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                oor[n].i2.i=ot[a].out;
            }

        }
    }
    oor[n].opert();
    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();
    ot[a].out=oor[n].o1.out;
    n+=1;
}
void Complex::Not1()    //implements  the not gate
{
    system("cls");
    static int n=0;
    if (control==1&&n!=0)
        n=0;
    int a,g;
    //cout<<"Enter the input \n";
    for(int i=1;i<2;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old"<<endl;
            cout<<"Enter the input : ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nt[n].i1.i=in[a].i;
            }
            else
            {
                cout<<"\nEnter the i/p no ip "<<i<<":";
                cin>>a;
                an[n].i2.i=in[a].i;
            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op "<<n<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nt[n].i1.i=ot[a].out;
            }
            else
            {
            cout<<"\nEnter the o/p no op 2 :";
            cin>>a;
            an[n].i2.i=in[a].i;
            }

        }
    }
    nt[n].opert();
    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();
    ot[a].out=nt[n].o1.out;
    n+=1;
}
void Complex::Nand1()   //implements the nand gate
{
    system("cls");
    static int n=0;
    if(control==1&&n!=0)
        n-=n;
    int a,g;

    for(int i=1;i<3;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old"<<endl;
            cout<<"Enter the input : ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nan[n].i1.i=in[a].i;

            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nan[n].i2.i=in[a].i;

            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op "<<n<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nan[n].i1.i=ot[a].out;

            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op 2 :";
                    cin>>a;
                    enq(a);
                }
                nan[n].i2.i=ot[a].out;

            }

        }
    }
    nan[n].opert();
    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();
    ot[a].out=nan[n].o1.out;
    n+=1;
}
void Complex::Nor1()    //implements the nor gate
{
    system("cls");
    static int n=0;
    if (control==1&&n!=0)
        n=n-n;
    int a,g;

    for(int i=1;i<3;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old\nChoice  :- ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nor[n].i1.i=in[a].i;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nor[n].i2.i=in[a].i;
            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op "<<n<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nor[n].i1.i=ot[a].out;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op 2 :";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                nor[n].i2.i=ot[a].out;
            }

        }
    }
    nor[n].opert();
    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();
    ot[a].out=nor[n].o1.out;
    n+=1;
}
void Complex::Xor1()    //implements the xor gate
{
    system("cls");
    static int n=0;
    if (control==1&&n!=0)
        n=n-n;
    int a,g;

    for(int i=1;i<3;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old\nChoice  :- ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xoor[n].i1.i=in[a].i;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xoor[n].i2.i=in[a].i;
            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op "<<n<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xoor[n].i1.i=ot[a].out;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op 2 :";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xoor[n].i2.i=ot[a].out;
            }

        }
    }
    xoor[n].opert();
    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();
    ot[a].out=xoor[n].o1.out;
    n+=1;
}
void Complex::Xnor1()   //implements the xnor gate
{
    system("cls");
    static int n=0;
    if (control==1&&n!=0)
        n-=n;
    int a,g;

    for(int i=1;i<3;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old\nChoice  :- ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xnor[n].i1.i=in[a].i;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xnor[n].i2.i=in[a].i;
            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op "<<n<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xnor[n].i1.i=ot[a].out;
            }
            else
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op 2 :";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                xnor[n].i2.i=ot[a].out;
            }

        }
    }
    xnor[n].opert();
    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();
    ot[a].out=xnor[n].o1.out;
    n+=1;
}
void Complex::encoder()     //implements the encoder logic circuit
{
    system("cls");
    Input j[4];
    Output t[2];

 //   static int n=0;
 //   if (control==1)
   //     n=n-n;
    int a,g;

    for(int i=0;i<4;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old\nChoice  :- ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i<4)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                j[i].i=in[a].i;
            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op :";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                j[i].i=ot[a].out;
            }

        }
    }
    t[0].out=j[1].i|j[3].i;
    t[1].out=j[2].i|j[3].i;
    for(int i=0;i<2;i++)
    {


    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - "<<i<<"   ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();

    ot[a].out=t[i].out;
    }
   // n+=1;
}
void Complex::decoder() //implements the decoder logic circuit
{
    system("cls");
    Input j[3];
    Output t[4];
    cout<<"\nIt is a 2 x 4 Decoder "<<endl;
    cout<<"Enter the data select 1 ";
    cin>>j[0].i;
    cout<<"Enter the data select 2 ";
    cin>>j[1].i;
    cout<<"Enter the Ground value";
    cin>>j[2].i;
    t[0].out=!j[0].i&!j[1].i&j[2].i;
    t[1].out=!j[0].i&j[1].i&j[2].i;
    t[1].out=j[0].i&!j[1].i&j[2].i;
    t[3].out=j[0].i&j[1].i&j[2].i;
    cout<<"The original values are "<<t[0].out<<"\t"<<t[1].out<<"\t"<<t[2].out<<"\t"<<t[3].out;
}
void Complex::mux()    //implements the multiplexer
{
    system("cls");
    Input j[6];
    Output t[5];
    cout<<"\nIt is a 4 * 1 Multipluxer "<<endl;
 //   static int n=0;
 //   if (control==1)
   //     n=n-n;
    int a,g;

    for(int i=0;i<4;i++)
    {
        if(control==0)
        {
            cout<<"\n1.New\n2.old\nChoice  :- ";
            cin>>g;
            enq(g);
        }
        else
            g=deq();
        if(g==1)
        {
            if(i<4)
            {
                if(control==0)
                {
                    cout<<"\nEnter the i/p no ip "<<i<<":";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                j[i].i=in[a].i;
            }

        }
        else if(g==2)
        {
            if(i==1)
            {
                if(control==0)
                {
                    cout<<"\nEnter the o/p no op :";
                    cin>>a;
                    enq(a);
                }
                else
                    a=deq();
                j[i].i=ot[a].out;
            }

        }
    }
    cout<<"Enter the data select : ";
    cin>>j[4].i>>j[5].i;
    t[0].out=j[4].i&j[5].i&j[0].i;
    t[1].out=j[4].i&j[5].i&j[1].i;
    t[2].out=j[4].i&j[5].i&j[2].i;
    t[3].out=j[4].i&j[5].i&j[3].i;
    t[4].out=t[0].out|t[1].out|t[2].out|t[3].out;
    for(int i=0;i<1;i++)
    {


    if(control==0)
    {
        cout<<"Enter the output line to which it is stored - "<<i<<"   ";
        cin>>a;
        enq(a);
    }
    else
        a=deq();

    ot[a].out=t[4].out;
    }
 }
 void Complex::demux()  //implements the demultiplexer
{
    system("cls");
    Input j[3];
    Output t[4];
    cout<<"\nIt is a 1 x 4 Demultipluxer "<<endl;
    cout<<"Enter the data select 1 ";
    cin>>j[0].i;
    cout<<"Enter the data select 2 ";
    cin>>j[1].i;
    cout<<"Enter the Ground value";
    cin>>j[2].i;
    t[0].out=!j[0].i&!j[1].i&j[2].i;
    t[1].out=!j[0].i&j[1].i&j[2].i;
    t[1].out=j[0].i&!j[1].i&j[2].i;
    t[3].out=j[0].i&j[1].i&j[2].i;
    cout<<"The original values are "<<t[0].out<<"\t"<<t[1].out<<"\t"<<t[2].out<<"\t"<<t[3].out;
}
