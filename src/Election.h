#ifndef ELECTION_H
#define ELECTION_H

#include <string>
    using std::string;

#include "Kronos.h"

class Election {
    

    private:

        int rv{0};
        int dv{0};
        int lv{0};
        int kv{0};
        int mv{0};
        int tv{0};
        int pi{0};
        int rn{0};
        int dn{0};
        int ln{0};
        int kn{0};
        
        float rp{0.0};
        float dp{0.0};
        float lp{0.0};
        float kp{0.0};
        float mp{0.0};

        char leader;
        char previousWinner;
        char projectedFor;

        bool hasKennedy{false};
        bool isClosed{false};
        bool isCounting{false};
        bool isFinished{false};
        bool isProjected{false};
        bool isFlip{false};
        bool wasRejected{false};

        string closingTime;
        string partyOrder;

        Kronos* kronosInstance{nullptr};
        
        
        public:

            Election();
            
            explicit Election(char thePreviousWinner, string theClosingTime);
            explicit Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy);
            explicit Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn);
            explicit Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn);
            explicit Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn);
            explicit Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn, Kronos* theKronosInstance);
            explicit Election(char thePreviousWinner, string theClosingTime, bool has_Kennedy, int theRn, int theDn, int theLn, Kronos* theKronosInstance, int theKn);
            
            ~Election();

            int getRv() const;
            int getDv() const;
            int getLv() const;
            int getKv() const;
            int getMv() const;
            int getTv() const;
            int getPi() const;
            int getRn() const;
            int getDn() const;
            int getLn() const;
            int getKn() const;
            float getRp() const;
            float getDp() const;
            float getLp() const;
            float getKp() const;
            float getMp() const;
            char getLeader() const;
            char getPreviousWinner() const;
            char getProjectedFor() const;
            bool getHasKennedy() const;
            bool getIsCounting() const;
            bool getIsClosed() const;
            bool getIsFinished() const;
            bool getIsProjected() const;
            bool getIsFlip() const;
            bool getWasRejected() const;
            string getClosingTime() const;
            string getPartyOrder() const;
            Kronos* getKronosInstance() const;

            void setRv(int theRv);
            void setDv(int theDv);
            void setLv(int theLv);
            void setKv(int theKv);
            void setMv(int theMv);
            void setTv(int theTv);
            void setPi(int thePi);
            void setRn(int theRn);
            void setDn(int theDn);
            void setLn(int theRn);
            void setKn(int theKn);
            void setRp(float theRp);
            void setDp(float theDp);
            void setLp(float theLp);
            void setKp(float theKp);
            void setMp(float theMp);
            void setLeader(char theLeader);
            void setPreviousWinner(char thePreviousWinner);
            void setProjectedFor(char projected_For);
            void setHasKennedy(bool has_Kennedy);
            void setIsCounting(bool is_Counting);
            void setIsClosed(bool is_Closed);
            void setIsFinished(bool is_Finished);
            void setIsProjected(bool is_Projected);
            void setIsFlip(bool is_Flip);
            void setWasRejected(bool was_Rejected);
            void setClosingTime(string theClosingTime);
            void setPartyOrder(string thePartyOrder);
            void setKronosInstance(Kronos* theKronosInstance);

            int getVotes(char party);
            float getPct(char party);
            void setPcts() {}
            void updatePartyOrder()
};

#endif