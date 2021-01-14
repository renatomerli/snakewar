#pragma once

#include <vector>

typedef struct {
    int a, b, c;

}RGB ;

RGB BLACK {0,0,0};
RGB WHITE {255,255,255};
RGB RED {255,0,0};
RGB GREEN {0,255,0};
RGB BLUE {0,0,255};
RGB MAROON {128,0,0};
RGB CYAN {0,255,255};
RGB SALMON {250,128,114};

static std::vector<RGB> COLORS = {WHITE, RED, GREEN, BLUE, MAROON, CYAN, SALMON};

