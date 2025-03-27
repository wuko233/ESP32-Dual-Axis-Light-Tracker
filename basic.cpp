#include "basic.h"

String get_input() {
    String msg;
    int status = 0;
    while (status == 0) {
        if (Serial.available()) {
            char c = Serial.read();
            if (c == '\n') {
                status = 1;
            } else {
                msg += c;
            }
        }
    }
    msg.trim();
    return msg;
}