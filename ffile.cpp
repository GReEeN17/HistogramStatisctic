#include "ffile.h"
using std::ios;

Ffile::Ffile(string file_name)
{
    file.open(file_name, ios::binary);
    file.seekg (0, ios::end);
    size = file.tellg();
    file.seekg(0, ios::beg);
}

long long Ffile::getSize() const{
    return size;
}

unsigned char* Ffile::fread(long long size) {
    unsigned char* ptr = (unsigned char*) malloc(size);
    unsigned char byte;
    for (int i = 0; file.read((char*)&byte, sizeof(char)); i++) {
        ptr[i] = byte;
    }
    return ptr;
}

Ffile::~Ffile() {
    file.close();
}
