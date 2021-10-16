/***********************************************************************/
/*                           HW#4-1 : 로봇 손-팔 모델링             */
/*  작성자 : 노민성                             날짜 : 2021년 10월 15일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  각 손가락 당 관절은 2개 이상
    <1 키를 누르면> 첫번째 손가락을 접었다 펼쳤다 반복
    <2 키를 누르면> 두번째 손가락을 접었다 펼쳤다 반복
    <3 키를 누르면> 세번째 손가락을 접었다 펼쳤다 반복
    <4 키를 누르면> 모든 손가락이 접었다 펼쳤다 반복
    <S 키를 누르면> 움직이던 손가락이 움직임을 멈춤
    <마우스 왼쪽 버튼을 클릭하면> 어깨, 팔꿈치 및 모든 손가락을 움직여서 Robot Arm이
    특정 물건을 잡는 것처럼 회전
    <마우스 오른쪽 버튼을 클릭하면> 팔꿈치 및 모든 손가락을 움직여서 Robot Arm의 원래
    위치와 자세로 되돌아가도록 함.
*/
/* 기능 :                                                                   */
/*    WireCube를 이용하여 구현하였으며 아령운동 하듯이 구현하였습니다 */
//         각도의 경우 90도까지 가능하게 구현하였습니다              //
/*************************************************************************/
#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

float shoulder = -30, elbow = 30;  //초기 어깨와 팔꿈치 각도 조절, float형
float thirdfinger= 0, thirdfinger2 = 10, thirdfinger3 = 10, firstfinger = 40, firstfinger2 = 10, firstfinger3 = 10, secondfinger = 20, secondfinger2 = 10, secondfinger3 = 10;
//손가락 3개 마디 3개 초기 선언 및 초기화
bool first = false, second = false, third = false;  //손가락 각각의 움직임을 제어하기 위해 
int change = 1, change2 = 1, change3 = 1;  //접었다 펼쳤다 하기위해 사용할 변수입니다.
 
void MyInit(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);  //초기 윈도우 색은 검은색으로 하였습니다
    glShadeModel(GL_FLAT);
}

void MyDisplay(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();   //항등행렬 I PUSH

    glTranslatef(-3.0, 0.0, 0.0);	 // Pivot 지정 및 객체 이동
    glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동

    glPushMatrix();	// 위 TRT PUSH
    glColor3f(1.0, 1.0, 1.0);   //색을 흰색으로 하여 scale만큼 계산한 WireCube 생성
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();   //POP

 
    glTranslatef(1.0, 0.0, 0.0);	// Pivot 지정 및 객체 이동
    glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(1.0, 0.0, 0.0);	// Pivot으로 지정할 위치를 원점으로 이동

    glPushMatrix();  //위에 TRT PUSH 
    glColor3f(1.0, 1.0, 1.0);    //색을 흰색으로 하여 scale만큼 계산한 WireCube 생성
    glScalef(2.0, 0.4, 1.0);
    glutWireCube(1.0);
    glPopMatrix();   //POP
     

    glTranslatef(1.0, 0.0, 0.0);  //손가락이 시작하는 곳으로 이동하고
    glPushMatrix(); //다른 손가락의 경우에도 사용하기 위해 이곳을 PUSH해서 저장한다

    glRotatef((GLfloat)firstfinger, 0.0, 0.0, 1.0);   //첫번째 손가락이 회전할 곳 rotate로 설정해주고
    glTranslatef(0.5, 0.0, 0.0); //x축기준 0.5만큼 옮겨준다

    glPushMatrix();	      //첫번째 손가락의 첫마디를 만들어준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
 
    glTranslatef(0.5, 0.0, 0.0);	//옆으로 좀 더 이동해서 두번째 마디그리기위해 준비한다
    glRotatef((GLfloat)firstfinger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);  //옆으로 더 이동한다

    glPushMatrix();   	// 첫번째 손가락의 두번째 마디를 만들어준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);  //세번째 마디를 그리기위해 위에서 한 작업을 반복한다
    glRotatef((GLfloat)firstfinger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();	// 첫번째 손가락의 세번째 마디를 그려준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix(); //여기서 POP을 함으로서 위에서 설정했던 첫마디가 시작되는 곳으로 온다

    glPushMatrix(); //다른 손가락의 경우에도 사용하기 위해 이곳을 PUSH해서 저장한다, 62번째줄과 같은 역할이다
    glRotatef((GLfloat)secondfinger, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);  

    glPushMatrix(); 	// 두번째 손가락의 첫번째 마디를 그려준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);	// 두번째 마디를 그리기위해 이동
    glRotatef((GLfloat)secondfinger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);  // 두번째 마디를 그리기위해 이동

    glPushMatrix();	// 두번째 손가락의 두번째 마디를 그려준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);    //세번째 마디를 그리기위해 이동
    glRotatef((GLfloat)secondfinger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);  //세번째 마디를 그리기위해 이동

    glPushMatrix();	// 두번째 손가락의 세번째 마디를 그려준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glPopMatrix();  //여기서 POP함으로서 위에 TRT 행렬들이 POP되고 손가락 첫마디 시작점의 행렬이 TOP에 남게됨

    glPushMatrix(); //이 행렬을 나중에 한번 더 사용하기 위해 PUSH했으나  마지막 손가락이므로 안해도 상관없긴하다
    glRotatef((GLfloat)thirdfinger, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);

    glPushMatrix();	// 세번째 손가락의 첫마디를 그려준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0);	//두번째 마디를 그리기 위해 이동
    glRotatef((GLfloat)thirdfinger2, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);  //두번째 마디를 그리기 위해 이동

    glPushMatrix();	// 세번째 손가락의 두번째 마디를 그려준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();

    glTranslatef(0.5, 0.0, 0.0); //세번째 마디를 그리기 위해 이동
    glRotatef((GLfloat)thirdfinger3, 0.0, 0.0, 1.0); // 원점을 기준으로 회전
    glTranslatef(0.5, 0.0, 0.0);  //세번째 마디를 그리기 위해 이동

    glPushMatrix();	// 세번째 손가락의 세번째 마디를 그려준다
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0, 0.2, 0.2);
    glutWireCube(1.0);
    glPopMatrix();
 
    glPopMatrix();  //TRT 행렬이 POP됨

    glPopMatrix();  //움직였던 손가락 첫 위치를 기억하는 행렬이 POP됨
    glPopMatrix();
    glutSwapBuffers();
}

void MyReshape(int w, int h) {  //ReShape함수 
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void FirstIdle() {   //손가락 굽혔다 폈다에 사용되는 함수 Idle이용
    if (first == true) {  //만약 first 가 true 면 처음 손가락을 움직인다
        if (change == 1) {   //처음 change는 1로 위에 선언했다
            firstfinger += 0.07;  //change가 1이면 각도를 양수로 증가시키고
            firstfinger2 += 0.03;
            firstfinger3 += 0.01;
        }
        else if (change == -1) {  //만약 change가 음수면 각도를 감소시킨다
            firstfinger -= 0.07;
            firstfinger2 -= 0.03;
            firstfinger3 -= 0.01;
        }
        if (firstfinger >= 110.00000) {  //각도가 110도가 넘어가면 각도를 줄이게 change부호를 바꿔준다
            change = -1;
        }
        if (firstfinger <= 0.00000) {  //각도가 0도보다 작아지면 각도를 늘리게 change 부호를 양수로 해준다
            change = 1;
        }
    }
    if (second == true) {  //만약 second 가 true 면 두번째 손가락을 움직인다
        if (change2 == 1) {  //처음 change2는 1로 위에 선언했다
            secondfinger += 0.07;  //change2가 1이면 각도를 양수로 증가시키고
            secondfinger2 += 0.03;  //change2가 1이면 각도를 양수로 증가시키고
            secondfinger3 += 0.01;  //change2가 1이면 각도를 양수로 증가시키고
        }
        else if (change2 == -1) {  //만약 change2가 음수면 각도를 감소시킨다
            secondfinger -= 0.07;
            secondfinger2 -= 0.03;
            secondfinger3 -= 0.01;
        }
        if (secondfinger >= 110.00000) {   //각도가 110도가 넘어가면 각도를 줄이게 change2부호를 바꿔준다
            change2 = -1;
        }
        if (secondfinger <= 0.00000) {   //각도가 0도보다 작아지면 각도를 늘리게 change2 부호를 양수로 해준다
            change2 = 1;
        }
    }
    if (third == true) {  //만약 third가 true면 세번째 손가락을 움직인다
        if (change3 == 1) {   //처음 change3는 1로 위에 선언했다
            thirdfinger += 0.07;  //change3가 1이면 각도를 양수로 증가시키고
            thirdfinger2 += 0.03;  //change3가 1이면 각도를 양수로 증가시키고
            thirdfinger3 += 0.01;  //change3가 1이면 각도를 양수로 증가시키고
        }
        else if (change3 == -1) {   //만약 change3가 음수면 각도를 감소시킨다
            thirdfinger -= 0.07;
            thirdfinger2 -= 0.03;
            thirdfinger3 -= 0.01;
        }
        if (thirdfinger >= 110.00000) {  //각도가 110도가 넘어가면 각도를 줄이게 change3부호를 바꿔준다
            change3 = -1;
        }
        if (thirdfinger <= 0.00000) {  //각도가 0도보다 작아지면 각도를 늘리게 change3 부호를 양수로 해준다
            change3 = 1;
        }
    }
    glutPostRedisplay();  //바로바로 적용되게한다
}

void Idle4() {  //모든 손가락이 접었다 펴졌다 하는 함수인데 Idle을 이용했고 모든 손가락이 움직이게 하였고 각 범위만 조절하였다 상세 내용은 위의 FirstIdle과 같다
    if (change == 1) {
        firstfinger += 0.07;  
        firstfinger2 += 0.03;
        firstfinger3 += 0.01;
    }
    else if (change == -1) {
        firstfinger -= 0.07;  
        firstfinger2 -= 0.03;
        firstfinger3 -= 0.01;
    }
    if (firstfinger >= 110.00000) {
        change = -1;
    }
    if (firstfinger <= 0.00000) {
        change = 1;
    }
    if (change2 == 1) {
        secondfinger += 0.07;  
        secondfinger2 += 0.03;  
        secondfinger3 += 0.01;  
    }
    else if (change2 == -1) {
        secondfinger -= 0.07;  
        secondfinger2 -= 0.03;  
        secondfinger3 -= 0.01;  
    }
    if (secondfinger >= 110.00000) {
        change2 = -1;
    }
    if (secondfinger <= 0.00000) {
        change2 = 1;
    }
    if (change3 == 1) {
        thirdfinger += 0.07;  
        thirdfinger2 += 0.03;  
        thirdfinger3 += 0.01;  
    }
    else if (change3 == -1) {
        thirdfinger -= 0.07;  
        thirdfinger2 -= 0.03;  
        thirdfinger3 -= 0.01;  
    }
    if (thirdfinger >= 110.00000) {
        change3 = -1;
    }
    if (thirdfinger <= 0.00000) {
        change3 = 1;
    }
    glutPostRedisplay();
}

void StopIdle() {  //멈추는 Idle ,S키를 눌렀을시 사용된다
    firstfinger = firstfinger;  //firstfinger,secondfinger,thirdfinger 각각 자신이 되게하여 움직임을 멈추어주었다
    secondfinger = secondfinger;
    thirdfinger = thirdfinger;
    glutPostRedisplay();
}

void Mouseright() {  //마우스 오른쪽을 눌렀을 때 적용되는 함수
    if (shoulder >= -30.0000) {     //if문을 이용하여 모두다 초기값과 비교하여 원래로 돌아가게 해주었다
        shoulder = shoulder - 0.01;
    }
    if (elbow >= 30.0000) {
        elbow = elbow - 0.01;
    }
    if (firstfinger >= 40.0000) {
        firstfinger -= 0.07;
    }
    if (firstfinger2 >= 10.0000) {
        firstfinger2 -= 0.03;
    }
    if (firstfinger3 >= 10.0000) {
        firstfinger3 -= 0.01;
    }
    if (secondfinger >= 20.0000) {
        secondfinger -= 0.07;
    }
    if (secondfinger2 >= 10.0000) {
        secondfinger2 -= 0.03;
    }
    if (secondfinger3 >= 10.0000) {
        secondfinger3 -= 0.01;
    }
    if (thirdfinger >= 0.0000) {
        thirdfinger -= 0.07;
    }
    if (thirdfinger2 >= 10.0000) {
        thirdfinger2 -= 0.03;
    }
    if (thirdfinger3 >= 10.0000) {
        thirdfinger3 -= 0.01;
    }
    first = false;   //처음으로 돌아가고 나서는 모든 손가락의 상태를 false로 하여 움직임을 멈춘 상태로 초기화하였다
    second = false;
    third = false;
    glutPostRedisplay();  //바로 적용되게 함
}

void Mouseleft() {  //마우스 왼쪽을 눌렀을 때 적용되는 함수 
    if (shoulder <= 15.000) {  //크게 shoulder를 기준으로 잡아 shoulder를 변화시키며 다른 부분들도 움직이게 하였다
        shoulder = shoulder + 0.01;
        elbow = elbow + 0.01;
        firstfinger += 0.01;
        firstfinger2 += 0.01;
        firstfinger3 += 0.01;
        secondfinger += 0.01;
        secondfinger2 += 0.01;
        secondfinger3 += 0.01;
        thirdfinger += 0.01;
        thirdfinger2 += 0.01;
        thirdfinger3 += 0.01;
    }
    glutPostRedisplay();  //바로 적용되게 함
}

void mouseCallback(int button, int state, int x, int y) {   //마우스 콜백함수 정의
    if ((button == GLUT_RIGHT_BUTTON) && (state == GLUT_DOWN)) {  //마우스 오른쪽이 클릭되었을 때
        glutIdleFunc(Mouseright);    //Mouseright함수 호출
    }
    else if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {  //마우스 왼쪽이 클릭되었을 때
        glutIdleFunc(Mouseleft);  //Mouseleft함수 호출
    }
}

void MyKeyboard(unsigned char key, int x, int y) {  //키보드 콜백함수 정의
    switch (key) {
    case '1':  //1번 클릭시 FirstIdle 호출
        first = true;  //first를 true로 바꿔줌
        glutIdleFunc(FirstIdle);
        break;

    case '2':  //2번 클릭시 SecondIlde 호출
        second = true;  //second를 true로 바꿔줌
        glutIdleFunc(FirstIdle);
        break;

    case '3':  //3번 클릭시 ThirdIdle 호출
        third = true;  //third를 true로 바꿔줌
        glutIdleFunc(FirstIdle);
        break;

    case '4':  //4번 클릭시 Idle4 호출
        glutIdleFunc(Idle4);  //모든 손가락을 움직이게 하는데 어차피 모든 손가락을 움직이는 상황에서는 stop만 할 수 있으니 따로 true설정을 해주지는 않았다
        break;

    case 's':  //s 클릭시 StopIdle 호출
        first = false;  //모두다 false로 바꿔서 움직임을 멈추게하였고 StopIdle을 호출해서 멈추게 하였다
        second = false;
        third = false;
        glutIdleFunc(StopIdle);
        break;
    case 'S':
        first = false;  //모두다 false로 바꿔서 움직임을 멈추게하였고 StopIdle을 호출해서 멈추게 하였다
        second = false;
        third = false;
        glutIdleFunc(StopIdle);
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);  //윈도우 크기 설정
    glutInitWindowPosition(100, 100);  //윈도우시작 위치 설정
    glutCreateWindow("Robot Arm");  //윈도우만듬
    MyInit();  //초기 설정
    glutDisplayFunc(MyDisplay);  //MyDisplay함수등록
    glutReshapeFunc(MyReshape);   //MyReschape함수등록
    glutKeyboardFunc(MyKeyboard);   //MyKeyboard함수등록
    glutMouseFunc(mouseCallback);  //mouseCallback 함수 등록
    glutMainLoop();
    return 0;
}