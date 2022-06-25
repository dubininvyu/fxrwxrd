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

struct PlayerAuthorizationStateMachine_ : public msm::front::state_machine_def<PlayerAuthorizationStateMachine_> {
    /*
     * fields
     */
    Player* player;

    /*
     * constructors & destructors
     */
    PlayerAuthorizationStateMachine_(Player* player);
    ~PlayerAuthorizationStateMachine_();

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

    struct AuthorizedState : public msm::front::state<> {
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
    void locale_enter(Next const& event);
    void password_enter(Next const& event);
    void authorize(Next const& event);

    void make_error(Error const& event);

    /*
     * guard conditions
     */

    // ...

    /*
     * transition table for the state machine
     */
    typedef PlayerAuthorizationStateMachine_ p; // makes transition table cleaner

    struct transition_table : mpl::vector<
        //              Start            Event             Next                     Action				        Guard
        //      +-------------------+------------+-----------------------+----------------------------+-----------------------+
        a_row   < None              , Next       , LocaleState           , &p::locale_enter                                   >,
        a_row   < None              , Error      , ErrorState            , &p::make_error                                     >,
        //      +-------------------+------------+-----------------------+----------------------------+-----------------------+
        a_row   < LocaleState       , Next       , PasswordState         , &p::password_enter                                 >,
        a_row   < LocaleState       , Error      , ErrorState            , &p::make_error                                     >,
        //      +-------------------+------------+-----------------------+----------------------------+-----------------------+
        a_row   < PasswordState     , Next       , AuthorizedState       , &p::authorize                                      >,
        a_row   < PasswordState     , Error      , ErrorState            , &p::make_error                                     >
        //      +-------------------+------------+-----------------------+----------------------------+-----------------------+
    > {};

    /*
     * replaces the default no-transition response
     */
    template <class FSM, class Event>
    void no_transition(Event const& e, FSM&, int state) {

    }
};

typedef msm::back::state_machine<PlayerAuthorizationStateMachine_> PlayerAuthorizationStateMachine;
