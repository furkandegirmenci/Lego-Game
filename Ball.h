#ifndef LEGO_GAME_BALL_H
#define LEGO_GAME_BALL_H


class Ball {
private:
    int ballEnergy {};
    int minEnergy {};
public:
    int getBallEnergy() const;
    void calcMinEnergy(const int*, int);

    int getMinEnergy() const;

    ~Ball();

};


#endif //LEGO_GAME_BALL_H
