#pragma XOD require "https://github.com/sensirion/arduino-core"
#pragma XOD require "https://github.com/Sensirion/arduino-i2c-scd4x"

#include <SensirionI2CScd4x.h>

node {

    meta {
        // Define our custom type as a pointer on the class instance.
        using Type = SensirionI2CScd4x*;
    }

    // Keep Adafruit_SGP30 object in state
    SensirionI2CScd4x sensor = SensirionI2CScd4x();


    void evaluate(Context ctx) {
        emitValue<output_DEV>(ctx, &sensor);
    }
}
