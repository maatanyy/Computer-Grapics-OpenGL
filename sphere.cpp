/*******************************************************************************/
/*                           HW#2 : 2-2  Sphere, Cylinder, Disk, PartialDisk  */
/*  작성자 : 노민성                             날짜 : 2021년 9월 24일       */
/*                                                                          */
/* 문제 정의 :                                                             */
/*         Display List를 사용한다.                                       */
/*         Solid, Wireframe 등 DrawSyle을 여러가지로 해본다.             */
/* 기능 :  Display List를 사용하여 Sphere를 구현하였습니다              */
//GLU_LINE 을 사용하였고 조명을 설정하고 Texture 좌표는 사용하지않았습니다//
//                                                                    //
//                                                                   //
/********************************************************************/
#include <GL/glut.h>

int MyListID; // DisplayList는 정수 ID에 의해 식별
// Display List 생성

GLUquadricObj* qobj = gluNewQuadric();  //새로운 Quadric 생성

void MyInit(void) {    
	//조명 설정
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);   //주변광의 세기 설정
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);    //반사광의 세기 설정
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);   //선명도 설정
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);    // 조명 설정
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);   //조명 모델 매개 변수 설정
 
	glEnable(GL_LIGHTING);  //조명 활성화
	glEnable(GL_LIGHT0);    //조명 on
	glEnable(GL_DEPTH_TEST);
}

void MyCreateList() {

	MyListID = glGenLists(1); // DisplayList 선언 (아이디 할당)
	glNewList(MyListID, GL_COMPILE);   //명령이 compile 되어짐
	gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
	gluQuadricNormals(qobj, GLU_SMOOTH); // 법선벡터 제어
	gluQuadricOrientation(qobj, GLU_OUTSIDE); // 법선벡터 내부 및 외부 등과 같은 방향 지정
	gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 사용할 것인지에 대한 여부
	gluSphere(qobj, 0.75, 50, 50); // Sphere 생성

	glEndList();  //Display List 의 끝을 표시함
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  //버퍼를 지움
	glMatrixMode(GL_MODELVIEW);  //모델뷰 변환 행렬
	glLoadIdentity();  //단위행렬로 만듬
	glEnable(GL_LIGHTING);  
	glShadeModel(GL_SMOOTH);
	glViewport(0, 0, 500, 500); //뷰포트 크기 설정
	// 컴파일이 완료된 리스트가 실제로 실행
	glCallList(MyListID);  //Display List를 실행하기 위한 함수
	glFlush();
	glutSwapBuffers();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);  //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB);   //Display 모드 설정
	glutInitWindowSize(500, 500);    //윈도우 사이즈는 500 * 500
	glutCreateWindow("GLUT Modeling Test");   //새로운 window 생성
	MyInit();   // MyInit() 호출
	glutDisplayFunc(MyDisplay);  //MyDisplay 함수 호출
	MyCreateList(); // Display List 생성
	glutMainLoop();
	return 0;
}