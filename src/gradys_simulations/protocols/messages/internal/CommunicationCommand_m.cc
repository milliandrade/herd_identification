//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/protocols/messages/internal/CommunicationCommand.msg.
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
#include "CommunicationCommand_m.h"

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

namespace gradys_simulations {

Register_Enum(gradys_simulations::CommunicationCommandType, (gradys_simulations::CommunicationCommandType::SET_PAYLOAD, gradys_simulations::CommunicationCommandType::SET_TARGET, gradys_simulations::CommunicationCommandType::SEND_MESSAGE));

Register_Class(CommunicationCommand)

CommunicationCommand::CommunicationCommand(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

CommunicationCommand::CommunicationCommand(const CommunicationCommand& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

CommunicationCommand::~CommunicationCommand()
{
}

CommunicationCommand& CommunicationCommand::operator=(const CommunicationCommand& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void CommunicationCommand::copy(const CommunicationCommand& other)
{
    this->commandType = other.commandType;
    this->payloadTemplate = other.payloadTemplate;
    this->target = other.target;
}

void CommunicationCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->commandType);
    doParsimPacking(b,this->payloadTemplate);
    doParsimPacking(b,this->target);
}

void CommunicationCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->commandType);
    doParsimUnpacking(b,this->payloadTemplate);
    doParsimUnpacking(b,this->target);
}

CommunicationCommandType CommunicationCommand::getCommandType() const
{
    return this->commandType;
}

void CommunicationCommand::setCommandType(CommunicationCommandType commandType)
{
    this->commandType = commandType;
}

const ::inet::FieldsChunk * CommunicationCommand::getPayloadTemplate() const
{
    return this->payloadTemplate;
}

void CommunicationCommand::setPayloadTemplate(::inet::FieldsChunk * payloadTemplate)
{
    this->payloadTemplate = payloadTemplate;
}

const char * CommunicationCommand::getTarget() const
{
    return this->target.c_str();
}

void CommunicationCommand::setTarget(const char * target)
{
    this->target = target;
}

class CommunicationCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_commandType,
        FIELD_payloadTemplate,
        FIELD_target,
    };
  public:
    CommunicationCommandDescriptor();
    virtual ~CommunicationCommandDescriptor();

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

Register_ClassDescriptor(CommunicationCommandDescriptor)

CommunicationCommandDescriptor::CommunicationCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(gradys_simulations::CommunicationCommand)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

CommunicationCommandDescriptor::~CommunicationCommandDescriptor()
{
    delete[] propertyNames;
}

bool CommunicationCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CommunicationCommand *>(obj)!=nullptr;
}

const char **CommunicationCommandDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CommunicationCommandDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CommunicationCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int CommunicationCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_commandType
        FD_ISCOMPOUND | FD_ISPOINTER | FD_ISCOBJECT | FD_ISREPLACEABLE,    // FIELD_payloadTemplate
        FD_ISEDITABLE,    // FIELD_target
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *CommunicationCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "commandType",
        "payloadTemplate",
        "target",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int CommunicationCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "commandType") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "payloadTemplate") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "target") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *CommunicationCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "gradys_simulations::CommunicationCommandType",    // FIELD_commandType
        "inet::FieldsChunk",    // FIELD_payloadTemplate
        "string",    // FIELD_target
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **CommunicationCommandDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_commandType: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *CommunicationCommandDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_commandType:
            if (!strcmp(propertyName, "enum")) return "gradys_simulations::CommunicationCommandType";
            return nullptr;
        default: return nullptr;
    }
}

int CommunicationCommandDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CommunicationCommandDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CommunicationCommand'", field);
    }
}

const char *CommunicationCommandDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        case FIELD_payloadTemplate: { const ::inet::FieldsChunk * value = pp->getPayloadTemplate(); return omnetpp::opp_typename(typeid(*value)); }
        default: return nullptr;
    }
}

std::string CommunicationCommandDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        case FIELD_commandType: return enum2string(pp->getCommandType(), "gradys_simulations::CommunicationCommandType");
        case FIELD_payloadTemplate: { auto obj = pp->getPayloadTemplate(); return obj == nullptr ? "" : obj->str(); }
        case FIELD_target: return oppstring2string(pp->getTarget());
        default: return "";
    }
}

void CommunicationCommandDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        case FIELD_target: pp->setTarget((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CommunicationCommand'", field);
    }
}

omnetpp::cValue CommunicationCommandDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        case FIELD_commandType: return static_cast<int>(pp->getCommandType());
        case FIELD_payloadTemplate: return omnetpp::toAnyPtr(pp->getPayloadTemplate()); break;
        case FIELD_target: return pp->getTarget();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CommunicationCommand' as cValue -- field index out of range?", field);
    }
}

void CommunicationCommandDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        case FIELD_payloadTemplate: pp->setPayloadTemplate(omnetpp::fromAnyPtr<::inet::FieldsChunk>(value.pointerValue())); break;
        case FIELD_target: pp->setTarget(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CommunicationCommand'", field);
    }
}

const char *CommunicationCommandDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_payloadTemplate: return omnetpp::opp_typename(typeid(::inet::FieldsChunk));
        default: return nullptr;
    };
}

omnetpp::any_ptr CommunicationCommandDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        case FIELD_payloadTemplate: return omnetpp::toAnyPtr(pp->getPayloadTemplate()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CommunicationCommandDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CommunicationCommand *pp = omnetpp::fromAnyPtr<CommunicationCommand>(object); (void)pp;
    switch (field) {
        case FIELD_payloadTemplate: pp->setPayloadTemplate(omnetpp::fromAnyPtr<::inet::FieldsChunk>(ptr)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CommunicationCommand'", field);
    }
}

}  // namespace gradys_simulations

namespace omnetpp {

}  // namespace omnetpp

