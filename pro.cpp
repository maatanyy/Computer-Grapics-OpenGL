/***********************************************************************/
/*                           HW#8 : 종합   삼도류 뚱이      */
/*  작성자 : 노민성                             날짜 : 2021년 12월 5일           */
/*                                                                              */
/* 문제 정의 :                                                                 */
/*지금까지 배운 기술 종합 
- 지금까지 수행한 실습과제의 내용을 종합하여 객체를 모델링하고, 
콜백프로그래밍, 모델변환, 시점변환, 투영변환, 뷰폿변환, 가시성검사, 조명, 텍스춰 
등 수업시간에 배웠던 기술이 모두 쓰일 수 있도록 프로그램을 만들어보시오. 
- 그동안 모델링해봤던 객체를 종합적으로 사용하여도 좋고, 추가로 만들고 싶은 객체를 모델링해도 좋고, 제공해주는 모델을 사용해도 좋음.
- 모델링 된 객체가 하는 기능은 각자 스스로 정의하도록 함.
    
    기존의 CanRobot을 변형에서 스펀지밥에 나오는 뚱이를 모델링 해봤습니다. 
    집에 강도가 들어왔다는 소식에 집에 뛰어오고 (R) 상대를 보고 복싱 자세를 취하고 (A->R) 
    싸움에서 밀리자 칼을 하나씩 꺼내며 싸웁니다. (D, F, V) 
    (C)는 스킬입니다...뚱이의 키가 커지고 무기가 커지며 입에 문 무기를 휘두릅니다 
    (A)를 누르면 다시 무기를 없애고 복싱 자세를 취합니다 
    Q (왼쪽) W (정면) E(오른족)에서 뚱이를 바라볼 수 있습니다
/*************************************************************************/
#include <windows.h>  //시스템 함수를 사용하려면 추가 
#include <stdlib.h>
#include <GL/glut.h>  //oepnGL 헤더파일
#include <stdio.h>
#include <GL/glaux.h>  //oepnGL 헤더파일

#pragma comment(lib, "glaux.lib")
#pragma comment (lib,"legacy_stdio_definitions.lib")  //추가시 링크에 걸리지 않고 컴파일 됨

GLuint g_textureID = -1;  //텍스처 매핑에 사용하기 위해 선언

float body = 0, rightarm = 0, rightarm2 = 0, leftarm = 0, leftarm2 = 0, rightleg = 0, rightleg2 = 0, leftleg = 0, leftleg2 = 0, neck = 0, eye = 0, head = 0;  //뚱이의 신체에 관한 변수 선언
float rightarmsub1 = 0, rightarmsub2 = 0,rightarmsub3 = 0, leftarmsub1 = 0, leftarmsub2 = 0, leftarmsub3 = 0, rightlegsub1 = 0, rightlegsub2 = 0, leftlegsub1 = 0, leftlegsub2 = 0;
float body1 = 0, body2 = 0;
//각 rotate에서 이동에 사용할 변수이고 0으로 초기화 및 선언하였습니다
int neckchange = 1, rightarmchange = 1, leftarmchange = 1, rightlegchange = 1, leftlegchange = 1;  //뚱이의 신체에서 방향 조절을 하기위해 선언 및 초기화
int rightarmchange2 = 1, leftarmchange2 = 1, rightlegchange2 = 1, leftlegchange2 = 1;
int rightpunch = 1;
//이동하며 최대 범위 도달후 방향 전환을 하기 위해 선언한 변수입니다 처음엔 1로 설정하였습니다
bool stop_1 = false, stop_2 = false, stop_3 = false, stop_4 = false, stop_5 = false, stop_7 = false, stop_8 = false , stop_10 = false, stop_12=false;  //이 bool이 true 이면 멈춥니다, flase일 경우 움직이게 합니다
bool knife = false, knife2 = false, knife3 = false;  //칼에 사용하기위한 변수입니다
bool mouth = true;  //입에 칼을 물었을 때 입을 없애기 위한 변수입니다
bool back = false;  //음영에 사용하기 위한 변수입니다
int skill1=0, skill2=0, skill3 = 0;  //칼을 꺼낼 때 사용하는 변수입니다
int len1 = 0, len2 = 0, len3 = 0;  //신체길이에 변화를 줄 때 사용하는 변수입니다
int legskill1 = 0, legskill2 = 0;  //다리에 쓰는 변수입니다
int rot3 = 0;  //무기를 돌릴 때 사용하는 변수입니다
GLdouble CameraX = 0.0, CameraY = 0.0, CameraZ = 0.0, FocusX = 0.0, FocusY = 0.0, FocusZ = 0.0;  //lookat에 사용하기 위한 변수입니다


//조명에 이용할 각 색들에 대한 설정입니다.  
const GLfloat red[] = { 255, 0.0, 0.0, 1.0 };
const GLfloat purple[] = { 1.0, 0.0, 1.0, 1.0 };
const GLfloat pink[] = { 250,0,0 };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat yellow[] = { 255.0, 255.0, 0.0 };
const GLfloat green[] = { 0 ,1 ,0 };
const GLfloat blue[] = { 0 ,0 ,1 };
const GLfloat sky[] = { 0, 204,204 };
const GLfloat polished[] = { 100.0 };
const GLfloat dull[] = { 0.0 };
const GLfloat light_pos[] = { -3.0, 1000.0, 7.0, 1.0 };  //조명위치에 대한 설정 

GLUquadricObj* qobj = gluNewQuadric();  //새로운 Quadric 생성

//사용할 함수 선언, 
void Timer6(int value);
void Timer8(int value);
void Stop1(int value);
void Stop2(int value);
void Stop3(int value);
void Stop4(int value);
void Stop5(int value);
void Stop7(int value);
void Stop8(int value);

void loadTexture(void) {  //텍스처를 가져오는 함수입니다   강의예제 10-8을 참고하였습니다
    AUX_RGBImageRec* pTextureImage = auxDIBImageLoad(L"cloth.bmp");

    if (pTextureImage != NULL) {
        glGenTextures(1, &g_textureID);

        glBindTexture(GL_TEXTURE_2D, g_textureID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, 3, pTextureImage->sizeX, pTextureImage->sizeY, 0,
            GL_RGB, GL_UNSIGNED_BYTE, pTextureImage->data);
    }

    if (pTextureImage) {  //마지막에 free 해줍니다
        if (pTextureImage->data)
            free(pTextureImage->data);

        free(pTextureImage);
    }
}

void Timer1(int value) {    //머리움직임에 관련된 타이머 입니다
    if (stop_1 == true) {  //만약  bool의 값이 true 일 경우 멈춥니다
        neck = neck;
        eye = eye;
        head = head;
    }
    else {     //bool의 값이 false 일 경우, 움직입니다
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
        if (neck >= 20.00000) {    //이동범위를 넘어가면 change의 부호를 바꿔줍니다
            neckchange = -1;
        }
        if (neck <= 0.00000) {    //처음상태로 돌아오면 멈추는 함수를 호출합니다
            neckchange = 1;
            glutTimerFunc(40, Stop1, 1);  
        }
        glutPostRedisplay();   //계속 변화를적용하며 다시 타이머를 호출합니다
        glutTimerFunc(20, Timer1, 1);
    }
}

void Timer2(int value) {      //오른팔 움직임에 관한 타이머입니다. 
    if (stop_2 == true) {     //만약  bool의 값이 true 일 경우 멈춥니다
        rightarm = rightarm;
        rightarm2 = rightarm2;
    }
    else {    //bool의 값이 false 일 경우, 움직입니다
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

void Timer3(int value) {     //왼팔 움직임에 관한 타이머입니다
    if (stop_3 == true) {   //만약  bool의 값이 true 일 경우 멈춥니다
        leftarm = leftarm;
        leftarm2 = leftarm2;
    }
    else {     //bool의 값이 false 일 경우, 움직입니다
        if (leftarmchange == 1) {   //처음엔 왼쪽으로 움직입니다
            leftarm = leftarm + 0.7;
            leftarm2 = leftarm2 + 0.3;
        }
        else if (leftarmchange == -1) {   //만약 change가 -1이면 오른쪽으로 움직입니다
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
        glutPostRedisplay();    //이동을 바로 적용하고 타이머를 호출합니다
        glutTimerFunc(20, Timer3, 1);
    }
}

void Timer4(int value) {     //오른쪽 다리 움직임에 관한 타이머입니다
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

void Timer5(int value) {     //왼쪽 다리 움직임에 관한 타이머입니다
    if (stop_5 == true) {    //만약  bool의 값이 true 일 경우 멈춥니다
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
        if (leftleg <= 0.00000) {  //각도가 지정범위를 벗어나면 이동방향을 바꿔줍니다
            leftlegchange = 1;
            glutTimerFunc(40, Stop5, 1);
        }
        glutPostRedisplay();  //바로 적용시켜주고 타이머를 호출해줍니다
        glutTimerFunc(40, Timer5, 1);
    }
}

void Timer7(int value) {    //달리기에 관한 티어미 입니다

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

    else {     //bool의 값이 false 일 경우, 움직입니다
        if (rightarm == -80) {
            rightarm = 0;
        }

        if (rightarmchange == 1) {     //change가 1일 경우 오른쪽으로 움직입니다
            rightarm = rightarm - 1.2;
            rightarm2 = rightarm2 - 0.3;
            rightarmsub1 = rightarmsub1 + 0.2;
            rightarmsub2 = rightarmsub2 - 0.05;
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
            leftarmsub1 = leftarmsub1 + 0.2;
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
            rightleg = rightleg - 1.2;     //-1.2
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
            leftleg = leftleg + 1.2;
            leftleg2 = leftleg2 + 0.3;
            leftlegsub1 = leftlegsub1 + 0.6;
            leftlegsub2 = leftlegsub2 - 0.2;
        }
        if (leftleg >= 20.00000) {  //각도가 지정범위를 벗어나면 이동방향을 바꿔줍니다
            leftlegchange = 1;
            glutTimerFunc(20, Stop5, 1);
        }
        if (leftleg <= -20.00000) {   //각도가 지정범위를 벗어나면 이동방향을 바꿔줍니다
            leftlegchange = -1;
        }

        glutPostRedisplay();   //계속 변화를적용하며 다시 타이머를 호출합니다
        glutTimerFunc(10, Timer7, 1);
    }
}

void Stop1(int value) {  //머리움직이는걸 멈추는 함수입니다
    stop_1 = true;    //stop_1을 true로 해주고 적용시키고 타이머를 호출합니다
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

void Stop7(int value) { //달리기에 관한 타이머, 달리기 멈추는 함수
    stop_7 = true;  //stop_7을 true로 해주고 적용시키고 타이머를 호출합니다
    glutPostRedisplay();
    glutTimerFunc(40, Timer7, 1);
} 

void Stop8() {  //전체 다 멈추는 함수입니다 다 초기설정으로 바꿔주고 적용시켜 줍니다
    body = 0, rightarm = 0, rightarm2 = 0, leftarm = 0, leftarm2 = 0, rightleg = 0, rightleg2 = 0, leftleg = 0, leftleg2 = 0, neck = 0, eye = 0, head = 0;
    rightarmsub1 = 0, rightarmsub2 = 0, leftarmsub1 = 0, leftarmsub2 = 0, rightlegsub1 = 0, rightlegsub2 = 0, leftlegsub1 = 0, leftlegsub2 = 0;
    body1 = 0, body2 = 0;
    glutPostRedisplay();
}

void Timer6(int value) {   //모두다 멈추는 timer입니다 모든 stop_을 true로 한 후 모든 타이머를 호출합니다
    stop_1 = true;
    stop_2 = true;
    stop_3 = true;
    stop_4 = true;
    stop_5 = true;
    stop_7 = true;
    stop_12 = true;
    glutPostRedisplay();
    glutTimerFunc(20, Timer1, 1);
    glutTimerFunc(20, Timer2, 1);
    glutTimerFunc(20, Timer3, 1);
    glutTimerFunc(20, Timer4, 1);
    glutTimerFunc(20, Timer5, 1);
    glutTimerFunc(20, Timer7, 1);
    glutTimerFunc(20, Timer8, 1);
}

void Timer8(int value) {   // 입에 문 칼을 돌립니다

    if (stop_12 == true) {  //만약 stop_12가 true라면 칼 돌리는 걸 멈춥니다
        rot3 = rot3;
    }
    //만약 stop_12가 false이면 칼을 움직입니다
    else {
        if (rot3 <= 360.00000) {  //rot3을 증가시키며 칼을 돌립니다
            rot3 += 5;
        }
        else {  //한바퀴돌면 다시 0으로해줍니다
            rot3 = 0;
        }
        glutPostRedisplay();  //바로 적용시켜줍니다
        glutTimerFunc(20, Timer8, 1);  //칼돌리는 타이머를 다시 호출합니다
    }
}

void MyMainMenu(int entryID) {  //메뉴등록에 관한 함수입니다
    if (entryID == 1) {    //1번 누를시 다 보여줍니다
        back = false;   
    }
    else if (entryID == 2) {    //2번 누를시 뒷면을 제거합니다
        back = true; 
    }
    glutPostRedisplay();  //바로 적용시켜줍니다
}

void MyInit(void) {  //초기 설정입니다
    loadTexture();  //텍스처를 불러옵니다
    glClearColor(0.0, 0.0, 0.0, 1.0);  //윈도우의 색 검정색으로 선언 
    //glShadeModel(GL_FLAT);
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);  //메뉴등록
    glutAddMenuEntry("See All", 1);    //각각 이름과 ID설정해줍니다
    glutAddMenuEntry("Remove Back", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);  //오른쪽 마우스 클릭시 작동하게 하였습니다
}

void Body(void) {  //로봇의 몸에 관한 함수입니다.
    glRotatef(-90, 1 + body1, 0 + body2, 0);    //rotate 를 사용하여 돌려줍니다
    //DrawAxis();
    glPushMatrix();  //PUSH
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의,  주변광계수 pink로
    glColor3f(0, 204, 204);  //색을 바꿔줌
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL로
    gluCylinder(qobj, 0.9, 0.8, 1.5, 40, 8);  //아래반지름 0.9 위반지름 0.8 높이1.5 회전개수 40 subdivision 개수 8로 설정
    glPopMatrix();  //로봇본체에관한 내용 POP
}

void Rightarm(void) {  //오른팔에 관한 함수입니다
    glPushMatrix();  //PUSH
    glRotatef(150, 0, 1, 0);  //ROTATE해줘서 축을 회전시키고
    glTranslatef(-1.25, 0, -0.9);  //위치에 맞게 이동시켜주었습니다
    glRotatef(rightarm, 0 + rightarmsub1, 1 + rightarmsub2, 0 + rightarmsub3);  //변수를 추가하여 움직일수있게 하였습니다

    glPushMatrix();   //윗 어깨에 관한 내용입니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의,  주변광계수 pink로
    glColor3f(255, 0, 0);  //색 설정
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL로
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 설정
    glPopMatrix();  

    glTranslatef(-0.05, 0, 0.9);     //팔꿈치에 관한 내용입니다 이동하고 회전하고 회전에 변수를 추가하였습니다
    glRotatef(40 + rightarm2, 0, 1, 0);
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의,  주변광계수 pink로
    glColor3f(1.0, 0.0, 1.0); //색을 바꿔주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL로
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 세부 스펙 설정
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.0);  //오른손에 관한 내용입니다 팔꿈치에서 이동시켜주고 색을 설정해주고 SolidSphere로 만들어 주었습니다
    glColor3f(1.0, 1.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의, 주변광계수 pink로
  
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();

    if (knife == true) {
        glPushMatrix();
        glTranslatef(0.0, 0, 1.0);  //오른손에 관한 내용입니다 팔꿈치에서 이동시켜주고 색을 설정해주고 Cylinder로 
        glColor3f(1.0, 1.0, 1.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, yellow);  //물체의 특성 정의,  주변광계수 yellow로
        gluCylinder(qobj, 0.3, 0.3, 0.5, 40, 8);
        glPopMatrix();  

        glTranslatef(0.0, 0, 1.5);
        glColor3f(1.0, 1.0, 1.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blue);  //물체의 특성 정의,  주변광계수 blue로
        gluCylinder(qobj, 0.2, 0.05+len1, 3.0+skill1, 40, 8);
    }
    glPopMatrix();

}

void Leftarm(void) {  //왼쪽팔에 관한 내용입니다
    glPushMatrix();
    glRotatef(-150, 0, 1, 0);  //회전하고 translate를 이용해 위치를 찾아주고 rotate에 변수를 추가하여 나중에 움직일수 있게 설정해주었습니다
    glTranslatef(1.25, 0, -0.9);
    glRotatef(leftarm, 0 + leftarmsub1, 1 + leftarmsub2, 0+leftarmsub3);

    glPushMatrix();  //왼쪽 어깨에 관한 내용입니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);    //물체의 특성 정의,  주변광계수 pink로 
    glColor3f(255, 0, 0);  //색을 설정해주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL로 설정
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 상세 스펙 설정
    glPopMatrix();

    glTranslatef(+0.05, 0, 0.9);  //왼쪽 팔꿈치에 관한 내용입니다
    glRotatef(-40 + leftarm2, 0, 1, 0);  //회전하고 이동하여 위치를 설정해주고 회전변수를 추가하였습니다
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //색을 설정해주었습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의,  주변광계수 pink로
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL 형태로
    gluCylinder(qobj, 0.2, 0.2, 1, 20, 8);  //Cylinder 상세 스펙을 설정해주었습니다
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 1.0); //이동하고 색바꾸고 왼쪽 손 만들어주었습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의,  주변광계수 pink로 
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(0.2, 10, 10);
    glPopMatrix();

    if (knife2 == true) {  //만약 knife2가 활성화되면 칼이 나옵니다 
        glPushMatrix();
        glTranslatef(0.0, 0, 1.0);  
        glColor3f(1.0, 1.0, 1.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, yellow);  //물체의 특성 정의,  주변광계수 yellow로
        gluCylinder(qobj, 0.3, 0.3, 0.5, 40, 8);   //실린더로 칼 손잡이 
        glPopMatrix();

        glTranslatef(0.0, 0, 1.5);
        glColor3f(1.0, 1.0, 1.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT, blue);  //물체의 특성 정의,  주변광계수 blue로
        gluCylinder(qobj, 0.2, 0.05+len2, 3.0+skill2, 40, 8);  //실린더로 칼날 만듬 
    }
    glPopMatrix();
}

void Rightleg(void) {  //오른쪽 다리에관한 함수입니다
    glPushMatrix();
    glRotatef(180, 0, 1, 0);  //회전하고 이동하고 회전변수 추가하여 처음 허벅지 부분 그려주었습니다
    glTranslatef(0, 0, -0.15);
    glRotatef(rightleg, 0 + rightlegsub1, 1 + rightlegsub2 , 0);

    //뚱이 바지 모델링
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glMaterialfv(GL_FRONT, GL_AMBIENT, yellow);    //물체의 특성 정의,  주변광계수 yellow로
    glColor3f(255, 0, 0);  //색을 바꿔주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL);  // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL
    gluQuadricTexture(qobj, GL_TRUE);
    glBindTexture(GL_TEXTURE_2D, g_textureID);  //텍스처를 입혔습니다 
    gluCylinder(qobj, 0.9, 0.6, 0.8, 40, 8);  
    glDisable(GL_TEXTURE_2D);   //glDisable로 텍스처를 Disable 해주었습니다 
    glPopMatrix();

    glTranslatef(-0.3, 0, 0.8);  //이동 회전후 종아리 부분 허벅지 아래에 이어주었습니다
    glRotatef(rightleg2, 0, 1, 0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //색 설정
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);   //pink로 조명 맞췄습니다 
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL
    gluCylinder(qobj, 0.3, 0.2, 0.4 +legskill1, 20, 8);  //상세 스펙 설정
    glPopMatrix();

    glTranslatef(0, 0, 0.4);  //이동후 색바꾸고 Cylinder로 발 만들어 주었습니다
    glColor3f(1.0, 1.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의,  주변광계수 pink로 
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL
    gluCylinder(qobj, 0.2, 0.1, 0.15, 20, 8);  //상세스펙 설정

    glPopMatrix();
}

void Leftleg(void) {  //왼쪽 다리에 관한 함수입니다
  
    glPushMatrix();
    glRotatef(180, 0, 1, 0);  //회전하고 이동하고 회전변수 추가하여 나중에 움직일 수 있게 설정해주었습니다
    glRotatef(leftleg, 0 + leftlegsub1, 1 + leftlegsub2, 0);
    glTranslatef(0.3, 0, 0.65);  //이동하고 회전하고 왼쪽 종아리 허벅지 아래에 이어주었습니다
    glRotatef(leftleg2, 0, 1, 0);
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);  //색을 변경하였습니다
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의, 주변광계수 pink로
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL로 
    gluCylinder(qobj, 0.3, 0.2, 0.4 + legskill2, 20, 8);  //상세스펙 설정
    glPopMatrix();

    glTranslatef(0, 0, 0.4);  //이동하고 색 변경하고 왼쪽 발 만들어주었습니다
    glColor3f(1.0, 1.0, 1.0);
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);  //물체의 특성 정의,  주변광계수 pink로 
    gluQuadricDrawStyle(qobj, GLU_FILL); // Quadric을 위해 원하는 Draw Style 지정 -> GLU_FILL로 설정하였습니다 
    gluCylinder(qobj, 0.2, 0.1, 0.15, 20, 8);  //아래반지름 1 위반지름 1 높이2 회전개수 20 subdivision 개수 5로 설정*/

    glPopMatrix();
}

void NeckAndHead(void) {  //목과 머리에 관한 함수입니다

    glPushMatrix();
    glRotatef(0, 0, 1, 0);  //회전하고 이동하여 목을 몸 위에 만들어주었고 neck변수를 통해 추후에 이동할수 있도록 해주었습니다
    glTranslatef(0, 0, 1.5);
    glRotatef(neck, 0, 1, 0);

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_AMBIENT, pink);   //물체의 특성 정의,  주변광계수 pink로 
    glColor3f(255.0, 255.0, 0.0);  //색을 수정해주었습니다
    gluQuadricDrawStyle(qobj, GLU_FILL);   //실린더로 만들어주었습니다
    gluCylinder(qobj, 0.5, 0.1, 1.4, 40, 8);
    glPopMatrix();

    if (mouth == true) {
        glPushMatrix();      //입 그리기
        glRotatef(-60, 1, 0, 0);  //목 기준으로 움직여서 입의 위치를 설정해주었습니다
        glTranslatef(0.0, -0.2, 0.5);

        glMaterialfv(GL_FRONT, GL_AMBIENT, white);  //물체의 특성 정의, 주변광계수 white로
        glColor3f(0, 1.0, 0);
        glLineWidth(5.0);
        glBegin(GL_LINES);        //GL_LINES로 입 그려줌
        glVertex3f(-0.25, 0.1, 0);
        glVertex3f(0.25, 0.1, 0);
        glEnd();
        glPopMatrix();
    }

    if (knife3 == true) {  //만약 knife3가 활성화되면 칼이 보이게 하였습니다 
        glPushMatrix();
        glRotatef(90+rot3, 0,1,0);  
        glTranslatef(-0.1, 0.5, -0.3);
        glMaterialfv(GL_FRONT, GL_AMBIENT,yellow);  //물체의 특성 정의, 주변광계수 yellow로
        glColor3f(1.0, 1.0, 1.0);
        gluCylinder(qobj, 0.3, 0.3, 0.6, 40, 8);
        glTranslatef(0.0, 0, 0.5);
        glColor3f(1.0, 1.0, 1.0);
        glMaterialfv(GL_FRONT, GL_AMBIENT,blue);  //물체의 특성 정의,  주변광계수 blue로
        gluCylinder(qobj, 0.2, 0.05+len3, 3.0+skill3, 40, 8);
        glPopMatrix();
    }

    glPushMatrix();      //오른쪽 눈동자
    glRotatef(-60, 1, 0, 0);  //목 기준으로 움직여서 눈의 위치를 설정해주었습니다
    glTranslatef(0.2, -0.5, 0.5);
    glRotatef(eye, 0, 1, 0);  //눈의 변수를 추가해주고 색 바꾸고 SolidSphere로 만들어 주었습니다 
    glMaterialfv(GL_FRONT, GL_AMBIENT, white);  //물체의 특성 정의,  주변광계수 white로
    glColor3f(0, 1.0, 0);
    glutSolidSphere(0.10, 10, 10);
    glPopMatrix();

    glPushMatrix();      //오른쪽 눈
    glRotatef(-60, 1, 0, 0);  //목 기준으로 움직여서 눈의 위치를 설정해주었습니다
    glTranslatef(0.2, -0.5, 0.5);
    glRotatef(eye, 0, 1, 0);  //눈의 변수를 추가해주고 색 바꾸고 SolidSphere로 만들어 주었습니다 
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);  //물체의 특성 정의,  주변광계수 black로
    glColor3f(0, 1.0, 0);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();

    glPushMatrix();         //왼쪽 눈동자
    glRotatef(-60, 1, 0, 0);  //목 기준으로 움직여서 눈의 위치를 설정해주었습니다
    glTranslatef(-0.2, -0.5, 0.5);
    glRotatef(eye, 0, 1, 0);   //눈의 변수를 추가해주고 색 바꾸고 SolidSphere로 만들어 주었습니다 
    glMaterialfv(GL_FRONT, GL_AMBIENT, white);  //물체의 특성 정의,  주변광계수 white로
    glColor3f(0, 1.0, 0);
    glutSolidSphere(0.10, 10, 10);
    glPopMatrix();

    glPushMatrix();      //왼쪽 눈
    glRotatef(-60, 1, 0, 0);  //목 기준으로 움직여서 눈의 위치를 설정해주었습니다
    glTranslatef(-0.2, -0.5, 0.5);
    glRotatef(eye, 0, 1, 0);  //눈의 변수를 추가해주고 색 바꾸고 SolidSphere로 만들어주었습니다 
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);  //물체의 특성 정의,  주변광계수 black으로
    glColor3f(0, 1.0, 0);
    glutSolidSphere(0.05, 10, 10);
    glPopMatrix();
 
    glPopMatrix();
}

void MyDisplay(void) {  //MyDispaly 함수에 관한 내용입니다
    glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); //그림을 그릴 때마다 색깔 버퍼를 초기화할때 깊이 버퍼도 초기화
    glPushMatrix();
    gluLookAt(CameraX, CameraY, 3.0 + CameraZ, FocusX, 0.0 + FocusY, 0.0 + FocusZ, 0.0, 1.0, 0.0);  //변수를 설정해 시점을 바꿀수 있게하였습니다
    glPushMatrix();

    glTranslatef(1.0, -1.0, 5.0);   //조명 위치 이동
    glShadeModel(GL_SMOOTH);     //GL_SMOOTH로 음영 설정
    glEnable(GL_LIGHTING);         //조명 기능 활성화
    glEnable(GL_LIGHT0);            //GL_LIGHT0 확성화
    glLightfv(GL_LIGHT0, GL_AMBIENT, white);   //주변광 흰색으로 설정
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);   //광원 위치 지정

    glColor3d(0.9, 0.9, 0.5);  //색 지정
    glutSolidSphere(0.1, 10, 10);    //크기 및 모양 설정
    glPopMatrix();

    if (back == true) {  //만약 back이 true면 
        glEnable(GL_CULL_FACE);  //후면 제거 모드 활성화 
    }
    glFrontFace(GL_CW);  //시계방향이 정면이 된다 
    glCullFace(GL_BACK);  //후면 제거하겠다 
    
    Body();  //위에서 만들 몸,오른팔, 오른다리 왼팔 왼다리 목과머리 함수를 모두 추가하였습니다
    Rightarm();
    Leftarm();
    Rightleg();
    Leftleg();
    NeckAndHead();
    glPopMatrix();
    glDisable(GL_CULL_FACE);  //후면제거 모드 비활성화 
    glutSwapBuffers();
}

void MyReshape(int w, int h) {  //윈도우 크기 변경시 적용되는 Reshape함수입니다
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);  //gluPerspective하기 위해 MatrixMode 바꿔줍니다 
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);  //다시 모델뷰로 바꿔줍니다 
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
}

void MyKeyboard(unsigned char key, int x, int y) {  //키보드 관련 함수이고 s클릭시 모두 멈추게 적용하였습니다
    switch (key) {

    case 's':  //멈추기
    case 'S':
        rot3 = 0;
        glutTimerFunc(40, Timer6, 1);
        break;

    case 't':  //차렷 자세로멈추기
    case 'T':
        rot3 = 0;
        Stop8();
        glutTimerFunc(40, Timer6, 1);
        break;

    case 'R':   //뛰기
    case 'r':
        leftarm = 0;
        rightarm = 0;
        stop_7 = false;
        glutTimerFunc(10, Timer7, 1);
        break;

    case 'q':  // gluLookAt 변수 값을 설정해줘서 멀리서 왼쪽을 바라보게 구현하였습니다
    case 'Q':
        CameraX = -5.0;
        CameraY = 0.0;
        CameraZ = 0.0;
        FocusX = 0.0;
        FocusY = 0.0;
        FocusZ = 0.0;
        break;

    case 'e':   //gluLookAt 변수 값을 설정해줘서 멀리서 오른쪽을 바라보게 구현하였습니다
    case 'E':
        //gluLookAt(CameraX, CameraY, 3.0 + CameraZ, FocusX, 0.0 + FocusY, 0.0 + FocusZ, 0.0, 1.0, 0.0);
        CameraX = 5.0;
        CameraY = 0.0;
        CameraZ = 0.0;
        FocusX = 0.0;
        FocusY = 0.0;
        FocusZ = 0.0;
        break;

    case 'w':  //gluLookAt 변수 값을 설정해줘서 정면을 바라보게 구현하였습니다
    case 'W':
        CameraX = 0.0;
        CameraY = 0.0;
        CameraZ = 2.0;
        FocusX = 0.0;
        FocusY = 0.0;
        FocusZ = 0.0;
        break;

    case 'a':  //복싱 자세 준비
    case 'A':
        mouth = true;
        knife = false;
        knife2 = false;
        knife3 = false;
        skill1 = 0.0;
        skill2 = 0.0;
        skill3 = 0.0;
        len1 = 0.0;
        len2 = 0.0;
        len3 = 0.0;
        legskill1 = 0.0;
        legskill2 = 0.0;
        rot3 = 0;
        Stop8();
        glutTimerFunc(40, Timer6, 1);
        leftarm = 30;
        rightarm = -30;
        leftarm2 = 240;
        rightarm2 = -240;
        break;

    case 'd': 
    case 'D':  //오른쪽 칼 활성화 합니다
        knife = true;
        rightarm2 = 200;
        glutPostRedisplay();
        break;
    
    case 'f':
    case 'F':   //왼쪽 칼 활성화 합니다
        knife2 = true;
        leftarm2 = -200;
        glutPostRedisplay();
        break;

    case 'v':  //뚱이의 입에 칼을 활성화합니다 
    case 'V':
        mouth = false;
        knife3 = true;
        glutPostRedisplay();
        break;

    case 'c':
    case 'C':   //뚱이가 스킬을 씁니다 
        skill1 = 0.6;
        skill2 = 0.6;
        skill3 = 2.6;
        len1 = 1.0;
        len2 = 1.0;
        len3 = 1.0;
        legskill1 = 2.0;
        legskill2 = 2.0;
        mouth = false;
        knife = true;
        knife2 = true;
        knife3 = true;
        stop_12 = false;
        glutTimerFunc(20, Timer8, 1);
        glutPostRedisplay();
        break;
        
    case 27:
        exit(0);
        break;
    default:
        break;
    }
    glutPostRedisplay();  //바로 적용합니다 
}

int main(int argc, char** argv) {  //메인함수입니다
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  //RGB 및 더블버퍼 사용, Z-buffer사용
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