#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CLEAR_SCREEN "\033[H\033[2J"

enum ErrorCode {
    IS_NOT_INTEGER = 0,
    IS_NOT_CARTYPE,
    IS_NOT_ENGINETYPE,
    IS_NOT_BRAKETYPE,
    IS_NOT_STEERINGTYPE,
    IS_NOT_RUNORTEST,
    IS_OK
};

enum QuestionType
{
    CarType_Q = 0,
    Engine_Q,
    brakeSystem_Q,
    SteeringSystem_Q,
    Run_Test,
};

enum RunTestType
{
    INIT_RUNTEST_TYPE = 0,
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
    BRAKE_ENGINE,
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


class Car {
private:
    CarType carType;
    Engine engineType;
    brakeSystem brakeType;
    SteeringSystem steeringType;
public:
    Car() : carType(CarType::INIT_CAR_TYPE), engineType(Engine::INIT_ENGINE_TYPE), brakeType(brakeSystem::INIT_BRAKE_TYPE), steeringType(SteeringSystem::INIT_STEERING_TYPE) {}
    ~Car() {}

    void SetCarType(int inputCarType);

    void SetEngineType(int inputEngineType);
    void SetBrakeType(int inputBrakeType);
    void SetSteeringType(int inputSteeringType);


    bool CheckConstraints();

    CarType GetCarType();
    Engine GetEngineType();
    brakeSystem GetBrakeType();
    SteeringSystem GetSteeringType();
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

    bool isExitString(const char* userInputString) {
        return !strcmp(userInputString, "exit");
    }

    void removeNewLine(char* userInputString) {
        char* context = nullptr;
        strtok_s(userInputString, "\r", &context);
        strtok_s(userInputString, "\n", &context);
    }

    void setDelayAndRetVal(int delayValue, bool& retVal) {
        delay(delayValue);
        retVal = false;
    }

    int convertStringToInt(char** checkNumber, const char* userInputString) {
        int answer = strtol(userInputString, checkNumber, 10); // 문자열을 10진수로 변환

        return answer;
    }
};

class CarAssemble {
private:
    Car car;
    QuestionType curStep;
    int answer;
    
public:
    bool isNeedToBackStep();
    void setCurrentStep(int nextStep);

    ErrorCode CheckInputisInterger(char* userInputString);

    int handleNextStep();

    void init(Car& inputCar);

    QuestionType getCurStep();

    CarAssemble() : car(), curStep(CarType_Q), answer(0) {}
    ~CarAssemble() {}

    Car& getCar() { return car; }
    void setAnswer(int input) { answer = input; }
    int getAnswer() { return answer; }
};