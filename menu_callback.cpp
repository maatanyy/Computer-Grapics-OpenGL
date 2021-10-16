/***********************************************************************/
/*											HW#3-4 : Menu callback ����             */
/*  �ۼ��� : ��μ�                             ��¥ : 2021�� 10�� 1��           */
/*                                                                              */
/* ���� ���� :                                                                 */
/*  �ָ޴� : Draw Sphere, Draw Torus, Draw Teapot, Change Color, Exit
	Draw Sphere �Ϻ� �޴� : Small Sphere, Large Sphere
	Draw Torus �Ϻ� �޴� : Small Torus , Large Torus
	 Draw Teapot �Ϻ� �޴� : Small Teapot , Large Teapot
	 Change Color �Ϻ� �޴� : Red, Green, Blue              */
	/* ��� :                                                                   */
	/*      ó���� ������ ���� Sphere�� ������ �Ͽ����� ���� �޴� ���ÿ� ���� boolean��
			�̿��Ͽ� ������ ���ǿ� �°� �ٲ�� �����Ͽ����ϴ�	*/
	//                       //
	/*************************************************************************/

#include <GL/glut.h>
#include <stdio.h>
 
GLboolean IsSphere = true;   //ó���� ������ ���� sphere�� �������� boolean�� �̿��Ͽ� �����Ͽ����ϴ�
GLboolean IsSmall = true;
GLboolean IsRed = true;
GLboolean IsLarge = false;
GLboolean IsTorus = false;
GLboolean IsTeapot = false;
GLboolean IsGreen = false;
GLboolean IsBlue = false;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.5);
	 //���� ���ǿ� �°� ������ �������� �����Ͽ����ϴ�.
	// ����, ũ��, ���� ���� ������ ���������Ͽ� �� 18������ ������ �����Ͽ����ϴ�. (3 * 2 * 3 -> ����, ũ��, ��)
	if ((IsSphere) && (IsSmall) && (IsRed)) {   
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(0.2, 30, 30);
	}
	else if ((IsSphere) && (IsLarge) && (IsRed)) {
		glColor3f(1.0, 0.0, 0.0);
		glutWireSphere(0.5, 30, 30);
	}
	else if ((IsSphere) && (IsSmall) && (IsGreen)) {
		glColor3f(0.0, 1.0, 0.0);
		glutWireSphere(0.2, 30, 30);
	}
	else if ((IsSphere) && (IsLarge) && (IsGreen)) {
		glColor3f(0.0, 1.0, 0.0);
		glutWireSphere(0.5, 30, 30);
	}
	else if ((IsSphere) && (IsSmall) && (IsBlue)) {
		glColor3f(0.0, 0.0, 1.0);
		glutWireSphere(0.2, 30, 30);
	}
	else if ((IsSphere) && (IsLarge) && (IsBlue)) {
		glColor3f(0.0, 0.0, 1.0);
		glutWireSphere(0.5, 30, 30);
	}
	
	else if ((IsTorus) && (IsSmall) && (IsRed)) {
		printf("1");
		glColor3f(1.0, 0.0, 0.0);
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	else if ((IsTorus) && (IsLarge) && (IsRed)) {
		printf("2");
		glColor3f(1.0, 0.0, 0.0);
		glutWireTorus(0.2, 0.5, 40, 20);
	}
	else if ((IsTorus) && (IsSmall) && (IsGreen)) {
		glColor3f(0.0, 1.0, 0.0);
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	else if ((IsTorus) && (IsLarge) && (IsGreen)) {
		glColor3f(0.0, 1.0, 0.0);
		glutWireTorus(0.2, 0.5, 40, 20);
	}
	else if ((IsTorus) && (IsSmall) && (IsBlue)) {
		glColor3f(0.0, 0.0, 1.0);
		glutWireTorus(0.1, 0.3, 40, 20);
	}
	else if ((IsTorus) && (IsLarge) && (IsBlue)) {
		glColor3f(0.0, 0.0, 1.0);
		glutWireTorus(0.2, 0.5, 40, 20);
	}

	else if ((IsTeapot) && (IsSmall) && (IsRed)) {
		glColor3f(1.0, 0.0, 0.0);
		glutSolidTeapot(0.2);
	}
	else if ((IsTeapot) && (IsLarge) && (IsRed)) {
		glColor3f(1.0, 0.0, 0.0);
		glutSolidTeapot(0.5);
	}
	else if ((IsTeapot) && (IsSmall) && (IsGreen)) {
		glColor3f(0.0, 1.0, 0.0);
		glutSolidTeapot(0.2);
	}
	else if ((IsTeapot) && (IsLarge) && (IsGreen)) {
		glColor3f(0.0, 1.0, 0.0);
		glutSolidTeapot(0.5);
	}
	else if ((IsTeapot) && (IsSmall) && (IsBlue)) {
		glColor3f(0.0, 0.0, 1.0);
		glutSolidTeapot(0.2);
	}
	else if ((IsTeapot) && (IsLarge) && (IsBlue)) {
		glColor3f(0.0, 0.0, 1.0);
		glutSolidTeapot(0.5);
	}

	glFlush();
}

void MyMainMenu(int entryID) {   //���� �޴��� ���� �������� entryID�� 5�϶� �� exit �� �����Ͽ����� ���α׷��� ����ǵ��� �Ͽ����ϴ�
	if (entryID == 5)
		exit(0);
	glutPostRedisplay();
}

void MySphereMenu(int entryID2) {  //Sphere�� ���� ���� �޴������Դϴ�
	IsSphere = true;    //sphere�� true �� �ϰ� �������� false�� �ٲߴϴ�
	IsTorus = false; 
	IsTeapot = false;

	if (entryID2 == 1) {  //���� ���θ޴����� 1���� Ŭ���� �۰� �����մϴ�
		IsSmall = true;
		IsLarge = false;
	}
	else if (entryID2 == 2) {  //���� ���θ޴����� 2���� Ŭ���� ũ�� �����մϴ�
		IsSmall = false;
		IsLarge = true;
	}
	glutPostRedisplay();  
}void MyTorusMenu(int entryID2) {  //Torus�� ���� ���� �޴������Դϴ�
	IsSphere = false;  //torus�� true �� �ϰ� �������� false�� �ٲߴϴ�
	IsTorus = true;
	IsTeapot = false;
	if (entryID2 == 1) {  //���� ���θ޴����� 1���� Ŭ���� �۰� �����մϴ�
		IsSmall = true;
		IsLarge = false;
	}
	else if (entryID2 == 2) {  //���� ���θ޴����� 2���� Ŭ���� ũ�� �����մϴ�
		IsSmall = false;
		IsLarge = true;
	}
	glutPostRedisplay();
}void MyTeapotMenu(int entryID2) {  //Teapot�� ���� ���� �޴������Դϴ�
	IsTeapot = true;             //teapot�� true �� �ϰ� �������� false�� �ٲߴϴ�
	IsTorus = false;
	IsSphere = false;
	if (entryID2 == 1) {   //���� ���θ޴����� 1���� Ŭ���� �۰� �����մϴ�
		IsSmall = true;
		IsLarge = false;
	}
	else if (entryID2 == 2) {  //���� ���θ޴����� 2���� Ŭ���� ũ�� �����մϴ�
		IsSmall = false;
		IsLarge = true;
	}
	glutPostRedisplay();
}void MyColorMenu(int entryID3) {  //���� ���� ���� �޴������Դϴ�
	if (entryID3 == 1) {  //1�� �� ����ڰ� Red�� ���ý� Red�� True�� �������ݴϴ�
		IsRed = true;
		IsGreen = false;
		IsBlue = false;
	}
	else if (entryID3 == 2) {  //2�� �� ����ڰ� Green�� ���ý� Green�� True�� �������ݴϴ�
		IsRed = false;
		IsGreen = true;
		IsBlue = false;
	}
	else if (entryID3 == 3) {  //3�� �� ����ڰ� Blue�� ���ý� Blue�� True�� �������ݴϴ�
		IsRed = false;
		IsGreen = false;
		IsBlue = true;
	}
	glutPostRedisplay();
}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);   
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint SphereMenu = glutCreateMenu(MySphereMenu);  //Sphere�޴��� ���� �����Դϴ�
	glutAddMenuEntry("Small Sphere", 1);           //Small Sphere, Large Sphere�� �Ʒ� �޴��� �߰����ְ� ���̵�� 1,2�Դϴ�
	glutAddMenuEntry("Large Sphere", 2);

	GLint TorusMenu = glutCreateMenu(MyTorusMenu);  //Torus �޴��� ���� �����Դϴ�
	glutAddMenuEntry("Small Torus", 1);				//Small Torus, Large Torus�� �Ʒ� �޴��� �߰����ְ� ���̵�� 1,2�Դϴ�
	glutAddMenuEntry("Large Torus", 2);

	GLint TeapotMenu = glutCreateMenu(MyTeapotMenu);   //Teapot�޴��� ���� �����Դϴ�
	glutAddMenuEntry("Small Teapot", 1);               //Small Teapot, Large Teapot�� �Ʒ� �޴��� �߰����ְ� ���̵�� 1,2�Դϴ�
	glutAddMenuEntry("Large Teapot", 2);

	GLint ColorMenu = glutCreateMenu(MyColorMenu);    //���� ���� �޴������Դϴ�
	glutAddMenuEntry("Red", 1);                       //Red Green Blue �� �߰��ϰ� ���̵�� 1,2,3�Դϴ�.
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);      //MyMainMenu�� �̿��Ͽ� �޴��� ����ϴ�

	glutAddSubMenu("Draw Sphere", SphereMenu);   //������ ������ �� �Ʒ� �޴����� �߰����ݴϴ�
	glutAddSubMenu("Draw Torus", TorusMenu);
	glutAddSubMenu("Draw Teapot", TeapotMenu);
	glutAddSubMenu("Change Color", ColorMenu);
	glutAddMenuEntry("Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library �ʱ�ȭ
	glutInitDisplayMode(GLUT_RGB);  //RGB����
	glutInitWindowSize(500, 500);    //������ ũ�� 500 * 500
	glutInitWindowPosition(0, 0);   //������ ��ġ 0,0
	glutCreateWindow("Menu Callback");  //���ο� window ����
	MyInit();
	glutDisplayFunc(MyDisplay);   //MyDisplay �ݹ��Լ� ���
	glutMainLoop();
	return 0;
}