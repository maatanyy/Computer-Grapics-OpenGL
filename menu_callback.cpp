/***********************************************************************/
/*											HW#3-4 : Menu callback 응용             */
/*  작성자 : 노민성                             날짜 : 2021년 10월 1일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  주메뉴 : Draw Sphere, Draw Torus, Draw Teapot, Change Color, Exit
	Draw Sphere 하부 메뉴 : Small Sphere, Large Sphere
	Draw Torus 하부 메뉴 : Small Torus , Large Torus
	 Draw Teapot 하부 메뉴 : Small Teapot , Large Teapot
	 Change Color 하부 메뉴 : Red, Green, Blue              */
	/* 기능 :                                                                   */
	/*      처음엔 빨간색 작은 Sphere가 나오게 하였으며 각종 메뉴 선택에 따라 boolean을
			이용하여 선택한 조건에 맞게 바뀌도록 설정하였습니다	*/
	//                       //
	/*************************************************************************/

#include <GL/glut.h>
#include <stdio.h>
 
GLboolean IsSphere = true;   //처음에 빨간색 작은 sphere가 나오도록 boolean을 이용하여 설정하였습니다
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
	 //각종 조건에 맞게 도형이 나오도록 설정하였습니다.
	// 도형, 크기, 색에 따라 도형이 나오도록하여 종 18종류의 도형을 설정하였습니다. (3 * 2 * 3 -> 종류, 크기, 색)
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

void MyMainMenu(int entryID) {   //메인 메뉴에 관한 설정으로 entryID가 5일때 즉 exit 를 선택하였을때 프로그램이 종료되도록 하였습니다
	if (entryID == 5)
		exit(0);
	glutPostRedisplay();
}

void MySphereMenu(int entryID2) {  //Sphere에 관한 세부 메뉴설정입니다
	IsSphere = true;    //sphere만 true 로 하고 나머지는 false로 바꿉니다
	IsTorus = false; 
	IsTeapot = false;

	if (entryID2 == 1) {  //만약 세부메뉴에서 1번을 클릭시 작게 설정합니다
		IsSmall = true;
		IsLarge = false;
	}
	else if (entryID2 == 2) {  //만약 세부메뉴에서 2번을 클릭시 크게 설정합니다
		IsSmall = false;
		IsLarge = true;
	}
	glutPostRedisplay();  
}void MyTorusMenu(int entryID2) {  //Torus에 관한 세부 메뉴설정입니다
	IsSphere = false;  //torus만 true 로 하고 나머지는 false로 바꿉니다
	IsTorus = true;
	IsTeapot = false;
	if (entryID2 == 1) {  //만약 세부메뉴에서 1번을 클릭시 작게 설정합니다
		IsSmall = true;
		IsLarge = false;
	}
	else if (entryID2 == 2) {  //만약 세부메뉴에서 2번을 클릭시 크게 설정합니다
		IsSmall = false;
		IsLarge = true;
	}
	glutPostRedisplay();
}void MyTeapotMenu(int entryID2) {  //Teapot에 관한 세부 메뉴설정입니다
	IsTeapot = true;             //teapot만 true 로 하고 나머지는 false로 바꿉니다
	IsTorus = false;
	IsSphere = false;
	if (entryID2 == 1) {   //만약 세부메뉴에서 1번을 클릭시 작게 설정합니다
		IsSmall = true;
		IsLarge = false;
	}
	else if (entryID2 == 2) {  //만약 세부메뉴에서 2번을 클릭시 크게 설정합니다
		IsSmall = false;
		IsLarge = true;
	}
	glutPostRedisplay();
}void MyColorMenu(int entryID3) {  //색에 관한 세부 메뉴설정입니다
	if (entryID3 == 1) {  //1번 즉 사용자가 Red를 선택시 Red만 True로 설정해줍니다
		IsRed = true;
		IsGreen = false;
		IsBlue = false;
	}
	else if (entryID3 == 2) {  //2번 즉 사용자가 Green를 선택시 Green만 True로 설정해줍니다
		IsRed = false;
		IsGreen = true;
		IsBlue = false;
	}
	else if (entryID3 == 3) {  //3번 즉 사용자가 Blue를 선택시 Blue만 True로 설정해줍니다
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

	GLint SphereMenu = glutCreateMenu(MySphereMenu);  //Sphere메뉴에 관한 설정입니다
	glutAddMenuEntry("Small Sphere", 1);           //Small Sphere, Large Sphere를 아래 메뉴로 추가해주고 아이디는 1,2입니다
	glutAddMenuEntry("Large Sphere", 2);

	GLint TorusMenu = glutCreateMenu(MyTorusMenu);  //Torus 메뉴에 관한 설정입니다
	glutAddMenuEntry("Small Torus", 1);				//Small Torus, Large Torus를 아래 메뉴로 추가해주고 아이디는 1,2입니다
	glutAddMenuEntry("Large Torus", 2);

	GLint TeapotMenu = glutCreateMenu(MyTeapotMenu);   //Teapot메뉴에 관한 설정입니다
	glutAddMenuEntry("Small Teapot", 1);               //Small Teapot, Large Teapot를 아래 메뉴로 추가해주고 아이디는 1,2입니다
	glutAddMenuEntry("Large Teapot", 2);

	GLint ColorMenu = glutCreateMenu(MyColorMenu);    //색에 관한 메뉴설정입니다
	glutAddMenuEntry("Red", 1);                       //Red Green Blue 를 추가하고 아이디는 1,2,3입니다.
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("Blue", 3);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);      //MyMainMenu를 이용하여 메뉴를 만듭니다

	glutAddSubMenu("Draw Sphere", SphereMenu);   //위에서 설정한 각 아래 메뉴들을 추가해줍니다
	glutAddSubMenu("Draw Torus", TorusMenu);
	glutAddSubMenu("Draw Teapot", TeapotMenu);
	glutAddSubMenu("Change Color", ColorMenu);
	glutAddMenuEntry("Exit", 5);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB);  //RGB설정
	glutInitWindowSize(500, 500);    //윈도우 크기 500 * 500
	glutInitWindowPosition(0, 0);   //윈도우 위치 0,0
	glutCreateWindow("Menu Callback");  //새로운 window 생성
	MyInit();
	glutDisplayFunc(MyDisplay);   //MyDisplay 콜백함수 등록
	glutMainLoop();
	return 0;
}