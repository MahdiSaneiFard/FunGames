#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

#include <QString>

class GameOptions {
public:
    QString name;       // اسم بازی
    QString color;      // رنگ بازی
    int timeLimit;      // محدودیت زمان

    GameOptions() : name(""), color("Red"), timeLimit(5) {}
    GameOptions(const QString &n, const QString &c, int t)
        : name(n), color(c), timeLimit(t) {}
};

#endif // GAMEOPTIONS_H
