#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H
#include "../Colleague/Colleague.h"
#include <string>

/**
    * @class StaffMember
 * @brief Base class for all staff members in the simulation.
* concrete classes are:
* - Gardner
* - Sales
* - Cashier
* - Pathologist
* This class tracks how much time a staff member has spent on duties.
* The standard duty pipeline is:
* 1. addTime(time)
* 2. tick(time) - role-specific time update
* 3. browse() - optional browsing action
* 4. receivePreference(pref) - optional preference reception
* 5. sendAdvice(advice) - optional advice sending
* Concrete subclassses must implement tick().
 */

class StaffMember : public Colleague {

protected:
    /**
    * @brief Adds time to the staff member's total time spent on duties.
    * @param time The amount of time to add.
    */
    void addTime(int time);

    /// @brief Total time spent on duties by the staff member.
    int TimeSpent;

public:
    /// @brief Constructs a StaffMember with zero time spent and Colleague.
    StaffMember();

    /// @brief Virtual destructor for StaffMember.
    virtual ~StaffMember()=default;

    /// @brief Performs the staff member's duty. (default time = 1)
    void doDuty();

    /**
    * @brief Performs the staff member's duty.
    * default pipeline:
    * 1. addTime(time)
    * 2. tick(time) - role-specific time update (must be implemented by subclass)
    * 3. browse() - optional browsing action
    * 4. receivePreference(pref) - optional preference reception
    * 5. sendAdvice(advice) - optional advice sending
    * Subclasses can override browse(), receivePreference(), and sendAdvice() as needed.
    * @param time The amount of time to spend on the duty.
    */
    void doDuty(int time);

    /**
    * @brief Role-specific time update during duty.
    * Must be implemented by concrete subclasses.
    * @param time The amount of time spent on the duty.
    */
    virtual void tick(int time)=0;

    /**
    * @brief Receives a preference from the user.
    * Base implementation does nothing.
    * @param pref The preference to receive.
    */
    virtual void receivePreference(const std::string& pref);

    /**
    * @brief Browsing action during duty.
    * Base implementation does nothing.
    */
    virtual void browse();
	
    /**
    * @brief Sends advice to the user.
    * Base implementation does nothing.
    * @param advice The advice to send.
    */
    virtual void sendAdvice(const std::string& advice);

    /**
    * @brief Returns the total time spent on duties.
    * @return The total time spent on duties.
    */
    int totalTime() const;
};

#endif
