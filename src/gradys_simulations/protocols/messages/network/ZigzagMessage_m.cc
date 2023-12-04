//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/protocols/messages/network/ZigzagMessage.msg.
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
#include "ZigzagMessage_m.h"

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

Register_Enum(inet::ZigzagMessageType, (inet::ZigzagMessageType::HEARTBEAT, inet::ZigzagMessageType::PAIR_REQUEST, inet::ZigzagMessageType::PAIR_CONFIRM, inet::ZigzagMessageType::BEARER));

Register_Class(ZigzagMessage)

ZigzagMessage::ZigzagMessage() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(14));

}

ZigzagMessage::ZigzagMessage(const ZigzagMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

ZigzagMessage::~ZigzagMessage()
{
}

ZigzagMessage& ZigzagMessage::operator=(const ZigzagMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void ZigzagMessage::copy(const ZigzagMessage& other)
{
    this->sourceID = other.sourceID;
    this->destinationID = other.destinationID;
    this->nextWaypointID = other.nextWaypointID;
    this->lastWaypointID = other.lastWaypointID;
    this->dataLength = other.dataLength;
    this->reversed = other.reversed;
    this->messageType = other.messageType;
}

void ZigzagMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->sourceID);
    doParsimPacking(b,this->destinationID);
    doParsimPacking(b,this->nextWaypointID);
    doParsimPacking(b,this->lastWaypointID);
    doParsimPacking(b,this->dataLength);
    doParsimPacking(b,this->reversed);
    doParsimPacking(b,this->messageType);
}

void ZigzagMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->sourceID);
    doParsimUnpacking(b,this->destinationID);
    doParsimUnpacking(b,this->nextWaypointID);
    doParsimUnpacking(b,this->lastWaypointID);
    doParsimUnpacking(b,this->dataLength);
    doParsimUnpacking(b,this->reversed);
    doParsimUnpacking(b,this->messageType);
}

int ZigzagMessage::getSourceID() const
{
    return this->sourceID;
}

void ZigzagMessage::setSourceID(int sourceID)
{
    handleChange();
    this->sourceID = sourceID;
}

int ZigzagMessage::getDestinationID() const
{
    return this->destinationID;
}

void ZigzagMessage::setDestinationID(int destinationID)
{
    handleChange();
    this->destinationID = destinationID;
}

int ZigzagMessage::getNextWaypointID() const
{
    return this->nextWaypointID;
}

void ZigzagMessage::setNextWaypointID(int nextWaypointID)
{
    handleChange();
    this->nextWaypointID = nextWaypointID;
}

int ZigzagMessage::getLastWaypointID() const
{
    return this->lastWaypointID;
}

void ZigzagMessage::setLastWaypointID(int lastWaypointID)
{
    handleChange();
    this->lastWaypointID = lastWaypointID;
}

int ZigzagMessage::getDataLength() const
{
    return this->dataLength;
}

void ZigzagMessage::setDataLength(int dataLength)
{
    handleChange();
    this->dataLength = dataLength;
}

bool ZigzagMessage::getReversed() const
{
    return this->reversed;
}

void ZigzagMessage::setReversed(bool reversed)
{
    handleChange();
    this->reversed = reversed;
}

ZigzagMessageType ZigzagMessage::getMessageType() const
{
    return this->messageType;
}

void ZigzagMessage::setMessageType(ZigzagMessageType messageType)
{
    handleChange();
    this->messageType = messageType;
}

class ZigzagMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_sourceID,
        FIELD_destinationID,
        FIELD_nextWaypointID,
        FIELD_lastWaypointID,
        FIELD_dataLength,
        FIELD_reversed,
        FIELD_messageType,
    };
  public:
    ZigzagMessageDescriptor();
    virtual ~ZigzagMessageDescriptor();

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

Register_ClassDescriptor(ZigzagMessageDescriptor)

ZigzagMessageDescriptor::ZigzagMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::ZigzagMessage)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

ZigzagMessageDescriptor::~ZigzagMessageDescriptor()
{
    delete[] propertyNames;
}

bool ZigzagMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ZigzagMessage *>(obj)!=nullptr;
}

const char **ZigzagMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ZigzagMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ZigzagMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int ZigzagMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_sourceID
        FD_ISEDITABLE,    // FIELD_destinationID
        FD_ISEDITABLE,    // FIELD_nextWaypointID
        FD_ISEDITABLE,    // FIELD_lastWaypointID
        FD_ISEDITABLE,    // FIELD_dataLength
        FD_ISEDITABLE,    // FIELD_reversed
        0,    // FIELD_messageType
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *ZigzagMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sourceID",
        "destinationID",
        "nextWaypointID",
        "lastWaypointID",
        "dataLength",
        "reversed",
        "messageType",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int ZigzagMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "sourceID") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "destinationID") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "nextWaypointID") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "lastWaypointID") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "dataLength") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "reversed") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "messageType") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *ZigzagMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_sourceID
        "int",    // FIELD_destinationID
        "int",    // FIELD_nextWaypointID
        "int",    // FIELD_lastWaypointID
        "int",    // FIELD_dataLength
        "bool",    // FIELD_reversed
        "inet::ZigzagMessageType",    // FIELD_messageType
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **ZigzagMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_messageType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *ZigzagMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_messageType:
            if (!strcmp(propertyName, "enum")) return "inet::ZigzagMessageType";
            return nullptr;
        default: return nullptr;
    }
}

int ZigzagMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ZigzagMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ZigzagMessage'", field);
    }
}

const char *ZigzagMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ZigzagMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sourceID: return long2string(pp->getSourceID());
        case FIELD_destinationID: return long2string(pp->getDestinationID());
        case FIELD_nextWaypointID: return long2string(pp->getNextWaypointID());
        case FIELD_lastWaypointID: return long2string(pp->getLastWaypointID());
        case FIELD_dataLength: return long2string(pp->getDataLength());
        case FIELD_reversed: return bool2string(pp->getReversed());
        case FIELD_messageType: return enum2string(pp->getMessageType(), "inet::ZigzagMessageType");
        default: return "";
    }
}

void ZigzagMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sourceID: pp->setSourceID(string2long(value)); break;
        case FIELD_destinationID: pp->setDestinationID(string2long(value)); break;
        case FIELD_nextWaypointID: pp->setNextWaypointID(string2long(value)); break;
        case FIELD_lastWaypointID: pp->setLastWaypointID(string2long(value)); break;
        case FIELD_dataLength: pp->setDataLength(string2long(value)); break;
        case FIELD_reversed: pp->setReversed(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ZigzagMessage'", field);
    }
}

omnetpp::cValue ZigzagMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sourceID: return pp->getSourceID();
        case FIELD_destinationID: return pp->getDestinationID();
        case FIELD_nextWaypointID: return pp->getNextWaypointID();
        case FIELD_lastWaypointID: return pp->getLastWaypointID();
        case FIELD_dataLength: return pp->getDataLength();
        case FIELD_reversed: return pp->getReversed();
        case FIELD_messageType: return static_cast<int>(pp->getMessageType());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ZigzagMessage' as cValue -- field index out of range?", field);
    }
}

void ZigzagMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        case FIELD_sourceID: pp->setSourceID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationID: pp->setDestinationID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_nextWaypointID: pp->setNextWaypointID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_lastWaypointID: pp->setLastWaypointID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dataLength: pp->setDataLength(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_reversed: pp->setReversed(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ZigzagMessage'", field);
    }
}

const char *ZigzagMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr ZigzagMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ZigzagMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ZigzagMessage *pp = omnetpp::fromAnyPtr<ZigzagMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ZigzagMessage'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

