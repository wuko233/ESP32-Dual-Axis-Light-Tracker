#include "oled_display.h"
#include "config.h"
#include "basic.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0, U8X8_PIN_NONE, OLED_SCL, OLED_SDA);

int setupDisplay() {
    OLED.begin();
    OLED.setFont(u8g2_font_wqy12_t_gb2312);
    OLED.enableUTF8Print();
    OLED.clearBuffer();
    OLED.sendBuffer();
    return 200;
}

void display_menu() {
    while (1) {
        display("Display\n[1] Test text\n[2] Test image\n[0] Exit", 100);
        String opt = get_input();
        if (opt == "0") {
        break;
        }
        if (opt == "1") {
            display("Senpai\nCiallo~", 2000);
        } else if (opt == "2") {
            img_test();
            delay(2500);
        } else {
            display("err!", 1000);
        }
    }
}

void display(const char* info, int display_time) {
    digitalWrite(LED_BUILTIN, HIGH);
    int max_Width = OLED.getDisplayWidth() / 6;
    int y = 10;
    int spilt_len = 25;
    Serial.println(info);
    OLED.clearBuffer();
    int total_len = strlen(info);  // 总长度
    int past_len = 0;                    // 初始Y坐标
    for (int pos = 0; pos <= total_len; ++pos) { // 包含结束符位置
        if (info[pos] == '\n' || info[pos] == '\0') { // 处理换行或字符串结束
            int seg_len = pos - past_len;
            if (seg_len > 0) { // 避免空行
                char* seg = new char[seg_len + 1];
                if (!seg) {
                    Serial.println("[ERR]new seg failed!");
                    return;
                }
                strncpy(seg, info + past_len, seg_len);
                seg[seg_len] = '\0';
                if (strlen(seg) > max_Width) {
                    for (int start = 0; start < seg_len; start += spilt_len) {
                        // 创建临时缓冲区存放子字符串
                        int tem_len = spilt_len;
                        if (seg_len < tem_len) {
                            tem_len = seg_len;
                        }
                        char* tem = new char[tem_len + 1];
                        if (!tem) {
                            Serial.println("[ERR]new    tem failed!");
                            return;
                        }
                        strncpy(tem, seg + start, tem_len);
                        tem[tem_len] = '\0';          // 手动添加终止符
                        // 显示当前段
                        OLED.setCursor(0, y);
                        OLED.print(tem);
                        delete[] tem; // 释放内存
                        y += 10;          // 下移一行
                    }
                } else {
                    OLED.setCursor(0, y);
                    OLED.print(seg);
                    y += 10;
                }
                delete[] seg; // 释放内存
            }
            past_len = pos + 1; // 跳过换行符或结束符
        }
    }
    OLED.sendBuffer();
    delay(20); // 确保缓冲区写入完成
    if (display_time > 0) {
        delay(display_time);
    }
    digitalWrite(LED_BUILTIN,LOW);
}

void img_test() {
    OLED.clearBuffer();
    // 显示全屏图像
    OLED.drawXBM(0, 0, 128, 64, imageData);
    OLED.sendBuffer();
    delay(50);
}