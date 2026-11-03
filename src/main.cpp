
#include "BuzzerAlertModule.h"
#include "FileTransferModule.h"
#include "PowerSupplyDisplayModule.h"
#include "SC8815PowerSupplyModule.h"

#include "OpenKNX.h"
#include "hardware.h"

void setup()
{
    const uint8_t firmwareRevision = 0;

    openknx.init(firmwareRevision);

    openknx.addModule(1, openknxBusPowerSupplyModule);
    openknx.addModule(2, openknxBuzzerAlertModule);
    openknx.addModule(3, openknxPowerSupplyDisplayModule);
    openknx.addModule(4, openknxFileTransferModule);

    openknx.setup();
}

void loop()
{
    openknx.loop();
}