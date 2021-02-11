#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;

int main()
{
    int gd=DETECT,gm;
    int x=628,a[100],y1[100],y2[100],b=0,k,l=0;
    int y=200,flag=0,z=10;
    int arr2[10]={93,y,98,y+6,98,y+16,94,y+6,87,y};

    for(int i=0;i<100;i++)
    {
        a[i]=b;//a directs to the positions of the obstacles
        b+=68;
    }

    //determining coordinates for the obstacles
    for(int i=0;i<100;i++)
    {
        take2:

        y1[i]=rand()%200;//taking random hieghts
        if(y1[i]<=20 || y1[i]>100 && y1[i]<=120)
            goto take2;

        if(y1[i]<=100)
        {
            y1[i]=300-y1[i];
            y2[i]=300;
        }
        else
        {
            y2[i]=100;
            y1[i]=100+y1[i]-100;
        }
        //y1,y2=coordinate for obstacle
    }



    initgraph(&gd,&gm,"C\\TC\\BGI");

    outtextxy(100,100,"Press 'space' to keep the bird flying");
    outtextxy(100,120,"Press any character to start the game");

    getch();

    while((x+a[99]+10)>0)//the x+a[99]+10 indicates the last obstacles
    {
        take:
        bar(0,100,639,80);//upper line
        bar(0,300,639,320);//lower line

        int arr1[8]={80,y,69,y+2,68,y-4,80,y};//tail coordinate
        int arr2[10]={93,y,98,y+6,98,y+16,94,y+6,87,y};//stable wing coordinate
        int arr3[10]={93,y,95,y-6,95,y-16,91,y-6,87,y};//upper wing coordinate

        circle(100,y,3);
        line(100,y-2,105,y);
        line(100,y+2,105,y);
        ellipse(89,y+1,0,360,7,5);
        drawpoly(4,arr1);//tail
        drawpoly(5,arr2);//stable wing


        y++;
        //ending logic when the bird touches upper or lower line
        if(y>=300)
        {
            take3:
                outtextxy(280,200,"Game Over");
                flag=1;
                break;
        }
        if(kbhit() && getch()==' ')
        {
            while(1)
            {
                bar(0,100,639,80);//upper line
                bar(0,300,639,320);//lower line

                int arr1[8]={80,y,69,y+2,68,y-4,80,y};//tail coordinate
                int arr3[10]={93,y,95,y-6,95,y-16,91,y-6,87,y};//upper wing coordinate


                circle(100,y,3);
                line(100,y-2,105,y);
                line(100,y+2,105,y);
                ellipse(89,y+1,0,360,7,5);
                drawpoly(4,arr1);//tail
                drawpoly(5,arr3);//upper wing


                y-=5;
                z++;
                x-=2;

                //ending logic
                if(y<=100)
                    goto take3;


                delay(15);
                clearviewport();
                if(z>=15)
                {
                    z=10;
                    goto take;
                }

            }
        }


        if(a[l]+x+10<=0)
            l++;
        for(int j=0;j<10;j++)
        {
            k=l+j;
            setfillstyle(SOLID_FILL,11);
            bar(x+a[k],y1[k],x+a[k]+10,y2[k]);//building obstacles

            if(x+a[k]<=104 && x+a[k]>=68)
            {
                if(y2[k]==300 && y>=y1[k]-5 || y2[k]==100 && y<=y1[k]+5)
                {
                    goto take3;
                }
            }
        }
        setfillstyle(SOLID_FILL,7);
        setcolor(YELLOW);
        x-=2;

        bar(0,100,639,80);//upper line
        bar(0,300,639,320);//lower line

        delay(2);
        clearviewport();
    }

    if(flag==0)
    {
        outtextxy(280,200,"YOU WIN!!!");
    }
    getch();
    closegraph();
}




