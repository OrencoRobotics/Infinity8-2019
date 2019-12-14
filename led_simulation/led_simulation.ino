#include "controller.h"

static liteguider::controller * control = nullptr;

void setup() { 
    Serial.begin(57600);

    static liteguider::controller lc;
    control = &lc;
}


void loop() {
    control->ride_bike();
}


/*
  Local Variables:
  mode: c++
  c-basic-offset: 4
  indent-tabs-mode: nil
  End:
*/
