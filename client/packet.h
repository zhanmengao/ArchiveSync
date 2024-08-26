#ifndef PACKET_H
#define PACKET_H

#include<string>
#include<QErrorMessage>

class Marshal{
public:
    virtual std::string SerializeAsString() = 0;
};

class Unmarshal{
public:
    virtual bool ParseFromArray(const void* data, int size) = 0;
};

typedef bool(*handle)(Unmarshal*);
class packet
{
public:
    virtual Unmarshal* GetResponse() = 0;
    virtual bool Handle(Unmarshal* req) = 0;
};

#endif // PACKET_H
