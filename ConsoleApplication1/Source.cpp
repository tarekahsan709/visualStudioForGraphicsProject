#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<GL/glut.h>

#define PI 3.14159

double wheelPostionx = 0;
double cameraAngle, cameraAngleDelta;
int canDrawGrid;
double iww = 0;

double cameraHeight;
double cameraRadius;

double carcentrex = 0, carcentrey = 0, carcentrez = 0;	//for moving whole shape
double speed = .5;

int num_texture = -1;
GLuint grassimg, wallimg, ballimg, cylimg, sandimg, carimg,pyramidimg;



int LoadBitmapImage(char *filename)
{
	int i, j = 0;
	FILE *l_file;
	unsigned char *l_texture;

	BITMAPFILEHEADER fileheader;
	BITMAPINFOHEADER infoheader;
	RGBTRIPLE rgb;

	num_texture++;

	if ((l_file = fopen(filename, "rb")) == NULL) return (-1);

	fread(&fileheader, sizeof(fileheader), 1, l_file);

	fseek(l_file, sizeof(fileheader), SEEK_SET);
	fread(&infoheader, sizeof(infoheader), 1, l_file);

	l_texture = (byte *)malloc(infoheader.biWidth * infoheader.biHeight * 4);
	memset(l_texture, 0, infoheader.biWidth * infoheader.biHeight * 4);
	for (i = 0; i < infoheader.biWidth*infoheader.biHeight; i++)
	{
		fread(&rgb, sizeof(rgb), 1, l_file);

		l_texture[j + 0] = rgb.rgbtRed;
		l_texture[j + 1] = rgb.rgbtGreen;
		l_texture[j + 2] = rgb.rgbtBlue;
		l_texture[j + 3] = 255;
		j += 4;
	}
	fclose(l_file);

	glBindTexture(GL_TEXTURE_2D, num_texture);

	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);


	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);		//set texture environment parameters
	glTexImage2D(GL_TEXTURE_2D, 0, 4, infoheader.biWidth, infoheader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);	// specify a two-dimensional texture image
	gluBuild2DMipmaps(GL_TEXTURE_2D, 4, infoheader.biWidth, infoheader.biHeight, GL_RGBA, GL_UNSIGNED_BYTE, l_texture);		//builds a two-dimensional mipmap

	free(l_texture);

	return (num_texture);

}

void loadImage()
{
	//baseimg = LoadBitmapImage("image/base.bmp");
	//sky = LoadBitmap("images/sky.bmp");
	sandimg = LoadBitmapImage("image/sand.bmp");
	grassimg = LoadBitmapImage("image/grass3.bmp");
	carimg = LoadBitmapImage("image/car2.bmp");
	pyramidimg = LoadBitmapImage("image/p.bmp");
	//cylimg = LoadBitmapImage("image/cyl.bmp");
	//ballimg = LoadBitmapImage("image/ball.bmp");
	//wallimg = LoadBitmapImage("image/wall.bmp");
	printf("Load successful");
}

void pyramid()
{
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
		glRotatef(30, 0, 1, 0);
		glPushMatrix();
		{
			glTranslatef(-57, -1, -40.3);
			glRotatef(90, 0, 0, 1);


			glBegin(GL_TRIANGLES); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, 0, 0);

				glTexCoord2f(1, 0);
				glVertex3f(30, 0, 0);

				glTexCoord2f(1, 1);
				glVertex3f(15, 0, 30);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();




	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
		glRotatef(30, 1, 0, 0);

		glPushMatrix();
		{
			glTranslatef(-70, 22, -20);
			glRotatef(0, 0, 0, 0);


			glBegin(GL_TRIANGLES); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, 0, 0);

				glTexCoord2f(1, 0);
				glVertex3f(30, 0, 0);

				glTexCoord2f(1, 1);
				glVertex3f(15, 0, 30);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();
	//------------------------------------------3rd part------------------------

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
		glRotatef(-30, 1, 0, 0);

		glPushMatrix();
		{
			glTranslatef(-70, 2.5, -6);
			glRotatef(0, 0, 0, 0);


			glBegin(GL_TRIANGLES); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, 0, 0);

				glTexCoord2f(1, 0);
				glVertex3f(30, 0, 0);

				glTexCoord2f(1, 1);
				glVertex3f(15, 0, 30);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	//------------------------------------------4th part------------------------

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
		glRotatef(-30, 0, 1, 0);
		glPushMatrix();
		{
			glTranslatef(-38, -1, 14.5);
			glRotatef(90, 0, 0, 1);


			glBegin(GL_TRIANGLES); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, 0, 0);

				glTexCoord2f(1, 0);
				glVertex3f(30, 0, 0);

				glTexCoord2f(1, 1);
				glVertex3f(15, 0, 30);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();


}
void drawWheel(double x){



	glPushMatrix(); {
		glTranslatef(5, 0, -1);
		glRotatef(iww, 0, -1, 0);
		glTranslatef(-5, 0, 0);



		glPushMatrix(); {


			glScalef(2, 2, 2);
			glTranslatef(x, 0, 0);
			glPushMatrix(); {

				glRotatef(90, 1, 0, 0);
				glPushMatrix(); {
					glColor3f(0, 0, 0);
					//** wheel's black outer part **//
					glutSolidTorus(.55, 1.8, 25, 25);

					//** wheel's inner disc part **//
					glColor3f(.6, .6, .6);
					gluDisk(gluNewQuadric(), 0, 1.25, 100, 100);

					//** Loop for drawing lines in inner part of wheel **/
					//inner lines
					glColor3f(.2, .2, .2);
					double i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glVertex3f(0, 0, .1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), .1);
						}
						glEnd();
						i += PI / 4;	//distance from one lines to another is 45 degree 
					}

					//outer lines
					i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glColor3f(.2, .2, .2);
							glVertex3f(0, 0, -.1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), -.1);
						}
						glEnd();
						i += PI / 4;
					}
				}
				glPopMatrix();
			}glPopMatrix();





		}glPopMatrix();




	}glPopMatrix();


}

void drawWheelFrontRight(double x){



	glPushMatrix(); {
		glTranslatef(-34, 0, -1);
		glRotatef(iww, 0, -1, 0);
		glTranslatef(34, 0, 0);



		glPushMatrix(); {


			glScalef(2, 2, 2);
			glTranslatef(x, 0, 0);
			glPushMatrix(); {

				glRotatef(90, 1, 0, 0);
				glPushMatrix(); {
					glColor3f(0, 0, 0);
					//** wheel's black outer part **//
					glutSolidTorus(.55, 1.8, 25, 25);

					//** wheel's inner disc part **//
					glColor3f(.6, .6, .6);
					gluDisk(gluNewQuadric(), 0, 1.25, 100, 100);

					//** Loop for drawing lines in inner part of wheel **/
					//inner lines
					glColor3f(.2, .2, .2);
					double i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glVertex3f(0, 0, .1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), .1);
						}
						glEnd();
						i += PI / 4;	//distance from one lines to another is 45 degree 
					}

					//outer lines
					i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glColor3f(.2, .2, .2);
							glVertex3f(0, 0, -.1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), -.1);
						}
						glEnd();
						i += PI / 4;
					}
				}
				glPopMatrix();
			}glPopMatrix();





		}glPopMatrix();




	}glPopMatrix();


}

void drawWheel2(double x, double y){

	glPushMatrix(); {

		glTranslatef(5, 0, -1);
		glRotatef(iww, 0, -1, 0);
		glTranslatef(-5, 0, 0);





		glPushMatrix(); {




			glScalef(2, 2, 2);
			glTranslatef(x, y, 0);
			glPushMatrix(); {

				glRotatef(90, 1, 0, 0);
				glPushMatrix(); {
					glColor3f(0, 0, 0);
					//** wheel's black outer part **//
					glutSolidTorus(.55, 1.8, 25, 25);

					//** wheel's inner disc part **//
					glColor3f(.6, .6, .6);
					gluDisk(gluNewQuadric(), 0, 1.25, 100, 100);

					//** Loop for drawing lines in inner part of wheel **/
					//inner lines
					glColor3f(.2, .2, .2);
					double i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glVertex3f(0, 0, .1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), .1);
						}
						glEnd();
						i += PI / 4;	//distance from one lines to another is 45 degree 
					}

					//outer lines
					i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glColor3f(.2, .2, .2);
							glVertex3f(0, 0, -.1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), -.1);
						}
						glEnd();
						i += PI / 4;
					}
				}
				glPopMatrix();
			}glPopMatrix();







		}glPopMatrix();




	}glPopMatrix();


}


void drawWheel23(double x, double y){

	glPushMatrix(); {

		glTranslatef(-34, 0, -1);
		glRotatef(iww, 0, -1, 0);
		glTranslatef(34, 0, 0);






		glPushMatrix(); {




			glScalef(2, 2, 2);
			glTranslatef(x, y, 0);
			glPushMatrix(); {

				glRotatef(90, 1, 0, 0);
				glPushMatrix(); {
					glColor3f(0, 0, 0);
					//** wheel's black outer part **//
					glutSolidTorus(.55, 1.8, 25, 25);

					//** wheel's inner disc part **//
					glColor3f(.6, .6, .6);
					gluDisk(gluNewQuadric(), 0, 1.25, 100, 100);

					//** Loop for drawing lines in inner part of wheel **/
					//inner lines
					glColor3f(.2, .2, .2);
					double i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glVertex3f(0, 0, .1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), .1);
						}
						glEnd();
						i += PI / 4;	//distance from one lines to another is 45 degree 
					}

					//outer lines
					i = .25*wheelPostionx;
					while (i<2 * PI + .25*wheelPostionx)
					{
						glBegin(GL_LINES);
						{
							glColor3f(.2, .2, .2);
							glVertex3f(0, 0, -.1);
							glVertex3f(1.25*cos(i), 1.25*sin(i), -.1);
						}
						glEnd();
						i += PI / 4;
					}
				}
				glPopMatrix();
			}glPopMatrix();







		}glPopMatrix();




	}glPopMatrix();


}


void drawShape(double y){


















	//glPushMatrix();
	//{
	//	glTranslatef(0, 0, 1);


	//----------------upper bar------------------
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-35, 0, 14);


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 2);

				glTexCoord2f(0, 1);
				glVertex3f(45, y, 2);

				glTexCoord2f(1, 0);
				glVertex3f(45, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();


	//glPushMatrix();
	//{
	//	glColor3f(1, .2, 0.2);
	//	glTranslatef(-35, 0, 14);
	//	/*glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/

	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 2);
	//		glVertex3f(45, y, 2);
	//		glVertex3f(45, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------------------------------

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(5, 0, 8);


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 8);


				glTexCoord2f(0, 1);
				glVertex3f(5, y, 8);

				glTexCoord2f(1, 0);
				glVertex3f(5, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();




	//glPushMatrix();
	//{
	//	glColor3f(.2, .2, 0.2);
	//	glTranslatef(5, 0, 8);
	//	/*glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/

	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 8);
	//		glVertex3f(5, y, 8);
	//		glVertex3f(5, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------------------------------

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-20, 0, 8);


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 8);


				glTexCoord2f(0, 1);
				glVertex3f(10, y, 8);

				glTexCoord2f(1, 0);
				glVertex3f(10, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();






	//glPushMatrix();
	//{
	//	glColor3f(.2, .2, 0.2);
	//	glTranslatef(-20, 0, 8);
	//	/*glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/

	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 8);
	//		glVertex3f(10, y, 8);
	//		glVertex3f(10, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();
	//}glPopMatrix();





	//---------------------Side Glass--------------------------




	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 0, .5);
		glTranslatef(-10, 0, 8);
		/*glScalef(0.3,1,0);
		glRotatef(-90, 1, 0, 0);*/

		glBegin(GL_QUADS);
		{
			glVertex3f(0, y, 6);
			glVertex3f(15, y, 6);
			glVertex3f(15, y, 0);
			glVertex3f(0, y, 0);
		}glEnd();
	}glPopMatrix();



	//-------------------------Side Glass-------------------------

	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 0, .5);
		glTranslatef(-35, 0, 8);
		/*glScalef(0.3,1,0);
		glRotatef(-90, 1, 0, 0);*/

		glBegin(GL_QUADS);
		{
			glVertex3f(0, y, 6);
			glVertex3f(15, y, 6);
			glVertex3f(15, y, 0);
			glVertex3f(0, y, 0);
		}glEnd();
	}glPopMatrix();


	//-----------------------Head side----------------------------












	//-----------------------right side----------------------------
	//-----------------------middle part---------------------------
	//glPushMatrix();
	//{
	//	glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
	//	glPushMatrix();
	//	{
	//		//glTranslatef(-20, 0, 8);


	//		glBegin(GL_QUADS); {
	//			//glNormal3f(0,0,1);
	//			glColor3f(1.0f, 1.0f, 1.0f);

	//			glTexCoord2f(0, 0);
	//			glVertex3f(0, y, 1);


	//			glTexCoord2f(0, 1);
	//			glVertex3f(.5, y, 1);

	//			glTexCoord2f(1, 0);
	//			glVertex3f(.5, y, 0);

	//			glTexCoord2f(1, 1);
	//			glVertex3f(0, y, 0);

	//		}glEnd();
	//	}
	//	glPopMatrix();

	//	glDisable(GL_TEXTURE_2D);
	//}
	//glPopMatrix();


	//glPushMatrix();
	//{

	//	/*glTranslatef(0,-10,25);
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/
	//	glColor3f(0.2, .2, 0.2);
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 1);
	//		glVertex3f(.5, y, 1);
	//		glVertex3f(.5, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();
	//}glPopMatrix();



	//-----------------------2nd part---------------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(0, 0, 5); //last one ins y axis


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 3);


				glTexCoord2f(0, 1);
				glVertex3f(10, y, 3);

				glTexCoord2f(1, 0);
				glVertex3f(10, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();




	//glPushMatrix();
	//{
	//	glColor3f(1, .2, 0.2);
	//	/*
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/
	//	glTranslatef(0, 0, 5); //last one ins y axis
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 3);
	//		glVertex3f(10, y, 3);
	//		glVertex3f(10, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------3rd part---------------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			//glTranslatef(0, 0, 5); //last one ins y axis


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(11, y, 16);

				glTexCoord2f(0, 1);
				glVertex3f(12, y, 16);

				glTexCoord2f(1, 0);
				glVertex3f(12, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(11, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();







	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	/*
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/
	//	//glTranslatef(0, 0, 7); //last one ins y axis
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(11, y, 16);
	//		glVertex3f(12, y, 16);
	//		glVertex3f(12, y, 0);
	//		glVertex3f(11, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------4th part---------------------------



	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			//glTranslatef(0, 0, 5); //last one ins y axis


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(10, y, 10);

				glTexCoord2f(0, 1);
				glVertex3f(17, y, 10);

				glTexCoord2f(1, 0);
				glVertex3f(17, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(10, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();



	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	/*
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/
	//	//glTranslatef(0, 0, 7); //last one ins y axis
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(10, y, 10);
	//		glVertex3f(17, y, 10);
	//		glVertex3f(17, y, 0);
	//		glVertex3f(10, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------5th part triangle---------------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-13, 0, 10);


			glBegin(GL_TRIANGLES); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(23, y, 0);

				glTexCoord2f(0, 1);
				glVertex3f(23, y, 6);

				glTexCoord2f(1, 0);
				glVertex3f(31, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();




	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	glTranslatef(-13, 0, 10);
	//	glBegin(GL_TRIANGLES); {
	//		glVertex3f(23, y, 0);
	//		glVertex3f(23, y, 6);
	//		glVertex3f(31, y, 0);
	//	}glEnd();

	//}glPopMatrix();

	//-----------------------Back Cover----------------------------




	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-3, -51, 0);
			glRotatef(90, 0, 0, 1);


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(31, y, 10);

				glTexCoord2f(0, 1);
				glVertex3f(51, y, 10);

				glTexCoord2f(1, 0);
				glVertex3f(51, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(31, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();



	/*glPushMatrix();
	{
		glColor3f(0.2, .2, 0.2);
		glTranslatef(-3, -51, 0);

		glRotatef(90, 0, 0, 1);
		glBegin(GL_QUADS);
		{
			glVertex3f(31, y, 10);
			glVertex3f(51, y, 10);
			glVertex3f(51, y, 0);
			glVertex3f(31, y, 0);
		}glEnd();
	}glPopMatrix();*/

	//-----------------------Front Cover----------------------------
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-50, -51, 0);
			glRotatef(90, 0, 0, 1);


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(31, y, 8);

				glTexCoord2f(0, 1);
				glVertex3f(51, y, 8);

				glTexCoord2f(1, 0);
				glVertex3f(51, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(31, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();


	/*glPushMatrix();
	{
		glColor3f(0.2, .2, 0.2);
		glTranslatef(-50, -51, 0);

		glRotatef(90, 0, 0, 1);
		glBegin(GL_QUADS);
		{
			glVertex3f(31, y, 8);
			glVertex3f(51, y, 8);
			glVertex3f(51, y, 0);
			glVertex3f(31, y, 0);
		}glEnd();
	}glPopMatrix();
*/



	//-----------------------Middle part of side----------------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 8);

				glTexCoord2f(0, 1);
				glVertex3f(-30, y, 8);

				glTexCoord2f(1, 0);
				glVertex3f(-30, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();



	//glPushMatrix();
	//{
	//	glColor3f(1, .2, 0.2);
	//	/*glTranslatef(0,-10,25);
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/

	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 8);
	//		glVertex3f(-30, y, 8);
	//		glVertex3f(-30, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------2nd part---------------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{

			glTranslatef(0, 0, 5); //last one ins y axis


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(-30, y, 3);

				glTexCoord2f(0, 1);
				glVertex3f(-39, y, 3);

				glTexCoord2f(1, 0);
				glVertex3f(-39, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(-30, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();



	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	/*
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/
	//	glTranslatef(0, 0, 5); //last one ins y axis
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(-30, y, 3);
	//		glVertex3f(-39, y, 3);
	//		glVertex3f(-39, y, 0);
	//		glVertex3f(-30, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------3rd part---------------------------




	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{



			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(-39, y, 8);

				glTexCoord2f(0, 1);
				glVertex3f(-50, y, 8);

				glTexCoord2f(1, 0);
				glVertex3f(-50, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(-39, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();



	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	/*
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/
	//	//glTranslatef(0, 0, 7); //last one ins y axis
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(-39, y, 8);
	//		glVertex3f(-50, y, 8);
	//		glVertex3f(-50, y, 0);
	//		glVertex3f(-39, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-----------------------4th part---------------------------
	//glPushMatrix();
	//{
	//	glColor3f(1, 0, 0);
	//	/*
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/
	//	//glTranslatef(0, 0, 7); //last one ins y axis
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(-38, y, 10);
	//		glVertex3f(-50, y, 10);
	//		glVertex3f(-50, y, 0);
	//		glVertex3f(-38, y, 0);
	//	}glEnd();
	//}glPopMatrix();

	//-------------------Another Right side---------------------
	//glPushMatrix();
	//{
	//	glColor3f(0, 0, 1);
	//	/*glTranslatef(0,-10,25);
	//	glScalef(0.3,1,0);
	//	glRotatef(-90, 1, 0, 0);*/

	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y-10, 10);
	//		glVertex3f(30, y-10, 10);
	//		glVertex3f(30, y-10, 0);
	//		glVertex3f(0, y-10, 0);
	//	}glEnd();
	//}glPopMatrix();


	//------------------roof---------------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-35, -20, 16);
			glScalef(1.65, 1, 0);
			glRotatef(-90, 1, 0, 0);


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 20);

				glTexCoord2f(0, 1);
				glVertex3f(27, y, 20);

				glTexCoord2f(1, 0);
				glVertex3f(27, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();




	/*glPushMatrix();
	{
		glColor3f(0.2, .2, 0.2);
		glTranslatef(-35, -20, 16);
		glScalef(1.65, 1, 0);
		glRotatef(-90, 1, 0, 0);
		glBegin(GL_QUADS);
		{
			glVertex3f(0, y, 20);
			glVertex3f(27, y, 20);
			glVertex3f(27, y, 0);
			glVertex3f(0, y, 0);
		}glEnd();

	}glPopMatrix();
*/
	//-----------------under ground---------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-47, -20, 1);
			glScalef(1.85, 1, 0);
			glRotatef(-90, 1, 0, 0);


			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 20);

				glTexCoord2f(0, 1);
				glVertex3f(35, y, 20);

				glTexCoord2f(1, 0);
				glVertex3f(35, y, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();



	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	glTranslatef(-47, -20, 1);
	//	glScalef(1.85, 1, 0);
	//	glRotatef(-90, 1, 0, 0);
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 20);
	//		glVertex3f(35, y, 20);
	//		glVertex3f(35, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();

	//}glPopMatrix();
	//-----------------right side triangle------------------


	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-45, 0, 8);


			glBegin(GL_TRIANGLES); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(10, y, 8);

				glTexCoord2f(0, 1);
				glVertex3f(10, y, 0);

				glTexCoord2f(1, 0);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();



	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	glTranslatef(-45, 0, 8);
	//	glBegin(GL_TRIANGLES); {
	//		glVertex3f(10, y, 8);
	//		glVertex3f(10, y, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();

	//}glPopMatrix();







	/*}glPopMatrix();*/

}
void frontGlass(double y)
{
	//-----------------------Back Light 1------------------------------


	glPushMatrix();
	{

		glColor4f(1, 0, 0, 1);
		glRotatef(90, 0, 0, 1);
		glTranslatef(-5, -17.1, 7.5);
		glBegin(GL_QUADS);
		{
			glVertex3f(0, y, 3);
			glVertex3f(4, y, 3);
			glVertex3f(4, y, 0);
			glVertex3f(0, y, 0);
		}glEnd();
	}glPopMatrix();


	//-----------------------Back Light 2------------------------------


	glPushMatrix();
	{

		glColor4f(1, 0, 0, 1);
		glRotatef(90, 0, 0, 1);
		glTranslatef(-19, -17.1, 7.5);
		glBegin(GL_QUADS);
		{
			glVertex3f(0, y, 3);
			glVertex3f(4, y, 3);
			glVertex3f(4, y, 0);
			glVertex3f(0, y, 0);
		}glEnd();
	}glPopMatrix();


	//-----------------------Front Glass----------------------------
	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 0, .5);
		glTranslatef(-44, -20, 8);

		glRotatef(50, 0, 1, 0);
		glBegin(GL_QUADS);
		{
			glVertex3f(0, y, 12);
			glVertex3f(0, y + 20, 12);
			glVertex3f(0, y + 20, 0);
			glVertex3f(0, y, 0);
		}glEnd();
	}glPopMatrix();

	//-----------------------Back Glass----------------------------
	glPushMatrix();
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 0, .5);
		glTranslatef(16, -20, 10);

		glRotatef(-51, 0, 1, 0);
		glBegin(GL_QUADS);
		{
			glVertex3f(0, y, 9);
			glVertex3f(0, y + 20, 9);
			glVertex3f(0, y + 20, 0);
			glVertex3f(0, y, 0);
		}glEnd();
	}glPopMatrix();

	//-----------------------Front Engine cover----------------------------

	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, carimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glTranslatef(-50, -20, 8);

			glRotatef(90, 0, 1, 0);

			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(0, y, 8.5);

				glTexCoord2f(0, 1);
				glVertex3f(0, y + 20, 8.5);

				glTexCoord2f(1, 0);
				glVertex3f(0, y + 20, 0);

				glTexCoord2f(1, 1);
				glVertex3f(0, y, 0);

			}glEnd();
		}
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();










	//glPushMatrix();
	//{
	//	glColor3f(0.2, .2, 0.2);
	//	glTranslatef(-50, -20, 8);

	//	glRotatef(90, 0, 1, 0);
	//	glBegin(GL_QUADS);
	//	{
	//		glVertex3f(0, y, 8.5);
	//		glVertex3f(0, y + 20, 8.5);
	//		glVertex3f(0, y + 20, 0);
	//		glVertex3f(0, y, 0);
	//	}glEnd();
	//}glPopMatrix();


}


void display(){
	//codes for Models, Camera

	//clear the display
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1, 0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		//clear buffers to preset values

	/***************************
	/ set-up camera (view) here
	****************************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);		//specify which matrix is the current matrix

	//initialize the matrix
	glLoadIdentity();				//replace the current matrix with the identity matrix [Diagonals have 1, others have 0]

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(0,-150,20,	0,0,0,	0,0,1);
	gluLookAt(cameraRadius*sin(cameraAngle), -cameraRadius*cos(cameraAngle), cameraHeight, 0, 0, 0, 0, 0, 1);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/**************************************************
	/ Grid and axes Lines(You can remove them if u want)
	***************************************************/
	//// draw the three major AXES
	//glBegin(GL_LINES);
	////X axis
	//glColor3f(0, 1, 0);	//100% Green
	//glVertex3f(-150, 0, 0);
	//glVertex3f(150, 0, 0);

	////Y axis
	//glColor3f(0, 0, 1);	//100% Blue
	//glVertex3f(0, -150, 0);	// intentionally extended to -150 to 150, no big deal
	//glVertex3f(0, 150, 0);

	////Z axis
	//glColor3f(1, 1, 1);	//100% White
	//glVertex3f(0, 0, -150);
	//glVertex3f(0, 0, 150);
	//glEnd();

	//some gridlines along the field
	int i;
	if (canDrawGrid){
		glColor3f(0.5, 0.5, 0.5);	//grey
		glBegin(GL_LINES);
		for (i = -10; i <= 10; i++){

			if (i == 0)
				continue;	//SKIP the MAIN axes

			//lines parallel to Y-axis
			glVertex3f(i * 10, -100, 0);
			glVertex3f(i * 10, 100, 0);

			//lines parallel to X-axis
			glVertex3f(-100, i * 10, 0);
			glVertex3f(100, i * 10, 0);
		}
		glEnd();
	}





	/****************************
	/ Add your objects from here
	****************************/
	//-------------------Sand---------------------------
	
	glPushMatrix();
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, sandimg);	//bind a named texture to a texturing target
		glPushMatrix();
		{
			glRotatef(-1.5, 0, 0, 1);
			glTranslatef(-124.5, 0, -1);

			glBegin(GL_QUADS); {
				//glNormal3f(0,0,1);
				glColor3f(1.0f, 1.0f, 1.0f);

				glTexCoord2f(0, 0);
				glVertex3f(-100, 200, 0);

				glTexCoord2f(0, 1);
				glVertex3f(-100, -150, 0);

				glTexCoord2f(1, 0);
				glVertex3f(100, -150, 0);

				glTexCoord2f(1, 1);
				glVertex3f(100, 200, 0);
			}glEnd();
		}
		glPopMatrix();

	    glDisable(GL_TEXTURE_2D);
	}
	glPopMatrix();

	//-------------------Grass---------------------------
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, grassimg);	//bind a named texture to a texturing target
	glPushMatrix();
	{
		glRotatef(1.5, 0, 0, 1);
		glTranslatef(124.5, 0, -1);

		glBegin(GL_QUADS); {
			//glNormal3f(0,0,1);
			glColor3f(1.0f, 1.0f, 1.0f);

			glTexCoord2f(0, 0);
			glVertex3f(-100, 200, 0);

			glTexCoord2f(0, 1);
			glVertex3f(-100, -150, 0);

			glTexCoord2f(1, 0);
			glVertex3f(100, -150, 0);

			glTexCoord2f(1, 1);
			glVertex3f(100, 200, 0);
		}glEnd();
	}
	glPopMatrix();

	glDisable(GL_TEXTURE_2D);

	//---------------------------Pyramid--------------------------------------------

	glPushMatrix();
	{
		glScalef(2, 2, 2);
		glTranslatef(0, 0, 0);
		pyramid();

	}
	glPopMatrix();
	
	glPushMatrix();
	{
		glScalef(2, 2, 2);
		glTranslatef(5, 30, 0);
		pyramid();

	}
	glPopMatrix();

	//glPushMatrix();
	//{
	//	glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
	//	glRotatef(30, 0, 1, 0);
	//	glPushMatrix();
	//	{
	//		glTranslatef(-57, -1, -40);
	//		glRotatef(90, 0, 0, 1);


	//		glBegin(GL_TRIANGLES); {
	//			//glNormal3f(0,0,1);
	//			glColor3f(1.0f, 1.0f, 1.0f);

	//			glTexCoord2f(0, 0);
	//			glVertex3f(0, 0, 0);

	//			glTexCoord2f(1, 0);
	//			glVertex3f(30, 0, 0);

	//			glTexCoord2f(1, 1);
	//			glVertex3f(15, 0, 30);

	//		}glEnd();
	//	}
	//	glPopMatrix();

	//	glDisable(GL_TEXTURE_2D);
	//}
	//glPopMatrix();




	//glPushMatrix();
	//{
	//	glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
	//	glRotatef(30, 1, 0, 0);

	//	glPushMatrix();
	//	{
	//		glTranslatef(-70, 22, -20);
	//		glRotatef(0, 0, 0, 0);


	//		glBegin(GL_TRIANGLES); {
	//			//glNormal3f(0,0,1);
	//			glColor3f(1.0f, 1.0f, 1.0f);

	//			glTexCoord2f(0, 0);
	//			glVertex3f(0, 0, 0);

	//			glTexCoord2f(1, 0);
	//			glVertex3f(30, 0, 0);

	//			glTexCoord2f(1, 1);
	//			glVertex3f(15, 0, 30);

	//		}glEnd();
	//	}
	//	glPopMatrix();

	//	glDisable(GL_TEXTURE_2D);
	//}
	//glPopMatrix();
	////------------------------------------------3rd part------------------------

	//glPushMatrix();
	//{
	//	glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
	//	glRotatef(-30, 1, 0, 0);

	//	glPushMatrix();
	//	{
	//		glTranslatef(-70, 2, -6);
	//		glRotatef(0, 0, 0, 0);


	//		glBegin(GL_TRIANGLES); {
	//			//glNormal3f(0,0,1);
	//			glColor3f(1.0f, 1.0f, 1.0f);

	//			glTexCoord2f(0, 0);
	//			glVertex3f(0, 0, 0);

	//			glTexCoord2f(1, 0);
	//			glVertex3f(30, 0, 0);

	//			glTexCoord2f(1, 1);
	//			glVertex3f(15, 0, 30);

	//		}glEnd();
	//	}
	//	glPopMatrix();

	//	glDisable(GL_TEXTURE_2D);
	//}
	//glPopMatrix();
	//
	////------------------------------------------4th part------------------------

	//glPushMatrix();
	//{
	//	glEnable(GL_TEXTURE_2D);
	//	glBindTexture(GL_TEXTURE_2D, pyramidimg);	//bind a named texture to a texturing target
	//	glRotatef(-30, 0, 1, 0);
	//	glPushMatrix();
	//	{
	//		glTranslatef(-38, -1, 15);
	//		glRotatef(90, 0, 0, 1);


	//		glBegin(GL_TRIANGLES); {
	//			//glNormal3f(0,0,1);
	//			glColor3f(1.0f, 1.0f, 1.0f);

	//			glTexCoord2f(0, 0);
	//			glVertex3f(0, 0, 0);

	//			glTexCoord2f(1, 0);
	//			glVertex3f(30, 0, 0);

	//			glTexCoord2f(1, 1);
	//			glVertex3f(15, 0, 30);

	//		}glEnd();
	//	}
	//	glPopMatrix();

	//	glDisable(GL_TEXTURE_2D);
	//}
	//glPopMatrix();






	//---------------------------Road--------------------------------------------
	glPushMatrix();
	{
		glColor3f(1, 0, 0);
		glBegin(GL_QUADS); {
			glVertex3f(-30, -150, 0);
			glVertex3f(-28, -150, 0);
			glVertex3f(-20, 200, 0);
			glVertex3f(-18, 200, 0);


		}glEnd();
		glBegin(GL_QUADS); {
			glVertex3f(30, -150, 0);
			glVertex3f(28, -150, 0);
			glVertex3f(20, 200, 0);
			glVertex3f(18, 200, 0);


		}glEnd();

		for (int i = -150; i<200; i = i + 20)
		{
			glColor3f(1, 1, 1);
			glBegin(GL_QUADS); {
				glVertex3f(-1, i, 0);
				glVertex3f(1, i, 0);
				glVertex3f(1, i + 15, 0);
				glVertex3f(-1, i + 15, 0);


			}glEnd();

		}

	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0, 0, -1);
		glColor3f(0, 0, 0);
		glBegin(GL_QUADS); {
			glVertex3f(-29, -150, 0);
			glVertex3f(29, -150, 0);
			glVertex3f(19, 200, 0);
			glVertex3f(-19, 200, 0);
		}glEnd();
	}
	glPopMatrix();



	//calling car function



	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)











	/*glPushMatrix(); {
	glTranslatef(carcentrex, carcentrey, carcentrez);
	drawShape(0);
	drawShape(50);
	}glPopMatrix();*/

	glPushMatrix();
	{
		glRotatef(-90, 0, 0, 1);
		glTranslatef(50, 10, 4);


		glPushMatrix();
		{
			glTranslatef(carcentrex, carcentrey, carcentrez);
			drawShape(0);

		}glPopMatrix();


		glPushMatrix();
		{
			glTranslatef(carcentrex, carcentrey, carcentrez);
			drawShape(-20);

		}glPopMatrix();

		//--------------------Drawing Front Glass------------
		glPushMatrix();
		{
			glTranslatef(carcentrex, carcentrey, carcentrez);
			frontGlass(0);


		}glPopMatrix();
		////--------------------Drawing Wheel back right------------------
		glPushMatrix();
		{
			/*glTranslatef(4.8,0,-1);
			glRotatef(iww,0,-1,0);
			glTranslatef(-4.8,0,0);*/

			glPushMatrix();
			{
				glTranslatef(carcentrex, carcentrey, carcentrez);
				drawWheel(2.5);

			}glPopMatrix();

		}glPopMatrix();

		//--------------------Drawing wheel front right-------------
		glPushMatrix();
		{

			glPushMatrix();
			{
				glTranslatef(carcentrex, carcentrey, carcentrez);
				drawWheelFrontRight(-17);

			}glPopMatrix();

		}glPopMatrix();

		////--------------------Drawing Wheel left back ------------------
		glPushMatrix();
		{
			/*glTranslatef(4.8,0,-1);
			glRotatef(iww,0,-1,0);
			glTranslatef(-4.8,0,0);		*/

			glPushMatrix();
			{
				glTranslatef(carcentrex, carcentrey, carcentrez);

				drawWheel2(2.5, -10);

			}glPopMatrix();


		}glPopMatrix();



		glPushMatrix();
		{
			glTranslatef(carcentrex, carcentrey, carcentrez);

			drawWheel23(-17, -10);

		}glPopMatrix();



	}glPopMatrix();




	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}

void animate(){
	//codes for any changes in Models, Camera

	//cameraAngle += cameraAngleDelta;	// camera will rotate at 0.002 radians per frame.

	//codes for any changes in Models

	//MISSING SOMETHING? -- YES: add the following

	//iww = iww + 0.5;
	glutPostRedisplay();	//this will call the display AGAIN

}

void keyboardListener(unsigned char key, int x, int y){
	switch (key){

	case 'w':

		carcentrex -= speed;
		wheelPostionx += 0.5;

		break;



	case 's':
		carcentrex += speed;
		wheelPostionx -= 0.5;

		break;

	case 'd':
		if (carcentrey <= 15)
		{
			carcentrey += speed;
			break;
		}
		else
			break;

	case 'a':
		if (carcentrey >= -15)
		{
			carcentrey -= speed;
			break;
		}
		else
			break;

	case '8':	//toggle grids
		canDrawGrid = 1 - canDrawGrid;
		break;

	case 'p':	//toggle grids
		cameraAngleDelta = 0;
		break;
	case 'r':	//toggle grids
		cameraAngleDelta = .001;
		break;

	default:
		break;
	}
}


void specialKeyListener(int key, int x, int y){
	switch (key){
	case GLUT_KEY_DOWN:		//down arrow key
		cameraRadius += 10;
		break;
	case GLUT_KEY_UP:		// up arrow key
		if (cameraRadius > 10)
			cameraRadius -= 10;
		break;

	case GLUT_KEY_RIGHT:
		cameraAngle += 0.01;
		break;
	case GLUT_KEY_LEFT:
		cameraAngle -= 0.01;
		break;

	case GLUT_KEY_PAGE_UP:
		cameraHeight += 10;
		break;
	case GLUT_KEY_PAGE_DOWN:
		cameraHeight -= 10;
		break;

	case GLUT_KEY_INSERT:
		break;

	case GLUT_KEY_HOME:
		break;
	case GLUT_KEY_END:
		break;

	default:
		break;
	}
}




void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch (button){
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
			cameraAngleDelta = -cameraAngleDelta;
		}
		break;

	case GLUT_RIGHT_BUTTON:
		//........
		break;

	case GLUT_MIDDLE_BUTTON:
		//........
		break;

	default:
		break;
	}
}



void init(){
	//codes for initialization
	loadImage();
	cameraAngle = 0;	//angle in radian
	cameraAngleDelta = 0.001;
	canDrawGrid = 1;

	cameraHeight = 50;
	cameraRadius = 150;
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
	gluPerspective() ? set up a perspective projection matrix
	fovy -         Specifies the field of view angle, in degrees, in the y direction.
	aspect ratio - Specifies the aspect ratio that determines the field of view in the x direction. The aspect ratio is the ratio of x (width) to y (height).
	zNear -        Specifies the distance from the viewer to the near clipping plane (always positive).
	zFar  -        Specifies the distance from the viewer to the far clipping plane (always positive).
	*/

	gluPerspective(70, 1, 0.1, 10000.0);

}

int main(int argc, char **argv){

	glutInit(&argc, argv);							//initialize the GLUT library

	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	/*
	glutInitDisplayMode - inits display mode
	GLUT_DOUBLE - allows for display on the double buffer window
	GLUT_RGBA - shows color (Red, green, blue) and an alpha
	GLUT_DEPTH - allows for depth buffer
	*/
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);

	glutCreateWindow("OpenGl Car");

	init();						//codes for initialization

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	//ADD keyboard listeners:
	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	//ADD mouse listeners:
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}