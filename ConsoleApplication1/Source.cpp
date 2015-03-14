#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

double cameraAngle;

void display(){
	//codes for Models, Camera

	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, 0);    //color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        //clear buffers to preset values

	/***************************
	/ set-up camera (view) here
	****************************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);        //specify which matrix is the current matrix

	//initialize the matrix
	glLoadIdentity();                //replace the current matrix with the identity matrix [Diagonals have 1, others have 0]

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	// gluLookAt(0,-150,20,    0,0,0,    0,0,1);
	gluLookAt(150 * sin(cameraAngle), -150 * cos(cameraAngle), 50, 0, 0, 1, 0, 0, 1);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//gluCylinder(quadric,10,10,30,20,20)
	//(pointer,base radius,top radius, height, slice,stack)
	//glutSolidSphere(base,height, slice, stack)


	//-------------------------------3D Hosue---------------------------

	//---------------Cube-----------
	/*glPushMatrix(); {
		glScalef(.2, .9, .9);
		glTranslatef(0, 0, 50);
		glutSolidCube(40);
	}glPopMatrix();
*/


	//---------------Cone-----------
	/*glColor4f(1, 0, 0, 0);
	glPushMatrix(); {
		glTranslatef(0, 0, 70);
		glutSolidCone(10, 20, 30, 20);
	}glPopMatrix();
*/

	//---------------Cylinder-----------
	//glPushMatrix(); {
	//	//glTranslatef(0, 0, 10);
	//	glScalef(3, .1, .6);//Width scale factor along X, Scale factors along the Z axis, Scale factors along the Y axis
	//	glTranslatef(0,-100,0);

	//	glColor4f(1, 0, 0, 0);
	//	GLUquadricObj *quadric;
	//	quadric = gluNewQuadric();

	//	gluCylinder(quadric, 10, 10, 60, 60, 60);
	//}glPopMatrix();





	glPushMatrix(); {

		//glScalef(1.5, .1, .6);//Width scale factor along X, Scale factors along the Z axis, Scale factors along the Y axis
		
		//glTranslatef(0, 100, 0);

		glColor3f(1, 0, 0);
		glBegin(GL_QUADS); {
			glVertex3f(0, 0, 15);
			glVertex3f(40, 0, 15);
			glVertex3f(40, 0, 0);
			glVertex3f(0, 0, 0);
		}glEnd();
	}glPopMatrix();




	glPushMatrix(); {

		//glScalef(1.5, .1, .6);//Width scale factor along X, Scale factors along the Z axis, Scale factors along the Y axis

		glTranslatef(0,30, 0);

		glColor3f(1, 0, 0);
		glBegin(GL_QUADS); {
			glVertex3f(0, 0, 15);
			glVertex3f(40, 0, 15);
			glVertex3f(40, 0, 0);
			glVertex3f(0, 0, 0);
		}glEnd();
	}glPopMatrix();



	glPushMatrix(); {

		//glScalef(1.5, .1, .6);//Width scale factor along X, Scale factors along the Z axis, Scale factors along the Y axis

	    //	glTranslatef(0, 30, 0);

		glRotatef(90,0,0,2);
		glColor3f(0, 0, 1);
		glBegin(GL_QUADS); {
			glVertex3f(0, 0, 15);
			glVertex3f(30, 0, 15);
			glVertex3f(30, 0, 0);
			glVertex3f(0, 0, 0);
		}glEnd();
	}glPopMatrix();



	glPushMatrix(); {	
		glColor3f(0, 0, 1);
		glTranslatef(0,0,20);
		glBegin(GL_QUADS); {
			glVertex3f(40, 0, 15);
			glVertex3f(60, 0, 15);
			glVertex3f(60, 0, 0);
			glVertex3f(40, 0, 0);
		}glEnd();
	}glPopMatrix();






	//glPushMatrix(); {
	//	
	//	glScalef(3, .1, .6);//Width scale factor along X, Scale factors along the Z axis, Scale factors along the Y axis
	//	glTranslatef(0, 100, 0);
	//	glColor4f(0, 1, 0, 0);
	//	GLUquadricObj *quadric;
	//	quadric = gluNewQuadric();

	//	gluCylinder(quadric, 10, 10, 60, 60, 60);
	//}glPopMatrix();



	//---------------Cone-----------

//	glutSolidCone(20, 20, 30, 20);



	//-------Rocket----------------------


	//glColor3f(0,1,1);
	//glBegin(GL_QUADS);{
	//glVertex3f(55,0,10);
	//glVertex3f(20,0,10);
	//glVertex3f(15,0,0);
	//glVertex3f(60,0,0);
	//}glEnd();

	//glBegin(GL_QUADS);{
	//glVertex3f(50,0,60);
	//glVertex3f(20,0,60);
	//glVertex3f(20,0,10);
	//glVertex3f(55,0,10);
	//}glEnd();

	//glColor3f(1,1,0);
	//glBegin(GL_TRIANGLES);{
	//glVertex3f(20, 0,60);
	//glVertex3f(50, 0,60);
	//glVertex3f(35, 0,80);
	//}glEnd();



	//---------------House-------------------




	/*glColor3f(0,0,1);
	glBegin(GL_QUADS);{
	glVertex3f(40,-1,60);
	glVertex3f(30,-1,60);
	glVertex3f(30,-1,10);
	glVertex3f(40,-1,10);
	}glEnd();
	*/

	//------------door-----------------


	/*glColor3f(0,1,1);
	glBegin(GL_QUADS);{
	glVertex3f(20,-1,10);
	glVertex3f(10,-1,10);
	glVertex3f(10,-1,0);
	glVertex3f(20,-1,0);
	}glEnd();*/
	

	//------------rectangle-----------------

	/*glColor3f(1,0,0);
	glBegin(GL_QUADS);{
	glVertex3f(0,0,15);
	glVertex3f(40,0,15);
	glVertex3f(40,0,0);
	glVertex3f(0,0,0);
	}glEnd();*/

	//------------triangle-----------------
	/*glColor3f(1,1,0);
	glBegin(GL_TRIANGLES);{
	glVertex3f(20, 0,20);
	glVertex3f(45, 0, 15);
	glVertex3f(-5, 0, 15);
	}glEnd();*/
	
	//---------------House-------------------




//-------------Circle---------------
	


  /*  glutSolidCube(15);
	glutWireCube(30);
	glutSolidSphere(10,20,20);
	glutWireSphere(30,30,30);
	glutSolidCone(10,30,100,100);
	glutWireCone(30,50,70,70);

	glPushMatrix();{
	glRotatef(90,1,0,0);
	glutSolidTorus(20,30,70,70);
	}
	glPopMatrix();

	glPushMatrix();{
	glRotatef(90,1,0,0);
	glutWireTorus(10,25,50,50);
	}
	glPopMatrix();
	
	glPushMatrix();{
	glRotatef(90,1,0,0);
	GLUquadricObj *quadric;
	quadric=gluNewQuadric();
	gluCylinder(quadric,10,10,30,20,20);
	}
	glPopMatrix();
*/


	//-------------Circle---------------



	/*glPushMatrix();
	{
	glScalef(2,2,2);

	glRotatef(0,1,0,0);

	glBegin(GL_TRIANGLES);{
	glVertex3f(20, 0, 0);
	glVertex3f(40, 0, 0);
	glVertex3f(30, 0, 10);
	}glEnd();
	}

	glPopMatrix();
	*/

	//some gridlines along the field
	int i;

	glColor3f(0.5, 0.5, 0.5);    //grey
	glBegin(GL_LINES); {
		for (i = -10; i <= 10; i++){

			if (i == 0)
				continue;    //SKIP the MAIN axes

			//lines parallel to Y-axis
			glVertex3f(i * 10, -100, 0);
			glVertex3f(i * 10, 100, 0);

			//lines parallel to X-axis
			glVertex3f(-100, i * 10, 0);
			glVertex3f(100, i * 10, 0);
		}
	}glEnd();

	// draw the three AXES

	glBegin(GL_LINES); {
		//X axis
		glColor3f(0, 1, 0);    //100% Green
		glVertex3f(-150, 0, 0);
		glVertex3f(150, 0, 0);

		//Y axis
		glColor3f(0, 0, 1);    //100% Blue
		glVertex3f(0, -150, 0);    // intentionally extended to -150 to 150, no big deal
		glVertex3f(0, 150, 0);

		//Z axis
		glColor3f(1, 1, 1);    //100% White
		glVertex3f(0, 0, -150);
		glVertex3f(0, 0, 150);
	}glEnd();



	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Models, Camera

	//cameraAngle += 0.0001;    // camera will rotate at 0.001 radians per frame.

	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following
	glutPostRedisplay();    //this will call the display AGAIN

}

void init(){
	//codes for initialization

	cameraAngle = 0;    //angle in radian
	//clear the screen
	glClearColor(0, 0, 0, 0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	/*
	gluPerspective() — set up a perspective projection matrix

	fovy -         Specifies the field of view angle, in degrees, in the y direction.
	aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
	zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
	*/

	gluPerspective(70, 1, 0.1, 10000.0);

}

int main(int argc, char **argv){

	glutInit(&argc, argv);                            //initialize the GLUT library

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	/*
	glutInitDisplayMode - inits display mode
	GLUT_DOUBLE - allows for display on the double buffer window
	GLUT_RGBA - shows color (Red, green, blue) and an alpha
	GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("Some Title");

	init();                        //codes for initialization

	glEnable(GL_DEPTH_TEST);    //enable Depth Testing

	glutDisplayFunc(display);    //display callback function
	glutIdleFunc(animate);        //what you want to do in the idle time (when no drawing is occuring)

	glutMainLoop();        //The main loop of OpenGL

	return 0;
}
