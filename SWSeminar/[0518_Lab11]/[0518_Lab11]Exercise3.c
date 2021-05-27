#include "Rect.h"

int main(void){
    RECT rect1 = {10, 20, 30, 40};
    PrintRect(&rect1);
    return 0;
}


//add_executable(single_file_exe SWSeminar/[0518_Lab11]/[0518_Lab11]Exercise3.c SWSeminar/[0518_Lab11]/Rect.h SWSeminar/[0518_Lab11]/Rect.c)