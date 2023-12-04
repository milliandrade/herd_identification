//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/protocols/messages/internal/Telemetry.msg.
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
#include "Telemetry_m.h"

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

Register_Enum(gradys_simulations::DroneActivity, (gradys_simulations::DroneActivity::IDLE, gradys_simulations::DroneActivity::NAVIGATING, gradys_simulations::DroneActivity::REACHED_EDGE, gradys_simulations::DroneActivity::FOLLOWING_COMMAND, gradys_simulations::DroneActivity::RECHARGING, gradys_simulations::DroneActivity::SHUTDOWN));

Register_Class(Telemetry)

Telemetry::Telemetry(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

Telemetry::Telemetry(const Telemetry& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

Telemetry::~Telemetry()
{
}

Telemetry& Telemetry::operator=(const Telemetry& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void Telemetry::copy(const Telemetry& other)
{
    this->nextWaypointID = other.nextWaypointID;
    this->lastWaypointID = other.lastWaypointID;
    this->currentCommand = other.currentCommand;
    this->currentX = other.currentX;
    this->currentY = other.currentY;
    this->currentZ = other.currentZ;
    this->currentLat = other.currentLat;
    this->currentLon = other.currentLon;
    this->currentAlt = other.currentAlt;
    this->isReversed_ = other.isReversed_;
    this->droneActivity = other.droneActivity;
}

void Telemetry::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->nextWaypointID);
    doParsimPacking(b,this->lastWaypointID);
    doParsimPacking(b,this->currentCommand);
    doParsimPacking(b,this->currentX);
    doParsimPacking(b,this->currentY);
    doParsimPacking(b,this->currentZ);
    doParsimPacking(b,this->currentLat);
    doParsimPacking(b,this->currentLon);
    doParsimPacking(b,this->currentAlt);
    doParsimPacking(b,this->isReversed_);
    doParsimPacking(b,this->droneActivity);
}

void Telemetry::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->nextWaypointID);
    doParsimUnpacking(b,this->lastWaypointID);
    doParsimUnpacking(b,this->currentCommand);
    doParsimUnpacking(b,this->currentX);
    doParsimUnpacking(b,this->currentY);
    doParsimUnpacking(b,this->currentZ);
    doParsimUnpacking(b,this->currentLat);
    doParsimUnpacking(b,this->currentLon);
    doParsimUnpacking(b,this->currentAlt);
    doParsimUnpacking(b,this->isReversed_);
    doParsimUnpacking(b,this->droneActivity);
}

int Telemetry::getNextWaypointID() const
{
    return this->nextWaypointID;
}

void Telemetry::setNextWaypointID(int nextWaypointID)
{
    this->nextWaypointID = nextWaypointID;
}

int Telemetry::getLastWaypointID() const
{
    return this->lastWaypointID;
}

void Telemetry::setLastWaypointID(int lastWaypointID)
{
    this->lastWaypointID = lastWaypointID;
}

int Telemetry::getCurrentCommand() const
{
    return this->currentCommand;
}

void Telemetry::setCurrentCommand(int currentCommand)
{
    this->currentCommand = currentCommand;
}

double Telemetry::getCurrentX() const
{
    return this->currentX;
}

void Telemetry::setCurrentX(double currentX)
{
    this->currentX = currentX;
}

double Telemetry::getCurrentY() const
{
    return this->currentY;
}

void Telemetry::setCurrentY(double currentY)
{
    this->currentY = currentY;
}

double Telemetry::getCurrentZ() const
{
    return this->currentZ;
}

void Telemetry::setCurrentZ(double currentZ)
{
    this->currentZ = currentZ;
}

double Telemetry::getCurrentLat() const
{
    return this->currentLat;
}

void Telemetry::setCurrentLat(double currentLat)
{
    this->currentLat = currentLat;
}

double Telemetry::getCurrentLon() const
{
    return this->currentLon;
}

void Telemetry::setCurrentLon(double currentLon)
{
    this->currentLon = currentLon;
}

double Telemetry::getCurrentAlt() const
{
    return this->currentAlt;
}

void Telemetry::setCurrentAlt(double currentAlt)
{
    this->currentAlt = currentAlt;
}

bool Telemetry::isReversed() const
{
    return this->isReversed_;
}

void Telemetry::setIsReversed(bool isReversed)
{
    this->isReversed_ = isReversed;
}

DroneActivity Telemetry::getDroneActivity() const
{
    return this->droneActivity;
}

void Telemetry::setDroneActivity(DroneActivity droneActivity)
{
    this->droneActivity = droneActivity;
}

class TelemetryDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_nextWaypointID,
        FIELD_lastWaypointID,
        FIELD_currentCommand,
        FIELD_currentX,
        FIELD_currentY,
        FIELD_currentZ,
        FIELD_currentLat,
        FIELD_currentLon,
        FIELD_currentAlt,
        FIELD_isReversed,
        FIELD_droneActivity,
    };
  public:
    TelemetryDescriptor();
    virtual ~TelemetryDescriptor();

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

Register_ClassDescriptor(TelemetryDescriptor)

TelemetryDescriptor::TelemetryDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(gradys_simulations::Telemetry)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TelemetryDescriptor::~TelemetryDescriptor()
{
    delete[] propertyNames;
}

bool TelemetryDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<Telemetry *>(obj)!=nullptr;
}

const char **TelemetryDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TelemetryDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TelemetryDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 11+base->getFieldCount() : 11;
}

unsigned int TelemetryDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_nextWaypointID
        FD_ISEDITABLE,    // FIELD_lastWaypointID
        FD_ISEDITABLE,    // FIELD_currentCommand
        FD_ISEDITABLE,    // FIELD_currentX
        FD_ISEDITABLE,    // FIELD_currentY
        FD_ISEDITABLE,    // FIELD_currentZ
        FD_ISEDITABLE,    // FIELD_currentLat
        FD_ISEDITABLE,    // FIELD_currentLon
        FD_ISEDITABLE,    // FIELD_currentAlt
        FD_ISEDITABLE,    // FIELD_isReversed
        0,    // FIELD_droneActivity
    };
    return (field >= 0 && field < 11) ? fieldTypeFlags[field] : 0;
}

const char *TelemetryDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "nextWaypointID",
        "lastWaypointID",
        "currentCommand",
        "currentX",
        "currentY",
        "currentZ",
        "currentLat",
        "currentLon",
        "currentAlt",
        "isReversed",
        "droneActivity",
    };
    return (field >= 0 && field < 11) ? fieldNames[field] : nullptr;
}

int TelemetryDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "nextWaypointID") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "lastWaypointID") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "currentCommand") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "currentX") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "currentY") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "currentZ") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "currentLat") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "currentLon") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "currentAlt") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "isReversed") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "droneActivity") == 0) return baseIndex + 10;
    return base ? base->findField(fieldName) : -1;
}

const char *TelemetryDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_nextWaypointID
        "int",    // FIELD_lastWaypointID
        "int",    // FIELD_currentCommand
        "double",    // FIELD_currentX
        "double",    // FIELD_currentY
        "double",    // FIELD_currentZ
        "double",    // FIELD_currentLat
        "double",    // FIELD_currentLon
        "double",    // FIELD_currentAlt
        "bool",    // FIELD_isReversed
        "gradys_simulations::DroneActivity",    // FIELD_droneActivity
    };
    return (field >= 0 && field < 11) ? fieldTypeStrings[field] : nullptr;
}

const char **TelemetryDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_droneActivity: {
            static const char *names[] = { "enum",  nullptr };
            return names;
        }
        default: return nullptr;
    }
}

const char *TelemetryDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_droneActivity:
            if (!strcmp(propertyName, "enum")) return "gradys_simulations::DroneActivity";
            return nullptr;
        default: return nullptr;
    }
}

int TelemetryDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TelemetryDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'Telemetry'", field);
    }
}

const char *TelemetryDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TelemetryDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        case FIELD_nextWaypointID: return long2string(pp->getNextWaypointID());
        case FIELD_lastWaypointID: return long2string(pp->getLastWaypointID());
        case FIELD_currentCommand: return long2string(pp->getCurrentCommand());
        case FIELD_currentX: return double2string(pp->getCurrentX());
        case FIELD_currentY: return double2string(pp->getCurrentY());
        case FIELD_currentZ: return double2string(pp->getCurrentZ());
        case FIELD_currentLat: return double2string(pp->getCurrentLat());
        case FIELD_currentLon: return double2string(pp->getCurrentLon());
        case FIELD_currentAlt: return double2string(pp->getCurrentAlt());
        case FIELD_isReversed: return bool2string(pp->isReversed());
        case FIELD_droneActivity: return enum2string(pp->getDroneActivity(), "gradys_simulations::DroneActivity");
        default: return "";
    }
}

void TelemetryDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        case FIELD_nextWaypointID: pp->setNextWaypointID(string2long(value)); break;
        case FIELD_lastWaypointID: pp->setLastWaypointID(string2long(value)); break;
        case FIELD_currentCommand: pp->setCurrentCommand(string2long(value)); break;
        case FIELD_currentX: pp->setCurrentX(string2double(value)); break;
        case FIELD_currentY: pp->setCurrentY(string2double(value)); break;
        case FIELD_currentZ: pp->setCurrentZ(string2double(value)); break;
        case FIELD_currentLat: pp->setCurrentLat(string2double(value)); break;
        case FIELD_currentLon: pp->setCurrentLon(string2double(value)); break;
        case FIELD_currentAlt: pp->setCurrentAlt(string2double(value)); break;
        case FIELD_isReversed: pp->setIsReversed(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Telemetry'", field);
    }
}

omnetpp::cValue TelemetryDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        case FIELD_nextWaypointID: return pp->getNextWaypointID();
        case FIELD_lastWaypointID: return pp->getLastWaypointID();
        case FIELD_currentCommand: return pp->getCurrentCommand();
        case FIELD_currentX: return pp->getCurrentX();
        case FIELD_currentY: return pp->getCurrentY();
        case FIELD_currentZ: return pp->getCurrentZ();
        case FIELD_currentLat: return pp->getCurrentLat();
        case FIELD_currentLon: return pp->getCurrentLon();
        case FIELD_currentAlt: return pp->getCurrentAlt();
        case FIELD_isReversed: return pp->isReversed();
        case FIELD_droneActivity: return static_cast<int>(pp->getDroneActivity());
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'Telemetry' as cValue -- field index out of range?", field);
    }
}

void TelemetryDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        case FIELD_nextWaypointID: pp->setNextWaypointID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_lastWaypointID: pp->setLastWaypointID(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_currentCommand: pp->setCurrentCommand(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_currentX: pp->setCurrentX(value.doubleValue()); break;
        case FIELD_currentY: pp->setCurrentY(value.doubleValue()); break;
        case FIELD_currentZ: pp->setCurrentZ(value.doubleValue()); break;
        case FIELD_currentLat: pp->setCurrentLat(value.doubleValue()); break;
        case FIELD_currentLon: pp->setCurrentLon(value.doubleValue()); break;
        case FIELD_currentAlt: pp->setCurrentAlt(value.doubleValue()); break;
        case FIELD_isReversed: pp->setIsReversed(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Telemetry'", field);
    }
}

const char *TelemetryDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr TelemetryDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TelemetryDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    Telemetry *pp = omnetpp::fromAnyPtr<Telemetry>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'Telemetry'", field);
    }
}

}  // namespace gradys_simulations

namespace omnetpp {

}  // namespace omnetpp

