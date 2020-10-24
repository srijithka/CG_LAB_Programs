
 
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

#include<stdio.h>
#include<GL/glut.h> 

int xc, yc, r;
void drawCircle(int xc, int yc, int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(xc + x, yc + y);
	glVertex2i(xc - x, yc + y);
	glVertex2i(xc + x, yc - y);
	glVertex2i(xc - x, yc - y);
	glVertex2i(xc + y, yc + x);
	glVertex2i(xc - y, yc + x);
	glVertex2i(xc + y, yc - x);
	glVertex2i(xc - y, yc - x);
	glEnd();
}
void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	while (x < y)
	{
		drawCircle(xc, yc, x, y);
		x++;
		if (d < 0)
			d = d + 4 * x + 6;
		else
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		drawCircle(xc, yc, x, y);
	}
}
void display()
{
	int j;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	circleBres(xc, yc, r);
	glFlush();
}
void myinit()
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0, 0, 1.0);
	glPointSize(5.0);
	gluOrtho2D(0.0, 500, 0.0, 500);
}
void main(int argc, char* argv[])
{
	int j;
	printf("Enter coord of centre of circle & radius: ");
	scanf_s("%d%d%d", &xc, &yc, &r);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenhams Circle");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}




