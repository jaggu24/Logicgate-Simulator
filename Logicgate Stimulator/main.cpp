#include <iostream>
#include<fstream>
#include "And.h"
#include "Or.h"
#include "Not.h"
#include<stdlib.h>
#include "Complex.h"
using namespace std;
// driver program
int main()
{
    system("color f0");
    cout<<"\n\n\t\t\tWELCOME: "<<endl;
    //cout<<"\t\t1.Signup\n\t\t2.Signin\n\t\t3.Use for free\nEnter choice : ";
    //int b;

    //cin>>b;
    cout<<endl;
    ifstream fin;
    fin.open("manual.txt");
    char c;
    while(!fin.eof())
    {
        fin.get(c);
        cout<<c;
    }
    fin.close();

    /*int a,p,o,d,e;
    cout<<" \nEnter no. of Inputs ";
    cin>>a;
    try
    {
        if(a>10)
        throw(a);
    }
    catch(int a)
    {
        cout<<"\nEnter inps less than 10 \n";
    }
    cout<<" Enter no. of AND ";
    cin>>p;
    try
    {
        if(p>7)
        throw(p);
    }
    catch(int as)
    {
        cout<<"\nEnter and less than 7 \n";
    }
    cout<<" Enter no. of OR ";
    cin>>o;
    try
    {
        if(o>10)
        throw(o);
    }
    catch(int a)
    {
        cout<<"Enter or less than 7 ";
    }
    cout<<" \nEnter no. of NOT \n";
    cin>>d;
    try
    {
        if(d>10)
        throw(d);
    }
    catch(int a)
    {
        cout<<"\nEnter mot less than 5 \n";
    }
    cout<<" Enter no. of Outputs ";
    cin>>e;
    try
    {
        if(e>10)
        throw(e);
    }
    catch(int a)
    {
        cout<<"\nEnter outputs less than 20\n ";
    }
    */
    system("pause");
    system("cls");
    Complex z;
    z.menu();
    return 0;
}
