#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::initgooglemock();
    return run_all_tests();
}

#else

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CLEAR_SCREEN "\033[H\033[2J"

int stack[10];

void selectCarType(int answer);
void selectEngine(int answer);
void selectbrakeSystem(int answer);
void selectSteeringSystem(int answer);
void runProducedCar();
void testProducedCar();
void delay(int ms);

enum QuestionType
{
    CarType_Q,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum CarType
{
    CARINIT = 0,
    SEDAN,
    SUV,
    TRUCK
};

enum Engine
{
    GM = 1,
    TOYOTA,
    WIA,
    BREAKDOWN
};

enum brakeSystem
{
    MANDO = 1,
    CONTINENTAL,
    BOSCH_B
};

enum SteeringSystem
{
    BOSCH_S = 1,
    MOBIS
};

void delay(int ms)
{
    volatile int sum = 0;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            for (int t = 0; t < ms; t++)
            {
                sum++;
            }
        }
    }
}

void showSelectCarTypeMenu() {
    printf(CLEAR_SCREEN);

    printf("        ______________\n");
    printf("       /|            | \n");
    printf("  ____/_|_____________|____\n");
    printf(" |                      O  |\n");
    printf(" '-(@)----------------(@)--'\n");
    printf("===============================\n");
    printf("� ���� Ÿ���� �����ұ��?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void showSelectEngineTypeMenu() {
    printf(CLEAR_SCREEN);
    printf("� ������ ž���ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. ���峭 ����\n");
}

void showSelectBrakeSystemMenu() {
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void showSelectSteeringSystmeMenu() {
    printf(CLEAR_SCREEN);
    printf("� ������ġ�� �����ұ��?\n");
    printf("0. �ڷΰ���\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void showRunTest() {
    printf(CLEAR_SCREEN);
    printf("���� ������ �ϼ��Ǿ����ϴ�.\n");
    printf("� ������ �ұ��?\n");
    printf("0. ó�� ȭ������ ���ư���\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void setDelayAndRetVal(int delayValue, bool& retVal) {
    delay(delayValue);
    retVal = false;
}

int convertStringToInt(char** checkNumber, const char* userInputString) {
    int answer = strtol(userInputString, checkNumber, 10); // ���ڿ��� 10������ ��ȯ

    return answer;
}

bool CheckInputisInterger(char* userInputString, int currentStep, int& answer) {

    char* checkNumber = NULL;
    answer = convertStringToInt(&checkNumber, userInputString);

    bool returnValue = true;
    int delayValue = 800;

    // �Է¹��� ���ڰ� ���ڰ� �ƴ϶��
    if (*checkNumber != '\0')
    {
        printf("ERROR :: ���ڸ� �Է� ����\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == Engine_Q && !(answer >= 0 && answer <= 4))
    {
        printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == brakeSystem_Q && !(answer >= 0 && answer <= 3))
    {
        printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == SteeringSystem_Q && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == Run_Test && !(answer >= 0 && answer <= 2))
    {
        printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    return returnValue;
}

bool isNeedToBackStep(const int& answer, int& currentStep) {
    bool isNeedToBack = false;
    
    // ó������ ���ư���
    if (answer == 0 && currentStep == Run_Test)
    {
        currentStep = CarType_Q;
        isNeedToBack = true;
    }

    // �������� ���ư���
    else if (answer == 0 && currentStep >= 1)
    {
        currentStep -= 1;
        isNeedToBack = true;
    }
    return isNeedToBack;
}

void setCurrentStep(int& currentStep, int nextStep) {
    currentStep = nextStep;
}

void handleNextStep(const int& answer, int& currentStep) {

    if (isNeedToBackStep(answer, currentStep)) {
        return;
    }

    if (currentStep == CarType_Q)
    {
        selectCarType(answer);
        delay(800);
        setCurrentStep(currentStep, Engine_Q);
    }
    else if (currentStep == Engine_Q)
    {
        selectEngine(answer);
        delay(800);
        setCurrentStep(currentStep, brakeSystem_Q);
    }
    else if (currentStep == brakeSystem_Q)
    {
        selectbrakeSystem(answer);
        delay(800);
        setCurrentStep(currentStep, SteeringSystem_Q);
    }
    else if (currentStep == SteeringSystem_Q)
    {
        selectSteeringSystem(answer);
        delay(800);
        setCurrentStep(currentStep, Run_Test);
    }
    else if (currentStep == Run_Test && answer == 1)
    {
        runProducedCar();
        delay(2000);
    }
    else if (currentStep == Run_Test && answer == 2)
    {
        printf("Test...\n");
        delay(1500);
        testProducedCar();
        delay(2000);
    }
}

void removeNewLine(char* userInputString) {
    char* context = nullptr;
    strtok_s(userInputString, "\r", &context);
    strtok_s(userInputString, "\n", &context);
}

bool isExitString(const char* userInputString) {
    return !strcmp(userInputString, "exit");
}

void getUserInputString(char* userInputString) {
    printf("===============================\n");
    printf("INPUT > ");
    fgets(userInputString, sizeof(userInputString), stdin);

    // ���� ���๮�� ����
    removeNewLine(userInputString);
}

void printExitString(void) {
    printf("���̹���\n");
}

void selectCarType(int answer)
{
    stack[CarType_Q] = answer;
    if (answer == SEDAN)
        printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
    if (answer == SUV)
        printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
    if (answer == TRUCK)
        printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
}

void selectEngine(int answer)
{
    stack[Engine_Q] = answer;
    if (answer == GM)
        printf("GM ������ �����ϼ̽��ϴ�.\n");
    if (answer == TOYOTA)
        printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
    if (answer == WIA)
        printf("WIA ������ �����ϼ̽��ϴ�.\n");
}

void selectbrakeSystem(int answer)
{
    stack[brakeSystem_Q] = answer;
    if (answer == MANDO)
        printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == CONTINENTAL)
        printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == BOSCH_B)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
}

void selectSteeringSystem(int answer)
{
    stack[SteeringSystem_Q] = answer;
    if (answer == BOSCH_S)
        printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
    if (answer == MOBIS)
        printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
}

bool CheckConstraints()
{
    bool isValidCondition = true;

    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        isValidCondition = false;
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        isValidCondition = false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        isValidCondition = false;
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        isValidCondition = false;
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        isValidCondition = false;
    }

    return isValidCondition;
}

void printCurrentCarType(int carType) {
    if (carType == SEDAN)
        printf("Car Type : Sedan\n");
    else if (carType == SUV)
        printf("Car Type : SUV\n");
    else if (carType == TRUCK)
        printf("Car Type : Truck\n");
}

void printCurrentEnginType(int engineType) {
    if (engineType == GM)
        printf("Engine : GM\n");
    else if (engineType == TOYOTA)
        printf("Engine : TOYOTA\n");
    else if (engineType == WIA)
        printf("Engine : WIA\n");
}

void printCurrentBrakeType(int brakeType) {
    if (brakeType == MANDO)
        printf("Brake System : Mando");
    else if (brakeType == CONTINENTAL)
        printf("Brake System : Continental\n");
    else if (brakeType == BOSCH_B)
        printf("Brake System : Bosch\n");
}

void printCurrentSteeringType(int steeringType) {
    if (steeringType == BOSCH_S)
        printf("SteeringSystem : Bosch\n");
    else if (steeringType == MOBIS)
        printf("SteeringSystem : Mobis\n");
}

void runProducedCar()
{
    if (CheckConstraints() == false)
    {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    else
    {
        if (stack[Engine_Q] == BREAKDOWN)
        {
            printf("������ ���峪�ֽ��ϴ�.\n");
            printf("�ڵ����� �������� �ʽ��ϴ�.\n");
        }
        else
        {
            printCurrentCarType(stack[CarType_Q]);
            printCurrentEnginType(stack[Engine_Q]);
            printCurrentBrakeType(stack[brakeSystem_Q]);
            printCurrentSteeringType(stack[SteeringSystem_Q]);

            printf("�ڵ����� ���۵˴ϴ�.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Sedan���� Continental������ġ ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("SUV���� TOYOTA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� WIA���� ��� �Ұ�\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Truck���� Mando������ġ ��� �Ұ�\n");
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
        printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
    }
    else
    {
        printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
    }
}

void RunCarAssemble() {
    char userInputString[100] = {0, };
    int currentStep = CarType_Q;
    int answer = 0;

    while (true) {
        switch (currentStep) {
        case CarType_Q:
            showSelectCarTypeMenu();
            break;
        case Engine_Q:
            showSelectEngineTypeMenu();
            break;
        case brakeSystem_Q:
            showSelectBrakeSystemMenu();
            break;
        case SteeringSystem_Q:
            showSelectSteeringSystmeMenu();
            break;
        case Run_Test:
            showRunTest();
            break;
        default:
            break;
        }

        getUserInputString(userInputString);

        if (isExitString(userInputString)) {
            printExitString();
            break;
        }

        // ���ڷ� �� ������� Ȯ��
        if (CheckInputisInterger(userInputString, currentStep, answer))
            handleNextStep(answer, currentStep);
    }
}

int main()
{
    RunCarAssemble();

    return 0;
}
#endif