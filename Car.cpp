#pragma once
#include "Car.h"

void Car::SetCarType(int inputCarType) {
    carType = (CarType)inputCarType;
}

void Car::SetEngineType(int inputEngineType) {
    engineType = (Engine)inputEngineType;
}

void Car::SetBrakeType(int inputBrakeType) {
    brakeType = (brakeSystem)inputBrakeType;
}

void Car::SetSteeringType(int inputSteeringType) {
    steeringType = (SteeringSystem)inputSteeringType;
}

bool Car::CheckConstraints()
{
    bool isValidCondition = true;

    if (carType == SEDAN && brakeType == CONTINENTAL)
    {
        isValidCondition = false;
    }
    else if (carType == SUV && engineType == TOYOTA)
    {
        isValidCondition = false;
    }
    else if (carType == TRUCK && engineType == WIA)
    {
        isValidCondition = false;
    }
    else if (carType == TRUCK && brakeType == MANDO)
    {
        isValidCondition = false;
    }
    else if (carType == BOSCH_B && steeringType != BOSCH_S)
    {
        isValidCondition = false;
    }

    return isValidCondition;
}

CarType Car::GetCarType() { return carType; }
Engine Car::Car::GetEngineType() { return engineType; }
brakeSystem Car::GetBrakeType() { return brakeType; }
SteeringSystem Car::GetSteeringType() { return steeringType; }

bool CarAssemble::isNeedToBackStep() {
    bool isNeedToBack = false;

    // 처음으로 돌아가기
    if (answer == 0 && curStep == Run_Test)
    {
        curStep = QuestionType::CarType_Q;
        isNeedToBack = true;
    }

    // 이전으로 돌아가기
    else if (answer == 0 && curStep >= 1)
    {
        int prevStep = curStep - 1;
        curStep = (QuestionType)prevStep;
        isNeedToBack = true;
    }
    return isNeedToBack;
}

void CarAssemble::setCurrentStep(int nextStep) {
    curStep = (QuestionType)nextStep;
}

ErrorCode CarAssemble::CheckInputisInterger(char* userInputString) {

    char* checkNumber = NULL;
    answer = car.convertStringToInt(&checkNumber, userInputString);

    ErrorCode errorCode = ErrorCode::IS_OK;
    int delayValue = 800;

    // 입력받은 문자가 숫자가 아니라면
    if (*checkNumber != '\0')
    {
        errorCode = ErrorCode::IS_NOT_INTEGER;
    }

    else if (curStep == CarType_Q && !(answer >= Engine_Q && answer <= SteeringSystem_Q))
    {
        errorCode = ErrorCode::IS_NOT_CARTYPE;
    }

    else if (curStep == Engine_Q && !(answer >= INIT_ENGINE_TYPE && answer < MAX_ENGINE_TYPE))
    {
        errorCode = ErrorCode::IS_NOT_ENGINETYPE;
    }

    else if (curStep == brakeSystem_Q && !(answer >= INIT_BRAKE_TYPE && answer < MAX_BRAKE_TYPE))
    {
        errorCode = ErrorCode::IS_NOT_BRAKETYPE;
    }

    else if (curStep == SteeringSystem_Q && !(answer >= INIT_STEERING_TYPE && answer < MAX_STEERING_TYPE))
    {
        errorCode = ErrorCode::IS_NOT_STEERINGTYPE;
    }

    else if (curStep == Run_Test && !(answer >= INIT_RUNTEST_TYPE && answer < MAX_RUNTEST_TYPE))
    {
        errorCode = ErrorCode::IS_NOT_RUNORTEST;
    }

    return errorCode;
}

int CarAssemble::handleNextStep() {

    if (isNeedToBackStep()) {
        return answer;
    }

    if (curStep == CarType_Q)
    {
        car.SetCarType(answer);
        setCurrentStep(Engine_Q);
    }
    else if (curStep == Engine_Q)
    {
        car.SetEngineType(answer);
        setCurrentStep(brakeSystem_Q);
    }
    else if (curStep == brakeSystem_Q)
    {
        car.SetBrakeType(answer);
        setCurrentStep(SteeringSystem_Q);
    }
    else if (curStep == SteeringSystem_Q)
    {
        car.SetSteeringType(answer);
        setCurrentStep(Run_Test);
    }
    else if (curStep == Run_Test && answer == 1) {
        car.CheckConstraints();
        car.delay(2000);
    }
    return answer;
}

void CarAssemble::init(Car& inputCar) {
    car = inputCar;
}

QuestionType CarAssemble::getCurStep() { return curStep; }
