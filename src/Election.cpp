#include "Election.h"
#include "Kronos.h"

#include <string>
    using std::string;

#include <array>
    using std::array;

#include <cmath>

Election::Election() {}

Election::Election(char thePreviousWinner, string theClosingTime) : previousWinner{thePreviousWinner}, closingTime{theClosingTime} {}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy) : Election(thePreviousWinner, theClosingTime) {
    this->hasKennedy = has_Kennedy;
}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn) : Election(thePreviousWinner, theClosingTime, hasKennedy){
    this->rn = theRn;
} 

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn) {
    this->dn = theDn;
}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn, theDn) {
    this->ln = theLn;
}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn, Kronos* theKronosInstance) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn, theDn, theLn) {
    this->kronosInstance = theKronosInstance;
}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn, Kronos* theKronosInstance, int theKn) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn, theDn, theLn, theKronosInstance) {
    this->kn = theKn;
}

Election::~Election(){
    this->kronosInstance = nullptr;
}

int Election::getRv() const {
    return this->rv;
}

int Election::getDv() const {
    return this->dv;
}

int Election::getLv() const {
    return this->lv;
}

int Election::getKv() const {
    return this->kv;
}

int Election::getMv() const {
    return this->mv;
}

int Election::getTv() const {
    return this->tv;
}

int Election::getPi() const {
    return this->pi;
}

int Election::getRn() const {
    return this->rn;
}

int Election::getDn() const {
    return this->dn;
}

int Election::getLn() const {
    return this->ln;
}

int Election::getKn() const {
    return this->kn;
}

float Election::getRp() const {
    return this->rp;
}

float Election::getDp() const {
    return this->dp;
}

float Election::getLp() const {
    return this->lp;
}

float Election::getKp() const {
    return this->kp;
}

float Election::getMp() const {
    return this->mp;
}

char Election::getLeader() const {
    return this->leader;
}

char Election::getPreviousWinner() const {
    return this->previousWinner;
}

char Election::getProjectedFor() const {
    return this->projectedFor;
}

bool Election::getHasKennedy() const {
    return this->hasKennedy;
}

bool Election::getIsCounting() const {
    return this->isCounting;
}

bool Election::getIsClosed() const {
    return this->isClosed;
}

bool Election::getIsFinished() const {
    return this->isFinished;
}

bool Election::getIsProjected() const {
    return this->isProjected;
}

bool Election::getIsFlip() const {
    return this->isFlip;
}

bool Election::getWasRejected() const {
    return this->wasRejected;
}

string Election::getClosingTime() const {
    return this->closingTime;
}

string Election::getPartyOrder() const {
    return this->partyOrder;
}

Kronos* Election::getKronosInstance() const {
    return this->kronosInstance;
}

void Election::setRv(int theRv) {
    this->rv = theRv;
}

void Election::setDv(int theDv) {
    this->dv = theDv;
}

void Election::setLv(int theLv) {
    this->rv = theLv;
}

void Election::setKv(int theKv) {
    this->kv = theKv;
}

void Election::setMv(int theMv) {
    this->mv = theMv;
}

void Election::setTv(int theTv){
    this->tv = theTv;
}

void Election::setPi(int thePi) {
    this->pi = thePi;
}

void Election::setRn(int theRn) {
    this->rn = theRn;
}

void Election::setDn(int theDn) {
    this->dn = theDn;
}

void Election::setLn(int theLn) {
    this->ln = theLn;
}

void Election::setKn(int theKn) {
    this->kn = theKn;
}

void Election::setRp(float theRp) {
    this->rp = theRp;
}

void Election::setDp(float theDp) {
    this->dp = theDp;
}

void Election::setLp(float theLp) {
    this->lp = theLp;
}

void Election::setKp(float theKp) {
    this->kp = theKp;
}

void Election::setMp(float theMp) {
    this->mp = theMp;
}

void Election::setLeader(char theLeader) {
    this->leader = theLeader;
}

void Election::setPreviousWinner(char thePreviousWinner) {
    this->previousWinner = thePreviousWinner;
}

void Election::setProjectedFor(char projected_For) {
    this->projectedFor = projected_For;
}

void Election::setHasKennedy(bool has_Kennedy) {
    this->hasKennedy = has_Kennedy;
}

void Election::setIsCounting(bool is_Counting) {
    this->isCounting = is_Counting;
}

void Election::setIsClosed(bool is_Closed) {
    this->isClosed = is_Closed;
}

void Election::setIsFinished(bool is_Finished) {
    this->isFinished = is_Finished;
}

void Election::setIsProjected(bool is_Projected) {
    this->isProjected = is_Projected;
}

void Election::setIsFlip(bool is_Flip) {
    this->isFlip = is_Flip;
}

void Election::setWasRejected(bool was_Rejected) {
    this->wasRejected = was_Rejected;
}

void Election::setClosingTime(string theClosingTime) {
    this->closingTime = theClosingTime;
}

void Election::setPartyOrder(string thePartyOrder) {
    this->partyOrder = thePartyOrder;
}

void Election::setKronosInstance(Kronos* theKronosInstance) {
    this->kronosInstance = theKronosInstance;
}

int Election::getVotes(char party) {
    switch(party) {
        case 'R': {
            return this->rv;
            break;
        }
        case 'D': {
            return this->dv;
            break;
        }
        case 'L': {
            return this->lv;
            break;
        }
        case 'K': {
            return this->kv;
            break;
        }
        default: {
            return -1;
            break;
        }
    }
}

float Election::getPct(char party) {
    switch(party) {
        case 'R': {
            return this->rp;
            break;
        }
        case 'D': {
            return this->dp;
            break;
        }
        case 'L': {
            return this->lp;
            break;
        }
        case 'K': {
            return this->kp;
            break;
        }
        default: {
            return -1.0;
            break;
        }
    }
}

void Election::setPcts() {
    int t_v = 0;
    t_v += this->rv;
    t_v += this->dv;
    t_v += this->lv;
    t_v += this->kv;
    if(!t_v){
        this->rp = 0.0;
        this->dp = 0.0;
        this->lp = 0.0;
        this->kp = 0.0;
        this->mp = 0.0
        this->tv = 0;
        this->mv = 0;
        this->leader = ' ';
    } else {
        double r_p_ = this->rv / t_v;
        double d_p_ = this->dv / t_v;
        double l_p_ = this->lv / t_v;
        double k_p_;
        if(this->hasKennedy) k_p_ = this->kv / t_v;
        double r_p = round(r_p_ * 1000);
        double d_p = round(d_p_ * 1000);
        double l_p = round(l_p_ * 1000);
        double k_p;
        if(this->hasKennedy) k_p = round(k_p_ * 1000);
        this->rp = static_cast<float>(r_p / 10);
        this->dp = static_cast<float>(d_p / 10);
        this->lp = static_cast<float>(l_p / 10);
        if(this->hasKennedy) this->kp = static_cast<float>(k_p / 10);
        this->tv = t_v;
    }
    this->updatePartyOrder();
    this->leader = this->partyOrder.at(0);
    this->mv = this->getVotes(this->partyOrder.at(0)) - this->getVotes(this->partyOrder.at(0));
    this->mp = this->getPct(this->partyOrder.at(0)) - this->getPct(this->partyOrder.at(0));
}

void Election::updatePartyOrder() {
    char party_1, party_2, party_3, party_4, temp_p1, temp_p2, temp_p3;
    int votes_1, votes_2, votes_3, votes_4, temp_v1, temp_v2, temp_v3;
    if(this->rv >= this->dv) {
        party_1 = 'R';
        party_2 = 'D';
        votes_1 = this->rv;
        votes_2 = this->dv;
    }
    else {
        party_1 = 'D';
        party_2 = 'R';
        votes_1 = this->dv;
        votes_2 = this->rv;
    }
    if(this->lv > votes_1) {
        temp_p1 = party_1;
        temp_p2 = party_2;
        temp_v1 = votes_1;
        temp_v2 = votes_2;
        party_1 = 'L';
        party_2 = temp_p1;
        party_3 = temp_p2;
        votes_1 = this->lv;
        votes_2 = temp_v1;
        votes_3 = temp_v2;
    } else if(this->lv >= votes_2) {
        temp_p2 = party_2;
        temp_v2 = votes_2;
        party_2 = 'L';
        votes_2 = this->lv;
        party_3 = temp_p2;
        votes_3 = temp_v2;
    } else {
        party_3 = 'L';
        votes_3 = this->lv;
    }
    if(this->hasKennedy) {
        if(this->kv > votes_1) {
            temp_p1 = party_1;
            temp_p2 = party_2;
            temp_p3 = party_3;
            temp_v1 = votes_1;
            temp_v2 = votes_2;
            temp_v3 = votes_3;
            party_1 = 'K';
            party_2 = temp_p1;
            party_3 = temp_p2;
            party_4 = temp_p3;
            votes_1 = this->kv;
            votes_2 = temp_v1;
            votes_3 = temp_v2;
            votes_4 = temp_v3;
        } else if (this->kv >= votes_2) {
            temp_p2 = party_2;
            temp_p3 = party_3;
            temp_v2 = votes_2;
            temp_v3 = votes_3;
            party_2 = 'K';
            party_3 = temp_p2;
            party_4 = temp_p3;
            votes_2 = this->kv;
            votes_3 = temp_v2;
            votes_4 = temp_v3;
        } else if(this->kv >= votes_3) {
            temp_p3 = party_3;
            temp_v3 = votes_3;
            party_3 = 'K';
            votes_3 = this->kv;
            party_4 = temp_p3;
            votes_4 = temp_v3;
        } else {
            party_4 = 'K';
            votes_4 = this->kv;
        }
    }
    this->partyOrder = "";
    this->partyOrder += party_1;
    this->partyOrder += party_2;
    this->partyOrder += party_3;
    if(this->hasKennedy) this->partyOrder += party_4;
}