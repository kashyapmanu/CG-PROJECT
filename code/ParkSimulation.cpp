#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define PI 3.1416

int flag = 0;
static GLfloat spin = 0.0;

static float tx = 0.0, bx = 0.0, by = 0.0, isbaby = 0, swing = 0, glUp = 1, angle = 0;
static float step = 0, stepx = 0, stepy = 0, cloudLeftMove = 0, cloudleftx = 0, cloudmiddlex = 0, cloudrightx = 0, cloudrightupx = 0, countSwing = 0;
static float ty = 5.0, m = 0;
static float xx = 10, yy = 13;

void baby();

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for (i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f(cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void halfcircle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for (i = 0; i < 51; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f(cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void sky()
{
    glPushMatrix();
    glColor3f(0.53f, 0.807f, 0.98f);
    glTranslated(0, 10, 1),
    glBegin(GL_QUADS);
    glVertex2d(-150.0, 0.0);
    glVertex2d(150.0, 0.0);
    glVertex2d(150.0, -8);
    glVertex2d(-150.0, -8);
    glEnd();
    glPopMatrix();
}

void hillSide()
{
    glPushMatrix();
    glScaled(1, 0.6, 0);
    glPushMatrix();
    glTranslated(-9.5, 0.0, 1);
    glColor3f(0.42, 0.56, 0.137);
    glTranslatef(0, 5, 0);
    halfcircle(12, 5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(8.5, 0.0, 1);
    glColor3f(0.0, 1.0, 0);
    glTranslatef(0, 5, 0);
    halfcircle(15, 7);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-4.5, 0.0, 1);
    glColor3f(0.68, 1, 0.184);
    glTranslatef(0, 5, 0);
    halfcircle(6, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-13.4, 5, 1);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.0, 0.0);
    glVertex2f(4.0, 1.75);
    glVertex2f(5.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.2, 5, 1);
    glRotated(180, 0, 1, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(1.0, 0.0);
    glVertex2f(4.0, 1.78);
    glVertex2f(5.0, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void hillTree()
{
    glPushMatrix(); //Big tree
    glTranslated(-15, 6, 0);
    glScaled(0.5, 0.2, 0);
    glPushMatrix();
    glTranslated(-1, -10, 1);
    glColor3f(0.55, 0.27, 0.0745);
    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 10.0);
    glVertex2d(1.0, 10.0);
    glVertex2d(1.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(-0.5, 0, 0);
    glScaled(0.4, 1, 1);
    glPushMatrix();
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(7, 6);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5, 1.0, 1);
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(3, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.0, 4.0, 1);
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(3, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5, -0.5, 1);
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(4, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.0, 4.0, 1);
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(3, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(0.0, 6.0, 1);
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(4, 2);
    glPopMatrix();

    glPushMatrix();
    glTranslated(-5.5, -3.0, 1);
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(4, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(5.5, -3.5, 1);
    glColor3f(0.0, 0.39, 0);
    glTranslatef(0, 5, 0);
    circle(3, 2);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void field()
{

    glPushMatrix();
    glColor3f(0.4, 0.8039, 0);
    glBegin(GL_QUADS);
    glVertex2d(-150.0, 0.0);
    glVertex2d(150.0, 8.0);
    glVertex2d(150.0, -50);
    glVertex2d(-150.0, -50);
    glEnd();
    glPopMatrix();
}

void path() 
{

    glPushMatrix();
    glColor3f(0.43, 0.2588, 0.078);
    glBegin(GL_QUADS);
    glVertex2d(-21.0, -2.5);
    glVertex2d(21.0, -2.5);
    glVertex2d(21.0, -4.5);
    glVertex2d(-21.0, -4.5);
    glEnd();
    glPopMatrix();
}

void person()
{
    m += 0.005;
    if (m > 40)
    {
        m = 2;
    }
    glPushMatrix();

    glTranslated(-21 + m ,-1,0);
    glScalef(0.04, 0.06, 0);
    
    glPushMatrix(); 
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(-6, -6);
    glVertex2d(-11, -9);
    glVertex2d(-9, -13);
    glVertex2d(-6, -11);
    glVertex2d(-6, -22);
    glVertex2d(6, -22);
    glVertex2d(6, -11);
    glVertex2d(9, -13);
    glVertex2d(11, -9);
    glVertex2d(6, -6);
    glVertex2d(4, -10);
    glVertex2d(-4, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left hand
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(-11, -9);
    glVertex2d(-9, -13);
    glVertex2d(-13, -20);
    glVertex2d(-16, -18);
    glEnd();

    glPopMatrix();

    glPushMatrix(); //left hand palm
    glTranslated(-15, -20, 0);
    glColor3f(0.87, 0.72, 0.53);
    circle(3, 2.5);
    glPopMatrix();

    glPushMatrix(); //right hand
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(11, -9);
    glVertex2d(9, -13);
    glVertex2d(13, -20);
    glVertex2d(16, -18);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right hand palm
    glTranslated(15, -20, 0);
    glColor3f(0.87, 0.72, 0.53);
    circle(3, 2.5);
    glPopMatrix();

    glPushMatrix(); //skirt
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2d(-6, -22);
    glVertex2d(6, -22);
    glVertex2d(13, -32);
    glVertex2d(-13, -32);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left leg
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(-6, -32);
    glVertex2d(-2, -32);
    glVertex2d(-2, -38);
    glVertex2d(-6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right leg
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(6, -32);
    glVertex2d(2, -32);
    glVertex2d(2, -38);
    glVertex2d(6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right shoe
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(10, -42);
    glVertex2d(2, -42);
    glVertex2d(2, -38);
    glVertex2d(6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left shoe
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(-10, -42);
    glVertex2d(-2, -42);
    glVertex2d(-2, -38);
    glVertex2d(-6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //hair
    glColor3f(0, 0, 0);
    circle(9, 10);
    glPopMatrix();

    glPushMatrix(); //head, neck, nose ,eye, lips
    glColor3f(0.87, 0.72, 0.53);
    circle(7, 6);      //head
    glBegin(GL_QUADS); //neck
    glVertex2d(-6, -6);
    glVertex2d(6, -6);
    glVertex2d(4, -10);
    glVertex2d(-4, -10);
    glEnd();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES); //right eye

    glVertex2d(4, 3);
    glVertex2d(1, 3);

    glEnd();
    glBegin(GL_LINES); //lips

    glVertex2d(2, -3);
    glVertex2d(-2, -3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES); //left eye

    glVertex2d(-4, 3);
    glVertex2d(-1, 3);

    glEnd();
    circle(0.5, 2); //nose
    glPopMatrix();

    glPopMatrix();
    
    glPopMatrix();
}

void sun()
{
    glPushMatrix();
    glTranslated(-4, 8, 0);
    glScaled(0.3, 0.3, 0);
    glColor3f(1, 0.843, 0);
    circle(3.5, 3.5);
    glPopMatrix();
}

void cloudLeft()
{
    cloudleftx = cloudleftx - 0.01;
    if (cloudleftx < -4)
    {
        cloudleftx = 40;
    }

    glPushMatrix();
    glTranslated(-20 + cloudleftx, 8.5, 1);
    glScaled(0.5, 0.2, 1);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslated(0, 0, 1),
        circle(1.5, 2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1.5, 1, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4, 1.5, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5, -0.7, 1),
        circle(2.5, 2.0);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.0, -1.0, 1),
        circle(1.5, 2.5);
    glPopMatrix();
    glPopMatrix();
}

void cloudRightUp()
{
    glPushMatrix();
    glTranslated(14, 16.5, 1);
    glScaled(0.5, 0.2, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslated(0, -38, 1),
        circle(1.5, 2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1, -35, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();

    glTranslated(3, -35, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();

    glTranslated(4.5, -37.5, 1);
    circle(1.5, 2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5, -38.5, 1),
        circle(1.5, 2.5);
    glPopMatrix();
    glPopMatrix();
}

void cloudRight()
{

    cloudrightx -= 0.02;
    if (cloudrightx < -35)
    {
        cloudrightx = 2;
    }


    glPushMatrix();
    glTranslated(12 + cloudrightx, 16, 1);
    glScaled(0.5, 0.2, 1);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslated(0, -38, 1),
        circle(1.5, 2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1, -35, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3, -35, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5, -37.5, 1),
        circle(1.5, 2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5, -38.5, 1),
        circle(1.5, 2.5);
    glPopMatrix();
    glPopMatrix();
}

void cloudMiddle()
{
    cloudmiddlex = cloudmiddlex - 0.03;
    if (cloudmiddlex < -20)
    {
        cloudmiddlex = 30;
    }
 
    glPushMatrix();
    glTranslated(-3.5 + cloudmiddlex, 16, 1);
    glScaled(0.5, 0.2, 1);
    glColor3f(1.0f, 1.0f, 1.0f);
    glPushMatrix();
    glTranslated(0, -38, 1),
        circle(1.5, 2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(1, -35, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3, -35, 1),
        circle(2, 3);
    glPopMatrix();

    glPushMatrix();
    glTranslated(4.5, -37.5, 1),
        circle(1.5, 2.5);
    glPopMatrix();

    glPushMatrix();
    glTranslated(2.5, -38.5, 1),
        circle(1.5, 2.5);
    glPopMatrix();
    glPopMatrix();
}

void babySwing()
{
    glPushMatrix();

    if (isbaby == 1 )
    {

        if (swing == 0)
        {
            glTranslated(-14, 1, 0);
            glScaled(0.05, 0.05, 0);
        }
        else if (swing >= 1)
        {
            glTranslated(-14, -0.4 + swing, 0);
            glScaled(0.04, 0.04, 0);
            swing = -0.1;
        }
        else if (swing <= -1)
        {
            glTranslated(-14, 2.4 + swing, 0);
            glScaled(0.06, 0.06, 0);
            swing = 0.1;
        }
        else if (swing > 0.1 && swing < 1)
        {
            glTranslated(0, -0.29 + swing, 0);
            glTranslated(-14, 1, 0);
            glScaled(0.05, 0.05, 0);
            countSwing++;
       }

        else if (swing < -0.1 && swing > -1)
        {
            glTranslated(-14, 1.35 + swing, 0);
            glScaled(0.05, 0.05, 0);
        }

        glPushMatrix(); // top
        glRotated(-20, 0, 1, 0);
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2d(-6, -6);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-6, -11);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(6, -11);
        glVertex2d(9, -13);
        glVertex2d(11, -9);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left hand
        glRotated(-20, 0, 1, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-13, -20);
        glVertex2d(-16, -18);
        glEnd();

        glPopMatrix();

        glPushMatrix(); //left hand palm
        glRotated(-20, 0, 1, 0);
        glTranslated(-15, -20, 0);
        glColor3f(0.87, 0.72, 0.53);
        circle(3, 2.5);
        glPopMatrix();

        glPushMatrix(); //right hand
        glRotated(-20, 0, 1, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(11, -9);
        glVertex2d(9, -13);
        glVertex2d(13, -20);
        glVertex2d(16, -18);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right hand palm
        glRotated(-20, 0, 1, 0);
        glTranslated(15, -20, 0);

        glColor3f(0.87, 0.72, 0.53);
        circle(3, 2.5);
        glPopMatrix();

        glPushMatrix(); //skirt
        glColor3f(0, 0, 1);
        glBegin(GL_QUADS);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(-1, -28);
        glVertex2d(-16, -28);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left leg
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(-13, -28);
        glVertex2d(-8, -28);
        glVertex2d(-11, -32);
        glVertex2d(-17, -32);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right leg
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(-2, -28);
        glVertex2d(-7, -28);
        glVertex2d(-10, -32);
        glVertex2d(-5, -32);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right shoe
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(-5, -32);
        glVertex2d(-10, -32);
        glVertex2d(-13, -35);
        glVertex2d(-6, -35);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left shoe
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(-17, -32);
        glVertex2d(-11, -32);
        glVertex2d(-12, -35);
        glVertex2d(-20, -35);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //hair
        glRotated(-20, 0, 1, 0);
        glColor3f(0, 0, 0);
        circle(9, 10);
        glPopMatrix();

        glPushMatrix(); //head, neck, nose ,eye, lips
        glRotated(-20, 0, 1, 0);
        glColor3f(0.87, 0.72, 0.53);
        circle(7, 6);      //head
        glBegin(GL_QUADS); //neck
        glVertex2d(-6, -6);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //right eye

        glVertex2d(4, 3);
        glVertex2d(1, 3);

        glEnd();
        glBegin(GL_LINES); //lips

        glVertex2d(2, -3);
        glVertex2d(-2, -3);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //left eye

        glVertex2d(-4, 3);
        glVertex2d(-1, 3);

        glEnd();
        circle(0.5, 2); //nose
        glPopMatrix();

        glPopMatrix();
    }
    glPopMatrix();
}

void swing_()
{
    glPushMatrix();
    glTranslated(-18, -1.5, 0);
    glScaled(0.7, 0.4, 0);

    glColor3f(1, 0, 0);

    glPushMatrix(); // swing left bar
    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 10.0);
    glVertex2d(0.4, 10.0);
    glVertex2d(0.4, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // swing right bar
    glTranslated(10, 0, 1);
    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 10.0);
    glVertex2d(0.4, 10.0);
    glVertex2d(0.4, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // swing up bar
    glTranslated(0, 9, 1);
    glRotatef(-90, 0, 0, 1);

    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 10.4);
    glVertex2d(0.4, 10.4);
    glVertex2d(0.4, 0.0);
    glEnd();
    glPopMatrix();


    glPushMatrix(); // swing left line
    glTranslated(2.9, 3, 1);
    glBegin(GL_QUADS);
    glVertex2d(0.0, swing);
    glVertex2d(0.0, 6.0);
    glVertex2d(0.1, 6.0);
    glVertex2d(0.1, swing);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // swing right side
    glTranslated(7.7, 3, 1);
    glBegin(GL_QUADS);
    glVertex2d(0, swing);
    glVertex2d(0, 6.0);
    glVertex2d(0.1, 6.0);
    glVertex2d(0.1, swing);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // swing sitting table

    glTranslated(1.8, 3, 1);
    glBegin(GL_QUADS);
    glVertex2d(1.0, swing + 1);
    glVertex2d(6.0, swing + 1);
    glVertex2d(7.0, swing);
    glVertex2d(0.0, swing);

    glEnd();
    glPopMatrix();

    glPushMatrix(); // swing under extra line
    glTranslated(1.8, 2.7, 1);
    glBegin(GL_QUADS);
    glVertex2d(0.0, swing);
    glVertex2d(7, swing);
    glVertex2d(7, swing + 0.1);
    glVertex2d(0, swing + 0.1);
    glEnd();
    glPopMatrix();

    glPopMatrix();
    babySwing();
}

void wheerligig()
{
    glPushMatrix();
  
    glPushMatrix(); //stand
    glTranslated(13, -5, 1);
    glScaled(0.4, 0.25, 0);
    glColor3f(0.184, 0.31, 0.31);
    glBegin(GL_QUADS);
    glVertex2d(0, -10);
    glVertex2d(1, -10);
    glVertex2d(1, 30);
    glVertex2d(0, 30);
    glEnd();

    glPopMatrix();
    glPushMatrix();

    glTranslated(13.25, 2.5, 1);
    glScaled(0.35, 0.2, 0);
    glRotated(angle, 0, 0, 1);
    glPushMatrix();
    glTranslatef(10, 13, 0);
    glRotated(-angle, 0, 0, 1);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, -3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -7.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -6.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -6.5);
    glEnd();

    glPopMatrix();

    glPopMatrix();
    glPushMatrix();
    glTranslatef(10, -13, 0);
    glRotated(-angle, 0, 0, 1);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, -3);
    glEnd();
    glPushMatrix();

    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -7.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -6.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, -13, 0);
    glRotated(-angle, 0, 0, 1);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, -3);
    glEnd();

    if (isbaby == 5)
    {
        baby();
    }

    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -7.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -6.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 13, 0);
    glRotated(-angle, 0, 0, 1);
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);
    glVertex2d(0, 0);
    glVertex2d(0, -3);
    glEnd();
    glPushMatrix();
    glBegin(GL_QUADS);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -2.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(1.5, -7.5);
    glColor3f(0.545, 0, 0);
    glVertex2d(-1.5, -7.5);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -3.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -4.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -5.5);
    glColor3f(0, 0, 0);
    glVertex2d(-1.5, -6.5);
    glColor3f(0, 0, 0);
    glVertex2d(1.5, -6.5);
    glEnd();

    glPopMatrix();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glBegin(GL_LINES);

    glVertex2d(0, 0);
    glVertex2d(10, 13);
    glVertex2d(0, 0);
    glVertex2d(10, -13);
    glVertex2d(0, 0); //4 cross lines
    glVertex2d(-10, -13);
    glVertex2d(0, 0);
    glVertex2d(-10, 13);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(0, 0, 0);
    glColor3f(0.545, 0, 0);
    circle(1, 1);
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void bench()
{
    glPushMatrix();
    glTranslated(-8, -3, 1);
    glColor3f(0, 0, 1);

    glScaled(0.8, 0.6, 1);
    glPushMatrix(); //Brench
    glTranslated(1.8, 3, 1);
    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(1.0, 1.0);
    glVertex2d(6.0, 1.0);
    glVertex2d(7.0, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90, 0, 0, 1);
    glTranslated(-2.8, 1.8, 1);
    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 7.0);
    glVertex2d(0.1, 7.0);
    glVertex2d(0.1, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(3, 1.7, 1);
    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 1.0);
    glVertex2d(0.4, 1.0);
    glVertex2d(0.4, 0.0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(7, 1.7, 1);
    glBegin(GL_QUADS);
    glVertex2d(0.0, 0.0);
    glVertex2d(0.0, 1.0);
    glVertex2d(0.4, 1.0);
    glVertex2d(0.4, 0.0);
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    if (isbaby == 3)
    {
        glTranslated(-4, 0.5, 0);
        glScaled(0.05, 0.06, 0);
        glPushMatrix(); // top
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2d(-6, -6);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-6, -11);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(6, -11);
        glVertex2d(9, -13);
        glVertex2d(11, -9);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left hand
        glColor3f(0.87, 0.72, 0.53);
        glRotated(-15, 0, 1, 0);
        glBegin(GL_QUADS);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-13, -20);
        glVertex2d(-16, -18);
        glEnd();

        glPopMatrix();

        glPushMatrix(); //left hand palm
        glTranslated(-15, -18.5, 0);
        //glRotated(-15,0,0,1);
        glColor3f(0.87, 0.72, 0.53);
        circle(3.3, 2.7);
        glPopMatrix();

        glPushMatrix(); //right hand
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(11, -9);
        glVertex2d(9, -13);
        glVertex2d(13, -20);
        glVertex2d(16, -18);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right hand palm
        glTranslated(15, -20, 0);
        glColor3f(0.87, 0.72, 0.53);
        circle(3, 2.5);
        glPopMatrix();

        glPushMatrix(); //skirt
        glColor3f(0, 0, 1);
        glBegin(GL_QUADS);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(4, -32);
        glVertex2d(-16, -30);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left leg
        glTranslated(-6, 1.5, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(-6, -32);
        glVertex2d(-2, -32);
        glVertex2d(-2, -38);
        glVertex2d(-6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right leg
        glTranslated(-5, 0.8, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(6, -32);
        glVertex2d(2, -32);
        glVertex2d(2, -38);
        glVertex2d(6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right shoe
        glTranslated(-5, 0.8, 0);
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(6, -42);
        glVertex2d(-2, -42);
        glVertex2d(2, -38);
        glVertex2d(6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left shoe
        glTranslated(-6, 1.5, 0);
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(-10, -42);
        glVertex2d(-2, -42);
        glVertex2d(-2, -38);
        glVertex2d(-6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //hair
        glColor3f(0, 0, 0);
        circle(9, 10);
        glPopMatrix();

        glPushMatrix(); //head, neck, nose ,eye, lips
        glColor3f(0.87, 0.72, 0.53);
        circle(7, 6);      //head
        glBegin(GL_QUADS); //neck
        glVertex2d(-6, -6);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //right eye

        glVertex2d(4, 3);
        glVertex2d(1, 3);

        glEnd();
        glBegin(GL_LINES); //lips

        glVertex2d(2, -3);
        glVertex2d(-2, -3);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //left eye

        glVertex2d(-4, 3);
        glVertex2d(-1, 3);

        glEnd();
        circle(0.5, 2); //nose
        glPopMatrix();
    }
    glPopMatrix();
}

void baby()
{
    glPushMatrix();
    if (isbaby == 0)
    {
        glTranslated(0 + bx, -1 + by, 0);
        glScalef(0.04, 0.06, 0);
    }

    else if (isbaby == 5)
    {
        glTranslated(-0.5, 2, 0);
        glScaled(0.07, 0.2, 0);
    }
    else if (isbaby == 6)
    {
        glTranslated(0 + bx, 0 + by, 0);
        glScalef(0.04, 0.06, 0);
    }

    
    glPushMatrix(); 
    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(-6, -6);
    glVertex2d(-11, -9);
    glVertex2d(-9, -13);
    glVertex2d(-6, -11);
    glVertex2d(-6, -22);
    glVertex2d(6, -22);
    glVertex2d(6, -11);
    glVertex2d(9, -13);
    glVertex2d(11, -9);
    glVertex2d(6, -6);
    glVertex2d(4, -10);
    glVertex2d(-4, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left hand
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(-11, -9);
    glVertex2d(-9, -13);
    glVertex2d(-13, -20);
    glVertex2d(-16, -18);
    glEnd();

    glPopMatrix();

    glPushMatrix(); //left hand palm
    glTranslated(-15, -20, 0);
    glColor3f(0.87, 0.72, 0.53);
    circle(3, 2.5);
    glPopMatrix();

    glPushMatrix(); //right hand
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(11, -9);
    glVertex2d(9, -13);
    glVertex2d(13, -20);
    glVertex2d(16, -18);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right hand palm
    glTranslated(15, -20, 0);
    glColor3f(0.87, 0.72, 0.53);
    circle(3, 2.5);
    glPopMatrix();

    glPushMatrix(); //skirt
    glColor3f(0, 0, 1);
    glBegin(GL_QUADS);
    glVertex2d(-6, -22);
    glVertex2d(6, -22);
    glVertex2d(13, -32);
    glVertex2d(-13, -32);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left leg
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(-6, -32);
    glVertex2d(-2, -32);
    glVertex2d(-2, -38);
    glVertex2d(-6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right leg
    glColor3f(0.87, 0.72, 0.53);
    glBegin(GL_QUADS);
    glVertex2d(6, -32);
    glVertex2d(2, -32);
    glVertex2d(2, -38);
    glVertex2d(6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right shoe
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(10, -42);
    glVertex2d(2, -42);
    glVertex2d(2, -38);
    glVertex2d(6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left shoe
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(-10, -42);
    glVertex2d(-2, -42);
    glVertex2d(-2, -38);
    glVertex2d(-6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //hair
    glColor3f(0, 0, 0);
    circle(9, 10);
    glPopMatrix();

    glPushMatrix(); //head, neck, nose ,eye, lips
    glColor3f(0.87, 0.72, 0.53);
    circle(7, 6);      //head
    glBegin(GL_QUADS); //neck
    glVertex2d(-6, -6);
    glVertex2d(6, -6);
    glVertex2d(4, -10);
    glVertex2d(-4, -10);
    glEnd();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES); //right eye

    glVertex2d(4, 3);
    glVertex2d(1, 3);

    glEnd();
    glBegin(GL_LINES); //lips

    glVertex2d(2, -3);
    glVertex2d(-2, -3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES); //left eye

    glVertex2d(-4, 3);
    glVertex2d(-1, 3);

    glEnd();
    circle(0.5, 2); //nose
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}

void babySlide()
{
    glPushMatrix();

    if (isbaby == 7 && step == 4)
    {
        glTranslatef(3.5 + stepx, -1.7 + stepy, 0);
        glScaled(0.04, 0.06, 0);

        glPushMatrix(); // top
        glRotated(-20, 0, 1, 0);
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2d(-6, -6);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-6, -11);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(6, -11);
        glVertex2d(9, -13);
        glVertex2d(11, -9);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left hand
        glRotated(-20, 0, 1, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-13, -20);
        glVertex2d(-16, -18);
        glEnd();

        glPopMatrix();

        glPushMatrix(); //left hand palm
        glRotated(-20, 0, 1, 0);
        glTranslated(-15, -20, 0);
        glColor3f(0.87, 0.72, 0.53);
        circle(3, 2.5);
        glPopMatrix();

        glPushMatrix(); //right hand
        glRotated(-20, 0, 1, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(11, -9);
        glVertex2d(9, -13);
        glVertex2d(13, -20);
        glVertex2d(16, -18);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right hand palm
        glRotated(-20, 0, 1, 0);
        glTranslated(15, -20, 0);

        glColor3f(0.87, 0.72, 0.53);
        circle(3, 2.5);
        glPopMatrix();

        glPushMatrix(); //skirt
        glColor3f(0, 0, 1);
        glBegin(GL_QUADS);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(17, -28);
        glVertex2d(-2, -28);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left leg
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(5, -28);
        glVertex2d(0, -28);
        glVertex2d(3, -32);
        glVertex2d(8, -32);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right leg
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(14, -28);
        glVertex2d(9, -28);
        glVertex2d(12, -32);
        glVertex2d(17, -32);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right shoe
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(17, -32);
        glVertex2d(12, -32);
        glVertex2d(15, -35);
        glVertex2d(21, -35);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left shoe
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(8, -32);
        glVertex2d(3, -32);
        glVertex2d(5, -35);
        glVertex2d(12, -35);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //hair
        glRotated(-20, 0, 1, 0);
        glColor3f(0, 0, 0);
        circle(9, 10);
        glPopMatrix();

        glPushMatrix(); //head, neck, nose ,eye, lips
        glRotated(-20, 0, 1, 0);
        glColor3f(0.87, 0.72, 0.53);
        circle(7, 6);      //head
        glBegin(GL_QUADS); //neck
        glVertex2d(-6, -6);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //right eye

        glVertex2d(4, 3);
        glVertex2d(1, 3);

        glEnd();
        glBegin(GL_LINES); //lips

        glVertex2d(2, -3);
        glVertex2d(-2, -3);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //left eye

        glVertex2d(-4, 3);
        glVertex2d(-1, 3);

        glEnd();
        circle(0.5, 2); //nose
        glPopMatrix();

        glPopMatrix();
    }
    glPopMatrix();
}

void slide()
{

    glPushMatrix();
    glTranslatef(2, -3, 0);
    glPushMatrix();
    glTranslatef(-3, -3, 0);
    glColor3f(0.54, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(3, 0);
    glVertex2d(2.8, -0.1);
    glVertex2d(-0.1, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, -2, 0);
    glColor3f(0.54, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(3, 0);
    glVertex2d(2.8, -0.1);
    glVertex2d(-0.1, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1, -1, 0);
    glColor3f(0.54, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(3, 0);
    glVertex2d(2.8, -0.1);
    glVertex2d(-0.1, -0.1);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54, 0.396, 0.031);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(0.3, 0);
    glVertex2d(-3.7, -4);
    glVertex2d(-4, -4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54, 0.396, 0.031);
    glBegin(GL_QUADS);
    glVertex2d(3, 0);
    glVertex2d(2.7, 0);
    glVertex2d(-1.3, -4);
    glVertex2d(-1, -4);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.54, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(0, 0);
    glVertex2d(3, 0);
    glVertex2d(6, -5);
    glVertex2d(3, -5);
    glEnd();
    glPopMatrix();
    glPopMatrix();
    babySlide();
}

void glidder()
{
    glPushMatrix();
    glTranslated(-18.5, -6, 0);
    glColor3f(0, 0, 0.54);
    glScalef(0.8, 0.5, 0);
    
    if (glUp == 0)
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(13, 3.0);
        glVertex2f(13, 3.3);
        glVertex2f(0, 0.3);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(3.0, 0.9);
        glVertex2d(3.0, 1.5);
        glVertex2d(3.3, 1.5);
        glVertex2d(3.3, 0.9);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(10.0, 2.4);
        glVertex2d(10.0, 3.0);
        glVertex2d(9.7, 3.0);
        glVertex2d(9.7, 2.4);
        glEnd();
        glPopMatrix();
        glPushMatrix(); //glidder bottom
        glTranslated(6.2, 1.0, 1);
     
        glBegin(GL_QUADS);
        glVertex2d(0.0, 0.5);
        glVertex2d(0.0, -2.0);
        glVertex2d(0.5, -2.0);
        glVertex2d(0.5, 0.6);
        glEnd();
        glPopMatrix();
    }

    else if (glUp == 1)
    {
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2f(0, 3.0);
        glVertex2f(0, 3.3);
        glVertex2f(13, 0.3);
        glVertex2f(13, 0);
        glEnd();
        glPopMatrix();
        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(3.0, 2.4);
        glVertex2d(3.0, 3.0);
        glVertex2d(3.3, 3.0);
        glVertex2d(3.3, 2.4);
        glEnd();
        glPopMatrix();

        glPushMatrix();
        glBegin(GL_QUADS);
        glVertex2d(10.0, 0.9);
        glVertex2d(10.0, 1.5);
        glVertex2d(9.7, 1.5);
        glVertex2d(9.7, 0.9);
        glEnd();
        glPopMatrix();
        glPushMatrix(); //glidder bottom
        glTranslated(6.2, 1.0, 1);
    
        glBegin(GL_QUADS);
        glVertex2d(0.0, 0.6);
        glVertex2d(0.0, -2.0);
        glVertex2d(0.5, -2.0);
        glVertex2d(0.5, 0.5);
        glEnd();
        glPopMatrix();
    }

    glPopMatrix();

    glPushMatrix();
    if (isbaby == 2)
    {
        if (glUp == 0)
        {
            glRotatef(20, 1, 1, 1);
            glTranslated(-17.8, -0.6, 0);
        }
        else if (glUp == 1)
        {
            glRotatef(-20, 1, 1, 1);
            glTranslated(-15.8, -6.6, 0);
        }

        glScaled(0.05, 0.05, 0);
        glPushMatrix(); //  top
        glColor3f(1, 0, 0);
        glBegin(GL_POLYGON);
        glVertex2d(-6, -6);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-6, -11);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(6, -11);
        glVertex2d(9, -13);
        glVertex2d(11, -9);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left hand
        glColor3f(0.87, 0.72, 0.53);
        glRotated(-15, 0, 1, 0);
        glBegin(GL_QUADS);
        glVertex2d(-11, -9);
        glVertex2d(-9, -13);
        glVertex2d(-18, -11);
        glVertex2d(-16, -7);
        glEnd();

        glPopMatrix();

        glPushMatrix(); //left hand palm
        glTranslated(-18.5, -9, 0);
        //glRotated(-15,0,0,1);
        glColor3f(0.87, 0.72, 0.53);
        circle(3.3, 2.7);
        glPopMatrix();

        glPushMatrix(); //right hand
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(11, -9);
        glVertex2d(9, -13);
        glVertex2d(13, -20);
        glVertex2d(16, -18);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right hand palm
        glTranslated(15, -20, 0);
        glColor3f(0.87, 0.72, 0.53);
        circle(3, 2.5);
        glPopMatrix();

        glPushMatrix(); //skirt
        glColor3f(0, 0, 1);
        glBegin(GL_QUADS);
        glVertex2d(-6, -22);
        glVertex2d(6, -22);
        glVertex2d(4, -32);
        glVertex2d(-16, -30);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left leg
        glTranslated(-6, 1.5, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(-6, -32);
        glVertex2d(-2, -32);
        glVertex2d(-2, -38);
        glVertex2d(-6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right leg
        glTranslated(-5, 0.8, 0);
        glColor3f(0.87, 0.72, 0.53);
        glBegin(GL_QUADS);
        glVertex2d(6, -32);
        glVertex2d(2, -32);
        glVertex2d(2, -38);
        glVertex2d(6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //right shoe
        glTranslated(-5, 0.8, 0);
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(6, -42);
        glVertex2d(-2, -42);
        glVertex2d(2, -38);
        glVertex2d(6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //left shoe
        glTranslated(-6, 1.5, 0);
        glColor3f(0, 0, 0);
        glBegin(GL_QUADS);
        glVertex2d(-10, -42);
        glVertex2d(-2, -42);
        glVertex2d(-2, -38);
        glVertex2d(-6, -38);
        glEnd();
        glPopMatrix();

        glPushMatrix(); //hair
        glColor3f(0, 0, 0);
        circle(9, 10);
        glPopMatrix();

        glPushMatrix(); //head, neck, nose ,eye, lips
        glColor3f(0.87, 0.72, 0.53);
        circle(7, 6);      //head
        glBegin(GL_QUADS); //neck
        glVertex2d(-6, -6);
        glVertex2d(6, -6);
        glVertex2d(4, -10);
        glVertex2d(-4, -10);
        glEnd();
        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //right eye

        glVertex2d(4, 3);
        glVertex2d(1, 3);

        glEnd();
        glBegin(GL_LINES); //lips

        glVertex2d(2, -3);
        glVertex2d(-2, -3);

        glEnd();
        glPopMatrix();

        glPushMatrix();
        glColor3f(0, 0, 0);
        glBegin(GL_LINES); //left eye

        glVertex2d(-4, 3);
        glVertex2d(-1, 3);

        glEnd();
        circle(0.5, 2); //nose
        glPopMatrix();

        glPopMatrix();
    }

    glPopMatrix();

    glPushMatrix();

    if (glUp == 0)
    {
        glRotatef(20, 1, 1, 1);
        glTranslated(-10.6, -1.2, 0);
    }
    else if (glUp == 1)
    {
        glRotatef(-20, 1, 1, 1);
        glTranslated(-8.5, -6.2, 0);
    }

    glScalef(0.05, 0.05, 0);
    
    glPushMatrix(); //  top
    glColor3f(1, 0.27, 0);
    glBegin(GL_POLYGON);
    glVertex2d(-6, -6);
    glVertex2d(-11, -9);
    glVertex2d(-9, -13);
    glVertex2d(-6, -11);
    glVertex2d(-6, -22);
    glVertex2d(6, -22);
    glVertex2d(6, -11);
    glVertex2d(9, -13);
    glVertex2d(11, -9);
    glVertex2d(6, -6);
    glVertex2d(4, -10);
    glVertex2d(-4, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left hand
    glColor3f(1, 0.94, 0.83);
    glBegin(GL_QUADS);
    glVertex2d(-11, -9);
    glVertex2d(-9, -13);
    glVertex2d(-13, -20);
    glVertex2d(-16, -18);
    glEnd();

    glPopMatrix();

    glPushMatrix(); //left hand palm
    glTranslated(-15, -20, 0);
    glColor3f(1, 0.94, 0.83);
    circle(3, 2.5);
    glPopMatrix();

    glPushMatrix(); //right hand
    glColor3f(1, 0.94, 0.83);
    glBegin(GL_QUADS);
    glVertex2d(11, -9);
    glVertex2d(9, -13);
    glVertex2d(13, -20);
    glVertex2d(16, -18);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right hand palm
    glTranslated(15, -20, 0);
    glColor3f(1, 0.94, 0.83);
    circle(3, 2.5);
    glPopMatrix();

    glPushMatrix(); //skirt
    glColor3f(0.6, 0.196, 0.8);
    glBegin(GL_QUADS);
    glVertex2d(-6, -22);
    glVertex2d(6, -22);
    glVertex2d(4, -32);
    glVertex2d(-16, -30);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left leg
    glTranslated(-6, 1.5, 0);
    glColor3f(1, 0.94, 0.83);
    glBegin(GL_QUADS);
    glVertex2d(-6, -32);
    glVertex2d(-2, -32);
    glVertex2d(-2, -38);
    glVertex2d(-6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right leg
    glTranslated(-5, 0.8, 0);
    glColor3f(1, 0.94, 0.83);
    glBegin(GL_QUADS);
    glVertex2d(6, -32);
    glVertex2d(2, -32);
    glVertex2d(2, -38);
    glVertex2d(6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //right shoe
    glTranslated(-5, 0.8, 0);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(6, -42);
    glVertex2d(-2, -42);
    glVertex2d(2, -38);
    glVertex2d(6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //left shoe
    glTranslated(-6, 1.5, 0);
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
    glVertex2d(-10, -42);
    glVertex2d(-2, -42);
    glVertex2d(-2, -38);
    glVertex2d(-6, -38);
    glEnd();
    glPopMatrix();

    glPushMatrix(); //hair
    glColor3f(0, 0, 0);
    circle(9, 10);
    glPopMatrix();

    glPushMatrix(); //head, neck, nose ,eye, lips
    glColor3f(1, 0.94, 0.83);
    circle(7, 6);      //head
    glBegin(GL_QUADS); //neck
    glVertex2d(-6, -6);
    glVertex2d(6, -6);
    glVertex2d(4, -10);
    glVertex2d(-4, -10);
    glEnd();
    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES); //right eye

    glVertex2d(4, 3);
    glVertex2d(1, 3);

    glEnd();
    glBegin(GL_LINES); //lips

    glVertex2d(2, -3);
    glVertex2d(-2, -3);

    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 0, 0);
    glBegin(GL_LINES); //left eye

    glVertex2d(-4, 3);
    glVertex2d(-1, 3);

    glEnd();
    circle(0.5, 2); //nose
    glPopMatrix();

    glPopMatrix();
    glPopMatrix();
}
void display(void)
{

    glClear(GL_COLOR_BUFFER_BIT);

    sky();
    hillSide();
    field();
    sun();
    path();
    
    cloudLeft();
    cloudRightUp();
    cloudRight();
    cloudMiddle();
    hillTree();

    glidder();
    if (isbaby != 8)
    {

        wheerligig();
        swing_();
    }
    bench();
    if (isbaby == 0 || isbaby == 6 || isbaby == 8)
    {
        baby();
    }
    slide();

    if (isbaby == 8)
    {
        wheerligig();
        swing_();
    }
    person();

    glutPostRedisplay();
    glFlush();
}

void init(void)
{
    glClearColor(0, 0, 0, 0);
    glMatrixMode(GL_PROJECTION);
    glOrtho(0, 50, 0, 50, 0, 10);
}

void spe_key(int key, int x, int y)
{
    switch (key)
    {

    case GLUT_KEY_LEFT:

        bx = bx - 0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_RIGHT:

        bx = bx + 0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_DOWN:

        by = by - 0.5;
        glutPostRedisplay();
        break;

    case GLUT_KEY_UP:

        by = by + 0.5;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void windMove()
{
    if (angle < -726.5)
    {
        isbaby = 0;
        angle = 0;
        bx = 7;
        by = 0;
        glutIdleFunc(NULL);
    }
    else
    {
        angle = angle - 0.2;
    }
    glutPostRedisplay();
}

void swinging()
{
    if (swing >= 0.1)
    {
        swing += 0.001;
    }
    else if (swing <= -0.1)
    {
        swing -= 0.001;
    }

    glutPostRedisplay();
}

void slideMove()
{
    stepx += 0.007;
    stepy -= 0.01;
    glutPostRedisplay();
    if (stepy < -4.5)
    {
        isbaby = 0;
        step = 0;
        stepx = 0;
        stepy = 0;
        bx = -1;
        by = -4;
        glutIdleFunc(NULL);
        glutPostRedisplay();
    }
}

void Display_on_screen(char *string)

{
    while (*string)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    }
}

void instructionPage()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2i(15, 40);
    glRasterPos3f(22, 40, 0);
    Display_on_screen("Instructions");

    glRasterPos3f(15, 26, 0);

    Display_on_screen("Move the girl using the arrow keys.");

    glRasterPos3f(23, 26, 0);
    glRasterPos3f(26, 26, 0);
    glRasterPos3f(15, 24, 0);

    Display_on_screen("Press 'u' to get on to the swing and 'd' to get off the swing.");

    glRasterPos3f(23, 24, 0);
    glRasterPos3f(26, 24, 0);
    glRasterPos3f(15, 22, 0);

    Display_on_screen("Press 'g' to get on the glider and 'j' to get off. Press 'h' and 'l' to use the glider");

    glRasterPos3f(23, 22, 0);
    glRasterPos3f(26, 22, 0);
    glRasterPos3f(15, 20, 0);

    Display_on_screen("Press 'o' to climb and slide step by step.");

    glRasterPos3f(23, 20, 0);
    glRasterPos3f(26, 20, 0);

    glRasterPos3f(15, 18, 0);

    Display_on_screen("Press 'w' to get into the giant wheel.");
    glRasterPos3f(15, 16, 0);

    Display_on_screen("Press 'r' to sit on the bench and press 's' to stand up.");
    glRasterPos3f(16, 10, 0);

    Display_on_screen("Press 'ENTER' to continue or CLICK here");
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(17, 39);
    glVertex2i(31, 39);
    glEnd();
    glFlush();
}

void normal_key(unsigned char key, int x, int y)
{
    if (key == 'i')
    {
        glLoadIdentity();
        glOrtho(0, 50, 0, 50, 0, 10);
        glutDisplayFunc(instructionPage);
        glutPostRedisplay();
    }
    if (key == (char)13)
    {
        glLoadIdentity();
        glOrtho(-20.0, 20.0, -10.0, 10.0, -15.0, 15.0);
        glutDisplayFunc(display);
        glutPostRedisplay();
    }
    switch (key)
    {
    case 'f': 
        swing = -1;
        glutPostRedisplay();
        break;

    case 'u':
        isbaby = 1;
        swing = 0.1;
        glutIdleFunc(swinging);
        glutPostRedisplay();
        break;
    case 'd':
        isbaby = 0;
        bx = -15;
        by = -0.5;
        glutIdleFunc(NULL);
        glutPostRedisplay();
        break;

    case 'g':
        isbaby = 2;
        glutPostRedisplay();
        break;

    case 'j':
        isbaby = 0;
        bx = -17;
        by = -6;
        glUp = 1;
        glutPostRedisplay();
        break;

    case 'h':
        glUp = 1;
        glutPostRedisplay();
        break;

    case 'l':
        glUp = 0;
        glutPostRedisplay();
        break;

    case 'r':
        isbaby = 3;
        glutPostRedisplay();
        break;

    case 's':
        isbaby = 0;
        bx = -4;
        by = -1;
        glutPostRedisplay();
        break;

    case 'w':
 
        isbaby = 5;
        glutIdleFunc(windMove);
        break;

    case 'o':
        isbaby = 6;
        step++;
        if (step == 1)
        {
            bx = 0.5;
            by = -3.5;
        }
        else if (step == 2)
        {
            bx = 1.5;
            by = -2.5;
        }
        else if (step == 3)
        {
            bx = 2.5;
            by = -1.5;
        }

        else if (step == 4)
        {
            isbaby = 7;
            glutIdleFunc(slideMove);
        }
        glutPostRedisplay();
        break;

    case 'b':
        isbaby = 8;
        glutPostRedisplay();
        break;


    default:
        break;
    }
}

void introPage()
{

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 1.0, 0.0);
    glRasterPos2i(15, 40);
    glRasterPos3f(20, 40, 0);
    Display_on_screen("Park Simulation");
    glRasterPos3f(15, 26, 0);

    Display_on_screen("Manasa V");
    glRasterPos3f(23, 26, 0);
    Display_on_screen("<-->");
    glRasterPos3f(26, 26, 0);
    Display_on_screen("4NM17CS099");
    glRasterPos3f(15, 24, 0);

    Display_on_screen("Manjunath Patkar");
    glRasterPos3f(23, 24, 0);
    Display_on_screen("<-->");
    glRasterPos3f(26, 24, 0);
    Display_on_screen("4NM17CS100");
    glRasterPos3f(15, 22, 0);

    Display_on_screen("Manukashyap U V");
    glRasterPos3f(23, 22, 0);
    Display_on_screen("<-->");
    glRasterPos3f(26, 22, 0);
    Display_on_screen("4NM17CS101");
    glRasterPos3f(15, 20, 0);

    Display_on_screen("Marlon Fernandes");
    glRasterPos3f(23, 20, 0);
    Display_on_screen("<-->");
    glRasterPos3f(26, 20, 0);
    Display_on_screen("4NM17CS102");
    glRasterPos3f(16, 10, 0);

    Display_on_screen("Press 'i' to get to the instruction page");
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(5);
    glBegin(GL_LINES);
    glVertex2i(15, 39);
    glVertex2i(31, 39);

    glEnd();
    glFlush();
}

void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glLoadIdentity();
        glOrtho(-20.0, 20.0, -10.0, 10.0, -15.0, 15.0);
        glutDisplayFunc(display);
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1400, 900);
    glutCreateWindow("Park Simulation");

    init();
    glutDisplayFunc(introPage);
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(normal_key);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0; 
}
