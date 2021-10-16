/***********************************************************************/
/*                           HW#3-2 : keyboard callback 응용2             */
/*  작성자 : 노민성                             날짜 : 2021년 9월 29일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  ↑ : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동
	↓ : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동
	← : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동
	→ : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동
	PageUp : 4개의 vertex 좌표로 이루어진 Polygon이 각 방향으로 0.1씩
	연속적으로 확대(Zoom In)
	PageDown : 4개의 vertex 좌표로 이루어진 Polygon이 각 방향으로 0.1씩
	연속적으로 축소(Zoom Out)
               */
	/* 기능 :                                                                   */
	/*      left,right,up,down을 설정하여 각 키에 맞게 움직일수 있도록 하였습니다.
			그리고 조건문을 통해 벽을 넘어가지 않도록 하였습니다. 
			                                                                  */
	//                       //
	/*************************************************************************/
#include <GL/glut.h>

GLdouble left = 0.0, right = 0.0, up = 0.0, down = 0.0, count = 5;    // x ,y 값 변경을 위한 변수 설정 처음엔 0으로 초기화,
//최소로 줄어들면 사라지는것을 방지하기 위해 count 추가


void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);  //배경색설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);  //glOrtho 설정
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);  //POLYGON 색 설정
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 + left, -0.5 + down, 0.0);  // POLYGON 왼쪽 아래 좌표
	glVertex3f(0.5 + right, -0.5 + down, 0.0);   // POLYGON 오른쪽 아래 좌표
	glVertex3f(0.5 + right, 0.5 + up, 0.0);    // POLYGON 오른쪽 위 좌표
	glVertex3f(-0.5 + left, 0.5 + up, 0.0);   // POLYGON 왼쪽 위 좌표
	glEnd();
	glFlush();
}

void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q': exit(0); break;   //q 또는 Q : 멈춤 
	case 'q': exit(0); break;
	case 27: exit(0); break;
	}
	glutPostRedisplay();   //강제로 display event 발생 -> 위에서 바꾼 설정 적용하게 함
}

void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:    // ← : 4개의 vertex 좌표가 동일하게 왼쪽으로 0.1씩 이동
		if (left > -0.5) {     
			left = left - 0.1;     //left ,right 를 각각 0.1씩 줄였습니다
			right = right - 0.1;
		}
		break;
	
	case GLUT_KEY_UP:   // ↑ : 4개의 vertex 좌표가 동일하게 위쪽으로 0.1씩 이동
		if (up < 0.5) {
			up = up + 0.1;    //up, down을 각각 0.1씩 올렸습니다
			down = down + 0.1;
		}
		break;

	case GLUT_KEY_DOWN:   //  ↓ : 4개의 vertex 좌표가 동일하게 아래쪽으로 0.1씩 이동
		if (down > -0.5) {
			down = down - 0.1;   //up,down을 각각 0.1씩 줄였습니다
			up = up - 0.1;
		}
		break;

	case GLUT_KEY_RIGHT: //  → : 4개의 vertex 좌표가 동일하게 오른쪽으로 0.1씩 이동
		if (right < 0.5) {
			right = right + 0.1;  //right, left 를 각각 0.1씩 올렸습니다
			left = left + 0.1;
		}
		break;

	case GLUT_KEY_PAGE_UP:  //  PageUp : 4개의 vertex 좌표로 이루어진 Polygon이 각 방향으로 0.1씩 	연속적으로 확대(Zoom In)
		if ((right < 0.5) && (up < 0.5) && (down > -0.5) && (left > -0.5)) {
			count = count + 1;  //확대하면 카운트 1증가
			right = right + 0.1; //right,up은 0.1씩 올리고 left,down 은 0.1씩 줄였습니다
			up = up + 0.1;
			left = left - 0.1;
			down = down - 0.1;
		}
		break;
	
	case GLUT_KEY_PAGE_DOWN:  //PageDown : 4개의 vertex 좌표로 이루어진 Polygon이 각 방향으로 0.1씩 연속적으로 축소(Zoom Out)
		if (count==0) {  //최소로 줄어든 경우 더이상 안줄어들게 함
			right = right;
			up = up;
			left = left;
			down = down;
			break;
		}

		else if ((right <= 0.5) && (up <= 0.5) && (down >= -0.5) && (left >= -0.5)) {  //부등호를 추가하여 한쪽이 벽에 붙은경우는 줄어들수 있게하였습니다.
			count = count - 1;   //축소하면 카운트를 하나 줄임
			right = right - 0.1;  //right up은 0.1씩 줄이고 left, down은 0.1씩 올렸습니다
			up = up - 0.1;
			left = left + 0.1;
			down = down + 0.1;
		}
		break;
			

	default:
		break;
	}
	glutPostRedisplay();  //강제로 display event 발생 -> 위에서 바꾼 설정 적용하게 함
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);  //GLUT library 초기화
	glutInitDisplayMode(GLUT_RGB);  //RGB설정
	glutInitWindowSize(300, 300);  //윈도우 크기 300 * 300
	glutInitWindowPosition(0, 0);  //윈도우 위치 0,0
	glutCreateWindow("Keyboard Callback");  //새로운 window 생성
	MyInit();   //MyInit()함수실행
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);  //MySpecial 함수 등록
	glutMainLoop();
	return 0;
}
