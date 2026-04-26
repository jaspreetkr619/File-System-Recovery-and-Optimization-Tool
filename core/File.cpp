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
string File::readSequential() const {
    return content;
}

char File::readAt(int position) const {
    if (position >= 0 && position < content.length()) {
        return content[position];
    }
    return '\0';
}

string File::readRange(int start, int length) const {
    if (start >= 0 && start < content.length()) {
        return content.substr(start, length);
    }
    return "";
}