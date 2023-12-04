//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/protocols/messages/internal/MobilityCommand.msg.
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
#include "MobilityCommand_m.h"

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

Register_Enum(gradys_simulations::MobilityCommandType, (gradys_simulations::MobilityCommandType::REVERSE, gradys_simulations::MobilityCommandType::GOTO_WAYPOINT, gradys_simulations::MobilityCommandType::GOTO_COORDS, gradys_simulations::MobilityCommandType::RETURN_TO_HOME, gradys_simulations::MobilityCommandType::IDLE_TIME, gradys_simulations::MobilityCommandType::RECHARGE, gradys_simulations::MobilityCommandType::FORCE_SHUTDOWN, gradys_simulations::MobilityCommandType::WAKE_UP));

Register_Class(MobilityCommand)

MobilityCommand::MobilityCommand(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

MobilityCommand::MobilityCommand(const MobilityCommand& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

MobilityCommand::~MobilityCommand()
{
}

MobilityCommand& MobilityCommand::operator=(const MobilityCommand& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void MobilityCommand::copy(const MobilityCommand& other)
{
    this->commandType = other.commandType;
    this->param1 = other.param1;
    this->param2 = other.param2;
    this->param3 = other.param3;
    this->param4 = other.param4;
    this->param5 = other.param5;
}

void MobilityCommand::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->commandType);
    doParsimPacking(b,this->param1);
    doParsimPacking(b,this->param2);
    doParsimPacking(b,this->param3);
    doParsimPacking(b,this->param4);
    doParsimPacking(b,this->param5);
}

void MobilityCommand::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->commandType);
    doParsimUnpacking(b,this->param1);
    doParsimUnpacking(b,this->param2);
    doParsimUnpacking(b,this->param3);
    doParsimUnpacking(b,this->param4);
    doParsimUnpacking(b,this->param5);
}

MobilityCommandType MobilityCommand::getCommandType() const
{
    return this->commandType;
}

void MobilityCommand::setCommandType(MobilityCommandType commandType)
{
    this->commandType = commandType;
}

double MobilityCommand::getParam1() const
{
    return this->param1;
}

void MobilityCommand::setParam1(double param1)
{
    this->param1 = param1;
}

double MobilityCommand::getParam2() const
{
    return this->param2;
}

void MobilityCommand::setParam2(double param2)
{
    this->param2 = param2;
}

double MobilityCommand::getParam3() const
{
    return this->param3;
}

void MobilityCommand::setParam3(double param3)
{
    this->param3 = param3;
}

double MobilityCommand::getParam4() const
{
    return this->param4;
}

void MobilityCommand::setParam4(double param4)
{
    this->param4 = param4;
}

double MobilityCommand::getParam5() const
{
    return this->param5;
}

void MobilityCommand::setParam5(double param5)
{
    this->param5 = param5;
}

class MobilityCommandDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_commandType,
        FIELD_param1,
        FIELD_param2,
        FIELD_param3,
        FIELD_param4,
        FIELD_param5,
    };
  public:
    MobilityCommandDescriptor();
    virtual ~MobilityCommandDescriptor();

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

Register_ClassDescriptor(MobilityCommandDescriptor)

MobilityCommandDescriptor::MobilityCommandDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(gradys_simulations::MobilityCommand)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

MobilityCommandDescriptor::~MobilityCommandDescriptor()
{
    delete[] propertyNames;
}

bool MobilityCommandDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MobilityCommand *>(obj)!=nullptr;
}

const char **MobilityCommandDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MobilityCommandDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MobilityCommandDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 6+base->getFieldCount() : 6;
}

unsigned int MobilityCommandDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        0,    // FIELD_commandType
        FD_ISEDITABLE,    // FIELD_param1
        FD_ISEDITABLE,    // FIELD_param2
        FD_ISEDITABLE,    // FIELD_param3
        FD_ISEDITABLE,    // FIELD_param4
        FD_ISEDITABLE,    // FIELD_param5
    };
    return (field >= 0 && field < 6) ? fieldTypeFlags[field] : 0;
}

const char *MobilityCommandDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "commandType",
        "param1",
        "param2",
        "param3",
        "param4",
        "param5",
    };
    return (field >= 0 && field < 6) ? fieldNames[field] : nullptr;
}

int MobilityCommandDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "commandType") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "param1") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "param2") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "param3") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "param4") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "param5") == 0) return baseIndex + 5;
    return base ? base->findField(fieldName) : -1;
}

const char *MobilityCommandDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "gradys_simulations::MobilityCommandType",    // FIELD_commandType
        "double",    // FIELD_param1
        "double",    // FIELD_param2
        "double",    // FIELD_param3
        "double",    // FIELD_param4
        "double",    // FIELD_param5
    };
    return (field >= 0 && field < 6) ? fieldTypeStrings[field] : nullptr;
}

const char **MobilityCommandDescriptor::getFieldPropertyNames(int field) const
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

const char *MobilityCommandDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_commandType:
            if (!strcmp(propertyName, "enum")) return "gradys_simulations::MobilityCommandType";
            return nullptr;
        default: return nullptr;
    }
}

int MobilityCommandDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void MobilityCommandDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MobilityCommand'", field);
    }
}

const char *MobilityCommandDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MobilityCommandDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        case FIELD_commandType: return enum2string(pp->getCommandType(), "gradys_simulations::MobilityCommandType");
        case FIELD_param1: return double2string(pp->getParam1());
        case FIELD_param2: return double2string(pp->getParam2());
        case FIELD_param3: return double2string(pp->getParam3());
        case FIELD_param4: return double2string(pp->getParam4());
        case FIELD_param5: return double2string(pp->getParam5());
        default: return "";
    }
}

void MobilityCommandDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        case FIELD_param1: pp->setParam1(string2double(value)); break;
        case FIELD_param2: pp->setParam2(string2double(value)); break;
        case FIELD_param3: pp->setParam3(string2double(value)); break;
        case FIELD_param4: pp->setParam4(string2double(value)); break;
        case FIELD_param5: pp->setParam5(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MobilityCommand'", field);
    }
}

omnetpp::cValue MobilityCommandDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        case FIELD_commandType: return static_cast<int>(pp->getCommandType());
        case FIELD_param1: return pp->getParam1();
        case FIELD_param2: return pp->getParam2();
        case FIELD_param3: return pp->getParam3();
        case FIELD_param4: return pp->getParam4();
        case FIELD_param5: return pp->getParam5();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MobilityCommand' as cValue -- field index out of range?", field);
    }
}

void MobilityCommandDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        case FIELD_param1: pp->setParam1(value.doubleValue()); break;
        case FIELD_param2: pp->setParam2(value.doubleValue()); break;
        case FIELD_param3: pp->setParam3(value.doubleValue()); break;
        case FIELD_param4: pp->setParam4(value.doubleValue()); break;
        case FIELD_param5: pp->setParam5(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MobilityCommand'", field);
    }
}

const char *MobilityCommandDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MobilityCommandDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MobilityCommandDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MobilityCommand *pp = omnetpp::fromAnyPtr<MobilityCommand>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MobilityCommand'", field);
    }
}

}  // namespace gradys_simulations

namespace omnetpp {

}  // namespace omnetpp

