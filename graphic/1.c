#include <stdio.h>
#include <graphics.h>
#include <dos.h>


void rain()
{

    setcolor(LIGHTCYAN);

	for(int i=0;i<70;i++)
	{
		settextstyle(0,HORIZ_DIR,1);
		outtextxy(rand()%1920,rand()%880,"|");
	}
	setcolor(WHITE);
}
void stickman()
{

	
	setcolor(YELLOW);
	setfillstyle(SOLID_FILL, YELLOW);
	circle(950, 770, 20);
	floodfill(950, 770, YELLOW);;//tolgoi
	line(950,790,950,830);//biy
	//hul
	line(950,830,930,890);
	line(950,830,970,890);
	//bgar
	line(950,800,920,840);
	line(950,800,980,820);
	line(980,820,1000,800);
	//zoontik
	setcolor(9);
	line(1000,800,1000,710);//hevtee
	line(950,710,1050,710);//dood tal
	arc(1000,710,0,180,50);//deed heseg
	setfillstyle(SOLID_FILL,9);
	floodfill(1000,700,9);

	
}
void gol()
{
	
	setcolor(BLUE);
	setfillstyle(SOLID_FILL,BLUE);
	rectangle(0,950,2000,1090);
	floodfill(1, 951, BLUE);
}
void zam()
{
		// zam
        setcolor(WHITE);
        line(0,890,2000,890);
		line(0,920,2000,920);
		//zamiin goliin tsagaan zuraas
		line(0 ,905, 70, 905);		
		line(100 ,905, 170, 905);
		line(200 ,905, 270, 905);
		line(300 ,905, 370, 905);
		line(300 ,905, 370, 905);
		line(400 ,905, 470, 905);
		line(500 ,905, 570, 905);
		line(600 ,905, 670, 905);	
		line(700 ,905, 770, 905);
		line(800 ,905, 870, 905);
		line(900 ,905, 970, 905);
		line(1000 ,905, 1070, 905);
		line(1100 ,905, 1170, 905);
		line(1200 ,905, 1270, 905);
		line(1300 ,905, 1370, 905);
		line(1400 ,905, 1470, 905);
		line(1500 ,905, 1570, 905);
		line(1600 ,905, 1670, 905);
		line(1700 ,905, 1770, 905);
		line(1800 ,905, 1870, 905);
		line(1900 ,905, 1970, 905);
}
int main() 
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\tc\\bgi");
    //BGI urgun
	int width = 1920;  
	//BGI undur 
    int height = 1080;  
    initwindow(width, height); 
    int line1X = 0;
    int line1Y1 = 0;
    int line1Y2 = 0;
    int line2X = 0;
    int line2Y1 = 0;
    int line2Y2 = 0;
    int page=1;
    cleardevice();
    for (int i=0;i<9000;i++) 
	{
		
    	//delgets anivchij bgaag boliulah
		setactivepage(page);
    	setvisualpage(1-page);
   		cleardevice();
   		
    	//nar
		
		//STORE
		
		//FONT SIZE
		setcolor(MAGENTA); 
		settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
		outtextxy(1275, 660, "CU");

		//gol heseg
		setcolor(WHITE); 
		rectangle(1100, 650, 1500, 890);
		//BARUUN taliin heseg
		setcolor(WHITE); // 
		rectangle(1500, 700, 1800, 890);
		//haalga
		setcolor(BROWN); 
		setfillstyle(SOLID_FILL, BROWN);
		rectangle(1250, 750, 1350, 890);
		floodfill(1255, 755, BROWN);
		//bariul
		setcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		circle(1295, 815, 3);
		circle(1305, 815, 3);
		floodfill(1295, 815, WHITE);
		floodfill(1305, 815, WHITE);
		//tsonh (tuv)
		setcolor(WHITE); 
		rectangle(1125, 750, 1225, 840);
		rectangle(1375, 750, 1475, 840);
		line(1125,795,1225,795);
		//goliin baruun taliin tsonhiig 4huvaah
		line1X = 1175;
        line1Y1 = 750;
        line1Y2 = 840;
        line(line1X, line1Y1, line1X, line1Y2);
        //goliin zuun taliin tsonhiig 4huvaah
		line(1375,795,1475,795);
		line1X = 1425;
        line1Y1 = 750;
        line1Y2 = 840;
        line(line1X, line1Y1, line1X, line1Y2);
		
		//tsonh (BARUUN)
		setcolor(WHITE); 
		rectangle(1550, 750, 1750, 840);
		//cu baruun taliin nogoon
		setcolor(GREEN);
		setfillstyle(SOLID_FILL, GREEN);
		rectangle(1100, 662, 1270, 683);
		floodfill(1135, 672, GREEN);		
		//cu zuun taliin nogoon
		setcolor(GREEN);
		setfillstyle(SOLID_FILL, GREEN);
		rectangle(1330, 662, 1500, 683);
		floodfill(1355, 672, GREEN);
		
		setcolor(WHITE);
		line(1100,870,1250,870);//haalganii zuun tal
		line(1350,870,1500,870);//----------baruun---
		line(1500,870,1800,870);//BARUUN taliin hesegnii dood taliin line
		line(1500,720,1800,720);//---------------------deed------------
		
		// haalgiig 2 huvaah
		setcolor(BLACK);
		line1X = 1300;
        line1Y1 = 750;
        line1Y2 = 890;
        line(line1X, line1Y1, line1X, line1Y2);
		
        //zuun taliin hesgiin tsonhiig 2 huuvaasan line
        setcolor(WHITE);
		line1X = 1650;
        line1Y1 = 750;
        line1Y2 = 840;
        line(line1X, line1Y1, line1X, line1Y2);
        
        
        
        
					
		//MASHIN
        //ih biy
        setcolor(YELLOW);

		line(50 + i, 870, 90 + i, 870);
		arc(110 + i, 870, 0, 180, 20);
		line(130 + i, 870, 220 + i, 870);
		arc(240 + i, 870, 0, 180, 20);
		line(260 + i, 870, 300 + i, 870);
		line(300 + i, 870, 300 + i, 850);
		line(300 + i, 850, 240 + i, 830);
		line(240 + i, 830, 200 + i, 800);
		line(200 + i, 800, 110 + i, 800);
		line(110 + i, 800, 80 + i, 830);
		line(80 + i, 830, 50 + i, 840);
		line(50 + i, 840, 50 + i, 870);
		setfillstyle(SOLID_FILL, YELLOW);
		floodfill(150 + i, 850, YELLOW);

        //gerel PURPLE=9
        setcolor(9);
        circle(65 + i, 850, 5);
        circle(55 + i, 850, 5);
        circle(295 + i, 860, 5);
        circle(285 + i, 860, 5);
        setfillstyle(SOLID_FILL,9);
		floodfill(65 + i, 850,9);
		floodfill(55 + i, 850,9);
		floodfill(295 + i, 860,9);
		floodfill(285 + i, 860,9);

        // urd tsonh
        setcolor(BLACK);
		line(165 + i, 805, 165 + i, 830);
		line(165 + i, 830, 230 + i, 830);
		line(230 + i, 830, 195 + i, 805);
		line(195 + i, 805, 165 + i, 805);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(166 + i, 806, BLACK);
		//hoid tsonh
		line(160 + i, 805, 160 + i, 830);
		line(160 + i, 830, 95 + i, 830);
		line(95 + i, 830, 120 + i, 805);
		line(120 + i, 805, 160 + i, 805);
		setfillstyle(SOLID_FILL, BLACK);
		floodfill(159 + i, 806, BLACK);
		

        // dugui
        setcolor(9);
        circle(110 + i, 870, 17);
        circle(240 + i, 870, 17);
		//obud
        //hoid duguinii obud bosoo line
        setcolor(9);
        line1X = 110 + i;
        line1Y1 = 855;
        line1Y2 = 885;
        line(line1X, line1Y1, line1X, line1Y2);
        //hoid duguinii obud dignol 1
        setcolor(9);
        line(97 + i ,858, 120+i, 880);
        //hoid duguinii obud dignol 2
        setcolor(9);
        line(100 + i ,880, 120+i, 858);
        //hoid duguinii hevtee line
        setcolor(9);
        line(93+i ,870, 125+i, 870);
        //urd duguinii obud bosoo line
        setcolor(9);
        line1X = 240 + i;
        line1Y1 = 855;
        line1Y2 = 885;
        line(line1X, line1Y1, line1X, line1Y2);
        //urd dugui obid hevtee line 
        setcolor(9);
        line(223+i ,870, 255+i, 870);
        //urd duguinii obud dignol1
        setcolor(9);
        line(227 + i ,858, 250+i, 880);
        //urd duguinii obud dignol2
        setcolor(9);
        line(230 + i ,880, 250+i, 858);
        // spoiler nii dood taliin Line1
        setcolor(YELLOW);
        line1X = 55 + i;
        line1Y1 = 825;
        line1Y2 = 838;
        line(line1X, line1Y1, line1X, line1Y2);
        // Line2
        setcolor(YELLOW);
        line2X = 65 + i;
        line2Y1 = 825;
        line2Y2 = 834;
        line(line2X, line2Y1, line2X, line2Y2);
		 // deed taliin Line1
        setcolor(YELLOW);
        line(40 + i, 822, 70 + i, 822);
        // deed taliin Line2
        setcolor(YELLOW);
        line(45 + i, 825, 70 + i, 825);
		
  		gol();
		//nar();
		zam();
		rain();
		stickman();
        delay(10);
        page=1-page;
        
    	
    }

    closegraph();
    return 0;
}