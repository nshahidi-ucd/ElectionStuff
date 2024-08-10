#include "ElectoralVoteTracker.h"

#include <stdexcept>
    using std::out_of_range;
    using std::invalid_argument;

ElectoralVoteTracker::ElectoralVoteTracker() {}

int ElectoralVoteTracker::getR() const {
    return this->R;
}

int ElectoralVoteTracker::getD() const {
    return this->D;
}

int ElectoralVoteTracker::getU() const {
    return this->U;
}

int ElectoralVoteTracker::getA() const {
    return this->A;
}

char ElectoralVoteTracker::getM() const {
    return this->M;
}

int ElectoralVoteTracker::getr() const {
    return this->r;
}

int ElectoralVoteTracker::getd() const {
    return this->d;
}

int ElectoralVoteTracker::getu() const {
    return this->u;
}

int ElectoralVoteTracker::geta() const {
    return this->a;
}

char ElectoralVoteTracker::getm() const {
    return this->m;
}

void ElectoralVoteTracker::setR(int theR){
    this->R = theR;
}

void ElectoralVoteTracker::setD(int theD){
    this->D = theD;
}

void ElectoralVoteTracker::setU(int theU){
    this->U = theU;
}

void ElectoralVoteTracker::setA(int theA){
    this->A = theA;
}

void ElectoralVoteTracker::setM(char theM){
    this->M = theM;
}

void ElectoralVoteTracker::setr(int ther){
    this->r = ther;
}

void ElectoralVoteTracker::setd(int thed){
    this->d = thed;
}

void ElectoralVoteTracker::setu(int theu){
    this->u = theu;
}

void ElectoralVoteTracker::seta(int thea){
    this->a = thea;
}

void ElectoralVoteTracker::setm(char them){
    this->m = them;
}

bool ElectoralVoteTracker::R_Wins() const {
    return this->R >= 270;
}

bool ElectoralVoteTracker::R_Won() const {
    return this->r >= 270;
}

bool ElectoralVoteTracker::R_Just_Won() const {
    return this->R_Wins() && ! this->R_Won();
}

bool ElectoralVoteTracker::R_Just_Unwon() const {
    return ! this->R_Wins() && this->R_Won();
}

bool ElectoralVoteTracker::D_Wins() const {
    return this->D >= 270;
}

bool ElectoralVoteTracker::D_Won() const {
    return this->d >= 270;
}

bool ElectoralVoteTracker::D_Just_Won() const {
    return this->D_Wins() && ! this->D_Won();
}

bool ElectoralVoteTracker::D_Just_Unwon() const {
    return ! this->D_Wins() && this->D_Won();
}

bool ElectoralVoteTracker::Is_A_Tie() const {
    return this->R == this->D && this->A == 538;
}

bool ElectoralVoteTracker::Was_A_Tie() const {
    return this->r == this->d && this->a == 538;
}

bool ElectoralVoteTracker::Tie_Reached() const {
    return this->Is_A_Tie() && ! this->Was_A_Tie();
}

bool ElectoralVoteTracker::Tie_Unreached() const {
    return ! this->Is_A_Tie() && this->Was_A_Tie();
}

bool ElectoralVoteTracker::Winner_Changed() const {
    return this->R_Just_Won() || this->R_Just_Unwon() || this->D_Just_Won() || this->D_Just_Unwon() || this->Tie_Reached() || this->Tie_Unreached();
}

char ElectoralVoteTracker::getWinner() const {
    return this->R_Wins() ? 'R' : this->D_Wins() ? 'D' : this->Is_A_Tie() ? 'T' : ' ';
}

void ElectoralVoteTracker::R_Gain(int evs) {
    if(evs > this->U)
        throw out_of_range("Not enough unallocated EVs for operation.");
    if(evs < 0)
        throw invalid_argument("Negative EVs are not allowed.");
    int cur_u, cur_a, cur_r;
    cur_u = this->U;
    cur_a = this->A;
    cur_r = this->R;
    this->U -= evs;
    this->A += evs;
    this->R += evs;
    this->u = cur_u;
    this->a = cur_a;
    this->r = cur_r;
    if(this->Winner_Changed())
        this->M = this->getWinner();
}

void ElectoralVoteTracker::R_Loss(int evs) {
    if(evs > this->R)
        throw out_of_range("Not enough Republican EVs for operation.");
    if(evs < 0)
        throw invalid_argument("Negative EVs are not allowed.");
    int cur_u, cur_a, cur_r;
    cur_u = this->U;
    cur_a = this->A;
    cur_r = this->R;
    this->U += evs;
    this->A -= evs;
    this->R -= evs;
    this->u = cur_u;
    this->a = cur_a;
    this->r = cur_r;
    if(this->Winner_Changed())
        this->M = this->getWinner();
}

void ElectoralVoteTracker::D_Gain(int evs) {
    if(evs > this->U)
        throw out_of_range("Not enough unallocated EVs for operation.");
    if(evs < 0)
        throw invalid_argument("Negative EVs are not allowed.");
    int cur_u, cur_a, cur_d;
    cur_u = this->U;
    cur_a = this->A;
    cur_d = this->D;
    this->U -= evs;
    this->A += evs;
    this->D += evs;
    this->u = cur_u;
    this->a = cur_a;
    this->d = cur_d;
    if(this->Winner_Changed())
        this->M = this->getWinner();
}

void ElectoralVoteTracker::D_Loss(int evs) {
    if(evs > this->R)
        throw out_of_range("Not enough Democratic EVs for operation.");
    if(evs < 0)
        throw invalid_argument("Negative EVs are not allowed.");
    int cur_u, cur_a, cur_d;
    cur_u = this->U;
    cur_a = this->A;
    cur_d = this->R;
    this->U += evs;
    this->A -= evs;
    this->D -= evs;
    this->u = cur_u;
    this->a = cur_a;
    this->d = cur_d;
    if(this->Winner_Changed())
        this->M = this->getWinner();
}