
#include "GeUI.h"

GeUI::GeUI()
{
}


GeUI::~GeUI(void)
{
}

void GeUI::draw() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	//MyDraw();

	glFlush();
}

void resize(int width, int height)
{
	//cout << width << " " << height << endl;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, height, 0);
}

void GeUI::init(int *argc, char ** argv)
{
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(100, 200);
	glutCreateWindow("GePro");

	glutDisplayFunc(MyDraw);
	glutReshapeFunc(resize);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glutMainLoop();
}


//

void drawLine(double x0, double y0, double x1, double y1)
{
	glColor3f(1.0,0.4,0.2); 
    glPointSize(3.0);

	glBegin(GL_LINES);
    glVertex2d(x0, y0);
    glVertex2d(x1, y1);
    glEnd(); 
}