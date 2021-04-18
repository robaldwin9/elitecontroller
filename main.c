#include "controls.h"

int main() 
{
    Key keys[10];
    keys[0] = makeKey(makeInput(0),  25, "cargo scoop", "Home");
    keys[1] = makeKey(makeInput(1),  25, "Landing Gear", "L");
    keys[2] = makeKey(makeInput(4),  25, "Jump", "j");
    keys[3] = makeKey(makeInput(5),  25, "hard points", "k");
    keys[4] = makeKey(makeInput(6),  25, "combat mode", "k");
    keys[5] = makeKey(makeInput(17), 25, "boost", "k");
    keys[6] = makeKey(makeInput(18), 25, "system map", "k");
    keys[7] = makeKey(makeInput(19), 25, "galaxy map", "k");
    keys[8] = makeKey(makeInput(21), 25, "cargo scoop", "k");
    keys[9] = makeKey(makeInput(22), 25, "cargo scoop", "k");
    
    while (true)
     {
        for(int i = 0; i< 10; i++)
        {
           update_key(&keys[i]);
        }
    }
}

