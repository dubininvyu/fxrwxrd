//
// Created by dubininvyu on 24.06.2022.
//

#pragma once

#include <boost/msm/back/state_machine.hpp>
#include <boost/msm/front/state_machine_def.hpp>

#include "machines_events.h"

namespace msm = boost::msm;
namespace mpl = boost::mpl;

using namespace std;

class Player;

struct PlayerRegistrationStateMachine_ : public msm::front::state_machine_def<PlayerRegistrationStateMachine_> {
    /*
     * fields
     */
    Player* player;

    /*
     * constructors & destructors
     */
    PlayerRegistrationStateMachine_(Player* player);
    ~PlayerRegistrationStateMachine_();

    /*
     * standard methods
     */
    template <class Event,class FSM>
    void on_entry(Event const& ,FSM&) {
        // entering
    }
    template <class Event,class FSM>
    void on_exit(Event const&,FSM& ) {
        // leaving
    }

    /*
     * state machine states
     */
    /* None state */
    struct None : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct LocaleState : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct PasswordState : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct SexState : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct AgeState : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct RegisteredState : public msm::front::state<> {
        template <class Event, class FSM>
        void on_entry(Event const& event, FSM& fsm) const {

        }

        template <class Event, class FSM>
        void on_exit(Event const& event, FSM& fsm) const {

        }
    };

    struct ErrorState : public msm::front::state<> {

    };

    /*
     * the initial state of the state machine
     */
    typedef None initial_state;

    /*
     * transition actions
     */
    void enter_locale(Next const& event);
    void enter_password(Next const& event);
    void enter_sex(Next const& event);
    void enter_age(Next const& event);
    void register_account(Next const& event);

    void make_error(Error const& event);

    /*
     * guard conditions
     */

    // werwerewr

    /*
     * transition table for the state machine
     */
    typedef PlayerRegistrationStateMachine_ p; // makes transition table cleaner

    struct transition_table : mpl::vector<
        //              Start             Event                 Next                        Action				     Guard
        //      +-------------------+---------------+--------------------------+------------------------+-----------------------+
        a_row   < None              , Next          , LocaleState              , &p::enter_locale                               >,
        a_row   < None              , Error         , ErrorState               , &p::make_error                                 >,
        //      +-------------------+---------------+--------------------------+------------------------+-----------------------+
        a_row   < LocaleState       , Next          , PasswordState            , &p::enter_password                             >,
        a_row   < LocaleState       , Error         , ErrorState               , &p::make_error                                 >,
        //      +-------------------+---------------+--------------------------+------------------------+-----------------------+
        a_row   < PasswordState     , Next          , SexState                 , &p::enter_sex                                  >,
        a_row   < PasswordState     , Error         , ErrorState               , &p::make_error                                 >,
        //      +-------------------+---------------+--------------------------+------------------------+-----------------------+
        a_row   < SexState          , Next          , AgeState                 , &p::enter_age                                  >,
        a_row   < SexState          , Error         , ErrorState               , &p::make_error                                 >,
        //      +-------------------+---------------+--------------------------+------------------------+-----------------------+
        a_row   < AgeState          , Next          , RegisteredState          , &p::register_account                           >,
        a_row   < AgeState          , Error         , ErrorState               , &p::make_error                                 >
        //      +-------------------+---------------+--------------------------+------------------------+-----------------------+
    > {};

    /*
     * replaces the default no-transition response
     */
    template <class FSM, class Event>
    void no_transition(Event const& e, FSM&, int state) {

    }
};

typedef msm::back::state_machine<PlayerRegistrationStateMachine_> PlayerRegistrationStateMachine;
