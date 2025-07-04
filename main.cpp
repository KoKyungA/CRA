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
    void printExitString(void) {
        printf("���̹���\n");
    }
    void printErrorConstraints() {
        printf("�ڵ����� ���۵��� �ʽ��ϴ�\n");
    }
    void printEnginError() {
        printf("������ ���峪�ֽ��ϴ�.\n");
        printf("�ڵ����� �������� �ʽ��ϴ�.\n");
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
        printf("�ڵ����� ���۵˴ϴ�.\n");
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
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Sedan���� Continental������ġ ��� �Ұ�\n");
        }
        else if (carType == SUV && engineType == TOYOTA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("SUV���� TOYOTA���� ��� �Ұ�\n");
        }
        else if (carType == TRUCK && engineType == WIA)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� WIA���� ��� �Ұ�\n");
        }
        else if (carType == TRUCK && brakeType == MANDO)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Truck���� Mando������ġ ��� �Ұ�\n");
        }
        else if (carType == BOSCH_B && steeringType != BOSCH_S)
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : FAIL\n");
            printf("Bosch������ġ���� Bosch������ġ �̿� ��� �Ұ�\n");
        }
        else
        {
            printf("�ڵ��� ��ǰ ���� �׽�Ʈ ��� : PASS\n");
        }
        car.delay(2000);
    }

    void printCarType(CarType carType)
    {
        if (carType == SEDAN)
            printf("���� Ÿ������ Sedan�� �����ϼ̽��ϴ�.\n");
        if (carType == SUV)
            printf("���� Ÿ������ SUV�� �����ϼ̽��ϴ�.\n");
        if (carType == TRUCK)
            printf("���� Ÿ������ Truck�� �����ϼ̽��ϴ�.\n");
        car.delay(800);
    }

    void printEnginType(Engine enginType)
    {
        if (enginType == GM)
            printf("GM ������ �����ϼ̽��ϴ�.\n");
        if (enginType == TOYOTA)
            printf("TOYOTA ������ �����ϼ̽��ϴ�.\n");
        if (enginType == WIA)
            printf("WIA ������ �����ϼ̽��ϴ�.\n");
        car.delay(800);
    }

    void printBrakeType(brakeSystem brakeType)
    {
        if (brakeType == MANDO)
            printf("MANDO ������ġ�� �����ϼ̽��ϴ�.\n");
        if (brakeType == CONTINENTAL)
            printf("CONTINENTAL ������ġ�� �����ϼ̽��ϴ�.\n");
        if (brakeType == BOSCH_B)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        car.delay(800);
    }

    void printSteeringType(SteeringSystem steeringType)
    {
        if (steeringType == BOSCH_S)
            printf("BOSCH ������ġ�� �����ϼ̽��ϴ�.\n");
        if (steeringType == MOBIS)
            printf("MOBIS ������ġ�� �����ϼ̽��ϴ�.\n");
        car.delay(800);
    }

    void getUserInputString(char* userInputString) {
        showGetInputStringMenu();
        fgets(userInputString, sizeof(userInputString), stdin);

        // ���� ���๮�� ����
        car.removeNewLine(userInputString);
    }

    void printErrorCode(ErrorCode errorCode) {
        switch (errorCode) {
        case IS_NOT_INTEGER:
            printf("ERROR :: ���ڸ� �Է� ����\n");
            break;
        case IS_NOT_CARTYPE:
            printf("ERROR :: ���� Ÿ���� 1 ~ 3 ������ ���� ����\n");
            break;
        case IS_NOT_ENGINETYPE:
            printf("ERROR :: ������ 1 ~ 4 ������ ���� ����\n");
            break;
        case IS_NOT_BRAKETYPE:
            printf("ERROR :: ������ġ�� 1 ~ 3 ������ ���� ����\n");
            break;
        case IS_NOT_STEERINGTYPE:
            printf("ERROR :: ������ġ�� 1 ~ 2 ������ ���� ����\n");
            break;
        case IS_NOT_RUNORTEST:
            printf("ERROR :: Run �Ǵ� Test �� �ϳ��� ���� �ʿ�\n");
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

            // ���ڷ� �� ������� Ȯ��
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