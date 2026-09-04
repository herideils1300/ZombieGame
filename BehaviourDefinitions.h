#pragma once
#define DEAD_CONDITION if(!this->alive) {return;}
#define DISPERSE_CONDITION if(this->isDispersed) {return;}
#define ANIMATION_RUNNING_CONDITION if(this->isAnimated) {return;}
