#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);
        
        uint16_t co2 = 0;
        float temperature = 0.0f;
        float humidity = 0.0f;

        auto sensorError = sensor->readMeasurement(co2, temperature, humidity);
        if (sensorError) {
            raiseError(ctx);
            return;
        }

        emitValue<output_CO2>(ctx, co2);
        emitValue<output_Temp>(ctx, temperature);
        emitValue<output_RH>(ctx, humidity);
        emitValue<output_OK>(ctx, 1);

    }
}
