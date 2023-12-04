//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/applications/mamapp/BMeshPacket.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "BMeshPacket_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

Register_Class(BMeshPacket)

BMeshPacket::BMeshPacket() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(11));

}

BMeshPacket::BMeshPacket(const BMeshPacket& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

BMeshPacket::~BMeshPacket()
{
}

BMeshPacket& BMeshPacket::operator=(const BMeshPacket& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void BMeshPacket::copy(const BMeshPacket& other)
{
    this->ttl = other.ttl;
    this->hops = other.hops;
    this->srcUuid = other.srcUuid;
    this->packetUuid = other.packetUuid;
    this->sequence = other.sequence;
    this->creationTime = other.creationTime;
}

void BMeshPacket::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->hops);
    doParsimPacking(b,this->srcUuid);
    doParsimPacking(b,this->packetUuid);
    doParsimPacking(b,this->sequence);
    doParsimPacking(b,this->creationTime);
}

void BMeshPacket::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->hops);
    doParsimUnpacking(b,this->srcUuid);
    doParsimUnpacking(b,this->packetUuid);
    doParsimUnpacking(b,this->sequence);
    doParsimUnpacking(b,this->creationTime);
}

int BMeshPacket::getTtl() const
{
    return this->ttl;
}

void BMeshPacket::setTtl(int ttl)
{
    handleChange();
    this->ttl = ttl;
}

int BMeshPacket::getHops() const
{
    return this->hops;
}

void BMeshPacket::setHops(int hops)
{
    handleChange();
    this->hops = hops;
}

const char * BMeshPacket::getSrcUuid() const
{
    return this->srcUuid.c_str();
}

void BMeshPacket::setSrcUuid(const char * srcUuid)
{
    handleChange();
    this->srcUuid = srcUuid;
}

const char * BMeshPacket::getPacketUuid() const
{
    return this->packetUuid.c_str();
}

void BMeshPacket::setPacketUuid(const char * packetUuid)
{
    handleChange();
    this->packetUuid = packetUuid;
}

int BMeshPacket::getSequence() const
{
    return this->sequence;
}

void BMeshPacket::setSequence(int sequence)
{
    handleChange();
    this->sequence = sequence;
}

::omnetpp::simtime_t BMeshPacket::getCreationTime() const
{
    return this->creationTime;
}

void BMeshPacket::setCreationTime(::omnetpp::simtime_t creationTime)
{
    handleChange();
    this->creationTime = creationTime;
}

class BMeshPacketDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_ttl,
        FIELD_hops,
        FIELD_srcUuid,
        FIELD_packetUuid,
        FIELD_sequence,
        FIELD_creationTime,
    };
  public:
    BMeshPacketDescriptor();
    virtual ~BMeshPacketDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(BMeshPacketDescriptor)

BMeshPacketDescriptor::BMeshPacketDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BMeshPacket)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

BMeshPacketDescriptor::~BMeshPacketDescriptor()
{
    delete[] propertyNames;
}

bool BMeshPacketDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BMeshPacket *>(obj)!=nullptr;
}

const char **BMeshPacketDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *BMeshPacketDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int BMeshPacketDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int BMeshPacketDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_ttl
        FD_ISEDITABLE,    // FIELD_hops
        FD_ISEDITABLE,    // FIELD_srcUuid
        FD_ISEDITABLE,    // FIELD_packetUuid
        FD_ISEDITABLE,    // FIELD_sequence
        FD_ISEDITABLE,    // FIELD_creationTime
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *BMeshPacketDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "ttl",
        "hops",
        "srcUuid",
        "packetUuid",
        "sequence",
        "creationTime",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int BMeshPacketDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "ttl") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "hops") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "srcUuid") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "packetUuid") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "sequence") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "creationTime") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *BMeshPacketDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_ttl
        "int",    // FIELD_hops
        "string",    // FIELD_srcUuid
        "string",    // FIELD_packetUuid
        "int",    // FIELD_sequence
        "omnetpp::simtime_t",    // FIELD_creationTime
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **BMeshPacketDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BMeshPacketDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BMeshPacketDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BMeshPacketDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BMeshPacket'", field);
    }
}

const char *BMeshPacketDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BMeshPacketDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ttl: return long2string(pp->getTtl());
        case FIELD_hops: return long2string(pp->getHops());
        case FIELD_srcUuid: return oppstring2string(pp->getSrcUuid());
        case FIELD_packetUuid: return oppstring2string(pp->getPacketUuid());
        case FIELD_sequence: return long2string(pp->getSequence());
        case FIELD_creationTime: return simtime2string(pp->getCreationTime());
        default: return "";
    }
}

void BMeshPacketDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ttl: pp->setTtl(string2long(value)); break;
        case FIELD_hops: pp->setHops(string2long(value)); break;
        case FIELD_srcUuid: pp->setSrcUuid((value)); break;
        case FIELD_packetUuid: pp->setPacketUuid((value)); break;
        case FIELD_sequence: pp->setSequence(string2long(value)); break;
        case FIELD_creationTime: pp->setCreationTime(string2simtime(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BMeshPacket'", field);
    }
}

omnetpp::cValue BMeshPacketDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ttl: return pp->getTtl();
        case FIELD_hops: return pp->getHops();
        case FIELD_srcUuid: return pp->getSrcUuid();
        case FIELD_packetUuid: return pp->getPacketUuid();
        case FIELD_sequence: return pp->getSequence();
        case FIELD_creationTime: return pp->getCreationTime().dbl();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'BMeshPacket' as cValue -- field index out of range?", field);
    }
}

void BMeshPacketDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        case FIELD_ttl: pp->setTtl(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_hops: pp->setHops(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_srcUuid: pp->setSrcUuid(value.stringValue()); break;
        case FIELD_packetUuid: pp->setPacketUuid(value.stringValue()); break;
        case FIELD_sequence: pp->setSequence(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_creationTime: pp->setCreationTime(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BMeshPacket'", field);
    }
}

const char *BMeshPacketDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr BMeshPacketDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void BMeshPacketDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    BMeshPacket *pp = omnetpp::fromAnyPtr<BMeshPacket>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BMeshPacket'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

