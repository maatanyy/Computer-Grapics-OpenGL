/***********************************************************************/
/*                           HW#1 : 3D Sierpinski Gasket                      */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 9�� 19��       */
/*                                                                          */
/* ���� ���� :                                                             */
/*    2D triangle Gasket�� �Ʒ��� ���� 3D tetrahedron Gasket���� ����     */
/*                Reshape Callback�� ����Ͽ� �ְ�� �ذ�              */ 
/* ��� :                                                               */
/*                2D triangle Gasket�� �Ʒ��� ���� 3D tetrahedron Gasket���� ����  
  Reshape Callback �� ����Ͽ� �������� ũ�⸦ �ٲ㵵 �ְ��� �Ȼ��⵵�� ��*/
//    https://slideplayer.com/slide/13772155/85/images/39/3D+Sierpinski+Gasket+Program.jpg�� �����Ͽ� ��ǥ�� �����Ͽ���   //
//     reshape �� ������ �κе��� �����ڷ�� ���� �������� �����Ͽ� �ۼ��Ͽ����ϴ�    //
/***********************************************************************/

#include <GL/glut.h>

void MyDisplay() {
	float vertices[4][3] = { {0.0, 0.0, 0.0}, {250.0, 500.0, 100.0},{500.0, 250.0, 250.0}, {250.0, 100.0, 250.0} };   //vertices[4][3] ����, ������ �������� ��
	float p[3] = { 250.0,50.0,250.0}; //   ���� ����Ʈ, ó�� ������ ���ο� ������ �� �ϳ��� ����
	int i, j;
	glClear(GL_COLOR_BUFFER_BIT);
	for (j = 0; j <100000; j++) {     //10���� �ݺ��ϸ� ���ο� ��� 
		i = rand() % 4;   //������ �� ����
		p[0] = (p[0] + vertices[i][0]) / 2.0;  // ���� ���õ� ���� ���� ���� �������� ���ο� �� ��ġ ���
		p[1] = (p[1] + vertices[i][1]) / 2.0;  // ���� ���õ� ���� ���� ���� �������� ���ο� �� ��ġ ���
		p[2] = (p[2] + vertices[i][2]) / 2.0;  // ���� ���õ� ���� ���� ���� �������� ���ο� �� ��ġ ���
		glBegin(GL_POINTS);
		glVertex3fv(p);  //���� ��ġ�� �� ���
		glEnd();
	}
	glFlush();
}

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);   //��� ������� ����
	glColor3f(1.0, 0.0, 0.0);    //�׸� ���������� ����
	glMatrixMode(GL_PROJECTION);  //���� ������ ���� ��� �������� �ٲ��ֱ� ���� ���
	glLoadIdentity();
	glOrtho(0.0, 500.0, 0.0, 500.0, 500, -500); //���� ����  [0, 500] �� [0,500] �� [500,-500]
}

void MyReshape(int NewWidth, int NewHeight) {  //������ ũ�⸦ �������� �� ȣ�� 
	glViewport(0, 0, NewWidth, NewHeight);  //viewport �� ���ο� NewWidth �� NewHeight ����
	GLfloat Widthfactor = (GLfloat)NewWidth / (GLfloat)500;  //Widthfactor ���, ���� �������� ũ�Ⱑ 500�̾����Ƿ� 500���� ����
	GLfloat Heightfactor = (GLfloat)NewHeight / (GLfloat)500;  //Heightfactor ���, ���� �������� ũ�Ⱑ 500�̾����Ƿ� 500���� ����
	glMatrixMode(GL_PROJECTION);  //������� �������� ����
	glLoadIdentity();
	glOrtho(0.0 * Widthfactor, 500.0 * Widthfactor, 0.0 *  //������ ����� Widthfactor, Heightfactor ���� ��ŭ ���ú��Ǹ� �ٲ���
		Heightfactor, 500.0 * Heightfactor, 500.0, -500.0);
}

void main(int argc, char** argv)  //���� �Լ�
{
	glutInit(&argc, argv);  //GLUT library �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB);  //Display ��� ����
	glutInitWindowSize(500, 500);  //������ ������� 500 * 500
	glutInitWindowPosition(0, 0);   //������ ������ǥ 0,0���� ����
	glutCreateWindow("Sierpinski Gasket"); //���ο� window ����
	glutDisplayFunc(MyDisplay);  //MyDisplay �ݹ��Լ� ���
	glutReshapeFunc(MyReshape); //MyReshape �Լ� ���
	MyInit();  // MyInit() ȣ��
	glutMainLoop();
}
