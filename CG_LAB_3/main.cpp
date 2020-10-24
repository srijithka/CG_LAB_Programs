
 
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

void draw_pixel(GLint cx, GLint cy)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POINTS);
	glVertex2i(cx, cy);
	glEnd();
}
void plotpixels(GLint h, GLint k, GLint x, GLint y)
{
	draw_pixel(x + h, y + k);
	draw_pixel(-x + h, y + k);
	draw_pixel(x + h, -y + k);
	draw_pixel(-x + h, -y + k);
	draw_pixel(y + h, x + k);
	draw_pixel(-y + h, x + k);
	draw_pixel(y + h, -x + k);
	draw_pixel(-y + h, -x + k);
}
void Circle_draw(GLint h, GLint k, GLint r) // Midpoint Circle Drawing Algorithm
{
	GLint d = 1 - r, x = 0, y = r;
	while (y > x)
	{
		plotpixels(h, k, x, y);
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			--y;
		}
		++x;
	}
	plotpixels(h, k, x, y);
}
void Cylinder_draw()
{
	GLint xc = 100, yc = 100, r = 50, i, n = 50;
	for (i = 0;i < n;i += 3)
		Circle_draw(xc, yc + i, r);
}
void parallelepiped(int x1, int x2, int y1, int y2)
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1, y1);
	glVertex2i(x2, y1);
	glVertex2i(x2, y2);
	glVertex2i(x1, y2);
	glEnd();
}
void parallelepiped_draw()
{
	int x1 = 200, x2 = 300, y1 = 100, y2 = 175, i, n = 40;
	for (i = 0;i < n;i += 2)
		parallelepiped(x1 + i, x2 + i, y1 + i, y2 + i);
}
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 300.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	Cylinder_draw();
	parallelepiped_draw();
	glFlush();
}
void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Cylinder,parallelePiped Disp by Extruding Circle &Quadrilaterl ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}





