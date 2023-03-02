#include "directory.h"

static std::string WORKING_DIRECTORY;

void Directory::set(std::string wd) {
    WORKING_DIRECTORY = wd;
}

std::string Directory::get() {
    return WORKING_DIRECTORY;
}
