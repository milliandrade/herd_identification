//
// Generated file, do not edit! Created by opp_msgtool 6.0 from gradys_simulations/protocols/messages/internal/Telemetry.msg.
//

#ifndef __GRADYS_SIMULATIONS_TELEMETRY_M_H
#define __GRADYS_SIMULATIONS_TELEMETRY_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif


namespace gradys_simulations {

class Telemetry;

}  // namespace gradys_simulations


namespace gradys_simulations {

/**
 * Enum generated from <tt>gradys_simulations/protocols/messages/internal/Telemetry.msg:19</tt> by opp_msgtool.
 * <pre>
 * // Activity that the drone is currently carrying out
 * enum DroneActivity
 * {
 *     IDLE = 0;
 *     NAVIGATING = 1;
 *     REACHED_EDGE = 2;
 *     FOLLOWING_COMMAND = 3;
 *     RECHARGING = 4;
 *     SHUTDOWN = 5;
 * }
 * </pre>
 */
enum DroneActivity {
    IDLE = 0,
    NAVIGATING = 1,
    REACHED_EDGE = 2,
    FOLLOWING_COMMAND = 3,
    RECHARGING = 4,
    SHUTDOWN = 5
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const DroneActivity& e) { b->pack(static_cast<int>(e)); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, DroneActivity& e) { int n; b->unpack(n); e = static_cast<DroneActivity>(n); }

/**
 * Class generated from <tt>gradys_simulations/protocols/messages/internal/Telemetry.msg:29</tt> by opp_msgtool.
 * <pre>
 * // Message declaration designed to share necessary drone information with the communication module
 * message Telemetry
 * {
 *     int nextWaypointID = -1;
 *     int lastWaypointID = -1;
 *     int currentCommand = -1;
 *     double currentX;
 *     double currentY;
 *     double currentZ;
 *     double currentLat;
 *     double currentLon;
 *     double currentAlt;
 *     bool isReversed = false;
 *     DroneActivity droneActivity;
 * }
 * </pre>
 */
class Telemetry : public ::omnetpp::cMessage
{
  protected:
    int nextWaypointID = -1;
    int lastWaypointID = -1;
    int currentCommand = -1;
    double currentX = 0;
    double currentY = 0;
    double currentZ = 0;
    double currentLat = 0;
    double currentLon = 0;
    double currentAlt = 0;
    bool isReversed_ = false;
    DroneActivity droneActivity = static_cast<gradys_simulations::DroneActivity>(-1);

  private:
    void copy(const Telemetry& other);

  protected:
    bool operator==(const Telemetry&) = delete;

  public:
    Telemetry(const char *name=nullptr, short kind=0);
    Telemetry(const Telemetry& other);
    virtual ~Telemetry();
    Telemetry& operator=(const Telemetry& other);
    virtual Telemetry *dup() const override {return new Telemetry(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getNextWaypointID() const;
    virtual void setNextWaypointID(int nextWaypointID);

    virtual int getLastWaypointID() const;
    virtual void setLastWaypointID(int lastWaypointID);

    virtual int getCurrentCommand() const;
    virtual void setCurrentCommand(int currentCommand);

    virtual double getCurrentX() const;
    virtual void setCurrentX(double currentX);

    virtual double getCurrentY() const;
    virtual void setCurrentY(double currentY);

    virtual double getCurrentZ() const;
    virtual void setCurrentZ(double currentZ);

    virtual double getCurrentLat() const;
    virtual void setCurrentLat(double currentLat);

    virtual double getCurrentLon() const;
    virtual void setCurrentLon(double currentLon);

    virtual double getCurrentAlt() const;
    virtual void setCurrentAlt(double currentAlt);

    virtual bool isReversed() const;
    virtual void setIsReversed(bool isReversed);

    virtual DroneActivity getDroneActivity() const;
    virtual void setDroneActivity(DroneActivity droneActivity);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const Telemetry& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, Telemetry& obj) {obj.parsimUnpack(b);}


}  // namespace gradys_simulations


namespace omnetpp {

template<> inline gradys_simulations::Telemetry *fromAnyPtr(any_ptr ptr) { return check_and_cast<gradys_simulations::Telemetry*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __GRADYS_SIMULATIONS_TELEMETRY_M_H

