#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>

#include "knob_data.h"
#include "task.h"

class DisplayTask : public Task<DisplayTask> {
    friend class Task<DisplayTask>; // Allow base Task to invoke protected run()

    public:
        DisplayTask(const uint8_t task_core);
        ~DisplayTask();

        void setData(KnobState state);

    protected:
        void run();

    private:
        TFT_eSPI tft_ = TFT_eSPI();

        /** Full-size sprite used as a framebuffer */
        TFT_eSprite spr_ = TFT_eSprite(&tft_);

        SemaphoreHandle_t semaphore_;

        KnobState state_;
};
