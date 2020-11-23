#include "istream.h"

istream cin(stdin);

inline int8_t istream::get_char() {
    if(pos == len) {
        pos = 0;
        fgets(buf, S, stdin);
        while(buf[len] != '\0') len++;
    }
    if(pos == len)  return eof = true, -1;
    return buf[pos++];
}

istream& istream::operator >> (int8_t &x) {
    x = get_char();
    while(x < 33)   x = get_char();
    return *this;
}

istream& istream::operator >> (int16_t &x) {
    x = 0;
    int8_t c = get_char(), sign = 1;
    while(c < 33)   c = get_char();
    if(c == '-')    c = get_char(), sign = -1;
    for(; c > 32; c = get_char())   x = x * 10 + (int16_t) (c - 48);
    x *= sign;
    return *this;
}

istream& istream::operator >> (int32_t &x) {
    x = 0;
    int8_t c = get_char(), sign = 1;
    while(c < 33)   c = get_char();
    if(c == '-')    c = get_char(), sign = -1;
    for(; c > 32; c = get_char())   x = x * 10 + (int32_t) (c - 48);
    x *= sign;
    return *this;
}

istream& istream::operator >> (int64_t &x) {
    x = 0;
    int8_t c = get_char(), sign = 1;
    while(c < 33)   c = get_char();
    if(c == '-')    c = get_char(), sign = -1;
    for(; c > 32; c = get_char())   x = x * 10 + (int64_t) (c - 48);
    x *= sign;
    return *this;
}

istream& istream::operator >> (uint8_t &x) {
    x = (uint8_t) get_char();
    while(x < 33)   x = (uint8_t) get_char();
    return *this;
}

istream& istream::operator >> (uint16_t &x) {
    x = 0;
    int8_t c = get_char();
    while(c < 33)   c = get_char();
    for(; c > 32; c = get_char())   x = x * 10 + (uint16_t) (c - 48);
    return *this;
}

istream& istream::operator >> (uint32_t &x) {
    x = 0;
    int8_t c = get_char();
    while(c < 33)   c = get_char();
    for(; c > 32; c = get_char())   x = x * 10 + (uint32_t) (c - 48);
    return *this;
}

istream& istream::operator >> (uint64_t &x) {
    x = 0;
    int8_t c = get_char();
    while(c < 33)   c = get_char();
    for(; c > 32; c = get_char())   x = x * 10 + (uint64_t) (c - 48);
    return *this;
}
