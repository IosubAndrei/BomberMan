#ifndef SETTINGS_H
#define SETTINGS_H

namespace sizes {
    enum gameStats {
        Rows = 11, // 16 randuri
        Columns = 13, // 21 coloane
        FieldSize = 50, // 48
        Players = 2
    };
    enum playerStats {
        Bombs = 1,
        ExplosionRange = 1,
        Health = 3
    };
}

#endif // SETTINGS_H
