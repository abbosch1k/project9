#include <iostream>
#include <dlfcn.h> // POSIX dynamic library
int main() {
    void* lib = dlopen("./plugin.so", RTLD_LAZY);
    if (!lib) { std::cerr << "Cannot load plugin\n"; return 1; }
    typedef void (*func_t)();
    func_t func = (func_t)dlsym(lib, "pluginFunc");
    if (func) func();
    dlclose(lib);
}
