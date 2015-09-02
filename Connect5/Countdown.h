#ifndef COUND_H
#define COUND_H

#include<QTimer>

class Countdown : public QObject
{
    Q_OBJECT
    
public:
    Countdown(int max) {
        maxV = max;
        v = max;
        on = false;
        QTimer* timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &Countdown::oneSec);
        timer->start(1000);
    }
signals:
    void timeChanged(int time);
    void timeOut();
public slots:
    void oneSec() {
        if (on) {
            v--;
            emit timeChanged(v);
            if (v == 0) {
                v = maxV;
                emit timeOut();
            }
        }
    }
    void pause() {
        on = false;
    }
    void resume() {
        on = true;
    }
    void start() {
        v = maxV;
        on = true;
    }
private:
    int v;
    int maxV;
    bool on;
};

#endif