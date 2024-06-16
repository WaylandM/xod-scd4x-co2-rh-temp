#pragma XOD evaluate_on_pin disable
#pragma XOD evaluate_on_pin enable input_UPD

node {

    void evaluate(Context ctx) {
        // The node responds only if there is an input pulse
        if (!isInputDirty<input_UPD>(ctx))
            return;

        auto sensor = getValue<input_DEV>(ctx);

        auto sensorError = sensor->wakeUp();
        if (sensorError) {
            raiseError(ctx);
            return;
        }

        emitValue<output_OK>(ctx, 1);

    }
}
