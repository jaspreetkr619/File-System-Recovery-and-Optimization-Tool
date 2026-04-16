#include "File.h"

File::File(string name, int size) {
    this->name = name;
    this->size = size;
    this->content = "";
    this->isDeleted = false;
}

void File::write(string data) {
    content += data;
}

string File::read() const {
    return content;
}

string File::getName() const {
    return name;
}

int File::getSize() const {
    return size;
}

void File::setDeleted(bool status) {
    isDeleted = status;
}

bool File::getDeleted() const {
    return isDeleted;
}
