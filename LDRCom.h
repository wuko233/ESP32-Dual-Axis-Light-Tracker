#pragma once

int setupLDR();

struct SensorData {
  int data1;
  int data2;
  int data3;
  int data4;
};

SensorData returnAllData();

int returnData1();
int returnData2();
int returnData3();
int returnData4();

