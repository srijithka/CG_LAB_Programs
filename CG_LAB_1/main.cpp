
 
// THIS IS THE FIRST SAMPLE
/*#include<GL/glut.h>

void display() 
	{
		glClearColor(0.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
		glFlush(); 
	}
	void main(int argc, char** argv)
	{
		glutInit(&argc, argv); 
		glutInitWindowSize(500,500); 
		glutInitWindowPosition(100,100);
		glutCreateWindow("Example1"); 
		glutDisplayFunc(display); 
		glutMainLoop();
	}
	*/




//DRAAWING A SQUARE USING LINE_LOOP
/*
#include<GL/glut.h> 
  void display() 
  {  
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(50, 50);
	glVertex2f(200, 50);
	glVertex2f(200, 200);
	glVertex2f(50, 200);
	glEnd();
	glFlush();
	} 
	void myinit() 
	{ 
		glClearColor(1.0,1.0,0.0,1.0);
		gluOrtho2D(0.0,499.0,0.0,499.0); 
	} 
	void main(int argc, char** argv)
	{  
		glutInit(&argc,argv);
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(300,300);
		glutInitWindowPosition(0,0);
		glutCreateWindow("LINE LOOP");
		glutDisplayFunc(display);
		myinit();
		glutMainLoop(); 
	}

	*/

	//DRAWING LINES
/*
	#include<GL/glut.h> 
	void display()
	{ 
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);  
		glLineWidth(3.0);   // Thickness of line
		glBegin(GL_LINES); 
		glVertex2d (50,50); // to draw horizontal line in red color 
		glVertex2d (150,50);  
		glColor3f(0.0,0.0,1.0); //draw the line with blue color 
		glVertex2d (200,200); // to draw vertical line in blue color 
		glVertex2d (200,300);
		glEnd(); 
		glFlush(); 
	}
	void myinit()
	{
		glClearColor(1.0, 1.0, 1.0, 1.0);
		glColor3f(1.0, 0.0, 0.0); 
		glPointSize(1.0); 
		gluOrtho2D(0.0, 500.0, 0.0, 500.0);
	} 
	void main(int argc, char** argv) {
		glutInit(&argc, argv); 
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
		glutInitWindowSize(500, 500); 
		glutInitWindowPosition(100, 100); 
		glutCreateWindow("LINE");  
		glutDisplayFunc(display); 
		myinit(); 
		glutMainLoop(); 
	}

*/
	//Change the window color to BLUE, Change the point color to CYAN ,Change the point width to 10
/*
	#include<GL/glut.h> 
	void display()
	{
		glClear(GL_COLOR_BUFFER_BIT); 
		glBegin(GL_POINTS);
			glVertex2i(10, 10);
			glVertex2i(250, 250); 
			glVertex2i(10, 490); 
			glVertex2i(490, 490);
			glVertex2i(490, 10); 
		glEnd(); 
		glFlush();
	}
	void myinit() {
		glClearColor(0.0, 0.0, 1.0, 0.0);// set the window color to blue
		glColor3f(0.0,1.0,1.0);// set the point color to cyan (RGB) 
		glPointSize(10.0); 
		gluOrtho2D(0.0,500.0,0.0,500.0);
	}
	void main(int argc, char** argv)
	{ 
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
		glutInitWindowSize(500, 500);
		glutInitWindowPosition(0, 0);
		glutCreateWindow("Activity2"); 
		glutDisplayFunc(display);
		myinit(); 
		glutMainLoop(); 
	}
	*/

//BRESENHAM"S LINE

#define BLACK 0
#include <stdio.h>
#include <GL/glut.h>
//GLint Point[4] = {0};
int x1, x2, y1, y2;
void draw_pixel(int x, int y, int value)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
void bres(int x1, int x2, int y1, int y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;
	dx = x2 - x1;
	dy = y2 - y1;
	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1)incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1;y = y1;
	if (dx > dy)
	{
		draw_pixel(x, y, BLACK);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0;i < dx;i++)
		{
			if (e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else e += inc2;
			x += incx;
			draw_pixel(x, y, BLACK);
		}
	}
	else
	{
		draw_pixel(x, y, BLACK);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0;i < dy;i++)
		{
			if (e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else e += inc2;
			y += incy;
			draw_pixel(x, y, BLACK);
		}
	}
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	bres(x1, y1, x2, y2);
	glFlush();
}
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
void main(int argc, char** argv)
{
	printf("Enter points: x1, y1, x2, y2");
	scanf_s("%d %d %d %d", &x1, &x2, &y1, &y2);
	/* Point[0] = x1;
	Point[1] = y1;
	Point[2] = x2;
	Point[3] = y2;*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham,s Algorithm");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}



