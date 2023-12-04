//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/linklayer/blemesh/BleMeshMacHeader.msg.
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
#include "BleMeshMacHeader_m.h"

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

Register_Class(BleMeshMacHeader)

BleMeshMacHeader::BleMeshMacHeader() : ::inet::FieldsChunk()
{
}

BleMeshMacHeader::BleMeshMacHeader(const BleMeshMacHeader& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

BleMeshMacHeader::~BleMeshMacHeader()
{
}

BleMeshMacHeader& BleMeshMacHeader::operator=(const BleMeshMacHeader& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void BleMeshMacHeader::copy(const BleMeshMacHeader& other)
{
    this->srcAddr = other.srcAddr;
    this->destAddr = other.destAddr;
    this->networkProtocol = other.networkProtocol;
    this->sequenceId = other.sequenceId;
}

void BleMeshMacHeader::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->srcAddr);
    doParsimPacking(b,this->destAddr);
    doParsimPacking(b,this->networkProtocol);
    doParsimPacking(b,this->sequenceId);
}

void BleMeshMacHeader::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->srcAddr);
    doParsimUnpacking(b,this->destAddr);
    doParsimUnpacking(b,this->networkProtocol);
    doParsimUnpacking(b,this->sequenceId);
}

const MacAddress& BleMeshMacHeader::getSrcAddr() const
{
    return this->srcAddr;
}

void BleMeshMacHeader::setSrcAddr(const MacAddress& srcAddr)
{
    handleChange();
    this->srcAddr = srcAddr;
}

const MacAddress& BleMeshMacHeader::getDestAddr() const
{
    return this->destAddr;
}

void BleMeshMacHeader::setDestAddr(const MacAddress& destAddr)
{
    handleChange();
    this->destAddr = destAddr;
}

int BleMeshMacHeader::getNetworkProtocol() const
{
    return this->networkProtocol;
}

void BleMeshMacHeader::setNetworkProtocol(int networkProtocol)
{
    handleChange();
    this->networkProtocol = networkProtocol;
}

long BleMeshMacHeader::getSequenceId() const
{
    return this->sequenceId;
}

void BleMeshMacHeader::setSequenceId(long sequenceId)
{
    handleChange();
    this->sequenceId = sequenceId;
}

class BleMeshMacHeaderDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_srcAddr,
        FIELD_destAddr,
        FIELD_networkProtocol,
        FIELD_sequenceId,
    };
  public:
    BleMeshMacHeaderDescriptor();
    virtual ~BleMeshMacHeaderDescriptor();

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

Register_ClassDescriptor(BleMeshMacHeaderDescriptor)

BleMeshMacHeaderDescriptor::BleMeshMacHeaderDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::BleMeshMacHeader)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

BleMeshMacHeaderDescriptor::~BleMeshMacHeaderDescriptor()
{
    delete[] propertyNames;
}

bool BleMeshMacHeaderDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BleMeshMacHeader *>(obj)!=nullptr;
}

const char **BleMeshMacHeaderDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *BleMeshMacHeaderDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int BleMeshMacHeaderDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int BleMeshMacHeaderDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_srcAddr
        0,    // FIELD_destAddr
        FD_ISEDITABLE,    // FIELD_networkProtocol
        FD_ISEDITABLE,    // FIELD_sequenceId
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *BleMeshMacHeaderDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "srcAddr",
        "destAddr",
        "networkProtocol",
        "sequenceId",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int BleMeshMacHeaderDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "srcAddr") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "destAddr") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "networkProtocol") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sequenceId") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *BleMeshMacHeaderDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::MacAddress",    // FIELD_srcAddr
        "inet::MacAddress",    // FIELD_destAddr
        "int",    // FIELD_networkProtocol
        "long",    // FIELD_sequenceId
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **BleMeshMacHeaderDescriptor::getFieldPropertyNames(int field) const
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

const char *BleMeshMacHeaderDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int BleMeshMacHeaderDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BleMeshMacHeaderDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BleMeshMacHeader'", field);
    }
}

const char *BleMeshMacHeaderDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BleMeshMacHeaderDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return pp->getSrcAddr().str();
        case FIELD_destAddr: return pp->getDestAddr().str();
        case FIELD_networkProtocol: return long2string(pp->getNetworkProtocol());
        case FIELD_sequenceId: return long2string(pp->getSequenceId());
        default: return "";
    }
}

void BleMeshMacHeaderDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_networkProtocol: pp->setNetworkProtocol(string2long(value)); break;
        case FIELD_sequenceId: pp->setSequenceId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BleMeshMacHeader'", field);
    }
}

omnetpp::cValue BleMeshMacHeaderDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return omnetpp::toAnyPtr(&pp->getSrcAddr()); break;
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        case FIELD_networkProtocol: return pp->getNetworkProtocol();
        case FIELD_sequenceId: return (omnetpp::intval_t)(pp->getSequenceId());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'BleMeshMacHeader' as cValue -- field index out of range?", field);
    }
}

void BleMeshMacHeaderDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_networkProtocol: pp->setNetworkProtocol(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sequenceId: pp->setSequenceId(omnetpp::checked_int_cast<long>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BleMeshMacHeader'", field);
    }
}

const char *BleMeshMacHeaderDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr BleMeshMacHeaderDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        case FIELD_srcAddr: return omnetpp::toAnyPtr(&pp->getSrcAddr()); break;
        case FIELD_destAddr: return omnetpp::toAnyPtr(&pp->getDestAddr()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void BleMeshMacHeaderDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    BleMeshMacHeader *pp = omnetpp::fromAnyPtr<BleMeshMacHeader>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BleMeshMacHeader'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

