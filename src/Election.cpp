#include "Election.h"
#include "Kronos.h"

#include <string>
    using std::string;

#include <array>
    using std::array;

Election::Election() {}

Election::Election(char thePreviousWinner, string theClosingTime) : previousWinner{thePreviousWinner}, closingTime{theClosingTime} {}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy) : Election(thePreviousWinner, theClosingTime) : hasKennedy{has_Kennedy} {}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn) : Election(thePreviousWinner, theClosingTime, hasKennedy) : rn{theRn} {}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn) : dn{theDn} {}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn, theDn) : ln{theLn} {}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn, Kronos* theKronosInstance) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn, theDn, theLn) : kronosInstance{theKronosInstance} {}

Election::Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn, Kronos* theKronosInstance, int theKn) : Election(thePreviousWinner, theClosingTime, hasKennedy, theRn, theDn, theLn, theKronosInstance) : kn{theKn} {}

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

void Election::setKronosInstance(Kronos* theKronosInstance) {
    this->kronosInstance = theKronosInstance;
}