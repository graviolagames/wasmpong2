#include <emscripten.h>
#include <stdarg.h>
#include <stdio.h>

void consolePrint(const char *format, ...){
    char buffer[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, 1024, format, args);
    va_end(args);
    EM_ASM({
        console.log(UTF8ToString($0));
  }, buffer);
}

EMSCRIPTEN_KEEPALIVE
int main(){
    consolePrint("%s", "[DEBUG] Main()");
    return 0;
}

EMSCRIPTEN_KEEPALIVE
void moduleUpdate(){
       consolePrint("%s", "[DEBUG] Test");
}