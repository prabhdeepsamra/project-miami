#ifndef Actor_hpp
#define Actor_hpp
#include "Entity.h"
#define DIAG_VSPEED  0.70710678118; 

class Actor: public Entity{

public:
    float vx; //keep this between 0 and 1 movement should be dx * speed * delta
    float vy;
    float speed;
    int health;

    Actor();
    ~Actor();
    
    virtual void init();
    //virtual void update(int delta);
    

};

#endif