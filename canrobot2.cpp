/***********************************************************************/
/*                           HW#7 : 전신 Can RoBot 달리기 및 조명 구현           */
/*  작성자 : 노민성                             날짜 : 2021년 11월 19일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*  실습과제4에서 계층적 모델링을 통해 구현한 <전신캔로봇>을 다음과 같은 기능이 수행되도록 추가 구현하시오.
• <R 또는 r 키를 누르면> 양팔과 양다리를 적절히 움직여 달리는 모습이 되게하시오.
• 로봇에 조명을 입히시오.
*/
/* 기능 :                                                                   */
/*    타이머를 이용하여 오른발-왼손, 왼발-오른손을 짝을 맞추어 달리는 모습 처럼 구현하였고
달릴 때 몸통도 움직이게하여 실제 달리는 모습과 유사하게 구현하려고 하였습니다
조명의 경우 전역광 하나와 각 도형에서의 설정을 통해 구현하였습니다 //
/*************************************************************************/

#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>

float body = 0, rightarm = 0, rightarm2 = 0, leftarm = 0, leftarm2 = 0, rightleg = 0, rightleg2 = 0, leftleg = 0, leftleg2 = 0, neck = 0, eye = 0, head = 0;
float rightarmsub1 = 0, rightarmsub2 = 0, leftarmsub1 = 0, leftarmsub2 = 0, rightlegsub1 = 0, rightlegsub2 = 0, leftlegsub1 = 0, leftlegsub2 = 0;
float body1 = 0, body2 = 0;
//각 rotate에서 이동에 사용할 변수이고 0으로 초기화 및 선언하였습니다
int neckchange = 1, rightarmchange = 1, leftarmchange = 1, rightlegchange = 1, leftlegchange = 1;
//이동하며 최대 범위 도달후 방향 전환을 하기 위해 선언한 변수입니다 처음엔 1로 설정하였습니다
bool stop_1 = false, stop_2 = false, stop_3 = false, stop_4 = false, stop_5 = false, stop_7 = false;  //이 bool이 true 이면 멈춥니다, flase일 경우 움직이게 합니다


//조명에 이용할 각 색에 대한 설정 
const GLfloat red[] = { 255, 0.0, 0.0, 1.0 };
const GLfloat purple[] = { 1.0, 0.0, 1.0, 1.0 };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat yellow[] = {255.0, 255.0, 0.0};
const GLfloat green[] = {0 ,1 ,0};
const GLfloat sky[] = {0, 204,204};
const GLfloat polished[] = { 100.0 };
const GLfloat dull[] = { 0.0 };
const GLfloat light_pos[] = { -3.0, 1000.0, 7.0, 1.0 };  //조명위치에 대한 설정 

GLUquadricObj* qobj = gluNewQuadric();  //새로운 Quadric 생성

//사용할 함수 선언, 
void Timer6(int value);
void Stop1(int value);
void Stop2(int value);
void Stop3(int value);
void Stop4(int value);
void Stop5(int value);
void Stop7(int value);

void Timer1(int value) {   //머리움직임에 관련된 타이머 입니다
    if (stop_1 == true) {  //만약  bool의 값이 true 일 경우 멈춥니다
        neck = neck;
        eye = eye;
        head = head;
    }
    else {  //bool의 값이 false 일 경우, 움직입니다
        if (neckchange == 1) {   //change가 1일경우는 오른쪽으로 움직입니다
            neck = neck + 0.5;
            eye = eye + 0.2;
            head = head + 0.2;
        }
        else if (neckchange == -1) {  //만약 change가 음수면 왼쪽으로 움직입니다
            neck = neck - 0.5;
            eye = eye - 0.2;
            head = head - 0.2;
        }
        if (neck >= 20.00000) {  //이동범위를 넘어가면 change의 부호를 바꿔줍니다
            neckchange = -1;
        }
        if (neck <= 0.00000) {  //처음상태로 돌아오면 멈추는 함수를 호출합니다
            neckchange = 1;
            glutTimerFunc(40, Stop1, 1);
        }
        glutPostRedisplay();   //계속 변화를적용하며 다시 타이머를 호출합니다
        glutTimerFunc(20, Timer1, 1);
    }
}

void Timer2(int value) {     //오른팔 움직임에 관한 타이머입니다. 
    if (stop_2 == true) {    //만약  bool의 값이 true 일 경우 멈춥니다
        rightarm = rightarm;
        rightarm2 = rightarm2;
    }
    else {   //bool의 값이 false 일 경우, 움직입니다
        if (rightarmchange == 1) {     //change가 1일 경우 오른쪽으로 움직입니다
            rightarm = rightarm - 0.7;
            rightarm2 = rightarm2 - 0.3;
        }
        else if (rightarmchange == -1) {  //만약 change가 --1이면 왼쪽으로 움직입니다
            rightarm = rightarm + 0.7;
            rightarm2 = rightarm2 + 0.3;
        }
        if (rightarm >= 0.00000) {   //처음상태로 돌아오면 멈추는 함수를 호출합니다
            rightarmchange = 1;
            glutTimerFunc(40, Stop2, 1);
        }
        if (rightarm <= -20.00000) {   //지정 이동범위에 도달하면 이동방향을 바꿔줍니다
            rightarmchange = -1;
        }
        glutPostRedisplay();   //계속 변화를적용하며 다시 타이머를 호출합니다
        glutTimerFunc(20, Timer2, 1);
    }
}

void Timer3(int value) {  //왼팔 움직임에 관한 타이머입니다
    if (stop_3 == true) {   //만약  bool의 값이 true 일 경우 멈춥니다
        leftarm = leftarm;
        leftarm2 = leftarm2;
    }
    else {   //bool의 값이 false 일 경우, 움직입니다
        if (leftarmchange == 1) {   //처음엔 왼쪽으로 움직입니다
            leftarm = leftarm + 0.7;
            leftarm2 = leftarm2 + 0.3;
        }
        else if (leftarmchange == -1) {  //만약 change가 -1이면 오른쪽으로 움직입니다
            leftarm = leftarm - 0.7;
            leftarm2 = leftarm2 - 0.3;
        }
        if (leftarm >= 20.00000) {  //각도가 이동범위를 넘어가면 이동방향을 바꿔줍니다
            leftarmchange = -1;
        }
        if (leftarm <= 0.00000) {  //처음상태로 돌아오면 stop을 호출해줍니다
            leftarmchange = 1;
            glutTimerFunc(40, Stop3, 1);
        }
        glutPostRedisplay();   //이동을 바로 적용하고 타이머를 호출합니다
        glutTimerFunc(20, Timer3, 1);
    }
}

void Timer4(int value) {  //오른쪽 다리 움직임에 관한 타이머입니다
    if (stop_4 == true) {    //만약  bool의 값이 true 일 경우 멈춥니다
        rightleg = rightleg;
        rightleg2 = rightleg2;
    }
    else {   //bool의 값이 false 일 경우, 움직입니다
        if (rightlegchange == 1) {   //change가 1일 경우 오른쪽으로 움직입니다
            rightleg = rightleg - 0.5;
            rightleg2 = rightleg2 + 0.3;
        }
        else if (rightlegchange == -1) {  //change가 -1일경우 왼쪽으로 움직입니다
            rightleg = rightleg + 0.5;
            rightleg2 = rightleg2 - 0.3;
        }
        if (rightleg > 0.00000) {  //처음으로 돌아오면 멈추는 함수를 호출합니다
            rightlegchange = 1;
            glutTimerFunc(40, Stop4, 1);
        }
        if (rightleg <= -30.00000) {  //지정범위를 벗어나면 이동방향을 바꿔줍니다
            rightlegchange = -1;
        }
        glutPostRedisplay();  //바로 적용하게하고 타이머를 다시 호출합니다
        glutTimerFunc(20, Timer4, 1);
    }
}

void Timer5(int value) {  //왼쪽 다리 움직임에 관한 타이머입니다
    if (stop_5 == true) {   //만약  bool의 값이 true 일 경우 멈춥니다
        leftleg = leftleg;
        leftleg2 = leftleg2;
    }
    else {    //bool의 값이 false 일 경우, 움직입니다
        if (leftlegchange == 1) {   //change 가 1일경우 왼쪽으로 움직입니다
            leftleg = leftleg + 0.5;
            leftleg2 = leftleg2 - 0.3;
        }
        else if (leftlegchange == -1) {  //만약 change가 -1이면 오른쪽으로 움직입니다
            leftleg = leftleg - 0.5;
            leftleg2 = leftleg2 + 0.3;
        }
        if (leftleg >= 30.00000) {  //각도가 지정범위를 벗어나면 이동방향을 바꿔줍니다
            leftlegchange = -1;
        }
        if (leftleg <= 0.00000) {  //처음상태로 돌아오면 멈춰줍니다
            leftlegchange = 1;
            glutTimerFunc(40, Stop5, 1);
        }
        glutPostRedisplay();  //바로 적용시켜주고 타이머를 호출해줍니다
        glutTimerFunc(40, Timer5, 1);
    }
}

void Timer7(int value) {  //달리기에 관한 티어미 입니다
    if (stop_7 == true) {   //만약  bool의 값이 true 일 경우 멈춥니다
        leftleg = leftleg;
        leftleg2 = leftleg2;
        rightleg = rightleg;
        rightleg2 = rightleg2;
        leftarm = leftarm;
        leftarm2 = leftarm2;
        rightarm = rightarm;
        rightarm2 = rightarm2;
    }

    else {    //bool의 값이 false 일 경우, 움직입니다
        if (rightarmchange == 1) {     //change가 1일 경우 오른쪽으로 움직입니다
            rightarm = rightarm - 1.2;
            rightarm2 = rightarm2 - 0.3;
            rightarmsub1 = rightarmsub1 +0.2;
            rightarmsub2 = rightarmsub2- 0.05;
            body2 = body2 + 0.005;
        }
        else if (rightarmchange == -1) {  //만약 change가 --1이면 왼쪽으로 움직입니다
            rightarm = rightarm + 1.2;
            rightarm2 = rightarm2 + 0.3;
            rightarmsub1 = rightarmsub1 - 0.2;
           rightarmsub2 = rightarmsub2 + 0.05;
           body2 = body2 - 0.005;
        }
        if (rightarm >= 20.00000) {   //처음상태로 돌아오면 멈추는 함수를 호출합니다
            rightarmchange = 1;
            glutTimerFunc(20, Stop2, 1);
        }
        if (rightarm <= -20.00000) {   //지정 이동범위에 도달하면 이동방향을 바꿔줍니다
            rightarmchange = -1;
        }

        if (leftarmchange == 1) {   //처음엔 왼쪽으로 움직입니다
            leftarm = leftarm + 1.2;
            leftarm2 = leftarm2 + 0.3;
            leftarmsub1 = leftarmsub1 +0.2;
            leftarmsub2 = leftarmsub2 - 0.05;
        }
        else if (leftarmchange == -1) {  //만약 change가 -1이면 오른쪽으로 움직입니다
            leftarm = leftarm - 1.2;
            leftarm2 = leftarm2 - 0.3;
            leftarmsub1 = leftarmsub1 - 0.2;
           leftarmsub2 = leftarmsub2 - 0.05;
        }
        if (leftarm >= 20.00000) {  //각도가 이동범위를 넘어가면 이동방향을 바꿔줍니다
            leftarmchange = -1;
        }
        if (leftarm <= -20.00000) {  //처음상태로 돌아오면 stop을 호출해줍니다
            leftarmchange = 1;
            glutTimerFunc(20, Stop3, 1);
        }

        if (rightlegchange == 1) {   //change가 1일 경우 오른쪽으로 움직입니다
            rightleg = rightleg + 1.2;
            rightleg2 = rightleg2 + 0.3;
            rightlegsub1 = rightlegsub1 + 0.6;
            rightlegsub2 = rightlegsub2 - 0.2;
        }
        else if (rightlegchange == -1) {  //change가 -1일경우 왼쪽으로 움직입니다
            rightleg = rightleg  -1.2;     //-1.2
            rightleg2 = rightleg2 - 0.3;     //-0.3
            rightlegsub1 = rightlegsub1 + 0.6;
            rightlegsub2 = rightlegsub2 - 0.2;
        }
        if (rightleg >= 20.00000) {  //처음으로 돌아오면 멈추는 함수를 호출합니다
            rightlegchange = -1;
        }
        if (rightleg <= -20.00000) {  //지정범위를 벗어나면 이동방향을 바꿔줍니다
            rightlegchange = 1;
            glutTimerFunc(20, Stop4, 1);
        }

        if (leftlegchange == 1) {   //change 가 1일경우 왼쪽으로 움직입니다
            leftleg = leftleg - 1.2;
            leftleg2 = leftleg2 - 0.3;
            leftlegsub1 = leftlegsub1 + 0.6;
            leftlegsub2 = leftlegsub2 - 0.2;
        }

        else if (leftlegchange == -1) {  //만약 change가 -1이면 오른쪽으로 움직입니다
            leftleg = leftleg +1.2;
            leftleg2 = leftleg2 + 0.3;
            leftlegsub1 = leftlegsub1 + 0.6;
            leftlegsub2 = leftlegsub2 - 0.2;
        }
        if (leftleg >= 20.00000) {  //각도가 지정범위를 벗어나면 이동방향을 바꿔줍니다
            leftlegchange = 1;
            glutTimerFunc(20, Stop5, 1);
        }
        if (leftleg <= -20.00000) {  //처음상태로 돌아오면 멈춰줍니다
            leftlegchange = -1;
        }


        glutPostRedisplay();   //계속 변화를적용하며 다시 타이머를 호출합니다
        glutTimerFunc(10, Timer7, 1);
    }
}
void Stop1(int value) {  //머리움직이는걸 멈추는 함수입니다
    stop_1 = true;  //stop_1을 true로 해주고 적용시키고 타이머를 호출합니다
    glutPostRedisplay();
    glutTimerFunc(20, Timer1, 1);
}
void Stop2(int value) { //오른팔이 움직이는걸 멈추는 함수입니다
    stop_2 = true;   //stop_2을 true로 해주고 적용시키고 타이머를 호출합니다
    glutPostRedisplay();
    glutTimerFunc(20, Timer2, 1);
}
void Stop3(int value) { //왼쪽팔이 움직이는걸 멈추는 함수입니다
    stop_3 = true;   //stop_3을 true로 해주고 적용시키고 타이머를 호출합니다
    glutPostRedisplay();
    glutTimerFunc(20, Timer3, 1);
}
void Stop4(int value) { //오른쪽 다리가 움직이는걸 멈추는 함수입니다
    stop_4 = true;   //stop_4을 true로 해주고 적용시키고 타이머를 호출합니다
    glutPostRedisplay();
    glutTimerFunc(20, Timer4, 1);
}
void Stop5(int value) { //왼쪽 다리가 움직이는걸 멈추는 함수입니다
    stop_5 = true;  //stop_5을 true로 해주고 적용시키고 타이머를 호출합니다
    glutPostRedisplay();
    glutTimerFunc(20, Timer5, 1);
}

void Stop7(int value) { //왼쪽 다리가 움직이는걸 멈추는 함수입니다
    stop_7 = false;  //stop_7을 true로 해주고 적용시키고 타이머를 호출합니다
    glutPostRedisplay();
    glutTimerFunc(40, Timer7, 1);
}

void Timer6(int value) {   //모두다 멈추는 timer입니다 모든 stop_을 true로 한 후 모든 타이머를 호출합니다
    stop_1 = true;
    stop_2 = true;
    stop_3 = true;
    stop_4 = true;
    stop_5 = true;
    stop_7 = true;
    glutPostRedisplay();
    glutTimerFunc(20, Timer1, 1);
    glutTimerFunc(20, Timer2, 1);
    glutTimerFunc(20, Timer3, 1);
    glutTimerFunc(20, Timer4, 1);
    glutTimerFunc(20, Timer5, 1);
}

void MyMainMenu(int entryID) {  //메뉴등록에 관한 함수입니다
    if (entryID == 1) {  //머리 움직이기
        stop_1 = false;   //bool false로 바꿔줘서 움직이게함
        glutTimerFunc(20, Timer1, 1);
    }
    else if (entryID == 2) {  //오른팔 움직이기
        stop_2 = false; //bool false로 바꿔줘서 움직이게함
        glutTimerFunc(20, Timer2, 1);
    }
    else if (entryID == 3) {  //왼쪽팔 움직이기
        stop_3 = false; //bool false로 바꿔줘서 움직이게함
        glutTimerFunc(20, Timer3, 1);
    }
    else if (entryID == 4) {  //오른다리 움직이기
        stop_4 = false; //bool false로 바꿔줘서 움직이게함
        glutTimerFunc(20, Timer4, 1);
    }
    else if (entryID == 5) {  //왼쪽다리 움직이기
        stop_5 = false; //bool false로 바꿔줘서 움직이게함
        glutTimerFunc(20, Timer5, 1);
    }
    glutPostRedisplay();
}

void MyInit(void) {  //초기 설정입니다
    glClearColor(0.0, 0.0, 0.0, 1.0);  //윈도우의 색 검정색으로 선언 
    glShadeModel(GL_FLAT);
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);  //메뉴등록
    glutAddMenuEntry("Move Head", 1);  //각각 이름과 ID설정해줍니다
    glutAddMenuEntry("Move Right Arm", 2);
    glutAddMenuEntry("Move Left Arm", 3);
    glutAddMenuEntry("Move Right Leg", 4);
    glutAddMenuEntry("Move Left Leg", 5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);  //오른쪽 마우스 클릭시 작동하게 하였습니다

}

void Body(void) {  //로봇의 몸에 관한 함수입니다.
    glRotatef(-90, 1+body1, 0+body2, 0);    //rotate 를 사용하여 돌려줌 
    //DrawAxis();
    glPushMatrix();  //PUSH
    glMaterialfv(GL_FRONT, GL_AMBIENT ,sky);  //물체의 특성 정의,  주변광계수 sky로
    glColor3f(0, 204, 204);  //색을 바꿔줌
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.6, 0.6, 1.5, 40, 8);  //아래반지름 0.6 위반지름 0.6 높이1.5 회전개수 40 subdivision 개수 8로 설정
    glPopMatrix();  //로봇본체에관한 내용 POP

}

void Rightarm(void) {  //오른팔에 관한 함수입니다
    glPushMatrix();  //PUSH

    glRotatef(150, 0, 1, 0);  //ROTATE해줘서 축을 회전시키고
    glTranslatef(-1.1, 0, -0.9);  //위치에 맞게 이동시켜주었습니다
    glRotatef(rightarm, 0+rightarmsub1, 1+ rightarmsub2, 0);  //변수를 추가하여 움직일수있게 하였습니다

    //DrawAxis(); 
    glPushMatrix();   //윗 어깨에 관한 내용입니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, red);  //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
   //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(255, 0, 0);  //색 설정
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 설정
    glPopMatrix();  //

    glTranslatef(-0.05, 0, 0.9);     //팔꿈치에 관한 내용입니다 이동하고 회전하고 회전에 변수를 추가하였습니다
    glRotatef(40 + rightarm2, 0, 1, 0);
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, purple);  //물체의 특성 정의,  주변광계수 purple로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(1.0, 0.0, 1.0); //색을 바꿔주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 세부 스펙 설정
    glPopMatrix();

    glTranslatef(0, 0, 1.0);  //오른손에 관한 내용입니다 팔꿈치에서 이동시켜주고 색을 설정해주고 WireSphere로 만들어 주었습니다
    glColor3f(1.0, 1.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, red);  //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glutSolidSphere(0.2, 10, 10);

    glPopMatrix();   //마지막에 POP해줍니다

}

void Leftarm(void) {  //왼쪽팔에 관한 내용입니다
    glPushMatrix();


    glRotatef(-150, 0, 1, 0);  //회전하고 translate를 이용해 위치를 찾아주고 rotate에 변수를 추가하여 나중에 움직일수 있게 설정해주었습니다
    glTranslatef(1.1, 0, -0.9);
    glRotatef(leftarm, 0+leftarmsub1, 1+leftarmsub2, 0);

    glPushMatrix();  //왼쪽 어깨에 관한 내용입니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, red);    //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(255, 0, 0);  //색을 설정해주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 상세 스펙 설정
    glPopMatrix();

    glTranslatef(+0.05, 0, 0.9);  //왼쪽 팔꿈치에 관한 내용입니다
    glRotatef(-40 + leftarm2, 0, 1, 0);  //회전하고 이동하여 위치를 설정해주고 회전변수를 추가하였습니다
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //색을 설정해주었습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, purple);  //물체의 특성 정의,  주변광계수 purple로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 상세 스펙을 설정해주었습니다
    glPopMatrix();

    glTranslatef(0, 0, 1.0); //이동하고 색바꾸고 왼쪽 손 만들어주었습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, red);  //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.2, 10, 10);

    glPopMatrix();
}

void Rightleg(void) {  //오른쪽 다리에관한 함수입니다
    glPushMatrix();

    glRotatef(180, 0, 1, 0);  //회전하고 이동하고 회전변수 추가하여 처음 허벅지 부분 그려주었습니다
    //DrawAxis();
    glTranslatef(-0.25, 0, 0);
    glRotatef(rightleg, 0+rightlegsub1, 1+rightlegsub2, 0);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, red);    //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(255, 0, 0);  //색을 바꿔주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 상세 스펙 설정
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //이동 회전후 종아리 부분 허벅지 아래에 이어주었습니다
    glRotatef(rightleg2, 0, 1, 0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //색 설정
    glMaterialfv(GL_FRONT, GL_AMBIENT, purple);
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //상세 스펙 설정
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //이동후 색바꾸고 Cylinder로 발 만들어 주었습니다
    glColor3f(1.0, 1.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT,red);  //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.25, 0.25, 0.15, 20, 8);  //상세스펙 설정

    glPopMatrix();
}

void Leftleg(void) {  //왼쪽 다리에 관한 함수입니다
    glPushMatrix();

    glRotatef(180, 0, 1, 0);  //회전하고 이동하고 회전변수 추가하여 나중에 움직일 수 있게 설정해주었습니다
    //DrawAxis();
    glTranslatef(0.25, 0, 0.0);
    glRotatef(leftleg, 0+leftlegsub1, 1+leftlegsub2, 0);

    glPushMatrix();
    glColor3f(255, 0, 0);  //색을 변경해주었습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, red);  //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //상세 스펙 설정해주었습니다
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //이동하고 회전하고 왼쪽 종아리 허벅지 아래에 이어주었습니다
    glRotatef(leftleg2, 0, 1, 0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //색을변경하였습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, purple);  //물체의 특성 정의,  주변광계수 purple로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //상세스펙 설정
    glPopMatrix();

    glTranslatef(0, 0, 0.9);  //이동하고 색 변경하고 왼쪽 발 만들어주었습니다
    glColor3f(1.0, 1.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, red);  //물체의 특성 정의,  주변광계수 red로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.25, 0.25, 0.15, 20, 8);  //아래반지름 1 위반지름 1 높이2 회전개수 20 subdivision 개수 5로 설정*/

    glPopMatrix();
}

void NeckAndHead(void) {  //목과 머리에 관한 함수입니다
    glPushMatrix();

    glRotatef(0, 0, 1, 0);  //회전하고 이동하여 목을 몸 위에 만들어주었고 neck변수를 통해 추후에 이동할수 있도록 해주었습니다
    glTranslatef(0, 0, 1.5);
    //DrawAxis();
    glRotatef(neck, 0, 1, 0);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT,yellow);   //물체의 특성 정의,  주변광계수 yellow로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(255.0, 255.0, 0.0);  //색을 수정해주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL);   //실린더로 만들어주었습니다
    gluCylinder(qobj, 0.2, 0.2, 0.4, 20, 8);
    glPopMatrix();

    glPushMatrix();      //오른쪽 눈
    glRotatef(-60, 1, 0, 0);  //목 기준으로 움직여서 눈의 위치를 설정해주었습니다
    glTranslatef(0.4, -0.5, 0.5);
    //DrawAxis();
    glRotatef(eye, 0, 1, 0);  //눈의 변수를 추가해주고 색 바꾸고 Disk로 만들어주었습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT,green);  //물체의 특성 정의,  주변광계수 green로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(0, 1.0, 0);
    glutSolidSphere(0.10, 10, 10);
    //gluDisk(qobj, 0.05, 0.1, 20, 3);
    glPopMatrix();

    glPushMatrix();         //왼쪽 눈
    glRotatef(-60, 1, 0, 0);  //목 기준으로 움직여서 눈의 위치를 설정해주었습니다
    glTranslatef(-0.4, -0.5, 0.5);
    //DrawAxis();
    glRotatef(eye, 0, 1, 0);   //눈의 변수를 추가해주고 색 바꾸고 Disk로 만들어주었습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, green);  //물체의 특성 정의,  주변광계수 green로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glColor3f(0, 1.0, 0);
    glutSolidSphere(0.10, 10, 10);
    //gluDisk(qobj, 0.05, 0.1, 20, 3);
    glPopMatrix();

    glTranslatef(0, 0, 0.4);  //머리를 이동하고 회전하여 만들어주었습니다
    glRotatef(head, 0, 1, 0);
    //DrawAxis();
    glPushMatrix();
    glColor3f(255.0, 255.0, 0.0);  //색을 설정해주었습닏
    glMaterialfv(GL_FRONT, GL_AMBIENT, yellow);  //물체의 특성 정의,  주변광계수 yellow로
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    gluQuadricDrawStyle(qobj, GLU_LINE); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_LINE 으로 설정하여 wire-frame 형태로 모델링함
    gluCylinder(qobj, 0.6, 0.4, 0.5, 30, 4);  //Cylinder 스펙을 설정해주었습니다
    glPopMatrix();

    glPopMatrix();
}

void MyDisplay(void) {  //MyDispaly 함수에 관한 내용입니다
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

   // glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
   // glLightfv(GL_LIGHT0, GL_AMBIENT, white);

    glPushMatrix();   
    glTranslatef(-2.0, 1.0,1.5);   //조명 위치 이동
    glEnable(GL_LIGHTING);         //조명 기능 활성화
    glEnable(GL_LIGHT0);            //GL_LIGHT0 확성화
    glLightfv(GL_LIGHT0, GL_AMBIENT, white);   //주변광 흰색으로 설정
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);   //광원 위치 지정
    glColor3d(0.9, 0.9, 0.5);  //색 지정
    glutSolidSphere(0.1, 10, 10);    //크기 및 모양 설정
    glPopMatrix(); 

    Body();  //위에서 만들 몸,오른팔, 오른다리 왼팔 왼다리 목과머리 함수를 모두 추가하였습니다
    Rightarm();
    Leftarm();
    Rightleg();
    Leftleg();
    NeckAndHead();

    glPopMatrix();
    glutSwapBuffers();
}

void MyReshape(int w, int h) {  //윈도우 크기 변경시 적용되는 Reshape함수입니다
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void MyKeyboard(unsigned char key, int x, int y) {  //키보드 관련 함수이고 s클릭시 모두 멈추게 적용하였습니다
    switch (key) {
    case 's':
        glutTimerFunc(40, Timer6, 1);
        break;
    case 'S':
        glutTimerFunc(40, Timer6, 1);
        break;
    case 'R':
        stop_7 = false;  
        glutTimerFunc(10, Timer7, 1);
        break;
    case 'r':
        stop_7 = false;
        glutTimerFunc(10, Timer7, 1);
        break;
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {  //메인함수입니다
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //RGB 및 더블버퍼 사용
    glutInitWindowSize(800, 600);  //윈도우 크기 설정
    glutInitWindowPosition(100, 100);  //윈도우 시작 위치 설정
    glutCreateWindow("Can Robot");  //윈도우만듬
    MyInit();  //MyInit함수 등록
    glutDisplayFunc(MyDisplay); //MyDisplay함수 등록
    glutReshapeFunc(MyReshape);  //MyReshape함수 등록
    glutKeyboardFunc(MyKeyboard);   //MyKeyboard함수 등록
    glutMainLoop();
    return 0;
}