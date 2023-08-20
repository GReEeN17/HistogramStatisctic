#ifndef FFILE_H
#define FFILE_H
#include <fstream>
#include <iostream>
using std::string, std::ifstream, std::streampos;


class Ffile
{
private:
    ifstream file;
    streampos size;
public:
    Ffile(string file_name);

    long long getSize() const;

    unsigned char* fread(long long size);

    ~Ffile();
};

#endif // FFILE_H
