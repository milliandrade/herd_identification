//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/protocols/messages/network/CentralizedQMessage.msg.
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
#include "CentralizedQMessage_m.h"

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

Register_Enum(inet::NodeType, (inet::NodeType::AGENT, inet::NodeType::PASSIVE, inet::NodeType::ALL));

Register_Enum(inet::MessageType, (inet::MessageType::SHARE, inet::MessageType::ACK, inet::MessageType::REQUEST));

Register_Class(CentralizedQMessage)

CentralizedQMessage::CentralizedQMessage() : ::inet::FieldsChunk()
{
    this->setChunkLength(B(15));

}

CentralizedQMessage::CentralizedQMessage(const CentralizedQMessage& other) : ::inet::FieldsChunk(other)
{
    copy(other);
}

CentralizedQMessage::~CentralizedQMessage()
{
}

CentralizedQMessage& CentralizedQMessage::operator=(const CentralizedQMessage& other)
{
    if (this == &other) return *this;
    ::inet::FieldsChunk::operator=(other);
    copy(other);
    return *this;
}

void CentralizedQMessage::copy(const CentralizedQMessage& other)
{
    this->nodeType = other.nodeType;
    this->messageType = other.messageType;
    this->nodeId = other.nodeId;
    this->targetId = other.targetId;
    this->targetNodeType = other.targetNodeType;
    this->packetLoad = other.packetLoad;
    this->nodePosition = other.nodePosition;
}

void CentralizedQMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::inet::FieldsChunk::parsimPack(b);
    doParsimPacking(b,this->nodeType);
    doParsimPacking(b,this->messageType);
    doParsimPacking(b,this->nodeId);
    doParsimPacking(b,this->targetId);
    doParsimPacking(b,this->targetNodeType);
    doParsimPacking(b,this->packetLoad);
    doParsimPacking(b,this->nodePosition);
}

void CentralizedQMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::inet::FieldsChunk::parsimUnpack(b);
    doParsimUnpacking(b,this->nodeType);
    doParsimUnpacking(b,this->messageType);
    doParsimUnpacking(b,this->nodeId);
    doParsimUnpacking(b,this->targetId);
    doParsimUnpacking(b,this->targetNodeType);
    doParsimUnpacking(b,this->packetLoad);
    doParsimUnpacking(b,this->nodePosition);
}

NodeType CentralizedQMessage::getNodeType() const
{
    return this->nodeType;
}

void CentralizedQMessage::setNodeType(NodeType nodeType)
{
    handleChange();
    this->nodeType = nodeType;
}

MessageType CentralizedQMessage::getMessageType() const
{
    return this->messageType;
}

void CentralizedQMessage::setMessageType(MessageType messageType)
{
    handleChange();
    this->messageType = messageType;
}

int CentralizedQMessage::getNodeId() const
{
    return this->nodeId;
}

void CentralizedQMessage::setNodeId(int nodeId)
{
    handleChange();
    this->nodeId = nodeId;
}

int CentralizedQMessage::getTargetId() const
{
    return this->targetId;
}

void CentralizedQMessage::setTargetId(int targetId)
{
    handleChange();
    this->targetId = targetId;
}

NodeType CentralizedQMessage::getTargetNodeType() const
{
    return this->targetNodeType;
}

void CentralizedQMessage::setTargetNodeType(NodeType targetNodeType)
{
    handleChange();
    this->targetNodeType = targetNodeType;
}

int CentralizedQMessage::getPacketLoad() const
{
    return this->packetLoad;
}

void CentralizedQMessage::setPacketLoad(int packetLoad)
{
    handleChange();
    this->packetLoad = packetLoad;
}

double CentralizedQMessage::getNodePosition() const
{
    return this->nodePosition;
}

void CentralizedQMessage::setNodePosition(double nodePosition)
{
    handleChange();
    this->nodePosition = nodePosition;
}

class CentralizedQMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_nodeType,
        FIELD_messageType,
        FIELD_nodeId,
        FIELD_targetId,
        FIELD_targetNodeType,
        FIELD_packetLoad,
        FIELD_nodePosition,
    };
  public:
    CentralizedQMessageDescriptor();
    virtual ~CentralizedQMessageDescriptor();

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

Register_ClassDescriptor(CentralizedQMessageDescriptor)

CentralizedQMessageDescriptor::CentralizedQMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(inet::CentralizedQMessage)), "inet::FieldsChunk")
{
    propertyNames = nullptr;
}

CentralizedQMessageDescriptor::~CentralizedQMessageDescriptor()
{
    delete[] propertyNames;
}

bool CentralizedQMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CentralizedQMessage *>(obj)!=nullptr;
}

const char **CentralizedQMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CentralizedQMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CentralizedQMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int CentralizedQMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_nodeType
        0,    // FIELD_messageType
        FD_ISEDITABLE,    // FIELD_nodeId
        FD_ISEDITABLE,    // FIELD_targetId
        0,    // FIELD_targetNodeType
        FD_ISEDITABLE,    // FIELD_packetLoad
        FD_ISEDITABLE,    // FIELD_nodePosition
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *CentralizedQMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nodeType",
        "messageType",
        "nodeId",
        "targetId",
        "targetNodeType",
        "packetLoad",
        "nodePosition",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int CentralizedQMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "nodeType") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "messageType") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "nodeId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "targetId") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "targetNodeType") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "packetLoad") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "nodePosition") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *CentralizedQMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "inet::NodeType",    // FIELD_nodeType
        "inet::MessageType",    // FIELD_messageType
        "int",    // FIELD_nodeId
        "int",    // FIELD_targetId
        "inet::NodeType",    // FIELD_targetNodeType
        "int",    // FIELD_packetLoad
        "double",    // FIELD_nodePosition
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **CentralizedQMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_nodeType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_messageType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        case FIELD_targetNodeType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CentralizedQMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_nodeType:
            if (!strcmp(propertyName, "enum")) return "inet::NodeType";
            return nullptr;
        case FIELD_messageType:
            if (!strcmp(propertyName, "enum")) return "inet::MessageType";
            return nullptr;
        case FIELD_targetNodeType:
            if (!strcmp(propertyName, "enum")) return "inet::NodeType";
            return nullptr;
        default: return nullptr;
    }
}

int CentralizedQMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CentralizedQMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CentralizedQMessage'", field);
    }
}

const char *CentralizedQMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CentralizedQMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        case FIELD_nodeType: return enum2string(pp->getNodeType(), "inet::NodeType");
        case FIELD_messageType: return enum2string(pp->getMessageType(), "inet::MessageType");
        case FIELD_nodeId: return long2string(pp->getNodeId());
        case FIELD_targetId: return long2string(pp->getTargetId());
        case FIELD_targetNodeType: return enum2string(pp->getTargetNodeType(), "inet::NodeType");
        case FIELD_packetLoad: return long2string(pp->getPacketLoad());
        case FIELD_nodePosition: return double2string(pp->getNodePosition());
        default: return "";
    }
}

void CentralizedQMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        case FIELD_nodeId: pp->setNodeId(string2long(value)); break;
        case FIELD_targetId: pp->setTargetId(string2long(value)); break;
        case FIELD_packetLoad: pp->setPacketLoad(string2long(value)); break;
        case FIELD_nodePosition: pp->setNodePosition(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CentralizedQMessage'", field);
    }
}

omnetpp::cValue CentralizedQMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        case FIELD_nodeType: return static_cast<int>(pp->getNodeType());
        case FIELD_messageType: return static_cast<int>(pp->getMessageType());
        case FIELD_nodeId: return pp->getNodeId();
        case FIELD_targetId: return pp->getTargetId();
        case FIELD_targetNodeType: return static_cast<int>(pp->getTargetNodeType());
        case FIELD_packetLoad: return pp->getPacketLoad();
        case FIELD_nodePosition: return pp->getNodePosition();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CentralizedQMessage' as cValue -- field index out of range?", field);
    }
}

void CentralizedQMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        case FIELD_nodeId: pp->setNodeId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_targetId: pp->setTargetId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_packetLoad: pp->setPacketLoad(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_nodePosition: pp->setNodePosition(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CentralizedQMessage'", field);
    }
}

const char *CentralizedQMessageDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr CentralizedQMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CentralizedQMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CentralizedQMessage *pp = omnetpp::fromAnyPtr<CentralizedQMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CentralizedQMessage'", field);
    }
}

}  // namespace inet

namespace omnetpp {

}  // namespace omnetpp

