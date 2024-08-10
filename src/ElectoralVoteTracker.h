#ifndef ELECTORALVOTETRACKER_H
#define ELECTORALVOTETRACKER_H

class ElectoralVoteTracker {


    private:
	    
        int R{0};
		int D{0};
		int U{538};
	    int A{0};
		char M{' '};
        int r{-1};
        int d{-1};
        int u{539};
        int a{-1};
        char m{'D'};
    
    
    public:
        
        ElectoralVoteTracker();
        ~ElectoralVoteTracker()=default;

        int getR() const;
        int getD() const;
        int getU() const;
        int getA() const;
        char getM() const;
        int getr() const;
        int getd() const;
        int getu() const;
        int geta() const;
        char getm() const;

        void setR(int theR);
        void setD(int theD);
        void setU(int theU);
        void setA(int theA);
        void setM(char theM);
        void setr(int ther);
        void setd(int thed);
        void setu(int theu);
        void seta(int thea);
        void setm(char them);
        
        bool R_Wins() const;
        bool R_Won() const;
        bool R_Just_Won() const;
        bool R_Just_Unwon() const;
        bool D_Wins() const;
        bool D_Won() const;
        bool D_Just_Won() const;
        bool D_Just_Unwon() const;
        bool Is_A_Tie() const;
        bool Was_A_Tie() const;
        bool Tie_Reached() const;
        bool Tie_Unreached() const;
        bool Winner_Changed() const;
        char getWinner() const;

        void R_Gain(int evs);
        void R_Loss(int evs);
        void D_Gain(int evs);
        void D_Loss(int evs);
};

#endif