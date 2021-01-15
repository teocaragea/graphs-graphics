#include <iostream>
#include <graphics.h>
#include <fstream>
#include <time.h>
#include <cmath>
#include <cstdlib>
using namespace std;
int m,n,a[101][101];
int g[101],maxx=-1;
int coada[100];
int viz[101];
struct segment
{
    int x;
    int y;
} v[101];


void df(int nod)
{
    cout<<nod<<" ";
    viz[nod]=1;
    for(int i=1;i<=n;i++)
        if(a[nod][i]==1 && viz[i]==0)
        df(i);
}
void bf(int x)
{
     int p,u,nod;
     p=u=1;
     ///c[p]=x;
     viz[x]=1;
     while(p<u)
     {
         nod=coada[p];
         for(int i=1;i<=n;i++)
         if(a[nod][i]==1 && viz[i]==0)
         {
             u++;
             coada[u]=i;
             viz[i];
         }
         p++;

     }

}


int main()
{
    int L=1000,l=800;
    initwindow(L,l,"Grafuri grafic");
    setcolor(8);
    line(700,0,700,l);

    line(700,l/4,L,l/4);
    line(700,l/2,L,l/2);
    line(700,l/2+l/4,L,l/2+l/4);
    outtextxy(800,l/8,"Generare nod");
    outtextxy(800,l/4+l/8,"Trasare muchii");
    outtextxy(800,l/8+l/2,"Generare cost");
    outtextxy(800,l-150,"Stop");
    int ok3=0;
///------------------------generare optiune
    int x2=0,y2=0;
    getmouseclick(WM_LBUTTONDOWN,x2,y2);

///--------------------------
    int ok=0,ok4=0;
    int k=1;
    while(!kbhit() || ok==1)
    {
        ///------------------------alegere optiune optiune
        int x2=0,y2=0;
        if(ismouseclick(WM_LBUTTONDOWN))
            getmouseclick(WM_LBUTTONDOWN,x2,y2);
        if(x2!=0)
            cout<<x2<<" "<<y2<<endl;
        ok3=0;
        ok4=0;
        ///-------------------- generare nod
        while(x2>700 && y2<l/4 && ok3==0)
        {
            ok3=0;

            int ok2=0;
            int x=0,y=0;
            while(x==0)
                if(ismouseclick(WM_LBUTTONDOWN))
                    getmouseclick(WM_LBUTTONDOWN,x,y);
            for(int j=1; j<k; j++)
                if(v[j].x-x<50 && v[j].x-x>-50 && v[j].y-y<50 && v[j].y-y>-50)
                    ok2=1;
            if(x<670 && ok2==0 && ok3==0)
            {
                circle(x,y,25);
                char c[100];
                itoa(k,c,10);
                outtextxy(x-5,y-5,c);
                v[k].x=x;
                v[k].y=y;
                k++;
            }
            if(x>700)
            {
                ok3=1;
                x2=x;
                y2=y;
            }
        }
        ///--------------------trasare muchii
        while(x2>700 && y2>l/4 && y2<l/2 &&ok4==0)
        {

            cout<<"Trasare muchii"<<endl;
            int n1,n2;
            int x=0,y=0;
            while(x==0)
                if(ismouseclick(WM_LBUTTONDOWN))
                    getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>800)
            {
                ok4=1;
                x2=x;
                y2=y;
            }
            else

            {
                for(int j=1; j<k; j++)
                    if(v[j].x-x<30 && v[j].x-x>-30 && v[j].y-y<30 && v[j].y-y>-30)
                        n1=j;
                setcolor(10);
                circle(v[n1].x,v[n1].y,25);
                delay(100);
                setcolor(8);
                circle(v[n1].x,v[n1].y,25);




                int x3=0,y3=0;
                while(x3==0)
                    if(ismouseclick(WM_LBUTTONDOWN))
                        getmouseclick(WM_LBUTTONDOWN,x3,y3);
                if(x3>800)
                {
                    ok4=1;
                    x2=x3;
                    y2=y3;

                }
                else
                {


                    for(int j=1; j<k; j++)
                        if(v[j].x-x3<30 && v[j].y-y3<30 && v[j].x-x3>-30 && v[j].y-y3>-30)
                            n2=j;
                    setcolor(10);
                    circle(v[n2].x,v[n2].y,25);
                    delay(100);
                    setcolor(8);
                    circle(v[n2].x,v[n2].y,25);



                    if(v[n1].x<v[n2].x && n1!=n2)
                        line(v[n1].x+27,v[n1].y,v[n2].x-27,v[n2].y);
                    else
                        line(v[n2].x+27,v[n2].y,v[n1].x-27,v[n1].y);

                    a[n1][n2]=1;
                }
            }


        }


        ///--------------------generare cost
        while(x2>800 && y2<l/2+l/4 && y2>l/2)
        {
            int n1,n2;
            int x=0,y=0,x3=0,y3=0;
            while(x==0)
                if(ismouseclick(WM_LBUTTONDOWN))
                    getmouseclick(WM_LBUTTONDOWN,x,y);
            if(x>800)
            {
                ok4=1;
                x2=x;
                y2=y;
            }
            else

            {
                while(x3==0)
                    if(ismouseclick(WM_LBUTTONDOWN))
                        getmouseclick(WM_LBUTTONDOWN,x3,y3);
                srand(time(NULL));
                if(x3>800)
                {
                    ok4=1;
                    x2=x3;
                    y2=y3;

                }
                else
                {

                    int cost=rand()%30;
                    char e[100];
                    itoa(cost,e,10);
                    for(int j=1; j<k; j++)
                        if(v[j].x-x<30 && v[j].x-x>-30 && v[j].y-y<30 && v[j].y-y>-30)
                            n1=j;
                    setcolor(10);
                    circle(v[n1].x,v[n1].y,25);
                    delay(100);
                    setcolor(8);
                    circle(v[n1].x,v[n1].y,25);
                    for(int j=1; j<k; j++)
                        if(v[j].x-x3<30 && v[j].y-y3<30 && v[j].x-x3>-30 && v[j].y-y3>-30)
                            n2=j;
                    setcolor(10);
                    circle(v[n2].x,v[n2].y,25);
                    delay(100);
                    setcolor(8);
                    circle(v[n2].x,v[n2].y,25);


                    if(a[n1][n2]==1)
                        outtextxy((v[n1].x+v[n2].x)/2,(v[n1].y+v[n2].y)/2,e);
                }

            }
        }


        ///--------------------

        if(x2>800 && y2>l/2+l/4)
            ok=1;





    }




    system("pause");
    return 0;
}
