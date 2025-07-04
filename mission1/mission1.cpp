#ifdef _DEBUG

#include "gmock/gmock.h"

int main()
{
    testing::InitGoogleMock();
    return RUN_ALL_TESTS();
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

enum RunTestType 
{
    INIT_RUNTEST_TYPE,
    RUN,
    TEST,
    MAX_RUNTEST_TYPE
};

enum CarType
{
    INIT_CAR_TYPE = 0,
    SEDAN,
    SUV,
    TRUCK,
    MAX_CAR_TYPE
};

enum Engine
{
    INIT_ENGINE_TYPE = 0,
    GM,
    TOYOTA,
    WIA,
    MAX_ENGINE_TYPE
};

enum brakeSystem
{
    INIT_BRAKE_TYPE = 0,
    MANDO,
    CONTINENTAL,
    BOSCH_B,
    MAX_BRAKE_TYPE
};

enum SteeringSystem
{
    INIT_STEERING_TYPE = 0,
    BOSCH_S,
    MOBIS,
    MAX_STEERING_TYPE
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
    printf("어떤 차량 타입을 선택할까요?\n");
    printf("1. Sedan\n");
    printf("2. SUV\n");
    printf("3. Truck\n");
}

void showSelectEngineTypeMenu() {
    printf(CLEAR_SCREEN);
    printf("어떤 엔진을 탑재할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. GM\n");
    printf("2. TOYOTA\n");
    printf("3. WIA\n");
    printf("4. 고장난 엔진\n");
}

void showSelectBrakeSystemMenu() {
    printf(CLEAR_SCREEN);
    printf("어떤 제동장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. MANDO\n");
    printf("2. CONTINENTAL\n");
    printf("3. BOSCH\n");
}

void showSelectSteeringSystmeMenu() {
    printf(CLEAR_SCREEN);
    printf("어떤 조향장치를 선택할까요?\n");
    printf("0. 뒤로가기\n");
    printf("1. BOSCH\n");
    printf("2. MOBIS\n");
}

void showRunTest() {
    printf(CLEAR_SCREEN);
    printf("멋진 차량이 완성되었습니다.\n");
    printf("어떤 동작을 할까요?\n");
    printf("0. 처음 화면으로 돌아가기\n");
    printf("1. RUN\n");
    printf("2. Test\n");
}

void setDelayAndRetVal(int delayValue, bool& retVal) {
    delay(delayValue);
    retVal = false;
}

int convertStringToInt(char** checkNumber, const char* userInputString) {
    int answer = strtol(userInputString, checkNumber, 10); // 문자열을 10진수로 변환

    return answer;
}

bool CheckInputisInterger(char* userInputString, int currentStep, int& answer) {

    char* checkNumber = NULL;
    answer = convertStringToInt(&checkNumber, userInputString);

    bool returnValue = true;
    int delayValue = 800;

    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
    {
        printf("ERROR :: 숫자만 입력 가능\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == CarType_Q && !(answer >= 1 && answer <= 3))
    {
        printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == Engine_Q && !(answer >= INIT_ENGINE_TYPE && answer < MAX_ENGINE_TYPE))
    {
        printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == brakeSystem_Q && !(answer >= INIT_BRAKE_TYPE && answer < MAX_BRAKE_TYPE))
    {
        printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == SteeringSystem_Q && !(answer >= INIT_STEERING_TYPE && answer < MAX_STEERING_TYPE))
    {
        printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    if (currentStep == Run_Test && !(answer >= INIT_RUNTEST_TYPE && answer < MAX_RUNTEST_TYPE))
    {
        printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
        setDelayAndRetVal(delayValue, returnValue);
    }

    return returnValue;
}

bool isNeedToBackStep(const int& answer, int& currentStep) {
    bool isNeedToBack = false;
    
    // 처음으로 돌아가기
    if (answer == 0 && currentStep == Run_Test)
    {
        currentStep = CarType_Q;
        isNeedToBack = true;
    }

    // 이전으로 돌아가기
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
    else if (currentStep == Run_Test && answer == RUN)
    {
        runProducedCar();
        delay(2000);
    }
    else if (currentStep == Run_Test && answer == TEST)
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

    // 엔터 개행문자 제거
    removeNewLine(userInputString);
}

void printExitString(void) {
    printf("바이바이\n");
}

void selectCarType(int answer)
{
    stack[CarType_Q] = answer;
    if (answer == SEDAN)
        printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
    if (answer == SUV)
        printf("차량 타입으로 SUV을 선택하셨습니다.\n");
    if (answer == TRUCK)
        printf("차량 타입으로 Truck을 선택하셨습니다.\n");
}

void selectEngine(int answer)
{
    stack[Engine_Q] = answer;
    if (answer == GM)
        printf("GM 엔진을 선택하셨습니다.\n");
    if (answer == TOYOTA)
        printf("TOYOTA 엔진을 선택하셨습니다.\n");
    if (answer == WIA)
        printf("WIA 엔진을 선택하셨습니다.\n");
}

void selectbrakeSystem(int answer)
{
    stack[brakeSystem_Q] = answer;
    if (answer == MANDO)
        printf("MANDO 제동장치를 선택하셨습니다.\n");
    if (answer == CONTINENTAL)
        printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
    if (answer == BOSCH_B)
        printf("BOSCH 제동장치를 선택하셨습니다.\n");
}

void selectSteeringSystem(int answer)
{
    stack[SteeringSystem_Q] = answer;
    if (answer == BOSCH_S)
        printf("BOSCH 조향장치를 선택하셨습니다.\n");
    if (answer == MOBIS)
        printf("MOBIS 조향장치를 선택하셨습니다.\n");
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
        printf("자동차가 동작되지 않습니다\n");
    }
    else
    {
        if (stack[Engine_Q] == MAX_ENGINE_TYPE)
        {
            printf("엔진이 고장나있습니다.\n");
            printf("자동차가 움직이지 않습니다.\n");
        }
        else
        {
            printCurrentCarType(stack[CarType_Q]);
            printCurrentEnginType(stack[Engine_Q]);
            printCurrentBrakeType(stack[brakeSystem_Q]);
            printCurrentSteeringType(stack[SteeringSystem_Q]);

            printf("자동차가 동작됩니다.\n");
        }
    }
}

void testProducedCar()
{
    if (stack[CarType_Q] == SEDAN && stack[brakeSystem_Q] == CONTINENTAL)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Sedan에는 Continental제동장치 사용 불가\n");
    }
    else if (stack[CarType_Q] == SUV && stack[Engine_Q] == TOYOTA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("SUV에는 TOYOTA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[Engine_Q] == WIA)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 WIA엔진 사용 불가\n");
    }
    else if (stack[CarType_Q] == TRUCK && stack[brakeSystem_Q] == MANDO)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Truck에는 Mando제동장치 사용 불가\n");
    }
    else if (stack[brakeSystem_Q] == BOSCH_B && stack[SteeringSystem_Q] != BOSCH_S)
    {
        printf("자동차 부품 조합 테스트 결과 : FAIL\n");
        printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
    }
    else
    {
        printf("자동차 부품 조합 테스트 결과 : PASS\n");
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

        // 숫자로 된 대답인지 확인
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
