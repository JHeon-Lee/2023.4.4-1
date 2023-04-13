// 2023.4.4,1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

/*
숫자 야구게임 : 1 ~ 9 까지의 숫자 중 랜덤한 숫자 3개가 선택되고 그 숫자 3개를 맞추는 게임
컴퓨터가 임의로 3개의 숫자를 순차적으로 선택
숫자 3개를 순차적으로 고른다
숫자가 없다 - OUT , 숫자는 맞췄지만 자리가 다르다 - BALL , 숫자, 위치 모두 맞췄다 - STRIKE
- 반복 -
2 0 3
STRIKE : 1
BALL : 1
OUT : 1
- 반복 -
*/

int main()
{
    srand(time(NULL));
    rand();

    bool isContinue = true, isRandom = true;
    int nC1 = rand() % 10, nC2 = rand() % 10, nC3 = rand() % 10;
    while (isRandom)
    {
        // system("cls"); --> 화면 깨끗하게 지워줌
        if (nC2 == nC1)
            nC2 = rand() % 10;
        if (nC3 == nC1 || nC3 == nC2)
            nC3 == rand() % 10;
        if (nC1 != nC2 && nC1 != nC3 && nC2 != nC3)
            break;
    }
    int nP, nP1, nP2, nP3;
    // int nCount = 0; --> 추가하면 시행한 횟수 기록 가능

    cout << "숫자 야구게임 시작!" << endl;
    cout << "컴퓨터의 3자리 숫자를 맞춰야합니다." << endl;
    cout << "숫자가 없다 : OUT, 숫자는 맞췄지만 자리가 다르다 - BALL, 숫자, 위치 모두 맞췄다 - STRIKE" << endl;
    //cout << nP1 << "\t" << nP2 << "\t" << nP3 << endl;

    while (isContinue)
    {
        cout << "숫자 세개를 입력해주세요 : (세개의 수는 중복되지 않음) : ";
        cin >> nP;
        nP1 = nP / 100;
        nP3 = nP % 10;
        nP2 = (nP - (nP1 * 100 + nP3)) / 10;

        int nS = 0, nB = 0, nO = 0;

        if (nP1 == nC1)
        {
            nS += 1;
            if (nP2 == nC1 || nP2 == nC3)
            {
                nB += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
            else if (nP2 == nC2)
            {
                nS += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
            else
            {
                nO += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
        }
        else if (nP1 == nC2 || nP1 == nC3)
        {
            nB += 1;
            if (nP2 == nC1 || nP2 == nC3)
            {
                nB += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
            else if (nP2 == nC2)
            {
                nS += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
            else
            {
                nO += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
        }
        else
        {
            nO += 1;
            if (nP2 == nC1 || nP2 == nC3)
            {
                nB += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
            else if (nP2 == nC2)
            {
                nS += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
            else
            {
                nO += 1;
                if (nP3 == nC1 || nP3 == nC2)
                    nB += 1;
                else if (nP3 == nC3)
                    nS += 1;
                else
                    nO += 1;
            }
        }
        cout << "STRIKE :" << nS << endl;
        cout << "BALL :" << nB << endl;
        cout << "OUT :" << nO << endl;

        if (nS == 3)
        {
            cout << "축하합니다 정답입니다!" << endl;
            isContinue = false;
            /*
            char chYN;
            cout << "새 게임(y, n) ";
            cin >> chYN;
            if (chYN == 'n')
                isContinue = false;     --> 게임을 더 할지 플레이어가 정할 수 있음
             */ 
        }
        cout << endl;
    }

    system("pause");

    return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
