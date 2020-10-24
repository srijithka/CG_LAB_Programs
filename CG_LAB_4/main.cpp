
 
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

#include <GL/glut.h>
typedef GLfloat point[3];
point v[] = { {30.0, 50.0, 100.0}, {0.0, 450.0, -150.0},
 {-350.0, -400.0, -150.0}, {350., -400., -150.0} };
int n; /* number of recursive steps */
void triangle(point a, point b, point c)
/* display one triangle */
{
	glBegin(GL_TRIANGLES);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}
void divide_triangle(point a, point b, point c, int m)
{
	/* triangle subdivision using vertex numbers */
	point v0, v1, v2;
	int j;
	if (m > 0)
	{
		for (j = 0; j < 3; j++) v0[j] = (a[j] + b[j]) / 2;
		for (j = 0; j < 3; j++) v1[j] = (a[j] + c[j]) / 2;
		for (j = 0; j < 3; j++) v2[j] = (b[j] + c[j]) / 2;
		divide_triangle(a, v0, v1, m - 1);
		divide_triangle(c, v1, v2, m - 1);
		divide_triangle(b, v2, v0, m - 1);
	}
	else(triangle(a, b, c));
	/* draw triangle at end of recursion */
}
void tetra(int m)
{
	glColor3f(1.0, 0.0, 0.0);
	divide_triangle(v[0], v[1], v[2], m);
	glColor3f(0.0, 1.0, 0.0);
	divide_triangle(v[3], v[2], v[1], m);
	glColor3f(0.0, 0.0, 1.0);
	divide_triangle(v[0], v[3], v[1], m);
	glColor3f(0.0, 0.0, 0.0);
	divide_triangle(v[0], v[2], v[3], m);
}
void display()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	tetra(n);
	glFlush();
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-499.0, 499.0, -499.0, 499.0, -499.0, 499.0);
	glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
	n = 5;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutCreateWindow("3D Gasket");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}




