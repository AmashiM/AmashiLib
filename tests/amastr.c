
#include "amastr.h"

int main(void){
    PAmaStr str = AmaStrCreate();
    AmaStrSet(str, "hello world\n");

    AmaStrPrint(str);

    AmaStrCat(str, "hey there\n");
    
    AmaStrPrint(str);

    AmaStrFree(str);
    return 0;
}