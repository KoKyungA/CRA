//#ifdef _DEBUG
//#pragma once
//#include "gmock/gmock.h"
//
//int main()
//{
//    testing::InitGoogleMock();
//    return RUN_ALL_TESTS();
//}
//
//#else

#pragma once
#include "Car.h"
using namespace std;
class CarAssembleMenu {
private:
    CarAssemble carAssemble;
    Car car;
    char userInputString[100];
public:
    void showGetInputStringMenu() {
        printf("===============================\n");
        printf("INPUT > ");
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
    void printExitString(void) {
        printf("바이바이\n");
    }
    void printErrorConstraints() {
        printf("자동차가 동작되지 않습니다\n");
    }
    void printEnginError() {
        printf("엔진이 고장나있습니다.\n");
        printf("자동차가 움직이지 않습니다.\n");
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

    void printRunCar() {
        printf("자동차가 동작됩니다.\n");
        car.delay(2000);
    }

    void printTest() {
        printf("Test...\n");
        car.delay(1500);
    }

    void testProducedCar(CarType carType, brakeSystem brakeType, Engine engineType, SteeringSystem steeringType)
    {
        if (carType == SEDAN && brakeType == CONTINENTAL)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Sedan에는 Continental제동장치 사용 불가\n");
        }
        else if (carType == SUV && engineType == TOYOTA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("SUV에는 TOYOTA엔진 사용 불가\n");
        }
        else if (carType == TRUCK && engineType == WIA)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 WIA엔진 사용 불가\n");
        }
        else if (carType == TRUCK && brakeType == MANDO)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Truck에는 Mando제동장치 사용 불가\n");
        }
        else if (carType == BOSCH_B && steeringType != BOSCH_S)
        {
            printf("자동차 부품 조합 테스트 결과 : FAIL\n");
            printf("Bosch제동장치에는 Bosch조향장치 이외 사용 불가\n");
        }
        else
        {
            printf("자동차 부품 조합 테스트 결과 : PASS\n");
        }
        car.delay(2000);
    }

    void printCarType(CarType carType)
    {
        if (carType == SEDAN)
            printf("차량 타입으로 Sedan을 선택하셨습니다.\n");
        if (carType == SUV)
            printf("차량 타입으로 SUV을 선택하셨습니다.\n");
        if (carType == TRUCK)
            printf("차량 타입으로 Truck을 선택하셨습니다.\n");
        car.delay(800);
    }

    void printEnginType(Engine enginType)
    {
        if (enginType == GM)
            printf("GM 엔진을 선택하셨습니다.\n");
        if (enginType == TOYOTA)
            printf("TOYOTA 엔진을 선택하셨습니다.\n");
        if (enginType == WIA)
            printf("WIA 엔진을 선택하셨습니다.\n");
        car.delay(800);
    }

    void printBrakeType(brakeSystem brakeType)
    {
        if (brakeType == MANDO)
            printf("MANDO 제동장치를 선택하셨습니다.\n");
        if (brakeType == CONTINENTAL)
            printf("CONTINENTAL 제동장치를 선택하셨습니다.\n");
        if (brakeType == BOSCH_B)
            printf("BOSCH 제동장치를 선택하셨습니다.\n");
        car.delay(800);
    }

    void printSteeringType(SteeringSystem steeringType)
    {
        if (steeringType == BOSCH_S)
            printf("BOSCH 조향장치를 선택하셨습니다.\n");
        if (steeringType == MOBIS)
            printf("MOBIS 조향장치를 선택하셨습니다.\n");
        car.delay(800);
    }

    void getUserInputString(char* userInputString) {
        showGetInputStringMenu();
        fgets(userInputString, sizeof(userInputString), stdin);

        // 엔터 개행문자 제거
        car.removeNewLine(userInputString);
    }

    void printErrorCode(ErrorCode errorCode) {
        switch (errorCode) {
        case IS_NOT_INTEGER:
            printf("ERROR :: 숫자만 입력 가능\n");
            break;
        case IS_NOT_CARTYPE:
            printf("ERROR :: 차량 타입은 1 ~ 3 범위만 선택 가능\n");
            break;
        case IS_NOT_ENGINETYPE:
            printf("ERROR :: 엔진은 1 ~ 4 범위만 선택 가능\n");
            break;
        case IS_NOT_BRAKETYPE:
            printf("ERROR :: 제동장치는 1 ~ 3 범위만 선택 가능\n");
            break;
        case IS_NOT_STEERINGTYPE:
            printf("ERROR :: 조향장치는 1 ~ 2 범위만 선택 가능\n");
            break;
        case IS_NOT_RUNORTEST:
            printf("ERROR :: Run 또는 Test 중 하나를 선택 필요\n");
            break;
        default:
            break;
        }
        car.delay(800);
    }

    void printProducedCar()
    {
        if (false == car.CheckConstraints())
        {
            printErrorConstraints();
        }
        else
        {
            if (BRAKE_ENGINE == car.GetEngineType())
            {
                printEnginError();
            }
            else
            {
                printCurrentCarType(car.GetCarType());
                printCurrentEnginType(car.GetEngineType());
                printCurrentBrakeType(car.GetBrakeType());
                printCurrentSteeringType(car.GetSteeringType());

                printRunCar();
            }
        }
    }

    void printCurrentStatus(int answer) {
        if (carAssemble.getCurStep() == Engine_Q) {
            printCarType(car.GetCarType());
        }
        if (carAssemble.getCurStep() == brakeSystem_Q) {
            printEnginType(car.GetEngineType());
        }
        if (carAssemble.getCurStep() == SteeringSystem_Q) {
            printBrakeType(car.GetBrakeType());
        }
        if (carAssemble.getCurStep() == Run_Test) {
            printSteeringType(car.GetSteeringType());
        }
        if (carAssemble.getCurStep() == Run_Test && answer == RUN) {
            printProducedCar();
        }
        if (carAssemble.getCurStep() == Run_Test && answer == TEST) {
            testProducedCar(car.GetCarType(), car.GetBrakeType(), car.GetEngineType(), car.GetSteeringType());
        }
    }

    void runCarAssemble() {
        carAssemble.init(carAssemble.getCar());
        while (true) {
            switch (carAssemble.getCurStep()) {
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

            if (car.isExitString(userInputString)) {
                printExitString();
                return;
            }

            // 숫자로 된 대답인지 확인
            ErrorCode errorCode = carAssemble.CheckInputisInterger(userInputString);
            if (errorCode == IS_OK) {
                int answer = carAssemble.handleNextStep();
                printCurrentStatus(answer);
            }
            else
                printErrorCode(errorCode);
        }
    }
};
int main()
{
    CarAssembleMenu carAssembleMenu;
    carAssembleMenu.runCarAssemble();

    return 0;
}
//#endif