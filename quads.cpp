/***********************************************************************/
/*                           HW#2-1 : GL_MODELING-2D Primitives ����              */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 9�� 24��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*   Points, Lines, LineStrip, LineLoop, TrangleFan, Triangles, TriangleStrip */
/*                Polygons, Quads, QuadStrip ����                            */
/* ��� :                                                                   */
/*       2D triangle Gasket�� �Ʒ��� ���� 3D tetrahedron Gasket���� ����   */
//       z ���� ��� 0���� �����ϰ�, x��� y�� ���� ���                  //
/*************************************************************************/

#include <GL/glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);   //����� �Ͼ������ �����Ͽ����ϴ�
	glColor3f(1.0, 0, 0);                //���������� �����Ͽ� �ߺ��̰� �Ͽ����ϴ�

	//// *** GL_QUADS �Դϴ�
	glShadeModel(GL_FLAT);
	glBegin(GL_QUADS);    //������ �װ��� �����ذ��� �簢���� ������ݴϴ�
	glVertex3f(0.3, -0.15, 0.0);  // �� ���� ��ǥ�� �����Ͽ��� v0~v7
	glVertex3f(0.4, 0.0, 0.0);  
	glVertex3f(0.15, 0.1, 0.0);  
	glVertex3f(0.0, -0.15, 0.0);    //v0~ v3 ù��° �簢��
	glColor3f(0, 1.0, 0);      // ���� �簢���� ���� ���� �ϱ����� ���� �ٲ���
	glVertex3f(-0.1, 0.0, 0.0);  
	glVertex3f(-0.05, 0.3, 0.0); 
	glVertex3f(-0.3, 0.25, 0.0);  
	glVertex3f(-0.35, 0.15, 0.0);    //v4~ v7 �ι�° �簢��

	glEnd();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);     //GLUT library �ʱ�ȭ
	glutCreateWindow("GLUT Modeling Test");   //���ο� window ����
	glutDisplayFunc(MyDisplay);  //MyDisplay �ݹ��Լ� ���
	glutMainLoop();
	return 0;
}