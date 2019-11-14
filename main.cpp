#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include<stdio.h>


void *font = GLUT_BITMAP_HELVETICA_18;
void *font2 = GLUT_BITMAP_TIMES_ROMAN_24;
void *font3 = GLUT_BITMAP_HELVETICA_12;
int xx = 120;
double musuh = 120;
double musuh2 = 120;
int health = 3;
double xxx,yyy,gerak,musuh3,musuh4,avyUp,avyDown,avxLeft,avxRight,mhxLeft,mhxRight,mhyUp,mhyDown;
double mhxLeft2,mhxRight2,mhyUp2,mhyDown2;
int hitungscore,posisi3,posisi4;
int respawn =6;
int tinggi1 = 90;
int tinggi2 =120;
int arr[4] = {0,20,40,60};
int posisi1 = rand() % 4;
int posisi2 = rand() % 4;
int score = 0;
int timer = 0;
int menux,menuy;
bool checkmenu = false;
bool collision = false;
bool checkgame = false;

///Helvetica
void tulis(int x, int y, char *string) {
    glRasterPos2f(x, y);
    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, string[i]);
    }
}
void tulis3(int x, int y, char *string) {
    glRasterPos2f(x, y);
    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font3, string[i]);
    }
}
///TimesRoman
void tulis2(int x, int y, char *string) {
    glRasterPos2f(x, y);
    int len = (int) strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font2, string[i]);
    }
}
void grass(){
    int jumlah = xx;
    int x=0;
    int y=1;
    int a,b,c;
    for(int i=1;i<jumlah+1;i++){
        if(i%2==0){
            if(y%2==0){
                a=21;b=176;c=73;
            }else{
                a=17;b=128;c=54;
                }
        }else{
            if(y%2==0){
                a=17;b=128;c=54;
            }else{
                a=21;b=176;c=73;
                }
            }
        glBegin(GL_QUADS);
            glColor3ub(a,b,c);
            glVertex2f(x+i-1,y-1);
            glVertex2f(x+i-1,y);
            glVertex2f(x+i,y);
            glVertex2f(x+i,y-1);
        glEnd();
        if(i%jumlah==0){
            y=y+1;
            i=0;
            if(y>jumlah+250){
                i=jumlah+1;
            }
        }
    }
}
void jalan(){
    int a=20;
    int b=40;
    for(int i=0;i<4;i++){
    //Aspal
    glBegin(GL_POLYGON);
        glColor3ub(29,29,31);
        glVertex2f(a,0);
        glVertex2f(b,0);
        glVertex2f(b,xx);
        glVertex2f(a,xx);
    glEnd();
    a=a+20;
    b=b+20;
    }
    //PembatasJalan
    glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(21,0);
        glVertex2f(21,xx);
    glEnd();
    glBegin(GL_LINES);
        glColor3ub(255,255,255);
        glVertex2f(99,0);
        glVertex2f(99,xx);
    glEnd();
}
void marka(){
    int sign = 40;
    int sign2 = -10;
    //Marka Jalan
    for(int i=0;i<3;i++){
        glBegin(GL_LINES);
            glColor3ub(255,255,255);
            glVertex2f(sign,sign2);
            glVertex2f(sign,sign2+10);
        glEnd();
        if(i==2){
            i=-1;
            sign=40;
            sign2=sign2+15;
            if(sign2>xx+300){
                i=3;
            }
        }else{
            sign=sign+20;
        }
    }
}
void mobilpolisi(){
    glColor3f(1.0,1.0,1.0);
    glPushMatrix();
    glScaled(2.5,1.5,0.0);
    glTranslated(5.0,-1.0,0.0);
    glBegin(GL_POLYGON); //BodyMobil
        glColor3ub(18,18,18);
        glVertex2f(6.2,10.2);//A
        glVertex2f(7.8,10.2);//B
        glVertex2f(8.2,10);//E
        glVertex2f(8.6,9.8);//F
        glVertex2f(9,9.4);//G
        glVertex2f(9,8.8);//H
        glVertex2f(9,4.4);//I
        glVertex2f(9.2,3.8);//J
        glVertex2f(9.2,3.4);//K
        glVertex2f(9,3);//L
        glVertex2f(8.8,2.8);//M
        glVertex2f(8.4,2.6);//N
        glVertex2f(5.6,2.6);//O
        glVertex2f(5.2,2.8);//P
        glVertex2f(5,3);//Q
        glVertex2f(4.8,3.4);//R
        glVertex2f(4.8,3.8);//S
        glVertex2f(5,4.4);//T
        glVertex2f(5,8.8);//U
        glVertex2f(5,9.4);//V
        glVertex2f(5.4,9.8);//W
        glVertex2f(5.8,10);//Z
    glEnd();
    glBegin(GL_TRIANGLES);//LampuKiriKanan
        glColor3ub(250,226,10);
        glVertex2f(6,9.8);//E1
        glVertex2f(5.2,9);//F1
        glVertex2f(5.8,9);//G1
    glEnd();
    glBegin(GL_TRIANGLES);//LampuKiriKanan
        glColor3ub(250,226,10);
        glVertex2f(8,9.8);//H1
        glVertex2f(8.8,9);//I1
        glVertex2f(8.2,9);//J1
    glEnd();
    glBegin(GL_POLYGON);//KapMesin
        glColor3ub(255,255,255);
        glVertex2f(6.2,9.8); //A1
        glVertex2f(7.8,9.8);//B1
        glVertex2f(8,8.6);//C1
        glVertex2f(6,8.6);//D1
    glEnd();
    glBegin(GL_POLYGON);//KacaDepan
        glColor3ub(5,78,161);
        glVertex2f(8,8.6);//C1
        glVertex2f(8.4,8);//N1
        glVertex2f(8,7.5);//M1
        glColor3ub(142,187,237);
        glVertex2f(6,7.5);//L1
        glVertex2f(5.6,8);//K1
        glVertex2f(6,8.6);//D1
    glEnd();
    glBegin(GL_QUADS);//BagianAtas
        glColor3ub(255,255,255);
        glVertex2f(8,7.5);//M1
        glVertex2f(6,7.5);//L1
        glVertex2f(6,3);//O1
        glVertex2f(8,3);//P1
    glEnd();
    glBegin(GL_QUADS);//LampuStroboBIru
        glColor3ub(34,2,242);
        glVertex2f(6.2,6.5);//A2
        glVertex2f(6.2,6);//b2
        glVertex2f(6.8,6);//c2
        glVertex2f(6.8,6.5);//d2
    glEnd();
    glBegin(GL_QUADS);//PemisahLampuStrobo
        glColor3ub(0,0,0);
        glVertex2f(6.8,6);//c2
        glVertex2f(6.8,6.5);//d2
        glVertex2f(7.2,6.5);//h2
        glVertex2f(7.2,6);//g2
    glEnd();
    glBegin(GL_QUADS);//LampuStroboMerah
        glColor3ub(242,2,2);
        glVertex2f(7.8,6.5);//e2
        glVertex2f(7.8,6);//f2
        glVertex2f(7.2,6);//g2
        glVertex2f(7.2,6.5);//h2
    glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(5,78,161);
        glVertex2f(6.6,5);//i1
        glVertex2f(6,4);//j1
        glVertex2f(6,3.4);//k2
        glColor3ub(142,187,237);
        glVertex2f(8,3.4);//l2
        glVertex2f(8,4);//m2
        glVertex2f(7.4,5);//n2
    glEnd();
    glBegin(GL_QUADS);//LampuBelakangKiri
        glColor3ub(250,226,10);
        glVertex2f(5.2,3.5);//Q1
        glVertex2f(5,3.5);//R1
        glVertex2f(5.3,3);//S1
        glVertex2f(5.5,3);//T1
    glEnd();
    glBegin(GL_QUADS);//LampuBelakangKanan
        glColor3ub(250,226,10);
        glVertex2f(8.8,3.5);//U1
        glVertex2f(9,3.5);//V1
        glVertex2f(8.7,3);//W1
        glVertex2f(8.5,3);//Z1
    glEnd();
    glPopMatrix();
}
void objectmobil(){
    glPushMatrix();
        glTranslated(10.0,90,0);//90
        glScaled(1.5,1,0);
        glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(11.07685, 6.48686);
        glVertex2f(10.98593, 6.87129);
        glVertex2f(10.8989, 7.19765);
        glVertex2f(10.76835, 7.63281);
        glVertex2f(10.68132, 8.00269);
        glVertex2f(10.59429, 8.48136);
        glVertex2f(10.55078, 8.91651);
        glVertex2f(10.50726, 9.41694);
        glVertex2f(10.50726, 9.93913);
        glVertex2f(10.55078, 10.37428);
        glVertex2f(10.59429, 10.93998);
        glVertex2f(10.61605, 11.46217);
        glVertex2f(10.68132, 12.02787);
        glVertex2f(10.66605, 13.52131);
        glVertex2f(10.70308, 15.26977);
        glVertex2f(10.09387, 15.13922);
        glVertex2f(10.10246, 15.61254);
        glVertex2f(10.68132, 15.81371);
        glVertex2f(10.70308, 17.6196);
        glVertex2f(10.55078, 17.92421);
        glVertex2f(10.46375, 18.3376);
        glVertex2f(10.46375, 18.77276);
        glVertex2f(10.4855, 19.1644);
        glVertex2f(10.52902, 19.57779);
        glVertex2f(10.65957, 20.09998);
        glVertex2f(10.83363, 20.4481);
        glVertex2f(11.00769, 20.77447);
        glVertex2f(11.20351, 21.05732);
        glVertex2f(11.42109, 21.34017);
        glVertex2f(11.70394, 21.55775);
        glVertex2f(12.00854, 21.73181);
        glVertex2f(12.33491, 21.86235);
        glVertex2f(12.63952, 21.9929);
        glVertex2f(12.96588, 22.07993);
        glVertex2f(13.35752, 22.12345);
        glVertex2f(13.70565, 22.12345);
        glVertex2f(14.33662, 22.10169);
        glVertex2f(14.75002, 22.01466);
        glVertex2f(15.07638, 21.97114);
        glVertex2f(15.44626, 21.90587);
        glVertex2f(15.85966, 21.73181);
        glVertex2f(16.20778, 21.55775);
        glVertex2f(16.46888, 21.31841);
        glVertex2f(16.75173, 21.10083);
        glVertex2f(16.99106, 20.7092);
        glVertex2f(17.18688, 20.40459);
        glVertex2f(17.33918, 20.07822);
        glVertex2f(17.3827, 19.75186);
        glVertex2f(17.44797, 19.42549);
        glVertex2f(17.46973, 18.09827);

        glVertex2f(17.29567, 15.90074);
        glVertex2f(17.86137, 15.59613);
        glVertex2f(17.83961, 15.16098);

        glVertex2f(17.33918, 12.02787);
        glVertex2f(17.33918, 11.65799);
        glVertex2f(17.36094, 11.24459);
        glVertex2f(17.3827, 10.85295);
        glVertex2f(17.40446, 10.46131);
        glVertex2f(17.44797, 10.13495);
        glVertex2f(17.44797, 9.80858);
        glVertex2f(17.42622, 9.39518);
        glVertex2f(17.42622, 9.04706);
        glVertex2f(17.36094, 8.56839);
        glVertex2f(17.33918, 8.19851);
        glVertex2f(17.2304, 7.85039);
        glVertex2f(17.12161, 7.45875);
        glVertex2f(17.05633, 7.13238);
        glVertex2f(16.9693, 6.78426);
        glVertex2f(16.83876, 6.43613);
        glVertex2f(16.49063, 6.26207);
        glVertex2f(15.72911, 6.13153);
        glVertex2f(14.96759, 6.08801);
        glVertex2f(14, 6);
        glVertex2f(13.20522, 6.06625);
        glVertex2f(12.61776, 6.08801);
        glVertex2f(12.26964, 6.10977);
        glVertex2f(11.72569, 6.24032);
    glEnd();
    //jendela belakang
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(12.21944, 8.13208);
        glVertex2f(12.00445, 9.5352);
        glVertex2f(12.06382, 9.6837);
        glVertex2f(12.14392, 9.79812);
        glVertex2f(12.29267, 9.88966);
        glVertex2f(15.6511, 9.90683);
        glVertex2f(15.79413, 9.83817);
        glVertex2f(15.92, 9.72375);
        glVertex2f(15.97721, 9.56927);
        glVertex2f(15.7598, 8.11605);
        glVertex2f(15.66254, 7.93869);
        glVertex2f(15.56528, 7.84715);
        glVertex2f(15.43369, 7.72128);
        glVertex2f(15.31354, 7.65262);
        glVertex2f(15.15906, 7.57824);
        glVertex2f(15, 7.5);
        glVertex2f(14.86155, 7.46382);
        glVertex2f(14.72996, 7.42949);
        glVertex2f(14.58121, 7.38944);
        glVertex2f(14.42101, 7.35511);
        glVertex2f(14.22648, 7.34939);
        glVertex2f(14.05484, 7.33795);
        glVertex2f(13.86032, 7.33795);
        glVertex2f(13.65435, 7.34939);
        glVertex2f(13.52848, 7.36083);
        glVertex2f(13.40261, 7.38944);
        glVertex2f(13.2653, 7.42377);
        glVertex2f(13.09938, 7.46382);
        glVertex2f(13, 7.5);
        glVertex2f(12.8648, 7.54964);
        glVertex2f(12.73894, 7.61829);
        glVertex2f(12.60734, 7.69839);
        glVertex2f(12.47575, 7.76705);
        glVertex2f(12.4071, 7.85859);
        glVertex2f(12.33272, 7.93297);
        glVertex2f(12.26406, 8.03595);

    glEnd();
    //kotak bagian belakang
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(13.5417, 7.10975);
        glVertex2f(13.90045, 7.12329);
        glVertex2f(13.88692, 6.41933);
        glVertex2f(13.52817, 6.41933);
    glEnd();
        //kotak bagian belakang 2
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(14.09675, 7.13006);
        glVertex2f(14.44873, 7.12329);
        glVertex2f(14.46227, 6.4261);
        glVertex2f(14.08321, 6.4261);
    glEnd();
        //kotak bagian tengah 1
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(13.54091, 14.75579);
        glVertex2f(13.89155, 14.74702);
        glVertex2f(13.87401, 10.07481);
        glVertex2f(13.52338, 10.06605);
    glEnd();
        //kotak bagian tengah 2
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(14.08439, 14.74702);
        glVertex2f(14.46133, 14.73826);
        glVertex2f(14.45256, 10.07481);
        glVertex2f(14.10193, 10.06605);
    glEnd();
    //kaca bagian depan
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(12, 15);
        glVertex2f(11.9101, 15.08215);
        glVertex2f(11.81918, 15.18006);
        glVertex2f(11.74925, 15.30593);
        glVertex2f(11.65834, 15.46678);
        glVertex2f(11.43456, 16.64165);
        glVertex2f(11.42057, 16.76752);
        glVertex2f(11.43456, 16.92138);
        glVertex2f(11.48351, 17.09621);
        glVertex2f(11.56743, 17.24307);
        glVertex2f(11.66533, 17.35496);
        glVertex2f(11.77723, 17.48084);
        glVertex2f(11.86814, 17.57874);
        glVertex2f(11.99402, 17.67665);
        glVertex2f(12.1129, 17.74658);
        glVertex2f(12.23878, 17.81651);
        glVertex2f(12.37865, 17.87246);
        glVertex2f(12.54648, 17.9284);
        glVertex2f(12.71432, 17.99134);
        glVertex2f(12.86118, 18.0403);
        glVertex2f(13.05, 18.07526);
        glVertex2f(13.28777, 18.11722);
        glVertex2f(13.47659, 18.1382);
        glVertex2f(13.69338, 18.15918);
        glVertex2f(13.91017, 18.17317);
        glVertex2f(14.07101, 18.16617);
        glVertex2f(14.2948, 18.15918);
        glVertex2f(14.50459, 18.13121);
        glVertex2f(14.68642, 18.11722);
        glVertex2f(14.84027, 18.08226);
        glVertex2f(15.07105, 18.0403);
        glVertex2f(15.31581, 17.97736);
        glVertex2f(15.50463, 17.89344);
        glVertex2f(15.71443, 17.81651);
        glVertex2f(15.88926, 17.71161);
        glVertex2f(16.0501, 17.60671);
        glVertex2f(16.21794, 17.46685);
        glVertex2f(16.3648, 17.29202);
        glVertex2f(16.46271, 17.14516);
        glVertex2f(16.5, 17);
        glVertex2f(16.54662, 16.88641);
        glVertex2f(16.5746, 16.76752);
        glVertex2f(16.31585, 15.48776);
        glVertex2f(16.27389, 15.3409);
        glVertex2f(16.21794, 15.24999);
        glVertex2f(16.11304, 15.1381);
        glVertex2f(16, 15);
    glEnd();
    //kotak bagian depan 1
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(13.5219, 18.39597);
        glVertex2f(13.88155, 18.40362);
        glVertex2f(13.9045, 21.87769);
        glVertex2f(13.5219, 21.87769);
    glEnd();
    //kotak bagian depan 2
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(14.08815, 21.88534);
        glVertex2f(14.4478, 21.88534);
        glVertex2f(14.4325, 18.40362);
        glVertex2f(14.11111, 18.41127);
    glEnd();
    //kotak bagian mata depan 1
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.5, 0.0);
        glVertex2f(12.2539, 21.81034);
        glVertex2f(12.29321, 21.73173);
        glVertex2f(12.27847, 21.62856);
        glVertex2f(12.2539, 21.53521);
        glVertex2f(12.21951, 21.46642);
        glVertex2f(12.19003, 21.37307);
        glVertex2f(12.12125, 21.30429);
        glVertex2f(12.0672, 21.23551);
        glVertex2f(12, 21.2);
        glVertex2f(11.91981, 21.14216);
        glVertex2f(11.83137, 21.09794);
        glVertex2f(11.74785, 21.06354);
        glVertex2f(11.67906, 21.02424);
        glVertex2f(11.6, 21);
        glVertex2f(11.51202, 20.98985);
        glVertex2f(11.43341, 20.99967);
        glVertex2f(11.32532, 20.98985);
        glVertex2f(11.22705, 20.98002);
        glVertex2f(11.12879, 20.99967);
        glVertex2f(11.20351, 21.05732);
        glVertex2f(11.20351, 21.05732);
        glVertex2f(11.24556, 21.11161);
        glVertex2f(11.29879, 21.19477);
        glVertex2f(11.38528, 21.27128);
        glVertex2f(11.49839, 21.35778);
        glVertex2f(11.63145, 21.47088);
        glVertex2f(11.77117, 21.58399);
        glVertex2f(11.89093, 21.64719);
        glVertex2f(12.00854, 21.73181);
        glVertex2f(12.10383, 21.75364);
        glVertex2f(12.17369, 21.78026);
    glEnd();
//kotak bagian mata depan 2
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.5, 0.0);
        glVertex2f(15.69477, 21.83268);
        glVertex2f(15.68518, 21.74636);
        glVertex2f(15.70196, 21.64806);
        glVertex2f(15.71395, 21.57133);
        glVertex2f(15.74752, 21.48981);
        glVertex2f(15.8, 21.4);
        glVertex2f(15.83863, 21.33395);
        glVertex2f(15.88659, 21.27881);
        glVertex2f(15.93934, 21.22845);
        glVertex2f(15.99448, 21.16851);
        glVertex2f(16.06881, 21.13255);
        glVertex2f(16.14314, 21.09418);
        glVertex2f(16.21747, 21.05582);
        glVertex2f(16.29899, 21.02465);
        glVertex2f(16.4, 21);
        glVertex2f(16.48602, 20.98868);
        glVertex2f(16.58432, 20.9743);
        glVertex2f(16.67064, 20.9695);
        glVertex2f(16.74497, 20.9647);
        glVertex2f(16.81211, 20.9719);
        glVertex2f(16.86246, 21.01026);
    glEnd();
    //kaca samping kiri
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(11.72245, 10.2255);
        glVertex2f(11.74672, 10.40513);
        glVertex2f(11.82439, 11.67219);
        glVertex2f(11.82925, 11.91492);
        glVertex2f(11.82439, 12.17221);
        glVertex2f(11.82925, 12.40524);
        glVertex2f(11.80498, 12.67224);
        glVertex2f(11.78556, 12.90041);
        glVertex2f(11.77099, 13.13343);
        glVertex2f(11.73701, 13.43442);
        glVertex2f(11.71274, 13.68201);
        glVertex2f(11.67875, 13.92959);
        glVertex2f(11.65448, 14.11892);
        glVertex2f(11.61079, 14.33253);
        glVertex2f(11.55739, 14.60924);
        glVertex2f(11.48942, 14.82284);
        glVertex2f(11.45544, 14.9879);
        glVertex2f(11.4, 15.2);
        glVertex2f(11.30009, 15.44909);
        glVertex2f(11.24184, 15.58988);
        glVertex2f(11.13989, 15.73552);
        glVertex2f(11.13018, 12.14794);
        glVertex2f(11.13018, 11.91977);
        glVertex2f(11.12047, 11.6916);
        glVertex2f(11.12047, 11.478);
        glVertex2f(11.13018, 11.23041);
        glVertex2f(11.16902, 11.05079);
        glVertex2f(11.22727, 10.82748);
        glVertex2f(11.30009, 10.62844);
        glVertex2f(11.38748, 10.48766);
        glVertex2f(11.52341, 10.35173);
    glEnd();
    //kaca samping kanan
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(16.27606, 10.2274);
        glVertex2f(16.15751, 11.67376);
        glVertex2f(16.16344, 11.9168);
        glVertex2f(16.16936, 12.13612);
        glVertex2f(16.16344, 12.34359);
        glVertex2f(16.17529, 12.56885);
        glVertex2f(16.199, 12.80003);
        glVertex2f(16.21678, 13.06085);
        glVertex2f(16.23457, 13.3513);
        glVertex2f(16.28199, 13.6714);
        glVertex2f(16.31756, 14.00335);
        glVertex2f(16.38276, 14.29381);
        glVertex2f(16.43611, 14.57834);
        glVertex2f(16.49539, 14.81545);
        glVertex2f(16.56059, 15.08813);
        glVertex2f(16.64951, 15.34302);
        glVertex2f(16.7325, 15.56234);
        glVertex2f(16.84512, 15.72832);
        glVertex2f(16.84512, 12.15391);
        glVertex2f(16.85698, 11.89901);
        glVertex2f(16.86291, 11.68562);
        glVertex2f(16.86291, 11.53742);
        glVertex2f(16.85698, 11.37145);
        glVertex2f(16.85105, 11.21733);
        glVertex2f(16.81548, 11.04542);
        glVertex2f(16.79177, 10.87352);
        glVertex2f(16.72657, 10.71347);
        glVertex2f(16.64358, 10.56528);
        glVertex2f(16.56652, 10.44672);
        glVertex2f(16.47168, 10.3341);
    glEnd();
    glPopMatrix();
}
void mobilmusuh(){
    glPushMatrix();
    glTranslated(10.0,0.0,0.0);//120
    glScaled(1.5,1,0);
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2f(11.07685, 6.48686);
        glVertex2f(10.98593, 6.87129);
        glVertex2f(10.8989, 7.19765);
        glVertex2f(10.76835, 7.63281);
        glVertex2f(10.68132, 8.00269);
        glVertex2f(10.59429, 8.48136);
        glVertex2f(10.55078, 8.91651);
        glVertex2f(10.50726, 9.41694);
        glVertex2f(10.50726, 9.93913);
        glVertex2f(10.55078, 10.37428);
        glVertex2f(10.59429, 10.93998);
        glVertex2f(10.61605, 11.46217);
        glVertex2f(10.68132, 12.02787);
        glVertex2f(10.66605, 13.52131);
        glVertex2f(10.70308, 15.26977);
        glVertex2f(10.09387, 15.13922);
        glVertex2f(10.10246, 15.61254);
        glVertex2f(10.68132, 15.81371);
        glVertex2f(10.70308, 17.6196);
        glVertex2f(10.55078, 17.92421);
        glVertex2f(10.46375, 18.3376);
        glVertex2f(10.46375, 18.77276);
        glVertex2f(10.4855, 19.1644);
        glVertex2f(10.52902, 19.57779);
        glVertex2f(10.65957, 20.09998);
        glVertex2f(10.83363, 20.4481);
        glVertex2f(11.00769, 20.77447);
        glVertex2f(11.20351, 21.05732);
        glVertex2f(11.42109, 21.34017);
        glVertex2f(11.70394, 21.55775);
        glVertex2f(12.00854, 21.73181);
        glVertex2f(12.33491, 21.86235);
        glVertex2f(12.63952, 21.9929);
        glVertex2f(12.96588, 22.07993);
        glVertex2f(13.35752, 22.12345);
        glVertex2f(13.70565, 22.12345);
        glVertex2f(14.33662, 22.10169);
        glVertex2f(14.75002, 22.01466);
        glVertex2f(15.07638, 21.97114);
        glVertex2f(15.44626, 21.90587);
        glVertex2f(15.85966, 21.73181);
        glVertex2f(16.20778, 21.55775);
        glVertex2f(16.46888, 21.31841);
        glVertex2f(16.75173, 21.10083);
        glVertex2f(16.99106, 20.7092);
        glVertex2f(17.18688, 20.40459);
        glVertex2f(17.33918, 20.07822);
        glVertex2f(17.3827, 19.75186);
        glVertex2f(17.44797, 19.42549);
        glVertex2f(17.46973, 18.09827);

        glVertex2f(17.29567, 15.90074);
        glVertex2f(17.86137, 15.59613);
        glVertex2f(17.83961, 15.16098);

        glVertex2f(17.33918, 12.02787);
        glVertex2f(17.33918, 11.65799);
        glVertex2f(17.36094, 11.24459);
        glVertex2f(17.3827, 10.85295);
        glVertex2f(17.40446, 10.46131);
        glVertex2f(17.44797, 10.13495);
        glVertex2f(17.44797, 9.80858);
        glVertex2f(17.42622, 9.39518);
        glVertex2f(17.42622, 9.04706);
        glVertex2f(17.36094, 8.56839);
        glVertex2f(17.33918, 8.19851);
        glVertex2f(17.2304, 7.85039);
        glVertex2f(17.12161, 7.45875);
        glVertex2f(17.05633, 7.13238);
        glVertex2f(16.9693, 6.78426);
        glVertex2f(16.83876, 6.43613);
        glVertex2f(16.49063, 6.26207);
        glVertex2f(15.72911, 6.13153);
        glVertex2f(14.96759, 6.08801);
        glVertex2f(14, 6);
        glVertex2f(13.20522, 6.06625);
        glVertex2f(12.61776, 6.08801);
        glVertex2f(12.26964, 6.10977);
        glVertex2f(11.72569, 6.24032);
    glEnd();
    //jendela belakang
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(12.21944, 8.13208);
        glVertex2f(12.00445, 9.5352);
        glVertex2f(12.06382, 9.6837);
        glVertex2f(12.14392, 9.79812);
        glVertex2f(12.29267, 9.88966);
        glVertex2f(15.6511, 9.90683);
        glVertex2f(15.79413, 9.83817);
        glVertex2f(15.92, 9.72375);
        glVertex2f(15.97721, 9.56927);
        glVertex2f(15.7598, 8.11605);
        glVertex2f(15.66254, 7.93869);
        glVertex2f(15.56528, 7.84715);
        glVertex2f(15.43369, 7.72128);
        glVertex2f(15.31354, 7.65262);
        glVertex2f(15.15906, 7.57824);
        glVertex2f(15, 7.5);
        glVertex2f(14.86155, 7.46382);
        glVertex2f(14.72996, 7.42949);
        glVertex2f(14.58121, 7.38944);
        glVertex2f(14.42101, 7.35511);
        glVertex2f(14.22648, 7.34939);
        glVertex2f(14.05484, 7.33795);
        glVertex2f(13.86032, 7.33795);
        glVertex2f(13.65435, 7.34939);
        glVertex2f(13.52848, 7.36083);
        glVertex2f(13.40261, 7.38944);
        glVertex2f(13.2653, 7.42377);
        glVertex2f(13.09938, 7.46382);
        glVertex2f(13, 7.5);
        glVertex2f(12.8648, 7.54964);
        glVertex2f(12.73894, 7.61829);
        glVertex2f(12.60734, 7.69839);
        glVertex2f(12.47575, 7.76705);
        glVertex2f(12.4071, 7.85859);
        glVertex2f(12.33272, 7.93297);
        glVertex2f(12.26406, 8.03595);

    glEnd();
    //kotak bagian belakang
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(13.5417, 7.10975);
        glVertex2f(13.90045, 7.12329);
        glVertex2f(13.88692, 6.41933);
        glVertex2f(13.52817, 6.41933);
    glEnd();
        //kotak bagian belakang 2
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(14.09675, 7.13006);
        glVertex2f(14.44873, 7.12329);
        glVertex2f(14.46227, 6.4261);
        glVertex2f(14.08321, 6.4261);
    glEnd();
        //kotak bagian tengah 1
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(13.54091, 14.75579);
        glVertex2f(13.89155, 14.74702);
        glVertex2f(13.87401, 10.07481);
        glVertex2f(13.52338, 10.06605);
    glEnd();
        //kotak bagian tengah 2
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(14.08439, 14.74702);
        glVertex2f(14.46133, 14.73826);
        glVertex2f(14.45256, 10.07481);
        glVertex2f(14.10193, 10.06605);
    glEnd();
    //kaca bagian depan
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(12, 15);
        glVertex2f(11.9101, 15.08215);
        glVertex2f(11.81918, 15.18006);
        glVertex2f(11.74925, 15.30593);
        glVertex2f(11.65834, 15.46678);
        glVertex2f(11.43456, 16.64165);
        glVertex2f(11.42057, 16.76752);
        glVertex2f(11.43456, 16.92138);
        glVertex2f(11.48351, 17.09621);
        glVertex2f(11.56743, 17.24307);
        glVertex2f(11.66533, 17.35496);
        glVertex2f(11.77723, 17.48084);
        glVertex2f(11.86814, 17.57874);
        glVertex2f(11.99402, 17.67665);
        glVertex2f(12.1129, 17.74658);
        glVertex2f(12.23878, 17.81651);
        glVertex2f(12.37865, 17.87246);
        glVertex2f(12.54648, 17.9284);
        glVertex2f(12.71432, 17.99134);
        glVertex2f(12.86118, 18.0403);
        glVertex2f(13.05, 18.07526);
        glVertex2f(13.28777, 18.11722);
        glVertex2f(13.47659, 18.1382);
        glVertex2f(13.69338, 18.15918);
        glVertex2f(13.91017, 18.17317);
        glVertex2f(14.07101, 18.16617);
        glVertex2f(14.2948, 18.15918);
        glVertex2f(14.50459, 18.13121);
        glVertex2f(14.68642, 18.11722);
        glVertex2f(14.84027, 18.08226);
        glVertex2f(15.07105, 18.0403);
        glVertex2f(15.31581, 17.97736);
        glVertex2f(15.50463, 17.89344);
        glVertex2f(15.71443, 17.81651);
        glVertex2f(15.88926, 17.71161);
        glVertex2f(16.0501, 17.60671);
        glVertex2f(16.21794, 17.46685);
        glVertex2f(16.3648, 17.29202);
        glVertex2f(16.46271, 17.14516);
        glVertex2f(16.5, 17);
        glVertex2f(16.54662, 16.88641);
        glVertex2f(16.5746, 16.76752);
        glVertex2f(16.31585, 15.48776);
        glVertex2f(16.27389, 15.3409);
        glVertex2f(16.21794, 15.24999);
        glVertex2f(16.11304, 15.1381);
        glVertex2f(16, 15);
    glEnd();
    //kotak bagian depan 1
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(13.5219, 18.39597);
        glVertex2f(13.88155, 18.40362);
        glVertex2f(13.9045, 21.87769);
        glVertex2f(13.5219, 21.87769);
    glEnd();
    //kotak bagian depan 2
    glBegin(GL_POLYGON);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2f(14.08815, 21.88534);
        glVertex2f(14.4478, 21.88534);
        glVertex2f(14.4325, 18.40362);
        glVertex2f(14.11111, 18.41127);
    glEnd();
    //kotak bagian mata depan 1
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.5, 0.0);
        glVertex2f(12.2539, 21.81034);
        glVertex2f(12.29321, 21.73173);
        glVertex2f(12.27847, 21.62856);
        glVertex2f(12.2539, 21.53521);
        glVertex2f(12.21951, 21.46642);
        glVertex2f(12.19003, 21.37307);
        glVertex2f(12.12125, 21.30429);
        glVertex2f(12.0672, 21.23551);
        glVertex2f(12, 21.2);
        glVertex2f(11.91981, 21.14216);
        glVertex2f(11.83137, 21.09794);
        glVertex2f(11.74785, 21.06354);
        glVertex2f(11.67906, 21.02424);
        glVertex2f(11.6, 21);
        glVertex2f(11.51202, 20.98985);
        glVertex2f(11.43341, 20.99967);
        glVertex2f(11.32532, 20.98985);
        glVertex2f(11.22705, 20.98002);
        glVertex2f(11.12879, 20.99967);
        glVertex2f(11.20351, 21.05732);
        glVertex2f(11.20351, 21.05732);
        glVertex2f(11.24556, 21.11161);
        glVertex2f(11.29879, 21.19477);
        glVertex2f(11.38528, 21.27128);
        glVertex2f(11.49839, 21.35778);
        glVertex2f(11.63145, 21.47088);
        glVertex2f(11.77117, 21.58399);
        glVertex2f(11.89093, 21.64719);
        glVertex2f(12.00854, 21.73181);
        glVertex2f(12.10383, 21.75364);
        glVertex2f(12.17369, 21.78026);
    glEnd();
//kotak bagian mata depan 2
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.5, 0.0);
        glVertex2f(15.69477, 21.83268);
        glVertex2f(15.68518, 21.74636);
        glVertex2f(15.70196, 21.64806);
        glVertex2f(15.71395, 21.57133);
        glVertex2f(15.74752, 21.48981);
        glVertex2f(15.8, 21.4);
        glVertex2f(15.83863, 21.33395);
        glVertex2f(15.88659, 21.27881);
        glVertex2f(15.93934, 21.22845);
        glVertex2f(15.99448, 21.16851);
        glVertex2f(16.06881, 21.13255);
        glVertex2f(16.14314, 21.09418);
        glVertex2f(16.21747, 21.05582);
        glVertex2f(16.29899, 21.02465);
        glVertex2f(16.4, 21);
        glVertex2f(16.48602, 20.98868);
        glVertex2f(16.58432, 20.9743);
        glVertex2f(16.67064, 20.9695);
        glVertex2f(16.74497, 20.9647);
        glVertex2f(16.81211, 20.9719);
        glVertex2f(16.86246, 21.01026);
    glEnd();
    //kaca samping kiri
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(11.72245, 10.2255);
        glVertex2f(11.74672, 10.40513);
        glVertex2f(11.82439, 11.67219);
        glVertex2f(11.82925, 11.91492);
        glVertex2f(11.82439, 12.17221);
        glVertex2f(11.82925, 12.40524);
        glVertex2f(11.80498, 12.67224);
        glVertex2f(11.78556, 12.90041);
        glVertex2f(11.77099, 13.13343);
        glVertex2f(11.73701, 13.43442);
        glVertex2f(11.71274, 13.68201);
        glVertex2f(11.67875, 13.92959);
        glVertex2f(11.65448, 14.11892);
        glVertex2f(11.61079, 14.33253);
        glVertex2f(11.55739, 14.60924);
        glVertex2f(11.48942, 14.82284);
        glVertex2f(11.45544, 14.9879);
        glVertex2f(11.4, 15.2);
        glVertex2f(11.30009, 15.44909);
        glVertex2f(11.24184, 15.58988);
        glVertex2f(11.13989, 15.73552);
        glVertex2f(11.13018, 12.14794);
        glVertex2f(11.13018, 11.91977);
        glVertex2f(11.12047, 11.6916);
        glVertex2f(11.12047, 11.478);
        glVertex2f(11.13018, 11.23041);
        glVertex2f(11.16902, 11.05079);
        glVertex2f(11.22727, 10.82748);
        glVertex2f(11.30009, 10.62844);
        glVertex2f(11.38748, 10.48766);
        glVertex2f(11.52341, 10.35173);
    glEnd();
    //kaca samping kanan
    glBegin(GL_POLYGON);
        glColor3f(0.75, 0.75, 0.75);
        glVertex2f(16.27606, 10.2274);
        glVertex2f(16.15751, 11.67376);
        glVertex2f(16.16344, 11.9168);
        glVertex2f(16.16936, 12.13612);
        glVertex2f(16.16344, 12.34359);
        glVertex2f(16.17529, 12.56885);
        glVertex2f(16.199, 12.80003);
        glVertex2f(16.21678, 13.06085);
        glVertex2f(16.23457, 13.3513);
        glVertex2f(16.28199, 13.6714);
        glVertex2f(16.31756, 14.00335);
        glVertex2f(16.38276, 14.29381);
        glVertex2f(16.43611, 14.57834);
        glVertex2f(16.49539, 14.81545);
        glVertex2f(16.56059, 15.08813);
        glVertex2f(16.64951, 15.34302);
        glVertex2f(16.7325, 15.56234);
        glVertex2f(16.84512, 15.72832);
        glVertex2f(16.84512, 12.15391);
        glVertex2f(16.85698, 11.89901);
        glVertex2f(16.86291, 11.68562);
        glVertex2f(16.86291, 11.53742);
        glVertex2f(16.85698, 11.37145);
        glVertex2f(16.85105, 11.21733);
        glVertex2f(16.81548, 11.04542);
        glVertex2f(16.79177, 10.87352);
        glVertex2f(16.72657, 10.71347);
        glVertex2f(16.64358, 10.56528);
        glVertex2f(16.56652, 10.44672);
        glVertex2f(16.47168, 10.3341);
    glEnd();
    glPopMatrix();
}
void kotakCollision(){
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glColor4f(0.0,0.0,0.0,0.0);
        glVertex2f(24.5,2.4);
        glVertex2f(24.5,13.8);
        glVertex2f(35.5,13.8);
        glVertex2f(35.5,2.4);
    glEnd();
    glPopMatrix();
}
void kotakCollisionmusuh(){
    glPushMatrix();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
        glColor4f(0.0,0.0,0.0,0.0);
        glVertex2f(25.35,6);
        glVertex2f(25.35,22.12);
        glVertex2f(36.7,22.12);
        glVertex2f(36.7,6);
    glEnd();
    glPopMatrix();
}
void scoreboard(){
    glPushMatrix();
        glBegin(GL_QUADS);
            glColor3f(1.0,1.0,1.0);
            glVertex2f(30,80);
            glVertex2f(90,80);
            glVertex2f(90,40);
            glVertex2f(30,40);
        glEnd();
        glBegin(GL_LINES);
            glColor3f(0.0,0.0,0.0);
            glVertex2f(40,70);
            glVertex2f(80,70);
        glEnd();
        tulis(48,73,"GAME OVER");
        tulis3(40,62,"Score : ");
        glBegin(GL_LINES);
            glColor3f(0.0,0.0,0.0);
            glVertex2f(40,55);
            glVertex2f(80,55);
        glEnd();
        tulis3(44,50,"THANK YOU FOR PLAYING");
    glPopMatrix();
}
void iconhealth(){
    int jaraknya = 3;
    int kiri = 1;
    int kanan = 4;
    int atas = 119;
    int bawah = 115;
    for(int i=0;i<health;i++){
        glPushMatrix();
        glBegin(GL_QUADS);
            glColor3ub(250, 17, 0);
            glVertex2f(kiri,atas);
            glVertex2f(kanan,atas);
            glVertex2f(kanan,bawah);
            glVertex2f(kiri,bawah);
        glEnd();
        glPopMatrix();
        kiri+=4;
        kanan+=4;
    }
}
void tombolStart(int posisix,int posisiy){
    menux=posisix;
    menuy=posisiy;
    glBegin(GL_QUADS);
        glColor3ub(52,235,58);
        glVertex2f(posisix,posisiy);
        glVertex2f(posisix,posisiy+11);
        glVertex2f(posisix+30,posisiy+11);
        glVertex2f(posisix+30,posisiy);
    glEnd();
    glPushMatrix();
        glColor3ub(0,0,0);
        tulis2(posisix+6,posisiy+4,"START");
    glPopMatrix();
}
void menu(void){
    glClear(GL_COLOR_BUFFER_BIT);
    tombolStart(45,60);
    glFlush();
}
void myKeyboard(int key,int x,int y){
    if(checkgame==true){
    switch(key){
    case GLUT_KEY_UP:
        if(yyy>100){
            yyy+=0;
        }else{
            yyy+=2.0;
        }
        printf("%f yUp\n",yyy+13.8);
        printf("%f yDown\n",yyy+2.4);
        break;
    case GLUT_KEY_RIGHT:
        if(xxx>60){
            xxx +=0;
        }else{
            xxx += 2.0;
        }
        printf("%f xleft\n",xxx+24.5);
        printf("%f xright\n",xxx+35.5);
        break;
    case GLUT_KEY_LEFT:
        if(xxx<0){
            xxx -=0;
        }else{
            xxx -= 2.0;
        }
        printf("%f xleft\n",xxx+24.5);
        printf("%f xright\n",xxx+35.5);
        break;
    case GLUT_KEY_DOWN:
        if(yyy<0){
            yyy-=0;
        }else{
            yyy-=2.0;
        }
        printf("%f yUp\n",yyy+13.8);
        printf("%f yDown\n",yyy+2.4);
        break;
    }
    glutPostRedisplay();
    }
}
void glCollision(){
    if(collision==true){
        health=health-1;
    }
}
void myTimeOut(int id){
    hitungscore++;
    musuh=musuh-1.5;
    musuh2=musuh2-1.5;
    if((hitungscore%10)==0){
        score++;
        if(respawn<6){
            respawn++;
            if(respawn==6){collision=false;}
        }
    }
    gerak-=1.5;
    if(gerak<-210){
       gerak=0;
    }

    if(musuh<=-30){
       posisi1 = rand() % 4;
       musuh = rand() % 120 + 150;
    }
    if(musuh2<=-30){
        posisi2 = rand() % 4;
        musuh2 = rand()  % 120 + 150;
    }

    avxLeft = 24.5 + xxx;
    avxRight = 35.5 + xxx;
    avyDown = 2.4 + yyy;
    avyUp = 13.8 +yyy;

    mhxLeft = 25.35 + arr[posisi1];
    mhxRight = 36.7 + arr[posisi1];
    mhyUp = 22.12 + musuh;
    mhyDown = 6 +musuh;

    mhxLeft2 = 25.35 + arr[posisi2];
    mhxRight2 = 36.7 + arr[posisi2];
    mhyUp2 = 22.12 + musuh2;
    mhyDown2 = 6 +musuh2;

    if(collision==false && respawn%6==0){
    if(((avxLeft<=mhxRight && avxLeft>=mhxLeft)|| (avxRight>=mhxLeft && avxRight<=mhxRight)) && ((avyUp>=mhyDown && avyUp<=mhyUp) || (avyDown<=mhyUp && avyDown>=mhyDown)) ) {collision=true;glCollision();respawn=0;}
    else if(((avxLeft<=mhxRight2 && avxLeft>=mhxLeft2)|| (avxRight>=mhxLeft2 && avxRight<=mhxRight2)) && ((avyUp>=mhyDown2 && avyUp<=mhyUp2 ) || (avyDown<=mhyUp2 && avyDown>=mhyDown2)) ) {collision=true;glCollision();respawn=0;}
    }
    //printf("%f xLeftMusuh\n",25.35+arr[posisi1]);
    if(health==0)checkgame=false;
    glutPostRedisplay();
    if(checkgame==true)glutTimerFunc(1, myTimeOut, 0); // request next timer event
}
void scoredisplay (int posx, int posy, int posz, int space_char, int scorevar){
        int j=0,p,k;
        GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;

        p = scorevar;
        j = 0;
        k = 0;
        while(p > 9)
        {
            k = p % 10;
            glRasterPos3f ((posx-(j*space_char)),posy, posz);
            glutBitmapCharacter(font_style1,48+k);
            j++;
            p /= 10;
        }
            glRasterPos3f ((posx-(j*space_char)), posy, posz);
            glutBitmapCharacter(font_style1,48+p);

}
void nyawa(int posx, int posy, int posz, int space_char, int scorevar){
        int j=0,p,k;
        GLvoid *font_style1 = GLUT_BITMAP_TIMES_ROMAN_24;

        p = scorevar;
        j = 0;
        k = 0;
        while(p > 9)
        {
            k = p % 10;
            glRasterPos3f ((posx-(j*space_char)),posy, posz);
            glutBitmapCharacter(font_style1,48+k);
            j++;
            p /= 10;
        }
            glRasterPos3f ((posx-(j*space_char)), posy, posz);
            glutBitmapCharacter(font_style1,48+p);

}
void display(void){
    glClear(GL_COLOR_BUFFER_BIT|GL_DOUBLEBUFFER);
    glPushMatrix();
        glTranslated(0.0,gerak,0.0);
        grass();
    glPopMatrix();
    jalan();
    glPushMatrix();
        glTranslated(0.0,gerak,0.0);
        marka();
    glPopMatrix();
    glPushMatrix();
        if(respawn<6 && respawn%2!=0){

        }else{
            iconhealth();
        }
    glPopMatrix();
    glPushMatrix();
        glTranslated(arr[posisi1],musuh,0.0);
        kotakCollisionmusuh();
        mobilmusuh();
    glPopMatrix();
    glPushMatrix();
        glTranslated(arr[posisi2],musuh2,0.0);
        kotakCollisionmusuh();
        mobilmusuh();
    glPopMatrix();
    glPushMatrix();
        glTranslated(xxx,yyy,0.0);
        kotakCollision();
        if(respawn<6 && respawn%2!=0){

        }else{
            mobilpolisi();
        }
    glPopMatrix();
    if(checkgame==true){
        scoredisplay(117,117,0,3,score);
        //nyawa(2,117,0,3,health);
    }
    if(checkgame == false){
        scoreboard();
        scoredisplay(72,61,0,3,score);
    }
    glFlush();
}
void mouse(int button, int state, int mousex, int mousey){
    int width, height;
    width  = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);
    int x; int y;
    if(checkmenu==false){
        if(button==GLUT_LEFT_BUTTON && state==GLUT_ENTERED && ((mousex/5)>=menux && (mousex/5)<=menux+30) && (-((mousey-720)/6)>=menuy && -((mousey-720)/6)<=menuy+11)){
            glutDisplayFunc(display);
            glutTimerFunc(1,myTimeOut,0);
            checkmenu = true;
            checkgame= true;
        }
    }
    printf(" \n");
    printf("%i width\n", width);
    printf("%i height\n", height);
    printf("%i mouse x\n", mousex);
    printf("%i mouse y\n", mousey);
    printf("%i mouse x baru\n", mousex/5);
    printf("%i mouse y baru\n", -(mousey-720)/6);
    glutPostRedisplay();
}
int main(int argc,char**argv){
    glutInit(&argc,argv);
    glutInitWindowSize(600,720);
    glutInitWindowPosition(500,80);
    glutCreateWindow("Car Game");
    glutDisplayFunc(menu);
    glutMouseFunc(mouse);
    glutSpecialFunc(myKeyboard);
    gluOrtho2D(0,xx,0,xx);
    glClearColor(1,1,1,1);//Warna Background
    glutTimerFunc(1, 0, 0);
    glutMainLoop();
}
