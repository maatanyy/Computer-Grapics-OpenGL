/***********************************************************************/
/*                           HW#3-1 : keyboard callback 응용             */
/*  작성자 : 노민성                             날짜 : 2021년 9월 29일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  a 또는 A : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동
    f 또는 F : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동
    r 또는 R : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동하고,
    빨간색으로 Polygon 칠함
    v 또는 V : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동
    b 또는 B : 파란색으로 Polygon 칠함                      */
/* 기능 :                                                                   */
/*      movex, movey 와 glColor3f의 변수를 따로 설정해서 누르는 키에 알맞게 변경할수 있도록 하였습니다  */
//                       //
/*************************************************************************/
#include <GL/glut.h>

float movex = 0, movey = 0;    // x ,y 값 변경을 위한 변수 설정 처음엔 0으로 초기화
float redcolor = 0.5, greencolor = 0.5, bluecolor = 0.5;   //RGB를 제어하기 위한 변수 설정 처음엔 다 0.5로 초기화

void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);  //배경색설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();   
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  //glOrtho 설정
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(redcolor, greencolor, bluecolor);   //처음 POLYGON 색은 위에서 0.5로 설정하였기에 회색으로 됨
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + movex, -0.5 + movey, 0.0);  // POLYGON 왼쪽 아래 좌표
	glVertex3f(0.5 + movex, -0.5 + movey, 0.0);   // POLYGON 오른쪽 아래 좌표
	glVertex3f(0.5 + movex, 0.5 + movey, 0.0);    // POLYGON 오른쪽 위 좌표
	glVertex3f(-0.5 + movex, 0.5 + movey, 0.0);   // POLYGON 왼쪽 위 좌표
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {   //MyKeyboard 콜백함수 
	switch (key) {   //switch 문을 통해 케이스 나눔
	case 'a': movex = movex - 0.1;      // a 또는 A : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동
			  break;
	case 'A': movex = movex - 0.1;
			  break;

	case 'f': movex = movex + 0.1;    // f 또는 F : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동
		      break;
	case 'F': movex = movex + 0.1;
		      break;

	case 'r': movey = movey - 0.1;   //r 또는 R : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동하고 빨간색으로 Polygon 칠함
			  redcolor = 1.0;
			  greencolor = 0;
			  bluecolor = 0;
		      break;

	case 'R': movey = movey - 0.1;
		      break;
	
	case 'v': movey = movey + 0.1;   //v 또는 V : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동
		      break;
	case 'V': movey = movey + 0.1;
		      break;

	case 'b': redcolor = 0;        //b 또는 B : 파란색으로 Polygon 칠함  
		      greencolor = 0;
			  bluecolor = 1;
		break;
	case 'B': redcolor = 0;
			  greencolor = 0;
		      bluecolor = 1;
		      break;

	case 'Q': exit(0); break;   //q 또는 Q : 멈춤 
	case 'q': exit(0); break;
	}
	glutPostRedisplay();  //강제로 display event 발생 -> 위에서 바꾼 설정 적용하게 함
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);   //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB);   //RGB설정
	glutInitWindowSize(300, 300);   //윈도우 크기 300 * 300
	glutInitWindowPosition(0, 0);   //윈도우 위치 0,0
	glutCreateWindow("Keyboard Callback");   //새로운 window 생성
	MyInit();       //MyInit()함수실행
	glutDisplayFunc(MyDisplay);   //MyDisplay 콜백함수 등록
	glutKeyboardFunc(MyKeyboard);   //MyKeyboard 콜백함수 등록
	glutMainLoop();
	return 0;
}