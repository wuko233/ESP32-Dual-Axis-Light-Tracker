# ESP32-Dual-Axis-Light-Tracker

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Platform: Arduino](https://img.shields.io/badge/Platform-Arduino-00979D.svg)](https://www.arduino.cc/)

基于ESP32-S3的双轴光追踪系统，通过四路光敏传感器控制两个步进电机，实现光源追踪。包含硬件设计、Arduino驱动代码及OLED状态显示功能。

## 📖 项目概述
基于ESP32-S3的双轴光追踪系统，实现以下功能：
- 双步进电机协同控制（俯仰轴 + 水平轴）
- 四路光敏传感器实时监测光照强度
- OLED显示屏输出传感器数据及系统状态

## 📦 BOM表
| 组件                | 型号/规格                   | 数量 |
|---------------------|----------------------------|------|
| ESP32-S3开发板       | N16R8                 | 1    |
| 28BYJ-48步进电机     | 5V减速步进电机 + ULN2003驱动板 | 2    |
| 光敏传感器模块       | 光敏电阻模块（AO）    | 4    |
| OLED显示屏           | SSD1306 128x64 I2C         | 1    |
| 电源模块             | 5V/2A独立供电 (推荐18650电池+ups电源模块) | 1    |

## 🛠️ 安装与使用

1. 克隆仓库：
   ```bash
   git clone https://github.com/wuko233/ESP32-Dual-Axis-Light-Tracker.git
   ```
2. 安装依赖库：
   - [U8g2 Library](https://github.com/olikraus/u8g2) (OLED驱动)
   - [ESP32 Arduino Core](https://github.com/espressif/arduino-esp32)
3. 烧写固件：
   - 使用Arduino IDE/VSCode+PlatformIO编译上传
4. 接线
   - 参考`config.h`文件
   - 电机需独立供电

