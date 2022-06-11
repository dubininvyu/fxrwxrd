//
// Created by dubininvyu on 30.05.2022.
//

#pragma once

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>

class Player;

using namespace std;

namespace msm = boost::msm;
namespace mpl = boost::mpl;

namespace player_authentication_sm {

/* Events */
struct Event {

};

struct Start : virtual public Event {

};

struct Next : virtual public Event {

};

struct Error : virtual public Event {

};

struct PlayerAuthenticationStateMachine_ : public msm::front::state_machine_def<PlayerAuthenticationStateMachine_> {
    PlayerAuthenticationStateMachine_(Player* player);

    /* None state */
    struct None : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    /* Authorization state */
    struct AuthorizationPassword : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct Authorized : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct AuthorizationError : public msm::front::state<> {

    };

    /* Registration state */
    struct RegistrationPassword : public msm::front::state<> {

    };

    struct RegistrationSex : public msm::front::state<> {

    };

    struct Registered : public msm::front::state<> {

    };

    struct RegistrationError : public msm::front::state<> {

    };

    /* initial state */
    typedef None initial_state;

    /* transition actions */

    // -- authorization
    void authorization_password(Start const& event);
    void authorization_end(Next const& event);

    // -- registration
    void registration_password(Start const& event);
    void registration_sex(Next const& event);
    void registration_end(Next const& event);

    /* guard conditions */
    bool isRegistered(Start const& event);
    bool isNotRegistered(Start const& event);

    /* transition table */
    typedef PlayerAuthenticationStateMachine_ p;

    struct transition_table : mpl::vector<
    //                  Start                 Event                 Next                        Action				         Guard
    //      +---------------------------+---------------+--------------------------+--------------------------------+-----------------------+
    row     < None                      , Start         , AuthorizationPassword    , &p::authorization_password     , &p::isRegistered      >,
    row     < None                      , Start         , RegistrationPassword     , &p::registration_password      , &p::isNotRegistered   >,
    //      +---------------------------+---------------+--------------------------+--------------------------------+-----------------------+
    a_row   < AuthorizationPassword     , Next          , Authorized               , &p::authorization_end                                  >,
    //      +---------------------------+---------------+--------------------------+--------------------------------+-----------------------+
    a_row   < RegistrationPassword      , Next          , RegistrationSex          , &p::registration_sex                                   >,
    a_row   < RegistrationSex           , Next          , Registered               , &p::registration_end                                   >,
    //      +---------------------------+---------------+--------------------------+--------------------------------+-----------------------+
    a_row   < Registered                , Start         , AuthorizationPassword    , &p::authorization_password                             >
    //      +---------------------------+---------------+--------------------------+--------------------------------+-----------------------+

    > {};

    /* variables */
    Player* player;
};

typedef msm::back::state_machine<PlayerAuthenticationStateMachine_> PlayerAuthenticationStateMachine;

};