#include <gamepad_controller/gamepad_controller.h>
#include <gamepad/gamepad_handler.h>
#include <gamepad/gamepad_types.h>
#include <gamepad/gamepad.h>
GamepadController::GamepadController(){
}
Gamepad *gp;
bool GamepadController::initialize(){
    GamepadHandler::init(this,datamanager());
    //TODO just for testing
    gp = GamepadHandler::getGamepad(this,"Xbox",false);

    if(gp == nullptr) {
        logger.error("init") << "gamepad is null";
        return false;
    }

    setAsXBoxController(*gp);

    return true;
}

bool GamepadController::deinitialize(){
    return true;
}

bool GamepadController::cycle(){
    GamepadHandler::processEvents();
    gp->printButtons();
    return true;
}
