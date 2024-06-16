#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_INIT

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_INIT>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);
        auto wire = getValue<input_I2C>(ctx);

        // Initialize SCD4X device with user specified I2C interface
        sensor->begin(*wire);

        auto sensorError = sensor->stopPeriodicMeasurement();
        if (sensorError) {
            raiseError(ctx);
            return;
        }

        emitValue<output_OK>(ctx, 1);

    }
}
