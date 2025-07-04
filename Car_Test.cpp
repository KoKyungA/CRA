#pragma once
#include "gmock/gmock.h"
#include "Car.cpp"

TEST(CarTest, setCarType) {
	// set param
	Car car;

	// do test & check result
	for (int i = 0; i < MAX_CAR_TYPE; i++) {
		car.SetCarType(i);
		EXPECT_EQ(i, car.GetCarType());
	}
}

TEST(CarTest, SetEngineType) {
	// set param
	Car car;

	// do test & check result
	for (int i = 0; i < MAX_ENGINE_TYPE; i++) {
		car.SetEngineType(i);
		EXPECT_EQ(i, car.GetEngineType());
	}
}

TEST(CarTest, SetBrakeType) {
	// set param
	Car car;

	// do test & check result
	for (int i = 0; i < MAX_BRAKE_TYPE; i++) {
		car.SetBrakeType(i);
		EXPECT_EQ(i, car.GetBrakeType());
	}
}

TEST(CarTest, SetSteeringType) {
	// set param
	Car car;

	// do test & check result
	for (int i = 0; i < MAX_BRAKE_TYPE; i++) {
		car.SetSteeringType(i);
		EXPECT_EQ(i, car.GetSteeringType());
	}
}

TEST(CarTest, CheckConstraintsForSEDAN) {
	// set param
	Car car;
	car.SetCarType(SEDAN);
	car.SetBrakeType(CONTINENTAL);

	// do test
	bool result = car.CheckConstraints();

	// check result
	bool expected = false;
	EXPECT_EQ(expected, result);	
}

TEST(CarTest, CheckConstraintsForSUV) {
	// set param
	Car car;
	car.SetCarType(SUV);
	car.SetEngineType(TOYOTA);

	// do test
	bool result = car.CheckConstraints();

	// check result
	bool expected = false;
	EXPECT_EQ(expected, result);
}

TEST(CarTest, CheckConstraintsForTruckEngine) {
	// set param
	Car car;
	car.SetCarType(TRUCK);
	car.SetEngineType(WIA);

	// do test
	bool result = car.CheckConstraints();

	// check result
	bool expected = false;
	EXPECT_EQ(expected, result);
}

TEST(CarTest, CheckConstraintsForTruckBrake) {
	// set param
	Car car;
	car.SetCarType(TRUCK);
	car.SetBrakeType(MANDO);

	// do test
	bool result = car.CheckConstraints();

	// check result
	bool expected = false;
	EXPECT_EQ(expected, result);
}

TEST(CarTest, CheckConstraintsForBOSCH) {
	// set param
	Car car;
	car.SetCarType(BOSCH_B);
	car.SetSteeringType(MOBIS);

	// do test
	bool result = car.CheckConstraints();

	// check result
	bool expected = false;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, isNeedToBackStepInit) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(QuestionType::Run_Test);

	// do test
	bool result = carAssemble.isNeedToBackStep();

	// check result
	bool expected = true;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, isNeedToBackStepPrev) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(QuestionType::brakeSystem_Q);

	// do test
	carAssemble.isNeedToBackStep();

	// check result
	QuestionType expected = Engine_Q;
	QuestionType result = carAssemble.getCurStep();
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, CheckInputisInterger) {
	// set param
	CarAssemble carAssemble;
	
	// do test
	char inputString[100];
	inputString[0] = 'a';
	inputString[1] = '\0';

	ErrorCode result = carAssemble.CheckInputisInterger(inputString);

	// check result
	ErrorCode expected = IS_NOT_INTEGER;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, CheckInputisCarType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(CarType_Q);

	// do test
	char inputString[100];
	inputString[0] = '4';
	inputString[1] = '\0';

	ErrorCode result = carAssemble.CheckInputisInterger(inputString);

	// check result
	ErrorCode expected = IS_NOT_CARTYPE;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, CheckInputisEngineType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(Engine_Q);

	// do test
	char inputString[100];
	inputString[0] = '5';
	inputString[1] = '\0';

	ErrorCode result = carAssemble.CheckInputisInterger(inputString);

	// check result
	ErrorCode expected = IS_NOT_ENGINETYPE;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, CheckInputisBrakeType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(brakeSystem_Q);

	// do test
	char inputString[100];
	inputString[0] = '4';
	inputString[1] = '\0';

	ErrorCode result = carAssemble.CheckInputisInterger(inputString);

	// check result
	ErrorCode expected = IS_NOT_BRAKETYPE;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, CheckInputisSteeringType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(SteeringSystem_Q);

	// do test
	char inputString[100];
	inputString[0] = '3';
	inputString[1] = '\0';

	ErrorCode result = carAssemble.CheckInputisInterger(inputString);

	// check result
	ErrorCode expected = IS_NOT_STEERINGTYPE;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, CheckInputisRunType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(Run_Test);

	// do test
	char inputString[100];
	inputString[0] = '3';
	inputString[1] = '\0';

	ErrorCode result = carAssemble.CheckInputisInterger(inputString);

	// check result
	ErrorCode expected = IS_NOT_RUNORTEST;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, handleNextStep_Negative) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(Run_Test);

	// do test
	int result = carAssemble.handleNextStep();

	// check result
	int expected = 0;
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, handleNextStepCarType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(CarType_Q);
	carAssemble.setAnswer(1);

	// do test
	carAssemble.handleNextStep();

	// check result
	QuestionType expected = Engine_Q;
	QuestionType result = carAssemble.getCurStep();
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, handleNextStepEngineType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(Engine_Q);
	carAssemble.setAnswer(1);

	// do test
	carAssemble.handleNextStep();

	// check result
	QuestionType expected = brakeSystem_Q;
	QuestionType result = carAssemble.getCurStep();
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, handleNextStepBrakeType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(brakeSystem_Q);
	carAssemble.setAnswer(1);

	// do test
	carAssemble.handleNextStep();

	// check result
	QuestionType expected = SteeringSystem_Q;
	QuestionType result = carAssemble.getCurStep();
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, handleNextStepSteeringType) {
	// set param
	CarAssemble carAssemble;
	carAssemble.setCurrentStep(SteeringSystem_Q);
	carAssemble.setAnswer(1);

	// do test
	carAssemble.handleNextStep();

	// check result
	QuestionType expected = Run_Test;
	QuestionType result = carAssemble.getCurStep();
	EXPECT_EQ(expected, result);
}

TEST(CarAssemble, init) {
	// set param
	CarAssemble carAssemble;
	Car car;
	car.SetCarType(SEDAN);

	// do test
	carAssemble.init(car);

	// check result
	CarType expected = SEDAN;
	CarType result = carAssemble.getCar().GetCarType();
	EXPECT_EQ(expected, result);
}