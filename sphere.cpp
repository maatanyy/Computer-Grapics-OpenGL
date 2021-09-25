/*******************************************************************************/
/*                           HW#2 : 2-2  Sphere, Cylinder, Disk, PartialDisk  */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 9�� 24��       */
/*                                                                          */
/* ���� ���� :                                                             */
/*         Display List�� ����Ѵ�.                                       */
/*         Solid, Wireframe �� DrawSyle�� ���������� �غ���.             */
/* ��� :  Display List�� ����Ͽ� Sphere�� �����Ͽ����ϴ�              */
//GLU_LINE �� ����Ͽ��� ������ �����ϰ� Texture ��ǥ�� ��������ʾҽ��ϴ�//
//                                                                    //
//                                                                   //
/********************************************************************/
#include <GL/glut.h>

int MyListID; // DisplayList�� ���� ID�� ���� �ĺ�
// Display List ����

GLUquadricObj* qobj = gluNewQuadric();  //���ο� Quadric ����

void MyInit(void) {    
	//���� ����
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);   //�ֺ����� ���� ����
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);    //�ݻ籤�� ���� ����
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);   //���� ����
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);    // ���� ����
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);   //���� �� �Ű� ���� ����
 
	glEnable(GL_LIGHTING);  //���� Ȱ��ȭ
	glEnable(GL_LIGHT0);    //���� on
	glEnable(GL_DEPTH_TEST);
}

void MyCreateList() {

	MyListID = glGenLists(1); // DisplayList ���� (���̵� �Ҵ�)
	glNewList(MyListID, GL_COMPILE);   //����� compile �Ǿ���
	gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric�� ���� ���ϴ� Draw Style ���� -> GLU_LINE ���� �����Ͽ� wire-frame ���·� �𵨸���
	gluQuadricNormals(qobj, GLU_SMOOTH); // �������� ����
	gluQuadricOrientation(qobj, GLU_OUTSIDE); // �������� ���� �� �ܺ� ��� ���� ���� ����
	gluQuadricTexture(qobj, GL_FALSE); // Texture ��ǥ ����� �������� ���� ����
	gluSphere(qobj, 0.75, 50, 50); // Sphere ����

	glEndList();  //Display List �� ���� ǥ����
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //���۸� ����
	glMatrixMode(GL_MODELVIEW);  //�𵨺� ��ȯ ���
	glLoadIdentity();  //������ķ� ����
	glEnable(GL_LIGHTING);  
	glShadeModel(GL_SMOOTH);
	glViewport(0, 0, 500, 500); //����Ʈ ũ�� ����
	// �������� �Ϸ�� ����Ʈ�� ������ ����
	glCallList(MyListID);  //Display List�� �����ϱ� ���� �Լ�
	glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);  //GLUT library �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB);   //Display ��� ����
	glutInitWindowSize(500, 500);    //������ ������� 500 * 500
	glutCreateWindow("GLUT Modeling Test");   //���ο� window ����
	MyInit();   // MyInit() ȣ��
	glutDisplayFunc(MyDisplay);  //MyDisplay �Լ� ȣ��
	MyCreateList(); // Display List ����
	glutMainLoop();
	return 0;
}